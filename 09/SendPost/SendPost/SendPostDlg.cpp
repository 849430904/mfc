
// SendPostDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "SendPost.h"
#include "SendPostDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

const int UM_TEST (WM_USER + 100);

// CSendPostDlg �Ի���



CSendPostDlg::CSendPostDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_SENDPOST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSendPostDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSendPostDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_SEND, &CSendPostDlg::OnBnClickedSend)
	ON_BN_CLICKED(IDC_POST, &CSendPostDlg::OnBnClickedPost)
	ON_WM_CLOSE()
	ON_MESSAGE(UM_TEST, &CSendPostDlg::OnUmtest)
END_MESSAGE_MAP()


// CSendPostDlg ��Ϣ�������

BOOL CSendPostDlg::OnInitDialog()
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

void CSendPostDlg::OnPaint()
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
HCURSOR CSendPostDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSendPostDlg::OnBnClickedSend()
{
	LRESULT res = SendMessage(UM_TEST, 1, 2);
}


void CSendPostDlg::OnBnClickedPost()
{
	BOOL a = PostMessage(UM_TEST, 1, 2);
	//BOOL a = PostMessage(WM_CLOSE);
}


void CSendPostDlg::OnClose()
{
	if(AfxMessageBox(_T("ȷ��Ҫ�رգ�"),MB_YESNO | MB_ICONQUESTION) == IDYES)
		CDialogEx::OnClose();
}


afx_msg LRESULT CSendPostDlg::OnUmtest(WPARAM wParam, LPARAM lParam)
{
	return wParam + lParam;
}
