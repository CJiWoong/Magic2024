// (C) Copyright 1998-2007 by Autodesk, Inc.
//
// Permission to use, copy, modify, and distribute this software in
// object code form for any purpose and without fee is hereby granted,
// provided that the above copyright notice appears in all copies and
// that both that copyright notice and the limited warranty and
// restricted rights notice below appear in all supporting
// documentation.
//
// AUTODESK PROVIDES THIS PROGRAM "AS IS" AND WITH ALL FAULTS.
// AUTODESK SPECIFICALLY DISCLAIMS ANY IMPLIED WARRANTY OF
// MERCHANTABILITY OR FITNESS FOR A PARTICULAR USE.  AUTODESK, INC.
// DOES NOT WARRANT THAT THE OPERATION OF THE PROGRAM WILL BE
// UNINTERRUPTED OR ERROR FREE.
//
// Use, duplication, or disclosure by the U.S. Government is subject to
// restrictions set forth in FAR 52.227-19 (Commercial Computer
// Software - Restricted Rights) and DFAR 252.227-7013(c)(1)(ii)
// (Rights in Technical Data and Computer Software), as applicable.
//
// MDITestDialog.cpp : implementation file
//
#include "stdafx.h"

//#if defined(_DEBUG) && !defined(AC_FULL_DEBUG)
//#error _DEBUG should not be defined except in internal Adesk debug builds
//#endif

#include "gcdocman.h"
#include "MDITestDialog.h"
#include "common.h"



#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern "C" HWND adsw_acadMainWnd();
extern boolean endDlg();

/////////////////////////////////////////////////////////////////////////////
// MDITestDialog message handlers
/////////////////////////////////////////////////////////////////////////////
// CMDITestDialog dialog


CMDITestDialog::CMDITestDialog(CWnd* pParent /*=NULL*/)
    : CDialog(CMDITestDialog::IDD, pParent)
{
    //{{AFX_DATA_INIT(CMDITestDialog)
    //}}AFX_DATA_INIT
}


void CMDITestDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    //{{AFX_DATA_MAP(CMDITestDialog)
    DDX_Control(pDX, IDC_ACT_MYLK_STATUS_FIELD_STATIC, m_staticActDocMyLockStatus);
    DDX_Control(pDX, IDC_CURDOC_FIELD_STATIC, m_staticCurrentDoc);
    DDX_Control(pDX, IDC_CUR_LK_STATUS_FIELD_STATIC, m_staticCurDocLockStatus);
    DDX_Control(pDX, IDC_CUR_MYLK_STATUS_FIELD_STATIC, m_staticCurDocMyLockStatus);
    DDX_Control(pDX, IDC_ACT_LK_STATUS_FIELD_STATIC, m_staticActDocLockStatus);
    DDX_Control(pDX, IDC_LOCK_COMBO, m_lockCombo);
    DDX_Control(pDX, IDC_ACTIVEDOC_FIELD_STATIC, m_staticActiveDoc);
    DDX_Control(pDX, IDC_TOBECURRDOC_FIELD_STATIC, m_staticToBeCurrDoc);
    DDX_Control(pDX, IDC_ACTIVATION_CHECK, m_activationCheck);
    DDX_Control(pDX, IDC_NUMDOCS_STATIC, m_staticDocNum);
    DDX_Control(pDX, IDC_DOC_LIST, m_docListBox);
    //}}AFX_DATA_MAP
}

#ifndef WM_GCAD_UPDATEDIALOG
#define WM_GCAD_UPDATEDIALOG       (WM_ACAD_MFC_BASE + 2)
#endif

#ifndef WM_GCAD_CREATEDOC
#define WM_GCAD_CREATEDOC	       (WM_ACAD_MFC_BASE + 3)
#endif

#ifndef WM_GCAD_DESTROYDOC
#define WM_GCAD_DESTROYDOC	       (WM_ACAD_MFC_BASE + 4)
#endif

#ifndef WM_GCAD_LOCKMODCHANGED
#define WM_GCAD_LOCKMODCHANGED     (WM_ACAD_MFC_BASE + 5)
#endif

#ifndef WM_GCAD_LOCKMODWILLCHANGE
#define WM_GCAD_LOCKMODWILLCHANGE  (WM_ACAD_MFC_BASE + 6)
#endif

