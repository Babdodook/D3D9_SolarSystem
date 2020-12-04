#include"Moon.h"

CMoon::CMoon()
{

}

CMoon::~CMoon()
{

}

void CMoon::OnInit(LPDIRECT3DDEVICE9 _pd3dDevice)
{
	m_pd3dDevice = _pd3dDevice;
	CPlanet::CreatePlanet(0.3f, 10, 10, "Moon.jpg");
}

void CMoon::OnUpdate()
{
	SetupMatrix();
}

void CMoon::OnRender()
{
	m_pd3dDevice->SetTexture(0, m_pTexture);
	m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLOROP, D3DTOP_MODULATE);
	m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG1, D3DTA_TEXTURE);
	m_pd3dDevice->SetTextureStageState(0, D3DTSS_COLORARG2, D3DTA_DIFFUSE);
	m_pd3dDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_DISABLE);

	m_pd3dDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	m_pMesh->DrawSubset(0);
}

void CMoon::OnRelease()
{
	if (m_pMesh != NULL)
		m_pMesh->Release();
}

void CMoon::SetupMatrix()
{
	if (rotateAngle >= 360)
		rotateAngle = 0;
	rotateAngle += 0.01f;

	if (AroundAngle >= 360)
		AroundAngle = 0;
	AroundAngle += 0.07f;

	D3DXMatrixRotationY(&m_matRotateSelf, rotateAngle);
	D3DXMatrixRotationY(&m_AroundRotateSpeed, AroundAngle);
	D3DXMatrixTranslation(&m_matTranslate, 2.0f, 0.0f, 0.0f);

	// 행렬 계산
	m_matWorld = m_matRotateSelf * m_matTranslate * m_AroundRotateSpeed * m_matRotateAxis;
}