#ifndef _MYSPRITE_H_
#define _MYSPRITE_H_

#include "cocos2d.h"

//�� ��������� ���� ����� �� ������ Sprite
class ActiveSprite : public cocos2d::Sprite
{
protected:
	//���������� ������ ��� ����� ������� ������������� �������.
	//����� ������ ��������� ������ �������������

	//������������� ����� � ���������� �������
	void _initOptions();

	//����������� ������� � �������
	void _addEvents();

	//�����, ������� ���������� ��� "�������������" � ����� �������
	void _touchEvent(cocos2d::Touch* touch);

public:
	ActiveSprite();
	~ActiveSprite();

	//��������� ����� �������� �������� �������
	static ActiveSprite* create();
};

#endif // _MYSPRITE_H_
