
/* WARNING: Could not reconcile some variable overlaps */

short * __stdcall olly::ParseFUNCTION(byte *param_4,uint param_5)

{
  byte *pbVar1;
  bool bVar2;
  short *psVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  int *piVar8;
  undefined **ppuVar9;
  bool bVar10;
  wchar_t local_2fc [127];
  uint uStack256;
  undefined2 local_fc [48];
  int local_9c [24];
  int *local_3c;
  undefined2 *local_38;
  int *local_34;
  uint *local_30;
  uint *local_2c;
  undefined4 local_28;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar5 = 3;
  do {
    local_8 = iVar5;
    iVar5 = local_8 + -1;
  } while (local_8 + -1 != 0);
  local_1c = 0;
  _Scan(param_4);
  if ((*(int *)(param_4 + 0x42e) == 6) && (*(int *)(param_4 + 0x18) == 0x2e)) {
    local_8 = 0;
  }
  else {
    if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) {
      psVar3 = _T(L"Bad module name");
      return psVar3;
    }
    if (0x1f < *(int *)(param_4 + 0x22a)) {
      psVar3 = _T(L"Length of module name is limited to 31 character");
      return psVar3;
    }
    FUN_004ecff0();
    iVar5 = msvc::strcmp((short *)(param_4 + 0x2a),L"_INTERN_");
    if (iVar5 == 0) {
      local_1c = 1;
    }
    local_8 = _StrcopyW(local_2fc,0x100,(wchar_t *)(param_4 + 0x2a));
    _Scan(param_4);
    if ((*(int *)(param_4 + 0x42e) != 6) || (*(int *)(param_4 + 0x18) != 0x2e)) {
      psVar3 = _T(L"Point after module name expected");
      return psVar3;
    }
  }
  *(undefined2 *)((int)local_2fc + local_8 * 2) = 0x2e;
  local_8 += 1;
  _Scan(param_4);
  if ((*(int *)(param_4 + 0x42e) == 2) || (*(int *)(param_4 + 0x42e) == 3)) {
    if ((int)(local_8 + *(int *)(param_4 + 0x22a)) < 0x100) {
      uVar4 = _StrcopyW((wchar_t *)((int)local_2fc + local_8 * 2),0x100 - local_8,
                        (wchar_t *)(param_4 + 0x2a));
      local_8 += uVar4;
      local_c = 0;
      local_24 = 0;
      local_28 = 0;
      local_14 = 0;
      local_10 = 0;
      local_20 = 0;
      do {
        local_3c = local_9c + local_c;
        local_30 = &uStack256 + local_c;
LAB_0047ba4b:
        _Scan(param_4);
        if (*(int *)(param_4 + 0x42e) != 1) {
          if ((*(int *)(param_4 + 0x42e) == 6) && (*(int *)(param_4 + 0x18) == 0x2e2e2e)) {
            if ((param_5 & 2) != 0) {
              psVar3 = _T(L"Variable number of arguments is not allowed for PASCAL or STDFUNC");
              return psVar3;
            }
            if (local_c == 0) {
              psVar3 = _T(L"Ellipsis (...) as first and only argument is not allowed");
              return psVar3;
            }
            if ((param_5 & 8) != 0) {
              psVar3 = _T(L"Duplicated ellipsis");
              return psVar3;
            }
            param_5 |= 8;
          }
          else {
            if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) {
              psVar3 = _T(L"Keyword or name of type expected");
              return psVar3;
            }
            iVar5 = FUN_004e7a58(param_4 + 0x2a,L"END");
            if (iVar5 == 0) {
              if (1 < local_20) {
                psVar3 = _T(L"Function contains too many formats");
                return psVar3;
              }
              local_2c = (uint *)FUN_004041a0();
              if (local_2c == (uint *)0x0) {
                psVar3 = _T(L"Low memory, processing interrupted");
                return psVar3;
              }
              *local_2c = param_5;
              *(undefined *)(local_2c + 1) = (undefined)local_c;
              *(undefined *)((int)local_2c + 5) = (undefined)local_28;
              *(int *)((int)local_2c + 6) = local_24;
              uVar4 = local_c * 8 + 10;
              if (((param_5 & 8) != 0) && (0 < local_c)) {
                *local_30 = *local_30 | 0x20;
              }
              local_38 = local_fc;
              iVar5 = 0;
              local_34 = local_9c;
              piVar8 = (int *)((int)local_2c + 10);
              if (0 < local_c) {
                do {
                  *piVar8 = *local_34;
                  *(undefined2 *)(piVar8 + 1) = *local_38;
                  *(short *)((int)piVar8 + 6) = (short)uVar4;
                  uVar6 = _StrcopyW((wchar_t *)((int)local_2c + uVar4),0x100,
                                    (wchar_t *)(&stack0xffffcd04 + iVar5 * 0x200));
                  local_38 = local_38 + 2;
                  local_34 = local_34 + 1;
                  iVar5 += 1;
                  uVar4 = (uVar6 + 1) * 2 + uVar4;
                  piVar8 = piVar8 + 2;
                } while (iVar5 < local_c);
              }
              if ((globals::g_Arg_TableFunctions_Capacity <=
                   (int)globals::g_Arg_TableFunctions_Count) &&
                 (globals::g_Arg_TableFunctions =
                       _Memdouble(globals::g_Arg_TableFunctions,
                                  &globals::g_Arg_TableFunctions_Capacity,4,(int *)&DAT_005ebc70,1),
                 globals::g_Arg_TableFunctions_Capacity <= (int)globals::g_Arg_TableFunctions_Count)
                 ) {
                psVar3 = _T(L"Low memory, processing interrupted");
                return psVar3;
              }
              if (((int)globals::g_Arg_TableAll_Capacity <
                   (int)(globals::g_Arg_TableAll_Count + uVar4)) &&
                 (globals::g_Arg_TableAll =
                       _Memdouble(globals::g_Arg_TableAll,(int *)&globals::g_Arg_TableAll_Capacity,1
                                  ,(int *)&DAT_005ebc70,1),
                 (int)globals::g_Arg_TableAll_Capacity <
                 (int)(globals::g_Arg_TableAll_Count + uVar4))) {
                psVar3 = _T(L"Low memory, processing interrupted");
                return psVar3;
              }
              iVar5 = FindInTableUnk__00478d08
                                ((short *)local_2fc,(int *)&globals::g_Arg_TableFunctions);
              if (iVar5 == 0) {
                iVar5 = ArgCreateEntry(globals::g_Arg_TableAll_Count,local_2fc,local_8);
                uVar6 = globals::g_Arg_TableFunctions_Count;
                globals::g_Arg_TableFunctions_Count += 1;
                globals::g_Arg_TableFunctions[uVar6] = iVar5;
                globals::g_Arg_TableFunctions_IsUsed = 1;
              }
              else {
                psVar3 = _T(L"  Redefined procedure \'%s\'");
                _Addtolist(0,2,(int)psVar3);
                *(uint *)(DAT_005e9e20 + iVar5) = globals::g_Arg_TableAll_Count;
              }
              if (local_1c == 0) {
                globals::g_Arg_NumFunctions += 1;
              }
              FUN_004e74f4((undefined4 *)
                           ((int)globals::g_Arg_TableAll + globals::g_Arg_TableAll_Count),local_2c,
                           uVar4);
              globals::g_Arg_TableAll_Count += uVar4;
              return (short *)0x0;
            }
            iVar5 = FUN_004e7a58(param_4 + 0x2a,L"RETURNS");
            if (iVar5 == 0) {
              if (local_10 != 0) {
                psVar3 = _T(L"Duplicated RETURNS");
                return psVar3;
              }
              _Scan(param_4);
              if ((*(int *)(param_4 + 0x42e) == 6) && (*(int *)(param_4 + 0x18) == 0x2a)) {
                bVar2 = true;
                _Scan(param_4);
              }
              else {
                bVar2 = false;
              }
              if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) {
                psVar3 = _T(L"Return type expected");
                return psVar3;
              }
              local_24 = FindInTableUnk__00478d08
                                   ((short *)(param_4 + 0x2a),&globals::g_Arg_TableTypes);
              if (local_24 == 0) {
                local_24 = FindInTableUnk__00478d08
                                     ((short *)(param_4 + 0x2a),&globals::g_Arg_TableStructures);
                if (local_24 == 0) {
                  psVar3 = _T(L"Undefined return type or structure");
                  return psVar3;
                }
                if (!bVar2) {
                  psVar3 = _T(L"Can\'t return structure, only pointer to structure");
                  return psVar3;
                }
                local_28 = 0x43;
              }
              else {
                if (bVar2) {
                  local_28 = 0x41;
                }
                else {
                  local_28 = 0x40;
                }
              }
              local_10 = 1;
            }
            else {
              iVar5 = FUN_004e7a58(param_4 + 0x2a,L"PRESERVES");
              if (iVar5 == 0) {
                if (local_14 != 0) {
                  psVar3 = _T(L"Duplicated PRESERVES");
                  return psVar3;
                }
                do {
                  _Scan(param_4);
                  if (*(int *)(param_4 + 0x42e) != 2) {
                    psVar3 = _T(L"Register name expected");
                    return psVar3;
                  }
                  FUN_004ecff0();
                  iVar5 = 0;
                  ppuVar9 = &PTR_DAT_0052fc84;
                  do {
                    iVar7 = msvc::strcmp((short *)(param_4 + 0x2a),(short *)*ppuVar9);
                    if (iVar7 == 0) break;
                    iVar5 += 1;
                    ppuVar9 = (undefined **)((short **)ppuVar9 + 1);
                  } while (iVar5 < 8);
                  if (7 < iVar5) {
                    psVar3 = _T(L"Register name expected");
                    return psVar3;
                  }
                  param_5 |= 0x100 << ((byte)iVar5 & 0x1f);
                  _Scan(param_4);
                  if ((*(int *)(param_4 + 0x42e) == 0) || (*(int *)(param_4 + 0x42e) == 1))
                  goto LAB_0047bef3;
                  if ((*(int *)(param_4 + 0x42e) != 6) || (*(int *)(param_4 + 0x18) != 0x2c)) {
                    psVar3 = _T(L"Comma between register names expected");
                    return psVar3;
                  }
                } while( true );
              }
              if ((param_5 & 8) != 0) {
                psVar3 = _T(L"Ellipsis (...) must be last in the list of arguments");
                return psVar3;
              }
              if (0x17 < local_c) {
                psVar3 = _T(L"Too many arguments");
                return psVar3;
              }
              local_30[1] = 0x40;
              iVar5 = FUN_004e7a58(param_4 + 0x2a,L"MARK");
              if (iVar5 == 0) {
                local_30[1] = local_30[1] | 0x10;
                _Scan(param_4);
              }
              if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) {
                psVar3 = _T(L"Keyword or name of type expected");
                return psVar3;
              }
              iVar5 = FUN_004e7a58(param_4 + 0x2a,L"OUT");
              if (iVar5 == 0) {
                _Scan(param_4);
                if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) {
                  psVar3 = _T(L"Type name expected");
                  return psVar3;
                }
                iVar5 = FUN_004e7a58(param_4 + 0x2a,L"ASCII");
                if ((iVar5 == 0) || (iVar5 = FUN_004e7a58(param_4 + 0x2a,L"UNICODE"), iVar5 == 0)) {
                  bVar2 = true;
                }
                else {
                  bVar2 = false;
                }
                local_30[1] = local_30[1] | 8;
              }
              else {
                bVar2 = false;
              }
              if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) {
                psVar3 = _T(L"Type name expected");
                return psVar3;
              }
              iVar5 = FindInTableUnk__00478d08((short *)(param_4 + 0x2a),&globals::g_Arg_TableTypes)
              ;
              bVar10 = iVar5 == 0;
              if (bVar10) {
                iVar5 = FindInTableUnk__00478d08
                                  ((short *)(param_4 + 0x2a),&globals::g_Arg_TableStructures);
              }
              local_18 = (uint)bVar10;
              _Scan(param_4);
              if ((*(int *)(param_4 + 0x42e) == 6) && (*(int *)(param_4 + 0x18) == 0x2a)) {
                if (iVar5 == 0) {
                  psVar3 = _T(L"Pointer to undefined type or structure");
                  return psVar3;
                }
                uVar4 = 1;
                if (local_18 != 0) {
                  uVar4 = 3;
                }
                local_30[1] = local_30[1] | uVar4;
                _Scan(param_4);
              }
              else {
                if (iVar5 == 0) {
                  psVar3 = _T(L"Undefined type");
                  return psVar3;
                }
                if (local_18 != 0) {
                  psVar3 = _T(L"Structure is not allowed, only pointer to structure");
                  return psVar3;
                }
                if (((*(byte *)(local_30 + 1) & 8) != 0) && (!bVar2)) {
                  psVar3 = _T(L"OUT applies only to pointers");
                  return psVar3;
                }
                pbVar1 = param_4 + 0x2a;
                iVar7 = FUN_004e7a58(pbVar1,L"FORMAT");
                if ((((iVar7 == 0) || (iVar7 = FUN_004e7a58(pbVar1,L"WFORMAT"), iVar7 == 0)) ||
                    (iVar7 = FUN_004e7a58(pbVar1,L"SCAN"), iVar7 == 0)) ||
                   (iVar7 = FUN_004e7a58(pbVar1,L"WSCAN"), iVar7 == 0)) {
                  local_20 += 1;
                }
                local_30[1] = local_30[1];
              }
              if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) {
                psVar3 = _T(L"Bad parameter name");
                return psVar3;
              }
              _StrcopyW((wchar_t *)(&stack0xffffcd04 + local_c * 0x200),0x100,
                        (wchar_t *)(param_4 + 0x2a));
              *local_3c = iVar5;
              local_c += 1;
              local_3c = local_3c + 1;
              local_30 = local_30 + 1;
            }
          }
          goto LAB_0047c181;
        }
      } while( true );
    }
    psVar3 = _T(L"Too long function name");
  }
  else {
    psVar3 = _T(L"Bad function name");
  }
  return psVar3;
LAB_0047bef3:
  local_14 = 1;
LAB_0047c181:
  _Scan(param_4);
  if ((*(int *)(param_4 + 0x42e) != 0) && (*(int *)(param_4 + 0x42e) != 1)) {
    psVar3 = _T(L"Extra characters on line");
    return psVar3;
  }
  goto LAB_0047ba4b;
}

