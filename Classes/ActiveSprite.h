#ifndef _MYSPRITE_H_
#pragma once

#include "cocos2d.h"


class ActiveSprite : public cocos2d::Sprite
{
private:
	ActiveSprite* m_pSprite = nullptr;
	cocos2d::EventListenerTouchOneByOne *m_pListener = nullptr;
protected:

	void _initOptions();

	void _addEvents();

	ActiveSprite();

public:
	~ActiveSprite();

	void _touchEvent(cocos2d::Touch* touch);

	static ActiveSprite* create(std::string name);
};

#endif // _MYSPRITE_H_
