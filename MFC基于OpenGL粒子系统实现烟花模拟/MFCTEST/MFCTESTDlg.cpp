
// MFCTESTDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCTEST.h"
#include "MFCTESTDlg.h"
#include "afxdialogex.h"
#include <windows.h>
#include <stdio.h>
#include <Gl/glut.h>
#include<stdlib.h>
#include "math.h"
#include"焰火.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
int Stop = 0;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCTESTDlg 对话框



CMFCTESTDlg::CMFCTESTDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCTEST_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCTESTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCTESTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_TIMER()
	ON_STN_CLICKED(IDC_RENDER, &CMFCTESTDlg::OnStnClickedRender)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCTESTDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDOK, &CMFCTESTDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCTESTDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCTESTDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCTESTDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCTESTDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCTESTDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCTESTDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCTESTDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCTESTDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCTESTDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON11, &CMFCTESTDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCTESTDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDOK2, &CMFCTESTDlg::OnBnClickedOk2)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCTESTDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON12, &CMFCTESTDlg::OnBnClickedButton12)

	ON_BN_CLICKED(IDC_BUTTON13, &CMFCTESTDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON14, &CMFCTESTDlg::OnBnClickedButton14)
END_MESSAGE_MAP()


// CMFCTESTDlg 消息处理程序

BOOL CMFCTESTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。
	CWnd* wnd = GetDlgItem(IDC_RENDER);                                        // 初始化MFC中的OpenGL设置
	hrenderDC = ::GetDC(wnd->m_hWnd);
	if (SetWindowPixelFormat(hrenderDC) == FALSE) {                // 设置hDC的像素格式
		return 0;
	}
	if (CreateViewGLContext(hrenderDC) == FALSE) {                    // 由hDC转换得到hRC
		return 0;
	}
	// openGL的初始化设置
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glShadeModel(GL_SMOOTH);
	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glShadeModel(GL_SMOOTH);
	glClearDepth(1.0f);
	glDisable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE);//混合
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glMatrixMode(GL_PROJECTION);


	gluPerspective(45, 1.5, 1, 2000.0);
	gluLookAt(0.0, -50.0, 100.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	// 设置计时器,10ms刷新一次
	SetTimer(1, 10, 0);

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCTESTDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCTESTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCTESTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCTESTDlg::OnStnClickedRender()
{
	// TODO: 在此添加控件通知处理程序代码
}

BOOL CMFCTESTDlg::SetWindowPixelFormat(HDC hDC) { // CCOpenGLDlg改为你自己创建的MFC类名
	PIXELFORMATDESCRIPTOR pixelDesc;
	pixelDesc.nSize = sizeof(PIXELFORMATDESCRIPTOR);
	pixelDesc.nVersion = 1;
	pixelDesc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER | PFD_TYPE_RGBA;
	pixelDesc.iPixelType = PFD_TYPE_RGBA;
	pixelDesc.cColorBits = 32;
	pixelDesc.cRedBits = 0;
	pixelDesc.cRedShift = 0;
	pixelDesc.cGreenBits = 0;
	pixelDesc.cGreenShift = 0;
	pixelDesc.cBlueBits = 0;
	pixelDesc.cBlueShift = 0;
	pixelDesc.cAlphaBits = 0;
	pixelDesc.cAlphaShift = 0;
	pixelDesc.cAccumBits = 0;
	pixelDesc.cAccumRedBits = 0;
	pixelDesc.cAccumGreenBits = 0;
	pixelDesc.cAccumBlueBits = 0;
	pixelDesc.cAccumAlphaBits = 0;
	pixelDesc.cDepthBits = 0;
	pixelDesc.cStencilBits = 1;
	pixelDesc.cAuxBuffers = 0;
	pixelDesc.iLayerType = PFD_MAIN_PLANE;
	pixelDesc.bReserved = 0;
	pixelDesc.dwLayerMask = 0;
	pixelDesc.dwVisibleMask = 0;
	pixelDesc.dwDamageMask = 0;

	PixelFormat = ChoosePixelFormat(hDC, &pixelDesc);
	if (PixelFormat == 0) {
		PixelFormat = 1;
		if (DescribePixelFormat(hDC, PixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pixelDesc) == 0) {
			return FALSE;
		}
	}
	if (SetPixelFormat(hDC, PixelFormat, &pixelDesc) == FALSE) {
		return FALSE;
	}
	return TRUE;
}

BOOL CMFCTESTDlg::CreateViewGLContext(HDC hDC) {
	hrenderRC = wglCreateContext(hDC);
	if (hrenderRC == NULL) {
		return FALSE;
	}
	if (wglMakeCurrent(hDC, hrenderRC) == FALSE) {
		return FALSE;
	}
	return TRUE;
}
//在MFC中调用绘图函数
void CMFCTESTDlg::RenderScene() {

	display();
	SwapBuffers(hrenderDC);

}
//在OnTimer中调用绘图函数保证动画效果
void CMFCTESTDlg::OnTimer(UINT nIDEvent) {

	if(Stop%2==0)
	RenderScene();
	CDialog::OnTimer(nIDEvent);
}



void CMFCTESTDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	Stop += 1;


}


void CMFCTESTDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}
void CMFCTESTDlg::OnBnClickedButton1()
{
	WAVES++;
}

void CMFCTESTDlg::OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}


void CMFCTESTDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	speeds -=0.05;
	//G *= 0.5;
	Init();

}


void CMFCTESTDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	MAX_FIRES++;
	Init();
}


void CMFCTESTDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if(MAX_FIRES>1)
	MAX_FIRES--;
	Init();
}


void CMFCTESTDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (WAVES > 1) {
	WAVES--;
	MAX_PARTICLES -= 24;
	}

	Init();
}


void CMFCTESTDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
		WAVES++;
		MAX_PARTICLES += 24;

	Init();
}


void CMFCTESTDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	lifes -= 0.1;
	Init();
}


void CMFCTESTDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	lifes += 0.1;
	Init();
}


void CMFCTESTDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	speeds += 0.05;
	//G *= 0.5;
	Init();
}


void CMFCTESTDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	EXP_speed += 0.1;
	Init();
}


void CMFCTESTDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	EXP_speed -= 0.1;
	Init();
}


void CMFCTESTDlg::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码
	color = 100;
WAVES = 1;
MAX_FIRES = 1;
WAVE_NUM = 24;// 最多5个烟花
MAX_PARTICLES = 24; // 每个烟花升空散开的小烟花个数
lifes = 1.0;		//生命
G = -0.005;		//y方向加速度
speeds = 1;				//速度
EXP_speed = rand() % 3 + 4;
	Init();
}


void CMFCTESTDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCTESTDlg::OnBnClickedButton12()
{
	color_mode = 1;
	char ch1[10], ch2[10], ch3[10], ch4[10], ch5[10],ch6[10];
	GetDlgItem(IDC_EDIT1)->GetWindowText(ch1, 10);
	GetDlgItem(IDC_EDIT2)->GetWindowText(ch2, 10);
	GetDlgItem(IDC_EDIT3)->GetWindowText(ch3, 10);
	GetDlgItem(IDC_EDIT4)->GetWindowText(ch4, 10);
	GetDlgItem(IDC_EDIT5)->GetWindowText(ch5, 10);
	GetDlgItem(IDC_EDIT6)->GetWindowText(ch6, 10);
	num1 = atoi(ch1);
	num2 = atoi(ch2);
	num3 = atoi(ch3);
	num4 = atoi(ch4);
	num5 = atoi(ch5);
	num6 = atoi(ch6);
	printf("%d", num1);
}




void CMFCTESTDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	SIZE_s -=0.3;
}


void CMFCTESTDlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	SIZE_s += 0.3;
}
