#ifndef FONT_H
#define FONT_H

#include<d3dx9.h>
#include<string>

class Font {
public:
	Font(std::string str);
	Font(float num);
	~Font();

	void Draw();
private:
	LPD3DXFONT m_pFont = NULL;
	std::string m_Str;
	float m_Num;
};
#endif