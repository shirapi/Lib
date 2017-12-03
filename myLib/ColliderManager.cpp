#include"ColliderManager.h"

ColliderManager* ColliderManager::m_pInstance = nullptr;

const ColliderManager& ColliderManager::GetInstance() {
	if (m_pInstance == nullptr) {
		m_pInstance = new ColliderManager;
	}
	return *m_pInstance;
}

ColliderManager::ColliderManager() {

}

ColliderManager::~ColliderManager() {

}

//const ColliderBase& ColliderManager::GetCollider(std::string className, int no) {
//	//if (m_Colliders.find(className) == m_Colliders.end()) {
//	//	std::vector< ColliderBase* >::iterator iter = std::find(m_Colliders[className].begin(), m_Colliders[className].end(), no);
//	//	if (iter == m_Colliders[className].end()) {
//	//		exit(1);
//	//	}
//	//}
//
//	return *m_Colliders[className][no];
//}
//
//unsigned int ColliderManager::GetSize(std::string className) {
//	return m_Colliders[className].size();
//}

//void ColliderManager::Register(ColliderBase* pCollider) {
//	m_Colliders.push_back(pCollider);
//}

void ColliderManager::Cancel(ColliderBase* pCollider) {

}