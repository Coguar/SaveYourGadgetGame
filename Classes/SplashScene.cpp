#include "SplashScene.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "MenuScene.h"
#include "Definitions.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

using namespace cocostudio::timeline;

Scene* SplashScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = SplashScene::create();

    // add layer as a child to scene
    scene->addChild(layer);

    // return the scene
    return scene;
}

// on "init" you need to initialize your instance
bool SplashScene::init()
{
	//1. super init first
	if (!Layer::init())
	{
		return false;
	}

	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/Point.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/lose.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("sound/drop.mp3");
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadBackgroundMusic("sound/BG_sound.mp3");
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	this->scheduleOnce( schedule_selector(SplashScene::GoToMenuScene), DISPLAY_TIME_SPLASH_SCENE );

	auto backgrowndSprite = Sprite::create("SplashScene.png");
	backgrowndSprite->setPosition(Point(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));

	this->addChild(backgrowndSprite);

	return true;
}

void SplashScene::GoToMenuScene(float dt)
{
	auto scene = MenuScene::createScene();

	Director::getInstance()->replaceScene(TransitionFade::create(TRANSITION_TIME, scene));
}
   
