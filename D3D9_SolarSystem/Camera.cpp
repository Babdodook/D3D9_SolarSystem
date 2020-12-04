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

    // ����Ʈ ����
    vp.X = 0;
    vp.Y = 0;
    vp.Width = rect.right - rect.left;
    vp.Height = rect.bottom - rect.top;
    vp.MinZ = 0.0f;
    vp.MaxZ = 1.0f;

    //ī�޶�
    m_vEye = D3DXVECTOR3(0.0f, 30.0f, -50.0f);
    m_vLook = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
    m_vUp = D3DXVECTOR3(0.0f, 1.0f, 0.0f);
    D3DXMatrixLookAtLH(&m_matView, &m_vEye, &m_vLook, &m_vUp);
    m_pd3dDevice->SetTransform(D3DTS_VIEW, &m_matView);

    //����
    D3DXMatrixPerspectiveFovLH(&m_matProj, D3DX_PI / 4, 2.0f, 1.0f, 1000.0f);
    m_pd3dDevice->SetTransform(D3DTS_PROJECTION, &m_matProj);

    // ����Ʈ ��ȯ
    m_pd3dDevice->SetViewport(&vp);

    //���콺 �������� ȭ�� �߾����� �ٲپ� �ش�.
    m_pt.x = rect.right - rect.left / 2;
    m_pt.y = rect.bottom - rect.top / 2;

    // ���� ���콺�� Ŭ���̾�Ʈ ��ǥ �������� �������ִ�.
    ClientToScreen(_hWnd, &m_pt);           // ��ũ�� �������� �ٲٱ� ���� ClientToScreen �� ���
    SetCursorPos(m_pt.x, m_pt.y);           // Ŀ���� ��ũ�� ���� x ,y �� ��ġ

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
    POINT  pt;                                      //���� ���콺 ��ġ , m_pt�� ȭ���߾� ��ǥ

    GetCursorPos(&pt);
    RotationCross((pt.x - m_pt.x) / 100.0f);
    //RotationUp((pt.y - m_pt.y) / 100.0f);

    //�ٽ� ȭ���� �߾����� ���콺�� ����
    SetCursorPos(m_pt.x, m_pt.y);
}