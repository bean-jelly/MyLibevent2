
// tcpTest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CtcpTestApp: 
// �йش����ʵ�֣������ tcpTest.cpp
//

class CtcpTestApp : public CWinApp
{
public:
	CtcpTestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CtcpTestApp theApp;