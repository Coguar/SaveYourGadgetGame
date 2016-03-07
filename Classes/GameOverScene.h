#pragma once

#include "cocos2d.h"

class GameOverScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene(size_t templeScore);

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameOverScene);

	size_t score;

private:
	

	cocos2d::Label *scoreLabel;
	cocos2d::Label *hScoreLabel;

	void GoToMenuScene(cocos2d::Ref * sender);
};

