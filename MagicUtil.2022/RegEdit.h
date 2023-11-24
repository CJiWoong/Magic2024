#pragma once

class CRegEdit : public CRegKey
{
public:
	CRegEdit();
	~CRegEdit(void);

protected:
	HKEY m_parentKey;
	CString m_keyPath;

public:
	void SetKey(HKEY parent, LPCTSTR path);
	CString GetString(LPCTSTR name, LPCTSTR def);
	void SetString(LPCTSTR name, LPCTSTR val);
	int GetDWord(LPCTSTR name, int def);
	void SetDWord(LPCTSTR name, int val);
	int GetInteger(LPCTSTR name, int def);
	void SetInteger(LPCTSTR name, int val);
	double GetDouble(LPCTSTR name, double def);
	void SetDouble(LPCTSTR name, double val);
	double GetDouble(LPCTSTR name, LPCTSTR def);
	void SetDouble(LPCTSTR name, LPCTSTR val);
	BOOL GetBoolean(LPCTSTR name, BOOL def);
	void SetBoolean(LPCTSTR name, BOOL val);
	BOOL DeleteValue(LPCTSTR name);
};

