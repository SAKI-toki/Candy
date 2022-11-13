#include <fbxsdk.h>
#include <exception>
#include <iostream>
#include <cassert>
#include <vector>
#include <string>
#include <fstream>
#include <filesystem>


#define CONVERT_FBX_VERSION (0x00000101)
#define CANDY_MAKE_FOURCC(x, y, z, w) (((w) << 24) | ((z) << 16) | ((y) << 8) | (x))
#define CANDY_MAKE_FOURCC_STR(str) (((str)[3] << 24) | ((str)[2] << 16) | ((str)[1] << 8) | (str)[0])

using s32 = std::int32_t;
using u32 = std::uint32_t;
using f32 = float;
using f64 = double;

bool ConvertFbx(const std::string& _inPath, const std::string& _outPath);

int main(int _argc, char* _argv[])
{
	std::optional<std::string> inPath;
	std::optional<std::string> outPath;
	for (int i = 1; i < _argc - 1; ++i)
	{
		std::string_view arg = _argv[i];
		std::string_view nextArg = _argv[i + 1];
		if (arg == "-i")
		{
			inPath = nextArg;
		}
		if (arg == "-o")
		{
			outPath = nextArg;
		}
	}

	if (!inPath)
	{
		return -1;
	}
	if (!outPath)
	{
		return -1;
	}

	std::cout << "inPath:" << inPath.value() << std::endl;
	std::cout << "outPath:" << outPath.value() << std::endl;
	if (ConvertFbx(inPath.value(), outPath.value()))
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "error" << std::endl;
		return -1;
	}

	return 0;
}

struct alignas(16) Vec4
{
	f32 x = 0.0f, y = 0.0f, z = 0.0f, w = 0.0f;
};

struct VertexInfo
{
	Vec4 m_Normal{};
	Vec4 m_TexCoord0{};
	Vec4 m_TexCoord1{};
};

struct FileHeader
{
	u32 m_Magic{};
	u32 m_Version{};
	u32 m_HeaderSize{};
	u32 m_Size{};
};
struct MeshHeader
{
	u32 m_ControlPointCount{};
	u32 m_VertexCount{};
	char m_Name[128]{ "" };
	char m_MaterialName[128]{ "" };
};
struct MeshInfo
{
	MeshHeader m_Header;
	std::vector<Vec4> m_ControlPointList;
	std::vector<VertexInfo> m_VertexInfoList;
	std::vector<u32> m_ControlPointIndexList;
};
struct MaterialHeader
{
	u32 m_TextureCount{};
	char m_Name[128]{ "" };
};
struct TextureInfo
{
	char m_FilePath[256]{ "" };
};

struct MaterialInfo
{
	MaterialHeader m_Header;
	std::vector<TextureInfo> m_TextureInfoList;
};

struct Chunk
{
	union
	{
		u32 m_Id;
		struct
		{
			char m_Ids[4];
		};
	};
	u32 m_Size;
};


template<typename T>
class FbxObjectWrapper
{
public:
	FbxObjectWrapper(T* _ptr) :m_Ptr{ _ptr } {}
	~FbxObjectWrapper() { if (m_Ptr) { m_Ptr->Destroy(); }; }

	T* get() { return m_Ptr; }
	operator bool()const { return !!m_Ptr; }
	T* operator->() { return m_Ptr; }
	T operator*() { return *m_Ptr; }

private:
	T* m_Ptr;
};

#define FAILED_RETURN_FALSE(EXPR) { if(!(EXPR))return false; }

void RecursiveNode(std::vector<MeshInfo>& _outMeshInfoList, FbxNode* _node);
std::vector<MaterialInfo> GetMaterialInfo(FbxScene* _scene);

