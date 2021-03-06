// MyView2.cpp: 实现文件
//

#include "stdafx.h"
#include "smartcar.h"
#include "MyView2.h"
#include "MainFrm.h"
#include "sendDataToCar.h"

// MyView2

IMPLEMENT_DYNCREATE(MyView2, CView)

MyView2::MyView2()
{
	state_of_record = false;
}

MyView2::~MyView2()
{
}

BEGIN_MESSAGE_MAP(MyView2, CView)
	ON_WM_CREATE()
	ON_COMMAND_RANGE(IDC_STARTRECORDBTN, IDC_CLEARBTN, OnButtonClick)
	ON_MESSAGE(WM_MSGVIEW1, OnMyMsg1Handler)
//	ON_WM_KEYDOWN()
//	ON_WM_KEYUP()
ON_WM_KEYDOWN()
ON_WM_KEYUP()
END_MESSAGE_MAP()


// MyView2 绘图

void MyView2::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  在此添加绘制代码
}


// MyView2 诊断

#ifdef _DEBUG
void MyView2::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void MyView2::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// MyView2 消息处理程序


int MyView2::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;
	ShowPosition_X.Create(ES_READONLY|ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER,CRect(50,50,150,70), this, IDC_SHOWPOSITION_X);
	ShowPosition_X.ShowWindow(SW_SHOWNORMAL);
	ShowPosition_Y.Create(ES_READONLY|ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, CRect(50, 90, 150, 110), this, IDC_SHOWPOSITION_X);
	ShowPosition_Y.ShowWindow(SW_SHOWNORMAL);
	ShowDirection.Create(ES_READONLY | ES_MULTILINE | WS_CHILD | WS_VISIBLE | WS_TABSTOP | WS_BORDER, CRect(50, 130, 150, 150), this, IDC_SHOWDIRECTION);
	ShowDirection.ShowWindow(SW_SHOWNORMAL);
	startrecord_point.Create(_T("start"), BS_DEFPUSHBUTTON, CRect(50, 170, 150, 190), this, IDC_STARTRECORDBTN);
	startrecord_point.ShowWindow(SW_SHOWNORMAL);
	endrecord_point.Create(_T("stop"), BS_DEFPUSHBUTTON, CRect(50, 210, 150, 230), this, IDC_ENDRECORDBTN);
	endrecord_point.ShowWindow(SW_SHOWNORMAL);
	clear_point.Create(_T("clear"), BS_DEFPUSHBUTTON, CRect(50, 250, 150, 270), this, IDC_CLEARBTN);
	clear_point.ShowWindow(SW_SHOWNORMAL);
	return 0;
}

void MyView2::OnButtonClick(UINT uID)
{
	if (uID == IDC_STARTRECORDBTN)
		state_of_record = true;
	else if (uID == IDC_ENDRECORDBTN)
	{
		state_of_record = false;
		ShowPosition_X.SetWindowTextW(_T(""));
		ShowPosition_Y.SetWindowTextW(_T(""));
	}
	else if (uID == IDC_CLEARBTN)
	{
		CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
		MyView *pView = (MyView *)pFrame->m_wndSplitter.GetPane(0, 0);
		::SendMessage(*pView, WM_MSGCLR, 0, 0);
	}
	OnMyMsg1Handler(0,0);
}

LRESULT MyView2::OnMyMsg1Handler(WPARAM, LPARAM)
{
	if (state_of_record)
	{
		CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
		MyView *pView = (MyView *)pFrame->m_wndSplitter.GetPane(0, 0);
		ShowPosi_X(pView->currentpoint.x);
		ShowPosi_Y(pView->currentpoint.y);
	}
	return 0;
}

void MyView2::ShowPosi_X(int x)
{
	CString str;
	str.Format(_T("%d"), x);
	LPCTSTR pStr = LPCTSTR(str);
	ShowPosition_X.SetWindowTextW(pStr);
}

void MyView2::ShowPosi_Y(int y)
{
	CString str;
	str.Format(_T("%d"), y);
	LPCTSTR pStr = LPCTSTR(str);
	ShowPosition_Y.SetWindowTextW(pStr);
}


void MyView2::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	unsigned char cmd[] = { 0xff, 0x00, 0x00, 0x00, 0xff };
	switch (nChar)
	{
	case(VK_UP):
	{
		cmd[2] = 0x01;
		//sendDataToCar(cmd, 5);
		ShowDirection.SetWindowTextW(_T("FORWARD"));
		break;
	}
	case(VK_DOWN):
	{
		cmd[2] = 0x02;
		//sendDataToCar(cmd, 5);
		ShowDirection.SetWindowTextW(_T("BACKWARD"));
		break;
	}
	case(VK_LEFT):
	{
		cmd[2] = 0x04;
		//sendDataToCar(cmd, 5);
		ShowDirection.SetWindowTextW(_T("LEFT"));
		break;
	}
	case(VK_RIGHT):
	{
		cmd[2] = 0x03;
		//sendDataToCar(cmd, 5);
		ShowDirection.SetWindowTextW(_T("RIGHT"));
		break;
	}
	default:
		break;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void MyView2::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	unsigned char cmd[] = { 0xff, 0x00, 0x00, 0x00, 0xff };
	switch (nChar)
	{
	case(VK_UP):
	{
		//sendDataToCar(cmd, 5);
		ShowDirection.SetWindowTextW(_T("停止"));
		break;
	}
	case(VK_DOWN):
	{
		//sendDataToCar(cmd, 5);
		ShowDirection.SetWindowTextW(_T("停止"));
		break;
	}
	case(VK_LEFT):
	{
		//sendDataToCar(cmd, 5);
		ShowDirection.SetWindowTextW(_T("停止"));
		break;
	}
	case(VK_RIGHT):
	{
		//sendDataToCar(cmd, 5);
		ShowDirection.SetWindowTextW(_T("停止"));
		break;
	}
	default:
		break;
	}
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
