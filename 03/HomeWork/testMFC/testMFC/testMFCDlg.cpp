
// testMFCDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "testMFC.h"
#include "testMFCDlg.h"
#include "afxdialogex.h"

#include <stdio.h>


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestMFCDlg �Ի���



CtestMFCDlg::CtestMFCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTMFC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestMFCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CtestMFCDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CtestMFCDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CtestMFCDlg ��Ϣ�������

BOOL CtestMFCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CtestMFCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CtestMFCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//CDialogEx::OnOK();
void CtestMFCDlg::OnBnClickedOk()
{

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	/*c��ʽ  ջ��*/
	//char s[200];
	//GetDlgItemText(IDC_LEFT1, s, sizeof(s));

	/*C++ģʽ  ����*/
	CString str;
	GetDlgItemText(IDC_LEFT1, str);
	double fLeft = atof(str);
	GetDlgItemText(IDC_RIGHT1, str);
	double fRight = atof(str);
	
	/*C����*/

	//char s[200];
	//sprintf_s(s,sizeof(s), "%.2lf", fRight + fLeft);
	//SetDlgItemText(IDC_RESTUL1, s);

	/*C++����*/
	str.Format("%.2lf", fLeft + fRight);
	SetDlgItemText(IDC_RESTUL1, str);

	/* - */
	GetDlgItemText(IDC_LEFT2, str);
	fLeft = atof(str);
	GetDlgItemText(IDC_RIGHT2, str);
	fRight = atof(str);
	str.Format("%.2lf", fLeft - fRight);
	SetDlgItemText(IDC_RESTUL2, str);

	/* * */
	GetDlgItemText(IDC_LEFT3, str);
	fLeft = atof(str);
	GetDlgItemText(IDC_RIGHT3, str);
	fRight = atof(str);
	str.Format("%.2lf", fLeft * fRight);
	SetDlgItemText(IDC_RESTUL3, str);

	/* / */
	GetDlgItemText(IDC_LEFT4, str);
	fLeft = atof(str);
	GetDlgItemText(IDC_RIGHT4, str);
	fRight = atof(str);
	if (fRight == 0)
	{
		SetDlgItemText(IDC_RESTUL4, "����������Ϊ0");
	}
	else
	{
		str.Format("%.2lf", fLeft / fRight);
		SetDlgItemText(IDC_RESTUL4, str);
	}

}
