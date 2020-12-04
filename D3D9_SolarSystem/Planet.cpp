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
	// 메쉬 사본 만들기용
	LPD3DXMESH pTempSunMesh;
	// 메쉬의 버텍스정보를 알기위한 버퍼
	LPDIRECT3DVERTEXBUFFER9 pTempVertexBuffer;

	// 텍스처 생성
	FAILED(D3DXCreateTextureFromFile(m_pd3dDevice, texture, &m_pTexture));
	
	// 구체 생성
	D3DXCreateSphere(m_pd3dDevice, _Radius, _Slices, _Stacks, &pTempSunMesh, NULL);

	// 텍스쳐 좌표를 가지는 메쉬 사본을 만든다.
	// D3D함수는 텍스쳐 좌표를 가지고 있지 않기 때문
	pTempSunMesh->CloneMeshFVF(0, D3DFVF_CUSTOMVERTEX, m_pd3dDevice, &m_pMesh);

	// 메시의 버텍스 버퍼를 가져옴
	if (SUCCEEDED(m_pMesh->GetVertexBuffer(&pTempVertexBuffer)))
	{
		// 버텍스의 개수를 알아낸다 (for문 돌리기위함)
		int nNumVerts = m_pMesh->GetNumVertices();
		CUSTOMVERTEX* pVertices = NULL;

		// 버텍스버퍼 락
		pTempVertexBuffer->Lock(0, 0, (void**)&pVertices, 0);

		// 버텍스마다 텍스쳐의 uv좌표를 계산해서 할당해줌
		for (int i = 0; i < nNumVerts; i++)
		{
			pVertices[i].tu = asinf(pVertices[i].norm.x) / D3DX_PI + 0.5f;
			pVertices[i].tv = asinf(pVertices[i].norm.y) / D3DX_PI + 0.5f;
		}
	}
	// 버텍스버퍼 언락, 해제
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