#include <Windows.h>
#include<stdio.h>
#include "resource.h"
#define _CRT_SECURE_NO_WARNINGS

INT_PTR WINAPI msgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:		//�Ի�����ʾ֮ǰ������׼������
		SetWindowText(hWnd, "��Ϣ����");
		//MessageBox(hWnd, "����", "����", MB_OK);
		break;
	case WM_CLOSE:	//ϵͳ�ر���Ϣ
		EndDialog(hWnd, IDCANCEL);
		//MessageBox(hWnd, "ϵͳ�ر�", "����", MB_OK);
		break;
	case WM_LBUTTONDOWN:	//�������
	{	//MessageBox(hWnd, "�������","����",MB_OK);
		short x = LOWORD(lParam);
		short y = HIWORD(lParam);
		char s[256];
		sprintf(s, "��������: x=%d, y=%d", x, y);
		SetWindowText(hWnd,s);
	}
		break;
	case WM_RBUTTONDOWN:		//����Ҽ����
	{	//MessageBox(hWnd, "�Ҽ�����","����", MB_OK);
		short x = LOWORD(lParam);
		short y = HIWORD(lParam);
		char s[256];
		sprintf(s, "�Ҽ������: x=%d, y=%d", x, y);
		SetWindowText(hWnd, s);
	}
		break;
	case WM_MOUSEMOVE:	//����ƶ�	
	{
		//lParam �ĵ�λ���x���꣬��λ���y����
		short x = LOWORD(lParam);
		short y = HIWORD(lParam);
		char s[256];
		sprintf(s, "����ƶ�: x=%d, y=%d wParam = %d", x, y, wParam);

		if (wParam == MK_LBUTTON)	//�ж��Ƿ������
			strcat(s, "�������");
		if (wParam == MK_RBUTTON)	//�ж��Ƿ����Ҽ�
			strcat(s, "�����Ҽ�");
		if (wParam & MK_MBUTTON)	//�ж��Ƿ����м�
			strcat(s, "�����м�");	

		SetWindowText(hWnd, s);
	}
		break;
	}

	return FALSE;
}

int WINAPI WinMain(HINSTANCE hIstance, HINSTANCE hPrev, LPSTR lpCmd, int nShow)
{

	DialogBox(hIstance, (LPCSTR)IDD_MSG_DLG, NULL, msgProc);

	return 0;
}