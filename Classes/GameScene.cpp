#include "GameScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"
#include "GameOverScene.h"
#include "ActiveSprite.h"
#include "SimpleAudioEngine.h"
#include "Constants.h"

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

	auto backgrowndSprite = Sprite::create(MENU_SCRENE);
	backgrowndSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgrowndSprite);

	auto edgeBody = PhysicsBody::createEdgeBox(visibleSize, PHYSICSBODY_MATERIAL_DEFAULT, 3);

	auto edgeNode = Node::create();
	edgeNode->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	edgeNode->setPhysicsBody(edgeBody);

	this->addChild(edgeNode);

	this->schedule(schedule_selector(GameScene::SpawnItem), SPAWN_FREQUENCY);

	water.create();
	water.AddWater(this);

	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(GameScene::onContactBegin, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(contactListener, this);

	scorePoint = 0;

	auto pointListener = EventListenerCustom::create(ADD_POINT, [=](EventCustom *event)
	{
		scorePoint++;
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(POINT_SOUND.c_str());

		if (scorePoint == LAPTOP_SPAWN_SCORE)
		{
			this->schedule(schedule_selector(GameScene::SpawnItemFromSide), SPAWN_FREQUENCY * 2);
		}

		if (scorePoint % FREQUENCY_RAISING == 0)
		{
			if (SPAWN_FREQUENCY - scorePoint * LEVEL_KOEFITSENT > MAX_SPAWN_FREQUENCY)
			{
				this->schedule(schedule_selector(GameScene::SpawnItem), SPAWN_FREQUENCY - scorePoint * LEVEL_KOEFITSENT);
			}
			else
			{
				this->schedule(schedule_selector(GameScene::SpawnItem), MAX_SPAWN_FREQUENCY);

			}
		}
		scoreLabel->setString(std::to_string(scorePoint));
	});
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(pointListener, this);

	scoreLabel = Label::createWithTTF(std::to_string(scorePoint), MAIN_FONT, visibleSize.height * FONT_SIZE);
	scoreLabel->setColor(Color3B::WHITE);
	scoreLabel->setPosition(visibleSize.width / 2 + origin.x, origin.y + visibleSize.height * FONT_SIZE);
	this->addChild(scoreLabel, 10000);


	return true;
}
  

void GameScene::SpawnItem(float dt)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(DROP_SOUND.c_str());
	item.SpawnItem(this);
}

void GameScene::SpawnItemFromSide(float dt)
{
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(DROP_SOUND.c_str());
	item.SpawnItemFromSide(this);
}

void GameScene::CheckGameCollision(cocos2d::PhysicsBody & first, cocos2d::PhysicsBody & second)
{
	if (((first.getCollisionBitmask() == WATER_COLLISION_BITMASK) && (second.
		getCollisionBitmask() == ITEM_COLLISION_BITMASK)) || ((second.
			getCollisionBitmask() == WATER_COLLISION_BITMASK) && (first.
				getCollisionBitmask() == ITEM_COLLISION_BITMASK)))
	{
		CocosDenshion::SimpleAudioEngine::getInstance()->playEffect(LOSE_SOUND.c_str());
		auto scene = GameOverScene::createScene(scorePoint);
		Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
	}
}

bool GameScene::onContactBegin(cocos2d::PhysicsContact &contact)
{

	PhysicsBody *first = contact.getShapeA()->getBody();
	PhysicsBody *second = contact.getShapeB()->getBody();
	CheckGameCollision(*first, *second);
	return true;
}