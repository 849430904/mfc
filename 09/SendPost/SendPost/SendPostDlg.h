
// SendPostDlg.h : ͷ�ļ�
//

#pragma once


// CSendPostDlg �Ի���
class CSendPostDlg : public CDialogEx
{
// ����
public:
	CSendPostDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SENDPOST_DIALOG };
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
	afx_msg void OnBnClickedSend();
	afx_msg void OnBnClickedPost();
	afx_msg void OnClose();
protected:
	afx_msg LRESULT OnUmtest(WPARAM wParam, LPARAM lParam);
};
