
// TestTimeDlg.h : ͷ�ļ�
//

#pragma once


// CTestTimeDlg �Ի���
class CTestTimeDlg : public CDialogEx
{
// ����
public:
	CTestTimeDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TESTTIME_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedGetTime();
	afx_msg void OnBnClickedGetTime2();
	afx_msg void OnBnClickedMkTime();
	afx_msg void OnBnClickedMkTime2();
	afx_msg void OnBnClickedMkTime3();
};
