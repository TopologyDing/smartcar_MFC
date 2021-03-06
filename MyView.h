#pragma once
#ifndef MYVIEW
#define MYVIEW

// MyView 视图

class MyView : public CView
{
	DECLARE_DYNCREATE(MyView)

protected:
	MyView();           // 动态创建所使用的受保护的构造函数
	virtual ~MyView();

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
	CPoint firstpoint;
	CPoint secondpoint;
	CPoint currentpoint;
	bool leftmousedown;

	int GetPoint_X();
	int GetPoint_Y();

	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg LRESULT OnMyMsgCLR(WPARAM, LPARAM);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
};

#endif // !MYVIEW
