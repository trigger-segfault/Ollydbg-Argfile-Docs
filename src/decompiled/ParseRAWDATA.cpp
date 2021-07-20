
/* WARNING: Could not reconcile some variable overlaps */

short * __stdcall olly::ParseRAWDATA(uint *param_4)

{
  bool bVar1;
  short *psVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint local_74;
  int local_70;
  undefined4 local_6c;
  wchar_t local_68 [16];
  undefined4 *local_28;
  undefined4 *local_24;
  undefined4 local_20;
  uint local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  _Scan((byte *)param_4);
  if ((*(int *)((int)param_4 + 0x42e) == 2) || (*(int *)((int)param_4 + 0x42e) == 3)) {
    if (*(int *)((int)param_4 + 0x22a) < 0x1f) {
      local_8 = _StrcopyW(local_68,0x1f,(wchar_t *)((int)param_4 + 0x2a));
      local_c = 0x1000;
      local_24 = (undefined4 *)FUN_004041a0();
      if (local_24 == (undefined4 *)0x0) {
        psVar2 = _T(L"Low memory, processing interrupted");
      }
      else {
        local_28 = (undefined4 *)((int)local_24 + local_c);
        local_20 = 0;
        local_14 = 0;
        local_18 = 0;
        uVar5 = 0;
        *param_4 = *param_4 | 0x1000;
        do {
          do {
            _Scan((byte *)param_4);
          } while (*(int *)((int)param_4 + 0x42e) == 1);
          local_10 = 1;
          bVar1 = false;
          while( true ) {
            while( true ) {
              while( true ) {
                while( true ) {
                  while (*(int *)((int)param_4 + 0x42e) == 3) {
                    if (bVar1) {
                      *param_4 = *param_4 & 0xffffefff;
                      psVar2 = _T(L"Data expected");
                      return psVar2;
                    }
                    if (local_c < (int)(*(int *)((int)param_4 + 0x22a) + uVar5 + 1)) {
                      *param_4 = *param_4 & 0xffffefff;
                      psVar2 = _T(L"Size of raw data exceeds allowed limit");
                      return psVar2;
                    }
                    if (0 < *(int *)((int)param_4 + 0x22a)) {
                      _Unicodetoascii();
                      FUN_004e7588();
                    }
                    uVar5 += *(int *)((int)param_4 + 0x22a);
                    _Scan((byte *)param_4);
                    if ((*(int *)((int)param_4 + 0x42e) == 6) || (param_4[6] == 0x2c)) {
                      _Scan((byte *)param_4);
                      bVar1 = true;
                    }
                    else {
                      bVar1 = false;
                    }
                    local_10 = 1;
                  }
                  if ((*(int *)((int)param_4 + 0x42e) == 2) &&
                     (iVar3 = FUN_004e7a58((int)param_4 + 0x2a,L"END"), iVar3 == 0)) {
                    *param_4 = *param_4 & 0xffffefff;
                    if (bVar1) {
                      psVar2 = _T(L"Data expected");
                      return psVar2;
                    }
                    if (uVar5 == 0) {
                      psVar2 = _T(L"Empty raw data block");
                      return psVar2;
                    }
                    if (((int)globals::g_Arg_TableRawData_Capacity <=
                         (int)globals::g_Arg_TableRawData_Count) &&
                       (globals::g_Arg_TableRawData =
                             _Memdouble(globals::g_Arg_TableRawData,
                                        (int *)&globals::g_Arg_TableRawData_Capacity,4,
                                        (int *)&DAT_005ebc70,1),
                       (int)globals::g_Arg_TableRawData_Capacity <=
                       (int)globals::g_Arg_TableRawData_Count)) {
                      psVar2 = _T(L"Low memory, processing interrupted");
                      return psVar2;
                    }
                    if (((int)globals::g_Arg_TableAll_Capacity <
                         (int)(uVar5 * 2 + globals::g_Arg_TableAll_Count + 0xc)) &&
                       (globals::g_Arg_TableAll =
                             _Memdouble(globals::g_Arg_TableAll,
                                        (int *)&globals::g_Arg_TableAll_Capacity,1,
                                        (int *)&DAT_005ebc70,1),
                       (int)globals::g_Arg_TableAll_Capacity <
                       (int)(uVar5 * 2 + globals::g_Arg_TableAll_Count + 0xc))) {
                      psVar2 = _T(L"Low memory, processing interrupted");
                      return psVar2;
                    }
                    iVar3 = FindInTableUnk__00478d08
                                      ((short *)local_68,(int *)&globals::g_Arg_TableRawData);
                    if (iVar3 == 0) {
                      iVar3 = ArgCreateEntry(globals::g_Arg_TableAll_Count,local_68,local_8);
                      uVar4 = globals::g_Arg_TableRawData_Count;
                      globals::g_Arg_TableRawData_Count += 1;
                      globals::g_Arg_TableRawData[uVar4] = iVar3;
                      globals::g_Arg_TableRawData_IsUsed = 1;
                    }
                    else {
                      psVar2 = _T(L"  Redefined data block \'%s\'",local_68);
                      _Addtolist(0,2,(int)psVar2);
                      *(uint *)(DAT_005e9e20 + iVar3) = globals::g_Arg_TableAll_Count;
                    }
                    globals::g_Arg_NumDataBlocks += 1;
                    local_70 = local_18;
                    local_6c = local_20;
                    local_74 = uVar5;
                    FUN_004e74f4((undefined4 *)
                                 ((int)globals::g_Arg_TableAll + globals::g_Arg_TableAll_Count),
                                 &local_74,0xc);
                    globals::g_Arg_TableAll_Count += 0xc;
                    FUN_004e74f4((undefined4 *)
                                 ((int)globals::g_Arg_TableAll + globals::g_Arg_TableAll_Count),
                                 local_24,uVar5);
                    globals::g_Arg_TableAll_Count += uVar5;
                    if (local_18 != 0) {
                      FUN_004e74f4((undefined4 *)
                                   ((int)globals::g_Arg_TableAll + globals::g_Arg_TableAll_Count),
                                   local_28,uVar5);
                      globals::g_Arg_TableAll_Count += uVar5;
                    }
                    return (short *)0x0;
                  }
                  if ((*(int *)((int)param_4 + 0x42e) != 2) ||
                     (iVar3 = FUN_004e7a58((int)param_4 + 0x2a,L"FEATURES"), iVar3 != 0)) break;
                  if (bVar1) {
                    *param_4 = *param_4 & 0xffffefff;
                    psVar2 = _T(L"Data expected");
                    return psVar2;
                  }
                  if (local_14 != 0) {
                    *param_4 = *param_4 & 0xffffefff;
                    psVar2 = _T(L"Duplicated FEATURES");
                    return psVar2;
                  }
                  iVar3 = FUN_00478c00((byte *)param_4,&local_20);
                  if (iVar3 != 0) {
                    *param_4 = *param_4 & 0xffffefff;
                    psVar2 = _T(L"Constant expected");
                    return psVar2;
                  }
                  local_14 = 1;
                  _Scan((byte *)param_4);
                }
                if ((*(int *)((int)param_4 + 0x42e) != 2) ||
                   (iVar3 = FUN_004e7a58((int)param_4 + 0x2a,L"BYTE"), iVar3 != 0)) break;
                if (bVar1) {
                  *param_4 = *param_4 & 0xffffefff;
                  psVar2 = _T(L"Data expected");
                  return psVar2;
                }
                local_10 = 1;
                bVar1 = true;
                _Scan((byte *)param_4);
              }
              if ((*(int *)((int)param_4 + 0x42e) != 2) ||
                 (iVar3 = FUN_004e7a58((int)param_4 + 0x2a,L"DWORD"), iVar3 != 0)) break;
              if (bVar1) {
                *param_4 = *param_4 & 0xffffefff;
                psVar2 = _T(L"Data expected");
                return psVar2;
              }
              local_10 = 4;
              bVar1 = true;
              _Scan((byte *)param_4);
            }
            iVar3 = *(int *)((int)param_4 + 0x42e);
            if ((iVar3 != 2) && (iVar3 != 4)) break;
            if (iVar3 == 2) {
              iVar3 = _Getconstantbyname((short *)((int)param_4 + 0x2a),&local_1c);
              if (iVar3 != 0) {
                *param_4 = *param_4 & 0xffffefff;
                psVar2 = _T(L"Unrecognized constant or keyword");
                return psVar2;
              }
              uVar4 = 0xffffffff;
            }
            else {
              local_1c = param_4[6];
              uVar4 = param_4[7];
            }
            if ((local_10 == 1) &&
               (((local_1c & 0xffffff00) != 0 || ((uVar4 & 0xffffff00) != 0xffffff00)))) {
              *param_4 = *param_4 & 0xffffefff;
              psVar2 = _T(L"Byte data expected");
              return psVar2;
            }
            if (local_c < (int)(local_10 + uVar5)) {
              *param_4 = *param_4 & 0xffffefff;
              psVar2 = _T(L"Size of raw data exceeds allowed limit");
              return psVar2;
            }
            if (local_10 == 1) {
              *(undefined *)((int)local_24 + uVar5) = (undefined)local_1c;
              *(char *)((int)local_28 + uVar5) = (char)uVar4;
              if ((char)uVar4 != -1) {
                local_18 = 1;
              }
            }
            else {
              *(uint *)((int)local_24 + uVar5) = local_1c;
              *(uint *)((int)local_28 + uVar5) = uVar4;
              if (uVar4 != 0xffffffff) {
                local_18 = 1;
              }
            }
            uVar5 += local_10;
            _Scan((byte *)param_4);
            if ((*(int *)((int)param_4 + 0x42e) == 6) || (param_4[6] == 0x2c)) {
              _Scan((byte *)param_4);
              bVar1 = true;
            }
            else {
              bVar1 = false;
            }
          }
          if ((*(int *)((int)param_4 + 0x42e) != 0) && (*(int *)((int)param_4 + 0x42e) != 1)) {
            *param_4 = *param_4 & 0xffffefff;
            psVar2 = _T(L"Syntax error in raw data description");
            return psVar2;
          }
        } while (!bVar1);
        *param_4 = *param_4 & 0xffffefff;
        psVar2 = _T(L"Data expected");
      }
    }
    else {
      psVar2 = _T(L"Length of data name is limited to 30 characters");
    }
  }
  else {
    psVar2 = _T(L"Bad name of data block");
  }
  return psVar2;
}

