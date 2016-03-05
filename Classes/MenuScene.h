#ifndef __MENU_SCENE_H__
#pragma once
#include "cocos2d.h"

class MenuScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(MenuScene);
private:
	void GoToGameScene(cocos2d::Ref *sender);
};

#endif // __MENU_SCENE_H__