#include "MainWindow.h"

MainWindow::MainWindow()
{
	window = new RenderWindow(VideoMode::getDesktopMode(), "Sphere!");
	circle = new Circle;
	line = new VertexArray();
	
	

	textSize = new Text();
	textVx = new Text();
	textVy = new Text();
	textDisappear = new Text();
	textSpeed = new Text();
	textFlightMode = new Text();
	textTailMode = new Text();

	srand(time(NULL));
}

MainWindow::~MainWindow()
{
	delete circle;
	delete window;
	delete line;

	delete textSize;
	delete textVx;
	delete textVy;
	delete textDisappear;
	delete textSpeed;
	delete textFlightMode;
	delete textTailMode;
}


inline void MainWindow::update(int elapsed)
{
	Event event;
	while (window->pollEvent(event))
	{
		if (event.type == Event::Closed) {
			window->close();
		}
		if (Keyboard::isKeyPressed(Keyboard::P)) {
			window->waitEvent(event);
			//создаём всплывающее окно
			createSettingsWindow();
		}
		//увеличиваем размер
		if (Keyboard::isKeyPressed(Keyboard::Equal) && circle->getRadius() < 400) {
			circle->setRadius(circle->getRadius() + 1);
		}
		//уменьшаем размер
		if (Keyboard::isKeyPressed(Keyboard::Hyphen) && circle->getRadius() > 3) {
			circle->setRadius(circle->getRadius() - 1);
		}

		//повышаем скорость по оси y
		if (Keyboard::isKeyPressed(Keyboard::Up) && circle->getVy() < 100) {
			circle->setVy(circle->getVy() + 10);
		}
		//уменьшаем скорость по оси y
		if (Keyboard::isKeyPressed(Keyboard::Down) && circle->getVy() > 1) {
			circle->setVy(circle->getVy() - 10);
		}
		//повышаем скорость по оси x
		if (Keyboard::isKeyPressed(Keyboard::Right) && circle->getVx() < 100) {
			circle->setVx(circle->getVx() + 10);
		}
		//уменьшаем скорость по оси x
		if (Keyboard::isKeyPressed(Keyboard::Left) && circle->getVx() > 1) {
			circle->setVx(circle->getVx() - 10);
		}
	}
}

inline void MainWindow::draw()
{
	window->clear();

	circle->draw(window);

	window->draw(*textSize);
	window->draw(*textVx);
	window->draw(*textVy);
	window->draw(*textDisappear);
	window->draw(*textSpeed);
	window->draw(*textFlightMode);
	window->draw(*textTailMode);

	window->draw(*line);

	window->display();
}

