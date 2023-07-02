#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <SFML/Graphics.hpp>
#include <fstream>
#include <ctime>
#include <iostream>
#include <sys/timeb.h>
#include <sys/timeb.h>
#include <algorithm>


#include "Circle.h"
#include "SettingsWindow.h"
#include "TextField.h"



using namespace sf;

class MainWindow
{
	RenderWindow* window;
	SettingsWindow* settingsWindow;
	Circle* circle;
	VertexArray* line; 
	
	Text* textSize;
	Text* textVx;
	Text* textVy;
	Text* textDisappear;
	Text* textSpeed;
	Text* textFlightMode;
	Text* textTailMode;

	sf::Font f;
	//режим скорости записи
	int SpeedWrite = 0;

	//режим полёта
	int FlightMode = 0;

	//включить или выключить шлейф
	int Tail = 0;

	float timeToWrite = 1;//время, через какое должны записываться координаты
	float timerToWrite = 1;//таймер для подчёта времени записи

	const int Max_Framerate = 90;

	int heightWindow;
	int widthWindow;
	//события (закрыть окно, нажатие кнопок и тд)
	void update(int elapsed);

	//отрисовка объектов
	void draw();

public:
	MainWindow();
	~MainWindow();

	//начало работы программы
	void start();

	//создание окна настроек
	void createSettingsWindow();

	//движение объекта
	void moveCircle(int mode);

	//показывает значение размера в главном экране
	void setTextSize();

	//показывает скорость по x в главном экране
	void setTextVx();

	//показывает скорость по y в главном экране
	void setTextVy();

	//показывает время исчезновения в главном экране
	void setTextDisappear();

	//передаём режим скорости записи
	int getTextSpeed();

	//устанавливаем режим скорости записи
	void setTextSpeed(int SpeedWrite);

	//показывает режим полёта в главном экране
	void setTextFlightMode();

	//показывает режим шлейфа в главном экране
	void setTextTailMode();

	//показывает режим записи в главном экране
	void setWriteText();

	//передать режим полёта
	int getFlightMode();

	//установить режим полёта
	void setFlightMode(int FlightMode);

	//передать режим шлейфа
	int getTailMode();

	//установить режим шлейфа
	void setTailMode(int Tail);

	//шрифт
	void setFont(Text* text);
	//запись в Excel файл(формат csv)
	void Write(std::ofstream &myfile, int &elapsed, struct __timeb32& tstruct, __time32_t& long_time, struct tm& newtime);
};