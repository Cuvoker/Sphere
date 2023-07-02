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
	//����� �������� ������
	int SpeedWrite = 0;

	//����� �����
	int FlightMode = 0;

	//�������� ��� ��������� �����
	int Tail = 0;

	float timeToWrite = 1;//�����, ����� ����� ������ ������������ ����������
	float timerToWrite = 1;//������ ��� ������� ������� ������

	const int Max_Framerate = 90;

	int heightWindow;
	int widthWindow;
	//������� (������� ����, ������� ������ � ��)
	void update(int elapsed);

	//��������� ��������
	void draw();

public:
	MainWindow();
	~MainWindow();

	//������ ������ ���������
	void start();

	//�������� ���� ��������
	void createSettingsWindow();

	//�������� �������
	void moveCircle(int mode);

	//���������� �������� ������� � ������� ������
	void setTextSize();

	//���������� �������� �� x � ������� ������
	void setTextVx();

	//���������� �������� �� y � ������� ������
	void setTextVy();

	//���������� ����� ������������ � ������� ������
	void setTextDisappear();

	//������� ����� �������� ������
	int getTextSpeed();

	//������������� ����� �������� ������
	void setTextSpeed(int SpeedWrite);

	//���������� ����� ����� � ������� ������
	void setTextFlightMode();

	//���������� ����� ������ � ������� ������
	void setTextTailMode();

	//���������� ����� ������ � ������� ������
	void setWriteText();

	//�������� ����� �����
	int getFlightMode();

	//���������� ����� �����
	void setFlightMode(int FlightMode);

	//�������� ����� ������
	int getTailMode();

	//���������� ����� ������
	void setTailMode(int Tail);

	//�����
	void setFont(Text* text);
	//������ � Excel ����(������ csv)
	void Write(std::ofstream &myfile, int &elapsed, struct __timeb32& tstruct, __time32_t& long_time, struct tm& newtime);
};