#include <windows.h>
#include <stdio.h>
#include "resource.h"

//hInstance:��Դ�ܹ�
double GetDlgItemDouble(HWND hwnd, UINT nID)
{
	char s[256];
	GetDlgItemText(hwnd, nID, s, sizeof(s));
		
	return  atof(s); //���ַ���ת���ɸ�����
}

void SetDlgItemDouble(HWND hwnd, UINT nID, double db)
{
	char s[256];
	sprintf(s,"%.2lf", db);
	SetDlgItemText(hwnd, nID, s);
}

//��Ϣ�ص�����
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case :
	case WM_COMMAND:	//������Ϣ
		if (LOWORD(wParam) == IDOK)
		{
			//+
			double nLeft = GetDlgItemDouble(hwndDlg, IDC_LEFT1);
			double nRight = GetDlgItemDouble(hwndDlg, IDC_RIGHT1);
			double nResult = nRight + nLeft;
			SetDlgItemDouble(hwndDlg, IDC_RESTUL1, nResult);
			//-
			nLeft = GetDlgItemDouble(hwndDlg, IDC_LEFT2);
			nRight = GetDlgItemDouble(hwndDlg, IDC_RIGHT2);
			nResult = nRight - nLeft;
			SetDlgItemDouble(hwndDlg, IDC_RESTUL2, nResult);
			//*
			nLeft = GetDlgItemDouble(hwndDlg, IDC_LEFT3);
			nRight = GetDlgItemDouble(hwndDlg, IDC_RIGHT3);
			nResult = nRight * nLeft;
			SetDlgItemDouble(hwndDlg, IDC_RESTUL3, nResult);
			// /
			nLeft = GetDlgItemDouble(hwndDlg, IDC_LEFT4);
			nRight = GetDlgItemDouble(hwndDlg, IDC_RIGHT4);
			if (nRight != 0)
			{
				nResult = nLeft / nRight  ;
				SetDlgItemDouble(hwndDlg, IDC_RESTUL4, nResult);
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