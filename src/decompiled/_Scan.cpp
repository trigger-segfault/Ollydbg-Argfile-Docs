
/* WARNING: Could not reconcile some variable overlaps */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl _Scan(byte *param_1)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  short *psVar9;
  int iVar10;
  undefined4 uVar11;
  int iVar12;
  short sVar13;
  short sVar14;
  uint uVar15;
  float10 in_ST0;
  float10 local_3c;
  undefined local_30 [4];
  undefined auStack44 [8];
  uint local_24;
  uint local_20;
  
                    /* 0x856a8  278  _Scan
                       0x856a8  704  Scan */
  if (param_1 == (byte *)0x0) {
    return;
  }
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 0x42e) = 0;
    return;
  }
  *(undefined4 *)(param_1 + 0x10) = *(undefined4 *)(param_1 + 0xc);
  iVar3 = *(int *)(param_1 + 4);
switchD_00485708_caseD_9:
  do {
    if (*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 0xc)) {
      *(undefined4 *)(param_1 + 0x42e) = 0;
      return;
    }
    iVar12 = *(int *)(param_1 + 0xc);
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    uVar1 = *(ushort *)(iVar3 + iVar12 * 2);
    local_20 = (uint)uVar1;
    if (false) goto switchD_00485708_caseD_1;
    switch(uVar1) {
    case 0:
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;
      *(undefined4 *)(param_1 + 0x42e) = 0;
      return;
    default:
switchD_00485708_caseD_1:
      *(uint *)(param_1 + 0x18) = local_20;
      *(undefined4 *)(param_1 + 0x42e) = 7;
      return;
    case 9:
    case 0xc:
    case 0x20:
      break;
    case 10:
    case 0xd:
      if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
         (((local_20 == '\n' && (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '\r')) ||
          ((local_20 == '\r' && (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '\n')))))) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      }
      *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
      if ((*param_1 & 0x10) == 0) {
        *(undefined4 *)(param_1 + 0x42e) = 1;
        return;
      }
      break;
    case 0x21:
      if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
         (*(short *)(iVar3 + *(uint *)(param_1 + 0xc) * 2) == '=')) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        *(undefined4 *)(param_1 + 0x18) = 0x3d21;
      }
      else {
        *(uint *)(param_1 + 0x18) = local_20;
      }
      *(undefined4 *)(param_1 + 0x42e) = 6;
      return;
    case 0x22:
      if ((param_1[1] & 8) != 0) {
        *(uint *)(param_1 + 0x18) = local_20;
        *(undefined4 *)(param_1 + 0x42e) = 6;
        return;
      }
      *(undefined4 *)(param_1 + 0x22a) = 0;
      goto LAB_0048587b;
    case 0x23:
    case 0x24:
    case 0x26:
    case 0x40:
    case 0x41:
    case 0x42:
    case 0x43:
    case 0x44:
    case 0x45:
    case 0x46:
    case 0x47:
    case 0x48:
    case 0x49:
    case 0x4a:
    case 0x4b:
    case 0x4c:
    case 0x4d:
    case 0x4e:
    case 0x4f:
    case 0x50:
    case 0x51:
    case 0x52:
    case 0x53:
    case 0x54:
    case 0x55:
    case 0x56:
    case 0x57:
    case 0x58:
    case 0x59:
    case 0x5a:
    case 0x5f:
    case 0x61:
    case 0x62:
    case 99:
    case 100:
    case 0x65:
    case 0x66:
    case 0x67:
    case 0x68:
    case 0x69:
    case 0x6a:
    case 0x6b:
    case 0x6c:
    case 0x6d:
    case 0x6e:
    case 0x6f:
    case 0x70:
    case 0x71:
    case 0x72:
    case 0x73:
    case 0x74:
    case 0x75:
    case 0x76:
    case 0x77:
    case 0x78:
    case 0x79:
    case 0x7a:
      if ((local_20 == '_') && ((*param_1 & 0x80) != 0)) {
        *(undefined4 *)(param_1 + 0x18) = 0x5f;
        *(undefined4 *)(param_1 + 0x42e) = 6;
        return;
      }
      if ((local_20 == '&') && ((*param_1 & '@') == 0)) {
        if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
           (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '&')) {
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          *(undefined4 *)(param_1 + 0x18) = 0x2626;
        }
        else {
          *(undefined4 *)(param_1 + 0x18) = '&';
        }
        *(undefined4 *)(param_1 + 0x42e) = 6;
        return;
      }
      if ((local_20 == '#') && ((*param_1 & '@') == 0)) {
        *(undefined4 *)(param_1 + 0x18) = 0x23;
        *(undefined4 *)(param_1 + 0x42e) = 6;
        return;
      }
      *(ushort *)(param_1 + 0x2a) = uVar1;
      *(undefined4 *)(param_1 + 0x22a) = 1;
      while ((((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8) &&
               (*(int *)(param_1 + 0x22a) < 0xff)) &&
              ((sVar14 = *(short *)(iVar3 + *(uint *)(param_1 + 0xc) * 2), sVar14 != 0x5f ||
               ((*param_1 & 0x80) == 0)))) &&
             ((((((iVar12 = FUN_004ecd50(), iVar12 != 0 || (iVar12 = FUN_004ecd7c(), iVar12 != 0))
                 || (sVar14 == 0x5f)) || ((sVar14 == 0x40 || (sVar14 == 0x23)))) || (sVar14 == 0x24)
               ) || (((*param_1 & '@') != 0 &&
                     (((sVar14 == 0x26 || (sVar14 == 0x2e)) ||
                      ((sVar14 == 0x21 ||
                       (((sVar14 == 0x3f || (sVar14 == 0x25)) || (sVar14 == 0x7e))))))))))))) {
        iVar12 = *(int *)(param_1 + 0x22a);
        *(int *)(param_1 + 0x22a) = *(int *)(param_1 + 0x22a) + 1;
        *(short *)(param_1 + iVar12 * 2 + 0x2a) = sVar14;
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      }
      *(undefined2 *)(param_1 + *(int *)(param_1 + 0x22a) * 2 + 0x2a) = 0;
      if ((*param_1 & 1) != 0) {
        FUN_004ecff0();
      }
      *(undefined4 *)(param_1 + 0x42e) = 2;
      return;
    case 0x25:
    case 0x28:
    case 0x29:
    case 0x2c:
    case 0x3b:
    case 0x3f:
    case 0x5b:
    case 0x5c:
    case 0x5d:
    case 0x5e:
    case 0x60:
    case 0x7b:
    case 0x7d:
    case 0x7e:
      *(uint *)(param_1 + 0x18) = local_20;
      *(undefined4 *)(param_1 + 0x42e) = 6;
      return;
    case 0x27:
      if (*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 0xc)) {
        psVar9 = _T(L"Unterminated character constant");
        FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
        *(undefined4 *)(param_1 + 0x42e) = 8;
        return;
      }
      iVar12 = *(int *)(param_1 + 0xc);
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      uVar1 = *(ushort *)(iVar3 + iVar12 * 2);
      uVar15 = (uint)uVar1;
      if ((uVar1 & 0xff00) != 0) {
        psVar9 = _T(L"UNICODE character constants are not allowed");
        FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
        *(undefined4 *)(param_1 + 0x42e) = 8;
        return;
      }
      if ((uVar15 == '\\') && ((*param_1 & 0x20) == 0)) {
        if (*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 0xc)) {
          psVar9 = _T(L"Unterminated character constant");
          FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
          *(undefined4 *)(param_1 + 0x42e) = 8;
          return;
        }
        iVar12 = *(int *)(param_1 + 0xc);
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        uVar15 = (uint)*(ushort *)(iVar3 + iVar12 * 2);
        if (((uVar15 == 0) || (uVar15 == '\n')) || (uVar15 == '\r')) {
          psVar9 = _T(L"Unterminated character constant");
          FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
          *(undefined4 *)(param_1 + 0x42e) = 8;
          return;
        }
        if (uVar15 == 'n') {
          uVar15 = 10;
        }
        else {
          if (uVar15 == 'r') {
            uVar15 = '\r';
          }
          else {
            if (uVar15 == 't') {
              uVar15 = '\t';
            }
            else {
              if (uVar15 == 0x30) {
                uVar15 = 0;
              }
              else {
                if ((uVar15 == 'x') || (uVar15 == 'X')) {
                  if (*(int *)(param_1 + 0xc) + 1U < *(uint *)(param_1 + 8)) {
                    uVar15 = (uint)*(ushort *)(iVar3 + *(int *)(param_1 + 0xc) * 2);
                    iVar12 = FUN_004ece10();
                    if ((iVar12 != 0) &&
                       (uVar2 = *(undefined2 *)(iVar3 + 2 + *(int *)(param_1 + 0xc) * 2),
                       iVar12 = FUN_004ece10(*(int *)(param_1 + 0xc),uVar2,uVar15,uVar2),
                       iVar12 != 0)) {
                      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
                      iVar12 = FUN_004ed0c0();
                      if (iVar12 < ':') {
                        iVar12 += -0x39;
                      }
                      else {
                        iVar12 += -0x37;
                      }
                      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
                      iVar10 = FUN_004ed0c0();
                      if (iVar10 < ':') {
                        iVar10 += -0x39;
                      }
                      else {
                        iVar10 += -0x37;
                      }
                      uVar15 = iVar12 * 0x10 + iVar10;
                      goto LAB_00485cb9;
                    }
                  }
                  psVar9 = _T(L"Hex escape must have two digits");
                  FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
                  *(undefined4 *)(param_1 + 0x42e) = 8;
                  return;
                }
              }
            }
          }
        }
      }
