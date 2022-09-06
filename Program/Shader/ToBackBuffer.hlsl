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

Texture2D<float4> testTexture : register(t0);
SamplerState testSampler : register(s0);

VS_OUTPUT vsMain(VS_INPUT _vsInput)
{
	VS_OUTPUT vsOutput;
	
    vsOutput.m_Position = _vsInput.m_Position;
    vsOutput.m_TexCoord = _vsInput.m_TexCoord;
    
	return vsOutput;
}

PS_OUTPUT psMain(VS_OUTPUT _vsOutput)
{
	PS_OUTPUT psOutput;
	
    psOutput.m_Color = testTexture.Sample(testSampler, _vsOutput.m_TexCoord.xy);
    
	return psOutput;
}