#include<Windows.h>
#include<tchar.h>
#include<comutil.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR lpCmd, int nShow)
{
	MessageBox(NULL, _T("abc"), _TEXT("����"), MB_OK);

	LPSTR p1 = "abc";	//MB 0X616263
	char *p2 = "�й�";	//MB 0xd0d6-fab9
	char *p3 = "�Ї�";	//MB 0xd0d6-f887
	TCHAR *t1 = _T("abc");
	wchar_t *lp1 = L"abc";	//unicode	0x0061 0062 0063
	wchar_t *lp2 = L"�й�";	//unicode	0x4e2d 56fd
	wchar_t *lp3 = L"�Ї�";	//unicode	0x4e2d 570b

	// ���ַ�תUnicode	��ǰ����
	wchar_t t[20];
	MultiByteToWideChar(CP_ACP, 0, p2, -1, t, _countof(t));
	/*	*/

	_bstr_t bstr1 = p1;

	_bstr_t bstr2 = lp1;

	return 0;
}