#ifndef WM_GCAD_CURRENTDOC
#define WM_GCAD_CURRENTDOC	       (WM_ACAD_MFC_BASE + 7)
#endif

#ifndef WM_GCAD_ACTIVATEDOC
#define WM_GCAD_ACTIVATEDOC	       (WM_ACAD_MFC_BASE + 8)
#endif

#ifndef WM_GCAD_DEACTIVATEDOC
#define WM_GCAD_DEACTIVATEDOC	   (WM_ACAD_MFC_BASE + 9)
#endif

#ifndef WM_GCAD_ACTMODIFIED
#define WM_GCAD_ACTMODIFIED	       (WM_ACAD_MFC_BASE + 10)
#endif

BEGIN_MESSAGE_MAP(CMDITestDialog, CDialog)
    ON_MESSAGE( WM_GCAD_KEEPFOCUS, onAcadKeepFocus )
    ON_MESSAGE( WM_GCAD_UPDATEDIALOG, onAcadUpdateDialog )
    ON_MESSAGE( WM_GCAD_CREATEDOC, onAcadCreateDoc )
    ON_MESSAGE( WM_GCAD_DESTROYDOC, onAcadDestroyDoc )
    ON_MESSAGE( WM_GCAD_LOCKMODCHANGED, onAcadLockModeChanged )
    ON_MESSAGE( WM_GCAD_LOCKMODWILLCHANGE, onAcadLockModeWillChange )
    ON_MESSAGE( WM_GCAD_CURRENTDOC, onAcadCurrDoc )
    ON_MESSAGE( WM_GCAD_ACTIVATEDOC, onAcadActivateDoc )
    ON_MESSAGE( WM_GCAD_DEACTIVATEDOC, onAcadDeactivateDoc )
    ON_MESSAGE( WM_GCAD_ACTMODIFIED, onAcadActModifiedDoc )
	ON_WM_CLOSE()
    //{{AFX_MSG_MAP(CMDITestDialog)
    ON_BN_CLICKED(IDC_NEWDOC_BUTTON, OnNewdocButton)
    ON_BN_CLICKED(IDC_APPNEWDOC_BUTTON, OnAppnewdocButton)
    ON_BN_CLICKED(IDC_APPOPENDOC_BUTTON, OnAppopendocButton)
    ON_BN_CLICKED(IDC_ACTIVATION_CHECK, OnActivationCheck)
    ON_BN_CLICKED(IDC_SENDSTRING_BUTTON, OnSendstringButton)
    ON_BN_CLICKED(IDC_OPENDOC_BUTTON, OnOpendocButton)
    ON_BN_CLICKED(IDC_ISQUIESCENT_BUTTON, OnIsquiescentButton)
    ON_BN_CLICKED(IDC_CLOSEDOC_BUTTON, OnClosedocButton)
    ON_BN_CLICKED(IDC_ACTIVATEDOC_BUTTON, OnActivatedocButton)
    ON_BN_CLICKED(IDC_SETCURRENTDOC_BUTTON, OnSetcurrentdocButton)
    ON_BN_CLICKED(ID_REFRESH_BUTTON, OnRefreshButton)
    //}}AFX_MSG_MAP
END_MESSAGE_MAP()



/////////////////////////////////////////////////////////////////////////////
// CMDITestDialog message handlers

BOOL CMDITestDialog::Create( CWnd* pParent )
{
    // TODO: Add your specialized code here and/or call the base class
    
    return CDialog::Create(CMDITestDialog::IDD, pParent);
}

//    This function gets called repeatedly whenever the mouse is moved over
//    the AutoCAD window.
//
LRESULT CMDITestDialog::onAcadKeepFocus( WPARAM, LPARAM )
{
    return TRUE;
}

