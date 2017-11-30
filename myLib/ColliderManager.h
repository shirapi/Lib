#ifndef COLLIDERMANAGER_H
#define COLLIDERMANAGER_H

#include<map>
#include<vector>

class ColliderBase;

class ColliderManager {
public:
	static const ColliderManager& GetInstance();
	const ColliderBase& GetCollider(std::string className, int uniqueNo);
	unsigned int GetSize(std::string className);
	void Register(std::string className, ColliderBase* pCollider);
	void Cancel(ColliderBase* pCollider);//className������Ă��炤�B�B�B�����b�g�[�����Ȃ�A �f�����b�g�[Collider���N���X����ێ����Ȃ��Ă͂����Ȃ�

private:
	ColliderManager();
	~ColliderManager();
	static ColliderManager* m_pInstance;

	std::map<std::string, std::vector<ColliderBase*>> m_Colliders;
};
#endif