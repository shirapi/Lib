#ifndef COLLIDERMANAGER_H
#define COLLIDERMANAGER_H

#include<vector>

class SquareCollider;
class CircleCollider;

class ColliderManager {
public:
	static const ColliderManager& GetInstance();

	void Update();

	void Register(SquareCollider* pCollider);
	void Cancel(SquareCollider* pCollider);
	void Register(CircleCollider* pCollider);
	void Cancel(CircleCollider* pCollider);
	
private:
	ColliderManager();
	~ColliderManager();
	static ColliderManager* m_pInstance;

	std::vector<SquareCollider*> m_PtrSquareColliders;
	std::vector<CircleCollider*> m_PtrCircleColliders;

	void JudgeAllSquare();
	void JudgeAllCircle();
};
#endif