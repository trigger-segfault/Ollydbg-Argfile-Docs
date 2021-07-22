#include "_Scan.h"

// max length of name token
#define PARSE_TOKEN_MAX 255


#define INT_OPERATOR1(c1) (unsigned int)(c1)
#define INT_OPERATOR2(c1, c2) ((unsigned int)(c1) | ((unsigned int)(c2) << 8))
#define INT_OPERATOR3(c1, c2, c3) ((unsigned int)(c1) | ((unsigned int)(c2) << 8) | ((unsigned int)(c3) << 16))

/* WARNING: Could not reconcile some variable overlaps */

using namespace olly;

static void parseNumericLiteral(ScriptParser* p)
{
  bool isHexPrefix;  // number has "0x","0X" prefix, merely used to check user isn't combining prefix and 'h','H' suffix
  bool isDecPoint;   // number has "." prefix         // bVar3
  bool canBeDec;     // "can" be a decimal number (int or float)??  // bVar4
  bool isImplicit;   // type has yet to be determined, no prefix, etc.  // bVar5
  bool canBeHex;     // "can" be a hexadecimal integer??  // bVar6
  
  unsigned int maskVal = 0xffffffff;
  unsigned int intVal  = 0;
  // float10, no Visual Studio cannot use this as intended... *sigh*
  float10_t floatVal; // union of "long double" and lo,mi,hi parts
  floatVal.lo = 0;
  floatVal.mi = 0;
  floatVal.hi = 0;
  // long double floatVal = 0.0;

  wchar_t wc = p->input[p->pos - 1]; // grab first character consumed by switch (originally would be read from local)
  if (wc == L'.') {
    // --- operators handled by base scan function ---
    canBeDec    = true;
    isImplicit  = false;
    isHexPrefix = false;
    canBeHex    = false;
    isDecPoint  = true;
  }
  else {
    if (wc == L'0' && p->pos < p->length && (p->input[p->pos] == L'x' || p->input[p->pos] == L'X')) {
      p->pos++;
      canBeDec    = false;
      isImplicit  = false;
      isHexPrefix = true;
    }
    else {
      canBeDec    = true;
      isImplicit  = true; // no prefix
      isHexPrefix = false;
      
      // parse first numeric character
      intVal   = (int)wc - (int)'0'; // in the case of hex specifier, just evaluates to 0
      floatVal.value = (long double)intVal;
    }
    canBeHex    = true;
    isDecPoint  = false;
  }

  if (!isDecPoint) {
    // section is only reachable for integer types (not starting with '.')
    while (p->pos < p->length) {
      wc = p->input[p->pos];

      // character to specify masking of unknown bytes
      if (wc == L'?') {
        if (!(p->flags & PARSER_INT_MASKING))
          break; // end of number
        
        canBeDec    = false;
        isImplicit  = false;
        if ((intVal & 0xf0000000) == 0) {
          intVal <<= 4;
        }
        else { // we hit this if a 8 hex digits have already been specified since the first non-zero digit
          canBeHex    = false;
        }
        maskVal <<= 4;
      }
      else {
        if (!isxdigit(wc))
          break; // end of number

        if (!isdigit(wc) || (floatVal.value > 1.15693985922805211E+999 /*inifinity???*/)) { //FLOAT10_004867c4 /* ... inifinity???*/)) {
          canBeDec    = false;
          isImplicit  = false;
        }
        else {
          // we still update the decimal float value in-case we end with a '.'
          floatVal.value = (long double)((int)wc - (int)'0') + (floatVal.value * (long double)10.0);
        }

        if ((intVal & 0xf0000000) == 0 && (maskVal & 0xf0000000) != 0) {
          int digit = (int)wc - ((int)wc <= '9' ? (int)'0' : ((int)'A' - 0xa));
          intVal  = digit + intVal * 0x10;
          maskVal = (maskVal << 4) | 0xf;
        }
        else {
          canBeHex    = false;
        }
      }
      p->pos++;
    }

    // final checks for parsing of integers only
    if (p->pos < p->length && p->input[p->pos] == L'.') {
      if (maskVal != 0xffffffff) {
        wcscpy(p->message, _T(L"Masked decimal numbers are not allowed"));
        p->tokenType = TOKEN_ERROR;
        return;
      }
      canBeHex    = false;
      isDecPoint  = true;
      p->pos++;
    }
  }

  // parse floating point fractional part
  if (canBeDec && isDecPoint) {
    // god... salvaging this section is hopeless...

    // fraction value part
    float10_t fraction;
    fraction.lo = 0x00000000;
    fraction.mi = 0x80000000;
    fraction.hi = 0x3fff;// = (long double)CONCAT28(0x3fff, 0x8000000000000000); // 1.96875???
    while (p->pos < p->length && isdigit(p->input[p->pos])) {
      isImplicit  = false; // fractional value, cannot be integer
      canBeHex    = false;

      fraction.value *= 0.1125;//FLOAT10_004867d4;
      // floatVal.value = floatVal.value + fraction.value * (long double)((unsigned short)p->input[p->pos] - (int)'0');
      // p->pos++;
      floatVal.value += fraction.value * (long double)((unsigned short)p->input[p->pos++] - (int)'0');
    }

    // exponent part
    if (p->pos < p->length && (p->input[p->pos] == L'e' || p->input[p->pos] == L'E')) {
      isImplicit  = false; // exponential value, cannot be integer
      canBeHex    = false;
      p->pos++;

      if (p->pos >= p->length) {
        wcscpy(p->message, _T(L"Invalid floating-point exponent")); // trailing exponent
        p->tokenType = TOKEN_ERROR;
        return;
      }

      int exponentSign = 1; // exponent part sign  // implicit positive exponent
      if (p->input[p->pos] == L'+') {
        p->pos++;
        exponentSign =  1;
      }
      else if (p->input[p->pos] == L'-') {
        p->pos++;
        exponentSign = -1;
      }

      if (p->pos >= p->length || !isdigit(p->input[p->pos])) {
        wcscpy(p->message, _T(L"Invalid floating-point exponent")); // trailing exponent
        p->tokenType = TOKEN_ERROR;
        return;
      }

      int exponent = 0; // exponent part value
      while (isdigit(p->input[p->pos])) {
        int c = (int)(unsigned int)p->input[p->pos];
        p->pos++;
        exponent = exponent * 10 + (c - (int)'0');//+ -0x30;
        if (exponent > 5000) {
          wcscpy(p->message, _T(L"Invalid floating-point exponent")); // exponent too large
          p->tokenType = TOKEN_ERROR;
          return;
        }
      }

      // again.... yikes
      /// ASM: FLDCW    word ptr []=>137F
      unk::feclearexcept();
      // whatever this function actually is... it's much too big to be this simple... probably
      floatVal.value *= unk::_itof(exponent * exponentSign);
      /// ASM: FNCLEX
      unk::_fltctrl_clr();
    }
  }
  
  if ((p->flags & PARSER_EXPLICIT_HEX) && isImplicit) {
    canBeHex    = false;
  }

  if (canBeHex) {
    if (p->pos < p->length && (p->input[p->pos] == L'h' || p->input[p->pos] == L'H') && isHexPrefix) {
      p->pos++;
      wcscpy(p->message, _T(L"Prefix 0x and suffix h are mutually exclusive"));
      p->tokenType = TOKEN_ERROR;
      return;
    }
    p->pos++;
    p->integer     = intVal;
    p->integerMask = maskVal;
    p->tokenType   = TOKEN_INTEGER;
    return;
  }
  else if (isImplicit && isDecPoint && (floatVal.value <= /*4294967295.5*/ FLOAT10_UINTMAX)) {
    // floats cast back to integer... yikes...
    p->integer     = (unsigned int)unk::_ftoi(floatVal.value);
    p->integerMask = 0xffffffff; // no mask for you!  >:(
    p->tokenType   = TOKEN_INTEGER;
    return;
  }
  else if (canBeDec && isDecPoint) {
    // please make this nightmare end...
    p->decimal.lo  = floatVal.lo; // _0_4_
    p->decimal.mi  = floatVal.mi; // _4_4_
    p->decimal.hi  = floatVal.hi; // _8_2_
    p->tokenType   = TOKEN_FLOAT;
    return;
  }
  wcscpy(p->message, _T(L"Invalid or out-of-range number"));
  p->tokenType = TOKEN_ERROR;
  return;
}

