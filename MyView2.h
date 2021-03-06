#pragma once

#include"MyView.h"
// MyView2 视图

class MyView2 : public CView
{
	DECLARE_DYNCREATE(MyView2)

protected:
	MyView2();           // 动态创建所使用的受保护的构造函数
	virtual ~MyView2();

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
	BOOL state_of_record;
	CEdit ShowPosition_X;
	CEdit ShowPosition_Y;
	CEdit ShowDirection;
	CButton startrecord_point;
	CButton endrecord_point;
	CButton clear_point;
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnButtonClick(UINT uID);
	afx_msg LRESULT OnMyMsg1Handler(WPARAM, LPARAM);
	void ShowPosi_X(int x);
	void ShowPosi_Y(int y);
//	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
//	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};


