struct VS_INPUT
{
	float4 m_Position : POSITION;
};

struct VS_OUTPUT
{
	float4 m_Position : SV_POSITION;
};

struct PS_OUTPUT
{
	float4 m_Color : SV_Target;
};

VS_OUTPUT vsMain(VS_INPUT _vsInput)
{
	VS_OUTPUT vsOutput;
	
	vsOutput.m_Position = _vsInput.m_Position;
	
	return vsOutput;
}

PS_OUTPUT psMain(VS_OUTPUT _vsOutput)
{
	PS_OUTPUT psOutput;
	
	psOutput.m_Color = float4(1.0f, 1.0f, 1.0f, 1.0f);
	
	return psOutput;
}