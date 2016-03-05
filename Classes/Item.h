#ifndef __ITEM_H__
#pragma once
#include "cocos2d.h"

class Item
{
public:
	Item();

	void SpawnItem(cocos2d::Layer * layer);

	void SpawnItemFromSide(cocos2d::Layer *layer);

private:

	cocos2d::Size visibleSize;

	cocos2d::Vec2 origin;
};

#endif // __ITEM_H__
