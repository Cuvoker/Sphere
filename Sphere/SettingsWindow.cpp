#include "SettingsWindow.h"


SettingsWindow::SettingsWindow()
{
	window = new RenderWindow(VideoMode(heightWindow, widthWindow), "Settings");
	changeSize = new TextField();
	changeVx = new TextField();
	changeVy = new TextField();
	changeDisappear = new TextField();
	changeWriteSpeed = new TextField();
	changeFlightMode = new TextField();
	changeTailMode = new TextField();

	setSizeCircle();
	setSpeedXCircle();
	setSpeedYCircle();
	setDisappearCircle();
	setWriteSpeed();
	setFlightMode();
	setTailMode();
}

SettingsWindow::~SettingsWindow()
{
	delete changeSize;
	delete changeVx;
	delete changeVy;
	delete changeDisappear;
	delete changeWriteSpeed;
	delete changeFlightMode;
	delete changeTailMode;
	delete window;
}


inline void SettingsWindow::update(int elapsed)
{
	Event event;
	while (window->pollEvent(event))
	{
		if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::E)) {
			window->close();
		}
		changeSize->input(event);
		changeVx->input(event);
		changeVy->input(event);
		changeDisappear->input(event);
		changeWriteSpeed->input(event);
		changeFlightMode->input(event);
		changeTailMode->input(event);
	}
}

inline void SettingsWindow::draw()
{
	window->clear();

	changeSize->render(window);
	changeVx->render(window);
	changeVy->render(window);
	changeDisappear->render(window);
	changeWriteSpeed->render(window);
	changeFlightMode->render(window);
	changeTailMode->render(window);

	window->display();
}

void SettingsWindow::start()
{
	window->setFramerateLimit(Max_Framerate);

	Clock clock;

	while (window->isOpen())
	{
		int elapsed = clock.restart().asMilliseconds();

		update(elapsed);

		draw();
	}
}

void SettingsWindow::setSizeCircle()
{
	changeSize->setPosition(Vector2f(200, 20));
	changeSize->setFont();  
	changeSize->setLength(20);
	changeSize->setText("Write Size: ");	
}

float SettingsWindow::geSizeCircle(float num)
{
	std::string s = changeSize->getText();

	if (s.empty()) {
		changeSize->setTxt(num);
		s = changeSize->getText();
		auto string = std::stof(s);
		return string;
	}

	else {
		auto string = std::stof(s);
		return string;
	}
}

void SettingsWindow::setSpeedXCircle()
{
	changeVx->setPosition(Vector2f(200, 80));
	changeVx->setFont();
	changeVx->setLength(20);
	changeVx->setText("Write Speed x: ");
}

float SettingsWindow::getSpeedXCircle(float num)
{
	std::string s = changeVx->getText();

	if (s.empty()) {
		changeVx->setTxt(num);
		s = changeVx->getText();
		auto string = std::stof(s);
		return string;
	}

	else {
		auto string = std::stof(s);
		return string;
	}
}

void SettingsWindow::setSpeedYCircle()
{
	changeVy->setPosition(Vector2f(200, 140));
	changeVy->setFont();
	changeVy->setLength(20);
	changeVy->setText("Write Speed y: ");
}

float SettingsWindow::getSpeedYCircle(float num)
{
	std::string s = changeVy->getText();

	if (s.empty()) {
		changeVy->setTxt(num);
		s = changeVy->getText();
		auto string = std::stof(s);
		return string;
	}

	else {
		auto string = std::stof(s);
		return string;
	}
}

void SettingsWindow::setDisappearCircle()
{
	changeDisappear->setPosition(Vector2f(200, 200));
	changeDisappear->setFont();
	changeDisappear->setLength(20);
	changeDisappear->setText("Write Time dis: ");
}

float SettingsWindow::getDisappearCircle(float num)
{
	std::string s = changeDisappear->getText();

	if (s.empty()) {
		changeDisappear->setTxt(num);
		s = changeDisappear->getText();
		auto string = std::stof(s);
		return string;
	}

	else {
		auto string = std::stof(s);
		return string;
	}
}

void SettingsWindow::setWriteSpeed()
{
	changeWriteSpeed->setPosition(Vector2f(200, 260));
	changeWriteSpeed->setFont();
	changeWriteSpeed->setLength(20);
	changeWriteSpeed->setText("Speed write: ");
}

int SettingsWindow::getWriteSpeed(int num, float& timeToWrite, float& timerToWrite)
{
	std::string s = changeWriteSpeed->getText();
	int string;
	if (s.empty()) {
		changeWriteSpeed->setTxt(num);
		s = changeWriteSpeed->getText();
		string = std::stof(s);
	}
	else {
		string = std::stof(s);
	}

	switch (string)
	{
	case 0: 
		//для 15 измерений
		timeToWrite = 115;//время, через какое должны записываться координаты
		timerToWrite = 115;//таймер для подчёта времени записи
		return 0;
		break;
	case 1:
		//для 18 измерений
		timeToWrite = 95;//время, через какое должны записываться координаты
		timerToWrite = 95;//таймер для подчёта времени записи
		return 1;
		break;
	case 2:
		//для 22.5 измерений
		timeToWrite = 73;//время, через какое должны записываться координаты
		timerToWrite = 73;//таймер для подчёта времени записи
		return 2;
		break;
	case 3:
		//для 30 измерений
		timeToWrite = 51;//время, через какое должны записываться координаты
		timerToWrite = 51;//таймер для подчёта времени записи
		return 3;
		break;
	case 4:
		//для 45 измерений
		timeToWrite = 30;//время, через какое должны записываться координаты
		timerToWrite = 30;//таймер для подчёта времени записи
		return 4;
		break;
	case 5:
		//для 90 измерений
		timeToWrite = 9;//время, через какое должны записываться координаты
		timerToWrite = 9;//таймер для подчёта времени записи
		return 5;
		break;
	default:
		break;
	}
}

void SettingsWindow::setFlightMode()
{
	changeFlightMode->setPosition(Vector2f(200, 320));
	changeFlightMode->setFont();
	changeFlightMode->setLength(20);
	changeFlightMode->setText("Flyight Mode : ");
}

int SettingsWindow::getFlightMode(int num)
{
	std::string s = changeFlightMode->getText();
	int string;
	if (s.empty()) {
		changeFlightMode->setTxt(num);
		s = changeFlightMode->getText();
		string = std::stof(s);
	}
	else {
		string = std::stof(s);
	}

	switch (string)
	{
	case 0:
		return 0;
	case 1:
		return 1;
	default:
		break;
	}
}

void SettingsWindow::setTailMode()
{
	changeTailMode->setPosition(Vector2f(200, 380));
	changeTailMode->setFont();
	changeTailMode->setLength(20);
	changeTailMode->setText("Tail : ");
}

int SettingsWindow::getTailMode(int num)
{
	std::string s = changeTailMode->getText();
	int string;
	if (s.empty()) {
		changeTailMode->setTxt(num);
		s = changeTailMode->getText();
		string = std::stof(s);
	}
	else {
		string = std::stof(s);
	}

	switch (string)
	{
	case 0:
		return 0;
	case 1:
		return 1;
	default:
		break;
	}
}
