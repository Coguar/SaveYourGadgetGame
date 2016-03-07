#pragma once
#include "cocos2d.h"

class Water
{
public:
	Water();

	cocos2d::Sprite* create();

	void AddWater(cocos2d::Layer * layer);

private:
	cocos2d::Sprite *waterSprite;

	cocos2d::Size visibleSize;

	cocos2d::Vec2 origin;
};

