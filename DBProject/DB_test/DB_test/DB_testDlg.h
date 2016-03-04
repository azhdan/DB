
// DB_testDlg.h : header file
//

#pragma once
#include "afxcmn.h"
#include "afxwin.h"
#include "OrderDBManager.h"


// CDB_testDlg dialog
class sqlite3;
class CDB_testDlg : public CDialogEx
{
// Construction
public:
	CDB_testDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_DB_TEST_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	
	CListCtrl OrderReport;
	CListCtrl CustomerReport;
	CListCtrl ProviderReport;
	CListCtrl CommodityReport;
	CListCtrl CustomTable;
	afx_msg void OnBnClickedButton1();
	void FillCommodityList();
	void FillCustomerList();
	void FillOrderList();
	void FillProviderList();
	void ConnectToDB();
	sqlite3 *m_db;
	afx_msg void OnClose();
	CEdit SQLEdit;
	afx_msg void OnBnClickedButton2();
	void ExequtSQL(CString sql);
	afx_msg void OnBnClickedButton3();
	OrderDBManager m_OrderDBManager;
};
