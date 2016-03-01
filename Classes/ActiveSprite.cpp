#include "ActiveSprite.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"

USING_NS_CC;

ActiveSprite::ActiveSprite() {}

ActiveSprite::~ActiveSprite() {}

ActiveSprite* ActiveSprite::create()
{
	ActiveSprite* pSprite = new ActiveSprite();

	if (pSprite->initWithFile("phone.png"))
	{
		pSprite->autorelease();

		pSprite->_initOptions();

		pSprite->_addEvents();

		return pSprite;
	}

	CC_SAFE_DELETE(pSprite);
	return nullptr;
}

void ActiveSprite::_initOptions()
{
  
}

void ActiveSprite::_addEvents()
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		if (this != nullptr)
		{
			Vec2 position = touch->getLocation();
			Rect rect = this->getBoundingBox();

			if (rect.containsPoint(position))
			{
				return true;
			}
		}
		return false;
	};

	listener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		_touchEvent(touch);
	};

	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(listener, 30);
}

void ActiveSprite::_touchEvent(cocos2d::Touch* touch)
{
	
	this->removeAllChildrenWithCleanup(true);
	this->removeFromParentAndCleanup(true);
	CCLOG("touched MySprite");
	//this->cleanup();
	//this = nullptr;
}