#include"Game.h"

CGame::CGame()
{

}

CGame::~CGame()
{

}

void CGame::OnInit()
{
	SolarSystem.OnInit(m_pd3dDevice, m_hWnd);
	Camera.SetUp(m_pd3dDevice, rect, m_hWnd);
}

void CGame::OnUpdate()
{
	SolarSystem.OnUpdate();
	Camera.OnUpdate();
}

void CGame::OnRender()
{
	SolarSystem.OnRender();
}

void CGame::OnRelease()
{
	SolarSystem.OnRelease();
}

void CGame::SetRect(RECT _rect)
{
	rect = _rect;
}