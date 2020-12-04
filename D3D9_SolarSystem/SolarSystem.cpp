#include"SolarSystem.h"

CSolarSystem::CSolarSystem()
{

}

CSolarSystem::~CSolarSystem()
{

}

void CSolarSystem::OnInit(LPDIRECT3DDEVICE9 _pd3dDevice, HWND _hWnd)
{
	m_pd3dDevice = _pd3dDevice;
	m_hWnd = _hWnd;

	Sun.OnInit(m_pd3dDevice);
	Earth.OnInit(m_pd3dDevice);
	Mercury.OnInit(m_pd3dDevice);
	Venus.OnInit(m_pd3dDevice);
	Mars.OnInit(m_pd3dDevice);
	Jupiter.OnInit(m_pd3dDevice);
	Saturn.OnInit(m_pd3dDevice);
	Uranus.OnInit(m_pd3dDevice);
	Neptune.OnInit(m_pd3dDevice);
}

void CSolarSystem::OnUpdate()
{
	// 행성 행렬 업데이트
	Sun.OnUpdate();

	Earth.SetRotAxis(Sun.GetRotAxis());
	Earth.OnUpdate();

	Mercury.SetRotAxis(Sun.GetRotAxis());
	Mercury.OnUpdate();

	Venus.SetRotAxis(Sun.GetRotAxis());
	Venus.OnUpdate();

	Mars.SetRotAxis(Sun.GetRotAxis());
	Mars.OnUpdate();

	Jupiter.SetRotAxis(Sun.GetRotAxis());
	Jupiter.OnUpdate();

	Saturn.SetRotAxis(Sun.GetRotAxis());
	Saturn.OnUpdate();

	Uranus.SetRotAxis(Sun.GetRotAxis());
	Uranus.OnUpdate();

	Neptune.SetRotAxis(Sun.GetRotAxis());
	Neptune.OnUpdate();
}

void CSolarSystem::OnRender()
{
	// 라이트 오프
	m_pd3dDevice->SetRenderState(D3DRS_LIGHTING, FALSE);

	// 행성 그리기
	Sun.OnRender();
	Earth.OnRender();
	Mercury.OnRender();
	Venus.OnRender();
	Mars.OnRender();
	Jupiter.OnRender();
	Saturn.OnRender();
	Uranus.OnRender();
	Neptune.OnRender();
}

void CSolarSystem::OnRelease()
{
	Sun.OnRelease();
	Earth.OnRelease();
	Mercury.OnRelease();
	Venus.OnRelease();
	Mars.OnRelease();
	Jupiter.OnRelease();
	Saturn.OnRelease();
	Uranus.OnRelease();
	Neptune.OnRelease();
}