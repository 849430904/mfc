// ChatDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Modal.h"
#include "ChatDlg.h"
#include "afxdialogex.h"


// CChatDlg �Ի���

IMPLEMENT_DYNAMIC(CChatDlg, CDialogEx)

CChatDlg::CChatDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CHAT_DLG, pParent)
{

}

CChatDlg::~CChatDlg()
{
}

void CChatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CChatDlg, CDialogEx)
	ON_BN_CLICKED(IDC_TEST, &CChatDlg::OnBnClickedTest)
END_MESSAGE_MAP()


// CChatDlg ��Ϣ�������


void CChatDlg::OnBnClickedTest()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CWnd *p1 = AfxGetMainWnd();
	CWnd *p2 = theApp.m_pMainWnd;
}
