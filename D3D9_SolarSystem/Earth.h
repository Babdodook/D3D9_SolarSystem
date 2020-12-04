#pragma once

#include"Planet.h"
#include"Moon.h"

class CEarth : public CPlanet
{
private:
	CMoon Moon;
public:
	CEarth();
	~CEarth();

	virtual void OnInit(LPDIRECT3DDEVICE9 _pd3dDevice);
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();

	virtual void SetupMatrix();
};