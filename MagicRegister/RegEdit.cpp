#include "StdAfx.h"
#include "RegEdit.h"


CRegEdit::CRegEdit()
{
}


CRegEdit::~CRegEdit(void)
{
}


void CRegEdit::SetKey(HKEY parent, LPCTSTR path)
{
	m_parentKey = parent;
	m_keyPath = path;
}

CString CRegEdit::GetString(LPCTSTR name, LPCTSTR def)
{
	CString val;
	DWORD len = 1023;

	if (Open(m_parentKey, m_keyPath) == ERROR_SUCCESS) {
		if (QueryStringValue(name, val.GetBuffer(len), &len) == ERROR_SUCCESS) {
			val.ReleaseBuffer();
			Close();
		}
		else
			val = def;
	}
	else
		val = def;

	return val;
}


void CRegEdit::SetString(LPCTSTR name, LPCTSTR val)
{
	if (Create(m_parentKey, m_keyPath) == ERROR_SUCCESS) {
		SetStringValue(name, val);
		Close();
	}
}


int CRegEdit::GetDWord(LPCTSTR name, int def)
{
	CString cstr;
	DWORD val;

	if (Open(m_parentKey, m_keyPath) == ERROR_SUCCESS) {
		if (QueryDWORDValue(name, val) == ERROR_SUCCESS) {
			Close();
		}
		else
			val = def;
	}
	else
		val = def;

	return val;
}


void CRegEdit::SetDWord(LPCTSTR name, int val)
{
	if (Create(m_parentKey, m_keyPath) == ERROR_SUCCESS) {
		SetDWORDValue(name, val);
		Close();
	}
}


int CRegEdit::GetInteger(LPCTSTR name, int def)
{
	CString cstr;
	CString cdef;

	cdef.Format(_T("%d"), def);
	cstr = GetString(name, cdef);

	return _ttoi(cstr);
}


void CRegEdit::SetInteger(LPCTSTR name, int val)
{
	CString cstr;

	cstr.Format(_T("%d"), val);
	SetString(name, cstr);
}


double CRegEdit::GetDouble(LPCTSTR name, double def)
{
	CString cstr;
	CString cdef;

	cdef.Format(_T("%f"), def);
	cstr = GetString(name, cdef);

	return _ttof(cstr);
}


void CRegEdit::SetDouble(LPCTSTR name, double val)
{
	CString cstr;

	cstr.Format(_T("%f"), val);
	SetString(name, cstr);
}


double CRegEdit::GetDouble(LPCTSTR name, LPCTSTR def)
{
	CString cstr;

	cstr = GetString(name, def);

	return _ttof(cstr);
}


void CRegEdit::SetDouble(LPCTSTR name, LPCTSTR val)
{
	SetString(name, val);
}


BOOL CRegEdit::GetBoolean(LPCTSTR name, BOOL def)
{
	CString cstr;

	cstr = GetString(name, (def) ? _T("1"): _T("0"));
	if (cstr.Compare(_T("1")) == 0)
		return TRUE;
	else
		return FALSE;
}


void CRegEdit::SetBoolean(LPCTSTR name, BOOL val)
{
	SetString(name, (val) ? _T("1"): _T("0"));
}


BOOL CRegEdit::DeleteValue(LPCTSTR name)
{
	if (Open(m_parentKey, m_keyPath) == ERROR_SUCCESS) {
		CRegKey::DeleteValue(name);
		return TRUE;
	}
	else
		return FALSE;
}

