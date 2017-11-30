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
	void Cancel(ColliderBase* pCollider);//classNameをいれてもらう。。。メリットー早くなる、 デメリットーColliderがクラス名を保持しなくてはいけない

private:
	ColliderManager();
	~ColliderManager();
	static ColliderManager* m_pInstance;

	std::map<std::string, std::vector<ColliderBase*>> m_Colliders;
};
#endif