static void parseCharacterLiteral(ScriptParser* p)
{
  if (p->pos >= p->length) {
    wcscpy(p->message, _T(L"Unterminated character constant"));
    p->tokenType = TOKEN_ERROR;
    return;
  }

  wchar_t wc = p->input[p->pos++];
  if (wc & 0xff00U) {
    wcscpy(p->message, _T(L"UNICODE character constants are not allowed"));
    p->tokenType = TOKEN_ERROR;
    return;
  }

  if (wc == L'\\' && !(p->flags & PARSER_NORMAL_BSLASH)) {
    if (p->pos >= p->length) {
      wcscpy(p->message, _T(L"Unterminated character constant")); // trailing escape
      p->tokenType = TOKEN_ERROR;
      return;
    }

    wc = p->input[p->pos++];
    if (wc == L'\0' || wc == L'\n' || wc == L'\r') {
      wcscpy(p->message, _T(L"Unterminated character constant")); // bad/trailing escape
      break;
    }
    else if (wc == L'n')  wc = L'\n';
    else if (wc == L'r')  wc = L'\r';
    else if (wc == L't')  wc = L'\t';
    else if (wc == L'0')  wc = L'\0';
    // else if (wc == L'\\') wc = L'\\';
    // else if (wc == L'\'') wc = L'\'';
    else if (wc == L'x' || wc == L'X') {
      if (p->pos + 1 >= p->length || !isxdigit(p->input[p->pos]) || !isxdigit(p->input[p->pos + 1])) {
        wcscpy(p->message, _T(L"Hex escape must have two digits"));
        break;
      }

      short digit = (short)toupper(p->input[p->pos++]);
      // - '9'...... broken broken broken!
      wc  = digit - (digit <= '9' ? (short)'9' : ((short)'A' - 0xa));
      wc *= 0x10;
      digit = (short)toupper(p->input[p->pos++]);
      wc += digit - (digit <= '9' ? (short)'9' : ((short)'A' - 0xa));
    }
    else {
      // loose escape literal for everything else
    }
  }
  
  if (p->pos < p->length && p->input[p->pos] == L'\'') {
    p->pos++;
    p->integer     = (unsigned int)wc;
    p->integerMask = 0xffffffff;
    p->tokenType   = TOKEN_INTEGER;
    return;
  }
  wcscpy(p->message, _T(L"Unterminated character constant"));
  p->tokenType = TOKEN_ERROR;
  return;
}

