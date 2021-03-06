
// smartcarView.cpp: CsmartcarView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "smartcar.h"
#endif

#include "smartcarDoc.h"
#include "smartcarView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CsmartcarView

IMPLEMENT_DYNCREATE(CsmartcarView, CView)

BEGIN_MESSAGE_MAP(CsmartcarView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CsmartcarView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
//	ON_WM_LBUTTONDOWN()
//	ON_WM_LBUTTONUP()
//	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()

// CsmartcarView 构造/析构

CsmartcarView::CsmartcarView()
{
	// TODO: 在此处添加构造代码
}

CsmartcarView::~CsmartcarView()
{
}

BOOL CsmartcarView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CsmartcarView 绘图

void CsmartcarView::OnDraw(CDC* /*pDC*/)
{
	CsmartcarDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CsmartcarView 打印


void CsmartcarView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CsmartcarView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CsmartcarView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CsmartcarView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CsmartcarView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CsmartcarView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CsmartcarView 诊断

#ifdef _DEBUG
void CsmartcarView::AssertValid() const
{
	CView::AssertValid();
}

void CsmartcarView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CsmartcarDoc* CsmartcarView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CsmartcarDoc)));
	return (CsmartcarDoc*)m_pDocument;
}
#endif //_DEBUG


// CsmartcarView 消息处理程序

