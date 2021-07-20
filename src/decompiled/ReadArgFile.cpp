
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __stdcall olly::ReadArgFile(wchar_t *param_4)

{
  bool bVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  short *psVar5;
  ushort *puVar6;
  undefined2 *puVar7;
  wchar16 *pwVar8;
  int *piVar9;
  int iVar10;
  undefined2 *puVar11;
  int iVar12;
  undefined4 unaff_EDI;
  undefined4 local_848;
  ushort *local_844;
  uint local_840;
  undefined4 local_83c;
  undefined4 local_838;
  undefined4 local_834;
  short local_81e [258];
  undefined local_61a [512];
  int local_41a;
  wchar_t local_414 [130];
  undefined2 local_20c [256];
  ushort *local_c;
  uint local_8;
  
  if (((param_4 == (wchar_t *)0x0) || (*(short *)param_4 == 0)) || (DAT_005e9e20 == 0)) {
    uVar2 = 0xffffffff;
  }
  else {
    globals::g_Arg_NumDataBlocks = 0;
    globals::g_Arg_NumFunctions = 0;
    globals::g_Arg_NumTypes = 0;
    globals::g_Arg_NumStructures = 0;
    globals::g_Arg_NumTranslators = 0;
    globals::g_Arg_NumGroups = 0;
    globals::g_Arg_NumConstants = 0;
    uVar3 = _StrcopyW(local_414,MAX_PATH,(wchar_t *)&_ollydir);
    uVar4 = _StrcopyW((wchar_t *)((int)local_414 + uVar3 * 2),0x104 - uVar3,(wchar_t *)L"\\");
    iVar10 = uVar3 + uVar4;
    uVar3 = _StrcopyW((wchar_t *)((int)local_414 + iVar10 * 2),0x104 - iVar10,param_4);
    _StrcopyW((wchar_t *)((int)local_414 + (iVar10 + uVar3) * 2),0x104 - (iVar10 + uVar3),
              (wchar_t *)L".arg");
    local_c = (ushort *)_Readfile((short *)local_414,0,0,&local_8);
    if (local_c == (ushort *)0x0) {
      if (local_8 != 0) {
        psVar5 = _T(L"Out of memory - unable to process descriptions in \'%s.arg\'",param_4);
        _Addtolist(0,1,(int)psVar5);
      }
      uVar2 = 0xffffffff;
    }
    else {
      if (((local_8 < 3) || (*(char *)local_c != -2)) || (*(char *)((int)local_c + 1) != -1)) {
        if (((local_8 < 3) || (*(char *)local_c != -1)) || (*(char *)((int)local_c + 1) != -2)) {
          local_844 = (ushort *)_Memalloc(local_8 * 2 + 2,1);
          if (local_844 == (ushort *)0x0) {
            _Memfree(local_c);
            psVar5 = _T(L"Out of memory - unable to process descriptions in \'%s.arg\'",param_4);
            _Addtolist(0,1,(int)psVar5);
            return 0xffffffff;
          }
          local_8 = _Asciitounicode((byte *)local_c,local_8,local_844,local_8 + 1);
          _Memfree(local_c);
          local_840 = local_8;
          local_c = local_844;
        }
        else {
          local_844 = local_c + 1;
          local_840 = local_8 - 2 >> 1;
        }
        _DAT_005ebc70 = 0;
        psVar5 = _T(L"Loading function descriptions from \'%s.arg\'",param_4);
        _Addtolist(0,0,(int)psVar5);
        local_848 = 0x200;
        local_838 = 0;
        local_83c = 0;
        local_834 = 1;
        psVar5 = (short *)0x0;
        do {
          while( true ) {
            if (psVar5 != (short *)0x0) goto LAB_0048311f;
            bVar1 = false;
            _Scan((byte *)&local_848);
            if (local_41a != 2) break;
            FUN_004ecff0();
            iVar10 = msvc::strcmp(local_81e,L"NORETURN");
            if (iVar10 == 0) {
              bVar1 = true;
              _Scan((byte *)&local_848);
              if (local_41a != 2) {
                psVar5 = _T(L"Keyword expected");
                goto LAB_0048311f;
              }
              FUN_004ecff0();
            }
            iVar10 = msvc::strcmp(local_81e,L"INFO");
            if (iVar10 == 0) {
              if (bVar1) {
                psVar5 = _T(L"Invalid type modifier(s)");
                goto LAB_0048311f;
              }
              _Scan((byte *)&local_848);
              if (local_41a == 3) {
                _Addtolist(0,2,(int)L"  %s");
              }
              else {
                psVar5 = _T(L"Text expected");
              }
            }
            else {
              iVar10 = msvc::strcmp(local_81e,L"CONST");
              if (iVar10 == 0) {
                if (bVar1) {
                  psVar5 = _T(L"Invalid type modifier(s)");
                  goto LAB_0048311f;
                }
                psVar5 = (short *)ParseCONST();
              }
              else {
                iVar10 = msvc::strcmp(local_81e,L"GROUP");
                if (iVar10 == 0) {
                  if (bVar1) {
                    psVar5 = _T(L"Invalid type modifier(s)");
                    goto LAB_0048311f;
                  }
                  psVar5 = (short *)ParseGROUP();
                }
                else {
                  iVar10 = msvc::strcmp(local_81e,L"TRANSLATOR");
                  if (iVar10 == 0) {
                    if (bVar1) {
                      psVar5 = _T(L"Invalid type modifier(s)");
                      goto LAB_0048311f;
                    }
                    psVar5 = (short *)ParseTRANSLATOR();
                  }
                  else {
                    iVar10 = msvc::strcmp(local_81e,L"TYPE");
                    if (iVar10 == 0) {
                      if (bVar1) {
                        psVar5 = _T(L"Invalid type modifier(s)");
                        goto LAB_0048311f;
                      }
                      psVar5 = (short *)ParseTYPE();
                    }
                    else {
                      iVar10 = msvc::strcmp(local_81e,L"STRUCT");
                      if (iVar10 == 0) {
                        if (bVar1) {
                          psVar5 = _T(L"Invalid type modifier(s)");
                          goto LAB_0048311f;
                        }
                        psVar5 = (short *)ParseSTRUCT();
                      }
                      else {
                        iVar10 = msvc::strcmp(local_81e,L"FUNCTION");
                        if (iVar10 == 0) {
                          psVar5 = (short *)ParseFUNCTION();
                        }
                        else {
                          iVar10 = msvc::strcmp(local_81e,L"PASCAL");
                          if (iVar10 == 0) {
                            psVar5 = (short *)ParseFUNCTION();
                          }
                          else {
                            iVar10 = msvc::strcmp(local_81e,L"CFUNC");
                            if (iVar10 == 0) {
                              psVar5 = (short *)ParseFUNCTION();
                            }
                            else {
                              iVar10 = msvc::strcmp(local_81e,L"STDFUNC");
                              if (iVar10 == 0) {
                                psVar5 = (short *)ParseFUNCTION();
                              }
                              else {
                                iVar10 = msvc::strcmp(local_81e,L"STDC");
                                if (iVar10 == 0) {
                                  psVar5 = (short *)ParseFUNCTION();
                                }
                                else {
                                  iVar10 = msvc::strcmp(local_81e,L"RAWDATA");
                                  if (iVar10 == 0) {
                                    if (bVar1) {
                                      psVar5 = _T(L"Invalid type modifier(s)");
                                      goto LAB_0048311f;
                                    }
                                    psVar5 = (short *)ParseRAWDATA();
                                  }
                                  else {
                                    psVar5 = _T(L"Unexpected keyword");
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
            if (_DAT_005ebc70 != 0) {
              psVar5 = _T(L"Low memory, processing interrupted");
              goto LAB_0048311f;
            }
            if (((psVar5 == (short *)0x0) && (_Scan((byte *)&local_848), local_41a != 0)) &&
               (local_41a != 1)) {
              psVar5 = _T(L"Extra characters on line");
            }
          }
          if (local_41a == 0) goto LAB_0048311f;
        } while (local_41a == 1);
        psVar5 = _T(L"Keyword expected");
LAB_0048311f:
        _Memfree(local_c);
        if (psVar5 == (short *)0x0) {
          _Getconstantbyname(L"$",(undefined4 *)0x0);
          for (iVar10 = 0; iVar10 < DAT_005e9e70 + -1; iVar10 += 1) {
            iVar12 = msvc::strcmp((short *)(*(int *)(DAT_005e9e68 + iVar10 * 4) + DAT_005e9e20 + 4),
                                  (short *)(*(int *)(DAT_005e9e68 + 4 + iVar10 * 4) + DAT_005e9e20 +
                                           4));
            if (iVar12 == 0) {
              psVar5 = _T(L"  Redefined constant \'%s\'",
                          *(int *)(DAT_005e9e68 + iVar10 * 4) + DAT_005e9e20 + 4);
              _Addtolist(0,2,(int)psVar5);
            }
          }
          puVar11 = (undefined2 *)0x0;
          if (0 < (int)globals::g_Arg_NumConstants) {
            if (globals::g_Arg_NumConstants == 1) {
              puVar6 = (ushort *)_T(L"1 constant");
              puVar11 = local_20c;
              FUN_004eafd0(puVar11,puVar6,unaff_EDI);
            }
            else {
              uVar3 = globals::g_Arg_NumConstants;
              puVar6 = (ushort *)_T(L"%i constants");
              puVar11 = local_20c;
              FUN_004eafd0(puVar11,puVar6,uVar3);
            }
          }
          if (0 < (int)globals::g_Arg_NumGroups) {
            if (0 < (int)puVar11) {
              puVar7 = local_20c + (int)puVar11;
              FUN_004eafd0(puVar7,(ushort *)L", ",unaff_EDI);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar7);
            }
            if (globals::g_Arg_NumGroups == 1) {
              puVar6 = (ushort *)_T(L"1 group");
              puVar7 = local_20c + (int)puVar11;
              FUN_004eafd0(puVar7,puVar6,unaff_EDI);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar7);
            }
            else {
              uVar3 = globals::g_Arg_NumGroups;
              puVar6 = (ushort *)_T(L"%i groups");
              FUN_004eafd0(local_20c + (int)puVar11,puVar6,uVar3);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar6);
            }
          }
          if (0 < (int)globals::g_Arg_NumTranslators) {
            if (0 < (int)puVar11) {
              pwVar8 = L", ";
              FUN_004eafd0(local_20c + (int)puVar11,(ushort *)L", ",unaff_EDI);
              puVar11 = (undefined2 *)((int)puVar11 + (int)pwVar8);
            }
            if (globals::g_Arg_NumTranslators == 1) {
              puVar6 = (ushort *)_T(L"1 translator");
              FUN_004eafd0(local_20c + (int)puVar11,puVar6,unaff_EDI);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar6);
            }
            else {
              uVar3 = globals::g_Arg_NumTranslators;
              puVar6 = (ushort *)_T(L"%i translators");
              puVar7 = local_20c;
              FUN_004eafd0(puVar7 + (int)puVar11,puVar6,uVar3);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar7);
            }
          }
          if (0 < (int)globals::g_Arg_NumStructures) {
            if (0 < (int)puVar11) {
              puVar7 = local_20c;
              FUN_004eafd0(puVar7 + (int)puVar11,(ushort *)L", ",unaff_EDI);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar7);
            }
            if (globals::g_Arg_NumStructures == 1) {
              puVar6 = (ushort *)_T(L"1 structure");
              puVar7 = local_20c;
              FUN_004eafd0(puVar7 + (int)puVar11,puVar6,unaff_EDI);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar7);
            }
            else {
              uVar3 = globals::g_Arg_NumStructures;
              puVar6 = (ushort *)_T(L"%i structures");
              puVar7 = local_20c + (int)puVar11;
              FUN_004eafd0(puVar7,puVar6,uVar3);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar7);
            }
          }
          if (0 < (int)globals::g_Arg_NumTypes) {
            if (0 < (int)puVar11) {
              puVar7 = local_20c + (int)puVar11;
              FUN_004eafd0(puVar7,(ushort *)L", ",unaff_EDI);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar7);
            }
            if (globals::g_Arg_NumTypes == 1) {
              puVar6 = (ushort *)_T(L"1 type");
              puVar7 = local_20c + (int)puVar11;
              FUN_004eafd0(puVar7,puVar6,unaff_EDI);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar7);
            }
            else {
              uVar3 = globals::g_Arg_NumTypes;
              puVar6 = (ushort *)_T(L"%i types");
              FUN_004eafd0(local_20c + (int)puVar11,puVar6,uVar3);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar6);
            }
          }
          if (0 < (int)globals::g_Arg_NumFunctions) {
            if (0 < (int)puVar11) {
              pwVar8 = L", ";
              FUN_004eafd0(local_20c + (int)puVar11,(ushort *)L", ",unaff_EDI);
              puVar11 = (undefined2 *)((int)puVar11 + (int)pwVar8);
            }
            if (globals::g_Arg_NumFunctions == 1) {
              puVar6 = (ushort *)_T(L"1 function");
              FUN_004eafd0(local_20c + (int)puVar11,puVar6,unaff_EDI);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar6);
            }
            else {
              uVar3 = globals::g_Arg_NumFunctions;
              puVar6 = (ushort *)_T(L"%i functions");
              puVar7 = local_20c;
              FUN_004eafd0(puVar7 + (int)puVar11,puVar6,uVar3);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar7);
            }
          }
          if (0 < (int)globals::g_Arg_NumDataBlocks) {
            if (0 < (int)puVar11) {
              puVar7 = local_20c;
              FUN_004eafd0(puVar7 + (int)puVar11,(ushort *)L", ",unaff_EDI);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar7);
            }
            if (globals::g_Arg_NumDataBlocks == 1) {
              puVar6 = (ushort *)_T(L"1 data block");
              puVar7 = local_20c;
              FUN_004eafd0(puVar7 + (int)puVar11,puVar6,unaff_EDI);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar7);
            }
            else {
              uVar3 = globals::g_Arg_NumDataBlocks;
              puVar6 = (ushort *)_T(L"%i data blocks");
              puVar7 = local_20c + (int)puVar11;
              FUN_004eafd0(puVar7,puVar6,uVar3);
              puVar11 = (undefined2 *)((int)puVar11 + (int)puVar7);
            }
          }
          if (0 < (int)puVar11) {
            _Addtolist(0,2,(int)L"  %s");
          }
          iVar10 = DAT_005e9e28 + DAT_005e9e34 +
                   (DAT_005e9e40 + DAT_005e9e50 + DAT_005e9e60 + DAT_005e9e70 + DAT_005e9e80) * 4;
          piVar9 = &DAT_005e9ec8;
          iVar12 = 0;
          do {
            if (*piVar9 != 0) {
              iVar10 = piVar9[2] * 4 + iVar10;
            }
            iVar12 += 1;
            piVar9 = piVar9 + 0x14;
          } while (iVar12 < 0x18);
          if (0 < iVar10) {
            psVar5 = _T(L"  Total size of known data is %i bytes",iVar10);
            _Addtolist(0,2,(int)psVar5);
          }
          uVar2 = 0;
        }
        else {
          if (local_41a == 8) {
            psVar5 = _T(L"  Line %i. %s (%s)",local_834,psVar5,local_61a);
            _Addtolist(0,1,(int)psVar5);
          }
          else {
            psVar5 = _T(L"  Line %i. %s",local_834,psVar5);
            _Addtolist(0,1,(int)psVar5);
          }
          uVar2 = 0xffffffff;
        }
      }
      else {
        _Memfree(local_c);
        psVar5 = _T(L"File \'%s.arg\' has unsupported UNICODE big endian format",param_4);
        _Addtolist(0,1,(int)psVar5);
        uVar2 = 0xffffffff;
      }
    }
  }
  return uVar2;
}

