#pragma once
#include"D3DApp.h"
#include"SolarSystem.h"
#include"Camera.h"

class CGame : public CD3DApp
{
private:
	RECT rect;

private:
	CSolarSystem SolarSystem;
	CCamera Camera;

private:
	virtual void OnInit();
	virtual void OnUpdate();
	virtual void OnRender();
	virtual void OnRelease();

public:
	CGame();
	~CGame();

	void SetRect(RECT _rect);
};