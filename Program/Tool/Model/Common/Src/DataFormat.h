#pragma once
#include <exception>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>
#include <map>
#include <numbers>
#include <sstream>

#pragma warning(disable : 4201) // 無名構造体
#pragma warning(disable : 4324) // 構造体のパッド

#define CONVERT_VERSION (0x00000002)
#define CANDY_MAKE_FOURCC(x, y, z, w) (((w) << 24) | ((z) << 16) | ((y) << 8) | (x))
#define CANDY_MAKE_FOURCC_STR(str) (((str)[3] << 24) | ((str)[2] << 16) | ((str)[1] << 8) | (str)[0])
#define FAILED_RETURN_FALSE(EXPR) { if(!(EXPR))return false; }
#define PRINT_COLOR_RED "\x1b[31m"
#define PRINT_COLOR_GREEN "\x1b[32m"
#define PRINT_COLOR_YELLOW "\x1b[33m"
#define PRINT_COLOR_BLUE "\x1b[34m"
#define PRINT_COLOR_MAGENTA "\x1b[35m"
#define PRINT_COLOR_CYAN "\x1b[36m"
#define PRINT_COLOR_WHITE "\x1b[37m"
#define PRINT_COLOR_DEFAULT "\x1b[39m"

using s8 = std::int8_t;
using u8 = std::uint8_t;
using s16 = std::int16_t;
using u16 = std::uint16_t;
using s32 = std::int32_t;
using u32 = std::uint32_t;
using s64 = std::int64_t;
using u64 = std::uint64_t;
using f32 = float;
using f64 = double;
using c8 = char;
using c16 = wchar_t;

struct alignas(16) Vec4
{
	union
	{
		struct
		{
			f32 x;
			f32 y;
			f32 z;
			f32 w;
		};
		f32 arr[4]{ 0.0f, 0.0f, 0.0f, 1.0f };
	};
};
struct Vec4NoAlign
{
	union
	{
		struct
		{
			f32 x;
			f32 y;
			f32 z;
			f32 w;
		};
		f32 arr[4]{ 0.0f, 0.0f, 0.0f, 1.0f };
	};
};
struct Vec2
{
	union
	{
		struct
		{
			f32 x;
			f32 y;
		};
		f32 arr[2]{ 0.0f, 0.0f };
	};
};
struct Vec3
{
	union
	{
		struct
		{
			f32 x;
			f32 y;
			f32 z;
		};
		f32 arr[3]{ 0.0f, 0.0f, 0.0f };
	};
};
inline Vec4 ToVec4(const Vec2& _v) { return Vec4{ _v.x, _v.y, 0.0f, 1.0f }; }
inline Vec4 ToVec4(const Vec3& _v) { return Vec4{ _v.x, _v.y, _v.z, 1.0f }; }

struct alignas(16) Mtx
{
	Vec4 v[4]
	{
		{ 1.0f, 0.0f, 0.0f, 0.0f },
		{ 0.0f, 1.0f, 0.0f, 0.0f },
		{ 0.0f, 0.0f, 1.0f, 0.0f },
		{ 0.0f, 0.0f, 0.0f, 1.0f },
	};
};

struct FileHeader
{
	u32 m_Magic{};
	u32 m_Version{};
	u32 m_HeaderSize{};
	u32 m_Size{};
};

struct Chunk
{
	union
	{
		u32 m_Id;
		struct
		{
			c8 m_Ids[4];
		};
	};
	u32 m_Size;
};

namespace Material
{
	enum class TEXTURE_TYPE : s32
	{
		ALBEDO,
		NORMAL,

		NONE = -1,
	};

	struct MaterialHeader
	{
		u32 m_TextureCount{};
		c8 m_Name[128]{ "" };
	};

	struct TextureInfo
	{
		TEXTURE_TYPE m_Type = TEXTURE_TYPE::NONE;
		c8 m_FileName[256]{ "" };
	};

	struct MaterialInfo
	{
		MaterialHeader m_Header;
		std::vector<TextureInfo> m_TextureInfoList;
	};
}

namespace Mesh
{
	struct VertexInfo
	{
		Vec4 m_Position{};
		Vec4 m_Normal{};
		Vec4 m_Tangent{};
		Vec4 m_TexCoord0{};
		Vec4 m_TexCoord1{};
	};

	struct MeshHeader
	{
		u32 m_VertexInfoCount{};
		u32 m_VertexIndexCount{};
		u32 m_MaterialIndex{};
		c8 m_Name[128]{ "" };
	};

	struct MeshInfo
	{
		MeshHeader m_Header;
		std::vector<VertexInfo> m_VertexInfoList;
		std::vector<u32> m_VertexIndexList;
	};
}

struct WriteData
{
	std::vector<Mesh::MeshInfo> m_MeshInfoList;
	std::vector<Material::MaterialInfo> m_MaterialInfoList;
};
