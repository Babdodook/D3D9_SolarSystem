#pragma once

#include<d3d9.h>
#include<d3dx9.h>
#include <d3dx9math.h>

#include"Sun.h"
#include"Earth.h"
#include"Mercury.h"
#include"Venus.h"
#include"Mars.h"
#include"Jupiter.h"
#include"Saturn.h"
#include"Uranus.h"
#include"Neptune.h"

/*
*	태양계 클래스
*	태양계 클래스가 모든 행성을 하위 클래스로 가지고 있다.
*	지구는 달 위성을 하위 클래스로 가지고 있다.
*	모든 행성은 태양의 자전 행렬을 기준으로 공전 행렬을 계산한다.
*/

class CSolarSystem
{
private:
	LPDIRECT3DDEVICE9	m_pd3dDevice;
	HWND m_hWnd;

private:
	CSun Sun;
	CEarth Earth;
	CMercury Mercury;
	CVenus Venus;
	CMars Mars;
	CJupiter Jupiter;
	CSaturn Saturn;
	CUranus Uranus;
	CNeptune Neptune;

public:
	CSolarSystem();
	~CSolarSystem();

	void OnInit(LPDIRECT3DDEVICE9 _pd3dDevice, HWND _hWnd);
	void OnUpdate();
	void OnRender();
	void OnRelease();
};