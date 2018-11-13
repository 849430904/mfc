
// explorerDlg.h : ͷ�ļ�
//

#pragma once


// CexplorerDlg �Ի���
class CexplorerDlg : public CDialogEx
{

	inline static BOOL IsHidden(const WIN32_FIND_DATA &c_file)
	{
		if (c_file.dwFileAttributes & FILE_ATTRIBUTE_HIDDEN)
			return TRUE;
		else if (!_tcscmp(c_file.cFileName, _T(".")))	//strcmp ֻ֧��char ���͵�  ����ʹ��_tcscmp ���͵ıȽϺ���
			return TRUE;
		else if (!_tcscmp(c_file.cFileName, _T("..")))
			return TRUE;
		else
			return FALSE;
	}


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
