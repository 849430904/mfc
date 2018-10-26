
// NotepadDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "Notepad.h"
#include "NotepadDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CNotepadDlg �Ի���



CNotepadDlg::CNotepadDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_NOTEPAD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNotepadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CNotepadDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(ID_APP_EXIT, &CNotepadDlg::OnAppExit)
	ON_WM_DROPFILES()
	ON_COMMAND(ID_APP_ABOUT, &CNotepadDlg::OnAppAbout)
	ON_WM_SIZE()
	ON_WM_CLOSE()
	ON_COMMAND(ID_EDIT_CLEAR, &CNotepadDlg::OnEditClear)
	ON_COMMAND(ID_EDIT_COPY, &CNotepadDlg::OnEditCopy)
	ON_COMMAND(ID_EDIT_CUT, &CNotepadDlg::OnEditCut)
	ON_COMMAND(ID_EDIT_DATA, &CNotepadDlg::OnEditData)
	ON_COMMAND(ID_EDIT_FIND, &CNotepadDlg::OnEditFind)
	ON_COMMAND(ID_EDIT_FINDNEXT, &CNotepadDlg::OnEditFindnext)
	ON_COMMAND(ID_EDIT_GO, &CNotepadDlg::OnEditGo)
	ON_COMMAND(ID_EDIT_PASTE, &CNotepadDlg::OnEditPaste)
	ON_COMMAND(ID_EDIT_REPLACE, &CNotepadDlg::OnEditReplace)
	ON_COMMAND(ID_EDIT_UNDO, &CNotepadDlg::OnEditUndo)
	ON_COMMAND(ID_EDIT_SELECT_ALL, &CNotepadDlg::OnEditSelectAll)
END_MESSAGE_MAP()


// CNotepadDlg ��Ϣ�������

BOOL CNotepadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	//���ؿ�ݼ�  loadAccelerators() �������ڼ���ָ���Ŀ�ݼ� ��

	HACCEL m_hAcc = LoadAccelerators(AfxGetInstanceHandle(), MAKEINTRESOURCE(IDR_MAIN));

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

void CNotepadDlg::OnPaint()
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
HCURSOR CNotepadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CNotepadDlg::OnOK()
{
	//ID_APP_EXIT
	//CDialogEx::OnOK();
}


void CNotepadDlg::OnCancel()
{
	// TODO: �ڴ����ר�ô����/����û���

	//CDialogEx::OnCancel();
}


void CNotepadDlg::OnAppExit()
{
	EndDialog(ID_APP_EXIT);
}

//����Acccept Files= True �Ϸ��ļ���������Ϣ
void CNotepadDlg::OnDropFiles(HDROP hDropInfo)
{
	TCHAR sFile[256];
	int nCount = DragQueryFile(hDropInfo, 0, sFile, _countof(sFile));
	CFile file;// �򿪵�һ������Ƿ�unicode �� ����Ľ�����unicode
	//SetDlgItemInt(...)

	CDialogEx::OnDropFiles(hDropInfo);
}
/*  ���ĵ����ļ�����  ����photoshop ������ĵ�һ�δ�
//DragQueryFile()�����ӳɹ����ϷŲ������Ϸŵ��ļ�������
TCHAR sFile[256];
//sizeof(sFile);

// nCount Ϊ�������ļ�������
int nCount = DragQueryFile(hDropInfo, -1, NULL, 0);
int i = 0;

while (i < nCount)
{
// �õ���������ļ����ļ���
DragQueryFile(hDropInfo, i, sFile, _countof(sFile));
++i;
}
*/

void CNotepadDlg::OnAppAbout()
{
	CAboutDlg dlg;
	dlg.DoModal();
	
}


void CNotepadDlg::OnSize(UINT nType, int cx, int cy)
{
	CDialogEx::OnSize(nType, cx, cy);
	//�������ؼ�
	//CWnd *p = GetDlgItem(IDC_TEXT);
	CEdit *p;
	p = (CEdit*)GetDlgItem(IDC_TEXT);
	if (p)
	{
		CRect rect;
		GetClientRect(rect);
		//����λ�úͳߴ�
		p->MoveWindow(rect);
		//ǿ��ת��Ϊ����CEdit��
	}

}

//ϵͳ�ر���Ϣ
void CNotepadDlg::OnClose()
{
	EndDialog(IDCANCEL);
	//CDialogEx::OnClose();
}


void CNotepadDlg::OnEditClear()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->Clear();

}


void CNotepadDlg::OnEditCopy()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->Copy();
}


void CNotepadDlg::OnEditCut()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->Cut();
}

/*�������ں���*/
void CNotepadDlg::OnEditData()
{
	COleDateTime time = COleDateTime::GetCurrentTime();
	CString str = time.Format(_T("%H:%M %Y/%m/%d %W"));

	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->ReplaceSel(str, 1);
	//SetDlgItemText(IDC_TEXT, str);
}


void CNotepadDlg::OnEditFind()
{
	// TODO: �ڴ���������������
}


void CNotepadDlg::OnEditFindnext()
{
	// TODO: �ڴ���������������
}


void CNotepadDlg::OnEditGo()
{
	// TODO: �ڴ���������������
}


void CNotepadDlg::OnEditPaste()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->Paste();
}


void CNotepadDlg::OnEditReplace()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
}


void CNotepadDlg::OnEditUndo()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->Undo();
}


void CNotepadDlg::OnEditSelectAll()
{
	CEdit *pEdit = (CEdit *)GetDlgItem(IDC_TEXT);
	pEdit->SetSel(0, -1);
}


BOOL CNotepadDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: �ڴ����ר�ô����/����û���
	if (WM_KEYFIRST <= pMsg->message&&pMsg->message <= WM_KEYLAST)

	{

		HACCEL hAccel = m_hAcc;

		if (hAccel && ::TranslateAccelerator(m_hWnd, hAccel, pMsg))

			return TRUE;

	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
