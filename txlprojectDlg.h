
// txlprojectDlg.h: 头文件
//

#include"DataInterface.h"

#pragma once


// CtxlprojectDlg 对话框
class CtxlprojectDlg : public CDialogEx
{
// 构造
public:
	CtxlprojectDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TXLPROJECT_DIALOG };
#endif

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
public:
	CListCtrl m_list;
	DataInterface DataInterface;
	CString strFilepath;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton5();
	void UpdateList();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton3();
	CString m_find;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();

	/*CString m_phoneToDisplay;  // 要显示的电话号码
	CString m_currentDisplay;  // 当前已经显示的电话号码
	UINT_PTR m_timerID;        // 定时器ID
	int m_displayIndex;        // 当前显示到的字符位置

protected:
	virtual void OnTimer(UINT_PTR nIDEvent);
	void StartPhoneDisplay(const CString& phoneNumber);*/
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton10();
};