LRESULT CMDITestDialog::onAcadUpdateDialog( WPARAM, LPARAM )
{
    // update elements of the dialog to reflect the current
    // state of the documents

    // get the current number of documents
    m_staticDocNum.SetWindowText( getDocCount() );

    // check/uncheck document activation
    m_activationCheck.SetCheck( gcDocManager->isDocumentActivationEnabled() );

    // set the current document fields
    CString fName;
    GcApDocument *pCurrDoc = gcDocManager->curDocument();
    if( pCurrDoc ) {
        fName = pCurrDoc->docTitle();
        m_staticCurrentDoc.SetWindowText(fName);
        m_staticToBeCurrDoc.SetWindowText(fName);
        m_staticCurDocLockStatus.SetWindowText( modeStr(pCurrDoc->lockMode()) );
        m_staticCurDocMyLockStatus.SetWindowText( modeStr(pCurrDoc->myLockMode()) );
    }
    else {
        m_staticCurrentDoc.SetWindowText(fName);
        m_staticToBeCurrDoc.SetWindowText(_T(""));
        m_staticCurDocLockStatus.SetWindowText(_T(""));
        m_staticCurDocMyLockStatus.SetWindowText(_T(""));
    }

    // set the active document data
    GcApDocument *pActDoc = gcDocManager->mdiActiveDocument();

    if( pActDoc ) {
        // active document name
        fName = pActDoc->docTitle();
        m_staticActiveDoc.SetWindowText(fName);
        // active document lock modes
        m_staticActDocLockStatus.SetWindowText( modeStr(pActDoc->lockMode()) );
        m_staticActDocMyLockStatus.SetWindowText( modeStr(pActDoc->myLockMode()) );
    }
    else {
        m_staticActiveDoc.SetWindowText(_T(""));
        m_staticActDocLockStatus.SetWindowText(_T(""));
        m_staticActDocMyLockStatus.SetWindowText(_T(""));
    }

    // rebuild listbox
    RebuildListBox();
	return TRUE;
}



///////////////////////////////////////////////////////////////
// Note: here you could do different actions for each reactor
// intercepted. For this sample I use a brute force approach:
// everything just updates the ui (with few exceptions)
///////////////////////////////////////////////////////////////
LRESULT CMDITestDialog::onAcadCreateDoc ( WPARAM, LPARAM )
{
    onAcadUpdateDialog(0,0L);
	return TRUE;
}


LRESULT CMDITestDialog::onAcadDestroyDoc ( WPARAM, LPARAM )
{
    // if we went to 0 doc state, clean all the pertinent 
    // ui elememnts of the dialog. Note however, that this function is
    // activated upon SendMessage (instead of PostMessage) so the document
    // count right here is still one more than the end result.
    // That's why 1 is subtracked from nDoc in the comparison.
    int nDoc = gcDocManager->documentCount();
    if( 0 == nDoc - 1 )
        cleanUpUI();
    else
        onAcadUpdateDialog(0,0L);
	return TRUE;
}


LRESULT CMDITestDialog::onAcadLockModeChanged ( WPARAM, LPARAM pCh )
{
    onAcadUpdateDialog(0,0L);
	return TRUE;
}


LRESULT CMDITestDialog::onAcadLockModeWillChange ( WPARAM, LPARAM pCh )
{
    onAcadUpdateDialog(0,0L);
	return TRUE;
}


LRESULT CMDITestDialog::onAcadCurrDoc ( WPARAM, LPARAM )
{
    onAcadUpdateDialog(0, 0L);
	return TRUE;
}


LRESULT CMDITestDialog::onAcadActivateDoc ( WPARAM, LPARAM )
{
    onAcadUpdateDialog(0, 0L);
	return TRUE;
}


LRESULT CMDITestDialog::onAcadDeactivateDoc ( WPARAM, LPARAM )
{
    // clear the fields related to the active document
    m_staticActiveDoc.SetWindowText(_T(""));
    m_staticActDocLockStatus.SetWindowText(_T(""));
    m_staticActDocMyLockStatus.SetWindowText(_T(""));
	return TRUE;
}


LRESULT CMDITestDialog::onAcadActModifiedDoc ( WPARAM, LPARAM bValue )
{
    // check/uncheck document activation depending on the activation value sent
    if( 1L == bValue )
        m_activationCheck.SetCheck( TRUE );
    else
        m_activationCheck.SetCheck( FALSE );
	return TRUE;
}



/////////////////////////////////////////////////////////////////
// ui related actions

void CMDITestDialog::OnNewdocButton() 
{
    // document context. 
    Gcad::ErrorStatus st = gcDocManager->newDocument();
}


void CMDITestDialog::OnOpendocButton() 
{
    // document context. 
    Gcad::ErrorStatus st = gcDocManager->openDocument();
}


void CMDITestDialog::OnAppnewdocButton() 
{
    static TCHAR pData[] = _T("acad.dwt");

    Gcad::ErrorStatus st = gcDocManager->appContextNewDocument((const TCHAR *)pData);
}


