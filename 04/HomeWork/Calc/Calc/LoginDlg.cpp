// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Calc.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LOGIN_DLG, pParent)
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
	ON_EN_CHANGE(IDC_STATUS, &CLoginDlg::OnEnChangeStatus)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CLoginDlg ��Ϣ�������


void CLoginDlg::OnBnClickedOk()
{
	CString szName, szPass;
	GetDlgItemText(IDC_NAME, szName);
	GetDlgItemText(IDC_PASSWD, szPass);

	if (szName != "admin" || szPass != "123456")
	{
		AfxMessageBox(L"�û�����������������������룡");
		return;
	}

	CDialogEx::OnOK();
}


void CLoginDlg::OnEnChangeStatus()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�
	CString szName;
	GetDlgItemText(IDC_NAME, szName);
	SetDlgItemText(IDC_STATUS, szName);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	CTime time = CTime::GetCurrentTime();
	CString str;
	str.Format(_T("%02d��%02d��%02d�� %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
	SetDlgItemText(IDC_STATIC3, str);
	SetTimer(1, 1000, NULL);	//���ö�ʱ��1 ÿ��1���н�һ���ж�


	return TRUE; 
}


void CLoginDlg::OnTimer(UINT_PTR nIDEvent)		//��ʱ
{
	CTime time = CTime::GetCurrentTime();
	CString str;
	str.Format(_T("%02d��%02d��%02d�� %02d:%02d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute(), time.GetSecond());
	SetDlgItemText(IDC_STATIC3, str);
	CDialogEx::OnTimer(nIDEvent);
}
