#include "Item.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"
#include "ActiveSprite.h"
#include "Constants.h"

USING_NS_CC;


Item::Item()
{
	m_visibleSize = Director::getInstance()->getVisibleSize();
	m_origin = Director::getInstance()->getVisibleOrigin();
}


void Item::SpawnItem(cocos2d::Layer *layer)
{

	auto phoneItem = ActiveSprite::create(PHONE_ITEM);

	auto phonePhysicsBoby = PhysicsBody::createBox(phoneItem->getContentSize());

	phonePhysicsBoby->setCollisionBitmask(ITEM_COLLISION_BITMASK);
	phonePhysicsBoby->setContactTestBitmask(true);

	auto random = CCRANDOM_0_1();

	if (random < LEFT_SCREEN_SPAWN_THRESHOLD)
	{
		random = LEFT_SCREEN_SPAWN_THRESHOLD;
	}
	else if (random > RIGHT_SCREEN_SPAWN_THRESHOLD)
	{
		random = RIGHT_SCREEN_SPAWN_THRESHOLD;
	}

	auto itemPosition = random * m_visibleSize.width;

	phonePhysicsBoby->setDynamic(true);

	phoneItem->setPhysicsBody(phonePhysicsBoby);

	phoneItem->setPosition(itemPosition + m_origin.x, m_visibleSize.height - 5);

	layer->addChild(phoneItem);

}

void Item::SpawnItemFromSide(cocos2d::Layer *layer)
{

	auto phoneItem = ActiveSprite::create(LAPTOP_ITEM);

	auto phonePhysicsBoby = PhysicsBody::createBox(phoneItem->getContentSize());

	phonePhysicsBoby->setCollisionBitmask(ITEM_COLLISION_BITMASK);
	phonePhysicsBoby->setContactTestBitmask(true);

	auto random = CCRANDOM_0_1();
	cocos2d::MoveBy *itemAction;
	if (random < 0.5)
	{
		random = MAX_LEFT_SCREEN_SPAWN;
		itemAction = cocos2d::MoveBy::create(MOVEMENT_SPEED * m_visibleSize.width, Point(m_visibleSize.width * 1.5, 0));

	}
	else if (random >= 0.5)
	{
		random = MAX_RIGHT_SCREEN_SPAWN;
		itemAction = cocos2d::MoveBy::create(MOVEMENT_SPEED * m_visibleSize.width, Point(-m_visibleSize.width * 1.5, 0));

	}

	auto itemPosition = random * m_visibleSize.width;

	phonePhysicsBoby->setDynamic(true);

	phoneItem->setPhysicsBody(phonePhysicsBoby);

	phoneItem->setPosition(itemPosition + m_origin.x, m_visibleSize.height * Y_POS_TO_SPAWN + m_origin.y);

	phoneItem->runAction(itemAction);
	layer->addChild(phoneItem);

}