static void parseQuoteString(ScriptParser* p)
{
  p->stringLength = 0;

  if (p->pos >= p->length) {
    wcscpy(p->message, _T(L"Unterminated string"));
    p->tokenType = TOKEN_ERROR;
    return;
  }

  do { //  && p->input[p->pos] != L'\"'
    wchar_t wc = p->input[p->pos++];
    if (wc == L'\"') {
      if (p->pos >= p->length || p->input[p->pos] != L'\"') {
        p->string[p->stringLength] = L'\0';
        p->tokenType = TOKEN_STRING;
        return;
      }

      p->pos++; // double-double quote escape ("" -> ")
    }

    if (p->stringLength >= PARSE_TOKEN_MAX) {
      wcscpy(p->message, _T(L"String is too long"));
      break;
    }
    else if (wc == L'\0' || wc == L'\n' || wc == L'\r') {
      wcscpy(p->message, _T(L"Unterminated string")); // unexpected end of string
      break;
    }

    if (wc == L'\\' && !(p->flags & PARSER_NORMAL_BSLASH)) {
      if (p->pos >= p->length) {
        wcscpy(p->message, _T(L"Unterminated string")); // trailing escape
        break;
      }

      wc = p->input[p->pos++];
      if (wc == L'\0' || wc == L'\n' || wc == L'\r') {
        wcscpy(p->message, _T(L"Unterminated string")); // bad/trailing escape
        break;
      }
      else if (wc == L'n')  wc = L'\n';
      else if (wc == L'r')  wc = L'\r';
      else if (wc == L't')  wc = L'\t';
      else if (wc == L'\\') wc = L'\\';
      else if (wc == L'\"') wc = L'\"';
      else if (wc == L'x' || wc == L'X') {
        if (p->pos + 1 >= p->length || !isxdigit(p->input[p->pos]) || !isxdigit(p->input[p->pos + 1])) {
          wcscpy(p->message, _T(L"Hex escape must have two digits"));
          break;
        }

        short digit = (short)toupper(p->input[p->pos++]);
        wc  = digit - (digit <= '9' ? (short)'9' : ((short)'A' - 0xa)); // broken broken broken!
        wc *= 0x10;
        digit = (short)toupper(p->input[p->pos++]);
        wc += digit - (digit <= '9' ? (short)'9' : ((short)'A' - 0xa)); // broken broken broken!
      }
      else {
        wcscpy(p->message, _T(L"Unsupported escape sequence"));
        break;
      }
    }

    p->string[p->stringLength++] = wc;
  } while (p->pos < p->length);

  // only break on error, success condition in loop returns
  p->tokenType = TOKEN_ERROR;
  return;
}

