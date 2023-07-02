#pragma once

#include<SFML/Graphics.hpp>
#include <string>
#include <ctime>
#include "TextField.h"

using namespace sf;

class SettingsWindow
{
	RenderWindow* window;

	TextField* changeSize;

	//������ ��������
	TextField* changeVx;
	TextField* changeVy;

	TextField* changeDisappear;

	TextField* changeWriteSpeed;

	TextField* changeFlightMode;

	TextField* changeTailMode;

	const int Max_Framerate = 90;

	int heightWindow = 800;
	int widthWindow = 600;

	void update(int elapsed);

	//��������� ��������
	void draw();

public:

	SettingsWindow();
	~SettingsWindow();

	void start();

	//������
	void setSizeCircle();
	float geSizeCircle(float num);

	//�������� �� x
	void setSpeedXCircle();
	float getSpeedXCircle(float num);

	//�������� �� y
	void setSpeedYCircle();
	float getSpeedYCircle(float num);

	//������ ����� ����������
	void setDisappearCircle();
	float getDisappearCircle(float num);

	//�������� ������
	void setWriteSpeed();
	int getWriteSpeed(int num, float& timeToWrite, float& timerToWrite);

	//����� �����
	void setFlightMode();
	int getFlightMode(int num);

	//�����
	void setTailMode();
	int getTailMode(int num);
};

