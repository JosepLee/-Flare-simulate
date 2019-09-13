
// MFCTESTDlg.h : ͷ�ļ�
//

#pragma once


// CMFCTESTDlg �Ի���
class CMFCTESTDlg : public CDialogEx
{
// ����
public:
	CMFCTESTDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCTEST_DIALOG };
#endif
	BOOL SetWindowPixelFormat(HDC hDC);                    // �趨���ظ�ʽ
	BOOL CreateViewGLContext(HDC hDC);                    // view GL Context
	void RenderScene();                                                    // ���Ƴ���
	HDC hrenderDC;                                                            // DC
	HGLRC hrenderRC;                                                        // RC
	int PixelFormat;                                                        // ���ظ�ʽ
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnTimer(UINT nIDEvent);                // ����OnTimer����
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
