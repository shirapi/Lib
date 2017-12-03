#ifndef CIRCLECOLLIDER_H
#define CIRCLECOLLIDER_H

#include"ColliderBase.h"

class CircleCollider :public ColliderBase {
public:
	CircleCollider();
	~CircleCollider();

private:
	float m_Radius;
};
#endif