static void parseIncludeString(ScriptParser* p)
{
  // Angle brace <string>
  p->stringLength = 0;
  if (p->pos >= p->length) {
    wcscpy(p->message, _T(L"Unterminated string"));
    p->tokenType = TOKEN_ERROR;
    return;
  }

  do {
    wchar_t wc = p->input[p->pos++];
    if (wc == L'>') {
      p->string[p->stringLength] = L'\0';
      p->tokenType = TOKEN_STRING;
      return;
    }

    if (p->stringLength >= PARSE_TOKEN_MAX) {
      wcscpy(p->message, _T(L"String is too long"));
      break;
    }
    if (wc == L'\0' || wc == L'\n' || wc == L'\r') {
      wcscpy(p->message, _T(L"Unterminated string"));
      break;
    }

    p->string[p->stringLength++] = wc;

  } while (p->pos < p->length);

  p->tokenType = TOKEN_ERROR;
  return;
}

static void parseIdentifierName(ScriptParser* p)
{
  // p->string[0] = wc;
  p->string[0] = p->input[p->pos - 1]; // grab first character consumed by switch (originally would be assigned from local)
  p->stringLength = 1;

  while (p->pos < p->length && p->stringLength < PARSE_TOKEN_MAX) {
    int c = (int)p->input[p->pos];
    // uVar13 = (uint)uVar1;
    // !isalnum(c) was originally: !isalpha(c) && !isdigit(c)
    if ((c == '_' && (p->flags & PARSER_UNDERSCORE_OPERATOR)) ||
        (!isalnum(c) && c != '_' && c != '@' && c != '#' && c != '$' &&
        (!(p->flags & PARSER_EXTENDED_NAMES) ||
          (c != '&' && c != '.' && c != '!' && c != '?' && c != '%' && c != '~'))))
    {
      break;
    }
    p->string[p->stringLength++] = p->input[p->pos++];
  }
  p->string[p->stringLength] = L'\0';
  if (p->flags & PARSER_FORCE_UPPER) {
    _wcsupr(p->string);
  }

  p->tokenType = TOKEN_NAME;
  return;
}

