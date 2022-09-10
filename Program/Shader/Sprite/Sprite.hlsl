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

cbuffer CONSTANT : register(b0)
{
    float4 pos;
    float4 col;
};

Texture2D<float4> spriteTexture : register(t0);
SamplerState spriteSampler : register(s0);

VS_OUTPUT vsMain(VS_INPUT _vsInput)
{
	VS_OUTPUT vsOutput;
	
    vsOutput.m_Position = _vsInput.m_Position + float4(pos.xyz, 0.0f);
    vsOutput.m_TexCoord = _vsInput.m_TexCoord;
    
	return vsOutput;
}

PS_OUTPUT psMain(VS_OUTPUT _vsOutput)
{
	PS_OUTPUT psOutput;
	
    float4 texCol = spriteTexture.Sample(spriteSampler, _vsOutput.m_TexCoord.xy);
    psOutput.m_Color = texCol * col;
    
	
	return psOutput;
}