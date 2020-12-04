#pragma once
#include<d3d9.h>

#define WHEELUP 120
#define WHEELDOWN -120

struct Vertex
{
	FLOAT x, y, z;
	DWORD diffuse;
};

#define D3DFVF_Vertex (D3DFVF_XYZ|D3DFVF_DIFFUSE)