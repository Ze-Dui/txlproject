// ChildDlg.cpp: 实现文件
//

#include "pch.h"
#include "txlproject.h"
#include "afxdialogex.h"
#include "ChildDlg.h"


// ChildDlg 对话框

IMPLEMENT_DYNAMIC(ChildDlg, CDialogEx)

ChildDlg::ChildDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ChildDlg, pParent)
	, m_name(_T(""))
	, m_phone(_T(""))
	, m_family_phone(_T(""))
	, m_office_phone(_T(""))
	, m_e_mail(_T(""))
	, m_group(_T(""))
{

}

ChildDlg::~ChildDlg()
{
}

void ChildDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_phone);
	DDX_Text(pDX, IDC_EDIT3, m_family_phone);
	DDX_Text(pDX, IDC_EDIT4, m_office_phone);
	DDX_Text(pDX, IDC_EDIT5, m_e_mail);
	DDX_Text(pDX, IDC_EDIT6, m_group);
}


BEGIN_MESSAGE_MAP(ChildDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &ChildDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &ChildDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// ChildDlg 消息处理程序


void ChildDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码

	EndDialog(0);
}


void ChildDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (m_name == TEXT("") || m_phone == TEXT("") || m_family_phone == TEXT("") || m_office_phone == TEXT("") || m_e_mail == TEXT("") || m_group == TEXT(""))
	{
		MessageBox(TEXT("您有输入为空，请重新填写。"),TEXT("提示"));
	}
	else
	{
		OnOK();
		return;
	}
}
