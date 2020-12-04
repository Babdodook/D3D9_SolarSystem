#pragma once

#include"Planet.h"

class CVenus : public CPlanet
{
public:
	CVenus();
	~CVenus();

	virtual void OnInit(LPDIRECT3DDEVICE9 _pd3dDevice);
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();

	virtual void SetupMatrix();
};