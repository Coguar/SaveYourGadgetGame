#include "Water.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"
#include "Constants.h"
USING_NS_CC;

Water::Water() {};

cocos2d::Sprite* Water::create()
{
	visibleSize = Director::getInstance()->getVisibleSize();
	origin = Director::getInstance()->getVisibleOrigin();

	waterSprite = Sprite::create(DEAD_LINE);
	auto waterBoby = PhysicsBody::createBox(waterSprite->getContentSize());
	waterBoby->setCollisionBitmask(WATER_COLLISION_BITMASK);
	waterBoby->setContactTestBitmask(true);

	waterBoby->setDynamic(false);
	waterSprite->setPhysicsBody(waterBoby);
	return waterSprite;
}

void Water::AddWater(cocos2d::Layer * layer)
{
	waterSprite->setPosition(waterSprite->getContentSize().width / 2 + origin.x, 140);
	layer->addChild(waterSprite);
}