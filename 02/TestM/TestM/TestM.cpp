
// TestM.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "TestM.h"
#include "TestMDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMApp

BEGIN_MESSAGE_MAP(CTestMApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CTestMApp ����

CTestMApp::CTestMApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CTestMApp ����

CTestMApp theApp;


// CTestMApp ��ʼ��

BOOL CTestMApp::InitInstance()
{
	CTestMDlg dlg;

	INT_PTR nResponse = dlg.DoModal();

	return FALSE;
}

