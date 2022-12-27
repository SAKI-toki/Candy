#include "Common.h"
#include "Write.h"

struct ResultSuccess {};

class Result
{
public:
	Result() : m_bSuccess{ false }, m_ErrorMessage{ "not yet set result."}
	{}
	Result(ResultSuccess) : m_bSuccess{ true }, m_ErrorMessage{}
	{}
	Result(const std::string& _errorMessage) : m_bSuccess{ false }, m_ErrorMessage{ _errorMessage }
	{}

	std::string GetErrorMessage()const { return m_ErrorMessage; }

	operator bool()const { return m_bSuccess; }

private:
	bool m_bSuccess;
	std::string m_ErrorMessage;
};
const Result Success{ ResultSuccess{} };
#define FALSE_RETURN_RESULT(EXPR) do{ if(!(EXPR))return Result{ #EXPR }; }while(false)


template<typename T>
bool parseInt(T& _outResult, const std::string& _str)
{
	char* endPtr = nullptr;
	_outResult = static_cast<T>(std::strtol(_str.data(), &endPtr, 10));
	if (!endPtr)return false;
	return _str.data() + _str.size() == endPtr;
}
Result Convert(const std::string& _inPath, const std::string& _outPath);
Result ConvertMeshPrimitve(Mesh::MeshInfo& _outMeshInfo, const glTF::MeshPrimitive& _primitive,
	const std::string& _meshName, const glTF::Document& _document, const std::unique_ptr<glTF::GLTFResourceReader>& _resourceReader);
Result ConvertMaterial(Material::MaterialInfo& _outMaterialInfo, const glTF::Material& _material,
	const glTF::Document& _document, const std::unique_ptr<glTF::GLTFResourceReader>& _resourceReader);

int main(int _argc, c8* _argv[])
{
	std::optional<std::string> inPath;
	std::optional<std::string> outPath;
	for (s32 i = 1; i < _argc - 1; ++i)
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

	Result result;
	try
	{
		result = Convert(inPath.value(), outPath.value());
	}
	catch (std::exception& _e)
	{
		result = Result{ _e.what() };
	}

	if (result)
	{
		std::cout << "success" << std::endl;
	}
	else
	{
		std::cout << "error" << std::endl;
		std::cout << result.GetErrorMessage() << std::endl;
		return -1;
	}
	return 0;
}

Result Convert(const std::string& _inPath, const std::string& _outPath)
{
	class StreamReader : public glTF::IStreamReader
	{
	public:
		StreamReader(const std::string& _basePath) : m_BasePath{ _basePath + "\\" } {}
		std::shared_ptr<std::istream> GetInputStream(const std::string& _path)const
		{
			return std::make_shared<std::ifstream>(m_BasePath + _path, std::ios_base::binary);
		}
	private:
		std::string m_BasePath;
	};
	auto streamReader = std::make_unique<StreamReader>(std::filesystem::path{ _inPath }.parent_path().string());
	FALSE_RETURN_RESULT(streamReader != nullptr);
	auto gltfStream = streamReader->GetInputStream(std::filesystem::path{ _inPath }.filename().string());
	FALSE_RETURN_RESULT(gltfStream != nullptr);
	auto resourceReader = std::make_unique<glTF::GLTFResourceReader>(std::move(streamReader));
	FALSE_RETURN_RESULT(resourceReader != nullptr);
	const std::string manifest = [&gltfStream]()
	{
		std::stringstream ss;
		ss << gltfStream->rdbuf();
		return ss.str();
	}();
	const auto document = glTF::Deserialize(manifest);

	WriteData writeData;

	std::cout << "Mesh Convert Begin" << std::endl;
	{
		const auto meshCount = document.meshes.Size();
		FALSE_RETURN_RESULT(meshCount > 0);
		for (s32 i = 0; i < meshCount; ++i)
		{
			const auto& mesh = document.meshes[i];
			for (s32 j = 0; j < (s32)mesh.primitives.size(); ++j)
			{
				Mesh::MeshInfo meshInfo;
				const auto result = ConvertMeshPrimitve(meshInfo, mesh.primitives[j], std::format("{0}_{1}", mesh.name, j), document, resourceReader);
				if (!result)return result;
				writeData.m_MeshInfoList.push_back(meshInfo);
			}
		}
	}
	std::cout << "Mesh Convert End" << std::endl;

	std::cout << "Material Convert Begin" << std::endl;
	{
		const auto materialCount = document.materials.Size();
		FALSE_RETURN_RESULT(materialCount > 0);
		for (s32 i = 0; i < materialCount; ++i)
		{
			const auto& material = document.materials[i];
			Material::MaterialInfo materialInfo;
			const auto result = ConvertMaterial(materialInfo, material, document, resourceReader);
			if (!result)return result;
			writeData.m_MaterialInfoList.push_back(materialInfo);
		}
	}
	std::cout << "Material Convert End" << std::endl;

	ConvertWrite(_outPath, writeData);

	return Success;
}

