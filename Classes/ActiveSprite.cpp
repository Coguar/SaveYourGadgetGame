#include "ActiveSprite.h"
#include "cocostudio/CocoStudio.h"
#include "ui/CocosGUI.h"
#include "Definitions.h"
#include "GameScene.h"
#include "Constants.h"

USING_NS_CC;

ActiveSprite::ActiveSprite() = default;

ActiveSprite::~ActiveSprite() {}

ActiveSprite* ActiveSprite::create(std::string name)
{
	ActiveSprite* pSprite = new ActiveSprite();

	if (pSprite->initWithFile(name))
	{
		pSprite->autorelease();

		pSprite->initOptions();

		pSprite->addEvents();

		return pSprite;
	}

	CC_SAFE_DELETE(pSprite);
	return nullptr;
}

void ActiveSprite::initOptions()
{
  
}

void ActiveSprite::addEvents()
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

	cocos2d::Director::getInstance()->getEventDispatcher()->addEventListenerWithFixedPriority(m_pListener, TOCH_ON_SPRITE_PRIORITY);
}

void ActiveSprite::_touchEvent(cocos2d::Touch* touch)
{
	this->cleanup();
	this->removeAllChildrenWithCleanup(true);
	this->removeFromParentAndCleanup(true);

	EventCustom event(ADD_POINT);
	Director::getInstance()->getEventDispatcher()->dispatchEvent(&event);
	
}

void ActiveSprite::cleanup()
{
	cocos2d::Director::getInstance()->getEventDispatcher()->removeEventListener(m_pListener);
}