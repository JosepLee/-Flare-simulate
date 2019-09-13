
// MFCTESTDlg.h : 头文件
//

#pragma once


// CMFCTESTDlg 对话框
class CMFCTESTDlg : public CDialogEx
{
// 构造
public:
	CMFCTESTDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTEST_DIALOG };
#endif
	BOOL SetWindowPixelFormat(HDC hDC);                    // 设定像素格式
	BOOL CreateViewGLContext(HDC hDC);                    // view GL Context
	void RenderScene();                                                    // 绘制场景
	HDC hrenderDC;                                                            // DC
	HGLRC hrenderRC;                                                        // RC
	int PixelFormat;                                                        // 像素格式
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT nIDEvent);                // 重载OnTimer函数
public:
	afx_msg void OnStnClickedRender();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnNMCustomdrawSlider1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider2(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnNMCustomdrawSlider4(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	afx_msg void OnNMCustomdrawSlider3(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedOk2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton12();

	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton14();
};
