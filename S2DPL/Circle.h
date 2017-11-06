#ifndef CIRCLE_H
#define CIRCLE_H
#include "Primitiv.h"
namespace s2dpl
{
	class Circle :
		public s2dpl::Primitiv
	{
	public:

		//инициализация
		Circle();
		Circle(b2World& world, sf::RenderWindow& window, sf::Vector2f pos, float r, int type);
		Circle(b2World& world, sf::RenderWindow& window, sf::Vector2f pos, float r, float density, int type);
		Circle(b2World& world, sf::RenderWindow& window, sf::Vector2f pos, float r, float density, float friction, float elasticity, int type, uint16 im, uint16 icol);
		Circle(b2World& world, sf::RenderWindow& window, sf::Vector2f pos, float r, float density, float elasticity, float friction, int type);


		~Circle();
	};
}
#endif