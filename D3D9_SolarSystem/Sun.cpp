#include "Sun.h"

CSun::CSun()
{

}

CSun::~CSun()
{

}

void CSun::OnInit(LPDIRECT3DDEVICE9 _pd3dDevice)
{
	m_pd3dDevice = _pd3dDevice;
	CPlanet::CreatePlanet(5.0f, 30, 10, "Sun.jpg");
}

void CSun::OnUpdate()
{
	SetupMatrix();
}

void CSun::OnRender()
{
	m_pd3dDevice->SetTexture(0, m_pTexture);
	m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	m_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_DISABLE);

	m_pd3dDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	m_pMesh->DrawSubset(0);
}

void CSun::OnRelease()
{
	if (m_pMesh != NULL)
		m_pMesh->Release();
}

void CSun::SetupMatrix()
{
	if (rotateAngle >= 360)
		rotateAngle = 0;
	rotateAngle += 0.005f;

	D3DXMatrixRotationY(&m_matRotateSelf, rotateAngle);
	D3DXMatrixTranslation(&m_matTranslate, 0.0f, 0.0f, 0.0f);

	m_matWorld = m_matRotateSelf * m_matTranslate;
	m_matRotateAxis = m_matWorld;
}