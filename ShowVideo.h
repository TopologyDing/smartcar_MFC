#pragma once

#include "MainFrm.h"
#include "MyView.h"
#include "MyView2.h"
// ShowVideo 视图

class ShowVideo : public CView
{
	DECLARE_DYNCREATE(ShowVideo)

protected:
	ShowVideo();           // 动态创建所使用的受保护的构造函数
	virtual ~ShowVideo();

public:
	virtual void OnDraw(CDC* pDC);      // 重写以绘制该视图
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};


