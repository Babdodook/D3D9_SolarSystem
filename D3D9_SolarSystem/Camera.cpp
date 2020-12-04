#include"Camera.h"

CCamera::CCamera()
{

}

CCamera::~CCamera()
{

}

void CCamera::SetUp(LPDIRECT3DDEVICE9 pd3dDevice, RECT _rect, HWND _hWnd)
{
    m_pd3dDevice = pd3dDevice;
    rect = _rect;

    // 뷰포트 세팅
    vp.X = 0;
    vp.Y = 0;
    vp.Width = rect.right - rect.left;
    vp.Height = rect.bottom - rect.top;
    vp.MinZ = 0.0f;
    vp.MaxZ = 1.0f;

    //카메라
    m_vEye = D3DXVECTOR3(0.0f, 30.0f, -50.0f);
    m_vLook = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_vUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
    D3DXMatrixLookAtLH(&m_matView, &m_vEye, &m_vLook, &m_vUp);
    m_pd3dDevice->SetTransform(D3DTS_VIEW, &m_matView);

    //투영
    D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 4, 2.0f, 1.0f, 1000.0f);
    m_pd3dDevice->SetTransform(D3DTS_PROJECTION, &m_matProj);

    // 뷰포트 변환
    m_pd3dDevice->SetViewport(&vp);

    //마우스 포지션을 화면 중앙으로 바꾸어 준다.
    m_pt.x = rect.right - rect.left / 2;
    m_pt.y = rect.bottom - rect.top / 2;

    // 현제 마우스는 클라이언트 좌표 기준으로 설정되있다.
    ClientToScreen(_hWnd, &m_pt);           // 스크린 영역으로 바꾸기 위해 ClientToScreen 를 사용
    SetCursorPos(m_pt.x, m_pt.y);           // 커서를 스크린 영역 x ,y 에 배치

    ShowCursor(false);
}

void CCamera::RotationCross(float fAngle)
{
    D3DXMATRIXA16 matRot;
    D3DXVECTOR3	vDist;

    D3DXMatrixRotationY(&matRot, fAngle);
    memcpy(&matRot._41, &m_vLook, sizeof(D3DXVECTOR3));
    vDist = m_vEye - m_vLook;

    for (int i = 0; i < 4; ++i)
    {
        D3DXVec3TransformNormal(&m_vAxis[i], &m_vAxis[i], &matRot);
        D3DXVec3Normalize(&m_vAxis[i], &m_vAxis[i]);
    }
    D3DXVec3TransformCoord(&m_vEye, &vDist, &matRot);
    D3DXMatrixLookAtLH(&m_matView, &m_vEye, &m_vLook, &m_vUp);
    m_pd3dDevice->SetTransform(D3DTS_VIEW, &m_matView);
}

void CCamera::RotationUp(float fAngle)
{
    D3DXMATRIXA16 matRot;
    D3DXVECTOR3	vDist;

    D3DXMatrixRotationAxis(&matRot, &m_vAxis[0], fAngle);
    memcpy(&matRot._41, &m_vLook, sizeof(D3DXVECTOR3));
    vDist = m_vEye - m_vLook;

    for (int i = 0; i < 4; ++i)
    {
        if (i == 0)
            continue;

        D3DXVec3TransformNormal(&m_vAxis[i], &m_vAxis[i], &matRot);
        D3DXVec3Normalize(&m_vAxis[i], &m_vAxis[i]);
    }
    D3DXVec3TransformCoord(&m_vEye, &vDist, &matRot);
}

void CCamera::OnUpdate()
{
    POINT  pt;                                      //현재 마우스 위치 , m_pt는 화면중앙 좌표

    GetCursorPos(&pt);
    RotationCross((pt.x - m_pt.x) / 100.0f);
    //RotationUp((pt.y - m_pt.y) / 100.0f);

    //다시 화면의 중앙으로 마우스를 셋팅
    SetCursorPos(m_pt.x, m_pt.y);
}