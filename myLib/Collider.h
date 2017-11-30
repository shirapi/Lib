#ifndef COLLIDER_H
#define COLIDER_H

class ObjectBase;

class ColliderBase {
public:
	ColliderBase(ObjectBase* objBase);

protected:
	ObjectBase* m_pObj;
};
#endif