void CMDITestDialog::OnAppopendocButton() 
{
    static TCHAR pData[] = _T("test1.dwg");

    Gcad::ErrorStatus st = gcDocManager->appContextOpenDocument((const TCHAR *)pData);
}

void CMDITestDialog::OnActivationCheck() 
{
    Gcad::ErrorStatus st;
    // get status of the button and set the activation state from it.
    UINT check = m_activationCheck.GetCheck();

    if( (check && 0x0003) == 0 ) {
        // unchecked - we need to disable the activation
        st = gcDocManager->disableDocumentActivation();
    }
    else {
        // checked - we need to enable the activation
        st = gcDocManager->enableDocumentActivation();
    }
}

void CMDITestDialog::OnSendstringButton() 
{
    if( gcDocManager->documentCount() == 0 )
        return;

    GcApDocument *pDoc = getSelectedDocument();

    if(pDoc) {
        Gcad::ErrorStatus st = gcDocManager->sendStringToExecute( pDoc, _T("_line 0,0 1,1 \n"),
			                                                      false, true);
//        Gcad::ErrorStatus st = gcDocManager->sendStringToExecute( pDoc, "_text 5,5 0.2 15 Testing\r\r");
    }
    else
        AfxMessageBox(_T("Please select a document on the list box"));

}


void CMDITestDialog::OnIsquiescentButton() 
{
    GcApDocument *pDoc = gcDocManager->curDocument();

    if(pDoc) {
        CString tempStr;
        tempStr.Format(_T("Current Doc is %s\nlockMode() returned %s\nand myLockMode() returned %s."),
                        pDoc->isQuiescent() ? _T("Quiescent.") : _T("NOT Quiescent."),
                        modeStr(pDoc->lockMode()),
                        modeStr(pDoc->myLockMode()) );
        AfxMessageBox( tempStr );
    }
}

void CMDITestDialog::OnClosedocButton() 
{
    if( gcDocManager->documentCount() == 0 )
        return;

    GcApDocument *pDoc = getSelectedDocument();

    if(pDoc) {
        // if you close the doc, update the UI
        if( gcDocManager->closeDocument(pDoc) == Gcad::eOk ) {
            onAcadUpdateDialog(0, 0L);
        }            
    }
    else
        AfxMessageBox(_T("Please select a document on the list box"));
}

void CMDITestDialog::OnActivatedocButton() 
{
    if( gcDocManager->documentCount() == 0 )
        return;

    GcApDocument *pDoc = getSelectedDocument();
    if( pDoc )
        gcDocManager->activateDocument( pDoc );
    else
        AfxMessageBox(_T("Please select a document on the list box"));
}


BOOL CMDITestDialog::OnInitDialog() 
{
    CDialog::OnInitDialog();

    // select one of the elements of the CComboBox to be displayed 
    m_lockCombo.SetCurSel(2);


    // set up all the UI elements
    // here I call the functions that update the ui elements directly
    // instead of waiting for posted messages.
    onAcadUpdateDialog(0, 0L);

    return TRUE;  // return TRUE unless you set the focus to a control
                  // EXCEPTION: OCX Property Pages should return FALSE
}


void CMDITestDialog::OnSetcurrentdocButton() 
{
    GcApDocument *pDoc = getSelectedDocument();
    if( !pDoc ) {
        AfxMessageBox(_T("Please select a document on the list box"));
        return;
    }

    // get the lock mode to be used from the combo box
    GcAp::DocLockMode lockMode = getSelectedLockMode();

    gcDocManager->unlockDocument( pDoc ); // in case we had lock it before
    gcDocManager->setCurDocument( pDoc, lockMode );
}


//Dialog is about to close (user clicked on 'X' button).
void CMDITestDialog::OnClose()
{
	CDialog::OnClose();
	
	endDlg();
}

/////////////////////////////////////////////////////////////////////////////
// other MDITestDialog member functions
/////////////////////////////////////////////////////////////////////////////
void CMDITestDialog::cleanUpUI( void ) 
{
    m_staticActDocMyLockStatus.SetWindowText(_T(""));
    m_staticCurrentDoc.SetWindowText(_T(""));
    m_staticCurDocLockStatus.SetWindowText(_T(""));
    m_staticCurDocMyLockStatus.SetWindowText(_T(""));
    m_staticActDocLockStatus.SetWindowText(_T(""));

    m_staticActiveDoc.SetWindowText(_T(""));
    m_staticToBeCurrDoc.SetWindowText(_T(""));
    m_activationCheck.SetCheck( gcDocManager->isDocumentActivationEnabled() );
    m_staticDocNum.SetWindowText( _T("0") );
    m_docListBox.ResetContent();
}

