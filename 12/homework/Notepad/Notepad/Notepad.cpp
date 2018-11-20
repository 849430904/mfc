
// Notepad.cpp : ����Ӧ�ó��������Ϊ��
//

#include "stdafx.h"
#include "Notepad.h"
#include "NotepadDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNotepadApp

BEGIN_MESSAGE_MAP(CNotepadApp, CWinApp)
	ON_COMMAND(ID_HELP, &CWinApp::OnHelp)
END_MESSAGE_MAP()


// CNotepadApp ����

CNotepadApp::CNotepadApp()
{
	// ֧����������������
	m_dwRestartManagerSupportFlags = AFX_RESTART_MANAGER_SUPPORT_RESTART;

	// TODO: �ڴ˴���ӹ�����룬
	// ��������Ҫ�ĳ�ʼ�������� InitInstance ��
}


// Ψһ��һ�� CNotepadApp ����

CNotepadApp theApp;


// CNotepadApp ��ʼ��

BOOL CNotepadApp::InitInstance()
{
	//�������ļ����浽ע�����
	SetRegistryKey(_T("NotePad"));

	// win10 ���޷�д��ini ʱֻ������� ���������ļ������·��
	free((LPTSTR)m_pszProfileName);
	m_pszProfileName = (LPCTSTR)malloc(256);
	sizeof(*m_pszProfileName);
	_tcscpy_s((LPTSTR)m_pszProfileName,128, _T("./notepad.ini"));


	CNotepadDlg dlg;
	m_pMainWnd = &dlg;
	INT_PTR nResponse = dlg.DoModal();	//EndDialog(n) �� n ��ʲôDomodal�ʹ���ʲô ���ڽ�����ж�

	return FALSE;
}



int CNotepadApp::ExitInstance()
{
	// TODO: �ڴ����ר�ô����/����û���

	return CWinApp::ExitInstance();
}
