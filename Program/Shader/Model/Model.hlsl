struct VS_INPUT
{
    float4 m_Position : POSITION;
    float4 m_Normal : NORMAL;
    float4 m_TexCoord0 : TEXCOORD0;
    float4 m_TexCoord1 : TEXCOORD1;
};

struct VS_OUTPUT
{
    float4 m_Position : SV_Position;
    float4 m_Normal : NORMAL;
    float4 m_TexCoord0 : TEXCOORD0;
    float4 m_TexCoord1 : TEXCOORD1;
};

struct PS_OUTPUT
{
	float4 m_Color : SV_Target;
};

cbuffer CameraParam : register(b0)
{
    float4x4 g_ViewMtx;
    float4x4 g_ProjectionMtx;
    float4x4 g_ViewProjectionMtx;
};

cbuffer ModelParam : register(b1)
{
    float4x4 g_WorldMtx;
    float4x4 g_RotMtx;
};

Texture2D<float4> albedoTexture : register(t0);
SamplerState albedoTextureSampler : register(s0);

VS_OUTPUT vsMain(VS_INPUT _vsInput)
{
    VS_OUTPUT vsOutput;
	
    vsOutput.m_Position = mul(_vsInput.m_Position, mul(g_WorldMtx, mul(g_ViewMtx, g_ProjectionMtx)));
    vsOutput.m_Normal = mul(_vsInput.m_Normal, g_RotMtx);
    vsOutput.m_TexCoord0 = _vsInput.m_TexCoord0;
    vsOutput.m_TexCoord1 = _vsInput.m_TexCoord1;
    
    return vsOutput;
}

PS_OUTPUT psMain(VS_OUTPUT _vsOutput)
{
    PS_OUTPUT psOutput;
	
    psOutput.m_Color = albedoTexture.Sample(albedoTextureSampler, _vsOutput.m_TexCoord0.xy) * dot(_vsOutput.m_Normal, float4(1.0f, 1.0f, -1.0f, 1.0f));
	
    return psOutput;
}
