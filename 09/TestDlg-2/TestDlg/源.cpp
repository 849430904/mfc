#include <windows.h>
#include "resource.h"
#include <tchar.h>
//hInstance:��Դ�ܹ�
enum
{
	UM_ADD = WM_USER + 100,
};

//��Ϣ�ص�����
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case UM_ADD:
	{
		return wParam+lParam;
	}
	case WM_CLOSE:
		MessageBox(hwndDlg, _T("�ر�"), _T("��ʾ"), 0);
		return FALSE;//true����ϵͳ���ùر��ˣ� FALSE����ϵͳ�����ر�
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hwndDlg, IDCANCEL);
			return TRUE;
		case IDC_SEND:
			{
				//HWND hWnd = FindWindow(_T("Notepad"), NULL);
				LRESULT res = SendMessage(hwndDlg, UM_ADD, wParam, lParam);
				return TRUE;
			}
		case IDC_POST:
			{			
				HWND hWnd = FindWindow(_T("Notepad"), NULL);
				BOOL a = PostMessage(hWnd, WM_CLOSE, 0, 0);
				return TRUE;
			}

		}
	break;
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{//MessageBox FindWindow
	DialogBox(hInstance, (LPCTSTR) IDD_MAIN_DLG, NULL, DialogProc);
	return 0;
}