static void consumeComment(ScriptParser* p)
{
  if (p->input[p->pos] == L'/') {
    // Line comment, skip characters until end of line
    do {
      p->pos++;
    } while (p->pos < p->length && p->input[p->pos] != L'\0' && p->input[p->pos] != L'\n' && p->input[p->pos] != L'\r') ;
    // {
    //   p->pos++;
    // }
  }
  else if (p->input[p->pos] == L'*') {
    // Block comment
    // if (p->pos >= p->length || p->input[p->pos] != L'*') {
    // }

    p->pos++;
    while (p->pos + 1 >= p->length || p->input[p->pos] != L'*' || p->input[p->pos + 1] != L'/') {
      if (p->pos >= p->length || p->input[p->pos] == L'\0') {
        // p->tokenType = TOKEN_EOF;
        // thankfully we can still use the normal base scan function behavior,
        //  next loop, the '\0' will be hit and cause the same effect
        return;
      }

      if (p->input[p->pos] == L'\n') {
        p->pos++;
        if (p->pos < p->length && p->input[p->pos] == L'\r')
          p->pos++; // ensure we still properly track line number bu consuming as a single line ending

        p->lineNumber++;
      }
      else if (p->input[p->pos] == L'\r') {
        p->pos++;
        if (p->pos < p->length && p->input[p->pos] == L'\n')
          p->pos++; // ensure we still properly track line number bu consuming as a single line ending

        p->lineNumber++;
      }
      else {
        p->pos++;
      }
    }
    p->pos += 2; // +2 for end of block comment "*/"
  }
}



