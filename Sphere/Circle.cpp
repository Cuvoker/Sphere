#include "Circle.h"

Circle::Circle()
{
	circle = new CircleShape(Radius);
	setColor();
	circle->setPosition(x, y);
}

Circle::~Circle()
{
	delete circle;
}

void Circle::setColor()
{
	circle->setFillColor(Color::White);
}

void Circle::changeColor()
{
	circle->setFillColor(Color::Black);
}


void Circle::draw(RenderWindow* window)
{
	window->draw(*circle);
}

float Circle::getX()
{
	return this->x;
}

float Circle::getY()
{
	return this->y;
}

float Circle::getVx()
{
	return this->Vx;
}

float Circle::getVy()
{
	return this->Vy;
}

float Circle::getRadius()
{
	return this->Radius;
}

float Circle::getDisappear()
{
	return this->disappear;
}

float Circle::getCenterCircleX()
{
	float x = getX();
	x += Radius;
	return x;
}

float Circle::getCenterCircleY()
{
	float y = getY();
	y += Radius;
	return y;
}

void Circle::setX(float x)
{
	this->x = x;
	circle->setPosition(this->x,this->y);
}

void Circle::setY(float y)
{
	this->y = y;
	circle->setPosition(this->x, this->y);
}

void Circle::setVx(float Vx)
{
	this->Vx = Vx;
	circle->move(this->Vx, this->Vy);
}

void Circle::setVy(float Vy)
{
	this->Vy = Vy;
	circle->move(this->Vx, this->Vy);
}

void Circle::setRadius(float Radius)
{
	this->Radius = Radius;
	circle->setRadius(this->Radius);
}

void Circle::setDisappear(float disappear)
{
	this->disappear = disappear;
}


