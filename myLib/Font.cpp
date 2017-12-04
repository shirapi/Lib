#include"Font.h"
#include"DirectGraphics.h"
#include<tchar.h>

Font::Font(std::string str) {
	m_Str = str;

	D3DXCreateFont(
		*DirectGraphics::GetInstance().GetDevice(),
		20,
		10,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		"ÇlÇr ÉSÉVÉbÉN",
		&m_pFont
	);
}

Font::Font(float num) {
	TCHAR buff[256];
	_stprintf_s(buff, 256, _T("%f\n"), num);

	m_Str = buff;

	D3DXCreateFont(
		*DirectGraphics::GetInstance().GetDevice(),
		20,
		10,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		"ÇlÇr ÉSÉVÉbÉN",
		&m_pFont
	);
}

Font::~Font() {
	SAFE_RELEASE(m_pFont);
}

void Font::Draw() {

}