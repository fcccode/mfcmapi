#pragma once

wstring GetDirectoryPath(HWND hWnd);

wstring BuildFileName(
	_In_ const wstring& szExt,
	_In_ LPMESSAGE lpMessage);
wstring BuildFileNameAndPath(
	_In_ const wstring& szExt,
	_In_ const wstring& szSubj,
	_In_ const wstring& szRootPath,
	_In_opt_ const LPSBinary lpBin);

_Check_return_ HRESULT LoadMSGToMessage(_In_ const wstring& szMessageFile, _Deref_out_opt_ LPMESSAGE* lppMessage);

_Check_return_ HRESULT LoadFromMSG(_In_ const wstring& szMessageFile, _In_ LPMESSAGE lpMessage, HWND hWnd);
_Check_return_ HRESULT LoadFromTNEF(_In_z_ LPCWSTR szMessageFile, _In_ LPADRBOOK lpAdrBook, _In_ LPMESSAGE lpMessage);

void SaveFolderContentsToTXT(_In_ LPMDB lpMDB, _In_ LPMAPIFOLDER lpFolder, bool bRegular, bool bAssoc, bool bDescend, HWND hWnd);
_Check_return_ HRESULT SaveFolderContentsToMSG(_In_ LPMAPIFOLDER lpFolder, _In_z_ LPCWSTR szPathName, bool bAssoc, bool bUnicode, HWND hWnd);
_Check_return_ HRESULT SaveToEML(_In_ LPMESSAGE lpMessage, _In_z_ LPCWSTR szFileName);
_Check_return_ HRESULT CreateNewMSG(_In_z_ LPCWSTR szFileName, bool bUnicode, _Deref_out_opt_ LPMESSAGE* lppMessage, _Deref_out_opt_ LPSTORAGE* lppStorage);
_Check_return_ HRESULT SaveToMSG(_In_ LPMESSAGE lpMessage, _In_z_ LPCWSTR szFileName, bool bUnicode, HWND hWnd, bool bAllowUI);
_Check_return_ HRESULT SaveToTNEF(_In_ LPMESSAGE lpMessage, _In_ LPADRBOOK lpAdrBook, _In_ const wstring& szFileName);

_Check_return_ HRESULT DeleteAttachments(_In_ LPMESSAGE lpMessage, _In_ const wstring& szAttName, HWND hWnd);
_Check_return_ HRESULT WriteAttachmentsToFile(_In_ LPMESSAGE lpMessage, HWND hWnd);
_Check_return_ HRESULT WriteAttachmentToFile(_In_ LPATTACH lpAttach, HWND hWnd);
_Check_return_ HRESULT WriteEmbeddedMSGToFile(_In_ LPATTACH lpAttach, _In_z_ LPCWSTR szFileName, bool bUnicode, HWND hWnd);