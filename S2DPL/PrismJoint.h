#ifndef PRISMJOINT_H
#define PRISMJOINT_H
#include"Box.h"
#include"Circle.h"
#include"Triangle.h"
#include"Primitiv.h"

namespace s2dpl
{
	class PrismJoint
	{
	protected:
		static b2World* world;
		float distance;
		float speed;
		float force;
		bool achieved;
		bool servo;
	public:
		b2PrismaticJoint* j{NULL};
		PrismJoint();
		PrismJoint(b2World* world, const Primitiv& A, const Primitiv& B, const sf::Vector2f& normal);
		PrismJoint(b2World* world, const Primitiv& A, const Primitiv& B, const sf::Vector2f& Apos, const sf::Vector2f& Bpos, sf::Vector2f& normal);
		//�����
		void onMotor(const float& speed, const float& force);
		void setSpeedForce(const float& speed, const float& force);
		void offMotor();
		//�����
		void onLimit(const float& min, const float& max);
		void offLimit();
		//��������� ������������
		virtual void setDistance(const float& distance);
		//����������� ����������� ����
		void destroy()
		{
			if (j)
			{
				world->DestroyJoint(j);
				j = NULL;
			}
		}

		float getAngle();
		float getSpeed();
		float getForce();
		~PrismJoint();
	};
}

#endif