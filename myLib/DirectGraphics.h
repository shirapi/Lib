/*!
* @file DirectInput.h
* @brief DirectInputクラス(シングルトン)のヘッダファイル
* @author shiraishi
*/

#ifndef DIRECTGRAPHICS_H
#define DIRECTGRAPHICS_H

#include<d3dx9.h>
#define SAFE_RELEASE(p) { if(p) { (p)->Release(); (p)=NULL; } }

class FileManagement;
class Renderer;

class DirectGraphics {
public:
	static void CreateInstance(HWND hWnd);
	static DirectGraphics& GetInstance();

	LPDIRECT3DDEVICE9* GetDevice() {
		return &m_pDevice;
	}

private:
	static DirectGraphics* pInstance;
	DirectGraphics(HWND hWnd);
	~DirectGraphics();

	LPDIRECT3D9 m_pDirect3D;
	LPDIRECT3DDEVICE9 m_pDevice;

	void SetRenderState();

	DirectGraphics(const DirectGraphics&);
	void operator =(const DirectGraphics&);
};
#endif