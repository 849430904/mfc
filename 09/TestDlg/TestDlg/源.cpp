#include <windows.h>
#include "resource.h"
#include <tchar.h>
//hInstance:��Դ�ܹ�


//��Ϣ�ص�����
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
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
			SendMessage(hwndDlg, WM_CLOSE, 0, 0);
			return TRUE;

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