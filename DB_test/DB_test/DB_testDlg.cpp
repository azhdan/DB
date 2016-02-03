
// DB_testDlg.cpp : implementation file
//

#include "stdafx.h"
#include "DB_test.h"
#include "DB_testDlg.h"
#include "afxdialogex.h"
#include "atlstr.h"

#include "sqlite3.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CDB_testDlg dialog




CDB_testDlg::CDB_testDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CDB_testDlg::IDD, pParent), m_db(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDB_testDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, OrderReport);
	DDX_Control(pDX, IDC_LIST2, CustomerReport);
	DDX_Control(pDX, IDC_LIST3, ProviderReport);
	DDX_Control(pDX, IDC_LIST4, CommodityReport);
	DDX_Control(pDX, IDC_EDIT1, SQLEdit);
	DDX_Control(pDX, IDC_LIST7, CustomTable);
}

BEGIN_MESSAGE_MAP(CDB_testDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	
	ON_BN_CLICKED(IDC_BUTTON1, &CDB_testDlg::OnBnClickedButton1)
	ON_WM_CLOSE()
	ON_BN_CLICKED(IDC_BUTTON2, &CDB_testDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CDB_testDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CDB_testDlg message handlers

BOOL CDB_testDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	CommodityReport.InsertColumn(0, L"id", 0, 30);
	CommodityReport.InsertColumn(1, L"name", 0, 80);
	CommodityReport.InsertColumn(2, L"price", 0, 80);
	CommodityReport.InsertColumn(3, L"is_enable", 0, 80);

	ProviderReport.InsertColumn(0, L"id", 0, 30);
	ProviderReport.InsertColumn(1, L"name", 0, 80);
	ProviderReport.InsertColumn(2, L"contacts", 0, 80);
	


	CustomerReport.InsertColumn(0, L"id", 0, 30);
	CustomerReport.InsertColumn(1, L"name", 0, 80);
	CustomerReport.InsertColumn(2, L"mail", 0, 80);
	CustomerReport.InsertColumn(3, L"phone_number", 0, 80);

	

	OrderReport.InsertColumn(0, L"OrderId", 0, 80);
	OrderReport.InsertColumn(1, L"Order_date", 0, 80);
	OrderReport.InsertColumn(2, L"Count", 0, 80);
	OrderReport.InsertColumn(3, L"CustomerName", 0, 100);
	OrderReport.InsertColumn(4, L"CustomerMail", 0, 100);
	OrderReport.InsertColumn(5, L"CustomerPhoneNumber", 0, 100);
	OrderReport.InsertColumn(6, L"CommodityName", 0, 100);
	OrderReport.InsertColumn(7, L"CommodityPrice", 0, 100);
	OrderReport.InsertColumn(8, L"CommodityIsEnable", 0, 100);
	OrderReport.InsertColumn(9, L"ProviderName", 0, 100);
	OrderReport.InsertColumn(10, L"ProviderContact", 0, 100);
	
	//CommodityReport.SetColumn(0, &col);
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CDB_testDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDB_testDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CDB_testDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

static wchar_t* charToWChar(const char* text)
{
    size_t size = strlen(text) + 1;
    wchar_t* wa = new wchar_t[size];
    mbstowcs(wa,text,size);
    return wa;
}


static int callback(void *data, int argc, char **argv, char **azColName){
   int i;
   CListCtrl *pDBTable = (CListCtrl*)data;
   int count = pDBTable->GetItemCount();
   pDBTable->InsertItem(count, L"");
   for(i=0; i<argc; i++)
   {
	   LVCOLUMNW vcol;
	   if(!pDBTable->GetColumn(i,&vcol))
		   pDBTable->InsertColumn(i, charToWChar(azColName[i]), 0, 100);

		pDBTable->SetItemText(count, i, charToWChar(argv[i]));
   }
   
   return 0;
}

void CDB_testDlg::FillCustomerList()
{
	int rc;	
	char *sql;
	char *zErrMsg = 0;
     
	sql = "SELECT * from Customer";
	
	rc = sqlite3_exec(m_db, sql, callback, (void*)&CustomerReport, &zErrMsg);
	if( rc != SQLITE_OK )
	{
		MessageBox(L"SQL error:",L"DB error"); 	
		sqlite3_free(zErrMsg);
	}
	
}
void CDB_testDlg::FillOrderList()
{
	int rc;	
	char *sql;
	char *zErrMsg = 0;
     
	sql = "SELECT order_id,\
			   order_date,\
			   count,\
			   Customer.name,\
			   Customer.mail,\
			   Customer.phone_number,\
			   Commodity.name,\
			   Commodity.price,\
			   Commodity.is_enable,\
			   Provider.name,\
			   Provider.contact\
		   FROM Orders o\
			   LEFT JOIN\
			   Customer ON o.customer_id = Customer.id\
			   LEFT JOIN\
			   Commodity ON o.commodity_id = Commodity.id\
			   LEFT JOIN\
			   Provider ON o.provider_id = Provider.id";

	rc = sqlite3_exec(m_db, sql, callback, (void*)&OrderReport, &zErrMsg);
	if( rc != SQLITE_OK )
	{
		MessageBox(L"SQL error:",L"DB error"); 	
		sqlite3_free(zErrMsg);
	}
	
}
void CDB_testDlg::FillProviderList()
{
	int rc;	
	char *sql;
	char *zErrMsg = 0;
     
	sql = "SELECT * from Provider";
		
	rc = sqlite3_exec(m_db, sql, callback, (void*)&ProviderReport, &zErrMsg);
	if( rc != SQLITE_OK )
	{
		MessageBox(L"SQL error:",L"DB error"); 	
		sqlite3_free(zErrMsg);
	}
	
}
void CDB_testDlg::FillCommodityList()
{
	int rc;	
	char *sql;
	char *zErrMsg = 0;
     
	sql = "SELECT * from Commodity";

	rc = sqlite3_exec(m_db, sql, callback, (void*)&CommodityReport, &zErrMsg);
	if( rc != SQLITE_OK )
	{
		MessageBox(L"SQL error:",L"DB error"); 	
		sqlite3_free(zErrMsg);
	}
	
}

void CDB_testDlg::ConnectToDB()
{
	int rc;

	m_OrderDBManager.ConnectToDB("b:\\SQLiteStudio\\Demo_DB.db", "SqLite");
	
	m_OrderDBManager.GetOrders();
	
}

void CDB_testDlg::ExequtSQL(CString strSql)
{
	int rc;	
	char *zErrMsg = 0;
	BSTR str;
	CStringA sql(strSql.GetBuffer());

	

	rc = sqlite3_exec(m_db, sql.GetBuffer(), callback, (void*)&CustomTable, &zErrMsg);
	if( rc != SQLITE_OK )
	{
		MessageBox(L"SQL error:",L"DB error"); 	
		sqlite3_free(zErrMsg);
	}
	
}


void CDB_testDlg::OnBnClickedButton1()
{
	ConnectToDB();
	OrderReport.DeleteAllItems();
	CustomerReport.DeleteAllItems();
	ProviderReport.DeleteAllItems();
	CommodityReport.DeleteAllItems();
	CustomTable.DeleteAllItems();

	FillCommodityList();
	FillCustomerList();
	FillOrderList();
	FillProviderList();
}


void CDB_testDlg::OnClose()
{
	if(m_db)
		sqlite3_close(m_db);

	CDialogEx::OnClose();
}


void CDB_testDlg::OnBnClickedButton2()
{
	CString sql;
	SQLEdit.GetWindowTextW(sql);

	CustomTable.DeleteAllItems();
	int nColumnCount = CustomTable.GetHeaderCtrl()->GetItemCount();
	// Delete all of the columns.

	for ( int i = nColumnCount-1; i >= 0; i--)
   	{
		CustomTable.DeleteColumn(i);
	}
	
	ExequtSQL(sql);
	
}


void CDB_testDlg::OnBnClickedButton3()
{
	OrderReport.DeleteAllItems();
	CustomerReport.DeleteAllItems();
	ProviderReport.DeleteAllItems();
	CommodityReport.DeleteAllItems();

	CustomTable.DeleteAllItems();
	int nColumnCount = CustomTable.GetHeaderCtrl()->GetItemCount();
	// Delete all of the columns.

	for ( int i = nColumnCount-1; i >= 0; i--)
   	{
		CustomTable.DeleteColumn(i);
	}
	
	FillCommodityList();
	FillCustomerList();
	FillOrderList();
	FillProviderList();
}
