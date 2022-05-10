struct VS_INPUT
{
    float4 m_Position : POSITION;
    float4 m_Color : COLOR;
};

struct VS_OUTPUT
{
    float4 m_Position : SV_Position;
    float4 m_Color : COLOR;
};

struct PS_OUTPUT
{
	float4 m_Color : SV_Target;
};

VS_OUTPUT vsMain(VS_INPUT _vsInput)
{
	VS_OUTPUT vsOutput;
	
    vsOutput.m_Position = _vsInput.m_Position;
    vsOutput.m_Color = _vsInput.m_Color;
    
	return vsOutput;
}

PS_OUTPUT psMain(VS_OUTPUT _vsOutput)
{
	PS_OUTPUT psOutput;
	
    psOutput.m_Color = _vsOutput.m_Color;
    
	return psOutput;
}