bool ConvertFbx(const std::string& _inPath, const std::string& _outPath)
{
	FbxObjectWrapper manager = FbxManager::Create();
	FAILED_RETURN_FALSE(manager);
	FbxObjectWrapper scene = FbxScene::Create(manager.get(), "fbx");
	FAILED_RETURN_FALSE(scene);

	FbxObjectWrapper importer = FbxImporter::Create(manager.get(), "imp");
	FAILED_RETURN_FALSE(importer);

	FbxString path(_inPath.c_str());
	FAILED_RETURN_FALSE(importer->Initialize(path.Buffer(), -1, manager->GetIOSettings()));
	FAILED_RETURN_FALSE(importer->Import(scene.get()));

	if (scene->GetGlobalSettings().GetAxisSystem() != FbxAxisSystem::DirectX)
	{
		FbxAxisSystem::DirectX.ConvertScene(scene.get());
	}

	FbxGeometryConverter geometryConverter(manager.get());
	geometryConverter.Triangulate(scene.get(), true);

	std::vector<MeshInfo> outMeshInfoList;
	RecursiveNode(outMeshInfoList, scene->GetRootNode());

	std::vector<MaterialInfo> materialInfoList = GetMaterialInfo(scene.get());

	std::ostringstream os;

	for (const auto& meshInfo : outMeshInfoList)
	{
		Chunk  chunk;
		chunk.m_Id = CANDY_MAKE_FOURCC_STR("MESH");
		chunk.m_Size = sizeof(MeshHeader) + sizeof(VertexInfo) * meshInfo.m_Header.m_VertexCount;
		os.write((const char*)&chunk, sizeof(Chunk));

		os.write((const char*)&meshInfo.m_Header, sizeof(MeshHeader));

		os.write((const char*)meshInfo.m_ControlPointList.data(), sizeof(Vec4) * meshInfo.m_Header.m_ControlPointCount);
		os.write((const char*)meshInfo.m_VertexInfoList.data(), sizeof(VertexInfo) * meshInfo.m_Header.m_VertexCount);
		os.write((const char*)meshInfo.m_ControlPointIndexList.data(), sizeof(u32) * meshInfo.m_Header.m_VertexCount);
	}

	for (const auto& materialInfo : materialInfoList)
	{
		Chunk  chunk;
		chunk.m_Id = CANDY_MAKE_FOURCC_STR("MAT_");
		chunk.m_Size = sizeof(MaterialHeader) + sizeof(TextureInfo) * materialInfo.m_Header.m_TextureCount;
		os.write((const char*)&chunk, sizeof(Chunk));

		os.write((const char*)&materialInfo.m_Header, sizeof(MaterialHeader));

		os.write((const char*)materialInfo.m_TextureInfoList.data(), sizeof(TextureInfo) * materialInfo.m_Header.m_TextureCount);
	}

	std::ofstream ofs(_outPath, std::ios::binary);

	FileHeader fileHeader;

	fileHeader.m_Magic = CANDY_MAKE_FOURCC_STR("FBX_");
	fileHeader.m_Version = CONVERT_FBX_VERSION;
	fileHeader.m_HeaderSize = sizeof(FileHeader);
	fileHeader.m_Size = sizeof(FileHeader) + os.str().size();

	ofs.write((const char*)&fileHeader, sizeof(FileHeader));
	ofs.write((const char*)os.str().data(), os.str().size());

	ofs.close();

	return true;
}

