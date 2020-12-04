#pragma once

#include"Planet.h"

class CMercury : public CPlanet
{
public:
	CMercury();
	~CMercury();

	virtual void OnInit(LPDIRECT3DDEVICE9 _pd3dDevice);
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();

	virtual void SetupMatrix();
};