#pragma once


// CLoginDlg �Ի���

class CLoginDlg : public CDialogEx
{
	// ������̬��������
	DECLARE_DYNAMIC(CLoginDlg)

public:
	CLoginDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CLoginDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_LOGIN_DLG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��
	//
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeStatus();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
};
