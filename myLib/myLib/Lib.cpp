#include"Lib.h"
#include"DirectGraphics.h"
#include"DirectInput.h"
#include"Renderer.h"
#include"ModelManager.h"
#include"TextureManager.h"

using namespace Utility;

Lib* Lib::pInstance = nullptr;

void Lib::CreateInstance(HWND hWnd, HINSTANCE hInstance){
	if (pInstance == nullptr) {
		pInstance = new Lib(hWnd, hInstance);
	}

}

Lib& Lib::GetInstance() {
	if (pInstance == nullptr) {
		MessageBox(0, "DirectInputインスタンスが生成されていません", NULL, MB_OK);
	}
	return *pInstance;
}

Lib::Lib(HWND hWnd, HINSTANCE hInstance){
	DirectGraphics::CreateInstance(hWnd);
	DirectInput::CrateInstance(hWnd, hInstance);
	Renderer::CreateInstance();
	ModelManager::CreateInstance();
	TextureManager::CreateInstance();

	m_DirectGraphics = &DirectGraphics::GetInstance();
	m_DirectInput = &DirectInput::GetInstance();
	m_Renderer = &Renderer::GetInstance();
	m_ModelManager = &ModelManager::GetInstance();
	m_TextureManager = &TextureManager::GetInstance();
}

Lib::~Lib() {
	delete pInstance;
}

void Lib::UpdateKey() {
	m_DirectInput->UpdateKey();
}

void Lib::UpdateMouse() {
	m_DirectInput->UpdateMouse();
}

BUTTON_STATE Lib::GetKeyState(KEY_KIND keyKind) {
	return m_DirectInput->GetKeyState(keyKind);
}

const MOUSE_DATA* Lib::GetMouseData() {
	return m_DirectInput->GetMouseData();
}

void Lib::CancelModel(const char* fileName) {
	m_ModelManager->CancelMesh(fileName);
}

HRESULT Lib::LoadXFile(const char* fileName) {
	return m_ModelManager->LoadXFile(fileName);
}

void Lib::TransformWorld(const D3DXVECTOR3& pPos, float degHeading, float degPitch, float degBank, float scale) {
	m_Renderer->TransformWorld(pPos,degHeading,degPitch,degBank,scale);
}

void Lib::TransformView(const D3DXVECTOR3& pCameraPos, const D3DXVECTOR3&  LookatPos, const D3DXVECTOR3& UpVec) {
	m_Renderer->TransformView(pCameraPos, LookatPos, UpVec);
}

D3DXVECTOR3* Lib::GetLookatPos(D3DXVECTOR3* pos, float length, float degHeading, float degBank) {
	return m_Renderer->GetLookatPos(pos, length, degHeading, degBank);
}

void Lib::TransformProjection(float angle, float aspectRatio, float mimDistance, float maxDistance) {
	m_Renderer->TransformProjection(angle, aspectRatio, mimDistance, maxDistance);
}

void Lib::StartRender() {
	m_Renderer->StartRender();
}

void Lib::StartDraw(int red, int green, int blue) {
	m_Renderer->StartDraw(red, green, blue);
}

bool Lib::Draw(const D3DXVECTOR2& pos, const char* fileName, float width, float height, float tu, float tv, float deg, float magnifying, DWORD color, bool flipHorizontal, bool flipVertical) {
	return m_Renderer->Draw(pos, fileName, width, height, tu, tv, deg, magnifying, color, flipHorizontal, flipVertical);
}
bool Lib::Draw(const CUSTOMVERTEX vertex[], const char* fileName) {
	return m_Renderer->Draw(vertex, fileName);
}

bool Lib::Render(const char* fileName) {
	return m_Renderer->Render(fileName);
}

void Lib::EndRender() {
	m_Renderer->EndRender();
}
void Lib::EndDraw() {
	m_Renderer->EndDraw();
}

void Lib::TurnVertex_tu(CUSTOMVERTEX vertex[]) {
	m_Renderer->TurnVertex_tu(vertex);
}

void Lib::TurnVertex_tv(CUSTOMVERTEX vertex[]) {
	m_Renderer->TurnVertex_tv(vertex);
}

void Lib::ChangeScale(CUSTOMVERTEX vertex[], float magnifying) {
	m_Renderer->ChangeScale(vertex, magnifying);
}

void Lib::TrimingVertex(CUSTOMVERTEX vertex[], float leftTopTu, float leftTopTv, float width, float height, float pngWidth, float pngHeight) {
	m_Renderer->TrimingVertex(vertex, leftTopTu, leftTopTv, width, height, pngWidth, pngHeight);
}

void Lib::Rotation(CUSTOMVERTEX vertex[], float deg) {
	m_Renderer->Rotation(vertex, deg);
}

void Lib::CancelTexture(const char* fileName) {
	m_TextureManager->CancelTexture(fileName);
}

HRESULT Lib::LoadPictureFile(const char* fileName) {
	return m_TextureManager->LoadPictureFile(fileName);
}