
// tcpTestDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "TcpCommLibBase.h"


// CtcpTestDlg �Ի���
class CtcpTestDlg : public CDialogEx
{
// ����
public:
	CtcpTestDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CtcpTestDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TCPTEST_DIALOG };
#endif

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
public:
	afx_msg void OnBnClickedButtonStart();
	afx_msg void OnBnClickedButtonStop();
	afx_msg void OnBnClickedButtonSend();

	static void TcpcbFun(CBTYPE_EN enType, void *pThis, void *pBuf);


	CEdit m_editRecv;
	CEdit m_editSend;
	CComboBox m_cmbType;


	CTcpCommLibBase *m_pTcpServer;
	CTcpCommLibBase *m_pTcpClient;
	afx_msg void OnBnClickedButtonNew();
};
