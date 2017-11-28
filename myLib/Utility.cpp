#include"Utility.h"

#include<d3dx9.h>
#include<stdio.h>
#include<tchar.h>
#include<time.h>

//min<= random <= max
int Utility::Random(int min, int max)
{
	static bool seedrandom = false;

	if (seedrandom == false) {
		srand((unsigned int)time(NULL));
		seedrandom = true;
	}

	return min + rand() % (max + 1);
}

bool Utility::JudgeCollisionCircle(const D3DXVECTOR2& pos1, float r1, const D3DXVECTOR2& pos2, float r2) {
	float sumR = r1 + r2;//2�̉~�̔��a�̍��v���߂�
						 // �O�����̒藝�Œ��S�_�̒��������߂Ă���
	float L = (float)pow(pos1.x - pos2.x, 2) + (float)pow(pos1.y - pos2.y, 2);
	L = (float)sqrt(L);

	if (sumR >= L) {//���S�_�̒��������a�̍��v���Z��������^
		return TRUE;
	}
	return FALSE;
}

bool Utility::JudgeCollisionSquare(const D3DXVECTOR2& pos1, float width1, float height1, const D3DXVECTOR2& pos2, float width2, float height2){
	D3DXVECTOR2 LeftTopA;
	D3DXVECTOR2 RightTopA;
	D3DXVECTOR2 RightBottomA;
	D3DXVECTOR2 LeftBottomA;
	D3DXVECTOR2 LeftTopB;
	D3DXVECTOR2 RightTopB;
	D3DXVECTOR2 RightBottomB;
	D3DXVECTOR2 LeftBottomB;

	LeftTopA.x = LeftBottomA.x = pos1.x - width1 / 2;
	RightTopA.x = RightBottomA.x = pos1.x + width1 / 2;
	LeftTopA.y = RightTopA.y = pos1.y - height1 / 2;
	RightBottomA.y = LeftBottomA.y = pos1.y + height1 / 2;
	LeftTopB.x = LeftBottomB.x = pos2.x - width2 / 2;
	RightTopB.x = RightBottomB.x = pos2.x + width2 / 2;
	LeftTopB.y = RightTopB.y = pos2.y - height2 / 2;
	RightBottomB.y = LeftBottomB.y = pos2.y + height2 / 2;

	if (LeftTopA.x < RightTopB.x) {
		if (LeftTopB.x < RightTopA.x) {
			if (LeftTopA.y < LeftBottomB.y) {
				if (LeftTopB.y < LeftBottomA.y) {
					return true;
				}
			}
		}
	}
	return false;
}

double Utility::CalculateRad(float x1, float y1, float x2, float y2) {
	double rad;

	double lengthX = x2 - x1;
	double lengthY = y2 - y1;

	if (0 < lengthX) {
		if (lengthY < 0) {

			rad = atan(lengthY / lengthX);

		}
		else {

			rad = atan(lengthY / lengthX) + (2 * D3DX_PI);

		}
	}
	else if (lengthX < 0) {

		rad = atan(lengthY / lengthX) + D3DX_PI;

	}
	else if (lengthX == 0) {
		if (0 < lengthY) {

			rad = 3 / 2 * D3DX_PI;

		}
		else {

			rad = D3DX_PI / 2;

		}
	}

	rad = (2 * D3DX_PI) - rad;

	return rad;
}

float Utility::CalculateDeg(float x1, float y1, float x2, float y2) {
	double rad;

	double lengthX = x2 - x1;
	double lengthY = y2 - y1;

	if (0 < lengthX) {
		if (lengthY < 0) {

			rad = atan(lengthY / lengthX);

		}
		else {

			rad = atan(lengthY / lengthX) + (2 * D3DX_PI);

		}
	}
	else if (lengthX < 0) {

		rad = atan(lengthY / lengthX) + D3DX_PI;

	}
	else if (lengthX == 0) {
		if (0 < lengthY) {

			rad = 3 / 2 * D3DX_PI;

		}
		else {

			rad = D3DX_PI / 2;

		}
	}

	rad = (2 * D3DX_PI) - rad;

	return (float)D3DXToDegree(rad);
}

float Utility::CalculateDistance(float x1, float y1, float x2, float y2) {
	return (float)sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

void Utility::OutputDebug_Number(float outputNum, HWND hWnd) {
	TCHAR buff[256];
	_stprintf_s(buff, 256, _T("%f\n"), outputNum);
	OutputDebugString(buff);
	SetWindowText(hWnd, buff);
}