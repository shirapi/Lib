#include"ModelManager.h"
#include"DirectGraphics.h"

ModelManager* ModelManager::pInstance = nullptr;

void ModelManager::CreateInstance() {
	if (pInstance == nullptr) {
		pInstance = new ModelManager();
	}
}

ModelManager& ModelManager::GetInstance() {

	if (pInstance == nullptr) {
		MessageBox(0, "ModelManagerインスタンスが生成されていません", "", MB_OK);
	}
	return *pInstance;
}

ModelManager::ModelManager() {
	
}

ModelManager::~ModelManager() {
	for (auto itr = m_MeshdData.begin(); itr != m_MeshdData.end(); itr++)
	{
		delete itr->second.pMeshMaterials;
		delete itr->second.pMeshTextures;
		SAFE_RELEASE(itr->second.pMesh);
	}

	delete pInstance;
}

HRESULT ModelManager::LoadXFile(const char* fileName) {

	LPDIRECT3DDEVICE9* pDXDevice = DirectGraphics::GetInstance().GetDevice();

	// Xファイルからメッシュをロードする	
	LPD3DXBUFFER pD3DXMtrlBuffer = NULL;

	if (FAILED(D3DXLoadMeshFromX(fileName, D3DXMESH_SYSTEMMEM,
		*pDXDevice, NULL, &pD3DXMtrlBuffer, NULL,
		&m_MeshdData[fileName].DwNumMaterials, &m_MeshdData[fileName].pMesh)))
	{
		MessageBox(NULL, "Xファイルの読み込みに失敗しました", NULL, MB_OK);
		return E_FAIL;
	}
	D3DXMATERIAL* d3dxMaterials = (D3DXMATERIAL*)pD3DXMtrlBuffer->GetBufferPointer();
	m_MeshdData[fileName].pMeshMaterials = new D3DMATERIAL9[m_MeshdData[fileName].DwNumMaterials];
	m_MeshdData[fileName].pMeshTextures = new LPDIRECT3DTEXTURE9[m_MeshdData[fileName].DwNumMaterials];

	for (DWORD i = 0; i < m_MeshdData[fileName].DwNumMaterials; i++)
	{
		m_MeshdData[fileName].pMeshMaterials[i] = d3dxMaterials[i].MatD3D;
		m_MeshdData[fileName].pMeshMaterials[i].Ambient = m_MeshdData[fileName].pMeshMaterials[i].Diffuse;
		m_MeshdData[fileName].pMeshTextures[i] = NULL;
		if (d3dxMaterials[i].pTextureFilename != NULL &&
			lstrlen(d3dxMaterials[i].pTextureFilename) > 0)
		{
			if (FAILED(D3DXCreateTextureFromFile(*pDXDevice,
				d3dxMaterials[i].pTextureFilename,
				&m_MeshdData[fileName].pMeshTextures[i])))
			{
				MessageBox(NULL, "テクスチャの読み込みに失敗しました", NULL, MB_OK);
			}
		}
	}
	pD3DXMtrlBuffer->Release();

	return S_OK;
}

void ModelManager::CancelMesh(const char* fileName) {
	delete m_MeshdData[fileName].pMeshMaterials;
	delete m_MeshdData[fileName].pMeshTextures;
	SAFE_RELEASE(m_MeshdData[fileName].pMesh);
	m_MeshdData.erase(fileName);
}