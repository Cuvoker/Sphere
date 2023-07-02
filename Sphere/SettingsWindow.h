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

	//меняем скорость
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

	//отрисовка объектов
	void draw();

public:

	SettingsWindow();
	~SettingsWindow();

	void start();

	//размер
	void setSizeCircle();
	float geSizeCircle(float num);

	//скорость по x
	void setSpeedXCircle();
	float getSpeedXCircle(float num);

	//скорость по y
	void setSpeedYCircle();
	float getSpeedYCircle(float num);

	//менять время пропадания
	void setDisappearCircle();
	float getDisappearCircle(float num);

	//скорость записи
	void setWriteSpeed();
	int getWriteSpeed(int num, float& timeToWrite, float& timerToWrite);

	//режим полёта
	void setFlightMode();
	int getFlightMode(int num);

	//шлейф
	void setTailMode();
	int getTailMode(int num);
};

