
// SendPost.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CSendPostApp: 
// �йش����ʵ�֣������ SendPost.cpp
//

class CSendPostApp : public CWinApp
{
public:
	CSendPostApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CSendPostApp theApp;