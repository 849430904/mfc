
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


void CNotepadDlg::ReadAnsi(CFile& file)
{
	file.Seek(0, CFile::begin);
	char buff[1024];
	CString str;
	UINT nRet = 0; //�����ļ�: ANSI(û���ļ�ͷ) Unicode UTF-8�����ļ�ͷ��
	while (nRet = file.Read(buff, sizeof(buff) - 1))
	{
		buff[nRet] = _T('\0');
		str += buff;
	}

	SetDlgItemText(IDC_TEXT, str);
}


void CNotepadDlg::ReadUnicode(CFile& file)
{
	file.Seek(2, CFile::begin);
	LONGLONG nLen = file.GetLength();		//��ȡ�ļ�����
	TCHAR *p = new TCHAR[nLen / 2 + 1];
	nLen = file.Read(p, nLen);
	p[nLen/2] = _T('\0');
	SetDlgItemText(IDC_TEXT, p);
	delete[]p;
}


void CNotepadDlg::ReadUTF_8(CFile& file)
{
	
	file.Seek(3, CFile::begin);
	LONGLONG nLen =file.GetLength();		//��ȡ�ļ�����
	char *p = new char[nLen + 1];
	nLen = file.Read(p, nLen);
	p[nLen] = '\0';
	TCHAR *pText = new TCHAR[nLen / 2 + 2];

	nLen = MultiByteToWideChar(CP_UTF8, NULL, p, -1, pText, nLen/2+2);

	SetDlgItemText(IDC_TEXT, pText);
	delete []p;
	delete []pText;
}


//����Acccept Files= True �Ϸ��ļ���������Ϣ
void CNotepadDlg::OnDropFiles(HDROP hDropInfo)
{
	CDialogEx::OnDropFiles(hDropInfo);
	TCHAR sFile[256];
	int nCount = DragQueryFile(hDropInfo, 0, sFile, _countof(sFile));
	CFile file;// �򿪵�һ������Ƿ�unicode �� ����Ľ�����unicode
	//SetDlgItemInt(...)
	if (!file.Open(sFile, CFile::modeRead))
	{
		AfxMessageBox(_T("���ļ�ʱʧ��"));
		return;
	}
	if(file.Read(sFile, 2) == 2)
	{	
		switch (sFile[0])
		{
		case 0xBBEF:
			//if (sFile)
			ReadUTF_8(file);
			return;
		case 0xFEFF:
			ReadUnicode(file);
			return;	
		}
		
	}
	ReadAnsi(file);
	
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


