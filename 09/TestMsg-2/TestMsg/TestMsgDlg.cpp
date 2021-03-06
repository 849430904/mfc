
// TestMsgDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "TestMsg.h"
#include "TestMsgDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTestMsgDlg 对话框



CTestMsgDlg::CTestMsgDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TESTMSG_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTestMsgDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CTestMsgDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CREATE()
//	ON_WM_SYSCOMMAND()
	ON_WM_CLOSE()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CTestMsgDlg 消息处理程序

BOOL CTestMsgDlg::OnInitDialog()
{//对话框专用回调
	CListCtrl *pList = (CListCtrl*)GetDlgItem(IDC_LIST);
	pList->InsertColumn(0, _T("工号"), LVCFMT_LEFT, 100);
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTestMsgDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTestMsgDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



int CTestMsgDlg::OnCreate(LPCREATESTRUCT lpCreateStruct)
{//所有窗口通用的初始化消息，子窗口和控件还没出现,可以对主窗口进行操作
	if (CDialogEx::OnCreate(lpCreateStruct) == -1)
		return -1;


	return 0;
}


void CTestMsgDlg::PreSubclassWindow()
{//可以对主窗口进行操作


	CDialogEx::PreSubclassWindow();
}


//void CTestMsgDlg::OnSysCommand(UINT nID, LPARAM lParam)
//{
//
//	CDialogEx::OnSysCommand(nID, lParam);
//}
//if (nID == SC_CLOSE)
//{
//	ShowWindow(SW_MINIMIZE);
//	return;
//}

void CTestMsgDlg::OnClose()
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	//ShowWindow(SW_MINIMIZE);
	CDialogEx::OnClose();
}


void CTestMsgDlg::OnCancel()
{
	// TODO: 在此添加专用代码和/或调用基类
	//ShowWindow(SW_MINIMIZE);
	CDialogEx::OnCancel();
}


BOOL CTestMsgDlg::DestroyWindow()
{
	// TODO: 在此添加专用代码和/或调用基类
	AfxMessageBox(_T("bey"));
	return CDialogEx::DestroyWindow();
}


void CTestMsgDlg::OnDestroy()
{
	AfxMessageBox(_T("bey"));
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
}
