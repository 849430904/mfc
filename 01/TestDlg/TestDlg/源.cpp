#include <windows.h>
#include "resource.h"
//hInstance:��Դ�ܹ�


//��Ϣ�ص�����
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:	//������Ϣ
		if (LOWORD(wParam) == IDOK)
		{
			int nLeft = GetDlgItemInt(hwndDlg, IDC_LEFT, NULL, TRUE);
			int nRight = GetDlgItemInt(hwndDlg, IDC_RIGHT, NULL, TRUE);
			int nResult = nRight + nLeft;
			SetDlgItemInt(hwndDlg, IDC_RESTUL, nResult, TRUE);
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hwndDlg, IDCANCEL);
			// MessageBox(hwndDlg, "������Cancel", "��ʱ", 0);
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