// (C) Copyright 1998-2006 by Autodesk, Inc.
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
// common.cpp: common definitions and functions for this project.
//             Used by docman.cpp and MDITestDialog.cpp files.
//
#include "stdafx.h"

//#if defined(_DEBUG) && !defined(AC_FULL_DEBUG)
//#error _DEBUG should not be defined except in internal Adesk debug builds
//#endif

#include "common.h"
#include "gcdocman.h"




const TCHAR* modeStr(GcAp::DocLockMode mode)
{
    switch (mode) {
    case GcAp::kNotLocked:
        return _T(/*NOXLATE*/"GcAp::kNotLocked");
    case GcAp::kRead:
        return _T(/*NOXLATE*/"GcAp::kRead");
    case GcAp::kWrite:
        return _T(/*NOXLATE*/"GcAp::kWrite");
    case GcAp::kAutoWrite:
        return _T(/*NOXLATE*/"GcAp::kAutoWrite");
    case GcAp::kProtectedAutoWrite:
        return _T(/*NOXLATE*/"GcAp::kProtectedAutoWrite");
    case GcAp::kXWrite:
        return _T(/*NOXLATE*/"GcAp::kXWrite");
    }
    return _T("ERROR");
}



bool getLockModeFromStr(CString csLockMode, GcAp::DocLockMode &lockMode)
{
    if( csLockMode == _T(/*NOXLATE*/"kNone") ) {
		lockMode = GcAp::kNone;
		return true;
	}
    if( csLockMode == _T(/*NOXLATE*/"kNotLocked") ) {
		lockMode = GcAp::kNotLocked;
		return true;
	}
    if( csLockMode == _T(/*NOXLATE*/"kRead") ) {
		lockMode = GcAp::kRead;
		return true;
	}
    if( csLockMode == _T(/*NOXLATE*/"kWrite") ) {
		lockMode = GcAp::kWrite;
		return true;
	}
    if( csLockMode == _T(/*NOXLATE*/"kAutoWrite") ) {
		lockMode = GcAp::kAutoWrite;
		return true;
	}
    if( csLockMode == _T(/*NOXLATE*/"kProtectedAutoWrite") ) {
		lockMode = GcAp::kProtectedAutoWrite;
		return true;
	}
    if( csLockMode == _T(/*NOXLATE*/"kXWrite") ) {
		lockMode = GcAp::kXWrite;
		return true;
	}

    return false;
}