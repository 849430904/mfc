
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
	pList->InsertColumn(2, _T("��С"), 0, 120);
	pList->InsertColumn(3, _T("�޸�����"), 0, 120);


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


#include <io.h>
#include <AtlBase.h>
void CexplorerDlg::OnOK()
{
	CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST);
	/*ֱ��ʹ�ÿ��ַ��� �����Բ��ý����ַ�����ת��*/
	struct _wfinddata_t c_file;
	intptr_t hFile;
	CString szAddr;
	GetDlgItemText(IDC_ADDR, szAddr);

	/*�������б�*/
	pList->DeleteAllItems();
	
	if ((hFile = _wfindfirst(szAddr + _T("*.*"), &c_file)) == -1L)
		return;
	int i = 0;
	USES_CONVERSION;// ����ʹ��_bstr_t �����ת��
	// ��� | , �ж�ʹ�� if(c_file.attrib & _A_HIDDEN) , ɾ������ c_file.attrib =~_A_HIDDEN
	CString str;
	do
	{
		if (!(c_file.attrib & _A_HIDDEN))
		{
			pList->InsertItem(i, c_file.name);
			if (c_file.attrib & _A_SUBDIR)
				pList->SetItemText(i, 1, _T("�ļ���"));
			else
			{
				//�ҳ��ļ��ĺ�׺��
				str = c_file.name;
				int n = str.ReverseFind(_T('.'));
				if (n > 0)
					pList->SetItemText(i, 1, str.Mid(n+1) + _T(" �ļ�"));

				//�ļ���С �ý�1 �ķ��� ��ʾΪKB
				str.Format(_T("%d"), (c_file.size+1023)/1024);
				pList->SetItemText(i, 2, str + _T(" KB"));

				COleDateTime time(c_file.time_write);
				str.Format(_T("%d/%d/%d %d:%d"), time.GetYear(), time.GetMonth(), time.GetDay(), time.GetHour(), time.GetMinute());
				pList->SetItemText(i, 3, str);

			}
			i++;
		}
			

		
	} while (_wfindnext(hFile, &c_file) == 0);


	/*խ�ַ�����ʹ�� ע��ȡ���ļ�����ʱ��Ҫ�����ַ�����ת��*/
	//CListCtrl *pList = (CListCtrl *)GetDlgItem(IDC_LIST);
	//struct _finddata_t c_file;
	//intptr_t hFile;
	//if ((hFile = _findfirst("C:\\*.*", &c_file)) == -1L)
	//	return;
	//int i = 0;
	//USES_CONVERSION;// ����ʹ��_bstr_t �����ת��
	//// ��� | , �ж�ʹ�� if(c_file.attrib & _A_HIDDEN) , ɾ������ c_file.attrib =~_A_HIDDEN
	//do
	//{
	//	if(!(c_file.attrib & _A_HIDDEN))
	//		pList->InsertItem(i++, A2T(c_file.name));

	//	
	//} while (_findnext(hFile, &c_file) == 0);

	//�رղ��Ҿ��
	_findclose(hFile);

}
