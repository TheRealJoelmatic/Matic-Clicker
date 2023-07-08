#pragma once

#include <Windows.h>
#include <list>
#include <d3d9.h>
#include <d3dx9math.h>

#pragma comment(lib, "d3d9.lib")
#pragma comment(lib, "d3dx9.lib")

struct TransformMatrix
{
	D3DXMATRIX projection;
	D3DXMATRIX modelview;

	TransformMatrix()
	{
		D3DXMatrixIdentity(&projection);
		D3DXMatrixIdentity(&modelview);
	}
};

enum ObjectType
{
	Entity,
	Chest,
	LargeChest
};

struct ObjectData
{
	TransformMatrix transformMatrix;
	ObjectType type;
};

std::list<ObjectData> objects;

typedef HRESULT(WINAPI* Direct3DCreate9ExProc)(UINT, IDirect3D9Ex**);
typedef HRESULT(WINAPI* CreateDeviceExProc)(IDirect3D9Ex*, UINT, D3DDEVTYPE, HWND, DWORD, D3DPRESENT_PARAMETERS*, D3DDISPLAYMODEEX*, IDirect3DDevice9Ex**);

Direct3DCreate9ExProc fpDirect3DCreate9Ex = nullptr;
CreateDeviceExProc fpCreateDeviceEx = nullptr;

HRESULT WINAPI myDirect3DCreate9Ex(UINT sdkVersion, IDirect3D9Ex** ppD3D);
HRESULT WINAPI myCreateDeviceEx(IDirect3D9Ex* pD3D, UINT adapter, D3DDEVTYPE deviceType, HWND hFocusWindow, DWORD behaviorFlags,
	D3DPRESENT_PARAMETERS* pPresentationParameters, D3DDISPLAYMODEEX* pFullscreenDisplayMode, IDirect3DDevice9Ex** ppReturnedDeviceInterface);
void drawBox(IDirect3DDevice9Ex* pDevice, D3DXVECTOR4 color);

BOOL APIENTRY DllMain(HINSTANCE hInstance, DWORD reason, LPVOID lpReserved);

#pragma once
