#pragma once

#include"Global.h"
#include<d3d9.h>
#include<d3dx9.h>
#include <d3dx9math.h>

class CPlanet
{
protected:
	LPDIRECT3DDEVICE9	m_pd3dDevice;
	LPD3DXMESH			m_pMesh;		// 메쉬
	LPDIRECT3DTEXTURE9	m_pTexture;		// 텍스쳐
	
	D3DXMATRIXA16 m_matWorld;			// 월드 적용할 행렬
	D3DXMATRIXA16 m_matRotateSelf;		// 자전
	D3DXMATRIXA16 m_matTranslate;		// 이동
	D3DXMATRIXA16 m_AroundRotateSpeed;	// 공전 속도 조절
	D3DXMATRIXA16 m_matRotateAxis;		// 공전에 기준이되는 축
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

	// 행성 생성
	void CreatePlanet(FLOAT _Radius, UINT _Slices, UINT _Stacks, const char * texture);
public:
	void SetTransform();

	// 자전 행렬 반환
	D3DXMATRIXA16& GetRotAxis();
	// 자전 행렬 세팅
	void SetRotAxis(D3DXMATRIXA16&);
};