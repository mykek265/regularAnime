#ifndef MyTest_H
#define MyTest_H
#include "../s2dpl.h"

class MyTest
{
private:
	static b2World*				_world;
	static sf::RenderWindow*	_window;
	//------------------------------------------
	s2dpl::Box					_bpart0;
	s2dpl::Box					_bpart1;
	s2dpl::Box					_bpart2;
	s2dpl::Circle				_cpart0;
	s2dpl::Triangle				_tpart0;
	s2dpl::Primitiv				_part0;
	s2dpl::Primitiv				_part1;
	s2dpl::Primitiv				_part2;
	//------------------------------------------
	s2dpl::ServoRevJoint		_servoRevJ0;
	//------------------------------------------
	sf::Vector2f				_position{0.f, 0.f};
	sf::Vector2f				_scale{1.f, 1.f};
public:
	MyTest();
	~MyTest();

	void draw();
	void setPosition(const sf::Vector2f& pos);
	void setPosition(float x, float y);
	const sf::Vector2f& getPosition() const;
	static void setWorld(b2World& world);
	static void setWindow(sf::RenderWindow& window);
};
#endif