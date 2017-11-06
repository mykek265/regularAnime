#include "MyTest.h"
#include <iostream>
b2World*			MyTest::_world(NULL);
sf::RenderWindow*	MyTest::_window(NULL);

MyTest::MyTest()
	:
	_bpart0(*(MyTest::_world), *(MyTest::_window), sf::Vector2f(4.80084,  -80.3963)	+ _position, sf::Vector2f(25, 23), 1, 0.35, 0.05, 1, 0x0001, 0xFFFE),
	_bpart1(*(MyTest::_world), *(MyTest::_window), sf::Vector2f(192.604,  -170.597)	+ _position, sf::Vector2f(38, 27), 0, 0.35, 0.05, 0, 0x0002, 0xFFFF),
	_bpart2(*(MyTest::_world), *(MyTest::_window), sf::Vector2f(193.604,  -48.597)	+ _position, sf::Vector2f(9.5, 46), 1, 0.35, 0.05, 1, 0x0001, 0xFFFF),
	_cpart0(*(MyTest::_world), *(MyTest::_window), sf::Vector2f(50.8008,  -142.396)	+ _position, 31.0644, 1, 0.35, 0.05, 1, 0x0001, 0xFFFF),
	_tpart0(*(MyTest::_world), *(MyTest::_window), sf::Vector2f(-46.3963, -158.597)	+ _position, /*verti*/sf::Vector2f(-38.3333, 64.6667), sf::Vector2f(44.6667, -9.33333), sf::Vector2f(-6.33333, -55.3333)/*cales*/, 1, 0.35, 0.05, 1, 0x0001, 0xFFFE),
	//------------------------------------------
	_part0(*(MyTest::_world), *(MyTest::_window), sf::Vector2f(-18.1992, 93.6037), 0, 0.35, 0.05, 0, 2, 65535),
	_part1(*(MyTest::_world), *(MyTest::_window), sf::Vector2f(55.6037, -284.597), 1, 0.35, 0.05, 1, 1, 65534),
	_part2(*(MyTest::_world), *(MyTest::_window), sf::Vector2f(354.604, 245.403), 0, 0.35, 0.05, 0, 2, 65535),
	//==========================================
	_servoRevJ0(MyTest::_world, (s2dpl::Primitiv*)(&(_bpart1)), (s2dpl::Primitiv*)(&(_bpart2)), sf::Vector2f(1, 51), sf::Vector2f(0, -71))//,
{
	{
		//sf::Vector2f verticales[3] = { sf::Vector2f(-38.3333, 64.6667), sf::Vector2f(44.6667, -9.33333), sf::Vector2f(-6.33333, -55.3333) };
	}
	//------------------------------------------
	//_part[0] = s2dpl::Primitiv(*(MyTest::_world), *(MyTest::_window), sf::Vector2f(-18.1992, 93.6037), 0, 0.35, 0.05, 0, 0x0002, 0xFFFF);
	//_part[1] = s2dpl::Primitiv(*(MyTest::_world), *(MyTest::_window), sf::Vector2f(55.6037, -284.597), 1, 0.35, 0.05, 1, 0x0001, 0xFFFE);
	//_part[2] = s2dpl::Primitiv(*(MyTest::_world), *(MyTest::_window), sf::Vector2f(354.604, 245.403), 0, 0.35, 0.05, 0, 0x0002, 0xFFFF);
	////==========================================
	//_servoRevJ0 = new s2dpl::ServoRevJoint(MyTest::_world,/* *(MyTest::_window),*/ (s2dpl::Primitiv*)(&(_bpart1)), (s2dpl::Primitiv*)(&(_bpart2)), sf::Vector2f(1, 51), sf::Vector2f(0, -71));
	////------------------------------------------
	_part0.addRect(sf::Vector2f(19.5f, -2.5f), sf::Vector2f(114.5f, 28.5f), 0, 0.35f, 0.05f);
	_part0.addRect(sf::Vector2f(85.f, 0.f), sf::Vector2f(-16.f, 7.f), 0, 0.35f, 0.05f);
	//{
	//}
	_part1.addRect(sf::Vector2f(23.5, 1), sf::Vector2f(18.5, 23), 1, 0.35, 0.05);
	_part1.addRect(sf::Vector2f(-9, 2), sf::Vector2f(14, 7), 1, 0.35, 0.05);
	_part1.addCirc(sf::Vector2f(49, -3), 13.4536f);
	{
		sf::Vector2f verticales[3];
		verticales[0] = { -23, 9 };
		verticales[1] = { 38, 9 };
		verticales[2] = { -15, -18 };
		_part1.addTriang(sf::Vector2f(-45, -24), verticales);
		verticales[0] = { -18.3333f, 17.3333f };
		verticales[1] = { 36.6667f, -14.6667f };
		verticales[2] = { -18.3333f, -2.66667f };
		_part1.addTriang(sf::Vector2f(-46.6667, 26.6667), verticales);
		verticales[0] = { -12.3333f, 0.f };
		verticales[1] = { 25.6667f, 15.f };
		verticales[2] = { -13.3333f, -15.f };
		_part1.addTriang(sf::Vector2f(8.33334, -43), verticales);
		verticales[0] = { -8.f, 17.f };
		verticales[1] = { 16.f, -11.f };
		verticales[2] = { -8.f, -6.f };
		_part1.addTriang(sf::Vector2f(20, 41), verticales);
	}
	{
		sf::Vector2f verticales[3];
		verticales[0] = { -56.f, 12.6667f };
		verticales[1] = { 67.f, 38.6667f };
		verticales[2] = { -11.f, -51.3333f };
		_part2.addTriang(sf::Vector2f(-225, -71.6667), verticales);
		verticales[0] = { 21.f, 37.3333f };
		verticales[1] = { 51.f, -5.66667f };
		verticales[2] = { -72.f, -31.6667f };
		_part2.addTriang(sf::Vector2f(-209, -27.3333), verticales);
		verticales[0] = { -66.6667f, 14.3333f };
		verticales[1] = { 103.333f, 14.3333f };
		verticales[2] = { -36.6667f, -28.6667f };
		_part2.addTriang(sf::Vector2f(-121.333, -4.33331), verticales);
		verticales[0] = { 64.f, 21.3333f };
		verticales[1] = { 53.f, -10.6667f };
		verticales[2] = { -117.f, -10.6667f };
		_part2.addTriang(sf::Vector2f(-71, 20.6667), verticales);
		verticales[0] = { -31.f, 24.3333f };
		verticales[1] = { -20.f, 56.3333f };
		verticales[2] = { 51.f, -80.6667f };
		_part2.addTriang(sf::Vector2f(13, -14.3333), verticales);
		verticales[0] = { -73.3333f, 93.f };
		verticales[1] = { 75.6667f, -49.f };
		verticales[2] = { -2.33331f, -44.f };
		_part2.addTriang(sf::Vector2f(66.3333, -51), verticales);
		verticales[0] = { -25.3333f, 49.f };
		verticales[1] = { 52.6667f, 44.f };
		verticales[2] = { -27.3333f, -93.f };
		_part2.addTriang(sf::Vector2f(89.3333, -144), verticales);
	}
	//------------------------------------------
	_servoRevJ0.setSpeedForce(2.f, 100.f);
	//_servoRevJ0.setAngle(268.877f);
	//------------------------------------------
}
/*!*/void MyTest::setWorld(b2World& world)
{
	_world = &world;
}
/*!*/void MyTest::setWindow(sf::RenderWindow& window)
{
	_window = &window;
}
/*!*/void MyTest::draw()
{
	_bpart0.draw();
	_bpart1.draw();
	_bpart2.draw();
	_cpart0.draw();
	_tpart0.draw();
	_part0.draw();
	_part1.draw();
	_part2.draw();
	_servoRevJ0.setAngle(-10.f);
}
/*~*/MyTest::~MyTest()
{
	_servoRevJ0.destroy();
}
