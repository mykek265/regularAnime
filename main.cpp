#include <SFML/Graphics.hpp>
#include <iostream>
#include "s2dpl.h"
#include "windowSize.h"
#include "MyTest\MyTest.h"
//================================================
float ZOOM = 1;
sf::Font mainFont;
sf::Text str1, str2;
sf::View cam1;
//================================================
void Load(sf::RenderWindow& window, b2World& world);
void setSubConsole(sf::Vector2f& mouse);
sf::Vector2f getMousePos(sf::RenderWindow& window);
//================================================
int main()
{
	//-----------------------------------------------
	//--Инициализация окна, мира и всего остального--
	//-----------------------------------------------
	sf::ContextSettings settings;
	settings.antialiasingLevel = 8;
	sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Cool Stuff Editor", (fullscrin ? sf::Style::Fullscreen : sf::Style::Default), settings);
	b2World world(b2Vec2(0, -9.832f));
	Load(window, world);
	//std::string display = "";
	//--------------------------------------------------
	MyTest::setWindow(window);
	MyTest::setWorld(world);
	MyTest test;
	//--------------------------------------------------
	bool trr = true;
	while (window.isOpen())
	{
		//==============================================
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			//-----------Прокручивание колеса-----------
			if (event.type == sf::Event::MouseWheelMoved)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
				{
					if (event.mouseWheel.delta < 0)	ZOOM += .01f;
					if (event.mouseWheel.delta > 0)	ZOOM -= .01f;
				}
			}
			//------------------------------------------
			/*--Ввод текста--*/
			//if (event.type == sf::Event::TextEntered)
			//{
			//	if (event.text.unicode >= 33 && event.text.unicode <= 126)
			//		display += (char)event.text.unicode;
			//	else if (event.text.unicode == 8)
			//		display = display.substr(0, display.length() - 1);
			//	system("cls");
			//	std::cout << display;
			//}
		}
		//==============================================
		world.Step(1 / 60.f, 8, 3);
		sf::Vector2f mouse = getMousePos(window);
		if (sf::Mouse::isButtonPressed(sf::Mouse::Middle) && sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
			cam1.setSize(WIDTH, HEIGHT);
		setSubConsole(mouse);
		//==============================================
		cam1.zoom(ZOOM);
		ZOOM = 1;
		if (trr)
		{
			ZOOM = 2.f;
			trr = false;
		}
		//==============================================
		window.setView(cam1);
		window.clear();
		window.draw(str1);
		test.draw();
		window.display();
	}

	return 0;
}
//------------------------------------------------
void Load(sf::RenderWindow& window, b2World& world)
{
	window.setFramerateLimit(70);
	world.SetContactListener(&s2dpl::myContactListener);
	cam1.setSize(sf::Vector2f(window.getSize()));
	cam1.setCenter(sf::Vector2f(window.getSize())*0.5f);
	//--------------------------------------------
	//--------Подготовка главного шрифта----------
	//--------------------------------------------
	mainFont.loadFromFile("10506.ttf");
	str1.setFont(mainFont);
	str1.setColor(sf::Color(216, 170, 41, 255));
	str1.setCharacterSize(14);
	//--------------------------------------------
	str2 = str1;
	s2dpl::Sensor::init(world, window);
}
void setSubConsole(sf::Vector2f& mouse)
{
	str1.setPosition(cam1.getCenter() - sf::Vector2f(WIDTH*0.5f, HEIGHT*0.5f));
	str1.setString("Stuff Animator\ncamera("
		+ toString(cam1.getCenter().x) + ", " + toString(cam1.getCenter().y)
		+ ")(" + toString(cam1.getSize().x) + ", " + toString(cam1.getSize().y)
		+ ")\n" + "mouse(" + toString(mouse.x) + ", " + toString(mouse.y) + ")"
		);
}
sf::Vector2f getMousePos(sf::RenderWindow& window)
{
	return (sf::Vector2f(sf::Mouse::getPosition(window)) - sf::Vector2f(window.getSize().x *0.5f, window.getSize().y *0.5f))*(cam1.getSize().x / WIDTH) + cam1.getCenter();
}