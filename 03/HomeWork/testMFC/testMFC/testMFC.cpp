
// testMFC.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "testMFC.h"
#include "testMFCDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestMFCApp

BEGIN_MESSAGE_MAP(CtestMFCApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CtestMFCApp ����

CtestMFCApp::CtestMFCApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CtestMFCApp ����

CtestMFCApp theApp;


// CtestMFCApp ��ʼ��

BOOL CtestMFCApp::InitInstance()
{

	CtestMFCDlg dlg;
	INT_PTR nResponse = dlg.DoModal();
	DWORD dwError = GetLastError();

	return FALSE;
}

