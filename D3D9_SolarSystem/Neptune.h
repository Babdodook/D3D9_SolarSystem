#pragma once

#include"Planet.h"

class CNeptune : public CPlanet
{
public:
	CNeptune();
	~CNeptune();

	virtual void OnInit(LPDIRECT3DDEVICE9 _pd3dDevice);
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();

	virtual void SetupMatrix();
};