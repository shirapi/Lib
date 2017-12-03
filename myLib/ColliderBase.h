#ifndef COLLIDER_H
#define COLIDER_H

#include<d3dx9.h>
#include<string>

class ColliderBase {
public:
	//ColliderBase(const std::string className);
	//~ColliderBase();

	const std::string& GetAffiliatedClassName();

protected:
	D3DXVECTOR3 m_Pos;
	const std::string m_ClassName;
	void (*m_pFunc)();
};
#endif