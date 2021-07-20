
short * __stdcall olly::ParseTRANSLATOR(byte *param_4)

{
  short *psVar1;
  int iVar2;
  HGLOBAL pvVar3;
  int iVar4;
  int iVar5;
  wchar_t *dest;
  uint uVar6;
  byte *pbVar7;
  
  pbVar7 = param_4;
  _Scan(param_4);
  iVar2 = *(int *)(param_4 + 0x42e);
  if ((iVar2 == 2) || (iVar2 == 3)) {
    if (*(int *)(param_4 + 0x22a) < 0x1f) {
      FUN_004ecff0(iVar2,param_4 + 0x2a,pbVar7,param_4 + 0x2a);
      uVar6 = 0;
      dest = (wchar_t *)&DAT_005ea608;
      do {
        if ((dest[0x10] == L'\0') ||
           (iVar2 = msvc::strcmp((short *)dest,(short *)(param_4 + 0x2a)), iVar2 == 0)) break;
        uVar6 += 1;
        dest = dest + 0x12;
      } while ((int)uVar6 < 8);
      if ((int)uVar6 < 8) {
        if ((int)uVar6 < (int)globals::g_Arg_NumTranslators) {
          psVar1 = _T(L"  Redefined translator \'%s\'",param_4 + 0x2a);
          _Addtolist(0,2,(int)psVar1);
          _Memfree((HGLOBAL)dest[0x10]);
          dest[0x10] = L'\0';
        }
        _StrcopyW(dest,0x20,(wchar_t *)(param_4 + 0x2a));
        _Scan(param_4);
        if ((*(int *)(param_4 + 0x42e) == 0) || (*(int *)(param_4 + 0x42e) == 1)) {
          pvVar3 = _Memalloc(0x10000,3);
          dest[0x10] = (wchar_t)pvVar3;
          if (dest[0x10] == L'\0') {
            psVar1 = _T(L"Low memory, processing interrupted");
          }
          else {
            dest[0x11] = L'\0';
            while( true ) {
              do {
                _Scan(param_4);
              } while (*(int *)(param_4 + 0x42e) == 1);
              if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) {
                psVar1 = _T(L"Expecting translation record or END");
                return psVar1;
              }
              if ((*(int *)(param_4 + 0x42e) == 2) &&
                 (iVar2 = FUN_004e7a58(param_4 + 0x2a,L"END"), iVar2 == 0)) {
                if (dest[0x11] == L'\0') {
                  psVar1 = _T(L"Empty translator");
                  return psVar1;
                }
                _Heapsort();
                for (iVar2 = 0; iVar2 < dest[0x11] + L'\xffffffff'; iVar2 += 1) {
                  iVar5 = *(int *)(dest[0x10] + iVar2 * 8) + DAT_005e9e20;
                  iVar4 = FUN_00410b90();
                  if (iVar4 == 0) {
                    psVar1 = _T(L"  Repeating input name \'%s\'",iVar5 + 4);
                    _Addtolist(0,2,(int)psVar1);
                  }
                }
                if (uVar6 == globals::g_Arg_NumTranslators) {
                  globals::g_Arg_NumTranslators += 1;
                }
                return (short *)0x0;
              }
              if (L'῿' < dest[0x11]) {
                psVar1 = _T(L"Too many translation records");
                return psVar1;
              }
              FUN_004ecff0();
              iVar2 = ArgCreateEntry(0,(undefined4 *)(param_4 + 0x2a),*(int *)(param_4 + 0x22a));
              *(int *)(dest[0x10] + dest[0x11] * 8) = iVar2;
              _Scan(param_4);
              if ((*(int *)(param_4 + 0x42e) != 6) || (*(int *)(param_4 + 0x18) != 0x3d)) {
                psVar1 = _T(L"Missing equal sign between names");
                return psVar1;
              }
              _Scan(param_4);
              if ((*(int *)(param_4 + 0x42e) != 2) && (*(int *)(param_4 + 0x42e) != 3)) {
                psVar1 = _T(L"Expecting output name");
                return psVar1;
              }
              iVar2 = ArgCreateEntry(0,(undefined4 *)(param_4 + 0x2a),*(int *)(param_4 + 0x22a));
              *(int *)(dest[0x10] + L'\x04' + dest[0x11] * 8) = iVar2;
              _Scan(param_4);
              if ((*(int *)(param_4 + 0x42e) != 0) && (*(int *)(param_4 + 0x42e) != 1)) break;
              dest[0x11] = dest[0x11] + L'\x01';
            }
            psVar1 = _T(L"Extra characters on line");
          }
        }
        else {
          psVar1 = _T(L"Extra characters on line");
        }
      }
      else {
        psVar1 = _T(L"Too many translators");
      }
    }
    else {
      psVar1 = _T(L"Length of translator name is limited to 30 characters");
    }
  }
  else {
    psVar1 = _T(L"Bad name of translator");
  }
  return psVar1;
}

