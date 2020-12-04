#pragma once

#include"Global.h"
#include<d3d9.h>
#include<d3dx9.h>
#include <d3dx9math.h>

class CPlanet
{
protected:
	LPDIRECT3DDEVICE9	m_pd3dDevice;
	LPD3DXMESH			m_pMesh;		// �޽�
	LPDIRECT3DTEXTURE9	m_pTexture;		// �ؽ���
	
	D3DXMATRIXA16 m_matWorld;			// ���� ������ ���
	D3DXMATRIXA16 m_matRotateSelf;		// ����
	D3DXMATRIXA16 m_matTranslate;		// �̵�
	D3DXMATRIXA16 m_AroundRotateSpeed;	// ���� �ӵ� ����
	D3DXMATRIXA16 m_matRotateAxis;		// ������ �����̵Ǵ� ��
	FLOAT rotateAngle;
	FLOAT AroundAngle;
public:
	CPlanet() = default;
	~CPlanet() = default;

	virtual void OnInit(LPDIRECT3DDEVICE9 _pd3dDevice) = 0;
	virtual void OnUpdate() = 0;
	virtual void OnRender() = 0;
	virtual void OnRelease() = 0;
	virtual void SetupMatrix() = 0;

	// �༺ ����
	void CreatePlanet(FLOAT _Radius, UINT _Slices, UINT _Stacks, const char * texture);
public:
	void SetTransform();

	// ���� ��� ��ȯ
	D3DXMATRIXA16& GetRotAxis();
	// ���� ��� ����
	void SetRotAxis(D3DXMATRIXA16&);
};