
// explorerDlg.h : ͷ�ļ�
//

#pragma once


// CexplorerDlg �Ի���
class CexplorerDlg : public CDialogEx
{

	//inline static BOOL IsHidden(const CFileFind &ff)
	//{
	//	if (ff.IsHidden())
	//		return TRUE;
	//	else if (ff.IsDots())
	//		return TRUE;
	//	else
	//		return FALSE;
	//}


	static LPCTSTR  m_weeks[];
// ����
public:
	CexplorerDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXPLORER_DIALOG };
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
	virtual void OnOK();
};
