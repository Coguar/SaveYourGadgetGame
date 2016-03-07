#pragma once

#include "cocos2d.h"


class ActiveSprite : public cocos2d::Sprite
{
private:
	ActiveSprite* m_pSprite = nullptr;
	cocos2d::EventListenerTouchOneByOne *m_pListener = nullptr;
protected:

	void initOptions();

	void addEvents();

	ActiveSprite();

public:
	~ActiveSprite();

	void _touchEvent(cocos2d::Touch* touch);

	virtual void cleanup() override;

	static ActiveSprite* create(std::string name);
};

