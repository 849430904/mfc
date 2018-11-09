
// ModalDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Modal.h"
#include "ModalDlg.h"
#include "afxdialogex.h"


#include "ChatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CModalDlg �Ի���



CModalDlg::CModalDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MODAL_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CModalDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CModalDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_CHAT, &CModalDlg::OnBnClickedChat)
END_MESSAGE_MAP()


// CModalDlg ��Ϣ�������

BOOL CModalDlg::OnInitDialog()
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

void CModalDlg::OnPaint()
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
HCURSOR CModalDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CModalDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnOK();
}


void CModalDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnCancel();
}


void CModalDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	if(MessageBox(_T("ȷ��Ҫ�˳���"),_T("��ܰ��ʾ"),MB_YESNO) == IDYES)
		EndDialog(IDCANCEL);
	//CDialogEx::OnClose();
}


//CChatDlg dlg;
//void CModalDlg::OnBnClickedChat()
//{//����ģʽ
//
//	//dlg.DoModal();	//ģʽ�Ի��򵯳�
//
//	if (!dlg.m_hWnd)	//�ж��Ƿ��ظ�����
//	{
//		dlg.Create(IDD_CHAT_DLG); //������ģʽ�Ի���
//	}
//	dlg.ShowWindow(SW_SHOW);
//
//}

void CModalDlg::OnBnClickedChat()
{//����ģʽ
	CChatDlg *pdlg = new CChatDlg;
	pdlg->Create(IDD_CHAT_DLG, CWnd::GetDesktopWindow());
	//pdlg->ShowWindow(SW_SHOW);

}
