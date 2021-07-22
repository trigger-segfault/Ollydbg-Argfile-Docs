#pragma once


namespace olly {

#pragma region Enums

enum ParserFlags : unsigned int
{
	PARSER_NONE                 = 0,

	PARSER_FORCE_UPPER          = 0x1,    // forces identifier names and strings into uppercase
	PARSER_LINE_INSENSITIVE     = 0x10,   // disables newlines don't trigger the newline token. (line insensitive)
	PARSER_NORMAL_BSLASH        = 0x20,   // disables blackslash '\\' escapes (probably to allow easier Windows filepaths)
	PARSER_EXTENDED_NAMES       = 0x40,   // disables '#' prefix operator, and allows '&','&&','.','!','?','%','~' in names
	PARSER_UNDERSCORE_OPERATOR  = 0x80,   // enables '_' operator

	PARSER_DOT_OPERATOR         = 0x200,  // enables '.' operator
	PARSER_EXPLICIT_HEX         = 0x400,  // number cannot be hexadecimal without 0x prefix
	PARSER_INCLUDE_STRINGS      = 0x800,  // enables <angle bracket> include-style strings,
	                                      // disables '<' operators, and changes '\"' to an operator token
	PARSER_INT_MASKING          = 0x1000, // allows masking of individual hex digits with '?' assigning to the intMask field
};
DEFINE_ENUM_FLAG_OPERATORS(ParserFlags)

enum TokenType : unsigned int
{
	TOKEN_EOF      = 0, // END: '', '\0' or input == nullptr
	TOKEN_NEWLINE  = 1, // EOL: '\n', '\r', '\n\r', '\r\n'

	TOKEN_NAME     = 2, // identifier name, keyword, etc.
	TOKEN_STRING   = 3, // string literal: quoted "" or include <>
	TOKEN_INTEGER  = 4, // integer literal: uint32 integer or character ''
	TOKEN_FLOAT    = 5, // float10 decimal literal: (never accepted by arg files)
	TOKEN_OPERATOR = 6, // operators, punctuation

	TOKEN_UNKNOWN  = 7, // unexpected character
	TOKEN_ERROR    = 8, // malformed token, error message placed in message field
};

#pragma endregion


#pragma region Types

#pragma pack(push, 1)
union float10_t
{
	// naturally, this field is completely and utterly useless in Visual Studio :D   *sobs*
	/*0,a*/ long double value;
	struct {
		/*0,4*/ unsigned int lo;
		/*4,4*/ unsigned int mi;
		/*8,2*/ unsigned short hi;
		/*a*/
	};
};

struct ScriptParser
{
	/*000,4*/ ParserFlags flags;        // user-defined behavior for the parser
	/*004,4*/ const wchar_t* input;
	/*008,4*/ unsigned int length;      // length of input text
	/*00c,4*/ unsigned int pos;         // position in input text
	/*010,4*/ unsigned int tokenStart;  // pos at start of _Scan() function
	/*014,4*/ unsigned int lineNumber;
	/*018,4*/ unsigned int integer;     // integer value and operator/punctuation text string
	/*01c,4*/ unsigned int integerMask; // hexadecimal mask where '?' are filled in to individual digits
	/*020,a*/ float10_t decimal;
	/*02a,200*/ wchar_t string[256];    // identifier name/string value
	/*22a,4*/   int stringLength;
	/*22e,200*/ wchar_t message[256];   // message for errors
	/*42e,4*/ TokenType tokenType;
	/*432*/
};
#pragma pack(pop)

#pragma endregion


#pragma region Functions

void __cdecl _Scan(ScriptParser* p);

#pragma endregion


} /* namespace olly */
