#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrev, LPSTR loCmd, int nCmdShow)
{
	//HWND hwnd = FindWindow(NULL, "����.txt -���±�");
	//HWND hwnd = FindWindow("MozillaWindowClass", NULL);
	int nRet = MessageBox(NULL, "�����ҵĵ�һ��Windows�����", "��ܰ��ʾ��", MB_YESNOCANCEL);
	switch (nRet)
	{
	case IDYES:
		MessageBox(NULL, "��������YES", "���:", MB_OK);
		break;
	case IDNO:
		MessageBox(NULL, "��������NO", "���:", MB_OK);
		break;
	case IDCANCEL:
		MessageBox(NULL, "��������CANCEL", "���:", MB_OK);
		break;
	default:
		break;
	}
	return 0;
}