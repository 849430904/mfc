
// calcDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "calc.h"
#include "calcDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CcalcDlg �Ի���



CcalcDlg::CcalcDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CALC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcalcDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcalcDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CcalcDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CcalcDlg ��Ϣ�������

BOOL CcalcDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();


	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_OPER);
	pCombo->AddString(_T("+"));
	pCombo->AddString(_T("-"));
	pCombo->AddString(_T("*"));
	pCombo->AddString(_T("/"));
	pCombo->AddString(_T("%"));
	pCombo->SetCurSel(0);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcalcDlg::OnPaint()
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
HCURSOR CcalcDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CcalcDlg::OnBnClickedOk()
{
	//��ȡ�Ի����е�ֵ
	CString szOper, str;
	GetDlgItemText(IDC_OPER, szOper);

	GetDlgItemText(IDC_LEFT, str);
	double fLeft = _tstof(str);
	
	GetDlgItemText(IDC_RIGHT, str);
	double fRight = _tstof(str);


	//���ݶ�Ӧ��ֵ������Ӧ�ļ���
	switch (szOper[0]) //switch ���ܱȽ��ַ�����������ת��Ϊ����
	{
	case _T('+'):
		str.Format(_T("%lf"), fLeft + fRight);
		break;
	case _T('-'):
		str.Format(_T("%lf"), fLeft - fRight);
		break;
	case _T('*'):
		str.Format(_T("%lf"), fLeft * fRight);
		break;
	case _T('/'):
		if (fRight == 0.0)
		{
			str = _T("��������Ϊ0");
		}
		else
			str.Format(_T("%lf"), fLeft / fRight);
		break;
	case _T('%'):
		str = _T("�ù�����ʱ��֧��");
		//str.Format(_T("%lf"), (int)fLeft % (int)fRight);
		break;
	}

	SetDlgItemText(IDC_RESULT, str);
}
