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
			//+
			int nLeft = GetDlgItemInt(hwndDlg, IDC_LEFT1, NULL, TRUE);
			int nRight = GetDlgItemInt(hwndDlg, IDC_RIGHT1, NULL, TRUE);
			int nResult = nRight + nLeft;
			SetDlgItemInt(hwndDlg, IDC_RESTUL1, nResult, TRUE);
			//-
			nLeft = GetDlgItemInt(hwndDlg, IDC_LEFT2, NULL, TRUE);
			nRight = GetDlgItemInt(hwndDlg, IDC_RIGHT2, NULL, TRUE);
			nResult = nRight - nLeft;
			SetDlgItemInt(hwndDlg, IDC_RESTUL2, nResult, TRUE);
			//*
			nLeft = GetDlgItemInt(hwndDlg, IDC_LEFT3, NULL, TRUE);
			nRight = GetDlgItemInt(hwndDlg, IDC_RIGHT3, NULL, TRUE);
			nResult = nRight * nLeft;
			SetDlgItemInt(hwndDlg, IDC_RESTUL3, nResult, TRUE);
			// /
			nLeft = GetDlgItemInt(hwndDlg, IDC_LEFT4, NULL, TRUE);
			nRight = GetDlgItemInt(hwndDlg, IDC_RIGHT4, NULL, TRUE);
			if (nRight != 0)
			{
				nResult = nRight / nLeft;
				SetDlgItemInt(hwndDlg, IDC_RESTUL4, nResult, TRUE);
			}
			else
				SetDlgItemText(hwndDlg, IDC_RESTUL4, "��������Ϊ0");


			return TRUE;
		}
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hwndDlg, IDCANCEL);
			return TRUE;
			// MessageBox(hwndDlg, "������Cancel", "��ʱ", 0);
		}
		if (LOWORD(wParam) == ID_EXIT)
		{
			EndDialog(hwndDlg, ID_EXIT);
			return TRUE;
		}

		break;
	}
	return FALSE;	//FALSE����ȱʡ����
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{//MessageBox FindWindow
	DialogBox(hInstance, (LPCTSTR) IDD_MAIN_DLG, NULL, DialogProc);
	return 0;
}