#ifndef OBJECTBASE111_H
#define OBJECTBASE111_H

#include<d3dx9.h>

class ObjectBase {
public:
	ObjectBase(const D3DXVECTOR3& pos) :
		m_Pos(pos) {};
	ObjectBase(const D3DXVECTOR2& pos) {
		m_Pos.x = pos.x;
		m_Pos.y = pos.y;
		m_Pos.z = 0.0f;
	}
	virtual ~ObjectBase() {};

	const D3DXVECTOR3& GetPos() {
		return m_Pos;
	}

	virtual void Update() = 0;
	virtual void Draw() = 0;

protected:
	D3DXVECTOR3 m_Pos;
};
#endif
