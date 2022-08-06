
// MyBoxDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "MyBox.h"
#include "MyBoxDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
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


// CMyBoxDlg 对话框



CMyBoxDlg::CMyBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CMyBoxDlg::IDD, pParent), _game(20, 12)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMyBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

void CMyBoxDlg::DrawBigNet()
{
	CRect rect;
	//IDC_PIC_MAIN是游戏窗口的ID，wnd是指向游戏窗口的一个指针
	CWnd* wnd = GetDlgItem(IDC_PIC_MAIN);	//若这里找不到对应的控件ID，则重启一下VS即可
	CPaintDC dc_real(wnd);
	wnd->GetClientRect(&rect);				//获取指定控件的大小

	_game.AddToolToAux(_game._bigNetAux, _game._iLocX, _game._iLocY, _game._tool);
	const COLORREF  colorTableA[] = { RGB(255, 0, 0), RGB(0, 255, 0), RGB(0, 0, 255),
		RGB(255, 255, 0), RGB(160, 32, 240),RGB(128, 60, 128),RGB(0, 128, 0),RGB(255, 0, 128),
		RGB(0, 128, 128),RGB(128, 128, 255), RGB(128, 0, 64),RGB(255, 128, 0) };
	int* pAuxBigNet = _game._bigNetAux;

	auto pDC = wnd->GetDC();
	CDC dc;
	dc.CreateCompatibleDC(NULL);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	dc.SelectObject(&bmp);
	dc.FillSolidRect(rect, pDC->GetBkColor());

	for (int i = 0; i < _game._netHeight; i++)
		for (int j = 0; j < _game._netWidth; j++) {
			//画矩形，所有不等于0的格子把矩形边框都画出来
			int iType = pAuxBigNet[i * (_game._netWidth) + j];
			if (iType > 0 && iType <= 12) 
			{
				//CClientDC dcc(wnd);		//画无边框的矩形
				CBrush brush(colorTableA[iType - 1]);
				dc.FillRect(CRect(j * rect.Width() / _game._netWidth,
					i * rect.Height() / _game._netHeight,
					(j + 1) * rect.Width() / _game._netWidth,
					(i + 1) * rect.Height() / _game._netHeight), &brush);

				//画中心为透明的矩形（空笔刷）
				CBrush* pBrush = CBrush::FromHandle((HBRUSH)GetStockObject(NULL_BRUSH));
				CBrush* pOldBrush = dc.SelectObject(pBrush);  //选入画刷
				dc.Rectangle(//加黑边
					j * rect.Width() / _game._netWidth,
					i * rect.Height() / _game._netHeight,
					(j + 1) * rect.Width() / _game._netWidth,
					(i + 1) * rect.Height() / _game._netHeight);
				dc.SelectObject(pOldBrush);
			}
		}

	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);
	dc.DeleteDC();
	bmp.DeleteObject();
	ReleaseDC(pDC);
	wnd->RedrawWindow();
}

void CMyBoxDlg::DrawSmallNet()
{
	Tool &next_tool = _game._nextTool;
	int type = next_tool.GetType();
	if (type == 0)
		return;

	CRect rect;
	//IDC_PIC_SMALL是显示下一个的窗口
	CWnd *wnd = GetDlgItem(IDC_PIC_SMALL);
	CPaintDC dc_real(wnd);
	wnd->GetClientRect(&rect);
	//CClientDC dcc(wnd);
	const COLORREF  colorTableA[] = { RGB(255, 0, 0), RGB(0, 255, 0), RGB(0, 0, 255),
		RGB(255, 255, 0), RGB(160, 32, 240),RGB(128, 60, 128),RGB(0, 128, 0),RGB(255, 0, 128),
		RGB(0, 128, 128),RGB(128, 128, 255), RGB(128, 0, 64),RGB(255, 128, 0) };
	
	auto pDC = wnd->GetDC();
	CDC dc;
	dc.CreateCompatibleDC(NULL);
	CBitmap bmp;
	bmp.CreateCompatibleBitmap(pDC, rect.Width(), rect.Height());
	dc.SelectObject(&bmp);
	dc.FillSolidRect(rect, pDC->GetBkColor());

	CBrush brush(colorTableA[type - 1]);
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			if (next_tool.ElementAt(i, j) != 0) {
				dc.FillRect(CRect(j*rect.Width() / 4,
					i*rect.Height() / 4,
					(j + 1)*rect.Width() / 4,
					(i + 1)*rect.Height() / 4), &brush);

				CBrush *pBrush = CBrush::FromHandle((HBRUSH)
					GetStockObject(NULL_BRUSH));
				CBrush *pOldBrush = dc.SelectObject(pBrush); //选入画刷
				dc.Rectangle(j*rect.Width() / 4,i*rect.Height() / 4,(j + 1)*rect.Width() / 4,(i + 1)*rect.Height() / 4);
				dc.SelectObject(pOldBrush);                  //恢复原先画刷
			}
		}

	pDC->BitBlt(0, 0, rect.Width(), rect.Height(), &dc, 0, 0, SRCCOPY);
	dc.DeleteDC();
	bmp.DeleteObject();
	ReleaseDC(pDC);
	wnd->RedrawWindow();
}

