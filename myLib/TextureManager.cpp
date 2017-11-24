#include"TextureManager.h"
#include"DirectGraphics.h"

TextureManager* TextureManager::pInstance = nullptr;

void TextureManager::CreateInstance() {
	if (pInstance == nullptr) {
		pInstance = new TextureManager();
	}
}

TextureManager& TextureManager::GetInstance() {

	if (pInstance == nullptr) {
		MessageBox(0, "TextureManagerインスタンスが生成されていません", "", MB_OK);
	}
	return *pInstance;
}

TextureManager::TextureManager() {

}

TextureManager::~TextureManager() {
	delete pInstance;
}

void TextureManager::CancelTexture(const char* fileName) {
	m_pTextures.erase(fileName);
}

HRESULT TextureManager::LoadPictureFile(const char* fileName) {
	
	LPDIRECT3DDEVICE9* pDXDevice = DirectGraphics::GetInstance().GetDevice();

	if (FAILED(D3DXCreateTextureFromFileEx(
		*pDXDevice,
		fileName,              // ファイル名
		0,
		0,
		0,
		0,
		D3DFMT_A1R5G5B5,                // 色抜きを可能に
		D3DPOOL_MANAGED,
		D3DX_FILTER_LINEAR,
		D3DX_FILTER_LINEAR,
		D3DCOLOR_ARGB(255, 0, 255, 0),  //緑を透過
		NULL,
		NULL,
		&m_pTextures[fileName] .texture         // テクスチャ名
	)))
	{
		MessageBox(NULL, "ファイルの読み込みに失敗しました", NULL, MB_OK);
		return E_FAIL;
	}

	return S_OK;
}