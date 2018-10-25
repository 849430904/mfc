
// TestTimeDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "TestTime.h"
#include "TestTimeDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestTimeDlg �Ի���



CTestTimeDlg::CTestTimeDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTTIME_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestTimeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestTimeDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_GET_TIME, &CTestTimeDlg::OnBnClickedGetTime)
	ON_BN_CLICKED(IDC_GET_TIME2, &CTestTimeDlg::OnBnClickedGetTime2)
	ON_BN_CLICKED(IDC_MK_TIME, &CTestTimeDlg::OnBnClickedMkTime)
	ON_BN_CLICKED(IDC_MK_TIME2, &CTestTimeDlg::OnBnClickedMkTime2)
	ON_BN_CLICKED(IDC_MK_TIME3, &CTestTimeDlg::OnBnClickedMkTime3)
END_MESSAGE_MAP()


// CTestTimeDlg ��Ϣ�������

BOOL CTestTimeDlg::OnInitDialog()
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

void CTestTimeDlg::OnPaint()
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
HCURSOR CTestTimeDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CTestTimeDlg::OnBnClickedGetTime()
{
	/*
		C���Է�����ȡʱ��
	*/
	time_t tt = time(NULL);
	struct tm tms;
	errno_t nErr = localtime_s(&tms, &tt);
	CString str;
	str.Format(_T("%d��%d��%d�� %d:%d:%d"),tms.tm_year+1900, tms.tm_mon, tms.tm_mday,
		tms.tm_hour, tms.tm_min, tms.tm_sec);
	AfxMessageBox(str);


}


void CTestTimeDlg::OnBnClickedGetTime2()
{
	/*
		C++�෽����ȡʱ��
	*/
	CTime t = CTime::GetCurrentTime();//���ر�ʾ��ǰʱ��� CTime ����
	CString str;
	str.Format(_T("%d��%d��%d�� %d:%d:%d"), t.GetYear(), t.GetMonth(), t.GetDay(),
		t.GetHour(), t.GetMinute(), t.GetSecond());
	AfxMessageBox(str);

}


void CTestTimeDlg::OnBnClickedMkTime()
{
	/*
		C���Է������ʱ��
	*/
	tm tms = { 15, 50, 9, 25, 10 - 1, 2018 - 1900 };
	time_t tt = mktime(&tms);

}


void CTestTimeDlg::OnBnClickedMkTime2()
{
	//CTime t(2015, 10, 25, 9, 56, 55);

	CTime t(GetDlgItemInt(IDC_YEAR), GetDlgItemInt(IDC_MONTH), GetDlgItemInt(IDC_DAY), GetDlgItemInt(IDC_HOUR), GetDlgItemInt(IDC_MIN), GetDlgItemInt(IDC_SEC));

	CString str;
	str.Format(_T("%d��%d��%d�� %d:%d:%d"), t.GetYear(), t.GetMonth(), t.GetDay(),
		t.GetHour(), t.GetMinute(), t.GetSecond());
	AfxMessageBox(str);
	
}


void CTestTimeDlg::OnBnClickedMkTime3()
{
	CMyTime time = CMyTime::GetCurrentTime();
	CMyTime t(GetDlgItemInt(IDC_YEAR), GetDlgItemInt(IDC_MONTH), GetDlgItemInt(IDC_DAY), GetDlgItemInt(IDC_HOUR), GetDlgItemInt(IDC_MIN), GetDlgItemInt(IDC_SEC));

	CString str;
	str.Format(_T("%d��%d��%d�� %d:%d:%d"), t.GetYear(), t.GetMonth(), t.GetDay(),
		t.GetHour(), t.GetMinute(), t.GetSecond());
	AfxMessageBox(str);
}
