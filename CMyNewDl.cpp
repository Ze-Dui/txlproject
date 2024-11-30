// CMyNewDl.cpp: 实现文件
//

#include "pch.h"
#include "txlproject.h"
#include "afxdialogex.h"
#include "CMyNewDl.h"


// CMyNewDl 对话框

IMPLEMENT_DYNAMIC(CMyNewDl, CDialogEx)

CMyNewDl::CMyNewDl(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

CMyNewDl::~CMyNewDl()
{
}

void CMyNewDl::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CMyNewDl, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &CMyNewDl::OnBnClickedButton1)
END_MESSAGE_MAP()


// CMyNewDl 消息处理程序


void CMyNewDl::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}
