#pragma once
#include "cocos2d.h"
#include "Item.h"
#include "Water.h"

class GameScene : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();

    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();

    // implement the "static create()" method manually
    CREATE_FUNC(GameScene);

	size_t scorePoint;
private:

	void SetPhysicsWorld(cocos2d::PhysicsWorld *world) { sceneWorld = world; }

	void SpawnItem(float dt);

	void SpawnItemFromSide(float dt);

	void CheckGameCollision(cocos2d::PhysicsBody & first, cocos2d::PhysicsBody & second);

	bool onContactBegin(cocos2d::PhysicsContact &contact);

	cocos2d::PhysicsWorld *sceneWorld;

	Item item;

	Water water;

	cocos2d::Label *scoreLabel;

};

