#include"Planet.h"

struct CUSTOMVERTEX
{
	//D3DXVECTOR3 position; // The position
	FLOAT x, y, z;
	D3DXVECTOR3 norm;
	FLOAT tu, tv;   // The texture coordinates
};

#define D3DFVF_CUSTOMVERTEX (D3DFVF_XYZ|D3DFVF_NORMAL|D3DFVF_TEX1)

void CPlanet::CreatePlanet(FLOAT _Radius, UINT _Slices, UINT _Stacks, const char * texture)
{
	// �޽� �纻 ������
	LPD3DXMESH pTempSunMesh;
	// �޽��� ���ؽ������� �˱����� ����
	LPDIRECT3DVERTEXBUFFER9 pTempVertexBuffer;

	// �ؽ�ó ����
	FAILED(D3DXCreateTextureFromFile(m_pd3dDevice, texture, &m_pTexture));
	
	// ��ü ����
	D3DXCreateSphere(m_pd3dDevice, _Radius, _Slices, _Stacks, &pTempSunMesh, NULL);

	// �ؽ��� ��ǥ�� ������ �޽� �纻�� �����.
	// D3D�Լ��� �ؽ��� ��ǥ�� ������ ���� �ʱ� ����
	pTempSunMesh->CloneMeshFVF(0, D3DFVF_CUSTOMVERTEX, m_pd3dDevice, &m_pMesh);

	// �޽��� ���ؽ� ���۸� ������
	if (SUCCEEDED(m_pMesh->GetVertexBuffer(&pTempVertexBuffer)))
	{
		// ���ؽ��� ������ �˾Ƴ��� (for�� ����������)
		int nNumVerts = m_pMesh->GetNumVertices();
		CUSTOMVERTEX* pVertices = NULL;

		// ���ؽ����� ��
		pTempVertexBuffer->Lock(0, 0, (void**)&pVertices, 0);

		// ���ؽ����� �ؽ����� uv��ǥ�� ����ؼ� �Ҵ�����
		for (int i = 0; i < nNumVerts; i++)
		{
			pVertices[i].tu = asinf(pVertices[i].norm.x) / D3DX_PI + 0.5f;
			pVertices[i].tv = asinf(pVertices[i].norm.y) / D3DX_PI + 0.5f;
		}
	}
	// ���ؽ����� ���, ����
	pTempVertexBuffer->Unlock();
	pTempVertexBuffer->Release();

	rotateAngle = 0;
	AroundAngle = 0;
}

D3DXMATRIXA16& CPlanet::GetRotAxis()
{
	return m_matRotateAxis;
}

void CPlanet::SetRotAxis(D3DXMATRIXA16& _matRotAxis)
{
	m_matRotateAxis = _matRotAxis;
}

void CPlanet::SetTransform()
{
	m_pd3dDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
}