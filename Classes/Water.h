#ifndef __WATER_H__
#pragma once
#include "cocos2d.h"

class Water
{
public:
	Water();

	void AddWater(cocos2d::Layer * layer);

private:
	cocos2d::Sprite *waterSprite;

	cocos2d::Size visibleSize;

	cocos2d::Vec2 origin;
};

#endif // __WATER_H__
