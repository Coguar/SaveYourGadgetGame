#include "MenuScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "GameScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"


USING_NS_CC;

using namespace cocostudio::timeline;

Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool MenuScene::init()
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

	auto playItem = MenuItemImage::create("play.png", "play_Clicked.png", CC_CALLBACK_1(MenuScene::GoToGameScene, this));
	playItem->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	auto menu = Menu::create(playItem, NULL);
	menu->setPosition(Point::ZERO);

	this->addChild(menu);

	CocosDenshion::SimpleAudioEngine::getInstance()->playBackgroundMusic("sound/BG_sound.mp3", true);

	return true;
}
   
void MenuScene::GoToGameScene(cocos2d::Ref *sender)
{
	auto scene = GameScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}