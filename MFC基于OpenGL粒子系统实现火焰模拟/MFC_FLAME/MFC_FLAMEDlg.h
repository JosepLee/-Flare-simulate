
// MFC_FLAMEDlg.h : ͷ�ļ�
//

#pragma once


// CMFC_FLAMEDlg �Ի���
class CMFC_FLAMEDlg : public CDialogEx
{
// ����
public:
	CMFC_FLAMEDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_FLAME_DIALOG };
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
	afx_msg void OnTimer(UINT nIDEvent);
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnEnChangeEdit2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton9();
};



