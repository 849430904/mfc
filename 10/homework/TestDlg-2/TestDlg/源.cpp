#include <windows.h>
#include "resource.h"
#include <tchar.h>
#include <Commctrl.h>
HINSTANCE g_inst;
//hInstance:��Դ�ܹ�
enum
{
	UM_ADD = WM_USER + 100,
};

int List_insertColumn(HWND hWnd, int nIndex, LPCTSTR sHeader, int nFormat, int nWidth)
{
	LVCOLUMN column;
	column.mask = LVCF_TEXT | LVCF_FMT;
	column.pszText = (LPTSTR)sHeader;
	column.fmt = nFormat;
	if (nWidth != -1)
	{
		column.mask |= LVCF_WIDTH;
		column.cx = nWidth;
	}
	return (int) ::SendMessage(hWnd, LVM_INSERTCOLUMN, nIndex, (LPARAM)&column);
}

void OnInitDialog(HWND hwndDlg)
{
	HICON hIcon = LoadIcon(g_inst, MAKEINTRESOURCE(IDI_ICON1));
	hIcon = (HICON)::SendMessage(hwndDlg, WM_SETICON, FALSE, (LPARAM)hIcon);

	HWND hWnd = GetDlgItem(hwndDlg, IDC_LIST1);
	List_insertColumn(hWnd, 0, _T("����"), 0, 100);
}
int List_InsertItem(HWND hWnd, int nIndex, LPCTSTR sText)
{
	LVITEM item = {LVIF_TEXT};	//ͨ�������ų�ʼ���ṹ�塣
	//item.mask = LVIF_TEXT;
	item.iItem = nIndex;
	item.pszText = (LPTSTR)sText;
	return (int)::SendMessage(hWnd, LVM_INSERTITEM, 0, (LPARAM)&item);
}
void OnAdd(HWND hwndDlg)
{
	HWND hWnd = GetDlgItem(hwndDlg, IDC_LIST1);
	TCHAR s[64];
	GetDlgItemText(hwndDlg, IDC_EDIT1, s, _countof(s));
	List_InsertItem(hWnd, 0, s);
}


//��Ϣ�ص�����
INT_PTR CALLBACK DialogProc(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_INITDIALOG:
		OnInitDialog(hwndDlg);
		return TRUE;
	case UM_ADD:
	{
		return wParam+lParam;
	}
	case WM_CLOSE:
		MessageBox(hwndDlg, _T("�ر�"), _T("��ʾ"), 0);
		return FALSE;//true����ϵͳ���ùر��ˣ� FALSE����ϵͳ�����ر�
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hwndDlg, IDCANCEL);
			return TRUE;
		case IDC_SEND:
			{
				//HWND hWnd = FindWindow(_T("Notepad"), NULL);
				LRESULT res = SendMessage(hwndDlg, UM_ADD, wParam, lParam);
				return TRUE;
			}
		case IDC_POST:
			{			
				HWND hWnd = FindWindow(_T("Notepad"), NULL);
				BOOL a = PostMessage(hWnd, WM_CLOSE, 0, 0);
				return TRUE;
			}
		case IDC_btnAdd:
			OnAdd(hwndDlg);
			return TRUE;

		}
	break;
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nCmdShow)
{//MessageBox FindWindow
	g_inst = hInstance;
	DialogBox(hInstance, (LPCTSTR)IDD_WORK_DIALOG, NULL, DialogProc);
	return 0;
}