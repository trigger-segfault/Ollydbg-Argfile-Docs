
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

short * __stdcall olly::ParseTYPE(byte *param_4)

{
  int *piVar1;
  short *psVar2;
  undefined4 *puVar3;
  int iVar4;
  int *piVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  int *local_30;
  int *local_2c;
  int local_28;
  int local_24;
  undefined4 local_20;
  int local_1c;
  int local_18;
  int local_14;
  int local_10;
  int local_c;
  uint local_8;
  
  iVar6 = 2;
  do {
    local_8 = iVar6;
    iVar6 = local_8 + -1;
  } while (local_8 + -1 != 0);
  _Scan(param_4);
  if ((*(int *)(param_4 + 0x42e) == 2) || (*(int *)(param_4 + 0x42e) == 3)) {
    if (*(int *)(param_4 + 0x22a) < 0x1f) {
      local_8 = _StrcopyW((wchar_t *)&stack0xffffdf90,0x1f,(wchar_t *)(param_4 + 0x2a));
      puVar3 = (undefined4 *)FUN_004041a0();
      if (puVar3 != (undefined4 *)0x0) {
        local_c = 0;
        local_10 = 0;
        local_14 = 0;
        iVar6 = 0;
        do {
          local_2c = (int *)(&stack0xffffdec4 + local_10 * 0xc);
          while( true ) {
            pbVar8 = param_4;
            _Scan(param_4);
            iVar4 = *(int *)(param_4 + 0x42e);
            if (iVar4 == 1) break;
            if (iVar4 == 3) {
              if (0x10000 < (uint)(iVar6 + 1 + (*(int *)(param_4 + 0x22a) + 1) * 2)) {
                psVar2 = _T(L"Type description is too long");
                return psVar2;
              }
              *(undefined *)((int)puVar3 + iVar6) = 0x10;
              FUN_004e74f4((undefined4 *)(iVar6 + 1 + (int)puVar3),(undefined4 *)(param_4 + 0x2a),
                           (*(int *)(param_4 + 0x22a) + 1) * 2);
              iVar6 = (*(int *)(param_4 + 0x22a) + 1) * 2 + iVar6 + 1;
              break;
            }
            if (*(int *)(param_4 + 0x42e) != 2) {
              psVar2 = _T(L"Keyword expected");
              return psVar2;
            }
            FUN_004ecff0(iVar4,param_4 + 0x2a,pbVar8);
            iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"END");
            if (iVar4 == 0) {
              if ((0 < local_10) && (*local_2c == 0)) {
                psVar2 = _T(L"ENDSEL expected");
                return psVar2;
              }
              if ((0 < local_10) && (*local_2c != 0)) {
                psVar2 = _T(L"ENDIF expected");
                return psVar2;
              }
              if (0xffff < iVar6) {
                psVar2 = _T(L"Type description is too long");
                return psVar2;
              }
              *(undefined *)((int)puVar3 + iVar6) = 0;
              uVar7 = iVar6 + 1;
              if ((DAT_005e9e3c <= DAT_005e9e40) &&
                 (DAT_005e9e38 = _Memdouble(DAT_005e9e38,&DAT_005e9e3c,4,(int *)&DAT_005ebc70,1),
                 DAT_005e9e3c <= DAT_005e9e40)) {
                psVar2 = _T(L"Low memory, processing interrupted");
                return psVar2;
              }
              if ((DAT_005e9e30 < (int)(DAT_005e9e34 + uVar7)) &&
                 (DAT_005e9e2c = _Memdouble(DAT_005e9e2c,&DAT_005e9e30,1,(int *)&DAT_005ebc70,1),
                 DAT_005e9e30 < (int)(DAT_005e9e34 + uVar7))) {
                psVar2 = _T(L"Low memory, processing interrupted");
                return psVar2;
              }
              local_28 = FUN_00478d08((short *)&stack0xffffdf90,(int *)&DAT_005e9e38);
              if (local_28 == 0) {
                local_24 = FUN_00478c44(DAT_005e9e34,(undefined4 *)&stack0xffffdf90,local_8);
                iVar6 = DAT_005e9e40;
                DAT_005e9e40 += 1;
                DAT_005e9e38[iVar6] = local_24;
                _DAT_005e9e44 = 1;
              }
              else {
                psVar2 = _T(L"  Redefined type \'%s\'");
                _Addtolist(0,2,(int)psVar2);
                *(int *)(DAT_005e9e20 + local_28) = DAT_005e9e34;
              }
              FUN_004e74f4((undefined4 *)((int)DAT_005e9e2c + DAT_005e9e34),puVar3,uVar7);
              DAT_005e9e34 += uVar7;
              globals::g_Arg_NumTypes += 1;
              return (short *)0x0;
            }
            if (0xffff < iVar6) {
              psVar2 = _T(L"Type description is too long");
              return psVar2;
            }
            iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"SELECT");
            if (iVar4 == 0) {
              if (local_c != 0) {
                psVar2 = _T(L"Nesting of SELECT blocks is not allowed");
                return psVar2;
              }
              if (0xf < local_10) {
                psVar2 = _T(L"Too deep block nesting");
                return psVar2;
              }
              if (0x10000 < iVar6 + 5U) {
                psVar2 = _T(L"Type description is too long");
                return psVar2;
              }
              _Scan(param_4);
              if ((*(int *)(param_4 + 0x42e) == 2) &&
                 (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"MASK"), iVar4 == 0)) {
                *(undefined *)((int)puVar3 + iVar6) = 1;
              }
              else {
                if ((*(int *)(param_4 + 0x42e) == 2) &&
                   (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"FIELD"), iVar4 == 0)) {
                  *(undefined *)((int)puVar3 + iVar6) = 2;
                }
                else {
                  if ((*(int *)(param_4 + 0x42e) != 2) ||
                     (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"SIGFIELD"), iVar4 != 0)) {
                    psVar2 = _T(L"Expecting MASK, FIELD or SIGFIELD");
                    return psVar2;
                  }
                  *(undefined *)((int)puVar3 + iVar6) = 3;
                }
              }
              iVar4 = FUN_00478c00(param_4,&local_20);
              if (iVar4 != 0) {
                psVar2 = _T(L"Constant expected");
                return psVar2;
              }
              *(undefined4 *)((int)puVar3 + iVar6 + 1) = local_20;
              iVar6 += 5;
              local_c = 1;
              local_2c[3] = 0;
              local_10 += 1;
              local_2c = local_2c + 3;
            }
            else {
              iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"ENDSEL");
              if (iVar4 == 0) {
                if ((local_10 == 0) || (local_c == 0)) {
                  psVar2 = _T(L"ENDSEL without corresponding SELECT");
                  return psVar2;
                }
                local_10 += -1;
                if (*local_2c != 0) {
                  local_2c = local_2c + -3;
                  psVar2 = _T(L"ENDSEL where ENDIF is expected");
                  return psVar2;
                }
                *(undefined *)((int)puVar3 + iVar6) = 4;
                iVar6 += 1;
                local_c = 0;
                local_2c = local_2c + -3;
              }
              else {
                iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"IF");
                if (((iVar4 == 0) ||
                    (iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"ELSEIF"), iVar4 == 0)) ||
                   (iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"ELIF"), iVar4 == 0)) {
                  if (*(short *)(param_4 + 0x2a) == 0x49) {
                    if (0xf < local_10) {
                      psVar2 = _T(L"Too deep nesting");
                      return psVar2;
                    }
                    local_2c[3] = 1;
                    local_2c[5] = local_14;
                    local_10 += 1;
                    local_2c = local_2c + 3;
                  }
                  else {
                    if (local_10 == 0) {
                      psVar2 = _T(L"ELSEIF without corresponding IF");
                      return psVar2;
                    }
                    if (*local_2c == 0) {
                      psVar2 = _T(L"ELSEIF where ENDSEL is expected");
                      return psVar2;
                    }
                    if (*local_2c == 2) {
                      psVar2 = _T(L"ELSEIF after ELSE");
                      return psVar2;
                    }
                    if (0x10000 < iVar6 + 3) {
                      psVar2 = _T(L"Type description is too long");
                      return psVar2;
                    }
                    *(undefined *)((int)puVar3 + iVar6) = 0xf;
                    if (0x7ff < local_14) {
                      psVar2 = _T(L"Too many ELSEIF statements");
                      return psVar2;
                    }
                    *(int *)(&stack0xffffdfd0 + local_14 * 4) = iVar6 + 1;
                    local_14 += 1;
                    *(undefined *)((int)puVar3 + iVar6 + 1) = 0;
                    *(undefined *)((int)puVar3 + iVar6 + 2) = 0;
                    iVar6 += 3;
                    *(short *)((int)puVar3 + local_2c[1]) = (short)iVar6;
                  }
                  if (0x10000 < iVar6 + 7) {
                    psVar2 = _T(L"Type description is too long");
                    return psVar2;
                  }
                  _Scan(param_4);
                  if ((*(int *)(param_4 + 0x42e) == 2) &&
                     (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"EQ"), iVar4 == 0)) {
                    *(undefined *)((int)puVar3 + iVar6) = 5;
                    iVar6 += 1;
                    iVar4 = FUN_00478c00(param_4,(undefined4 *)(iVar6 + (int)puVar3));
                    if (iVar4 != 0) {
                      psVar2 = _T(L"Constant expected");
                      return psVar2;
                    }
                  }
                  else {
                    if ((*(int *)(param_4 + 0x42e) == 2) &&
                       (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"NE"), iVar4 == 0)) {
                      *(undefined *)((int)puVar3 + iVar6) = 6;
                      iVar6 += 1;
                      iVar4 = FUN_00478c00(param_4,(undefined4 *)(iVar6 + (int)puVar3));
                      if (iVar4 != 0) {
                        psVar2 = _T(L"Constant expected");
                        return psVar2;
                      }
                    }
                    else {
                      if ((*(int *)(param_4 + 0x42e) == 2) &&
                         ((iVar4 = FUN_004e7a58(param_4 + 0x2a,L"SET"), iVar4 == 0 ||
                          (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"BIT"), iVar4 == 0)))) {
                        *(undefined *)((int)puVar3 + iVar6) = 7;
                        iVar6 += 1;
                        iVar4 = FUN_00478c00(param_4,(undefined4 *)(iVar6 + (int)puVar3));
                        if (iVar4 != 0) {
                          psVar2 = _T(L"Constant expected");
                          return psVar2;
                        }
                      }
                      else {
                        if ((*(int *)(param_4 + 0x42e) == 2) &&
                           ((iVar4 = FUN_004e7a58(param_4 + 0x2a,L"ZERO"), iVar4 == 0 ||
                            (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"CLR"), iVar4 == 0)))) {
                          *(undefined *)((int)puVar3 + iVar6) = 8;
                          iVar6 += 1;
                          iVar4 = FUN_00478c00(param_4,(undefined4 *)(iVar6 + (int)puVar3));
                          if (iVar4 != 0) {
                            psVar2 = _T(L"Constant expected");
                            return psVar2;
                          }
                        }
                        else {
                          if ((*(int *)(param_4 + 0x42e) == 2) &&
                             (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"LE"), iVar4 == 0)) {
                            *(undefined *)((int)puVar3 + iVar6) = 9;
                            iVar6 += 1;
                            iVar4 = FUN_00478c00(param_4,(undefined4 *)(iVar6 + (int)puVar3));
                            if (iVar4 != 0) {
                              psVar2 = _T(L"Constant expected");
                              return psVar2;
                            }
                          }
                          else {
                            if ((*(int *)(param_4 + 0x42e) == 2) &&
                               (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"GE"), iVar4 == 0)) {
                              *(undefined *)((int)puVar3 + iVar6) = 10;
                              iVar6 += 1;
                              iVar4 = FUN_00478c00(param_4,(undefined4 *)(iVar6 + (int)puVar3));
                              if (iVar4 != 0) {
                                psVar2 = _T(L"Constant expected");
                                return psVar2;
                              }
                            }
                            else {
                              if ((*(int *)(param_4 + 0x42e) == 2) &&
                                 (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"MASK"), iVar4 == 0)) {
                                iVar4 = FUN_00478c00(param_4,(undefined4 *)(iVar6 + 1 + (int)puVar3)
                                                    );
                                if (iVar4 != 0) {
                                  psVar2 = _T(L"Constant expected");
                                  return psVar2;
                                }
                                _Scan(param_4);
                                if ((*(int *)(param_4 + 0x42e) == 2) &&
                                   (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"EQ"), iVar4 == 0)) {
                                  *(undefined *)((int)puVar3 + iVar6) = 0xb;
                                }
                                else {
                                  if ((*(int *)(param_4 + 0x42e) != 2) ||
                                     (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"NE"), iVar4 != 0)) {
                                    psVar2 = _T(L"\'EQ\' or \'NE\' expected");
                                    return psVar2;
                                  }
                                  *(undefined *)((int)puVar3 + iVar6) = 0xc;
                                }
                                iVar6 += 5;
                                iVar4 = FUN_00478c00(param_4,(undefined4 *)(iVar6 + (int)puVar3));
                                if (iVar4 != 0) {
                                  psVar2 = _T(L"Constant expected");
                                  return psVar2;
                                }
                              }
                              else {
                                if ((*(int *)(param_4 + 0x42e) == 2) &&
                                   (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"FIELD"), iVar4 == 0)) {
                                  iVar4 = FUN_00478c00(param_4,(undefined4 *)
                                                               (iVar6 + 1 + (int)puVar3));
                                  if (iVar4 != 0) {
                                    psVar2 = _T(L"Constant expected");
                                    return psVar2;
                                  }
                                  _Scan(param_4);
                                  if ((*(int *)(param_4 + 0x42e) == 2) &&
                                     (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"EQ"), iVar4 == 0)) {
                                    *(undefined *)((int)puVar3 + iVar6) = 0xd;
                                  }
                                  else {
                                    if ((*(int *)(param_4 + 0x42e) != 2) ||
                                       (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"NE"), iVar4 != 0)) {
                                      psVar2 = _T(L"\'EQ\' or \'NE\' expected");
                                      return psVar2;
                                    }
                                    *(undefined *)((int)puVar3 + iVar6) = 0xe;
                                  }
                                  iVar6 += 5;
                                  iVar4 = FUN_00478c00(param_4,(undefined4 *)(iVar6 + (int)puVar3));
                                  if (iVar4 != 0) {
                                    psVar2 = _T(L"Constant expected");
                                    return psVar2;
                                  }
                                }
                                else {
                                  if ((*(int *)(param_4 + 0x42e) == 2) &&
                                     (iVar4 = _Getconstantbyname((short *)(param_4 + 0x2a),&local_20
                                                                ), iVar4 == 0)) {
                                    *(undefined *)((int)puVar3 + iVar6) = 5;
                                    iVar6 += 1;
                                    *(undefined4 *)((int)puVar3 + iVar6) = local_20;
                                  }
                                  else {
                                    if (*(int *)(param_4 + 0x42e) != 4) {
                                      psVar2 = _T(L"Operation or constant expected");
                                      return psVar2;
                                    }
                                    *(undefined *)((int)puVar3 + iVar6) = 5;
                                    iVar6 += 1;
                                    *(undefined4 *)((int)puVar3 + iVar6) =
                                         *(undefined4 *)(param_4 + 0x18);
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                  local_2c[1] = iVar6 + 4;
                  *(undefined *)((int)puVar3 + iVar6 + 4) = 0;
                  *(undefined *)((int)puVar3 + iVar6 + 5) = 0;
                  iVar6 += 6;
                }
                else {
                  iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"ELSE");
                  if (iVar4 == 0) {
                    if (local_10 == 0) {
                      psVar2 = _T(L"ELSE without corresponding IF");
                      return psVar2;
                    }
                    if (*local_2c == 0) {
                      psVar2 = _T(L"ELSE where ENDSEL is expected");
                      return psVar2;
                    }
                    if (*local_2c == 2) {
                      psVar2 = _T(L"ELSE after ELSE");
                      return psVar2;
                    }
                    if (0x10000 < iVar6 + 3) {
                      psVar2 = _T(L"Type description is too long");
                      return psVar2;
                    }
                    *(undefined *)((int)puVar3 + iVar6) = 0xf;
                    if (0x7ff < local_14) {
                      psVar2 = _T(L"Too many ELSEIF statements");
                      return psVar2;
                    }
                    *(int *)(&stack0xffffdfd0 + local_14 * 4) = iVar6 + 1;
                    local_14 += 1;
                    *(undefined *)((int)puVar3 + iVar6 + 1) = 0;
                    *(undefined *)((int)puVar3 + iVar6 + 2) = 0;
                    iVar6 += 3;
                    *(short *)((int)puVar3 + local_2c[1]) = (short)iVar6;
                    *local_2c = 2;
                  }
                  else {
                    iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"ENDIF");
                    if (iVar4 == 0) {
                      if (local_10 == 0) {
                        psVar2 = _T(L"ENDIF without corresponding IF");
                        return psVar2;
                      }
                      local_10 += -1;
                      piVar1 = local_2c + -3;
                      if (*local_2c == 0) {
                        local_2c = piVar1;
                        psVar2 = _T(L"ENDIF where ENDSEL is expected");
                        return psVar2;
                      }
                      if (*local_2c == 1) {
                        *(short *)((int)puVar3 + local_2c[1]) = (short)iVar6;
                      }
                      piVar5 = (int *)(&stack0xffffdfd0 + local_14 * 4);
                      local_30 = local_2c + 2;
                      while (local_2c = piVar1, *local_30 < local_14) {
                        local_14 += -1;
                        piVar5 = piVar5 + -1;
                        *(short *)((int)puVar3 + *piVar5) = (short)iVar6;
                      }
                    }
                    else {
                      iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"BIT");
                      if (iVar4 == 0) {
                        if (0x10000 < iVar6 + 7) {
                          psVar2 = _T(L"Type description is too long");
                          return psVar2;
                        }
                        *(undefined *)((int)puVar3 + iVar6) = 7;
                        iVar4 = FUN_00478c00(param_4,(undefined4 *)(iVar6 + 1 + (int)puVar3));
                        if (iVar4 != 0) {
                          psVar2 = _T(L"Constant expected");
                          return psVar2;
                        }
                        _Scan(param_4);
                        if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) {
                          psVar2 = _T(L"Text expected");
                          return psVar2;
                        }
                        if (0x10000 < (uint)(iVar6 + 8 + (*(int *)(param_4 + 0x22a) + 1) * 2)) {
                          psVar2 = _T(L"Type description is too long");
                          return psVar2;
                        }
                        *(short *)((int)puVar3 + iVar6 + 5) =
                             (*(short *)(param_4 + 0x22a) + 1) * 2 + (short)(iVar6 + 5) + 3;
                        *(undefined *)((int)puVar3 + iVar6 + 7) = 0x11;
                        FUN_004e74f4((undefined4 *)(iVar6 + 8 + (int)puVar3),
                                     (undefined4 *)(param_4 + 0x2a),
                                     (*(int *)(param_4 + 0x22a) + 1) * 2);
                        iVar6 = (*(int *)(param_4 + 0x22a) + 1) * 2 + iVar6 + 8;
                      }
                      else {
                        iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"HEXBITS");
                        if (iVar4 == 0) {
                          if (0x10000 < iVar6 + 5) {
                            psVar2 = _T(L"Type description is too long");
                            return psVar2;
                          }
                          *(undefined *)((int)puVar3 + iVar6) = 0x12;
                          iVar4 = FUN_00478c00(param_4,(undefined4 *)(iVar6 + 1 + (int)puVar3));
                          if (iVar4 != 0) {
                            psVar2 = _T(L"Constant expected");
                            return psVar2;
                          }
                          iVar6 += 5;
                        }
                        else {
                          iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"TEXT");
                          if (iVar4 == 0) {
                            _Scan(param_4);
                            if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)
                               ) {
                              psVar2 = _T(L"Text expected");
                              return psVar2;
                            }
                            if (0x10000 < (uint)(iVar6 + 1 + (*(int *)(param_4 + 0x22a) + 1) * 2)) {
                              psVar2 = _T(L"Type description is too long");
                              return psVar2;
                            }
                            *(undefined *)((int)puVar3 + iVar6) = 0x10;
                            FUN_004e74f4((undefined4 *)(iVar6 + 1 + (int)puVar3),
                                         (undefined4 *)(param_4 + 0x2a),
                                         (*(int *)(param_4 + 0x22a) + 1) * 2);
                            iVar6 = (*(int *)(param_4 + 0x22a) + 1) * 2 + iVar6 + 1;
                          }
                          else {
                            iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"PURGE");
                            if (iVar4 == 0) {
                              *(undefined *)((int)puVar3 + iVar6) = 0x13;
                              iVar6 += 1;
                            }
                            else {
                              iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"SET");
                              if (iVar4 == 0) {
                                _Scan(param_4);
                                if ((*(int *)(param_4 + 0x42e) != 2) &&
                                   (*(int *)(param_4 + 0x42e) != 3)) {
                                  psVar2 = _T(L"Name expected");
                                  return psVar2;
                                }
                                if (0x10000 < (uint)(iVar6 + 2 + (*(int *)(param_4 + 0x22a) + 1) * 2
                                                    )) {
                                  psVar2 = _T(L"Type description is too long");
                                  return psVar2;
                                }
                                *(undefined *)((int)puVar3 + iVar6) = 0x14;
                                local_18 = iVar6 + 1;
                                *(undefined *)((int)puVar3 + local_18) = 0x40;
                                FUN_004e74f4((undefined4 *)(iVar6 + 2 + (int)puVar3),
                                             (undefined4 *)(param_4 + 0x2a),
                                             (*(int *)(param_4 + 0x22a) + 1) * 2);
                                iVar6 = (*(int *)(param_4 + 0x22a) + 1) * 2 + iVar6 + 2;
                                _Scan(param_4);
                                if ((*(int *)(param_4 + 0x42e) == 2) &&
                                   (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"OUT"), iVar4 == 0)) {
                                  *(byte *)((int)puVar3 + local_18) =
                                       *(byte *)((int)puVar3 + local_18) | 8;
                                  _Scan(param_4);
                                  iVar4 = FUN_004e7a58(param_4 + 0x2a,L"ASCII");
                                  if ((iVar4 == 0) ||
                                     (iVar4 = FUN_004e7a58(param_4 + 0x2a,L"UNICODE"), iVar4 == 0))
                                  {
                                    local_1c = 1;
                                  }
                                  else {
                                    local_1c = 0;
                                  }
                                }
                                else {
                                  local_1c = 0;
                                }
                                if ((*(int *)(param_4 + 0x42e) != 2) &&
                                   (*(int *)(param_4 + 0x42e) != 3)) {
                                  psVar2 = _T(L"Name expected");
                                  return psVar2;
                                }
                                if (0x10000 < (uint)((*(int *)(param_4 + 0x22a) + 1) * 2 + iVar6)) {
                                  psVar2 = _T(L"Type description is too long");
                                  return psVar2;
                                }
                                FUN_004e74f4((undefined4 *)(iVar6 + (int)puVar3),
                                             (undefined4 *)(param_4 + 0x2a),
                                             (*(int *)(param_4 + 0x22a) + 1) * 2);
                                iVar6 = (*(int *)(param_4 + 0x22a) + 1) * 2 + iVar6;
                                _Scan(param_4);
                                if ((*(int *)(param_4 + 0x42e) == 6) &&
                                   (*(int *)(param_4 + 0x18) == 0x2a)) {
                                  *(byte *)((int)puVar3 + local_18) =
                                       *(byte *)((int)puVar3 + local_18) | 1;
                                  _Scan(param_4);
                                }
                                else {
                                  if (((*(byte *)((int)puVar3 + local_18) & 8) != 0) &&
                                     (local_1c == 0)) {
                                    psVar2 = _T(L"OUT applies only to pointers");
                                    return psVar2;
                                  }
                                }
                                if ((*(int *)(param_4 + 0x42e) == 0) ||
                                   (*(int *)(param_4 + 0x42e) == 1)) {
                                  *(undefined2 *)(param_4 + 0x2a) = 0;
                                  *(undefined4 *)(param_4 + 0x22a) = 0;
                                }
                                else {
                                  if ((*(int *)(param_4 + 0x42e) != 2) &&
                                     (*(int *)(param_4 + 0x42e) != 3)) {
                                    psVar2 = _T(L"Name expected");
                                    return psVar2;
                                  }
                                }
                                if (0x10000 < (uint)((*(int *)(param_4 + 0x22a) + 1) * 2 + iVar6)) {
                                  psVar2 = _T(L"Type description is too long");
                                  return psVar2;
                                }
                                FUN_004e74f4((undefined4 *)(iVar6 + (int)puVar3),
                                             (undefined4 *)(param_4 + 0x2a),
                                             (*(int *)(param_4 + 0x22a) + 1) * 2);
                                iVar6 = (*(int *)(param_4 + 0x22a) + 1) * 2 + iVar6;
                              }
                              else {
                                iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"HEX");
                                if (iVar4 == 0) {
                                  *(undefined *)((int)puVar3 + iVar6) = 0x20;
                                  iVar6 += 1;
                                }
                                else {
                                  iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"HEXDATA");
                                  if (iVar4 == 0) {
                                    *(undefined *)((int)puVar3 + iVar6) = 0x21;
                                    iVar6 += 1;
                                  }
                                  else {
                                    iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"HEX8");
                                    if (iVar4 == 0) {
                                      *(undefined *)((int)puVar3 + iVar6) = 0x22;
                                      iVar6 += 1;
                                    }
                                    else {
                                      iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"QUAD_LO");
                                      if (iVar4 == 0) {
                                        *(undefined *)((int)puVar3 + iVar6) = 0x23;
                                        iVar6 += 1;
                                      }
                                      else {
                                        iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"QUAD_HI");
                                        if (iVar4 == 0) {
                                          *(undefined *)((int)puVar3 + iVar6) = 0x24;
                                          iVar6 += 1;
                                        }
                                        else {
                                          iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"INT");
                                          if (iVar4 == 0) {
                                            *(undefined *)((int)puVar3 + iVar6) = 0x25;
                                            iVar6 += 1;
                                          }
                                          else {
                                            iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"UINT");
                                            if (iVar4 == 0) {
                                              *(undefined *)((int)puVar3 + iVar6) = 0x26;
                                              iVar6 += 1;
                                            }
                                            else {
                                              iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),L"BOOL"
                                                                  );
                                              if (iVar4 == 0) {
                                                *(undefined *)((int)puVar3 + iVar6) = 0x27;
                                                iVar6 += 1;
                                              }
                                              else {
                                                iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),
                                                                     L"BYTE");
                                                if (iVar4 == 0) {
                                                  *(undefined *)((int)puVar3 + iVar6) = 0x28;
                                                  iVar6 += 1;
                                                }
                                                else {
                                                  iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),
                                                                       L"CHAR");
                                                  if (iVar4 == 0) {
                                                    *(undefined *)((int)puVar3 + iVar6) = 0x29;
                                                    iVar6 += 1;
                                                  }
                                                  else {
                                                    iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),
                                                                         L"WCHAR");
                                                    if (iVar4 == 0) {
                                                      *(undefined *)((int)puVar3 + iVar6) = 0x2a;
                                                      iVar6 += 1;
                                                    }
                                                    else {
                                                      iVar4 = msvc::strcmp((short *)(param_4 + 0x2a)
                                                                           ,L"WORD");
                                                      if (iVar4 == 0) {
                                                        *(undefined *)((int)puVar3 + iVar6) = 0x2b;
                                                        iVar6 += 1;
                                                      }
                                                      else {
                                                        iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                      0x2a),L"ASCII"
                                                                            );
                                                        if (iVar4 == 0) {
                                                          *(undefined *)((int)puVar3 + iVar6) = 0x2c
                                                          ;
                                                          iVar6 += 1;
                                                        }
                                                        else {
                                                          iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                        0x2a),
                                                                               L"UNICODE");
                                                          if (iVar4 == 0) {
                                                            *(undefined *)((int)puVar3 + iVar6) =
                                                                 0x2d;
                                                            iVar6 += 1;
                                                          }
                                                          else {
                                                            iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                          0x2a),
                                                                                 L"MASCII");
                                                            if (iVar4 == 0) {
                                                              *(undefined *)((int)puVar3 + iVar6) =
                                                                   0x2e;
                                                              iVar6 += 1;
                                                            }
                                                            else {
                                                              iVar4 = msvc::strcmp((short *)(param_4
                                                                                            + 0x2a),
                                                                                   L"MUNICODE");
                                                              if (iVar4 == 0) {
                                                                *(undefined *)((int)puVar3 + iVar6)
                                                                     = 0x2f;
                                                                iVar6 += 1;
                                                              }
                                                              else {
                                                                iVar4 = msvc::strcmp((short *)(
                                                  param_4 + 0x2a),L"FORMAT");
                                                  if (iVar4 == 0) {
                                                    *(undefined *)((int)puVar3 + iVar6) = 0x30;
                                                    iVar6 += 1;
                                                  }
                                                  else {
                                                    iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),
                                                                         L"WFORMAT");
                                                    if (iVar4 == 0) {
                                                      *(undefined *)((int)puVar3 + iVar6) = 0x31;
                                                      iVar6 += 1;
                                                    }
                                                    else {
                                                      iVar4 = msvc::strcmp((short *)(param_4 + 0x2a)
                                                                           ,L"SCAN");
                                                      if (iVar4 == 0) {
                                                        *(undefined *)((int)puVar3 + iVar6) = 0x32;
                                                        iVar6 += 1;
                                                      }
                                                      else {
                                                        iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                      0x2a),L"WSCAN"
                                                                            );
                                                        if (iVar4 == 0) {
                                                          *(undefined *)((int)puVar3 + iVar6) = 0x33
                                                          ;
                                                          iVar6 += 1;
                                                        }
                                                        else {
                                                          iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                        0x2a),
                                                                               L"FLOAT");
                                                          if (iVar4 == 0) {
                                                            *(undefined *)((int)puVar3 + iVar6) =
                                                                 0x34;
                                                            iVar6 += 1;
                                                          }
                                                          else {
                                                            iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                          0x2a),
                                                                                 L"DOUBLE_LO");
                                                            if (iVar4 == 0) {
                                                              *(undefined *)((int)puVar3 + iVar6) =
                                                                   0x35;
                                                              iVar6 += 1;
                                                            }
                                                            else {
                                                              iVar4 = msvc::strcmp((short *)(param_4
                                                                                            + 0x2a),
                                                                                   L"DOUBLE_HI");
                                                              if (iVar4 == 0) {
                                                                *(undefined *)((int)puVar3 + iVar6)
                                                                     = 0x36;
                                                                iVar6 += 1;
                                                              }
                                                              else {
                                                                iVar4 = msvc::strcmp((short *)(
                                                  param_4 + 0x2a),L"LDOUBLE_LO");
                                                  if (iVar4 == 0) {
                                                    *(undefined *)((int)puVar3 + iVar6) = 0x37;
                                                    iVar6 += 1;
                                                  }
                                                  else {
                                                    iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),
                                                                         L"LDOUBLE_MI");
                                                    if (iVar4 == 0) {
                                                      *(undefined *)((int)puVar3 + iVar6) = 0x38;
                                                      iVar6 += 1;
                                                    }
                                                    else {
                                                      iVar4 = msvc::strcmp((short *)(param_4 + 0x2a)
                                                                           ,L"LDOUBLE_HI");
                                                      if (iVar4 == 0) {
                                                        *(undefined *)((int)puVar3 + iVar6) = 0x39;
                                                        iVar6 += 1;
                                                      }
                                                      else {
                                                        iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                      0x2a),
                                                                             L"RSRC_STRING");
                                                        if (iVar4 == 0) {
                                                          *(undefined *)((int)puVar3 + iVar6) = 0x3a
                                                          ;
                                                          iVar6 += 1;
                                                        }
                                                        else {
                                                          iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                        0x2a),
                                                                               L"VOIDPTR");
                                                          if (iVar4 == 0) {
                                                            *(undefined *)((int)puVar3 + iVar6) =
                                                                 0x3b;
                                                            iVar6 += 1;
                                                          }
                                                          else {
                                                            iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                          0x2a),
                                                                                 L"GROUP");
                                                            if (iVar4 == 0) {
                                                              _Scan(param_4);
                                                              if ((*(int *)(param_4 + 0x42e) != 2)
                                                                 && (*(int *)(param_4 + 0x42e) != 3)
                                                                 ) {
                                                                psVar2 = _T(L"Name expected");
                                                                return psVar2;
                                                              }
                                                              if (0x10000 < (uint)(iVar6 + 1 +
                                                                                  (*(int *)(param_4 
                                                  + 0x22a) + 1) * 2)) {
                                                    psVar2 = _T(L"Type description is too long");
                                                    return psVar2;
                                                  }
                                                  *(undefined *)((int)puVar3 + iVar6) = 0x3d;
                                                  FUN_004e74f4((undefined4 *)
                                                               (iVar6 + 1 + (int)puVar3),
                                                               (undefined4 *)(param_4 + 0x2a),
                                                               (*(int *)(param_4 + 0x22a) + 1) * 2);
                                                  iVar6 = (*(int *)(param_4 + 0x22a) + 1) * 2 +
                                                          iVar6 + 1;
                                                  }
                                                  else {
                                                    iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),
                                                                         L"STRUCT");
                                                    if (iVar4 == 0) {
                                                      _Scan(param_4);
                                                      if ((*(int *)(param_4 + 0x42e) != 2) &&
                                                         (*(int *)(param_4 + 0x42e) != 3)) {
                                                        psVar2 = _T(L"Name expected");
                                                        return psVar2;
                                                      }
                                                      if (0x10000 < (uint)(iVar6 + 1 +
                                                                          (*(int *)(param_4 + 0x22a)
                                                                          + 1) * 2)) {
                                                        psVar2 = _T(L"Type description is too long")
                                                        ;
                                                        return psVar2;
                                                      }
                                                      *(undefined *)((int)puVar3 + iVar6) = 0x3e;
                                                      FUN_004e74f4((undefined4 *)
                                                                   (iVar6 + 1 + (int)puVar3),
                                                                   (undefined4 *)(param_4 + 0x2a),
                                                                   (*(int *)(param_4 + 0x22a) + 1) *
                                                                   2);
                                                      iVar6 = (*(int *)(param_4 + 0x22a) + 1) * 2 +
                                                              iVar6 + 1;
                                                    }
                                                    else {
                                                      iVar4 = msvc::strcmp((short *)(param_4 + 0x2a)
                                                                           ,L"HANDLE");
                                                      if (iVar4 == 0) {
                                                        *(undefined *)((int)puVar3 + iVar6) = 0x3f;
                                                        iVar6 += 1;
                                                      }
                                                      else {
                                                        iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                      0x2a),L"HWND")
                                                        ;
                                                        if (iVar4 == 0) {
                                                          *(undefined *)((int)puVar3 + iVar6) = 0x40
                                                          ;
                                                          iVar6 += 1;
                                                        }
                                                        else {
                                                          iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                        0x2a),
                                                                               L"HMODULE");
                                                          if (iVar4 == 0) {
                                                            *(undefined *)((int)puVar3 + iVar6) =
                                                                 0x41;
                                                            iVar6 += 1;
                                                          }
                                                          else {
                                                            iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                          0x2a),
                                                                                 L"HDC");
                                                            if (iVar4 == 0) {
                                                              *(undefined *)((int)puVar3 + iVar6) =
                                                                   0x42;
                                                              iVar6 += 1;
                                                            }
                                                            else {
                                                              iVar4 = msvc::strcmp((short *)(param_4
                                                                                            + 0x2a),
                                                                                   L"HGDI");
                                                              if (iVar4 == 0) {
                                                                *(undefined *)((int)puVar3 + iVar6)
                                                                     = 0x43;
                                                                iVar6 += 1;
                                                              }
                                                              else {
                                                                iVar4 = msvc::strcmp((short *)(
                                                  param_4 + 0x2a),L"HMEM");
                                                  if (iVar4 == 0) {
                                                    *(undefined *)((int)puVar3 + iVar6) = 0x44;
                                                    iVar6 += 1;
                                                  }
                                                  else {
                                                    iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),
                                                                         L"HKEY");
                                                    if (iVar4 == 0) {
                                                      *(undefined *)((int)puVar3 + iVar6) = 0x45;
                                                      iVar6 += 1;
                                                    }
                                                    else {
                                                      iVar4 = msvc::strcmp((short *)(param_4 + 0x2a)
                                                                           ,L"CALLBACK");
                                                      if (iVar4 == 0) {
                                                        *(undefined *)((int)puVar3 + iVar6) = 0x46;
                                                        iVar6 += 1;
                                                      }
                                                      else {
                                                        iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                      0x2a),
                                                                             L"WINPROCA");
                                                        if (iVar4 == 0) {
                                                          *(undefined *)((int)puVar3 + iVar6) = 0x47
                                                          ;
                                                          iVar6 += 1;
                                                        }
                                                        else {
                                                          iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                        0x2a),
                                                                               L"WINPROCW");
                                                          if (iVar4 == 0) {
                                                            *(undefined *)((int)puVar3 + iVar6) =
                                                                 0x48;
                                                            iVar6 += 1;
                                                          }
                                                          else {
                                                            iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                          0x2a),
                                                                                 L"PROCID");
                                                            if (iVar4 == 0) {
                                                              *(undefined *)((int)puVar3 + iVar6) =
                                                                   0x4a;
                                                              iVar6 += 1;
                                                            }
                                                            else {
                                                              iVar4 = msvc::strcmp((short *)(param_4
                                                                                            + 0x2a),
                                                                                   L"VOID");
                                                              if (iVar4 == 0) {
                                                                *(undefined *)((int)puVar3 + iVar6)
                                                                     = 0x49;
                                                                iVar6 += 1;
                                                              }
                                                              else {
                                                                iVar4 = msvc::strcmp((short *)(
                                                  param_4 + 0x2a),L"QUAD");
                                                  if (iVar4 == 0) {
                                                    *(undefined *)((int)puVar3 + iVar6) = 0x50;
                                                    iVar6 += 1;
                                                  }
                                                  else {
                                                    iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),
                                                                         L"ATEXT");
                                                    if (iVar4 == 0) {
                                                      *(undefined *)((int)puVar3 + iVar6) = 0x51;
                                                      iVar6 += 1;
                                                    }
                                                    else {
                                                      iVar4 = msvc::strcmp((short *)(param_4 + 0x2a)
                                                                           ,L"WTEXT");
                                                      if (iVar4 == 0) {
                                                        *(undefined *)((int)puVar3 + iVar6) = 0x52;
                                                        iVar6 += 1;
                                                      }
                                                      else {
                                                        iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                      0x2a),
                                                                             L"DOUBLE");
                                                        if (iVar4 == 0) {
                                                          *(undefined *)((int)puVar3 + iVar6) = 0x53
                                                          ;
                                                          iVar6 += 1;
                                                        }
                                                        else {
                                                          iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                        0x2a),
                                                                               L"LDOUBLE");
                                                          if (iVar4 == 0) {
                                                            *(undefined *)((int)puVar3 + iVar6) =
                                                                 0x54;
                                                            iVar6 += 1;
                                                          }
                                                          else {
                                                            iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                          0x2a),
                                                                                 L"NETSW");
                                                            if (iVar4 == 0) {
                                                              *(undefined *)((int)puVar3 + iVar6) =
                                                                   0x5a;
                                                              iVar6 += 1;
                                                            }
                                                            else {
                                                              iVar4 = msvc::strcmp((short *)(param_4
                                                                                            + 0x2a),
                                                                                   L"NETSD");
                                                              if (iVar4 == 0) {
                                                                *(undefined *)((int)puVar3 + iVar6)
                                                                     = 0x5b;
                                                                iVar6 += 1;
                                                              }
                                                              else {
                                                                iVar4 = msvc::strcmp((short *)(
                                                  param_4 + 0x2a),L"NETGW");
                                                  if (iVar4 == 0) {
                                                    *(undefined *)((int)puVar3 + iVar6) = 0x5c;
                                                    iVar6 += 1;
                                                  }
                                                  else {
                                                    iVar4 = msvc::strcmp((short *)(param_4 + 0x2a),
                                                                         L"NETGD");
                                                    if (iVar4 == 0) {
                                                      *(undefined *)((int)puVar3 + iVar6) = 0x5d;
                                                      iVar6 += 1;
                                                    }
                                                    else {
                                                      iVar4 = msvc::strcmp((short *)(param_4 + 0x2a)
                                                                           ,L"NETBW");
                                                      if (iVar4 == 0) {
                                                        *(undefined *)((int)puVar3 + iVar6) = 0x5e;
                                                        iVar6 += 1;
                                                      }
                                                      else {
                                                        iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                      0x2a),L"NETBD"
                                                                            );
                                                        if (iVar4 == 0) {
                                                          *(undefined *)((int)puVar3 + iVar6) = 0x5f
                                                          ;
                                                          iVar6 += 1;
                                                        }
                                                        else {
                                                          iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                        0x2a),
                                                                               L"NETCI");
                                                          if (iVar4 == 0) {
                                                            *(undefined *)((int)puVar3 + iVar6) =
                                                                 0x60;
                                                            iVar6 += 1;
                                                          }
                                                          else {
                                                            iVar4 = msvc::strcmp((short *)(param_4 +
                                                                                          0x2a),
                                                                                 L"NETCH");
                                                            if (iVar4 == 0) {
                                                              *(undefined *)((int)puVar3 + iVar6) =
                                                                   0x61;
                                                              iVar6 += 1;
                                                            }
                                                            else {
                                                              iVar4 = msvc::strcmp((short *)(param_4
                                                                                            + 0x2a),
                                                                                   L"NETCF");
                                                              if (iVar4 == 0) {
                                                                *(undefined *)((int)puVar3 + iVar6)
                                                                     = 0x62;
                                                                iVar6 += 1;
                                                              }
                                                              else {
                                                                iVar4 = msvc::strcmp((short *)(
                                                  param_4 + 0x2a),L"NETCU");
                                                  if (iVar4 != 0) {
                                                    psVar2 = _T(L"Invalid or unexpected keyword");
                                                    return psVar2;
                                                  }
                                                  *(undefined *)((int)puVar3 + iVar6) = 99;
                                                  iVar6 += 1;
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                  }
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                }
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        } while( true );
      }
      psVar2 = _T(L"Low memory, processing interrupted");
    }
    else {
      psVar2 = _T(L"Length of type name is limited to 30 characters");
    }
  }
  else {
    psVar2 = _T(L"Bad type name");
  }
  return psVar2;
}