Result ConvertMeshPrimitve(Mesh::MeshInfo& _outMeshInfo, const glTF::MeshPrimitive& _primitive,
	const std::string& _meshName, const glTF::Document& _document, const std::unique_ptr<glTF::GLTFResourceReader>& _resourceReader)
{
	strcpy_s(_outMeshInfo.m_Header.m_Name, _meshName.c_str());

	const auto& positionAccessor = _document.accessors[_primitive.GetAttributeAccessorId(glTF::ACCESSOR_POSITION)];
	const auto positions = glTF::MeshPrimitiveUtils::GetPositions(_document, *_resourceReader, positionAccessor);
	_outMeshInfo.m_VertexInfoList.resize(positions.size() / 3);
	_outMeshInfo.m_Header.m_VertexInfoCount = (u32)positions.size() / 3;
	for (s32 j = 0; j < (s32)positions.size() / 3; ++j)
	{
		_outMeshInfo.m_VertexInfoList[j].m_Position = Vec4{ positions[j * 3 + 0], positions[j * 3 + 1], positions[j * 3 + 2], 1.0f };
	}

	if (_primitive.attributes.contains(glTF::ACCESSOR_NORMAL))
	{
		const auto& normalAccessor = _document.accessors[_primitive.GetAttributeAccessorId(glTF::ACCESSOR_NORMAL)];
		const auto normals = glTF::MeshPrimitiveUtils::GetNormals(_document, *_resourceReader, normalAccessor);
		FALSE_RETURN_RESULT(_outMeshInfo.m_VertexInfoList.size() == normals.size() / 3);

		for (s32 j = 0; j < (s32)normals.size() / 3; ++j)
		{
			_outMeshInfo.m_VertexInfoList[j].m_Normal = Vec4{ normals[j * 3 + 0], normals[j * 3 + 1], normals[j * 3 + 2], 1.0f };
		}
	}

	if (_primitive.attributes.contains(glTF::ACCESSOR_TANGENT))
	{
		const auto& tangentAccessor = _document.accessors[_primitive.GetAttributeAccessorId(glTF::ACCESSOR_TANGENT)];
		const auto tangents = glTF::MeshPrimitiveUtils::GetTangents(_document, *_resourceReader, tangentAccessor);
		FALSE_RETURN_RESULT(_outMeshInfo.m_VertexInfoList.size() == tangents.size() / 4);

		for (s32 j = 0; j < (s32)tangents.size() / 4; ++j)
		{
			_outMeshInfo.m_VertexInfoList[j].m_Tangent = Vec4{ tangents[j * 4 + 0], tangents[j * 4 + 1], tangents[j * 4 + 2], tangents[j * 4 + 3] };
		}
	}

	if (_primitive.attributes.contains(glTF::ACCESSOR_TEXCOORD_0))
	{
		const auto& texcoordAccessor = _document.accessors[_primitive.GetAttributeAccessorId(glTF::ACCESSOR_TEXCOORD_0)];
		const auto texcoords = glTF::MeshPrimitiveUtils::GetTexCoords(_document, *_resourceReader, texcoordAccessor);
		FALSE_RETURN_RESULT(_outMeshInfo.m_VertexInfoList.size() == texcoords.size() / 2);

		for (s32 j = 0; j < (s32)texcoords.size() / 2; ++j)
		{
			_outMeshInfo.m_VertexInfoList[j].m_TexCoord0.x = texcoords[j * 2 + 0];
			_outMeshInfo.m_VertexInfoList[j].m_TexCoord0.y = texcoords[j * 2 + 1];
		}
	}

	if (_primitive.attributes.contains(glTF::ACCESSOR_TEXCOORD_1))
	{
		const auto& texcoordAccessor = _document.accessors[_primitive.GetAttributeAccessorId(glTF::ACCESSOR_TEXCOORD_1)];
		const auto texcoords = glTF::MeshPrimitiveUtils::GetTexCoords(_document, *_resourceReader, texcoordAccessor);
		FALSE_RETURN_RESULT(_outMeshInfo.m_VertexInfoList.size() == texcoords.size() / 2);

		for (s32 j = 0; j < (s32)texcoords.size() / 2; ++j)
		{
			_outMeshInfo.m_VertexInfoList[j].m_TexCoord0.z = texcoords[j * 2 + 0];
			_outMeshInfo.m_VertexInfoList[j].m_TexCoord0.w = texcoords[j * 2 + 1];
		}
	}

	const auto& indexAccessor = _document.accessors[_primitive.indicesAccessorId];
	const auto indices = glTF::MeshPrimitiveUtils::GetIndices32(_document, *_resourceReader, indexAccessor);
	_outMeshInfo.m_VertexIndexList.resize(indices.size());
	_outMeshInfo.m_Header.m_VertexIndexCount = (u32)indices.size();
	for (s32 j = 0; j < (s32)indices.size(); ++j)
	{
		_outMeshInfo.m_VertexIndexList[j] = indices[j];
	}

	FALSE_RETURN_RESULT(parseInt(_outMeshInfo.m_Header.m_MaterialIndex, _primitive.materialId));

	return Success;
}

Result ConvertMaterial(Material::MaterialInfo& _outMaterialInfo, const glTF::Material& _material,
	const glTF::Document& _document, const std::unique_ptr<glTF::GLTFResourceReader>& _resourceReader)
{
	const auto textures = _material.GetTextures();
	for (const auto& texture : textures)
	{
		if (texture.first.empty())continue;

		Material::TextureInfo textureInfo;
		switch (texture.second)
		{
		case glTF::TextureType::BaseColor:	textureInfo.m_Type = Material::TEXTURE_TYPE::ALBEDO;	break;
		case glTF::TextureType::Normal:		textureInfo.m_Type = Material::TEXTURE_TYPE::NORMAL;	break;
		}
		if (textureInfo.m_Type == Material::TEXTURE_TYPE::NONE)continue;
		s32 textureId = 0;
		FALSE_RETURN_RESULT(parseInt(textureId, texture.first));
		s32 imageId = 0;
		FALSE_RETURN_RESULT(parseInt(imageId, _document.textures[textureId].imageId));
		strcpy_s(textureInfo.m_FileName, std::filesystem::path(_document.images[imageId].uri).replace_extension("dds").string().c_str());
		_outMaterialInfo.m_TextureInfoList.push_back(textureInfo);
	}
	return Success;
}
