#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;

class Circle
{
    CircleShape* circle;
    //����������
    float x = 0.0f,
        y = 0.0f;
    //�������� �� ���� x � y
    float Vx = 5,
        Vy = 5;

    float Radius = 30.f;

    float disappear = 0;//����� ������������
    

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
    //����� ������
    float getCenterCircleX();
    float getCenterCircleY();

    void setX(float x);
    void setY(float y);
    void setVx(float Vx);
    void setVy(float Vy);
    void setRadius(float Radius);
    void setDisappear(float disappear);

    //����� ������� ��� ���
    int flagDis = 1;
};