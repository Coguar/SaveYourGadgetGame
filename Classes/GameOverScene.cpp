#include "GameOverScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"
#include "GameScene.h"

USING_NS_CC;

size_t myScore;

using namespace cocostudio::timeline;

Scene* GameOverScene::createScene(size_t templeScore)
{
	myScore = templeScore;

    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = GameOverScene::create();

    // add layer as a child to scene
    scene->addChild(layer);
	
    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool GameOverScene::init()
{
	//1. super init first
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	score = myScore;

	auto backgrowndSprite = Sprite::create("GameOverScene.png");
	backgrowndSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgrowndSprite);

	auto playItem = MenuItemImage::create("PLAY.png", "PLAY_Clicked.png", CC_CALLBACK_1(GameOverScene::GoToMenuScene, this));
	playItem->setPosition(Point(visibleSize.width / 2 + origin.x, playItem->getContentSize().height + origin.y));

	auto menu = Menu::create(playItem, NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);


	UserDefault *def = UserDefault::getInstance();

	size_t highScore = def->getIntegerForKey("HIGHSCORE", size_t(0));
	if (score > highScore)
	{
		highScore = score;

		def->setIntegerForKey("HIGHSCORE", highScore);
	}

	def->flush();

	__String * templeScore = __String::createWithFormat("Score: %i", score);
	scoreLabel = Label::createWithTTF(templeScore->getCString(), "score.ttf", visibleSize.height * FONT_SIZE);
	scoreLabel->setColor(Color3B::WHITE);
	scoreLabel->setPosition(visibleSize.width / 2 + origin.x, origin.y + visibleSize.height / 2);
	this->addChild(scoreLabel);

	__String * templeHScore = __String::createWithFormat("High Score: %i", highScore);
	hScoreLabel = Label::createWithTTF(templeHScore->getCString(), "score.ttf", visibleSize.height * FONT_SIZE / 2);
	hScoreLabel->setColor(Color3B::YELLOW);
	hScoreLabel->setPosition(visibleSize.width / 2 + origin.x, origin.y + visibleSize.height / 2 + visibleSize.height * FONT_SIZE);
	this->addChild(hScoreLabel);

	return true;
}
   
void GameOverScene::GoToMenuScene(cocos2d::Ref *sender)
{
	auto scene = GameScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}