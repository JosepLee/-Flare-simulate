
// MFC_FLAME.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_FLAMEApp: 
// �йش����ʵ�֣������ MFC_FLAME.cpp
//

class CMFC_FLAMEApp : public CWinApp
{
public:
	CMFC_FLAMEApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_FLAMEApp theApp;
