
// WorkDlg.h : ͷ�ļ�
//

#pragma once


// CWorkDlg �Ի���
class CWorkDlg : public CDialogEx
{
// ����
public:
	CWorkDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_WORK_DIALOG };

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
	afx_msg void OnBnClickedCancel();
	afx_msg void OnLvnItemchangedList1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedbtnadd();
	afx_msg void OnBnClickedbtndel();
	afx_msg void OnBnClickedbtnload();
	afx_msg void OnBnClickedbtnsave();
	// �������Ƿ����
	bool CheckNumber(LPCTSTR szNumber);
};
