

// explorerDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "explorer.h"
#include "explorerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CexplorerDlg �Ի���



CexplorerDlg::CexplorerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_EXPLORER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CexplorerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CexplorerDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
END_MESSAGE_MAP()


// CexplorerDlg ��Ϣ�������

/*
	��Ϣ�����ļ���������(Ŀ¼���������ļ���)����С���޸����ڵ�
*/

BOOL CexplorerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	/*�����б����*/
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST);
	pList->InsertColumn(0, _T("�ļ���"), 0, 160);
	pList->InsertColumn(1, _T("����"), 0, 120);
	pList->InsertColumn(2, _T("��С"), LVCFMT_RIGHT, 80);
	pList->InsertColumn(3, _T("�޸�����"), 0, 180);


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CexplorerDlg::OnPaint()
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
HCURSOR CexplorerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


LPCTSTR  CexplorerDlg::m_weeks[] =
{
	_T("������"),
	_T("����һ"),
	_T("���ڶ�"),
	_T("������"),
	_T("������"),
	_T("������"),
	_T("������"),
	NULL
};



void CexplorerDlg::OnOK()
{
	CFileFind ff;
	CString szAddr;
	GetDlgItemText(IDC_ADDR, szAddr);
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST);
	/*�������б�*/
	pList->DeleteAllItems();
	
	//��ʾ����ʧ��
	BOOL bff = ff.FindFile(szAddr + _T("\\*.*"));
	int i = 0;
	CString str;

	//ע�� CFileFind ��ÿ�� ��Ҫ��FindNextһ�� ���ұ���֮ǰ��Ҫ���ж���ѭ��
	while (bff)
	{
		bff = ff.FindNextFile();
		// ��Ϊÿ�β��Ҷ������������  �ö��ж�̫�� ���Կ��Ǽ����������� 
		if (ff.IsHidden() || ff.IsDots())
			continue;

			pList->InsertItem(i, ff.GetFileName());
			if (ff.IsDirectory())
				pList->SetItemText(i, 1, _T("�ļ���"));
			else
			{
				//�ҳ��ļ��ĺ�׺��
				str = ff.GetFileName();
				int n = str.ReverseFind(_T('.'));
				if (n > 0)
					pList->SetItemText(i, 1, str.Mid(n+1) + _T(" �ļ�"));

				//�ļ���С �ý�1 �ķ��� ��ʾΪKB			nFileSizeLow ��Ϊ0~4G ֮��Ĵ�С �������4G ����Ҫʹ�ö�Ӧ���㷨nFileSizeHight
				str.Format(_T("%d"), (ff.GetLength() +1023)/1024);
				pList->SetItemText(i, 2, str + _T(" KB"));
			}
			
			FILETIME pTimeStamp;
			ff.GetLastWriteTime(&pTimeStamp);

			COleDateTime time(pTimeStamp);
			str.Format(_T("%d/%d/%d %s %d:%02d"), time.GetYear(), time.GetMonth(), time.GetDay(), m_weeks[time.GetDayOfWeek() - 1] ,time.GetHour(), time.GetMinute());
			pList->SetItemText(i, 3, str);
			i++;
	}

	ff.Close();
}
