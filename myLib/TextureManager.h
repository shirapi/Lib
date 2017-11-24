#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include"Utility.h"
#include<map>
#include<d3dx9.h>

using std::string;
using Utility::PICTURE_INFO;

class TextureManager {
public:
	static void CreateInstance();
	static TextureManager& GetInstance();

	//テキスチャを消します
	void CancelTexture(const char* fileName);

	//png,jpegファイルからデータを読み込みます
	//第一引数 ファイルへのパス
	//第二引数 そのテキスチャのID
	HRESULT LoadPictureFile(const char* fileName);

private:
	static TextureManager* pInstance;
	TextureManager();
	~TextureManager();

	std::map<string, PICTURE_INFO> m_pTextures;

public:
	const PICTURE_INFO& GetPictureInfo(const char* fileName) {
		if (m_pTextures.find(fileName) != m_pTextures.end()) {
			return m_pTextures[fileName];
		}
		exit(1);
	}
};

#endif
