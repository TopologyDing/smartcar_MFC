// ShowVideo.cpp: 实现文件
//

#include "stdafx.h"
#include "smartcar.h"
#include "ShowVideo.h"


// ShowVideo

IMPLEMENT_DYNCREATE(ShowVideo, CView)

ShowVideo::ShowVideo()
{

}

ShowVideo::~ShowVideo()
{
}

BEGIN_MESSAGE_MAP(ShowVideo, CView)
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
END_MESSAGE_MAP()


// ShowVideo 绘图

void ShowVideo::OnDraw(CDC* pDC)
{
	CDocument* pDoc = GetDocument();
	// TODO:  在此添加绘制代码
}


// ShowVideo 诊断

#ifdef _DEBUG
void ShowVideo::AssertValid() const
{
	CView::AssertValid();
}

#ifndef _WIN32_WCE
void ShowVideo::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif
#endif //_DEBUG


// ShowVideo 消息处理程序


void ShowVideo::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags)
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


void ShowVideo::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags)
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
