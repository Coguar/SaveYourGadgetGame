#include "ActiveSprite.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"
#include "GameScene.h"

USING_NS_CC;

ActiveSprite::ActiveSprite() {}

ActiveSprite::~ActiveSprite() 
{

	cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(m_pListener);
}

ActiveSprite* ActiveSprite::create(std::string name)
{
	ActiveSprite* pSprite = new ActiveSprite();

	if (pSprite->initWithFile(name))
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
	m_pListener = EventListenerTouchOneByOne::create();
	m_pListener->setSwallowTouches(true);

	m_pListener->onTouchBegan = [&](cocos2d::Touch* touch, cocos2d::Event* event)
	{
			Vec2 position = touch->getLocation();
			Rect rect = this->getBoundingBox();

			if (rect.containsPoint(position))
			{
				return true;
			}
		return false;
	};

	m_pListener->onTouchEnded = [=](cocos2d::Touch* touch, cocos2d::Event* event)
	{
		_touchEvent(touch);
	};

	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(m_pListener, 30);
}

void ActiveSprite::_touchEvent(cocos2d::Touch* touch)
{
	
	this->removeAllChildrenWithCleanup(true);
	this->removeFromParentAndCleanup(true);
	cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(m_pListener);
	EventCustom event("addPoint");
	Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
}