LAB_00485cb9:
      if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
         (*(short *)(iVar3 + *(uint *)(param_1 + 0xc) * 2) == '\'')) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        *(uint *)(param_1 + 0x18) = uVar15;
        *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
        *(undefined4 *)(param_1 + 0x42e) = 4;
        return;
      }
      psVar9 = _T(L"Unterminated character constant");
      FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
      *(undefined4 *)(param_1 + 0x42e) = 8;
      return;
    case 0x2a:
      if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
         (*(short *)(iVar3 + *(uint *)(param_1 + 0xc) * 2) == '/')) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        psVar9 = _T(L"End of comment outside the comment");
        FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
        *(undefined4 *)(param_1 + 0x42e) = 8;
        return;
      }
      *(uint *)(param_1 + 0x18) = local_20;
      *(undefined4 *)(param_1 + 0x42e) = 6;
      return;
    case 0x2b:
      if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
         (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '+')) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        *(undefined4 *)(param_1 + 0x18) = 0x2b2b;
      }
      else {
        *(undefined4 *)(param_1 + 0x18) = '+';
      }
      *(undefined4 *)(param_1 + 0x42e) = 6;
      return;
    case 0x2d:
      if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
         (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '-')) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        *(undefined4 *)(param_1 + 0x18) = 0x2d2d;
      }
      else {
        if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
           (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '>')) {
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          *(undefined4 *)(param_1 + 0x18) = 0x3e2d;
        }
        else {
          *(undefined4 *)(param_1 + 0x18) = '-';
        }
      }
      *(undefined4 *)(param_1 + 0x42e) = 6;
      return;
    case 0x2e:
    case 0x30:
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
      if (local_20 == '.') {
        if (((*(int *)(param_1 + 0xc) + 1U < *(uint *)(param_1 + 8)) &&
            (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '.')) &&
           (*(short *)(iVar3 + 2 + *(int *)(param_1 + 0xc) * 2) == '.')) {
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 2;
          *(undefined4 *)(param_1 + 0x18) = 0x2e2e2e;
          *(undefined4 *)(param_1 + 0x42e) = 6;
          return;
        }
        if (((*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 0xc)) || ((param_1[1] & 2) != 0)) ||
           (iVar12 = FUN_004ecd7c(), iVar12 == 0)) {
          *(undefined4 *)(param_1 + 0x18) = '.';
          *(undefined4 *)(param_1 + 0x42e) = 6;
          return;
        }
        local_20 = 0;
        _local_30 = (float10)((unkuint10)auStack44._0_6_ << 0x20);
        _local_30 = (float10)((unkuint10)_local_30 & 0xffffffff);
        bVar8 = false;
        bVar7 = false;
        bVar6 = true;
        bVar4 = false;
        bVar5 = true;
      }
      else {
        if (local_20 == 0x30) {
          if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
             ((*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == 'x' ||
              (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == 'X')))) {
            bVar6 = false;
            bVar7 = false;
            bVar4 = true;
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          }
          else {
            bVar6 = true;
            bVar7 = true;
            bVar4 = false;
          }
          bVar8 = true;
          local_20 = 0;
          _local_30 = (float10)((unkuint10)auStack44._0_6_ << 0x20);
          _local_30 = (float10)((unkuint10)_local_30 & 0xffffffff);
          bVar5 = false;
        }
        else {
          local_20 -= 0x30;
          _local_30 = (float10)local_20;
          bVar6 = true;
          bVar8 = true;
          bVar7 = true;
          bVar5 = false;
          bVar4 = false;
        }
      }
      local_24 = 0xffffffff;
      if (bVar5) goto LAB_0048639a;
      goto LAB_0048633d;
    case 0x2f:
      if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
         (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '/')) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        while ((((uVar15 = *(uint *)(param_1 + 0xc), uVar15 < *(uint *)(param_1 + 8) &&
                 (*(short *)(iVar3 + uVar15 * 2) != 0)) && (*(short *)(iVar3 + uVar15 * 2) != 10))
               && (*(short *)(iVar3 + uVar15 * 2) != 0xd))) {
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        }
      }
      else {
        if ((*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 0xc)) ||
           (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) != '*')) {
          *(uint *)(param_1 + 0x18) = local_20;
          *(undefined4 *)(param_1 + 0x42e) = 6;
          return;
        }
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        while (((iVar12 = *(int *)(param_1 + 0xc), *(uint *)(param_1 + 8) <= iVar12 + 1U ||
                (*(short *)(iVar3 + iVar12 * 2) != 0x2a)) ||
               (*(short *)(iVar3 + 2 + iVar12 * 2) != 0x2f))) {
          uVar15 = *(uint *)(param_1 + 0xc);
          if ((*(uint *)(param_1 + 8) <= uVar15) || (*(short *)(iVar3 + uVar15 * 2) == 0))
          goto switchD_00485708_caseD_9;
          if (*(short *)(iVar3 + uVar15 * 2) == '\n') {
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
            if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
               (*(short *)(iVar3 + *(uint *)(param_1 + 0xc) * 2) == '\r')) {
              *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
            }
            *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
          }
          else {
            if (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '\r') {
              *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
              if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
                 (*(short *)(iVar3 + *(uint *)(param_1 + 0xc) * 2) == '\n')) {
                *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
              }
              *(int *)(param_1 + 0x14) = *(int *)(param_1 + 0x14) + 1;
            }
            else {
              *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
            }
          }
        }
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 2;
      }
      break;
    case 0x3a:
      if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
         (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '=')) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        *(undefined4 *)(param_1 + 0x18) = 0x3d3a;
      }
      else {
        if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
           (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == ':')) {
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          *(undefined4 *)(param_1 + 0x18) = 0x3a3a;
        }
        else {
          *(uint *)(param_1 + 0x18) = local_20;
        }
      }
      *(undefined4 *)(param_1 + 0x42e) = 6;
      return;
    case 0x3c:
      if ((param_1[1] & 8) == 0) {
        if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
           (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '=')) {
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          *(undefined4 *)(param_1 + 0x18) = 0x3d3c;
        }
        else {
          if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
             (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '<')) {
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
            *(undefined4 *)(param_1 + 0x18) = 0x3c3c;
          }
          else {
            *(undefined4 *)(param_1 + 0x18) = '<';
          }
        }
        *(undefined4 *)(param_1 + 0x42e) = 6;
        return;
      }
      *(undefined4 *)(param_1 + 0x22a) = 0;
      goto LAB_00485ecc;
    case 0x3d:
      if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
         (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '=')) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        *(undefined4 *)(param_1 + 0x18) = 0x3d3d;
      }
      else {
        *(undefined4 *)(param_1 + 0x18) = '=';
      }
      *(undefined4 *)(param_1 + 0x42e) = 6;
      return;
    case 0x3e:
      if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
         (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '=')) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        *(undefined4 *)(param_1 + 0x18) = 0x3d3e;
      }
      else {
        if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
           (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '>')) {
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          *(undefined4 *)(param_1 + 0x18) = 0x3e3e;
        }
        else {
          *(undefined4 *)(param_1 + 0x18) = '>';
        }
      }
      *(undefined4 *)(param_1 + 0x42e) = 6;
      return;
    case 0x7c:
      if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
         (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '|')) {
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        *(undefined4 *)(param_1 + 0x18) = 0x7c7c;
      }
      else {
        *(undefined4 *)(param_1 + 0x18) = '|';
      }
      *(undefined4 *)(param_1 + 0x42e) = 6;
      return;
    }
  } while( true );
