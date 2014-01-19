// GameProgramming_Assignment1.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include "GameProgramming_Assignment1.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;								// current instance
static TCHAR szTitle[MAX_LOADSTRING] ;			// The title bar text

TCHAR szWindowClass[MAX_LOADSTRING];			// the main window class name
HBRUSH drawingBrush;
HPEN drawingPen;

POINT cursorPosition;

// Forward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
					   _In_opt_ HINSTANCE hPrevInstance,
					   _In_ LPTSTR    lpCmdLine,
					   _In_ int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_GAMEPROGRAMMING_ASSIGNMENT1, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAMEPROGRAMMING_ASSIGNMENT1));

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAMEPROGRAMMING_ASSIGNMENT1));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_GAMEPROGRAMMING_ASSIGNMENT1);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
	HWND hWnd;

	hInst = hInstance; // Store instance handle in our global variable

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	
	BOOLEAN rectum = false;
	PAINTSTRUCT ps;
	HDC hdc;
	COLORREF  neutral = 0x9900CC; 
	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Parse the menu selections:

		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;

		case IDM_BLUE:
			{
			COLORREF blue =RGB (0,0,255); 
		
				drawingPen = CreatePen(PS_DASHDOT,10, blue);
			}
			break;
		case IDM_PURPLE:
			{
			COLORREF purple = RGB (204,0,204);
			
				drawingPen = CreatePen(PS_DASHDOT,10, purple);
			}
			break;
		case IDM_GREEN:
			{
			COLORREF green = RGB (0,255,0);
		
				drawingPen = CreatePen(PS_DASHDOT,10, green);

			
			}
			break;

		case IDM_RED:
			{
				COLORREF red = RGB (255,0,0);
				drawingPen = CreatePen(PS_DASHDOT,10, red);
				neutral = red;
				return red;
			}
			break;
		case IDM_PEN:
			{
		//COLORREF blue = 0x00FF0000;
		//	drawingPen = CreatePen(PS_DASHDOT,10, blue);
			}
			break;

		case IDM_ELLIPSE:
			rectum = true;
			UpdateWindow(hWnd);
			InvalidateRect(hWnd, NULL, FALSE);
			
			//RedrawWindow(hWnd,NULL,NULL,RDW_ALLCHILDREN | RDW_UPDATENOW);
			break;

		case IDM_RECTANGLE :
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;


		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		{


		hdc = BeginPaint(hWnd, &ps);
		
	
			RECT clientRect;
			GetClientRect(hWnd, &clientRect);
		// TODO: Add any drawing code here...

			int screenWidth = clientRect.right - clientRect.left ;
			int screenHeight =  clientRect.bottom - clientRect.top ;

		HDC backbufferDC = CreateCompatibleDC(hdc);
		HBITMAP backBufferBmp = CreateCompatibleBitmap(hdc,screenWidth, screenHeight );


		SelectObject (backbufferDC, backBufferBmp);

		SelectObject(backbufferDC,drawingPen);
		MoveToEx (backbufferDC,cursorPosition.x,cursorPosition.y,NULL);
		LineTo(backbufferDC,cursorPosition.x,cursorPosition.y);

		if(rectum == true) {
		Ellipse (backbufferDC, cursorPosition.x, cursorPosition.y, 100,500);
		}
		BitBlt(hdc, 0,0,screenWidth, screenHeight, backbufferDC,0,0, SRCCOPY);

		DeleteObject(backBufferBmp);
		DeleteDC (backbufferDC);
		//	Rectangle(hdc,10,200,300,40);

		EndPaint(hWnd, &ps);
		}
		break;
	case WM_LBUTTONDOWN:

		
		break;

	case WM_MOUSEMOVE:
		{
			cursorPosition.x = LOWORD(lParam);
			cursorPosition.y = HIWORD(lParam);
			RECT clientRect;
			GetClientRect(hWnd, &clientRect);
			InvalidateRect(hWnd,&clientRect, false);
		}
		break;

	case WM_CREATE:
		{
			COLORREF blue = 0x00FF0000;
			COLORREF black = 0x0;
			drawingPen = CreatePen(PS_DASHDOTDOT,10, neutral);

		//	drawingBrush = CreateSolidBrush (black);
		}
		break;


	case WM_DESTROY:

		DeleteObject(drawingPen);
		DeleteObject(drawingBrush);
		
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}
