#include "TextField.h"

TextField::TextField() {
	active = false;

	box = new RectangleShape();
	txt = new Text();
	text = new Text();

	box->setFillColor(Color::White);
	box->setOutlineThickness(3);

	renderPlaceholder = false;
	placeholder = "";

	text->setFillColor(Color::White);

	txt->setFillColor(Color::Black);

	size = GUI_TEXT_MAX;

	length = 0;
}

TextField::~TextField()
{
	delete txt;
	delete text;
	delete box;
}

void TextField::setTxt(float Radius)
{
	std::string str = std::to_string(Radius);
	txt->setString(str);
}

void TextField::setPosition(Vector2f vec) {
	box->setPosition(vec);
	txt->setPosition(vec + Vector2f(5, 5));
	text->setPosition(10, vec.y);
}

void TextField::input(sf::Event ev) {
	if (ev.type == sf::Event::MouseButtonReleased) {
		sf::Vector2f pos(ev.mouseButton.x, ev.mouseButton.y);
		if (box->getGlobalBounds().contains(pos)) {
			setActive(true);
		}
		else {
			setActive(false);
		}
	}

	if (ev.type == sf::Event::TextEntered && active) {
		sf::String str = txt->getString();

		if (ev.text.unicode == GUI_TEXT_BACKSPACE) {
			if (str.getSize() > 0) {
				length--;
				str = str.substring(0, str.getSize() - 1);
			}
		}
		else if (ev.text.unicode == GUI_TEXT_ESCAPE) {
			setActive(false);
		}
		else {
			sf::String sfstr = "";
			sfstr += ev.text.unicode;
			str += sfstr.toAnsiString();
		}

		if (str.getSize() == size) return;

		txt->setString(str);


		length++;
	}
}

void TextField::setFont() {
	
	f.loadFromFile("Mona-Sans.ttf");
	txt->setFont(f);
	txt->setCharacterSize(24);

	text->setFont(f);
	text->setCharacterSize(24);

	box->setSize(sf::Vector2f((txt->getCharacterSize() * (size / 2 + 1)) + 10, txt->getCharacterSize() + 10));
}

const sf::String& TextField::getText() {
	return txt->getString();
}



void TextField::setText(std::string str)
{
	text->setString(str);
}

void TextField::render(sf::RenderWindow* window) {
	window->draw(*text);
	window->draw(*box);
	window->draw(*txt);
}

void TextField::setActive(bool arg) {
	active = arg;
	if (active) {
		box->setOutlineColor(sf::Color::Red);
	}
	else {
		box->setOutlineColor(sf::Color::White);
	}

	if (renderPlaceholder && arg) {
		renderPlaceholder = false;
		txt->setString("");
		txt->setFillColor(sf::Color::Black);
	}
}

void TextField::setLength(int arg) {
	size = arg;

	box->setSize(sf::Vector2f((txt->getCharacterSize() * (size / 2 + 1)) + 10, txt->getCharacterSize() + 10));
}

int TextField::getTextLength() {
	return length;
}

bool TextField::isActive() {
	return active;
}

void TextField::open() {
	setActive(true);
}

