// MyView.cpp: 实现文件
//

#include "stdafx.h"
#include "smartcar.h"
#include "MyView.h"
#include "MainFrm.h"

// MyView

IMPLEMENT_DYNCREATE(MyView, CView)

MyView::MyView()
{
	firstpoint.x = -1;
	firstpoint.y = -1;
	secondpoint.x = -1;
	secondpoint.y = -1;
	currentpoint.x = -1;
	currentpoint.y = -1;
	leftmousedown = false;
}

MyView::~MyView()
{
}

BEGIN_MESSAGE_MAP(MyView, CView)
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_MESSAGE(WM_MSGCLR, OnMyMsgCLR)
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()


// MyView 绘图

void MyView::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  在此添加绘制代码
}


// MyView 诊断

#ifdef _DEBUG
void MyView::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void MyView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// MyView 消息处理程序

void MyView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	leftmousedown = true;
	firstpoint = point;
	CView::OnLButtonDown(nFlags, point);
}


void MyView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	leftmousedown = false;
	CClientDC dc(this);
	CPen pen(PS_SOLID, 5, RGB(0, 0, 0));
	dc.SelectObject(pen);
	dc.MoveTo(firstpoint);
	dc.LineTo(point);
	firstpoint.x = -1;
	firstpoint.y = -1;
	CView::OnLButtonUp(nFlags, point);
}


void MyView::OnMouseMove(UINT nFlags, CPoint point)
{
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	MyView *pView = (MyView *)pFrame->subm_wndSplitter.GetPane(1,0);
	::SendMessage(*pView, WM_MSGVIEW1, 0, 0);
	currentpoint = point;
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	if (leftmousedown == true)
	{
		secondpoint = point;
		CClientDC dc(this);
		CPen pen(PS_SOLID, 5, RGB(0, 0, 0));
		dc.SelectObject(pen);
		dc.MoveTo(firstpoint);
		dc.LineTo(point);
		firstpoint = secondpoint;
	}
	CView::OnMouseMove(nFlags, point);
}

LRESULT MyView::OnMyMsgCLR(WPARAM, LPARAM)
{
	CRect rect;
	GetClientRect(&rect);
	InvalidateRect(&rect, TRUE);
	UpdateWindow();
	return 0;
}

int MyView::GetPoint_X()
{
	return firstpoint.x;
}

int MyView::GetPoint_Y()
{
	return firstpoint.y;
}

void MyView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	MyView2 *pView = (MyView2 *)pFrame->subm_wndSplitter.GetPane(1, 0);
	unsigned char cmd[] = { 0xff, 0x00, 0x00, 0x00, 0xff };
	switch (nChar)
	{
	case(VK_UP):
	{
		cmd[2] = 0x01;
		//sendDataToCar(cmd, 5);
		pView->ShowDirection.SetWindowTextW(_T("FORWARD"));
		break;
	}
	case(VK_DOWN):
	{
		cmd[2] = 0x02;
		//sendDataToCar(cmd, 5);
		pView->ShowDirection.SetWindowTextW(_T("BACKWARD"));
		break;
	}
	case(VK_LEFT):
	{
		cmd[2] = 0x04;
		//sendDataToCar(cmd, 5);
		pView->ShowDirection.SetWindowTextW(_T("LEFT"));
		break;
	}
	case(VK_RIGHT):
	{
		cmd[2] = 0x03;
		//sendDataToCar(cmd, 5);
		pView->ShowDirection.SetWindowTextW(_T("RIGHT"));
		break;
	}
	default:
		break;
	}
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}


void MyView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CMainFrame *pFrame = (CMainFrame *)AfxGetMainWnd();
	MyView2 *pView = (MyView2 *)pFrame->subm_wndSplitter.GetPane(1, 0);
	unsigned char cmd[] = { 0xff, 0x00, 0x00, 0x00, 0xff };
	switch (nChar)
	{
	case(VK_UP):
	{
		//sendDataToCar(cmd, 5);
		pView->ShowDirection.SetWindowTextW(_T("停止"));
		break;
	}
	case(VK_DOWN):
	{
		//sendDataToCar(cmd, 5);
		pView->ShowDirection.SetWindowTextW(_T("停止"));
		break;
	}
	case(VK_LEFT):
	{
		//sendDataToCar(cmd, 5);
		pView->ShowDirection.SetWindowTextW(_T("停止"));
		break;
	}
	case(VK_RIGHT):
	{
		//sendDataToCar(cmd, 5);
		pView->ShowDirection.SetWindowTextW(_T("停止"));
		break;
	}
	default:
		break;
	}
	CView::OnKeyUp(nChar, nRepCnt, nFlags);
}
