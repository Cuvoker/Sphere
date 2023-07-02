#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Circle
{
    CircleShape* circle;
    //координаты
    float x = 0.0f,
        y = 0.0f;
    //скорость по осям x и y
    float Vx = 5,
        Vy = 5;

    float Radius = 30.f;

    float disappear = 0;//время исчезновения
    

public:
    Circle();
    ~Circle();
    void setColor();
    void changeColor();
    void draw(RenderWindow* window);
    float getX();
    float getY();
    float getVx();
    float getVy();
    float getRadius();
    float getDisappear();
    //центр фигуры
    float getCenterCircleX();
    float getCenterCircleY();

    void setX(float x);
    void setY(float y);
    void setVx(float Vx);
    void setVy(float Vy);
    void setRadius(float Radius);
    void setDisappear(float disappear);

    //сфера исчезла или нет
    int flagDis = 1;
};