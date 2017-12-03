#ifndef COLLIDERMANAGER_H
#define COLLIDERMANAGER_H

#include<vector>

class SquareCollider;
class ColliderBase;

class ColliderManager {
public:
	static const ColliderManager& GetInstance();

	void Register(ColliderBase* pCollider);
	void Cancel(ColliderBase* pCollider);

private:
	ColliderManager();
	~ColliderManager();
	static ColliderManager* m_pInstance;

	std::vector<SquareCollider*> m_PtrColliders;
};
#endif