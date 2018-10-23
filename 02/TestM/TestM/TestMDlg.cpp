
// TestMDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestM.h"
#include "TestMDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMDlg �Ի���



CTestMDlg::CTestMDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}
// ��Ϣӳ����ƣ� ��Ϣ������Ͷ�Ӧ�Ĵ���ID������һ����Ա������
/* ******************************** */
BEGIN_MESSAGE_MAP(CTestMDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADD, &CTestMDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_DEC, &CTestMDlg::OnBnClickedDec)
END_MESSAGE_MAP()


// CTestMDlg ��Ϣ�������

BOOL CTestMDlg::OnInitDialog()
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

void CTestMDlg::OnPaint()
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
HCURSOR CTestMDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestMDlg::OnBnClickedAdd()
{
	int nLeft = GetDlgItemInt(IDC_LEFT1);
	int nRight = GetDlgItemInt(IDC_RIGHT1);

	SetDlgItemInt(IDC_RESULT1, nLeft + nRight);
	// TODO: �ڴ���ӿؼ�֪ͨ����������

}


void CTestMDlg::OnBnClickedDec()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
