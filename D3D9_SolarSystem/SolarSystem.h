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
*	�¾�� Ŭ����
*	�¾�� Ŭ������ ��� �༺�� ���� Ŭ������ ������ �ִ�.
*	������ �� ������ ���� Ŭ������ ������ �ִ�.
*	��� �༺�� �¾��� ���� ����� �������� ���� ����� ����Ѵ�.
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