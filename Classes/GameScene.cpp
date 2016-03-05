#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"
#include "GameOverScene.h"
#include "ActiveSprite.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

using namespace cocostudio::timeline;

Scene* GameScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::createWithPhysics();
	//scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

    // 'layer' is an autorelease object
    auto layer = GameScene::create();
	layer->SetPhysicsWorld(scene->getPhysicsWorld());
    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameScene::init()
{
	//1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgrowndSprite = Sprite::create("GameScene.png");
	backgrowndSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgrowndSprite);

	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);

	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);

	this->addChild(edgeNode);

	this->schedule(schedule_selector(GameScene::SpawnItem), SPAWN_FREQUENCY);

	water.AddWater(this);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	scorePoint = 0;
	auto pointListener = EventListenerCustom::create("addPoint", [=](EventCustom *event)
	{
		scorePoint++;
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/Point.mp3");

		if (scorePoint == 100)
		{
			this->schedule(schedule_selector(GameScene::SpawnItemFromSide), SPAWN_FREQUENCY * 2);
		}

		if (scorePoint % 10 == 0)
		{
			if (scorePoint / 1000 < 0.3)
			{
				this->schedule(schedule_selector(GameScene::SpawnItem), SPAWN_FREQUENCY - scorePoint / 1000);
			}
			else
			{
				this->schedule(schedule_selector(GameScene::SpawnItem), MAX_SPAWN_FREQUENCY);

			}
		}
		__String * templeScore = __String::createWithFormat("%i", scorePoint);
		scoreLabel->setString(templeScore->getCString());
	});
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(pointListener, this);

	__String * templeScore = __String::createWithFormat("%i", scorePoint);
	scoreLabel = Label::createWithTTF(templeScore->getCString(), "score.ttf", visibleSize.height * FONT_SIZE);
	scoreLabel->setColor(Color3B::WHITE);
	scoreLabel->setPosition(visibleSize.width / 2 + origin.x, origin.y + visibleSize.height * FONT_SIZE);
	this->addChild(scoreLabel, 10000);


	return true;
}
   

void GameScene::SpawnItem(float dt)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/drop.mp3");
	item.SpawnItem(this);
}

void GameScene::SpawnItemFromSide(float dt)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/drop.mp3");
	item.SpawnItemFromSide(this);
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact &contact)
{

	PhysicsBody *first = contact.getShapeA()->getBody();
	PhysicsBody *second = contact.getShapeB()->getBody();

	if (((first->getCollisionBitmask() == WATER_COLLISION_BITMASK) && (second->
		getCollisionBitmask() == ITEM_COLLISION_BITMASK)) || ((second->
			getCollisionBitmask() == WATER_COLLISION_BITMASK) && (first->
				getCollisionBitmask() == ITEM_COLLISION_BITMASK)))
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("sound/lose.mp3");
		this->removeAllChildrenWithCleanup(true);
		auto scene = GameOverScene::createScene(scorePoint);
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));

	}
	return true;
}