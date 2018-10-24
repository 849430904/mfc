
// WorkDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Work.h"
#include "WorkDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CWorkDlg �Ի���



CWorkDlg::CWorkDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CWorkDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_bModified = FALSE;
}

void CWorkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CWorkDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CWorkDlg::OnBnClickedCancel)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST1, &CWorkDlg::OnLvnItemchangedList1)

	//��Ϣ��ID�� ������
	ON_BN_CLICKED(IDC_btnAdd, &CWorkDlg::OnBnClickedbtnadd)
	ON_BN_CLICKED(IDC_btnDel, &CWorkDlg::OnBnClickedbtndel)
	ON_BN_CLICKED(IDC_btnLoad, &CWorkDlg::OnBnClickedbtnload)
	ON_BN_CLICKED(IDC_btnSave, &CWorkDlg::OnBnClickedbtnsave)
	ON_BN_CLICKED(IDC_btnModify, &CWorkDlg::OnBnClickedbtnmodify)
END_MESSAGE_MAP()


// CWorkDlg ��Ϣ�������

BOOL CWorkDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//�򿪽���֮ǰ�ĳ�ʼ��

	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	/*	һ�·���Ϊ�󶨵���Ӧ��list�����ϡ�
		CListCtrl	list;
		list.InsertColumn(0, _T("����"),LVCFMT_LEFT,100);
	*/

	CListCtrl *pList = (CListCtrl *) GetDlgItem(IDC_LIST1);
	pList->InsertColumn(0, _T("����"), LVCFMT_LEFT, 100);	//�����ֶ���(�У����ݣ����룬����)
	pList->InsertColumn(1, _T("����"), LVCFMT_LEFT, 150);
	pList->InsertColumn(2, _T("����"), LVCFMT_LEFT, 150);
	pList->InsertColumn(3, _T("����"), LVCFMT_LEFT, 200);
	//�����б�����ɫ
	pList->SetBkColor(RGB(205, 226, 252));	
	pList->SetTextColor(RGB(0, 0, 255));
	pList->SetTextBkColor(RGB(205, 226, 252));
	
	//����ʱ���Զ����� work.dat�ļ��е�����
	OnBnClickedbtnload();

	// �����չ������
	pList->SetExtendedStyle( LVS_EX_GRIDLINES | LVS_EX_FULLROWSELECT); 


	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CWorkDlg::OnPaint()
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
HCURSOR CWorkDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CWorkDlg::OnBnClickedCancel()
{
	if (IDYES == AfxMessageBox(_T("�Ƿ񱣴�Ķ������ݣ�"), MB_YESNO | MB_ICONQUESTION))
	{
		OnBnClickedbtnsave();
	}
	CDialogEx::OnCancel();
}


void CWorkDlg::OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO:  �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}


// �������Ƿ����, ����flase����ɲ��룬����true�������Բ���
bool CWorkDlg::CheckNumber(LPCTSTR szNumber)
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);
	int i = 0, nCount = pList->GetItemCount();

	while (i < nCount)
	{
		if (pList->GetItemText(i, 0) == szNumber)
		{
			AfxMessageBox(_T("�ú����Ѵ��ڣ����������룡"));
			this->SetFocus();
			//SetDlgItemText(IDC_EDIT2, NULL);
			return true;
		}
		++i;
	}
	return false;
}


void CWorkDlg::OnBnClickedbtnadd()
{
	// �ų��ظ����ŵĹ��ܣ����ظ��Ĺ��Ž�ֹ���루�Ѵ��ڣ��� ��Ҫʵ��

	CString str;
	GetDlgItemText(IDC_EDIT1, str);

	if (CheckNumber(str))
		return;
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);
	int i = pList->GetItemCount();

	GetDlgItemText(IDC_EDIT1, str);	//��ȡIDC_EDIT1 ����������ָ�str
	pList->InsertItem(i, str);
	GetDlgItemText(IDC_EDIT2, str);
	pList->SetItemText(i, 1, str);
	GetDlgItemText(IDC_EDIT3, str);
	pList->SetItemText(i, 2, str);
	GetDlgItemText(IDC_DATE, str);
	pList->SetItemText(i, 3, str);

	m_bModified = TRUE;
}




/*

//��ѡ��־
GetSelectedCount()
GetNextSelectdItem()
GetFirstSelectedItemPosition()


if (!pList->GetSelectedCount())
{
AfxMessageBox(_T("��ѡ��һ����ɾ����"));
return;
}
*/
/*
ɾ����ť
*/

