
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short * __stdcall olly::ParseSTRUCT(byte *param_4)

{
  byte bVar1;
  short *psVar2;
  int iVar3;
  int iVar4;
  uint *puVar5;
  uint uVar6;
  undefined2 *puVar7;
  uint *puVar8;
  ushort uVar9;
  uint *puVar10;
  byte *pbVar11;
  uint uVar12;
  wchar_t local_136c [16];
  byte local_132c [300];
  byte local_1200 [300];
  ushort local_10d4 [300];
  uint local_e7c [300];
  uint local_9cc [300];
  uint local_51c [300];
  uint *local_6c;
  uint *local_68;
  byte *local_64;
  byte *local_60;
  ushort *local_5c;
  uint *local_58;
  uint *local_54;
  byte *local_50;
  byte *local_4c;
  ushort *local_48;
  int local_44;
  int *local_40;
  undefined4 *local_3c;
  byte local_35;
  uint local_34;
  int local_30;
  uint local_2c;
  int local_28;
  int local_24;
  int local_20;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  int local_c;
  int local_8;
  
  iVar3 = 9;
  do {
    local_8 = iVar3;
    iVar3 = local_8 + -1;
  } while (local_8 + -1 != 0);
  _Scan(param_4);
  if ((*(int *)(param_4 + 0x42e) == 2) || (*(int *)(param_4 + 0x42e) == 3)) {
    if (*(int *)(param_4 + 0x22a) < 0x1f) {
      local_10 = _StrcopyW(local_136c,0x1f,(wchar_t *)(param_4 + 0x2a));
      local_3c = (undefined4 *)FUN_004041a0();
      if (local_3c == (undefined4 *)0x0) {
        psVar2 = _T(L"Low memory, processing interrupted");
      }
      else {
        uVar12 = 0;
        local_18 = 0;
        local_30 = 0;
        while( true ) {
          while( true ) {
            do {
              _Scan(param_4);
            } while (*(int *)(param_4 + 0x42e) == 1);
            if (*(int *)(param_4 + 0x42e) != 2) {
              psVar2 = _T(L"Expecting field size or END");
              return psVar2;
            }
            iVar3 = FUN_004e7a58(param_4 + 0x2a,L"END");
            if (iVar3 == 0) {
              if (local_18 == 0) {
                psVar2 = _T(L"Empty structures are not allowed");
                return psVar2;
              }
              local_14 = local_18 * 0xe + 6;
              if ((DAT_005e9e5c <= DAT_005e9e60) &&
                 (DAT_005e9e58 = _Memdouble(DAT_005e9e58,&DAT_005e9e5c,4,(int *)&DAT_005ebc70,1),
                 DAT_005e9e5c <= DAT_005e9e60)) {
                psVar2 = _T(L"Low memory, processing interrupted");
                return psVar2;
              }
              if ((DAT_005e9e30 < (int)(DAT_005e9e34 + local_14 + uVar12)) &&
                 (DAT_005e9e2c = _Memdouble(DAT_005e9e2c,&DAT_005e9e30,1,(int *)&DAT_005ebc70,1),
                 DAT_005e9e30 < (int)(DAT_005e9e34 + local_14 + uVar12))) {
                psVar2 = _T(L"Low memory, processing interrupted");
                return psVar2;
              }
              iVar3 = FUN_00478d08((short *)local_136c,(int *)&DAT_005e9e58);
              if (iVar3 == 0) {
                iVar4 = FUN_00478c44(DAT_005e9e34,local_136c,local_10);
                iVar3 = DAT_005e9e60;
                DAT_005e9e60 += 1;
                DAT_005e9e58[iVar3] = iVar4;
                _DAT_005e9e64 = 1;
              }
              else {
                psVar2 = _T(L"  Redefined structure \'%s\'");
                _Addtolist(0,2,(int)psVar2);
                *(int *)(DAT_005e9e20 + iVar3) = DAT_005e9e34;
              }
              globals::g_Arg_NumStructures += 1;
              local_40 = (int *)((int)DAT_005e9e2c + DAT_005e9e34);
              *local_40 = local_30;
              *(undefined2 *)(local_40 + 1) = (undefined2)local_18;
              local_8 = 0;
              local_54 = local_51c;
              local_50 = local_132c;
              local_4c = local_1200;
              local_48 = local_10d4;
              puVar5 = (uint *)((int)local_40 + 6);
              puVar8 = local_e7c;
              puVar10 = local_9cc;
              if (0 < local_18) {
                do {
                  uVar6 = *puVar10;
                  puVar10 = puVar10 + 1;
                  *puVar5 = uVar6;
                  uVar6 = *puVar8;
                  puVar8 = puVar8 + 1;
                  puVar5[1] = uVar6;
                  *(ushort *)(puVar5 + 2) = *local_48;
                  *(byte *)((int)puVar5 + 10) = *local_4c;
                  *(byte *)((int)puVar5 + 0xb) = *local_50;
                  *(short *)(puVar5 + 3) = *(short *)local_54 + (short)local_14;
                  puVar5 = (uint *)((int)puVar5 + 0xe);
                  local_8 += 1;
                  local_54 = local_54 + 1;
                  local_50 = local_50 + 1;
                  local_4c = local_4c + 1;
                  local_48 = local_48 + 1;
                } while (local_8 < local_18);
              }
              FUN_004e74f4((undefined4 *)((int)DAT_005e9e2c + local_14 + DAT_005e9e34),local_3c,
                           uVar12);
              DAT_005e9e34 += uVar12 + local_14;
              return (short *)0x0;
            }
            if (299 < local_18) {
              psVar2 = _T(L"Too many items");
              return psVar2;
            }
            iVar3 = FUN_004e7a58(param_4 + 0x2a,L"BYTE");
            if (iVar3 == 0) {
              local_28 = 1;
            }
            else {
              iVar3 = FUN_004e7a58(param_4 + 0x2a,L"WORD");
              if (iVar3 == 0) {
                local_28 = 2;
              }
              else {
                iVar3 = FUN_004e7a58(param_4 + 0x2a,L"THREE");
                if (iVar3 == 0) {
                  local_28 = 3;
                }
                else {
                  iVar3 = FUN_004e7a58(param_4 + 0x2a,L"DWORD");
                  if (iVar3 == 0) {
                    local_28 = 4;
                  }
                  else {
                    iVar3 = FUN_004e7a58(param_4 + 0x2a,L"QWORD");
                    if (iVar3 == 0) {
                      local_28 = 8;
                    }
                    else {
                      iVar3 = FUN_004e7a58(param_4 + 0x2a,L"TBYTE");
                      if (iVar3 != 0) {
                        psVar2 = _T(L"Field size expected");
                        return psVar2;
                      }
                      local_28 = 10;
                    }
                  }
                }
              }
            }
            _Scan(param_4);
            if ((*(int *)(param_4 + 0x42e) == 6) && (*(int *)(param_4 + 0x18) == 0x2a)) {
              iVar3 = FUN_00478c00(param_4,&local_2c);
              if (iVar3 != 0) {
                psVar2 = _T(L"Invalid repeat count");
                return psVar2;
              }
              if ((0x8000 < local_2c) || (0x8000 < local_28 * local_2c)) {
                psVar2 = _T(L"Repeat count outside of allowed limits");
                return psVar2;
              }
              _Scan(param_4);
            }
            else {
              local_2c = 1;
            }
            if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) {
              psVar2 = _T(L"Type name expected");
              return psVar2;
            }
            uVar6 = FUN_00478d08((short *)(param_4 + 0x2a),&DAT_005e9e38);
            if (uVar6 == 0) {
              uVar6 = FUN_00478d08((short *)(param_4 + 0x2a),(int *)&DAT_005e9e58);
              local_24 = 1;
              local_35 = 4;
            }
            else {
              local_24 = 0;
              iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"CHAR");
              if ((iVar3 == 0) ||
                 (iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"ATEXT"), iVar3 == 0)) {
                local_35 = 9;
              }
              else {
                iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"WCHAR");
                if ((iVar3 == 0) ||
                   (iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"WTEXT"), iVar3 == 0)) {
                  local_35 = 0xb;
                }
                else {
                  iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"FLOAT");
                  if (iVar3 == 0) {
                    if (local_28 != 4) {
                      psVar2 = _T(L"Invalid size of FLOAT");
                      return psVar2;
                    }
                    local_35 = 0xd;
                  }
                  else {
                    iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"DOUBLE");
                    if (iVar3 == 0) {
                      if (local_28 != 8) {
                        psVar2 = _T(L"Invalid size of DOUBLE");
                        return psVar2;
                      }
                      local_35 = 0xd;
                    }
                    else {
                      iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"LDOUBLE");
                      if (iVar3 == 0) {
                        if (local_28 != 10) {
                          psVar2 = _T(L"Invalid size of LDOUBLE");
                          return psVar2;
                        }
                        local_35 = 0xd;
                      }
                      else {
                        iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"ASCII");
                        if ((((((iVar3 == 0) ||
                               (iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"UNICODE"),
                               iVar3 == 0)) ||
                              (iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"FORMAT"), iVar3 == 0
                              )) || ((iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"WFORMAT"),
                                     iVar3 == 0 ||
                                     (iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"SCAN"),
                                     iVar3 == 0)))) ||
                            (((iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"WSCAN"), iVar3 == 0
                              || ((iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"VOIDPTR"),
                                  iVar3 == 0 ||
                                  (iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"CALLBACK"),
                                  iVar3 == 0)))) ||
                             (iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"WINPROCA"),
                             iVar3 == 0)))) ||
                           (iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"WINPROCW"), iVar3 == 0)
                           ) {
                          if (local_28 != 4) {
                            psVar2 = _T(L"Invalid pointer size");
                            return psVar2;
                          }
                          local_35 = 4;
                        }
                        else {
                          iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"VOID");
                          if ((((iVar3 == 0) ||
                               (iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"HEXDATA"),
                               iVar3 == 0)) ||
                              (iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"INT"), iVar3 == 0))
                             || (iVar3 = msvc::strcmp((short *)(param_4 + 0x2a),L"UINT"), iVar3 == 0
                                )) {
                            local_35 = 6;
                          }
                          else {
                            local_35 = 4;
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
            _Scan(param_4);
            if ((*(int *)(param_4 + 0x42e) == 6) && (*(int *)(param_4 + 0x18) == '*')) break;
            if (uVar6 == 0) {
              psVar2 = _T(L"Undefined type");
              return psVar2;
            }
            if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) {
              psVar2 = _T(L"Bad item name");
              return psVar2;
            }
            if (local_24 == 0) {
              local_9cc[local_18] = local_28 * local_2c;
              local_30 += local_9cc[local_18];
              local_10d4[local_18] = 0x40;
              local_1200[local_18] = local_35;
              local_132c[local_18] = (byte)local_28;
              FUN_004e74f4((undefined4 *)((int)local_3c + uVar12),(undefined4 *)(param_4 + 0x2a),
                           (*(int *)(param_4 + 0x22a) + 1) * 2);
              local_51c[local_18] = uVar12;
              iVar3 = *(int *)(param_4 + 0x22a);
              local_e7c[local_18] = uVar6;
              uVar12 = (iVar3 + 1) * 2 + uVar12;
              local_18 += 1;
            }
            else {
              local_44 = DAT_005e9e20 + uVar6;
              local_20 = _Getstructureitemcount();
              if ((local_20 == 0) || (0x20 < local_20)) {
                psVar2 = _T(L"Child structure is too comlex");
                return psVar2;
              }
              if ((local_34 == 0) ||
                 ((int)(((longlong)local_28 * (longlong)(int)local_2c & 0xffffffffU) %
                       (ulonglong)local_34) != 0)) {
                psVar2 = _T(L"Size of field is not multiple of child structure");
                return psVar2;
              }
              iVar3 = _Decodestructure();
              if (iVar3 != local_20) {
                psVar2 = _T(L"Unable to get description of child structure");
                return psVar2;
              }
              local_1c = (int)(((longlong)local_28 * (longlong)(int)local_2c & 0xffffffffU) /
                              (ulonglong)local_34);
              local_8 = 0;
              if (0 < local_1c) {
                do {
                  local_c = 0;
                  local_6c = local_e7c + local_18;
                  local_68 = local_51c + local_18;
                  local_64 = local_132c + local_18;
                  local_60 = local_1200 + local_18;
                  local_5c = local_10d4 + local_18;
                  local_58 = local_9cc + local_18;
                  pbVar11 = &stack0xffff62a2;
                  uVar6 = uVar12;
                  if (0 < local_20) {
                    do {
                      if (299 < local_18) {
                        psVar2 = _T(L"Too many items");
                        return psVar2;
                      }
                      uVar12 = _StrcopyW((wchar_t *)((int)local_3c + uVar6),0x100,
                                         (wchar_t *)(param_4 + 0x2a));
                      if (0xf0 < (int)uVar12) {
                        psVar2 = _T(L"Resulting name of child structure member is too long");
                        return psVar2;
                      }
                      if (local_1c == 1) {
                        puVar7 = (undefined2 *)
                                 _StrcopyW((wchar_t *)((int)local_3c + uVar12 * 2 + uVar6),0x100,
                                           (wchar_t *)L".");
                      }
                      else {
                        puVar7 = (undefined2 *)((int)local_3c + uVar12 * 2 + uVar6);
                        FUN_004eafd0(puVar7,(ushort *)L"[%i.].");
                      }
                      iVar3 = uVar12 + (int)puVar7;
                      uVar12 = _StrcopyW((wchar_t *)((int)local_3c + iVar3 * 2 + uVar6),
                                         0x100 - iVar3,
                                         (wchar_t *)(&stack0xffff62e4 + local_c * 0x450));
                      bVar1 = *pbVar11;
                      *local_58 = (uint)bVar1;
                      uVar12 = (iVar3 + uVar12 + 1) * 2 + uVar6;
                      local_30 = local_30 + (uint)bVar1;
                      *local_5c = *(ushort *)(pbVar11 + 2);
                      *local_60 = pbVar11[-1];
                      *local_64 = *pbVar11;
                      *local_68 = uVar6;
                      if ((*local_5c & 6) == 2) {
                        uVar6 = FUN_00478d08((short *)(&stack0xffff62a6 + local_c * 0x450),
                                             (int *)&DAT_005e9e58);
                        *local_6c = uVar6;
                      }
                      else {
                        uVar6 = FUN_00478d08((short *)(&stack0xffff62a6 + local_c * 0x450),
                                             &DAT_005e9e38);
                        *local_6c = uVar6;
                      }
                      if (*local_6c == 0) {
                        psVar2 = _T(L"Undefined child member type");
                        return psVar2;
                      }
                      local_18 += 1;
                      local_6c = local_6c + 1;
                      local_68 = local_68 + 1;
                      local_64 = local_64 + 1;
                      local_60 = local_60 + 1;
                      local_5c = local_5c + 1;
                      local_58 = local_58 + 1;
                      local_c += 1;
                      pbVar11 = pbVar11 + 0x450;
                      uVar6 = uVar12;
                    } while (local_c < local_20);
                  }
                  local_8 += 1;
                } while (local_8 < local_1c);
              }
            }
          }
          if (uVar6 == 0) {
            psVar2 = _T(L"Pointer to undefined type or structure");
            return psVar2;
          }
          if (local_28 != 4) {
            psVar2 = _T(L"Invalid pointer size");
            return psVar2;
          }
          local_9cc[local_18] = local_2c * 4;
          uVar9 = 1;
          local_30 += local_9cc[local_18];
          if (local_24 != 0) {
            uVar9 = 3;
          }
          local_10d4[local_18] = uVar9 | 0x40;
          local_1200[local_18] = 4;
          _Scan(param_4);
          local_132c[local_18] = (byte)local_28;
          if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) break;
          FUN_004e74f4((undefined4 *)((int)local_3c + uVar12),(undefined4 *)(param_4 + 0x2a),
                       (*(int *)(param_4 + 0x22a) + 1) * 2);
          local_51c[local_18] = uVar12;
          iVar3 = *(int *)(param_4 + 0x22a);
          local_e7c[local_18] = uVar6;
          uVar12 = (iVar3 + 1) * 2 + uVar12;
          local_18 += 1;
        }
        psVar2 = _T(L"Bad item name");
      }
    }
    else {
      psVar2 = _T(L"Length of structure name is limited to 30 characters");
    }
  }
  else {
    psVar2 = _T(L"Bad structure name");
  }
  return psVar2;
}

