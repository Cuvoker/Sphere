#pragma once

#ifndef TXTFIELD_H
#define TXTFIELD_H

#include <string>
#include <SFML/Graphics.hpp>

using namespace sf;


const int GUI_TEXT_MAX = 24;

const int GUI_TEXT_BACKSPACE = 8;
const int GUI_TEXT_ESCAPE = 27;

const Color GUI_TEXT_GRAY = Color(105, 105, 105);

class TextField {
public:
	TextField();
	~TextField();

	void setPosition(sf::Vector2f vec);

	void input(sf::Event ev);

	void setFont();

	const sf::String& getText();

	void setText(std::string str);

	void render(sf::RenderWindow* window);

	void setLength(int arg);

	int getTextLength();

	bool isActive();

	void open();


	void setTxt(float Radius);
private:
	Text* txt;
	Text* text;
	RectangleShape* box;

	int size;

	int length;

	bool renderPlaceholder;

	void setActive(bool arg);

	bool active;

	Vector2f pos;

	std::string placeholder;

	Font f;
};

#endif