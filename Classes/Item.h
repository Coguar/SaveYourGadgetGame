#pragma once
#include "cocos2d.h"

class Item
{
public:
	Item();

	void SpawnItem(cocos2d::Layer * layer);

	void SpawnItemFromSide(cocos2d::Layer *layer);

private:

	cocos2d::Size m_visibleSize;

	cocos2d::Vec2 m_origin;
};

