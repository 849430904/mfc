#include <windows.h>
#include <stdio.h>
#include "resource.h"


//hInstance:��Դ�ܹ�

//�Զ����һ����ȡС���ĺ����������Ĭ�ϲ��� ��ͨ��atofʵ�ֽ�����ת��Ϊ��������
double GetDlgItemDouble(HWND hwnd, UINT nID)
{
	char s[256];
	GetDlgItemText(hwnd, nID, s, sizeof(s));
		
	return  atof(s); //���ַ���ת���ɸ�����
}
// ͨ��sprintf()ʵ�ֽ���������ת��Ϊ���� 
void SetDlgItemDouble(HWND hwnd, UINT nID, double db)
{
	char s[256];
	sprintf(s,"%.2lf", db);
	SetDlgItemText(hwnd, nID, s);
}
//���ھ��к���
void OnInitDialog(HWND hwndDlg)
{
	RECT rect;
	GetWindowRect(hwndDlg, &rect);	//��ȡָ�����ڵı߽���ε�ά�����������£�
	int cx = GetSystemMetrics(SM_CXFULLSCREEN);	//��ȡȫ�����ڵĿ�ȵ�λΪ����
	int cy = GetSystemMetrics(SM_CYFULLSCREEN);	// ע��SM_CYSCREEN��FULLSCREEN����Ļ���ǲ�ͬ�� 
	//��Ļ�� ��cx - ���ڿ�� ��/2

	int x = (cx - rect.right) / 2;
	int y = (cy - rect.bottom) / 2;
	MoveWindow(hwndDlg, x, y, rect.right, rect.bottom, FALSE);

}

void OnCalc(HWND hwndDlg)
{
	//OnCalc(hwndDlg);
	//+
	//����һ��ϵͳ�Ľṹ�壬 ���� SIZE , RECTL
	POINT pt;
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
		nResult = nLeft / nRight;
		SetDlgItemDouble(hwndDlg, IDC_RESTUL4, nResult);
	}
	else
		SetDlgItemText(hwndDlg, IDC_RESTUL4, "��������Ϊ0");
}
// ��¼�жϺ���
void OnLogin(HWND hwndDlg)
{
	char sName[32], sPass[32];
	GetDlgItemText(hwndDlg, IDC_NAME, sName, sizeof(sName));
	GetDlgItemText(hwndDlg, IDC_PASSWD, sPass, sizeof(sPass));

	if (strcmp(sName, "admin") || strcmp(sPass, "123456"))
	{
		MessageBox(hwndDlg, "�û����������������������", "����", MB_OK);
		return ;
	}
	
	EndDialog(hwndDlg, IDOK);
	
}

//��¼����ص�����
INT_PTR CALLBACK logProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{

	case WM_SETCURSOR:	//�ƶ���굽��Ӧλ�� �������ʾ
		if ((HWND)wParam == GetDlgItem(hwndDlg, IDC_NAME))
			SetDlgItemText(hwndDlg, IDC_STATUS, "���ڴ˴������˺�");
		if ((HWND)wParam == GetDlgItem(hwndDlg, IDC_PASSWD))
			SetDlgItemText(hwndDlg, IDC_STATUS, "���ڴ˴���������");
		return TRUE;
	case WM_INITDIALOG:
		OnInitDialog(hwndDlg);
	case WM_COMMAND:
		if (LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hwndDlg, IDCANCEL);
			return TRUE;
		}
		if (LOWORD(wParam) == IDOK)
		{

			OnLogin(hwndDlg);
			return TRUE;
		}
	default:
		break;
	}
	return FALSE;
}
//��������Ϣ�ص�����
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:	//�Ի����ʼ������
	{
		OnInitDialog(hwndDlg);
		return TRUE;
	}
	case WM_COMMAND:	//������Ϣ
		if (LOWORD(wParam) == IDOK)
		{
			OnCalc(hwndDlg);
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

	if(DialogBox(hInstance, (LPCTSTR) IDD_LOGIN_DLG, NULL, logProc) == IDCANCEL)
		return 0;
		
	DialogBox(hInstance, (LPCTSTR) IDD_MAIN_DLG, NULL, DialogProc);
	return 0;
}