#pragma once

#include<d3d9.h>
#include<d3dx9.h>

// 카메라 클래스
class CCamera
{
private:
	LPDIRECT3DDEVICE9 m_pd3dDevice;
	D3DXMATRIX m_matView;
	D3DXMATRIX m_matProj;
	D3DXVECTOR3 m_vAxis[4];
	D3DXVECTOR3 m_vEye, m_vLook, m_vUp;
	D3DVIEWPORT9 vp;
	RECT rect;
	POINT m_pt;

public:
	CCamera();
	~CCamera();

	void SetUp(LPDIRECT3DDEVICE9 pd3dDevice, RECT _rect, HWND _hWnd);
	void RotationCross(float fAngle);
	void RotationUp(float fAngle);

	void OnUpdate();
};