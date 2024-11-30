
// txlprojectDlg.cpp: 实现文件
//

#include<string>
#include "pch.h"
#include "framework.h"
#include "txlproject.h"
#include "txlprojectDlg.h"
#include "afxdialogex.h"
#include "ChildDlg.h"
#include"CMyNewDl.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

extern "C"
{
	int WINAPI MessageBoxTimeoutA(IN HWND hWnd, IN LPCSTR lpText, IN LPCSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);
	int WINAPI MessageBoxTimeoutW(IN HWND hWnd, IN LPCWSTR lpText, IN LPCWSTR lpCaption, IN UINT uType, IN WORD wLanguageId, IN DWORD dwMilliseconds);
};
#ifdef UNICODE
#define MessageBoxTimeout MessageBoxTimeoutW
#else
#define MessageBoxTimeout MessageBoxTimeoutA
#endif


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


// CtxlprojectDlg 对话框



CtxlprojectDlg::CtxlprojectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TXLPROJECT_DIALOG, pParent)
	, m_find(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtxlprojectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_find);
}

BEGIN_MESSAGE_MAP(CtxlprojectDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CtxlprojectDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON5, &CtxlprojectDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CtxlprojectDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON2, &CtxlprojectDlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT1, &CtxlprojectDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON3, &CtxlprojectDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CtxlprojectDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON7, &CtxlprojectDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CtxlprojectDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CtxlprojectDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CtxlprojectDlg::OnBnClickedButton10)
END_MESSAGE_MAP()


// CtxlprojectDlg 消息处理程序

BOOL CtxlprojectDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	//设置风格
	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;
	dwStyle |= LVS_EX_GRIDLINES;
	m_list.SetExtendedStyle(dwStyle);

	m_list.InsertColumn(0, TEXT("编号"), 0, 100);
	m_list.InsertColumn(1, TEXT("姓名"), 0, 100);
	m_list.InsertColumn(2, TEXT("电话号码"), 0, 200);
	m_list.InsertColumn(3, TEXT("家庭电话"), 0, 200);
	m_list.InsertColumn(4, TEXT("办公电话"), 0, 200);
	m_list.InsertColumn(5, TEXT("电子邮件"), 0, 250);
	m_list.InsertColumn(6, TEXT("分组"), 0, 100);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CtxlprojectDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CtxlprojectDlg::OnPaint()
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
HCURSOR CtxlprojectDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtxlprojectDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	ChildDlg dlg;
	if (IDOK == dlg.DoModal())
	{
		Member Mem(dlg.m_name.GetBuffer(), dlg.m_phone.GetBuffer(), dlg.m_family_phone.GetBuffer(), dlg.m_office_phone.GetBuffer(), dlg.m_e_mail.GetBuffer(), dlg.m_group.GetBuffer());
		DataInterface.Add(Mem);
		UpdateList();
	}
}


void CtxlprojectDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	//设置过滤器
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	//构造打开文本对话框
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);

	//显示打开文件对话框
	if (IDOK == fileDlg.DoModal())
	{
		strFilepath = fileDlg.GetPathName();
		DataInterface.Open(strFilepath);
		UpdateList();
	}

}

void CtxlprojectDlg::UpdateList()
{
	m_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < DataInterface.Mem.size(); i++)
	{
		str.Format(TEXT("%d"), i+1);
		m_list.InsertItem(i,str);
		str.Format(TEXT("%s"), DataInterface.Mem[i].m_name.c_str());
		m_list.SetItemText(i,1,str);
		str.Format(TEXT("%s"), DataInterface.Mem[i].m_phone.c_str());
		m_list.SetItemText(i, 2, str);
		str.Format(TEXT("%s"), DataInterface.Mem[i].m_family_phone.c_str());
		m_list.SetItemText(i, 3, str);
		str.Format(TEXT("%s"), DataInterface.Mem[i].m_office_phone.c_str());
		m_list.SetItemText(i, 4, str);
		str.Format(TEXT("%s"), DataInterface.Mem[i].m_e_mail.c_str());
		m_list.SetItemText(i, 5, str);
		str.Format(TEXT("%s"), DataInterface.Mem[i].m_group.c_str());
		m_list.SetItemText(i, 6, str);
	}
}


void CtxlprojectDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_list.GetSelectionMark();

	if (index > -1)
	{
		UINT i;
		i = MessageBox(_T("确定要删除该联系人吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			DataInterface.Del(index);
			UpdateList();
			MessageBox(TEXT("删除成功"), TEXT("提示!"));
		}
		else
			return;
	}
	else
	{
		MessageBox(TEXT("请先点击列表选择需要删除的联系人"),TEXT("提示!"));
	}
}


void CtxlprojectDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_list.GetSelectionMark();

	if (index > -1)
	{
		ChildDlg dlg;
		CString str;
		str.Format(TEXT("%s"), DataInterface.Mem[index].m_name.c_str());
		dlg.m_name = str;
		str.Format(TEXT("%s"), DataInterface.Mem[index].m_phone.c_str());
		dlg.m_phone = str;
		str.Format(TEXT("%s"), DataInterface.Mem[index].m_family_phone.c_str());
		dlg.m_family_phone = str;
		str.Format(TEXT("%s"), DataInterface.Mem[index].m_office_phone.c_str());
		dlg.m_office_phone = str;
		str.Format(TEXT("%s"), DataInterface.Mem[index].m_e_mail.c_str());
		dlg.m_e_mail = str;
		str.Format(TEXT("%s"), DataInterface.Mem[index].m_group.c_str());
		dlg.m_group = str;
		if (IDOK == dlg.DoModal())
		{
			Member Mem(dlg.m_name.GetBuffer(), dlg.m_phone.GetBuffer(), dlg.m_family_phone.GetBuffer(), dlg.m_office_phone.GetBuffer(), dlg.m_e_mail.GetBuffer(), dlg.m_group.GetBuffer());
			DataInterface.Amend(index,Mem);
			UpdateList();
			
		}
	}
	else
	{
		MessageBox(TEXT("请先点击列表选择需要修改的联系人"), TEXT("提示!"));
	}

}


void CtxlprojectDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CtxlprojectDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Member FindMem=DataInterface.Search(m_find.GetBuffer());
	if (FindMem.m_name == TEXT(""))
		MessageBox("查无此联系人",TEXT("提示"));
	else
	{
		CString str;
		str.Format(TEXT("查找成功！\n\n姓名：%s\n电话号码：%s\n家庭电话：%s\n办公电话：%s\n电子邮件：%s\n分组：%s\n"), FindMem.m_name.c_str(),  FindMem.m_phone.c_str(), FindMem.m_family_phone.c_str(), FindMem.m_office_phone.c_str(), FindMem.m_e_mail.c_str(), FindMem.m_group.c_str());
		MessageBox(str, TEXT("提示"));
	}

}


void CtxlprojectDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	if(DataInterface.Save(strFilepath))
	MessageBox(TEXT("保存成功！"), TEXT("提示"));
	else
		MessageBox(TEXT("保存失败！"), TEXT("提示"));
}


void CtxlprojectDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CtxlprojectDlg::OnBnClickedButton8()
{
	int index = m_list.GetSelectionMark();
	if (index > -1) {
		UINT i;
		i = MessageBox(_T("确认拨打"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES) {

			for (int i = 2; i < 13; i++)
			{
				CString str;
				str.Format(TEXT(" % s"), DataInterface.Mem[index].m_phone.c_str());
				CString str1 = ("正在拨打" + str.Left(i) + "....");
				int result = MessageBoxTimeout(NULL, TEXT(str1), TEXT("提示"), MB_OKCANCEL, 0, 1 * 1000);


			}
			MessageBox(TEXT("接通失败！！"), TEXT("提示"));
		}
		else {
			return;
		}
	}
	else {
		MessageBox(TEXT("请选择拨打的用户！"), TEXT("提示"));
	}
}



void CtxlprojectDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	CMyNewDl  Dlg;
	Dlg.DoModal();
}


void CtxlprojectDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = m_list.GetSelectionMark();
	Member* FindMem = DataInterface.Find(index);
	if (FindMem[0].m_name == TEXT(""))
	MessageBox("请先选中一个分组", TEXT("提示"));
	else
	{
		CString str,stra;
		stra.Empty();
		str.Format(TEXT("%s分组下有：\n"), FindMem[0].m_group.c_str());
			stra += str;
		for (int i = 0; FindMem[i].m_name != TEXT(""); i++)
		{
			str.Format(TEXT("\n\n姓名：%s\n电话号码：%s\n"), FindMem[i].m_name.c_str(), FindMem[i].m_phone.c_str());
			stra += str;
			
		}
       MessageBox(stra, TEXT("提示"));
	}
}