void RecursiveNode(std::vector<MeshInfo>& _outMeshInfoList, FbxNode* _node)
{
	auto attribute = _node->GetNodeAttribute();
	if (attribute != nullptr && attribute->GetAttributeType() == FbxNodeAttribute::eMesh)
	{
		if (auto mesh = _node->GetMesh())
		{
			s32 polygonCount = mesh->GetPolygonCount();
			MeshInfo meshInfo;
			meshInfo.m_Header.m_ControlPointCount = mesh->GetControlPointsCount();
			meshInfo.m_Header.m_VertexCount = polygonCount * 3;

			meshInfo.m_ControlPointList.resize(meshInfo.m_Header.m_ControlPointCount);
			meshInfo.m_VertexInfoList.resize(meshInfo.m_Header.m_VertexCount);

			for (s32 i = 0; i < meshInfo.m_Header.m_ControlPointCount; ++i)
			{
				auto controlPoint = mesh->GetControlPointAt(i);
				meshInfo.m_ControlPointList[i].x = static_cast<f32>(controlPoint[0]);
				meshInfo.m_ControlPointList[i].y = static_cast<f32>(controlPoint[1]);
				meshInfo.m_ControlPointList[i].z = static_cast<f32>(controlPoint[2]);
				meshInfo.m_ControlPointList[i].w = 1.0f;
			}

			for (s32 i = 0; i < polygonCount; ++i)
			{
				for (s32 j = 0; j < 3; ++j)
				{
					meshInfo.m_ControlPointIndexList.push_back(mesh->GetPolygonVertex(i, j));

					FbxVector4 nor;
					mesh->GetPolygonVertexNormal(i, j, nor);
					meshInfo.m_VertexInfoList[i * 3 + j].m_Normal.x = (f32)nor[0];
					meshInfo.m_VertexInfoList[i * 3 + j].m_Normal.y = (f32)nor[1];
					meshInfo.m_VertexInfoList[i * 3 + j].m_Normal.z = (f32)nor[2];
					meshInfo.m_VertexInfoList[i * 3 + j].m_Normal.w = 1.0f;
				}
			}
			fbxsdk::FbxStringList uvSetNameList;
			mesh->GetUVSetNames(uvSetNameList);
			for (s32 i = 0; i < uvSetNameList.GetCount(); ++i)
			{
				FbxArray<FbxVector2> uvSet{};
				mesh->GetPolygonVertexUVs(uvSetNameList.GetStringAt(i), uvSet);
				assert(uvSet.GetCount() == polygonCount * 3);
				for (s32 j = 0; j < uvSet.GetCount(); ++j)
				{
					float* xRef = nullptr;
					float* yRef = nullptr;
					switch (i)
					{
					case 0:
						xRef = &meshInfo.m_VertexInfoList[j].m_TexCoord0.x;
						yRef = &meshInfo.m_VertexInfoList[j].m_TexCoord0.y;
						break;
					case 1:
						xRef = &meshInfo.m_VertexInfoList[j].m_TexCoord0.z;
						yRef = &meshInfo.m_VertexInfoList[j].m_TexCoord0.w;
						break;
					case 2:
						xRef = &meshInfo.m_VertexInfoList[j].m_TexCoord1.x;
						yRef = &meshInfo.m_VertexInfoList[j].m_TexCoord1.y;
						break;
					case 3:
						xRef = &meshInfo.m_VertexInfoList[j].m_TexCoord1.z;
						yRef = &meshInfo.m_VertexInfoList[j].m_TexCoord1.w;
						break;
					}
					if (xRef && yRef)
					{
						*xRef = uvSet[j].mData[0];
						*yRef = uvSet[j].mData[1];
					}
					else
					{
						std::cout << "over 4uv" << std::endl;
						break;
					}
				}
			}
			if (mesh->GetElementMaterialCount() > 0)
			{
				if (FbxLayerElementMaterial* material = mesh->GetElementMaterial(0))
				{
					if (FbxSurfaceMaterial* surfaceMaterial = mesh->GetNode()->GetSrcObject<FbxSurfaceMaterial>(material->GetIndexArray().GetAt(0)))
					{
						strcpy_s(meshInfo.m_Header.m_MaterialName, surfaceMaterial->GetName());
					}
				}
			}
			strcpy_s(meshInfo.m_Header.m_Name, _node->GetName());
			_outMeshInfoList.push_back(meshInfo);
		}
	}
	for (s32 i = 0; i < _node->GetChildCount(); ++i)
	{
		RecursiveNode(_outMeshInfoList, _node->GetChild(i));
	}
}

std::vector<TextureInfo> GetTextureInfo(FbxSurfaceMaterial* _material)
{
	std::vector<TextureInfo> textureInfoList;

	for (s32 i = 0; i < FbxLayerElement::sTypeTextureCount; ++i)
	{
		auto prop = _material->FindProperty(FbxLayerElement::sTextureChannelNames[i]);
		if (!prop.IsValid())continue;
		for (s32 j = 0; j < prop.GetSrcObjectCount<FbxTexture>(); ++j)
		{
			if (auto layeredTexture = prop.GetSrcObject<FbxLayeredTexture>(j))
			{
				for (s32 k = 0; k < layeredTexture->GetSrcObjectCount<FbxTexture>(); ++k)
				{
					FbxFileTexture* texture = FbxCast<FbxFileTexture>(layeredTexture->GetSrcObject<FbxTexture>(k));
					if (!texture)continue;
					TextureInfo textureInfo;
					strcpy_s(textureInfo.m_FilePath, texture->GetRelativeFileName());
					textureInfoList.push_back(textureInfo);
				}
			}
			else
			{
				FbxFileTexture* texture = FbxCast<FbxFileTexture>(prop.GetSrcObject<FbxTexture>(j));
				if (!texture)continue;
				TextureInfo textureInfo;
				strcpy_s(textureInfo.m_FilePath, texture->GetFileName());
				textureInfoList.push_back(textureInfo);
			}
		}
	}
	return textureInfoList;
}

std::vector<MaterialInfo> GetMaterialInfo(FbxScene* _scene)
{
	const s32 materialCount = _scene->GetMaterialCount();
	std::vector<MaterialInfo> materialInfoList;

	for (s32 i = 0; i < materialCount; ++i)
	{
		auto material = _scene->GetMaterial(i);
		if (!material)continue;

		MaterialInfo materialInfo;
		materialInfo.m_TextureInfoList = GetTextureInfo(material);
		materialInfo.m_Header.m_TextureCount = materialInfo.m_TextureInfoList.size();
		strcpy_s(materialInfo.m_Header.m_Name, material->GetName());

		materialInfoList.push_back(materialInfo);
	}

	return materialInfoList;
}
