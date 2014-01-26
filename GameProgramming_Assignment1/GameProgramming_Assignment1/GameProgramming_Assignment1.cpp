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
HPEN finalPen;
POINT End;
POINT cursorPosition;
UINT color = NULL;
UINT easteregg =  NULL;

POINT final;

HDC backbufferDC;
HBITMAP backbufferBitmap;
COLORREF currentPenColour;
UINT brushtype = NULL;
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
	wcex.hCursor		= LoadCursor(NULL, IDC_CROSS);
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


	PAINTSTRUCT ps;
	HDC hdc;
	COLORREF  neutral = RGB (0,0,255); 
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

			/*****************************************************************************************
			*****************************************************************************************
			*****************************************************************************************
			Switch case for the color drop menu for color BLUE
			Returns : 1-3

			*****************************************************************************************
			*****************************************************************************************
			*****************************************************************************************/

		case IDM_BLUE:
			{
				COLORREF blue =RGB (0,0,255); 

				drawingPen = CreatePen(PS_ENDCAP_SQUARE,10, blue);
				switch (color) {

				case 1: 

					drawingPen = CreatePen(PS_ENDCAP_SQUARE,5, blue);
					return 1;
					break;
				case 2:

					drawingPen = CreatePen(PS_ENDCAP_SQUARE,15, blue);
					return 2;
					break;
				case 3:

					drawingPen = CreatePen(PS_ENDCAP_SQUARE,70, blue);
					return 3;
					break;
				default: 
					return 2;
					break;


				}
			}
			break;

			/*****************************************************************************************
			*****************************************************************************************
			*****************************************************************************************
			Switch case for the color drop menu for color PURPLE
			Returns : 1-3

			*****************************************************************************************
			*****************************************************************************************
			*****************************************************************************************/

		case IDM_PURPLE:
			{
				COLORREF purple = RGB (204,0,204);

				drawingPen = CreatePen(PS_ENDCAP_SQUARE,10, purple);
				switch (color) {
				case 1: 
					drawingPen = CreatePen(PS_ENDCAP_SQUARE,5, purple);
					return 1;
					break;
				case 2:
					drawingPen = CreatePen(PS_ENDCAP_SQUARE,15, purple);
					return 2;
					break;
				case 3:
					drawingPen = CreatePen(PS_ENDCAP_SQUARE,70, purple);
					return 3;
					break;
				default: 
					return 2;
					break;


				}
			}
			
			break;


			/*****************************************************************************************
			*****************************************************************************************
			*****************************************************************************************
			Switch case for the color drop menu for color GREEN
			Returns : 1-3

			*****************************************************************************************
			*****************************************************************************************
			*****************************************************************************************/


		case IDM_GREEN:
			{
				COLORREF green = RGB (0,255,0);
				drawingBrush = CreateSolidBrush (green);
				drawingPen = CreatePen(PS_ENDCAP_SQUARE,10, green);
				switch (color) {

				case 1: 

					drawingPen = CreatePen(PS_ENDCAP_SQUARE,5, green);
					return 1;
					break;
				case 2:

					drawingPen = CreatePen(PS_ENDCAP_SQUARE,15, green);
					return 2;
					break;
				case 3:

					drawingPen = CreatePen(PS_ENDCAP_SQUARE,70, green);
					return 3;
					break;
				default: 
					return 2;
					break;


				}

			}
			break;

			/*****************************************************************************************
			*****************************************************************************************
			*****************************************************************************************
			Switch case for the color drop menu for color RED
			Returns : 1-3

			*****************************************************************************************
			*****************************************************************************************
			*****************************************************************************************/

		case IDM_RED:
			{
				COLORREF red = RGB (255,0,0); //creates the color reference to RGB red
				drawingPen = CreatePen(PS_ENDCAP_SQUARE,10, red); //creates and initializes the drawing pen (by default)
				switch (color) {

				case 1: //small
					drawingPen = CreatePen(PS_ENDCAP_SQUARE,5, red);
					return 1;//return unsigned int 1 for size
					break;
				case 2: //medium

					drawingPen = CreatePen(PS_ENDCAP_SQUARE,15, red);
					return 2;//return unsigned int 2 for size
					break;
				case 3: //large

					drawingPen = CreatePen(PS_ENDCAP_SQUARE,70, red);
					return 3; //return unsigned int 3 for size
					break;
				default: 
					return 2; //return default size...2
					break;
				}

			}
			break;
		case IDM_PEN:
			{
			brushtype = 1;
			}
			break;

		case IDM_ELLIPSE:
			{
				brushtype = 2;
			}
			break;

		case IDM_RECTANGLE :
			brushtype = 3;
			break;


		case IDM_SMALL:
			color = 1;
			easteregg+= color;
			break;
		case IDM_MEDIUM:
			color = 2;
			if (easteregg == 4) {
				DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX1), hWnd, About);
				easteregg = 0;
			}
			break;
		case IDM_LARGE :
			color = 3;
			easteregg+= color;
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
			// TODO: Add any drawing code here...
			switch (brushtype) {

				/******************************
				*******************************
				*When User selects Pen Tool****
				******************************/
			case 1: 
				{
					RECT clientArea;
					GetClientRect(hWnd, &clientArea);
					int screenWidth = clientArea.right - clientArea.left;
					int screenHeight = clientArea.bottom - clientArea.top;

					backbufferDC = CreateCompatibleDC(hdc);
					backbufferBitmap = CreateCompatibleBitmap(hdc, screenWidth, screenHeight);
					SelectObject(backbufferDC, backbufferBitmap);

					HGDIOBJ previousPen = SelectObject(backbufferDC, drawingPen);
					SelectObject(backbufferDC, drawingBrush);

					MoveToEx(backbufferDC, cursorPosition.x, cursorPosition.y, NULL);
					LineTo(backbufferDC, End.x, End.y);

					SelectObject(backbufferDC, previousPen);
					BitBlt(hdc, 0, 0, screenWidth, screenHeight, backbufferDC, 0, 0, SRCCOPY);
				}
				break;

				/**********************************
				***********************************
				*When User selects Ellipse Tool****
				***********************************/
			case 2:
				{
					RECT clientArea;
					GetClientRect(hWnd, &clientArea);
					int screenWidth = clientArea.right - clientArea.left;
					int screenHeight = clientArea.bottom - clientArea.top;

					backbufferDC = CreateCompatibleDC(hdc);
					backbufferBitmap = CreateCompatibleBitmap(hdc, screenWidth, screenHeight);

					SelectObject(backbufferDC, backbufferBitmap);
					HGDIOBJ previousPen = SelectObject(backbufferDC, drawingPen);
					SelectObject(backbufferDC, drawingBrush);

					Ellipse(backbufferDC,cursorPosition.x,cursorPosition.y,End.x,End.y);
					SelectObject(backbufferDC, previousPen);

					BitBlt(hdc, 0, 0, screenWidth, screenHeight, backbufferDC, 0, 0, SRCCOPY);
				}
				break;


				/************************************
				*************************************
				*When User selects Rectangle Tool****
				*************************************/
			case 3:
				{

					RECT clientArea;
					GetClientRect(hWnd, &clientArea);
					int screenWidth = clientArea.right - clientArea.left;
					int screenHeight = clientArea.bottom - clientArea.top;
					
					backbufferDC = CreateCompatibleDC(hdc);
					backbufferBitmap = CreateCompatibleBitmap(hdc, screenWidth, screenHeight);
					SelectObject(backbufferDC, backbufferBitmap);
					HGDIOBJ previousPen = SelectObject(backbufferDC, drawingPen);
					SelectObject(backbufferDC, drawingBrush);

					Rectangle(backbufferDC,cursorPosition.x,cursorPosition.y,End.x,End.y);
			
					
					SelectObject(backbufferDC, previousPen);
					BitBlt(hdc, 0, 0, screenWidth, screenHeight, backbufferDC, 0, 0, SRCCOPY);
				}
				break;


				/**********************************
				***********************************
				***Pen Tool is Default on Launch****
				***********************************/
			default:
				{
					RECT clientArea;
					GetClientRect(hWnd, &clientArea);
					int screenWidth = clientArea.right - clientArea.left;
					int screenHeight = clientArea.bottom - clientArea.top;
					
					backbufferDC = CreateCompatibleDC(hdc);
					backbufferBitmap = CreateCompatibleBitmap(hdc, screenWidth, screenHeight);
					
					SelectObject(backbufferDC, backbufferBitmap);
					
					HGDIOBJ previousPen = SelectObject(backbufferDC, drawingPen);
					SelectObject(backbufferDC, drawingBrush);
					
					MoveToEx(backbufferDC, cursorPosition.x, cursorPosition.y, NULL);
					LineTo(backbufferDC, End.x, End.y);
					
					SelectObject(backbufferDC, previousPen);
					BitBlt(hdc, 0, 0, screenWidth, screenHeight, backbufferDC, 0, 0, SRCCOPY);
				}
				break;
			}


			EndPaint(hWnd, &ps);

		}
		break;


	case WM_LBUTTONDOWN:
		{

			switch (brushtype) {

			case 1:  //pen

				{
					cursorPosition.x = LOWORD(lParam);
					cursorPosition.y = HIWORD(lParam);

					End.x = LOWORD(lParam);
					End.y = HIWORD(lParam);
					InvalidateRect(hWnd, NULL, false);

				}
				break;

			case 2: //ellipse
				{
					cursorPosition.x = LOWORD(lParam);
					cursorPosition.y = HIWORD(lParam);

					End.x = LOWORD(lParam);
					End.y = HIWORD(lParam);
		
				}
				break;

			case 3: //rectangle
				break;
			default :
					cursorPosition.x = LOWORD(lParam);
					cursorPosition.y = HIWORD(lParam);

					End.x = LOWORD(lParam);
					End.y = HIWORD(lParam);
					InvalidateRect(hWnd, NULL, false);

				break;
			}

		}
		break;



	case WM_LBUTTONUP:
		{
			/*hdc = BeginPaint(hWnd, &ps);
			SelectObject(hdc,finalPen);
			MoveToEx(hdc, 300, 50, NULL);
			LineTo(hdc, 500, 300); */
		}

		break;

	case WM_MOUSEMOVE:
		{
			if(wParam == MK_LBUTTON)
			{
				End.x = LOWORD(lParam);
				End.y = HIWORD(lParam);
				InvalidateRect(hWnd, NULL, false);

			}
		}
		break;

	case WM_CREATE:
		{
			drawingPen = CreatePen(PS_ENDCAP_SQUARE,10, neutral);
			finalPen=CreatePen(PS_ENDCAP_FLAT,20,neutral);
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

