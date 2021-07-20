
short * __stdcall olly::ParseGROUP(byte *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  wchar_t wVar3;
  short *psVar4;
  int iVar5;
  HGLOBAL pvVar6;
  undefined4 *puVar7;
  wchar_t *dest;
  byte *pbVar8;
  uint local_8;
  
  pbVar8 = param_4;
  _Scan(param_4);
  iVar5 = *(int *)(param_4 + 0x42e);
  if ((iVar5 == 2) || (iVar5 == 3)) {
    if (*(int *)(param_4 + 0x22a) < 0x20) {
      FUN_004ecff0(iVar5,param_4 + 0x2a,pbVar8,param_4 + 0x2a);
      dest = (wchar_t *)&DAT_005e9e88;
      local_8 = 0;
      do {
        if ((dest[0x10] == L'\0') ||
           (iVar5 = msvc::strcmp((short *)dest,(short *)(param_4 + 0x2a)), iVar5 == 0)) break;
        local_8 += 1;
        dest = dest + 0x14;
      } while ((int)local_8 < 0x18);
      if ((int)local_8 < 0x18) {
        if ((int)local_8 < (int)globals::g_Arg_NumGroups) {
          psVar4 = _T(L"  Redefined group \'%s\'",param_4 + 0x2a);
          _Addtolist(0,2,(int)psVar4);
        }
        if (dest[0x10] == L'\0') {
          dest[0x11] = L'Ѐ';
          pvVar6 = _Memalloc(dest[0x11] << 2,1);
          dest[0x10] = (wchar_t)pvVar6;
          if (dest[0x10] == L'\0') {
            psVar4 = _T(L"Low memory, processing interrupted");
            return psVar4;
          }
          dest[0x12] = L'\0';
        }
        _StrcopyW(dest,0x20,(wchar_t *)(param_4 + 0x2a));
        _Scan(param_4);
        if ((*(int *)(param_4 + 0x42e) == 0) || (*(int *)(param_4 + 0x42e) == 1)) {
          do {
            do {
              _Scan(param_4);
            } while (*(int *)(param_4 + 0x42e) == 1);
            if (*(int *)(param_4 + 0x42e) != 2) {
              psVar4 = _T(L"Expecting CONST or END");
              return psVar4;
            }
            iVar5 = FUN_004e7a58(param_4 + 0x2a,L"END");
            if (iVar5 == 0) {
              if (local_8 == globals::g_Arg_NumGroups) {
                globals::g_Arg_NumGroups += 1;
              }
              return (short *)0x0;
            }
            iVar5 = FUN_004e7a58(param_4 + 0x2a,L"CONST");
            if (iVar5 != 0) {
              psVar4 = _T(L"Expecting CONST or END");
              return psVar4;
            }
            _Scan(param_4);
            if (*(int *)(param_4 + 0x42e) != 4) {
              psVar4 = _T(L"Integer constant expected");
              return psVar4;
            }
            uVar2 = *(undefined4 *)(param_4 + 0x18);
            _Scan(param_4);
            if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) {
              psVar4 = _T(L"Bad constant name");
              return psVar4;
            }
            if ((0 < *(int *)(param_4 + 0x22a)) &&
               (*(short *)(param_4 + *(int *)(param_4 + 0x22a) * 2 + 0x28) == 0x7c)) {
              psVar4 = _T(L"Constant ends with vertical line");
              return psVar4;
            }
            if ((DAT_005e9e6c <= DAT_005e9e70) &&
               (DAT_005e9e68 = _Memdouble(DAT_005e9e68,&DAT_005e9e6c,4,(int *)&DAT_005ebc70,1),
               DAT_005e9e6c <= DAT_005e9e70)) {
              psVar4 = _T(L"Low memory, processing interrupted");
              return psVar4;
            }
            if (dest[0x11] <= dest[0x12]) {
              puVar7 = _Memdouble((undefined4 *)dest[0x10],dest + 0x11,4,(int *)&DAT_005ebc70,1);
              dest[0x10] = (wchar_t)puVar7;
              if (dest[0x11] <= dest[0x12]) {
                psVar4 = _T(L"Low memory, processing interrupted");
                return psVar4;
              }
            }
            iVar5 = FUN_00478c44(uVar2,(undefined4 *)(param_4 + 0x2a),*(int *)(param_4 + 0x22a));
            piVar1 = DAT_005e9e68 + DAT_005e9e70;
            DAT_005e9e70 = DAT_005e9e70 + 1;
            *piVar1 = iVar5;
            globals::g_Arg_NumConstants += 1;
            DAT_005e9e74 = 1;
            wVar3 = dest[0x12];
            dest[0x12] = dest[0x12] + L'\x01';
            *(int *)(dest[0x10] + wVar3 * 4) = iVar5;
            dest[0x13] = L'\x01';
            _Scan(param_4);
          } while (*(int *)(param_4 + 0x42e) == 1);
          psVar4 = _T(L"Extra characters on line");
        }
        else {
          psVar4 = _T(L"Extra characters on line");
        }
      }
      else {
        psVar4 = _T(L"Too many groups");
      }
    }
    else {
      psVar4 = _T(L"Length of group name is limited to 31 character");
    }
  }
  else {
    psVar4 = _T(L"Bad group name");
  }
  return psVar4;
}