BEGIN_MESSAGE_MAP(CMyBoxDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BSTART, &CMyBoxDlg::OnClickedBStart)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_BPAUSE, &CMyBoxDlg::OnClickedBPause)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BHELP, &CMyBoxDlg::OnClickedBHelp)
	ON_STN_CLICKED(IDC_STATIC_SHOWLEVEL, &CMyBoxDlg::OnClickedStaticShowlevel)
	ON_STN_CLICKED(IDC_STATIC_SHOWSCORE, &CMyBoxDlg::OnClickedStaticShowscore)
END_MESSAGE_MAP()


// CMyBoxDlg 消息处理程序

BOOL CMyBoxDlg::OnInitDialog()
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

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMyBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMyBoxDlg::OnPaint()
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
		CPaintDC  dc(this);			// 响应一个WM_PAINT消息的时候被使用
		CRect  rect;				// 新建一个画布
		GetClientRect(&rect);		// 获得控件大小
		CDC  dcMem;
		dcMem.CreateCompatibleDC(&dc); // 创建一个与dc相容的上下文环境
		CBitmap  bmpBackground;
		bmpBackground.LoadBitmap(IDB_BMP_BACKGROUND);//自己的图对应的ID  
		BITMAP  bitmap;
		bmpBackground.GetBitmap(&bitmap);
		CBitmap* pbmpOld = dcMem.SelectObject(&bmpBackground); // 用bmpBackground替换原来同类型的值
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcMem, 0, 0, bitmap.bmWidth, bitmap.bmHeight, SRCCOPY); // 这个函数对图片进行缩放，这里使用的是填充

		DrawSmallNet();	//绘制下一个方块界面
		DrawBigNet();	//绘制游戏界面
		
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标显示。
HCURSOR CMyBoxDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMyBoxDlg::OnClickedBStart()
{
	if (_game._state == GO)
		KillTimer(1);

	_game.Start();
	SetTimer(1, 500, NULL); //1号定时器500ms(调整下落速度)
}


void CMyBoxDlg::OnTimer(UINT_PTR nIDEvent)
{
	if (!_game.Go())
	{
		KillTimer(1);
		TCHAR* msg = _T("Game Over!");
		MessageBox(msg);
		//ShowHighScore()；
	}
	else
	{
		ShowScore();
		ShowLevel();
		DrawBigNet();
		DrawSmallNet();
	}
	//Invalidate(true);
}

void CMyBoxDlg::OnClickedBPause()
{
	// TODO:  在此添加控件通知处理程序代码
	CWnd* wnd = GetDlgItem(IDC_PIC_MAIN);

	_game.PauseOrContinue();
	//ID为1的定时器失效
	if (_game._state == PAUSE)
	{
		KillTimer(1);
		wnd->ShowWindow(FALSE);
	}
	//ID为1的定时器启用，时间间隔为500毫秒
	if (_game._state == GO)
	{
			SetTimer(1, 500, NULL);
			wnd->ShowWindow(TRUE);
	}
}


BOOL CMyBoxDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO:  在此添加专用代码和/或调用基类

	if (pMsg->message == WM_KEYDOWN) {
		OnKeyDown((UINT)pMsg->wParam);
		return true;
	}

	return CDialogEx::PreTranslateMessage(pMsg);
}

void CMyBoxDlg::OnKeyDown(UINT nChar) {
	if (_game._state == GO)
		_game.Input(nChar);
	if (nChar == VK_SPACE) 
	{
		OnClickedBPause();
	}
	
	//ShowScore();
	//ShowLevel();
	
	DrawBigNet();
	DrawSmallNet();// 重绘画面
	 
	//Invalidate(true);
}

void CMyBoxDlg::OnClose()
{
	if (_game._state == GO)
		KillTimer(1);

	CDialogEx::OnClose();
}


BOOL CMyBoxDlg::OnEraseBkgnd(CDC* pDC) //减少频闪？
{
	//return CMyBoxDlg::OnEraseBkgnd(pDC);
	return true;
}

void CMyBoxDlg::ShowScore()
{
	CString score_str;
	score_str.Format(L"%d", _game._score);
	UpdateData(true);
	GetDlgItem(IDC_STATIC_SHOWSCORE)->SetWindowTextW(score_str);
}

void CMyBoxDlg::ShowLevel()
{
	CString level_str;
	level_str.Format(L"%d", _game._level);
	UpdateData(true);
	GetDlgItem(IDC_STATIC_SHOWLEVEL)->SetWindowTextW(level_str);

	_game._interval = 501-(_game._level-1)*50;
	//SetTimer(1, _game._interval, NULL);
	Upgrade();
}

void CMyBoxDlg::Upgrade()
{
	if (_game._state == GO)
		KillTimer(1);

	SetTimer(1, _game._interval, NULL);
}

void CMyBoxDlg::OnClickedBHelp()
{
	// TODO: 在此添加控件通知处理程序代码
	MessageBox(L"玩俄罗斯方块还需要帮助？？？\n\n#[终极版]做出了一些优化：\n1.解决了重新开始时的速度不会恢复至初始值的问题；\n2.解决了旋转时方块不会下落的问题；\n3.暂停游戏时会屏蔽画面以防止作弊.\n\n#积分规则如下：\n1.一次消一行得100分；\n2.一次连消n行得100+200+···+n*100分；\n3.Level每500分升一级，最高Level 11；\n4.为了不使玩家怀疑自己的智商，一行不足两格即可消去.");
}

void CMyBoxDlg::OnClickedStaticShowlevel()
{
	// TODO: 在此添加控件通知处理程序代码
}


void CMyBoxDlg::OnClickedStaticShowscore()
{
	// TODO: 在此添加控件通知处理程序代码
}