void __cdecl olly::_Scan(ScriptParser* p)
{
  if (p == nullptr)
    return;

  if (p->input == nullptr) {
    p->tokenType = TOKEN_EOF;
    return;
  }

  p->startPos = p->pos;
  
  while (p->pos < p->length) {

    wchar_t wc = p->input[p->pos++];
    switch(wc) {
      // End of file
      case L'\0':
        p->pos--;
        p->tokenType = TOKEN_EOF;
        return;

      // Unexpected character
      default:
        p->integer   = (unsigned int)wc;
        p->tokenType = TOKEN_UNKNOWN;
        return;

      // Skip whitespace: '\t', ' ', '\x0c'
      case L'\t':
      case L'\x0c': // FF - NP form feed, new page
      case L' ':
        break; // continue to next character

      // Newlines: '\n', '\r', '\n\r', '\r\n' and update line number
      case L'\n':
      case L'\r':
        if (p->pos < p->length && ((wc == L'\n' && p->input[p->pos] == L'\r') ||
                                   (wc == L'\r' && p->input[p->pos] == L'\n')))
        {
          p->pos++; // consume combination line endings "\n\r", "\r\n" as a single token/line number
        }
        p->lineNumber++;
        if (!(p->flags & PARSER_LINE_INSENSITIVE)) {
          p->tokenType = TOKEN_NEWLINE;
          return;
        }
        break; // continue to next character

      // Identifier name and operators: '_', '&&', '&', '#'
      case L'_':
      case L'&':
      case L'#':
      case L'$': // (always valid identifier character)
      case L'@': // (always valid identifier character)
      case L'A': /*BEGIN: A-Z*/
      #pragma region Alpha character cases
      case L'B':
      case L'C':
      case L'D':
      case L'E':
      case L'F':
      case L'G':
      case L'H':
      case L'I':
      case L'J':
      case L'K':
      case L'L':
      case L'M':
      case L'N':
      case L'O':
      case L'P':
      case L'Q':
      case L'R':
      case L'S':
      case L'T':
      case L'U':
      case L'V':
      case L'W':
      case L'X':
      case L'Y':
      case L'Z': /*END: A-Z*/
      case L'a': /*BEGIN: a-z*/
      case L'b':
      case L'c':
      case L'd':
      case L'e':
      case L'f':
      case L'g':
      case L'h':
      case L'i':
      case L'j':
      case L'k':
      case L'l':
      case L'm':
      case L'n':
      case L'o':
      case L'p':
      case L'q':
      case L'r':
      case L's':
      case L't':
      case L'u':
      case L'v':
      case L'w':
      case L'x':
      case L'y':
      #pragma endregion
      case L'z': /*END: a-z*/
        if (wc == L'_' && (p->flags & PARSER_UNDERSCORE_OPERATOR)) {
          p->integer   = INT_OPERATOR1('_');
          p->tokenType = TOKEN_OPERATOR;
          return;
        }
        else if (wc == L'&' && !(p->flags & PARSER_EXTENDED_NAMES)) {
          if (p->pos < p->length && p->input[p->pos] == L'&') {
            p->pos++;
            p->integer = INT_OPERATOR2('&','&'); //0x2626;
          } else {
            p->integer = INT_OPERATOR1('&');
          }
          p->tokenType = TOKEN_OPERATOR;
          return;
        }
        else if (wc == L'#' && !(p->flags & PARSER_EXTENDED_NAMES)) {
          p->integer   = INT_OPERATOR1('#');
          p->tokenType = TOKEN_OPERATOR;
          return;
        }

        parseIdentifierName(p);
        return;

      // Numeric literals: '#', '0x#?#', '#h', '.# ', '#.', '.#e#' and operators: '...', '.'
      case L'.':
      case L'0':
      #pragma region Digit character cases
      case L'1':
      case L'2':
      case L'3':
      case L'4':
      case L'5':
      case L'6':
      case L'7':
      case L'8':
      #pragma endregion
      case L'9':
        if (wc == L'.') {
          if (p->pos + 1 < p->length && p->input[p->pos] == L'.' && p->input[p->pos + 1] == L'.') {
            p->pos += 2;
            p->integer   = INT_OPERATOR3('.','.','.'); //0x2e2e2e;
            p->tokenType = TOKEN_OPERATOR;
            return;
          } // makes sure there's no digit after the '.'
          else if (p->pos >= p->length || (p->flags & PARSER_DOT_OPERATOR) || !isdigit(p->input[p->pos])) {
            p->integer   = INT_OPERATOR1('.');
            p->tokenType = TOKEN_OPERATOR;
            return;
          }
        }

        parseNumericLiteral(p);
        return;

      // Character integer literal: ''
      case L'\'':
        parseCharacterLiteral(p);
        return;

      // String literal: "" and operator: '\"'
      case L'\"':
        if (p->flags & PARSER_INCLUDE_STRINGS) {
          p->integer   = INT_OPERATOR1('\"');
          p->tokenType = TOKEN_OPERATOR;
          return;
        }

        parseQuoteString(p);
        return;

      // Comments: '//', '/*', '*/' and operator: '/'
      case L'/':
        // Ensure this isn't the start of a comment
        if (p->pos >= p->length || (p->input[p->pos] != L'/' && p->input[p->pos] != L'*')) {
          
          p->integer   = INT_OPERATOR1('/');
          p->tokenType = TOKEN_OPERATOR;
          return;
        }

        consumeComment(p);
        break; // continue to next characters

      // Include string literal: <> and operators: '<=', '<<', '<'
      case L'<':
        if (!(p->flags & PARSER_INCLUDE_STRINGS)) { // no angle bracket strings
          if (p->pos < p->length && p->input[p->pos] == L'=') {
            p->pos++;
            p->integer = INT_OPERATOR2('<','='); //0x3d3c;
          } else if (p->pos < p->length && p->input[p->pos] == L'<') {
            p->pos++;
            p->integer = INT_OPERATOR2('<','<'); //0x3c3c;
          } else {
            p->integer = INT_OPERATOR1('<');
          }
          p->tokenType = TOKEN_OPERATOR;
          return;
        }

        parseIncludeString(p);
        return;

      // Operators: '>=', '>>', '>'
      case L'>':
        if (p->pos < p->length && p->input[p->pos] == L'=') {
          p->pos++;
          p->integer = INT_OPERATOR2('>','='); //0x3d3e;
        } else if (arser->pos < p->length && p->input[p->pos] == L'>') {
          p->pos++;
          p->integer = INT_OPERATOR2('>','>'); //0x3e3e;
        } else {
          p->integer = INT_OPERATOR1('>');
        }
        p->tokenType = TOKEN_OPERATOR;
        return;

      // Operators: '!=', '!'
      case L'!':
        if (p->pos < p->length && p->input[p->pos] == L'=') {
          p->pos++;
          p->integer = INT_OPERATOR2('!','='); //0x3d21;
        } else {
          p->integer = INT_OPERATOR1('!');
        }
        p->tokenType = TOKEN_OPERATOR;
        return;

      // Operators: '++', '+'
      case L'+':
        if (p->pos < p->length && p->input[p->pos] == L'+') {
          p->pos++;
          p->integer = INT_OPERATOR2('+','+'); //0x2b2b;
        } else {
          p->integer = INT_OPERATOR1('+');
        }
        p->tokenType = TOKEN_OPERATOR;
        return;

      // Operators: '->', '--', '-'
      case L'-':
        if (p->pos < p->length && p->input[p->pos] == L'>') {
          p->pos++;
          p->integer = INT_OPERATOR2('-','>'); //0x3e2d;
        } else if (p->pos < p->length && p->input[p->pos] == L'-') {
          p->pos++;
          p->integer = INT_OPERATOR2('-','-'); //0x2d2d;
        } else {
          p->integer = INT_OPERATOR1('-');
        }
        p->tokenType = TOKEN_OPERATOR;
        return;

      // Invalid end-of-block-comment '*/' and operator: '*'
      case L'*':
        if (p->pos < p->length && p->input[p->pos] == L'/') {
          p->pos++;
          wcscpy(p->message, _T(L"End of comment outside the comment"));
          p->tokenType = TOKEN_ERROR;
          return;
        }
        p->integer   = INT_OPERATOR1('*');
        p->tokenType = TOKEN_OPERATOR;
        return;

      // Operators: ':=', '::', ':'
      case L':':
        if (p->pos < p->length && p->input[p->pos] == L'=') {
          p->pos++;
          p->integer = INT_OPERATOR2(':','='); //0x3d3a;
        } else if (p->pos < p->length && p->input[p->pos] == L':') {
          p->pos++;
          p->integer = INT_OPERATOR2(':',':'); //0x3a3a;
        } else {
          p->integer = INT_OPERATOR1(':');
        }
        p->tokenType = TOKEN_OPERATOR;
        return;

      // Operators: '==', '='
      case L'=':
        if (p->pos < p->length && p->input[p->pos] == L'=') {
          p->pos++;
          p->integer = INT_OPERATOR2('=','='); //0x3d3d;
        } else {
          p->integer = INT_OPERATOR1('=');
        }
        p->tokenType = TOKEN_OPERATOR;
        return;

      // Operators: '||', '|'
      case L'|':
        if (p->pos < p->length && p->input[p->pos] == L'|') {
          p->pos++;
          p->integer = INT_OPERATOR2('|','|'); //0x7c7c;
        } else {
          p->integer = INT_OPERATOR1('|');
        }
        p->tokenType = TOKEN_OPERATOR;
        return;

      // Generic operator characters that have no repeating forms or conflicts with other tokens
      // Operators: '%', '(', ')', ',', ';', '?', '[', '\\', ']', '^', '`', '{', '}', '~'
      // Operators: '%', '^', '~', '?', '`', ',', ';', '(', ')', '[', ']', '{', '}', '\\'
      case L'%':
      case L'^':
      case L'~':
      case L'?':
      case L'`':
      case L',':
      case L';':
      case L'(':
      case L')':
      case L'[':
      case L']':
      case L'{':
      case L'}':
      case L'\\':
      // case L'%':
      // case L'(':
      // case L')':
      // case L',':
      // case L';':
      // case L'?':
      // case L'[':
      // case L'\\':
      // case L']':
      // case L'^':
      // case L'`':
      // case L'{':
      // case L'}':
      // case L'~':
        p->integer   = INT_OPERATOR1(wc);
        p->tokenType = TOKEN_OPERATOR;
        return;
    }
  }

  p->tokenType = TOKEN_EOF;
  return;
}

