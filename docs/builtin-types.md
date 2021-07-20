
## Built-in Types

List of all *currently known* built-in types. Many have special properties for how data is displayed.

This table is also a list of all built-in types supported by the `TYPE` block (with exception to `PURGE`, whose purpose is not known).

|Size   |Ptr|Type         |Notes|
|------:|:-:|:------------|:----|
|*any*  |   |`HEX`        ||
|*any*  |   |`HEXDATA`    ||
|*any*  |   |`HEX8`       ||
|*any*  |   |`BOOL`       |boolean (`FALSE`, `TRUE`)|
|*any*  |   |`BYTE`       ||
|*any*  |   |`WORD`       ||
|*any*  |   |`INT`        ||
|*any*  |   |`UINT`       ||
|*any*  |   |`VOID`       |does not require `*`|
|`DWORD`|`*`|`VOIDPTR`    ||
|*any*  |   |`CHAR`       ||
|*any*  |   |`WCHAR`      ||
|`DWORD`|`*`|`ASCII`      |ptr to cstring|
|`DWORD`|`*`|`UNICODE`    |ptr to wide cstring|
|*any*  |   |`MASCII`     ||
|*any*  |   |`MUNICODE`   ||
|`DWORD`|`*`|`FORMAT`     |[printf format][printf] cstring|
|`DWORD`|`*`|`WFORMAT`    |[printf format][printf] wide cstring|
|`DWORD`|`*`|`SCAN`       |[scanf format][scanf] cstring|
|`DWORD`|`*`|`WSCAN`      |[scanf format][scanf] wide cstring|
|*any*  |   |`ATEXT`      |array cstring|
|*any*  |   |`WTEXT`      |array wide cstring|
|*any*  |   |`RSRC_STRING`||
|*any*  |   |`QUAD`       ||
|*any*  |   |`QUAD_LO`    ||
|*any*  |   |`QUAD_HI`    ||
|`DWORD`|   |`FLOAT`      |32-bit IEEE floating point|
|`QWORD`|   |`DOUBLE`     |64-bit IEEE floating point|
|*any*  |   |`DOUBLE_LO`  ||
|*any*  |   |`DOUBLE_HI`  ||
|`TBYTE`|   |`LDOUBLE`    |80-bit IEEE floating|
|*any*  |   |`LDOUBLE_LO` ||
|*any*  |   |`LDOUBLE_MI` ||
|*any*  |   |`LDOUBLE_HI` ||
|*any*  |   |`HANDLE`     ||
|*any*  |   |`HWND`       ||
|*any*  |   |`HMODULE`    ||
|*any*  |   |`HDC`        ||
|*any*  |   |`HGDI`       ||
|*any*  |   |`HMEM`       ||
|*any*  |   |`HKEY`       ||
|`DWORD`|`*`|`CALLBACK`   |`__stdcall` function|
|`DWORD`|`*`|`WINPROCA`   |*[WNDPROC][WNDPROC]*(?) function|
|`DWORD`|`*`|`WINPROCW`   |*[WNDPROC][WNDPROC]*(?) function|
|*any*  |   |`PROCID`     ||
|*any*  |   |`NETSW`      ||
|*any*  |   |`NETSD`      ||
|*any*  |   |`NETGW`      ||
|*any*  |   |`NETGD`      ||
|*any*  |   |`NETBW`      ||
|*any*  |   |`NETBD`      ||
|*any*  |   |`NETCI`      ||
|*any*  |   |`NETCH`      ||
|*any*  |   |`NETCF`      ||
|*any*  |   |`NETCU`      ||


## Built-in Enums

List of all *currently known* built-in enum types.

|Type     |Notes|
|--------:|:----|
|`BOOL`   |`FALSE` for `0`, `TRUE` for everything else|
|`ERRNO`  |C error number codes|
|`HRESULT`|HRESULT error codes|
|`MESSAGE`|Windows messages (`WM_`, etc.)|



<!-- ======== MARKDOWN REFERENCES ======== -->

[WNDPROC]: <https://docs.microsoft.com/en-us/windows/win32/api/winuser/nc-winuser-wndproc>
[printf]: <https://www.cplusplus.com/reference/cstdio/printf/>
[scanf]: <https://www.cplusplus.com/reference/cstdio/scanf/>