CString CMDITestDialog::getDocCount( void )
{
    // get the current number of documents
    int nDoc = gcDocManager->documentCount();
    CString tempStr;
    tempStr.Format(_T("%d"),nDoc);
    return tempStr;
}

CString CMDITestDialog::makeStringFromPtr( LONG_PTR pCh )
{
    CString tempStr;

    TCHAR *pChar = (TCHAR*) pCh;
    if( pChar ) {
        tempStr.Format(_T("%s"),pChar);
        if( *pChar )
            delete pChar;
    }
    else
        tempStr = _T("");

    return tempStr;
}

// getDocFromFilename()
//  Passed a filename, it finds the corresponding document pointer
//  Returns true if successful
bool CMDITestDialog::getDocFromFilename(CString csFileName, GcApDocument* &pNewDocument)
{
    // Iterate over the open documents. We will match the filename if:
    //      The filename specified matches the fully qualified path
    //      name, as returned by GcApDocument::filename()
    //      -or-
    //      The filename specified matches the filename portion of the 
    //      document name

    GcApDocumentIterator* iter = gcDocManager->newAcApDocumentIterator();
    GcApDocument* pThisDocument = NULL;
    CString csThisFilename;
    CString csThisFilenameShort;

    csFileName.MakeUpper(); // uppercase comparisons

    while(!iter->done()) {   // Tiptoe through the tulips
        pThisDocument = iter->document();
        csThisFilename = pThisDocument->docTitle();
        csThisFilename.MakeUpper();
        csThisFilenameShort = csThisFilename.Right(csThisFilename.GetLength() -
            csThisFilename.ReverseFind(_T('\\')) - 1);

        if(csFileName == csThisFilename ||       // Full path match
            csFileName == csThisFilenameShort || // Matches filename only
            csFileName == csThisFilenameShort.Left( // Filename less extension
                          csThisFilenameShort.GetLength() - 4)) 
        {
            pNewDocument = pThisDocument;
            if( iter )
                delete iter;
            return true;
        }
        iter->step();
    }

    pNewDocument = NULL;
    if( iter )
        delete iter;
    // no match found 
    return false;
}
            

GcApDocument* CMDITestDialog::getSelectedDocument( void )
{
    GcApDocument *pDoc = NULL;

    CString fName;
    int ndx = m_docListBox.GetCurSel();

    if( LB_ERR != ndx ) {
        m_docListBox.GetText(ndx, fName);
        // find out which document has this file name and get its document pointer.
        if( !getDocFromFilename( fName, pDoc ) )
            AfxMessageBox(_T("Document NOT found.")); 
    }
    return pDoc;
}


GcAp::DocLockMode CMDITestDialog::getSelectedLockMode( void )
{
    GcAp::DocLockMode lm = GcAp::kNone;

    int ndx = m_lockCombo.GetCurSel();
    CString lModeStr;

    if( LB_ERR != ndx ) {
        m_lockCombo.GetLBText(ndx, lModeStr);
        // to activate the document, first I need to find out which document
        // has this file name and get its document pointer.
        if( !getLockModeFromStr( lModeStr, lm ) )
            AfxMessageBox(_T("Error with lock mode combo box")); //should never get here.
    }
    return lm;

}


void CMDITestDialog::RebuildListBox()
{
    m_docListBox.ResetContent(); // start from an empty list box

    // at this moment, get all drawing names and add them to the list box.
    GcApDocumentIterator* iter = gcDocManager->newAcApDocumentIterator();
    GcApDocument* pDoc = NULL;
    CString csFilename;

    while(!iter->done()) {   
        pDoc = iter->document();
        if(pDoc) {                     // #### make sure pDoc is not NULL ####
            csFilename = pDoc->docTitle(); 
            m_docListBox.AddString( csFilename );
        }
        iter->step();
    }
    if( iter )
        delete iter;
}

void CMDITestDialog::OnRefreshButton() 
{
    // Just to give peace of mind: if you think something is displayed wrong
    // in the dialog, this button will update all ui of the dialog
    onAcadUpdateDialog(0,0L);
}