LAB_00485ecc:
  if (*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 0xc)) {
    psVar9 = _T(L"Unterminated string");
    FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
LAB_00485f89:
    *(undefined4 *)(param_1 + 0x42e) = 8;
    return;
  }
  iVar12 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  sVar14 = *(short *)(iVar3 + iVar12 * 2);
  if (sVar14 == 0x3e) {
    *(undefined2 *)(param_1 + *(int *)(param_1 + 0x22a) * 2 + 0x2a) = 0;
    *(undefined4 *)(param_1 + 0x42e) = 3;
    return;
  }
  if (0xfe < *(int *)(param_1 + 0x22a)) {
    psVar9 = _T(L"String is too long");
    FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
    goto LAB_00485f89;
  }
  if (((sVar14 == 0) || (sVar14 == 10)) || (sVar14 == 0xd)) {
    psVar9 = _T(L"Unterminated string");
    FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
    goto LAB_00485f89;
  }
  iVar12 = *(int *)(param_1 + 0x22a);
  *(int *)(param_1 + 0x22a) = *(int *)(param_1 + 0x22a) + 1;
  *(short *)(param_1 + iVar12 * 2 + 0x2a) = sVar14;
  goto LAB_00485ecc;
LAB_0048633d:
  if (*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 0xc)) {
LAB_00486349:
    if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
       (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '.')) {
      if (local_24 != 0xffffffff) {
        psVar9 = _T(L"Masked decimal numbers are not allowed");
        FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
        *(undefined4 *)(param_1 + 0x42e) = 8;
        return;
      }
      bVar8 = false;
      bVar5 = true;
      *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
    }
