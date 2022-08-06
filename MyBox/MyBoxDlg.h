
// MyBoxDlg.h: 头文件

#pragma once
#include"Game.h"

// CMyBoxDlg 对话框
class CMyBoxDlg : public CDialogEx
{
// 构造
public:
	CMyBoxDlg(CWnd* pParent = nullptr);	// 标准构造函数

	enum { IDD = IDD_MYBOX_DIALOG };
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MYBOX_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
private:
	Game _game;
	void DrawBigNet();
	void DrawSmallNet();
	void OnKeyDown(UINT nChar);		//监听键盘输入函数
	BOOL OnEraseBkgnd(CDC* pDC);
	void ShowScore();
	void ShowLevel();
	void Upgrade();
	//void ShowHighScore();
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP();
public:
	afx_msg void OnClickedBPause();
	afx_msg void OnClickedBStart();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	afx_msg void OnClose();
	afx_msg void OnClickedBHelp();
	afx_msg void OnClickedStaticShowlevel();
	afx_msg void OnClickedStaticShowscore();
};
