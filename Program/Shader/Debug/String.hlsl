struct VS_INPUT
{
    float4 m_Position : POSITION;
    float4 m_TexCoord : TEXCOORD;
    float4 m_Color : COLOR;
};

struct VS_OUTPUT
{
    float4 m_Position : SV_Position;
    float4 m_TexCoord : TEXCOORD;
    float4 m_Color : COLOR;
};

struct PS_OUTPUT
{
	float4 m_Color : SV_Target;
};

Texture2D<float4> fontTexture : register(t0);
SamplerState fontSampler : register(s0);

VS_OUTPUT vsMain(VS_INPUT _vsInput)
{
	VS_OUTPUT vsOutput;
	
    vsOutput.m_Position = _vsInput.m_Position;
    vsOutput.m_Color = _vsInput.m_Color;
    vsOutput.m_TexCoord = _vsInput.m_TexCoord;
    
	return vsOutput;
}

PS_OUTPUT psMain(VS_OUTPUT _vsOutput)
{
	PS_OUTPUT psOutput;
	
    float4 texCol = fontTexture.Sample(fontSampler, _vsOutput.m_TexCoord.xy);
    psOutput.m_Color = _vsOutput.m_Color * texCol.a;
	
	return psOutput;
}