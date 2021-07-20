
short * __stdcall olly::ParseCONST(byte *param_4)

{
  int *piVar1;
  undefined4 uVar2;
  short *psVar3;
  int iVar4;
  
  _Scan(param_4);
  if (*(int *)(param_4 + 0x42e) == 4) {
    uVar2 = *(undefined4 *)(param_4 + 0x18);
    _Scan(param_4);
    if ((*(int *)(param_4 + 0x42e) == 2) || (*(int *)(param_4 + 0x42e) == 3)) {
      if ((*(int *)(param_4 + 0x22a) < 1) ||
         (*(short *)(param_4 + *(int *)(param_4 + 0x22a) * 2 + 0x28) != 0x7c)) {
        if (((int)globals::g_Arg_TableConstants_Capacity <= (int)globals::g_Arg_TableConstants_Count
            ) && (globals::g_Arg_TableConstants =
                       _Memdouble(globals::g_Arg_TableConstants,
                                  (int *)&globals::g_Arg_TableConstants_Capacity,4,
                                  (int *)&DAT_005ebc70,1),
                 (int)globals::g_Arg_TableConstants_Capacity <=
                 (int)globals::g_Arg_TableConstants_Count)) {
          psVar3 = _T(L"Low memory, processing interrupted");
          return psVar3;
        }
        iVar4 = ArgCreateEntry(uVar2,(undefined4 *)(param_4 + 0x2a),*(int *)(param_4 + 0x22a));
        piVar1 = globals::g_Arg_TableConstants + globals::g_Arg_TableConstants_Count;
        globals::g_Arg_TableConstants_Count = globals::g_Arg_TableConstants_Count + 1;
        *piVar1 = iVar4;
        globals::g_Arg_NumConstants += 1;
        psVar3 = (short *)0x0;
        globals::g_Arg_TableConstants_IsUsed = 1;
      }
      else {
        psVar3 = _T(L"Constant ends with vertical line");
      }
    }
    else {
      psVar3 = _T(L"Bad constant name");
    }
  }
  else {
    psVar3 = _T(L"Integer constant expected");
  }
  return psVar3;
}

