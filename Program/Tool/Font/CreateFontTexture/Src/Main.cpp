#define STB_TRUETYPE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_truetype.h"
#include "stb_image_write.h"
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

struct FontUvInfoHeader
{
	std::uint32_t m_NumCodes;
};
struct UvInfo
{
	std::uint32_t code;
	float x0, y0, x1, y1;
};

void App(int _argc, char* _argv[]);
void Usage();

int main(int _argc, char* _argv[])
{
	try
	{
		App(_argc, _argv);
	}
	catch(std::exception& e)
	{
		std::cout << e.what() << std::endl;
		Usage();
		return -1;
	}
	return 0;
}

void App(int _argc, char* _argv[])
{
	if (_argc <= 3)throw std::exception("引数が足りません");

	std::ifstream ifs(_argv[1], std::ios::binary);
	if (ifs.fail())throw std::exception("パスが間違っています");

	std::string fontData;
	fontData.resize(ifs.seekg(0, ifs.end).tellg());
	ifs.seekg(0, ifs.beg).read(fontData.data(), fontData.size());

	unsigned char* pData = new unsigned char[fontData.size()];
	memcpy_s(pData, fontData.size(), fontData.data(), fontData.size());

	stbtt_fontinfo fontinfo;
	stbtt_InitFont(&fontinfo, pData, stbtt_GetFontOffsetForIndex(pData, 0));

	float font_scale = stbtt_ScaleForPixelHeight(&fontinfo, 20.0f);

	int ascent_int, descent_int, line_gap_int;
	stbtt_GetFontVMetrics(&fontinfo, &ascent_int, &descent_int, &line_gap_int);
	float ascent = ascent_int * font_scale;
	float descent = descent_int * font_scale;
	float height = ascent - descent;

	static constexpr int FONT_BUFFER_WIDTH = 4096;
	static constexpr int FONT_BUFFER_HEIGHT = 4096;

	std::vector<std::uint8_t> pixels(FONT_BUFFER_WIDTH * FONT_BUFFER_HEIGHT, 0);
	int x_pos = 0, y_pos = 0;
	auto p_pixels = pixels.data();

	std::vector<UvInfo> uvInfos;

	for (std::uint32_t i = 0; i <= 0xffff; ++i)
	{
		if (!stbtt_FindGlyphIndex(&fontinfo, i))continue;
		int advance, lsb;
		stbtt_GetCodepointHMetrics(&fontinfo, i, &advance, &lsb);
		int x0, x1, y0, y1;
		stbtt_GetCodepointBitmapBox(&fontinfo, i, font_scale, font_scale, &x0, &y0, &x1, &y1);
		int font_width = x1 - x0;
		int font_height = y1 - y0;
		if (font_width == 0 || font_height == 0)continue;

		if (x_pos + (int)(advance * font_scale) >= FONT_BUFFER_WIDTH)
		{
			x_pos = 0;
			y_pos += (int)(height + 1);
			if (y_pos + (int)(height) >= FONT_BUFFER_HEIGHT)
			{
				throw std::exception("サイズが足りません");
			}
		}

		int yoff = int(std::ceil(ascent));

		stbtt_MakeCodepointBitmap(&fontinfo, p_pixels + ((y_pos + (yoff + y0)) * FONT_BUFFER_WIDTH + (x_pos + x0)),
			font_width, font_height, FONT_BUFFER_WIDTH, font_scale, font_scale, i);

		UvInfo uvInfo;
		uvInfo.code = i;
		uvInfo.x0 = (float)x_pos / (float)FONT_BUFFER_WIDTH;
		uvInfo.y0 = (float)y_pos / (float)FONT_BUFFER_HEIGHT;
		uvInfo.x1 = uvInfo.x0 + advance * font_scale / (float)FONT_BUFFER_WIDTH;
		uvInfo.y1 = uvInfo.y0 + height / (float)FONT_BUFFER_HEIGHT;
		uvInfos.push_back(uvInfo);

		x_pos += (int)(advance * font_scale);
	}

	struct Color
	{
		std::uint8_t r = 0x00, g = 0x00, b = 0x00, a = 0xff;
	};
	std::vector<Color> colors(FONT_BUFFER_WIDTH * FONT_BUFFER_HEIGHT);
	for (int h = 0; h < FONT_BUFFER_HEIGHT; ++h)
	{
		for (int w = 0; w < FONT_BUFFER_WIDTH; ++w)
		{
			int index = (h * FONT_BUFFER_WIDTH + w);
			colors[index].a = pixels[index];
		}
	}
	stbi_write_bmp(_argv[2], static_cast<int>(FONT_BUFFER_WIDTH), static_cast<int>(FONT_BUFFER_HEIGHT), static_cast<int>(sizeof(Color)), colors.data());
	std::ofstream ofs(_argv[3], std::ios::binary);
	FontUvInfoHeader header;
	header.m_NumCodes = (std::uint32_t)uvInfos.size();
	ofs.write(reinterpret_cast<const char*>(&header), sizeof(header));
	for (auto uvInfo : uvInfos)
	{
		ofs.write(reinterpret_cast<const char*>(&uvInfo), sizeof(uvInfo));
	}
	ofs.close();
}

void Usage()
{

}