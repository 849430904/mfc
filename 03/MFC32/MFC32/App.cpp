#include "App.h"
#include "resource.h"
#include <afxdialogex.h>
CApp theApp;

BOOL CApp::InitInstance()
{//��Ϊ��������
	//MessageBox(NULL, "�ҵ�ģ��MFC���򿪷�", "��ܰ��ʾ��", MB_OK);
	
	//DialogBox()
	CDialogEx dlg(IDD_MAIN_DLG);
	dlg.DoModal();	//MFC�����Ի���ĺ���


	return 0;
}

CApp::CApp()
{
}

CApp::~CApp()
{
}