void MainWindow::start()
{
	int i = 1;
	auto dd = 0;

	window->setFramerateLimit(Max_Framerate);

	createSettingsWindow();

	VideoMode vectorWindow = VideoMode::getDesktopMode();//координаты окна
	this->heightWindow = vectorWindow.height;
	this->widthWindow = vectorWindow.width;

	Clock clock;

	float timerToDisappear = 8000;//через какое время будет исчезновение

	float timer = 0;//таймер для наступления пропадния
	float t = 0;//таймер для счёта времени пропадания

	//запись файла по времени
	std::time_t ti = std::time(nullptr);
	std::tm* now = localtime(&ti);
	char buffer[128];
	char csv[5] = ".csv";
	strftime(buffer, sizeof(buffer), "%c", now);
	std::string str = buffer;
	str += csv;
	std::replace(str.begin(), str.end(), ':', '-');

	std::ofstream myfile;
	
	myfile.open(str, std::ios_base::app);

	// для указания времени записи
	char tmpbuf[128];
	struct __timeb32 tstruct;
	__time32_t long_time;
	struct tm newtime;

	//шлейф
	int timerVertex = 0;
	Vector2f vec;
	VertexArray lines(Lines, 2);

	_tzset();

	while (window->isOpen())
	{
		setTextSize();
		setTextVx();
		setTextVy();
		setTextDisappear();
		setWriteText();
		setTextFlightMode();
		setTextTailMode();
		
		int elapsed = clock.getElapsedTime().asMilliseconds();
		clock.restart();

		//шлейф
		if (Tail == 1) {

			vec.x = circle->getVx();
			vec.y = circle->getVy();

			

			if (vec.x < 0 && vec.y > 0) {
				lines[0].position = Vector2f(circle->getCenterCircleX() - circle->getRadius() * 3 * (circle->getVx() / circle->getVx() * -1), circle->getCenterCircleY() - circle->getRadius() * 3);
				lines[1].position = Vector2f(circle->getCenterCircleX(), circle->getCenterCircleY());
			}
			if (vec.x > 0 && vec.y < 0) {
				lines[0].position = Vector2f(circle->getCenterCircleX() - circle->getRadius() * 3, circle->getCenterCircleY() - circle->getRadius() * 3 * (circle->getVy() / circle->getVy() * -1));
				lines[1].position = Vector2f(circle->getCenterCircleX(), circle->getCenterCircleY());
			}
			if (vec.x > 0 && vec.y > 0) {
				lines[0].position = Vector2f(circle->getCenterCircleX() - circle->getRadius() * 3 * (circle->getVx() / circle->getVx()), circle->getCenterCircleY() - circle->getRadius() * 3 * (circle->getVy() / circle->getVy()));
				lines[1].position = Vector2f(circle->getCenterCircleX(), circle->getCenterCircleY());
			}
			if (vec.x < 0 && vec.y < 0) {
				lines[0].position = Vector2f(circle->getCenterCircleX() - circle->getRadius() * 3 * (circle->getVx() / circle->getVx() * -1), circle->getCenterCircleY() - circle->getRadius() * 3 * (circle->getVy() / circle->getVy() * -1));
				lines[1].position = Vector2f(circle->getCenterCircleX(), circle->getCenterCircleY());
			}

			line = &lines;
		}
		

		//пропадание
		timer += elapsed;
		
		if (timer > timerToDisappear) {
			circle->changeColor();//меняем цвет
			circle->flagDis = 0;
			//меняем цвет шлейфа//меняем цвет шлейфа
			lines[0].color = Color::Black;
			lines[1].color = Color::Black;

			if (t > circle->getDisappear()) {
				circle->setColor();//возвращаем цвет
				circle->flagDis = 1;

				//меняем цвет шлейфа//меняем цвет шлейфа
				lines[0].color = Color::White;
				lines[1].color = Color::White;

				timer = 0;
				timerToDisappear = 5000 + rand() % 9001;//рандомное время до следующего исчезновения
			}
			else t += elapsed;
		}
		else if (t != 0) t = 0;
		
		update(elapsed);

		//движение
		moveCircle(FlightMode);
		
		draw();

		//запись координат
		dd += elapsed;
		timerToWrite += elapsed;
			if (timerToWrite >= timeToWrite) {
				Write(myfile, elapsed, tstruct, long_time, newtime);
				timerToWrite = 0;
			}
			else timerToWrite += elapsed;

	}
}

void MainWindow::createSettingsWindow()
{
	settingsWindow = new SettingsWindow();
	settingsWindow->start();
	//размер
	settingsWindow->setSizeCircle();
	float oldSize = circle->getRadius();
	float size = settingsWindow->geSizeCircle(oldSize);
	circle->setRadius(size);

	//скорость по x
	settingsWindow->setSpeedXCircle();
	float oldSpeedX = circle->getVx();
	float speedX = settingsWindow->getSpeedXCircle(oldSpeedX);
	circle->setVx(speedX);
	//скорость по y
	settingsWindow->setSpeedYCircle();
	float oldSpeedY = circle->getVy();
	float speedY = settingsWindow->getSpeedYCircle(oldSpeedY);
	circle->setVy(speedY);

	//пропадание
	settingsWindow->setDisappearCircle();
	float oldDisappear = circle->getDisappear();
	float disappear = settingsWindow->getDisappearCircle(oldDisappear);
	circle->setDisappear(disappear);

	//скорость записи
	settingsWindow->setWriteSpeed();
	int oldSpeedWrite = getTextSpeed();
	int SpeedWrite = settingsWindow->getWriteSpeed(oldSpeedWrite, timeToWrite, timerToWrite);
	setTextSpeed(SpeedWrite);

	//режим полёта
	settingsWindow->setFlightMode();
	int OldFlightMode = getFlightMode();
	int FlightMode = settingsWindow->getFlightMode(OldFlightMode);
	setFlightMode(FlightMode);

	//шлейф
	settingsWindow->setTailMode();
	int OldTail = getTailMode();
	int Tail = settingsWindow->getTailMode(OldTail);
	setTailMode(Tail);

	circle->setX(0);
	circle->setY(0);
}

