#ifndef UTILITY_H
#define UTILITY_H

#include<d3dx9.h>

namespace Utility {
	struct CUSTOMVERTEX {
		FLOAT	x, y, z, rhw;
		DWORD	color;
		FLOAT	tu, tv;
	};

	enum BUTTON_STATE {
		OFF,	//!< 前フレームから離されている状態
		ON,		//!< 前フレームから押されている状態
		PUSH,	//!< 現フレームから押された状態
		RELEASE	//!< 現フレームから離された状態
	};

	enum KEY_KIND
	{
		LEFT,
		RIGHT,
		UP,
		DOWN,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,
		KEY_0,
		A,
		B,
		C,
		D,
		E,
		F,
		G,
		H,
		I,
		J,
		K,
		L,
		M,
		N,
		O,
		P,
		Q,
		R,
		S,
		T,
		U,
		V,
		W,
		X,
		Y,
		Z,
		SPACE,
		LSHIFT,
		RSHIFT,
		LCONTROL,
		RCONTROL,
		ESC,
		MAX
	};

	struct MOUSE_DATA {
		int Dim_x;					//!< マウスのXの移動量
		int Dim_y;					//!< マウスのYの移動量
		int Dim_z;					//!< マウスのZの移動量
		BUTTON_STATE LeftMouse;		//!< マウスの左クリックの状態
		BUTTON_STATE RightMouse;	//!< マウスの右クリックの状態
	};

	struct PICTURE_INFO {
		LPDIRECT3DTEXTURE9 texture;
		int width;
		int height;
	};

	bool JudgeCollisionCircle(const D3DXVECTOR2& pos1, float r1, const D3DXVECTOR2& pos2, float r2);

	bool JudgeCollisionSquare(const D3DXVECTOR2& pos1, float width1, float height1, const D3DXVECTOR2& pos2, float width2, float height2);

	float CalculateDistance(float x1, float y1, float x2, float y2);

	float CalculateDeg(float x1, float y1, float x2, float y2);

	double CalculateRad(float x1, float y1, float x2, float y2);

	void OutputDebug_Number(float outputNum, HWND hWnd);

	//min<= random <= max
	int Random(int min, int max);
}
#endif
