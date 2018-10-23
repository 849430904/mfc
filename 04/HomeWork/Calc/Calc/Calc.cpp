
// Calc.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Calc.h"
#include "CalcDlg.h"
#include "LoginDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCalcApp

BEGIN_MESSAGE_MAP(CCalcApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CCalcApp ����

CCalcApp::CCalcApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CCalcApp ����

CCalcApp theApp;


// CCalcApp ��ʼ��
// һ�������ؼ�����
BOOL CCalcApp::InitInstance()	//winmain()�൱��
{
	CLoginDlg logdlg;
	if (IDCANCEL == logdlg.DoModal())
		return FALSE;
	CCalcDlg dlg;
	INT_PTR nResponse = dlg.DoModal();
	return FALSE;
}