void MainWindow::moveCircle(int mode)
{
	if (mode == 0) {
		if (circle->getX() < 0 || circle->getX() > this->widthWindow - circle->getRadius() * 2) {

			circle->setVx(circle->getVx() * -1);
		}
		if (circle->getY() < 0 || circle->getY() > this->heightWindow - circle->getRadius() * 2) {

			circle->setVy(circle->getVy() * -1);
		}
	}

	if (mode == 1) {
		bool crossX = false;

		if (circle->getX() + circle->getRadius() > this->widthWindow && circle->getX() < this->widthWindow) {
			circle->setX(circle->getX() - this->widthWindow);
			crossX = true;
		}
		else if (-widthWindow < circle->getX() && circle->getX() < 0) {
			circle->setX(circle->getX() + this->widthWindow);
			crossX = true;
		}
		else if (crossX) {
			if (0 > circle->getX() || circle->getX() > this->widthWindow) {
				circle->setX(0 - circle->getRadius());
				crossX = false;
			}
		}

		if (circle->getY() + circle->getRadius() > this->heightWindow && circle->getY() < this->heightWindow) {
			circle->setY(0 - circle->getRadius());
		}
	}

	circle->setX(circle->getX() + circle->getVx());
	circle->setY(circle->getY() + circle->getVy());

}

void MainWindow::setTextSize()
{
	setFont(textSize);
	textSize->setCharacterSize(16);
	textSize->setFillColor(sf::Color::White);
	textSize->setPosition(5, 60);
	std::string s = std::to_string(static_cast<int>(circle->getRadius()));
	textSize->setString("Size: " + s);
}
void MainWindow::setTextVx()
{
	setFont(textVx);
	textVx->setCharacterSize(16);
	textVx->setFillColor(sf::Color::White);
	textVx->setPosition(5, 80);
	std::string s = std::to_string(static_cast<int>(circle->getVx()));
	textVx->setString("Vx: " + s);

}
void MainWindow::setTextVy()
{
	setFont(textVy);
	textVy->setCharacterSize(16);
	textVy->setFillColor(sf::Color::White);
	textVy->setPosition(5, 100);
	std::string s = std::to_string(static_cast<int>(circle->getVy()));
	textVy->setString("Vy: " + s);
}
void MainWindow::setTextDisappear()
{
	setFont(textDisappear);
	textDisappear->setCharacterSize(16);
	textDisappear->setFillColor(sf::Color::White);
	textDisappear->setPosition(5, 120);
	std::string s = std::to_string(static_cast<int>(circle->getDisappear()));
	textDisappear->setString("Disappear: " + s);
}

void MainWindow::setWriteText()
{
	setFont(textSpeed);
	textSpeed->setCharacterSize(16);
	textSpeed->setFillColor(sf::Color::White);
	textSpeed->setPosition(5, 140);
	std::string s = std::to_string(SpeedWrite);
	textSpeed->setString("Speed: " + s);
}

void MainWindow::setTextFlightMode()
{
	setFont(textFlightMode);
	textFlightMode->setCharacterSize(16);
	textFlightMode->setFillColor(sf::Color::White);
	textFlightMode->setPosition(5, 160);
	std::string s = std::to_string(FlightMode);
	textFlightMode->setString("FlightMode: " + s);
}
void MainWindow::setTextTailMode()
{
	setFont(textTailMode);
	textTailMode->setCharacterSize(16);
	textTailMode->setFillColor(sf::Color::White);
	textTailMode->setPosition(5, 180);
	std::string s = std::to_string(Tail);
	textTailMode->setString("Tail: " + s);
}
int MainWindow::getFlightMode()
{
	return this->FlightMode;
}

void MainWindow::setFlightMode(int FlightMode)
{
	this->FlightMode = FlightMode;
}

int MainWindow::getTailMode()
{
	return this->Tail;
}

void MainWindow::setTailMode(int Tail)
{
	this->Tail = Tail;
}

int MainWindow::getTextSpeed()
{
	return this->SpeedWrite;
}
void MainWindow::setTextSpeed(int SpeedWrite)
{
	this->SpeedWrite = SpeedWrite;

}

void MainWindow::setFont(Text* text)
{
	f.loadFromFile("Mona-Sans.ttf");
	text->setFont(f);
}
void MainWindow::Write(std::ofstream& myfile, int &elapsed, __timeb32& tstruct, __time32_t& long_time, tm& newtime)
{
	timerToWrite += elapsed;
	 
	_ftime32_s(&tstruct);

	_time32(&long_time);
	_localtime32_s(&newtime, &long_time);

	std::string hour = std::to_string(newtime.tm_hour);
	std::string min = std::to_string(newtime.tm_min);
	std::string sec = std::to_string(newtime.tm_sec);
	std::string ms = std::to_string(tstruct.millitm);
	std::string x = std::to_string(static_cast<int>(circle->getCenterCircleX()));
	std::string y = std::to_string(static_cast<int>(circle->getCenterCircleY()));
	std::string dis = std::to_string(static_cast<int>(circle->flagDis));
	
	myfile << hour + ";" + min + ";" + sec + ";" + ms + ";;" + x + ";" + y + ";" + dis + "\n";
}