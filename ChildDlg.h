#pragma once
#include "afxdialogex.h"


// ChildDlg 对话框

class ChildDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ChildDlg)

public:
	ChildDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ChildDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ChildDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton2();
	CString m_name;
	CString m_phone;
	CString m_family_phone;
	CString m_office_phone;
	CString m_e_mail;
	CString m_group;
	afx_msg void OnBnClickedButton1();
};
