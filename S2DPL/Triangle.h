#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Primitiv.h"
namespace s2dpl
{
	class Triangle :
		public s2dpl::Primitiv
	{
	public:

		//инициализация
		Triangle();
		Triangle(b2World& world, sf::RenderWindow& window, sf::Vector2f pos, sf::Vector2f v3[], int type);
		Triangle(b2World& world, sf::RenderWindow& window, sf::Vector2f pos, sf::Vector2f v3[], float dencity, int type);
		Triangle(b2World& world, sf::RenderWindow& window, sf::Vector2f pos, sf::Vector2f v3[], float dencity, float elasticity, float friction, int type, uint16 im, uint16 icol);
		Triangle(b2World& world, sf::RenderWindow& window, sf::Vector2f pos, sf::Vector2f v0, sf::Vector2f v1, sf::Vector2f v2, float dencity, float elasticity, float friction, int type, uint16 im, uint16 icol);
		Triangle(b2World& world, sf::RenderWindow& window, sf::Vector2f pos, sf::Vector2f v3[], float dencity, float elasticity, float friction, int type);
		
		~Triangle();
	};
}

#endif