LAB_0048639a:
    if ((bVar6) && (bVar5)) {
      local_3c = (float10)CONCAT28(0x3fff,0x8000000000000000);
      while ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8) &&
             (iVar12 = FUN_004ecd7c(), iVar12 != 0))) {
        bVar7 = false;
        bVar8 = false;
        local_3c = local_3c * _DAT_004867d4;
        _local_30 = _local_30 +
                    local_3c * (float10)(*(ushort *)(iVar3 + *(int *)(param_1 + 0xc) * 2) - 0x30);
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
      }
      if ((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
         ((*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == 'e' ||
          (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == 'E')))) {
        bVar7 = false;
        bVar8 = false;
        *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        if (*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 0xc)) {
          psVar9 = _T(L"Invalid floating-point exponent");
          FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
          *(undefined4 *)(param_1 + 0x42e) = 8;
          return;
        }
        if (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '+') {
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
        }
        else {
          if (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == '-') {
            *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          }
        }
        if ((*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 0xc)) ||
           (iVar12 = FUN_004ecd7c(), iVar12 == 0)) {
          psVar9 = _T(L"Invalid floating-point exponent");
          FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
          *(undefined4 *)(param_1 + 0x42e) = 8;
          return;
        }
        iVar12 = 0;
        while (iVar10 = FUN_004ecd7c(), iVar10 != 0) {
          uVar1 = *(ushort *)(iVar3 + *(int *)(param_1 + 0xc) * 2);
          *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
          iVar12 = (uint)uVar1 + iVar12 * 10 + -0x30;
          if (5000 < iVar12) {
            psVar9 = _T(L"Invalid floating-point exponent");
            FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
            *(undefined4 *)(param_1 + 0x42e) = 8;
            return;
          }
        }
        FUN_0041100b();
        FUN_004edf60();
        _local_30 = _local_30 * in_ST0;
        FUN_00411014();
      }
    }
    if (((param_1[1] & 4) != 0) && (bVar7)) {
      bVar8 = false;
    }
    if (bVar8) {
      if (((*(uint *)(param_1 + 0xc) < *(uint *)(param_1 + 8)) &&
          ((*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == 'h' ||
           (*(short *)(iVar3 + *(int *)(param_1 + 0xc) * 2) == 'H')))) &&
         (*(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1, bVar4)) {
        psVar9 = _T(L"Prefix 0x and suffix h are mutually exclusive");
        FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
        *(undefined4 *)(param_1 + 0x42e) = 8;
        return;
      }
      *(uint *)(param_1 + 0x18) = local_20;
      *(uint *)(param_1 + 0x1c) = local_24;
      *(undefined4 *)(param_1 + 0x42e) = 4;
      return;
    }
    if (((bVar7) && (bVar5)) && (_local_30 <= _DAT_004867e0)) {
      uVar11 = FUN_004eda98();
      *(undefined4 *)(param_1 + 0x18) = uVar11;
      *(undefined4 *)(param_1 + 0x1c) = 0xffffffff;
      *(undefined4 *)(param_1 + 0x42e) = 4;
      return;
    }
    if ((bVar6) && (bVar5)) {
      *(undefined4 *)(param_1 + 0x20) = local_30;
      *(undefined4 *)(param_1 + 0x24) = auStack44._0_4_;
      *(undefined2 *)(param_1 + 0x28) = auStack44._4_2_;
      *(undefined4 *)(param_1 + 0x42e) = 5;
      return;
    }
    psVar9 = _T(L"Invalid or out-of-range number");
    FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
    *(undefined4 *)(param_1 + 0x42e) = 8;
    return;
  }
  uVar15 = (uint)*(ushort *)(iVar3 + *(uint *)(param_1 + 0xc) * 2);
  if (uVar15 == '?') {
    if ((param_1[1] & 0x10) == 0) goto LAB_00486349;
    bVar6 = false;
    bVar7 = false;
    if ((local_20 & 0xf0000000) == 0) {
      local_20 <<= 4;
    }
    else {
      bVar8 = false;
    }
    local_24 <<= 4;
  }
  else {
    iVar12 = FUN_004ece10();
    if (iVar12 == 0) goto LAB_00486349;
    iVar12 = FUN_004ecd7c();
    if ((iVar12 == 0) || (_DAT_004867c4 < _local_30)) {
      bVar6 = false;
      bVar7 = false;
    }
    else {
      _local_30 = (float10)(uVar15 - 0x30) + _local_30 * (float10)10.0;
    }
    if (((local_20 & 0xf0000000) == 0) && ((local_24 & 0xf0000000) != 0)) {
      if (uVar15 < ':') {
        iVar12 = uVar15 - 0x30;
      }
      else {
        iVar12 = FUN_004ed0c0();
        iVar12 += -0x37;
      }
      local_20 = iVar12 + local_20 * 0x10;
      local_24 = local_24 << 4 | 0xf;
    }
    else {
      bVar8 = false;
    }
  }
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  goto LAB_0048633d;
LAB_0048587b:
  if (*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 0xc)) {
    psVar9 = _T(L"Unterminated string");
    FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
LAB_00485aca:
    *(undefined4 *)(param_1 + 0x42e) = 8;
                    /* WARNING: Read-only address (ram,0x004867c4) is written */
                    /* WARNING: Read-only address (ram,0x004867d4) is written */
                    /* WARNING: Read-only address (ram,0x004867e0) is written */
    return;
  }
  iVar12 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  sVar14 = *(short *)(iVar3 + iVar12 * 2);
  if (sVar14 == 0x22) {
    if ((*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 0xc)) ||
       (*(short *)(iVar3 + *(uint *)(param_1 + 0xc) * 2) != '\"')) {
      *(undefined2 *)(param_1 + *(int *)(param_1 + 0x22a) * 2 + 0x2a) = 0;
      *(undefined4 *)(param_1 + 0x42e) = 3;
      return;
    }
    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  }
  if (0xfe < *(int *)(param_1 + 0x22a)) {
    psVar9 = _T(L"String is too long");
    FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
    goto LAB_00485aca;
  }
  if (((sVar14 == 0) || (sVar14 == 10)) || (sVar14 == 0xd)) {
    psVar9 = _T(L"Unterminated string");
    FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
    goto LAB_00485aca;
  }
  if ((sVar14 != 0x5c) || ((*param_1 & 0x20) != 0)) goto LAB_00485ab4;
  if (*(uint *)(param_1 + 8) <= *(uint *)(param_1 + 0xc)) {
    psVar9 = _T(L"Unterminated string");
    FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
    goto LAB_00485aca;
  }
  iVar12 = *(int *)(param_1 + 0xc);
  *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
  sVar14 = *(short *)(iVar3 + iVar12 * 2);
  if (((sVar14 == 0) || (sVar14 == 10)) || (sVar14 == 0xd)) {
    psVar9 = _T(L"Unterminated string");
    FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
    goto LAB_00485aca;
  }
  if (sVar14 == 0x6e) {
    sVar14 = '\n';
  }
  else {
    if (sVar14 == 0x72) {
      sVar14 = '\r';
    }
    else {
      if (sVar14 == 0x74) {
        sVar14 = '\t';
      }
      else {
        if ((sVar14 == 0x78) || (sVar14 == 0x58)) {
          if (*(int *)(param_1 + 0xc) + 1U < *(uint *)(param_1 + 8)) {
            uVar15 = (uint)*(ushort *)(iVar3 + *(int *)(param_1 + 0xc) * 2);
            iVar12 = FUN_004ece10();
            if ((iVar12 != 0) &&
               (iVar12 = FUN_004ece10(*(int *)(param_1 + 0xc),
                                      *(undefined2 *)(iVar3 + 2 + *(int *)(param_1 + 0xc) * 2),
                                      uVar15), iVar12 != 0)) {
              *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
              iVar12 = FUN_004ed0c0();
              if (iVar12 < 0x3a) {
                sVar13 = (short)iVar12 + -0x39;
              }
              else {
                sVar13 = (short)iVar12 + -0x37;
              }
              *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;
              iVar12 = FUN_004ed0c0();
              if (iVar12 < 0x3a) {
                sVar14 = (short)iVar12 + -0x39;
              }
              else {
                sVar14 = (short)iVar12 + -0x37;
              }
              sVar14 = sVar13 * 0x10 + sVar14;
              goto LAB_00485ab4;
            }
          }
          psVar9 = _T(L"Hex escape must have two digits");
          FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
          goto LAB_00485aca;
        }
        if (sVar14 == 0x5c) {
          sVar14 = '\\';
        }
        else {
          if (sVar14 != 0x22) {
            psVar9 = _T(L"Unsupported escape sequence");
            FUN_004e78e4((undefined2 *)(param_1 + 0x22e),psVar9);
            goto LAB_00485aca;
          }
          sVar14 = '\"';
        }
      }
    }
  }
LAB_00485ab4:
  iVar12 = *(int *)(param_1 + 0x22a);
  *(int *)(param_1 + 0x22a) = *(int *)(param_1 + 0x22a) + 1;
  *(short *)(param_1 + iVar12 * 2 + 0x2a) = sVar14;
  goto LAB_0048587b;
}

