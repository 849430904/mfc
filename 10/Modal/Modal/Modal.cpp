
// Modal.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Modal.h"
#include "ModalDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModalApp

BEGIN_MESSAGE_MAP(CModalApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CModalApp ����

CModalApp::CModalApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CModalApp ����

CModalApp theApp;


// CModalApp ��ʼ��

BOOL CModalApp::InitInstance()
{

	AfxSocketInit();
	AfxInitRichEdit();	//ʹ��richeditʱ������øú�����
	CModalDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();

	return FALSE;
}