// ����ɾ��
//CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);
//
////���뵥ѡ��־
//int nSel = pList->GetSelectionMark();
//if (nSel < 0)
//{
//	AfxMessageBox(_T("��ѡ��һ����ɾ����"));
//	return;
//}
//
//CString str = pList->GetItemText(nSel, 0);
//
//if (AfxMessageBox(_T("��ȷ��Ҫɾ�� ") + str + _T(" ��"), MB_YESNO) == IDYES)
//pList->DeleteItem(nSel);
void CWorkDlg::OnBnClickedbtndel()
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);
	
	if(!pList->GetSelectedCount())
	{
		AfxMessageBox(_T("��ѡ��һ����ɾ����"));
		return;
	}

	POSITION pos = pList->GetFirstSelectedItemPosition();
	while (pos)
	{
		int nSel = pList->GetNextSelectedItem(pos);
		CString str = pList->GetItemText(nSel, 0);
		if (IDNO == AfxMessageBox(_T("ȷ��Ҫɾ�����Ϊ") + str + _T("����Ϣ��"), MB_YESNO))
			continue;
		// ɾ������� Ҫ����
		pList->DeleteItem(nSel);
		m_bModified = TRUE;
	}
	

}

/*
	���ذ�ť
*/
void CWorkDlg::OnBnClickedbtnload()
{
	CFile file;
	if (!file.Open(_T("./Worker.dat"), CFile::modeRead))
		return;

	
	CListCtrl * pList = (CListCtrl*)GetDlgItem(IDC_LIST1);
	SInfo info;
	int i = 0;
	CString str;

	while (file.Read(&info, sizeof(info)) == sizeof(info))
	{
		str.Format(_T("%d"), info.nNumb);//����ת��Ϊ�ַ���
		pList->InsertItem(i, str);
		pList->SetItemText(i, 1, info.sName);

		str.Format(_T("%0.2f"), info.fSala);
		pList->SetItemText(i, 2, str);

		pList->SetItemText(i, 3, info.tDate.Format(_T("%Y��%m��%d��")));
		i++;
	}

	file.Close();



}



/*
	���水ť
*/
void CWorkDlg::OnBnClickedbtnsave()
{
	CFile file;
	if (!file.Open(_T("./Worker.dat"), CFile::modeCreate | CFile::modeWrite))
	{
		AfxMessageBox(_T("�����ļ�ʱ��ʧ�ܣ�"));
		return;
	}
	


	SInfo info;
	CListCtrl * pList = (CListCtrl*)GetDlgItem(IDC_LIST1);
	int i = 0;
	int nCount = pList->GetItemCount();
	while (i < nCount)
	{
		//int
		info.nNumb = _tstoi(pList->GetItemText(i, 0));
		//�ַ���
		_tcscpy(info.sName, pList->GetItemText(i, 1));
		//float
		info.fSala = _tstof(pList->GetItemText(i, 2));
		//time
		info.tDate.ParseDateTime(pList->GetItemText(i, 3),VAR_DATEVALUEONLY);

		file.Write(&info, sizeof(info));
		++i;
	}

	AfxMessageBox(_T("�����ļ��ɹ���"));
	file.Close();
	m_bModified = FALSE;

}



/*
	�޸İ�ť
*/
//	��ѡ
//CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);
//
//POSITION pos = pList->GetFirstSelectedItemPosition();
//if (!pList->GetSelectedCount())
//{
//	AfxMessageBox(_T("��ѡ��һ�����޸�"));
//	return;
//}
//int nSel = pList->GetNextSelectedItem(pos);
//CString str = pList->GetItemText(nSel, 0);
//if (IDNO == AfxMessageBox(_T("ȷ��Ҫ�޸ı��Ϊ") + str + _T("����Ϣ��"), MB_YESNO))
//return;
//
//GetDlgItemText(IDC_EDIT2, str);
//pList->SetItemText(nSel, 1, str);
//
//GetDlgItemText(IDC_EDIT3, str);
//pList->SetItemText(nSel, 2, str);
//
//GetDlgItemText(IDC_DATE, str);
//pList->SetItemText(nSel, 3, str);

void CWorkDlg::OnBnClickedbtnmodify()
{
	CListCtrl* pList = (CListCtrl*)GetDlgItem(IDC_LIST1);

	POSITION pos = pList->GetFirstSelectedItemPosition();
	if (!pList->GetSelectedCount())
	{
		AfxMessageBox(_T("��ѡ��һ�����޸�"));
		return;
	}

	while (pos)
	{
		int nSel = pList->GetNextSelectedItem(pos);
		CString str = pList->GetItemText(nSel, 0);
		if (IDNO == AfxMessageBox(_T("ȷ��Ҫ�޸ı��Ϊ") + str + _T("����Ϣ��"), MB_YESNO))
			continue;

		GetDlgItemText(IDC_EDIT2, str);
		pList->SetItemText(nSel, 1, str);

		GetDlgItemText(IDC_EDIT3, str);
		pList->SetItemText(nSel, 2, str);

		GetDlgItemText(IDC_DATE, str);
		pList->SetItemText(nSel, 3, str);

		m_bModified = TRUE;
	}
	
}
