#include "Water.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"

USING_NS_CC;

Water::Water()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	waterSprite = Sprite::create("DeadLine.png");
	auto waterBoby = PhysicsBody::createBox(waterSprite->getContentSize());
	waterBoby->setCollisionBitmask(WATER_COLLISION_BITMASK);
	waterBoby->setContactTestBitmask(true);

	waterBoby->setDynamic(false);
	waterSprite->setPhysicsBody(waterBoby);
	
}


void Water::AddWater(cocos2d::Layer * layer)
{
	waterSprite->setPosition(waterSprite->getContentSize().width / 2 + origin.x, 140);
	layer->addChild(waterSprite);
}