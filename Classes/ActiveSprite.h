#ifndef _MYSPRITE_H_
#define _MYSPRITE_H_

#include "cocos2d.h"

//Мы наследуем свой класс от класса Sprite
class ActiveSprite : public cocos2d::Sprite
{
protected:
	//Защищённые методы для более удобной инициализации объекта.
	//Здесь просто разделяем логику инициализации

	//Инициализация опций и параметров объекта
	void _initOptions();

	//Подключение событий к объекту
	void _addEvents();

	//Метод, который вызывается при "прикосновении" к этому объекту
	void _touchEvent(cocos2d::Touch* touch);

public:
	ActiveSprite();
	~ActiveSprite();

	//Фабричный метод создания текущего объекта
	static ActiveSprite* create();
};

#endif // _MYSPRITE_H_
