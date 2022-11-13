struct VS_INPUT
{
    float4 m_Position : POSITION;
    float4 m_TexCoord : TEXCOORD;
};

struct VS_OUTPUT
{
    float4 m_Position : SV_Position;
    float4 m_TexCoord : TEXCOORD;
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

cbuffer SpriteParam: register(b1)
{
    float4x4 g_WorldMtx;
    float4x4 g_RotMtx;
    float4 g_Color;
};

Texture2D<float4> spriteTexture : register(t0);
SamplerState spriteSampler : register(s0);

VS_OUTPUT vsMain(VS_INPUT _vsInput)
{
	VS_OUTPUT vsOutput;
	
    vsOutput.m_Position = mul(_vsInput.m_Position, mul(g_WorldMtx, mul(g_ViewMtx, g_ProjectionMtx)));
    vsOutput.m_TexCoord = _vsInput.m_TexCoord;
    
	return vsOutput;
}

PS_OUTPUT psMain(VS_OUTPUT _vsOutput)
{
	PS_OUTPUT psOutput;
	
    float4 texCol = spriteTexture.Sample(spriteSampler, _vsOutput.m_TexCoord.xy);
    psOutput.m_Color = texCol * g_Color;
    
	
	return psOutput;
}