#pragma once
#include "../Utilities.h"

namespace UltraEngine
{
  #undef ERROR;
    #undef STDAPI;

    class BaseLexer : public Object
    {
        protected:
            ILexer5* _lexer;
            shared_ptr<SyntaxEditor> _editor;
        private:
            BaseLexer();
            virtual void InitLexer() = 0;
        public:
            BaseLexer(shared_ptr<SyntaxEditor> editor)
            {
                _editor = editor;
            };
    };

	class PythonLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("python");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENTLINE = 1;
			static const int NUMBER = 2;
			static const int STRING = 3;
			static const int CHARACTER = 4;
			static const int WORD = 5;
			static const int TRIPLE = 6;
			static const int TRIPLEDOUBLE = 7;
			static const int CLASSNAME = 8;
			static const int DEFNAME = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int COMMENTBLOCK = 12;
			static const int STRINGEOL = 13;
			static const int WORD2 = 14;
			static const int DECORATOR = 15;
			static const int FSTRING = 16;
			static const int FCHARACTER = 17;
			static const int FTRIPLE = 18;
			static const int FTRIPLEDOUBLE = 19;
			PythonLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<PythonLexer> CreatePythonLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<PythonLexer>(editor);
	}
	class NimrodLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("nimrod");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENTLINE = 1;
			static const int NUMBER = 2;
			static const int STRING = 3;
			static const int CHARACTER = 4;
			static const int WORD = 5;
			static const int TRIPLE = 6;
			static const int TRIPLEDOUBLE = 7;
			static const int CLASSNAME = 8;
			static const int DEFNAME = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int COMMENTBLOCK = 12;
			static const int STRINGEOL = 13;
			static const int WORD2 = 14;
			static const int DECORATOR = 15;
			static const int FSTRING = 16;
			static const int FCHARACTER = 17;
			static const int FTRIPLE = 18;
			static const int FTRIPLEDOUBLE = 19;
			NimrodLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<NimrodLexer> CreateNimrodLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<NimrodLexer>(editor);
	}
	class CppLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("cpp");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTDOC = 3;
			static const int NUMBER = 4;
			static const int WORD = 5;
			static const int STRING = 6;
			static const int CHARACTER = 7;
			static const int UUID = 8;
			static const int PREPROCESSOR = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int STRINGEOL = 12;
			static const int VERBATIM = 13;
			static const int REGEX = 14;
			static const int COMMENTLINEDOC = 15;
			static const int WORD2 = 16;
			static const int COMMENTDOCKEYWORD = 17;
			static const int COMMENTDOCKEYWORDERROR = 18;
			static const int GLOBALCLASS = 19;
			static const int STRINGRAW = 20;
			static const int TRIPLEVERBATIM = 21;
			static const int HASHQUOTEDSTRING = 22;
			static const int PREPROCESSORCOMMENT = 23;
			static const int PREPROCESSORCOMMENTDOC = 24;
			static const int USERLITERAL = 25;
			static const int TASKMARKER = 26;
			static const int ESCAPESEQUENCE = 27;
			CppLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<CppLexer> CreateCppLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<CppLexer>(editor);
	}
	class BullAntLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("bullant");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTDOC = 3;
			static const int NUMBER = 4;
			static const int WORD = 5;
			static const int STRING = 6;
			static const int CHARACTER = 7;
			static const int UUID = 8;
			static const int PREPROCESSOR = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int STRINGEOL = 12;
			static const int VERBATIM = 13;
			static const int REGEX = 14;
			static const int COMMENTLINEDOC = 15;
			static const int WORD2 = 16;
			static const int COMMENTDOCKEYWORD = 17;
			static const int COMMENTDOCKEYWORDERROR = 18;
			static const int GLOBALCLASS = 19;
			static const int STRINGRAW = 20;
			static const int TRIPLEVERBATIM = 21;
			static const int HASHQUOTEDSTRING = 22;
			static const int PREPROCESSORCOMMENT = 23;
			static const int PREPROCESSORCOMMENTDOC = 24;
			static const int USERLITERAL = 25;
			static const int TASKMARKER = 26;
			static const int ESCAPESEQUENCE = 27;
			BullAntLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<BullAntLexer> CreateBullAntLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<BullAntLexer>(editor);
	}

	class COBOLLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("cobol");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTDOC = 3;
			static const int NUMBER = 4;
			static const int WORD = 5;
			static const int STRING = 6;
			static const int CHARACTER = 7;
			static const int UUID = 8;
			static const int PREPROCESSOR = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int STRINGEOL = 12;
			static const int VERBATIM = 13;
			static const int REGEX = 14;
			static const int COMMENTLINEDOC = 15;
			static const int WORD2 = 16;
			static const int COMMENTDOCKEYWORD = 17;
			static const int COMMENTDOCKEYWORDERROR = 18;
			static const int GLOBALCLASS = 19;
			static const int STRINGRAW = 20;
			static const int TRIPLEVERBATIM = 21;
			static const int HASHQUOTEDSTRING = 22;
			static const int PREPROCESSORCOMMENT = 23;
			static const int PREPROCESSORCOMMENTDOC = 24;
			static const int USERLITERAL = 25;
			static const int TASKMARKER = 26;
			static const int ESCAPESEQUENCE = 27;
			COBOLLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<COBOLLexer> CreateCOBOLLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<COBOLLexer>(editor);
	}
	class TACLLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("tacl");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTDOC = 3;
			static const int NUMBER = 4;
			static const int WORD = 5;
			static const int STRING = 6;
			static const int CHARACTER = 7;
			static const int UUID = 8;
			static const int PREPROCESSOR = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int STRINGEOL = 12;
			static const int VERBATIM = 13;
			static const int REGEX = 14;
			static const int COMMENTLINEDOC = 15;
			static const int WORD2 = 16;
			static const int COMMENTDOCKEYWORD = 17;
			static const int COMMENTDOCKEYWORDERROR = 18;
			static const int GLOBALCLASS = 19;
			static const int STRINGRAW = 20;
			static const int TRIPLEVERBATIM = 21;
			static const int HASHQUOTEDSTRING = 22;
			static const int PREPROCESSORCOMMENT = 23;
			static const int PREPROCESSORCOMMENTDOC = 24;
			static const int USERLITERAL = 25;
			static const int TASKMARKER = 26;
			static const int ESCAPESEQUENCE = 27;
			TACLLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<TACLLexer> CreateTACLLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<TACLLexer>(editor);
	}
	class TALLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("tal");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTDOC = 3;
			static const int NUMBER = 4;
			static const int WORD = 5;
			static const int STRING = 6;
			static const int CHARACTER = 7;
			static const int UUID = 8;
			static const int PREPROCESSOR = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int STRINGEOL = 12;
			static const int VERBATIM = 13;
			static const int REGEX = 14;
			static const int COMMENTLINEDOC = 15;
			static const int WORD2 = 16;
			static const int COMMENTDOCKEYWORD = 17;
			static const int COMMENTDOCKEYWORDERROR = 18;
			static const int GLOBALCLASS = 19;
			static const int STRINGRAW = 20;
			static const int TRIPLEVERBATIM = 21;
			static const int HASHQUOTEDSTRING = 22;
			static const int PREPROCESSORCOMMENT = 23;
			static const int PREPROCESSORCOMMENTDOC = 24;
			static const int USERLITERAL = 25;
			static const int TASKMARKER = 26;
			static const int ESCAPESEQUENCE = 27;
			TALLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<TALLexer> CreateTALLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<TALLexer>(editor);
	}
	class DLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("d");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTDOC = 3;
			static const int COMMENTNESTED = 4;
			static const int NUMBER = 5;
			static const int WORD = 6;
			static const int WORD2 = 7;
			static const int WORD3 = 8;
			static const int TYPEDEF = 9;
			static const int STRING = 10;
			static const int STRINGEOL = 11;
			static const int CHARACTER = 12;
			static const int OPERATOR = 13;
			static const int IDENTIFIER = 14;
			static const int COMMENTLINEDOC = 15;
			static const int COMMENTDOCKEYWORD = 16;
			static const int COMMENTDOCKEYWORDERROR = 17;
			static const int STRINGB = 18;
			static const int STRINGR = 19;
			static const int WORD5 = 20;
			static const int WORD6 = 21;
			static const int WORD7 = 22;
			DLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<DLexer> CreateDLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<DLexer>(editor);
	}
	class TCLLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("tcl");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int NUMBER = 3;
			static const int WORD_IN_QUOTE = 4;
			static const int IN_QUOTE = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int SUBSTITUTION = 8;
			static const int SUB_BRACE = 9;
			static const int MODIFIER = 10;
			static const int EXPAND = 11;
			static const int WORD = 12;
			static const int WORD2 = 13;
			static const int WORD3 = 14;
			static const int WORD4 = 15;
			static const int WORD5 = 16;
			static const int WORD6 = 17;
			static const int WORD7 = 18;
			static const int WORD8 = 19;
			static const int COMMENT_BOX = 20;
			static const int BLOCK_COMMENT = 21;
			TCLLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<TCLLexer> CreateTCLLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<TCLLexer>(editor);
	}
	class HTMLLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("hypertext");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int TAG = 1;
			static const int TAGUNKNOWN = 2;
			static const int ATTRIBUTE = 3;
			static const int ATTRIBUTEUNKNOWN = 4;
			static const int NUMBER = 5;
			static const int DOUBLESTRING = 6;
			static const int SINGLESTRING = 7;
			static const int OTHER = 8;
			static const int COMMENT = 9;
			static const int ENTITY = 10;
			static const int TAGEND = 11;
			static const int XMLSTART = 12;
			static const int XMLEND = 13;
			static const int SCRIPT = 14;
			static const int ASP = 15;
			static const int ASPAT = 16;
			static const int CDATA = 17;
			static const int QUESTION = 18;
			static const int VALUE = 19;
			static const int XCCOMMENT = 20;
			static const int SGML_DEFAULT = 21;
			static const int SGML_COMMAND = 22;
			static const int SGML_1ST_PARAM = 23;
			static const int SGML_DOUBLESTRING = 24;
			static const int SGML_SIMPLESTRING = 25;
			static const int SGML_ERROR = 26;
			static const int SGML_SPECIAL = 27;
			static const int SGML_ENTITY = 28;
			static const int SGML_COMMENT = 29;
			static const int SGML_1ST_PARAM_COMMENT = 30;
			static const int SGML_BLOCK_DEFAULT = 31;
			static const int START = 40;
			static const int HJ_DEFAULT = 41;
			static const int HJ_COMMENT = 42;
			static const int COMMENTLINE = 43;
			static const int COMMENTDOC = 44;
			static const int HJ_NUMBER = 45;
			static const int WORD = 46;
			static const int KEYWORD = 47;
			static const int HJ_DOUBLESTRING = 48;
			static const int HJ_SINGLESTRING = 49;
			static const int SYMBOLS = 50;
			static const int STRINGEOL = 51;
			static const int REGEX = 52;
			static const int HJA_START = 55;
			static const int HJA_DEFAULT = 56;
			static const int HJA_COMMENT = 57;
			static const int HJA_COMMENTLINE = 58;
			static const int HJA_COMMENTDOC = 59;
			static const int HJA_NUMBER = 60;
			static const int HJA_WORD = 61;
			static const int HJA_KEYWORD = 62;
			static const int HJA_DOUBLESTRING = 63;
			static const int HJA_SINGLESTRING = 64;
			static const int HJA_SYMBOLS = 65;
			static const int HJA_STRINGEOL = 66;
			static const int HJA_REGEX = 67;
			static const int HB_START = 70;
			static const int HB_DEFAULT = 71;
			static const int HB_COMMENTLINE = 72;
			static const int HB_NUMBER = 73;
			static const int HB_WORD = 74;
			static const int STRING = 75;
			static const int IDENTIFIER = 76;
			static const int HB_STRINGEOL = 77;
			static const int HBA_START = 80;
			static const int HBA_DEFAULT = 81;
			static const int HBA_COMMENTLINE = 82;
			static const int HBA_NUMBER = 83;
			static const int HBA_WORD = 84;
			static const int HBA_STRING = 85;
			static const int HBA_IDENTIFIER = 86;
			static const int HBA_STRINGEOL = 87;
			static const int HP_START = 90;
			static const int HP_DEFAULT = 91;
			static const int HP_COMMENTLINE = 92;
			static const int HP_NUMBER = 93;
			static const int HP_STRING = 94;
			static const int CHARACTER = 95;
			static const int HP_WORD = 96;
			static const int TRIPLE = 97;
			static const int TRIPLEDOUBLE = 98;
			static const int CLASSNAME = 99;
			static const int DEFNAME = 100;
			static const int OPERATOR = 101;
			static const int HP_IDENTIFIER = 102;
			static const int COMPLEX_VARIABLE = 104;
			static const int HPHP_DEFAULT = 118;
			static const int HSTRING = 119;
			static const int SIMPLESTRING = 120;
			static const int HPHP_WORD = 121;
			static const int HPHP_NUMBER = 122;
			static const int VARIABLE = 123;
			static const int HPHP_COMMENT = 124;
			static const int HPHP_COMMENTLINE = 125;
			static const int HSTRING_VARIABLE = 126;
			static const int HPHP_OPERATOR = 127;
			static const int HPA_START = 105;
			static const int HPA_DEFAULT = 106;
			static const int HPA_COMMENTLINE = 107;
			static const int HPA_NUMBER = 108;
			static const int HPA_STRING = 109;
			static const int HPA_CHARACTER = 110;
			static const int HPA_WORD = 111;
			static const int HPA_TRIPLE = 112;
			static const int HPA_TRIPLEDOUBLE = 113;
			static const int HPA_CLASSNAME = 114;
			static const int HPA_DEFNAME = 115;
			static const int HPA_OPERATOR = 116;
			static const int HPA_IDENTIFIER = 117;
			HTMLLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<HTMLLexer> CreateHTMLLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<HTMLLexer>(editor);
	}
	class XMLLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("xml");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int TAG = 1;
			static const int TAGUNKNOWN = 2;
			static const int ATTRIBUTE = 3;
			static const int ATTRIBUTEUNKNOWN = 4;
			static const int NUMBER = 5;
			static const int DOUBLESTRING = 6;
			static const int SINGLESTRING = 7;
			static const int OTHER = 8;
			static const int COMMENT = 9;
			static const int ENTITY = 10;
			static const int TAGEND = 11;
			static const int XMLSTART = 12;
			static const int XMLEND = 13;
			static const int SCRIPT = 14;
			static const int ASP = 15;
			static const int ASPAT = 16;
			static const int CDATA = 17;
			static const int QUESTION = 18;
			static const int VALUE = 19;
			static const int XCCOMMENT = 20;
			static const int SGML_DEFAULT = 21;
			static const int SGML_COMMAND = 22;
			static const int SGML_1ST_PARAM = 23;
			static const int SGML_DOUBLESTRING = 24;
			static const int SGML_SIMPLESTRING = 25;
			static const int SGML_ERROR = 26;
			static const int SGML_SPECIAL = 27;
			static const int SGML_ENTITY = 28;
			static const int SGML_COMMENT = 29;
			static const int SGML_1ST_PARAM_COMMENT = 30;
			static const int SGML_BLOCK_DEFAULT = 31;
			static const int START = 40;
			static const int HJ_DEFAULT = 41;
			static const int HJ_COMMENT = 42;
			static const int COMMENTLINE = 43;
			static const int COMMENTDOC = 44;
			static const int HJ_NUMBER = 45;
			static const int WORD = 46;
			static const int KEYWORD = 47;
			static const int HJ_DOUBLESTRING = 48;
			static const int HJ_SINGLESTRING = 49;
			static const int SYMBOLS = 50;
			static const int STRINGEOL = 51;
			static const int REGEX = 52;
			static const int HJA_START = 55;
			static const int HJA_DEFAULT = 56;
			static const int HJA_COMMENT = 57;
			static const int HJA_COMMENTLINE = 58;
			static const int HJA_COMMENTDOC = 59;
			static const int HJA_NUMBER = 60;
			static const int HJA_WORD = 61;
			static const int HJA_KEYWORD = 62;
			static const int HJA_DOUBLESTRING = 63;
			static const int HJA_SINGLESTRING = 64;
			static const int HJA_SYMBOLS = 65;
			static const int HJA_STRINGEOL = 66;
			static const int HJA_REGEX = 67;
			static const int HB_START = 70;
			static const int HB_DEFAULT = 71;
			static const int HB_COMMENTLINE = 72;
			static const int HB_NUMBER = 73;
			static const int HB_WORD = 74;
			static const int STRING = 75;
			static const int IDENTIFIER = 76;
			static const int HB_STRINGEOL = 77;
			static const int HBA_START = 80;
			static const int HBA_DEFAULT = 81;
			static const int HBA_COMMENTLINE = 82;
			static const int HBA_NUMBER = 83;
			static const int HBA_WORD = 84;
			static const int HBA_STRING = 85;
			static const int HBA_IDENTIFIER = 86;
			static const int HBA_STRINGEOL = 87;
			static const int HP_START = 90;
			static const int HP_DEFAULT = 91;
			static const int HP_COMMENTLINE = 92;
			static const int HP_NUMBER = 93;
			static const int HP_STRING = 94;
			static const int CHARACTER = 95;
			static const int HP_WORD = 96;
			static const int TRIPLE = 97;
			static const int TRIPLEDOUBLE = 98;
			static const int CLASSNAME = 99;
			static const int DEFNAME = 100;
			static const int OPERATOR = 101;
			static const int HP_IDENTIFIER = 102;
			static const int COMPLEX_VARIABLE = 104;
			static const int HPHP_DEFAULT = 118;
			static const int HSTRING = 119;
			static const int SIMPLESTRING = 120;
			static const int HPHP_WORD = 121;
			static const int HPHP_NUMBER = 122;
			static const int VARIABLE = 123;
			static const int HPHP_COMMENT = 124;
			static const int HPHP_COMMENTLINE = 125;
			static const int HSTRING_VARIABLE = 126;
			static const int HPHP_OPERATOR = 127;
			static const int HPA_START = 105;
			static const int HPA_DEFAULT = 106;
			static const int HPA_COMMENTLINE = 107;
			static const int HPA_NUMBER = 108;
			static const int HPA_STRING = 109;
			static const int HPA_CHARACTER = 110;
			static const int HPA_WORD = 111;
			static const int HPA_TRIPLE = 112;
			static const int HPA_TRIPLEDOUBLE = 113;
			static const int HPA_CLASSNAME = 114;
			static const int HPA_DEFNAME = 115;
			static const int HPA_OPERATOR = 116;
			static const int HPA_IDENTIFIER = 117;
			XMLLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<XMLLexer> CreateXMLLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<XMLLexer>(editor);
	}
	class PerlLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("perl");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int ERROR = 1;
			static const int COMMENTLINE = 2;
			static const int POD = 3;
			static const int NUMBER = 4;
			static const int WORD = 5;
			static const int STRING = 6;
			static const int CHARACTER = 7;
			static const int PUNCTUATION = 8;
			static const int PREPROCESSOR = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int SCALAR = 12;
			static const int ARRAY = 13;
			static const int HASH = 14;
			static const int SYMBOLTABLE = 15;
			static const int VARIABLE_INDEXER = 16;
			static const int REGEX = 17;
			static const int REGSUBST = 18;
			static const int LONGQUOTE = 19;
			static const int BACKTICKS = 20;
			static const int DATASECTION = 21;
			static const int HERE_DELIM = 22;
			static const int HERE_Q = 23;
			static const int HERE_QQ = 24;
			static const int HERE_QX = 25;
			static const int STRING_Q = 26;
			static const int STRING_QQ = 27;
			static const int STRING_QX = 28;
			static const int STRING_QR = 29;
			static const int STRING_QW = 30;
			static const int POD_VERB = 31;
			static const int SUB_PROTOTYPE = 40;
			static const int FORMAT_IDENT = 41;
			static const int FORMAT = 42;
			static const int STRING_VAR = 43;
			static const int XLAT = 44;
			static const int REGEX_VAR = 54;
			static const int REGSUBST_VAR = 55;
			static const int BACKTICKS_VAR = 57;
			static const int HERE_QQ_VAR = 61;
			static const int HERE_QX_VAR = 62;
			static const int STRING_QQ_VAR = 64;
			static const int STRING_QX_VAR = 65;
			static const int STRING_QR_VAR = 66;
			PerlLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<PerlLexer> CreatePerlLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<PerlLexer>(editor);
	}
	class RubyLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("ruby");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int ERROR = 1;
			static const int COMMENTLINE = 2;
			static const int POD = 3;
			static const int NUMBER = 4;
			static const int WORD = 5;
			static const int STRING = 6;
			static const int CHARACTER = 7;
			static const int CLASSNAME = 8;
			static const int DEFNAME = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int REGEX = 12;
			static const int GLOBAL = 13;
			static const int SYMBOL = 14;
			static const int MODULE_NAME = 15;
			static const int INSTANCE_VAR = 16;
			static const int CLASS_VAR = 17;
			static const int BACKTICKS = 18;
			static const int DATASECTION = 19;
			static const int HERE_DELIM = 20;
			static const int HERE_Q = 21;
			static const int HERE_QQ = 22;
			static const int HERE_QX = 23;
			static const int STRING_Q = 24;
			static const int STRING_QQ = 25;
			static const int STRING_QX = 26;
			static const int STRING_QR = 27;
			static const int STRING_QW = 28;
			static const int WORD_DEMOTED = 29;
			static const int STDIN = 30;
			static const int STDOUT = 31;
			static const int STDERR = 40;
			static const int UPPER_BOUND = 41;
			RubyLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<RubyLexer> CreateRubyLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<RubyLexer>(editor);
	}
	class VBLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("vb");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int KEYWORD = 3;
			static const int STRING = 4;
			static const int PREPROCESSOR = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int DATE = 8;
			static const int STRINGEOL = 9;
			static const int KEYWORD2 = 10;
			static const int KEYWORD3 = 11;
			static const int KEYWORD4 = 12;
			static const int CONSTANT = 13;
			static const int ASM = 14;
			static const int LABEL = 15;
			static const int ERROR = 16;
			static const int HEXNUMBER = 17;
			static const int BINNUMBER = 18;
			static const int COMMENTBLOCK = 19;
			static const int DOCLINE = 20;
			static const int DOCBLOCK = 21;
			static const int DOCKEYWORD = 22;
			VBLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<VBLexer> CreateVBLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<VBLexer>(editor);
	}
	class VBScriptLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("vbscript");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int KEYWORD = 3;
			static const int STRING = 4;
			static const int PREPROCESSOR = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int DATE = 8;
			static const int STRINGEOL = 9;
			static const int KEYWORD2 = 10;
			static const int KEYWORD3 = 11;
			static const int KEYWORD4 = 12;
			static const int CONSTANT = 13;
			static const int ASM = 14;
			static const int LABEL = 15;
			static const int ERROR = 16;
			static const int HEXNUMBER = 17;
			static const int BINNUMBER = 18;
			static const int COMMENTBLOCK = 19;
			static const int DOCLINE = 20;
			static const int DOCBLOCK = 21;
			static const int DOCKEYWORD = 22;
			VBScriptLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<VBScriptLexer> CreateVBScriptLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<VBScriptLexer>(editor);
	}
	class PowerBasicLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("powerbasic");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int KEYWORD = 3;
			static const int STRING = 4;
			static const int PREPROCESSOR = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int DATE = 8;
			static const int STRINGEOL = 9;
			static const int KEYWORD2 = 10;
			static const int KEYWORD3 = 11;
			static const int KEYWORD4 = 12;
			static const int CONSTANT = 13;
			static const int ASM = 14;
			static const int LABEL = 15;
			static const int ERROR = 16;
			static const int HEXNUMBER = 17;
			static const int BINNUMBER = 18;
			static const int COMMENTBLOCK = 19;
			static const int DOCLINE = 20;
			static const int DOCBLOCK = 21;
			static const int DOCKEYWORD = 22;
			PowerBasicLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<PowerBasicLexer> CreatePowerBasicLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<PowerBasicLexer>(editor);
	}
	class BlitzBasicLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("blitzbasic");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int KEYWORD = 3;
			static const int STRING = 4;
			static const int PREPROCESSOR = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int DATE = 8;
			static const int STRINGEOL = 9;
			static const int KEYWORD2 = 10;
			static const int KEYWORD3 = 11;
			static const int KEYWORD4 = 12;
			static const int CONSTANT = 13;
			static const int ASM = 14;
			static const int LABEL = 15;
			static const int ERROR = 16;
			static const int HEXNUMBER = 17;
			static const int BINNUMBER = 18;
			static const int COMMENTBLOCK = 19;
			static const int DOCLINE = 20;
			static const int DOCBLOCK = 21;
			static const int DOCKEYWORD = 22;
			BlitzBasicLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<BlitzBasicLexer> CreateBlitzBasicLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<BlitzBasicLexer>(editor);
	}
	class PureBasicLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("purebasic");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int KEYWORD = 3;
			static const int STRING = 4;
			static const int PREPROCESSOR = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int DATE = 8;
			static const int STRINGEOL = 9;
			static const int KEYWORD2 = 10;
			static const int KEYWORD3 = 11;
			static const int KEYWORD4 = 12;
			static const int CONSTANT = 13;
			static const int ASM = 14;
			static const int LABEL = 15;
			static const int ERROR = 16;
			static const int HEXNUMBER = 17;
			static const int BINNUMBER = 18;
			static const int COMMENTBLOCK = 19;
			static const int DOCLINE = 20;
			static const int DOCBLOCK = 21;
			static const int DOCKEYWORD = 22;
			PureBasicLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<PureBasicLexer> CreatePureBasicLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<PureBasicLexer>(editor);
	}
	class FreeBasicLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("freebasic");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int KEYWORD = 3;
			static const int STRING = 4;
			static const int PREPROCESSOR = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int DATE = 8;
			static const int STRINGEOL = 9;
			static const int KEYWORD2 = 10;
			static const int KEYWORD3 = 11;
			static const int KEYWORD4 = 12;
			static const int CONSTANT = 13;
			static const int ASM = 14;
			static const int LABEL = 15;
			static const int ERROR = 16;
			static const int HEXNUMBER = 17;
			static const int BINNUMBER = 18;
			static const int COMMENTBLOCK = 19;
			static const int DOCLINE = 20;
			static const int DOCBLOCK = 21;
			static const int DOCKEYWORD = 22;
			FreeBasicLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<FreeBasicLexer> CreateFreeBasicLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<FreeBasicLexer>(editor);
	}
	class PropertiesLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("properties");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int SECTION = 2;
			static const int ASSIGNMENT = 3;
			static const int DEFVAL = 4;
			static const int KEY = 5;
			PropertiesLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<PropertiesLexer> CreatePropertiesLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<PropertiesLexer>(editor);
	}
	class LaTeXLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("latex");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMAND = 1;
			static const int TAG = 2;
			static const int MATH = 3;
			static const int COMMENT = 4;
			static const int TAG2 = 5;
			static const int MATH2 = 6;
			static const int COMMENT2 = 7;
			static const int VERBATIM = 8;
			static const int SHORTCMD = 9;
			static const int SPECIAL = 10;
			static const int CMDOPT = 11;
			static const int ERROR = 12;
			LaTeXLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<LaTeXLexer> CreateLaTeXLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<LaTeXLexer>(editor);
	}
	class LuaLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("lua");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTDOC = 3;
			static const int NUMBER = 4;
			static const int WORD = 5;
			static const int STRING = 6;
			static const int CHARACTER = 7;
			static const int LITERALSTRING = 8;
			static const int PREPROCESSOR = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int STRINGEOL = 12;
			static const int WORD2 = 13;
			static const int WORD3 = 14;
			static const int WORD4 = 15;
			static const int WORD5 = 16;
			static const int WORD6 = 17;
			static const int WORD7 = 18;
			static const int WORD8 = 19;
			static const int LABEL = 20;
			LuaLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<LuaLexer> CreateLuaLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<LuaLexer>(editor);
	}
	class ErrorListLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("errorlist");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int PYTHON = 1;
			static const int GCC = 2;
			static const int MS = 3;
			static const int CMD = 4;
			static const int BORLAND = 5;
			static const int PERL = 6;
			static const int NET = 7;
			static const int LUA = 8;
			static const int CTAG = 9;
			static const int DIFF_CHANGED = 10;
			static const int DIFF_ADDITION = 11;
			static const int DIFF_DELETION = 12;
			static const int DIFF_MESSAGE = 13;
			static const int PHP = 14;
			static const int ELF = 15;
			static const int IFC = 16;
			static const int IFORT = 17;
			static const int ABSF = 18;
			static const int TIDY = 19;
			static const int JAVA_STACK = 20;
			static const int VALUE = 21;
			static const int GCC_INCLUDED_FROM = 22;
			static const int ESCSEQ = 23;
			static const int ESCSEQ_UNKNOWN = 24;
			static const int GCC_EXCERPT = 25;
			static const int ES_BLACK = 40;
			static const int ES_RED = 41;
			static const int ES_GREEN = 42;
			static const int ES_BROWN = 43;
			static const int ES_BLUE = 44;
			static const int ES_MAGENTA = 45;
			static const int ES_CYAN = 46;
			static const int ES_GRAY = 47;
			static const int ES_DARK_GRAY = 48;
			static const int ES_BRIGHT_RED = 49;
			static const int ES_BRIGHT_GREEN = 50;
			static const int ES_YELLOW = 51;
			static const int ES_BRIGHT_BLUE = 52;
			static const int ES_BRIGHT_MAGENTA = 53;
			static const int ES_BRIGHT_CYAN = 54;
			static const int ES_WHITE = 55;
			ErrorListLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<ErrorListLexer> CreateErrorListLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<ErrorListLexer>(editor);
	}
	class BatchLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("batch");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int WORD = 2;
			static const int LABEL = 3;
			static const int HIDE = 4;
			static const int COMMAND = 5;
			static const int IDENTIFIER = 6;
			static const int OPERATOR = 7;
			BatchLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<BatchLexer> CreateBatchLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<BatchLexer>(editor);
	}
	class TCMDLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("tcmd");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int WORD = 2;
			static const int LABEL = 3;
			static const int HIDE = 4;
			static const int COMMAND = 5;
			static const int IDENTIFIER = 6;
			static const int OPERATOR = 7;
			static const int ENVIRONMENT = 8;
			static const int EXPANSION = 9;
			static const int CLABEL = 10;
			TCMDLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<TCMDLexer> CreateTCMDLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<TCMDLexer>(editor);
	}
	class MakeFileLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("makefile");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int PREPROCESSOR = 2;
			static const int IDENTIFIER = 3;
			static const int OPERATOR = 4;
			static const int TARGET = 5;
			static const int IDEOL = 9;
			MakeFileLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<MakeFileLexer> CreateMakeFileLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<MakeFileLexer>(editor);
	}
	class DiffLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("diff");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMAND = 2;
			static const int HEADER = 3;
			static const int POSITION = 4;
			static const int DELETED = 5;
			static const int ADDED = 6;
			static const int CHANGED = 7;
			static const int PATCH_ADD = 8;
			static const int PATCH_DELETE = 9;
			static const int REMOVED_PATCH_ADD = 10;
			static const int REMOVED_PATCH_DELETE = 11;
			DiffLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<DiffLexer> CreateDiffLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<DiffLexer>(editor);
	}
	class ConfLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("conf");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int IDENTIFIER = 3;
			static const int EXTENSION = 4;
			static const int PARAMETER = 5;
			static const int STRING = 6;
			static const int OPERATOR = 7;
			static const int IP = 8;
			static const int DIRECTIVE = 9;
			ConfLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<ConfLexer> CreateConfLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<ConfLexer>(editor);
	}
	class AvenueLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("avenue");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int WORD = 3;
			static const int STRING = 6;
			static const int ENUM = 7;
			static const int STRINGEOL = 8;
			static const int IDENTIFIER = 9;
			static const int OPERATOR = 10;
			static const int WORD1 = 11;
			static const int WORD2 = 12;
			static const int WORD3 = 13;
			static const int WORD4 = 14;
			static const int WORD5 = 15;
			static const int WORD6 = 16;
			AvenueLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<AvenueLexer> CreateAvenueLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<AvenueLexer>(editor);
	}
	class AdaLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("ada");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int WORD = 1;
			static const int IDENTIFIER = 2;
			static const int NUMBER = 3;
			static const int DELIMITER = 4;
			static const int CHARACTER = 5;
			static const int CHARACTEREOL = 6;
			static const int STRING = 7;
			static const int STRINGEOL = 8;
			static const int LABEL = 9;
			static const int COMMENTLINE = 10;
			static const int ILLEGAL = 11;
			AdaLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<AdaLexer> CreateAdaLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<AdaLexer>(editor);
	}
	class BaanLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("baan");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTDOC = 2;
			static const int NUMBER = 3;
			static const int WORD = 4;
			static const int STRING = 5;
			static const int PREPROCESSOR = 6;
			static const int OPERATOR = 7;
			static const int IDENTIFIER = 8;
			static const int STRINGEOL = 9;
			static const int WORD2 = 10;
			static const int WORD3 = 11;
			static const int WORD4 = 12;
			static const int WORD5 = 13;
			static const int WORD6 = 14;
			static const int WORD7 = 15;
			static const int WORD8 = 16;
			static const int WORD9 = 17;
			static const int TABLEDEF = 18;
			static const int TABLESQL = 19;
			static const int FUNCTION = 20;
			static const int DOMDEF = 21;
			static const int FUNCDEF = 22;
			static const int OBJECTDEF = 23;
			static const int DEFINEDEF = 24;
			BaanLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<BaanLexer> CreateBaanLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<BaanLexer>(editor);
	}
	class LispLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("lisp");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int KEYWORD = 3;
			static const int KEYWORD_KW = 4;
			static const int SYMBOL = 5;
			static const int STRING = 6;
			static const int STRINGEOL = 8;
			static const int IDENTIFIER = 9;
			static const int OPERATOR = 10;
			static const int SPECIAL = 11;
			static const int MULTI_COMMENT = 12;
			LispLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<LispLexer> CreateLispLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<LispLexer>(editor);
	}
	class EiffelLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("eiffel");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENTLINE = 1;
			static const int NUMBER = 2;
			static const int WORD = 3;
			static const int STRING = 4;
			static const int CHARACTER = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int STRINGEOL = 8;
			EiffelLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<EiffelLexer> CreateEiffelLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<EiffelLexer>(editor);
	}
	class EiffelKWLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("eiffelkw");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENTLINE = 1;
			static const int NUMBER = 2;
			static const int WORD = 3;
			static const int STRING = 4;
			static const int CHARACTER = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int STRINGEOL = 8;
			EiffelKWLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<EiffelKWLexer> CreateEiffelKWLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<EiffelKWLexer>(editor);
	}
	class NNCronTabLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("nncrontab");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int TASK = 2;
			static const int SECTION = 3;
			static const int KEYWORD = 4;
			static const int MODIFIER = 5;
			static const int ASTERISK = 6;
			static const int NUMBER = 7;
			static const int STRING = 8;
			static const int ENVIRONMENT = 9;
			static const int IDENTIFIER = 10;
			NNCronTabLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<NNCronTabLexer> CreateNNCronTabLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<NNCronTabLexer>(editor);
	}
	class ForthLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("forth");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENT_ML = 2;
			static const int IDENTIFIER = 3;
			static const int CONTROL = 4;
			static const int KEYWORD = 5;
			static const int DEFWORD = 6;
			static const int PREWORD1 = 7;
			static const int PREWORD2 = 8;
			static const int NUMBER = 9;
			static const int STRING = 10;
			static const int LOCALE = 11;
			ForthLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<ForthLexer> CreateForthLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<ForthLexer>(editor);
	}
	class MatLabLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("matlab");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMAND = 2;
			static const int NUMBER = 3;
			static const int KEYWORD = 4;
			static const int STRING = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int DOUBLEQUOTESTRING = 8;
			MatLabLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<MatLabLexer> CreateMatLabLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<MatLabLexer>(editor);
	}
	class MaximaLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("maxima");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int OPERATOR = 0;
			static const int COMMANDENDING = 1;
			static const int COMMENT = 2;
			static const int NUMBER = 3;
			static const int STRING = 4;
			static const int COMMAND = 5;
			static const int VARIABLE = 6;
			static const int UNKNOWN = 7;
			MaximaLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<MaximaLexer> CreateMaximaLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<MaximaLexer>(editor);
	}
	class SolLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("sol");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int WHITE = 1;
			static const int COMMENTLINE = 2;
			static const int PERSISTENT = 3;
			static const int CSTYLE = 4;
			static const int COMMENTBLOCK = 5;
			static const int NUMBER = 6;
			static const int STRING = 7;
			static const int CHARACTER = 8;
			static const int STRINGEOL = 9;
			static const int KEYWORD = 10;
			static const int OPERATOR = 11;
			static const int IDENTIFIER = 12;
			static const int TRIPLE = 13;
			static const int CLASSNAME = 14;
			static const int PREPROCESSOR = 15;
			SolLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<SolLexer> CreateSolLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<SolLexer>(editor);
	}
	class AsmLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("asm");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int STRING = 3;
			static const int OPERATOR = 4;
			static const int IDENTIFIER = 5;
			static const int CPUINSTRUCTION = 6;
			static const int MATHINSTRUCTION = 7;
			static const int REGISTER = 8;
			static const int DIRECTIVE = 9;
			static const int DIRECTIVEOPERAND = 10;
			static const int COMMENTBLOCK = 11;
			static const int CHARACTER = 12;
			static const int STRINGEOL = 13;
			static const int EXTINSTRUCTION = 14;
			static const int COMMENTDIRECTIVE = 15;
			AsmLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<AsmLexer> CreateAsmLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<AsmLexer>(editor);
	}
	class AsLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("as");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int STRING = 3;
			static const int OPERATOR = 4;
			static const int IDENTIFIER = 5;
			static const int CPUINSTRUCTION = 6;
			static const int MATHINSTRUCTION = 7;
			static const int REGISTER = 8;
			static const int DIRECTIVE = 9;
			static const int DIRECTIVEOPERAND = 10;
			static const int COMMENTBLOCK = 11;
			static const int CHARACTER = 12;
			static const int STRINGEOL = 13;
			static const int EXTINSTRUCTION = 14;
			static const int COMMENTDIRECTIVE = 15;
			AsLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<AsLexer> CreateAsLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<AsLexer>(editor);
	}
	class FortranLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("fortran");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int STRING1 = 3;
			static const int STRING2 = 4;
			static const int STRINGEOL = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int WORD = 8;
			static const int WORD2 = 9;
			static const int WORD3 = 10;
			static const int PREPROCESSOR = 11;
			static const int OPERATOR2 = 12;
			static const int LABEL = 13;
			static const int CONTINUATION = 14;
			FortranLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<FortranLexer> CreateFortranLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<FortranLexer>(editor);
	}
	class F77Lexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("f77");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int STRING1 = 3;
			static const int STRING2 = 4;
			static const int STRINGEOL = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int WORD = 8;
			static const int WORD2 = 9;
			static const int WORD3 = 10;
			static const int PREPROCESSOR = 11;
			static const int OPERATOR2 = 12;
			static const int LABEL = 13;
			static const int CONTINUATION = 14;
			F77Lexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<F77Lexer> CreateF77Lexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<F77Lexer>(editor);
	}
	class CSSLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("css");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int TAG = 1;
			static const int CLASS = 2;
			static const int PSEUDOCLASS = 3;
			static const int UNKNOWN_PSEUDOCLASS = 4;
			static const int OPERATOR = 5;
			static const int IDENTIFIER = 6;
			static const int UNKNOWN_IDENTIFIER = 7;
			static const int VALUE = 8;
			static const int COMMENT = 9;
			static const int ID = 10;
			static const int IMPORTANT = 11;
			static const int DIRECTIVE = 12;
			static const int DOUBLESTRING = 13;
			static const int SINGLESTRING = 14;
			static const int IDENTIFIER2 = 15;
			static const int ATTRIBUTE = 16;
			static const int IDENTIFIER3 = 17;
			static const int PSEUDOELEMENT = 18;
			static const int EXTENDED_IDENTIFIER = 19;
			static const int EXTENDED_PSEUDOCLASS = 20;
			static const int EXTENDED_PSEUDOELEMENT = 21;
			static const int MEDIA = 22;
			static const int VARIABLE = 23;
			CSSLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<CSSLexer> CreateCSSLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<CSSLexer>(editor);
	}
	class POVLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("pov");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int NUMBER = 3;
			static const int OPERATOR = 4;
			static const int IDENTIFIER = 5;
			static const int STRING = 6;
			static const int STRINGEOL = 7;
			static const int DIRECTIVE = 8;
			static const int BADDIRECTIVE = 9;
			static const int WORD2 = 10;
			static const int WORD3 = 11;
			static const int WORD4 = 12;
			static const int WORD5 = 13;
			static const int WORD6 = 14;
			static const int WORD7 = 15;
			static const int WORD8 = 16;
			POVLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<POVLexer> CreatePOVLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<POVLexer>(editor);
	}
	class LOUTLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("lout");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int WORD = 3;
			static const int WORD2 = 4;
			static const int WORD3 = 5;
			static const int WORD4 = 6;
			static const int STRING = 7;
			static const int OPERATOR = 8;
			static const int IDENTIFIER = 9;
			static const int STRINGEOL = 10;
			LOUTLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<LOUTLexer> CreateLOUTLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<LOUTLexer>(editor);
	}
	class ESCRIPTLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("escript");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTDOC = 3;
			static const int NUMBER = 4;
			static const int WORD = 5;
			static const int STRING = 6;
			static const int OPERATOR = 7;
			static const int IDENTIFIER = 8;
			static const int BRACE = 9;
			static const int WORD2 = 10;
			static const int WORD3 = 11;
			ESCRIPTLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<ESCRIPTLexer> CreateESCRIPTLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<ESCRIPTLexer>(editor);
	}
	class PSLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("ps");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int DSC_COMMENT = 2;
			static const int DSC_VALUE = 3;
			static const int NUMBER = 4;
			static const int NAME = 5;
			static const int KEYWORD = 6;
			static const int LITERAL = 7;
			static const int IMMEVAL = 8;
			static const int PAREN_ARRAY = 9;
			static const int PAREN_DICT = 10;
			static const int PAREN_PROC = 11;
			static const int TEXT = 12;
			static const int HEXSTRING = 13;
			static const int BASE85STRING = 14;
			static const int BADSTRINGCHAR = 15;
			PSLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<PSLexer> CreatePSLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<PSLexer>(editor);
	}
	class NSISLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("nsis");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int STRINGDQ = 2;
			static const int STRINGLQ = 3;
			static const int STRINGRQ = 4;
			static const int FUNCTION = 5;
			static const int VARIABLE = 6;
			static const int LABEL = 7;
			static const int USERDEFINED = 8;
			static const int SECTIONDEF = 9;
			static const int SUBSECTIONDEF = 10;
			static const int IFDEFINEDEF = 11;
			static const int MACRODEF = 12;
			static const int STRINGVAR = 13;
			static const int NUMBER = 14;
			static const int SECTIONGROUP = 15;
			static const int PAGEEX = 16;
			static const int FUNCTIONDEF = 17;
			static const int COMMENTBOX = 18;
			NSISLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<NSISLexer> CreateNSISLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<NSISLexer>(editor);
	}
	class MMIXALLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("mmixal");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int LEADWS = 0;
			static const int COMMENT = 1;
			static const int LABEL = 2;
			static const int OPCODE = 3;
			static const int OPCODE_PRE = 4;
			static const int OPCODE_VALID = 5;
			static const int OPCODE_UNKNOWN = 6;
			static const int OPCODE_POST = 7;
			static const int OPERANDS = 8;
			static const int NUMBER = 9;
			static const int REF = 10;
			static const int CHAR = 11;
			static const int STRING = 12;
			static const int REGISTER = 13;
			static const int HEX = 14;
			static const int OPERATOR = 15;
			static const int SYMBOL = 16;
			static const int INCLUDE = 17;
			MMIXALLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<MMIXALLexer> CreateMMIXALLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<MMIXALLexer>(editor);
	}
	class ClarionLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("clarion");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int LABEL = 1;
			static const int COMMENT = 2;
			static const int STRING = 3;
			static const int USER_IDENTIFIER = 4;
			static const int INTEGER_CONSTANT = 5;
			static const int REAL_CONSTANT = 6;
			static const int PICTURE_STRING = 7;
			static const int KEYWORD = 8;
			static const int COMPILER_DIRECTIVE = 9;
			static const int RUNTIME_EXPRESSIONS = 10;
			static const int BUILTIN_PROCEDURES_FUNCTION = 11;
			static const int STRUCTURE_DATA_TYPE = 12;
			static const int ATTRIBUTE = 13;
			static const int STANDARD_EQUATE = 14;
			static const int ERROR = 15;
			static const int DEPRECATED = 16;
			ClarionLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<ClarionLexer> CreateClarionLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<ClarionLexer>(editor);
	}
	class LOTLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("lot");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int HEADER = 1;
			static const int BREAK = 2;
			static const int SET = 3;
			static const int PASS = 4;
			static const int FAIL = 5;
			static const int ABORT = 6;
			LOTLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<LOTLexer> CreateLOTLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<LOTLexer>(editor);
	}
	class YAMLLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("yaml");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int IDENTIFIER = 2;
			static const int KEYWORD = 3;
			static const int NUMBER = 4;
			static const int REFERENCE = 5;
			static const int DOCUMENT = 6;
			static const int TEXT = 7;
			static const int ERROR = 8;
			static const int OPERATOR = 9;
			YAMLLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<YAMLLexer> CreateYAMLLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<YAMLLexer>(editor);
	}
	class TeXLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("tex");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int SPECIAL = 1;
			static const int GROUP = 2;
			static const int SYMBOL = 3;
			static const int COMMAND = 4;
			static const int TEXT = 5;
			TeXLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<TeXLexer> CreateTeXLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<TeXLexer>(editor);
	}
	class MetapostLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("metapost");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int SPECIAL = 1;
			static const int GROUP = 2;
			static const int SYMBOL = 3;
			static const int COMMAND = 4;
			static const int TEXT = 5;
			static const int EXTRA = 6;
			MetapostLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<MetapostLexer> CreateMetapostLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<MetapostLexer>(editor);
	}
	class ErlangLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("erlang");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int VARIABLE = 2;
			static const int NUMBER = 3;
			static const int KEYWORD = 4;
			static const int STRING = 5;
			static const int OPERATOR = 6;
			static const int ATOM = 7;
			static const int FUNCTION_NAME = 8;
			static const int CHARACTER = 9;
			static const int MACRO = 10;
			static const int RECORD = 11;
			static const int PREPROC = 12;
			static const int NODE_NAME = 13;
			static const int COMMENT_FUNCTION = 14;
			static const int COMMENT_MODULE = 15;
			static const int COMMENT_DOC = 16;
			static const int COMMENT_DOC_MACRO = 17;
			static const int ATOM_QUOTED = 18;
			static const int MACRO_QUOTED = 19;
			static const int RECORD_QUOTED = 20;
			static const int NODE_NAME_QUOTED = 21;
			static const int BIFS = 22;
			static const int MODULES = 23;
			static const int MODULES_ATT = 24;
			static const int UNKNOWN = 31;
			ErlangLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<ErlangLexer> CreateErlangLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<ErlangLexer>(editor);
	}
	class OctaveLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("octave");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMAND = 2;
			static const int NUMBER = 3;
			static const int KEYWORD = 4;
			static const int STRING = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int DOUBLEQUOTESTRING = 8;
			OctaveLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<OctaveLexer> CreateOctaveLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<OctaveLexer>(editor);
	}
	class MSSQLLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("mssql");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int LINE_COMMENT = 2;
			static const int NUMBER = 3;
			static const int STRING = 4;
			static const int OPERATOR = 5;
			static const int IDENTIFIER = 6;
			static const int VARIABLE = 7;
			static const int COLUMN_NAME = 8;
			static const int STATEMENT = 9;
			static const int DATATYPE = 10;
			static const int SYSTABLE = 11;
			static const int GLOBAL_VARIABLE = 12;
			static const int FUNCTION = 13;
			static const int STORED_PROCEDURE = 14;
			static const int DEFAULT_PREF_DATATYPE = 15;
			static const int COLUMN_NAME_2 = 16;
			MSSQLLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<MSSQLLexer> CreateMSSQLLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<MSSQLLexer>(editor);
	}
	class VerilogLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("verilog");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTLINEBANG = 3;
			static const int NUMBER = 4;
			static const int WORD = 5;
			static const int STRING = 6;
			static const int WORD2 = 7;
			static const int WORD3 = 8;
			static const int PREPROCESSOR = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int STRINGEOL = 12;
			static const int USER = 19;
			static const int COMMENT_WORD = 20;
			static const int INPUT = 21;
			static const int OUTPUT = 22;
			static const int INOUT = 23;
			static const int PORT_CONNECT = 24;
			VerilogLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<VerilogLexer> CreateVerilogLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<VerilogLexer>(editor);
	}
	class KixLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("kix");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int STRING1 = 2;
			static const int STRING2 = 3;
			static const int NUMBER = 4;
			static const int VAR = 5;
			static const int MACRO = 6;
			static const int KEYWORD = 7;
			static const int FUNCTIONS = 8;
			static const int OPERATOR = 9;
			static const int COMMENTSTREAM = 10;
			static const int IDENTIFIER = 31;
			KixLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<KixLexer> CreateKixLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<KixLexer>(editor);
	}
	class Gui4CliLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("gui4cli");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENTLINE = 1;
			static const int COMMENTBLOCK = 2;
			static const int GLOBAL = 3;
			static const int EVENT = 4;
			static const int ATTRIBUTE = 5;
			static const int CONTROL = 6;
			static const int COMMAND = 7;
			static const int STRING = 8;
			static const int OPERATOR = 9;
			Gui4CliLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<Gui4CliLexer> CreateGui4CliLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<Gui4CliLexer>(editor);
	}
	class SpecmanLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("specman");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int CODE = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTLINEBANG = 3;
			static const int NUMBER = 4;
			static const int WORD = 5;
			static const int STRING = 6;
			static const int WORD2 = 7;
			static const int WORD3 = 8;
			static const int PREPROCESSOR = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int STRINGEOL = 12;
			static const int REGEXTAG = 13;
			static const int SIGNAL = 14;
			static const int USER = 19;
			SpecmanLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<SpecmanLexer> CreateSpecmanLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<SpecmanLexer>(editor);
	}
	class Au3Lexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("au3");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTBLOCK = 2;
			static const int NUMBER = 3;
			static const int FUNCTION = 4;
			static const int KEYWORD = 5;
			static const int MACRO = 6;
			static const int STRING = 7;
			static const int OPERATOR = 8;
			static const int VARIABLE = 9;
			static const int SENT = 10;
			static const int PREPROCESSOR = 11;
			static const int SPECIAL = 12;
			static const int EXPAND = 13;
			static const int COMOBJ = 14;
			static const int UDF = 15;
			Au3Lexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<Au3Lexer> CreateAu3Lexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<Au3Lexer>(editor);
	}
	class APDLLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("apdl");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTBLOCK = 2;
			static const int NUMBER = 3;
			static const int STRING = 4;
			static const int OPERATOR = 5;
			static const int WORD = 6;
			static const int PROCESSOR = 7;
			static const int COMMAND = 8;
			static const int SLASHCOMMAND = 9;
			static const int STARCOMMAND = 10;
			static const int ARGUMENT = 11;
			static const int FUNCTION = 12;
			APDLLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<APDLLexer> CreateAPDLLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<APDLLexer>(editor);
	}
	class BashLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("bash");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int ERROR = 1;
			static const int COMMENTLINE = 2;
			static const int NUMBER = 3;
			static const int WORD = 4;
			static const int STRING = 5;
			static const int CHARACTER = 6;
			static const int OPERATOR = 7;
			static const int IDENTIFIER = 8;
			static const int SCALAR = 9;
			static const int PARAM = 10;
			static const int BACKTICKS = 11;
			static const int HERE_DELIM = 12;
			static const int HERE_Q = 13;
			BashLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<BashLexer> CreateBashLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<BashLexer>(editor);
	}
	class Asn1Lexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("asn1");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int IDENTIFIER = 2;
			static const int STRING = 3;
			static const int OID = 4;
			static const int SCALAR = 5;
			static const int KEYWORD = 6;
			static const int ATTRIBUTE = 7;
			static const int DESCRIPTOR = 8;
			static const int TYPE = 9;
			static const int OPERATOR = 10;
			Asn1Lexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<Asn1Lexer> CreateAsn1Lexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<Asn1Lexer>(editor);
	}
	class VHDLLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("vhdl");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINEBANG = 2;
			static const int NUMBER = 3;
			static const int STRING = 4;
			static const int OPERATOR = 5;
			static const int IDENTIFIER = 6;
			static const int STRINGEOL = 7;
			static const int KEYWORD = 8;
			static const int STDOPERATOR = 9;
			static const int ATTRIBUTE = 10;
			static const int STDFUNCTION = 11;
			static const int STDPACKAGE = 12;
			static const int STDTYPE = 13;
			static const int USERWORD = 14;
			static const int BLOCK_COMMENT = 15;
			VHDLLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<VHDLLexer> CreateVHDLLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<VHDLLexer>(editor);
	}
	class CamlLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("caml");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int IDENTIFIER = 1;
			static const int TAGNAME = 2;
			static const int KEYWORD = 3;
			static const int KEYWORD2 = 4;
			static const int KEYWORD3 = 5;
			static const int LINENUM = 6;
			static const int OPERATOR = 7;
			static const int NUMBER = 8;
			static const int CHAR = 9;
			static const int WHITE = 10;
			static const int STRING = 11;
			static const int COMMENT = 12;
			static const int COMMENT1 = 13;
			static const int COMMENT2 = 14;
			static const int COMMENT3 = 15;
			CamlLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<CamlLexer> CreateCamlLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<CamlLexer>(editor);
	}
	class HaskellLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("haskell");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int IDENTIFIER = 1;
			static const int KEYWORD = 2;
			static const int NUMBER = 3;
			static const int STRING = 4;
			static const int CHARACTER = 5;
			static const int CLASS = 6;
			static const int MODULE = 7;
			static const int CAPITAL = 8;
			static const int DATA = 9;
			static const int IMPORT = 10;
			static const int OPERATOR = 11;
			static const int INSTANCE = 12;
			static const int COMMENTLINE = 13;
			static const int COMMENTBLOCK = 14;
			static const int COMMENTBLOCK2 = 15;
			static const int COMMENTBLOCK3 = 16;
			static const int PRAGMA = 17;
			static const int PREPROCESSOR = 18;
			static const int STRINGEOL = 19;
			static const int RESERVED_OPERATOR = 20;
			static const int LITERATE_COMMENT = 21;
			static const int LITERATE_CODEDELIM = 22;
			HaskellLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<HaskellLexer> CreateHaskellLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<HaskellLexer>(editor);
	}
	class TADS3Lexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("tads3");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int X_DEFAULT = 1;
			static const int PREPROCESSOR = 2;
			static const int BLOCK_COMMENT = 3;
			static const int LINE_COMMENT = 4;
			static const int OPERATOR = 5;
			static const int KEYWORD = 6;
			static const int NUMBER = 7;
			static const int IDENTIFIER = 8;
			static const int S_STRING = 9;
			static const int D_STRING = 10;
			static const int X_STRING = 11;
			static const int LIB_DIRECTIVE = 12;
			static const int MSG_PARAM = 13;
			static const int HTML_TAG = 14;
			static const int HTML_DEFAULT = 15;
			static const int HTML_STRING = 16;
			static const int USER1 = 17;
			static const int USER2 = 18;
			static const int USER3 = 19;
			static const int BRACE = 20;
			TADS3Lexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<TADS3Lexer> CreateTADS3Lexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<TADS3Lexer>(editor);
	}
	class RebolLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("rebol");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENTLINE = 1;
			static const int COMMENTBLOCK = 2;
			static const int PREFACE = 3;
			static const int OPERATOR = 4;
			static const int CHARACTER = 5;
			static const int QUOTEDSTRING = 6;
			static const int BRACEDSTRING = 7;
			static const int NUMBER = 8;
			static const int PAIR = 9;
			static const int TUPLE = 10;
			static const int BINARY = 11;
			static const int MONEY = 12;
			static const int ISSUE = 13;
			static const int TAG = 14;
			static const int FILE = 15;
			static const int EMAIL = 16;
			static const int URL = 17;
			static const int DATE = 18;
			static const int TIME = 19;
			static const int IDENTIFIER = 20;
			static const int WORD = 21;
			static const int WORD2 = 22;
			static const int WORD3 = 23;
			static const int WORD4 = 24;
			static const int WORD5 = 25;
			static const int WORD6 = 26;
			static const int WORD7 = 27;
			static const int WORD8 = 28;
			RebolLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<RebolLexer> CreateRebolLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<RebolLexer>(editor);
	}
	class SQLLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("sql");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTDOC = 3;
			static const int NUMBER = 4;
			static const int WORD = 5;
			static const int STRING = 6;
			static const int CHARACTER = 7;
			static const int SQLPLUS = 8;
			static const int SQLPLUS_PROMPT = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int SQLPLUS_COMMENT = 13;
			static const int COMMENTLINEDOC = 15;
			static const int WORD2 = 16;
			static const int COMMENTDOCKEYWORD = 17;
			static const int COMMENTDOCKEYWORDERROR = 18;
			static const int USER1 = 19;
			static const int USER2 = 20;
			static const int USER3 = 21;
			static const int USER4 = 22;
			static const int QUOTEDIDENTIFIER = 23;
			static const int QOPERATOR = 24;
			SQLLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<SQLLexer> CreateSQLLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<SQLLexer>(editor);
	}
	class SmalltalkLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("smalltalk");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int STRING = 1;
			static const int NUMBER = 2;
			static const int COMMENT = 3;
			static const int SYMBOL = 4;
			static const int BINARY = 5;
			static const int BOOL = 6;
			static const int SELF = 7;
			static const int SUPER = 8;
			static const int NIL = 9;
			static const int GLOBAL = 10;
			static const int RETURN = 11;
			static const int SPECIAL = 12;
			static const int KWSEND = 13;
			static const int ASSIGN = 14;
			static const int CHARACTER = 15;
			static const int SPEC_SEL = 16;
			SmalltalkLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<SmalltalkLexer> CreateSmalltalkLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<SmalltalkLexer>(editor);
	}
	class FlagShipLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("flagship");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTDOC = 3;
			static const int COMMENTLINEDOC = 4;
			static const int COMMENTDOCKEYWORD = 5;
			static const int COMMENTDOCKEYWORDERROR = 6;
			static const int KEYWORD = 7;
			static const int KEYWORD2 = 8;
			static const int KEYWORD3 = 9;
			static const int KEYWORD4 = 10;
			static const int NUMBER = 11;
			static const int STRING = 12;
			static const int PREPROCESSOR = 13;
			static const int OPERATOR = 14;
			static const int IDENTIFIER = 15;
			static const int DATE = 16;
			static const int STRINGEOL = 17;
			static const int CONSTANT = 18;
			static const int WORDOPERATOR = 19;
			static const int DISABLEDCODE = 20;
			static const int DEFAULT_C = 21;
			static const int COMMENTDOC_C = 22;
			static const int COMMENTLINEDOC_C = 23;
			static const int KEYWORD_C = 24;
			static const int KEYWORD2_C = 25;
			static const int NUMBER_C = 26;
			static const int STRING_C = 27;
			static const int PREPROCESSOR_C = 28;
			static const int OPERATOR_C = 29;
			static const int IDENTIFIER_C = 30;
			static const int STRINGEOL_C = 31;
			FlagShipLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<FlagShipLexer> CreateFlagShipLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<FlagShipLexer>(editor);
	}
	class CsoundLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("csound");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int OPERATOR = 3;
			static const int INSTR = 4;
			static const int IDENTIFIER = 5;
			static const int OPCODE = 6;
			static const int HEADERSTMT = 7;
			static const int USERKEYWORD = 8;
			static const int COMMENTBLOCK = 9;
			static const int PARAM = 10;
			static const int ARATE_VAR = 11;
			static const int KRATE_VAR = 12;
			static const int IRATE_VAR = 13;
			static const int GLOBAL_VAR = 14;
			static const int STRINGEOL = 15;
			CsoundLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<CsoundLexer> CreateCsoundLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<CsoundLexer>(editor);
	}
	class InnoLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("inno");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int KEYWORD = 2;
			static const int PARAMETER = 3;
			static const int SECTION = 4;
			static const int PREPROC = 5;
			static const int INLINE_EXPANSION = 6;
			static const int COMMENT_PASCAL = 7;
			static const int KEYWORD_PASCAL = 8;
			static const int KEYWORD_USER = 9;
			static const int STRING_DOUBLE = 10;
			static const int STRING_SINGLE = 11;
			static const int IDENTIFIER = 12;
			InnoLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<InnoLexer> CreateInnoLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<InnoLexer>(editor);
	}
	class OpalLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("opal");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int SPACE = 0;
			static const int COMMENT_BLOCK = 1;
			static const int COMMENT_LINE = 2;
			static const int INTEGER = 3;
			static const int KEYWORD = 4;
			static const int SORT = 5;
			static const int STRING = 6;
			static const int PAR = 7;
			static const int BOOL_CONST = 8;
			static const int DEFAULT = 32;
			OpalLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<OpalLexer> CreateOpalLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<OpalLexer>(editor);
	}
	class SpiceLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("spice");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int IDENTIFIER = 1;
			static const int KEYWORD = 2;
			static const int KEYWORD2 = 3;
			static const int KEYWORD3 = 4;
			static const int NUMBER = 5;
			static const int DELIMITER = 6;
			static const int VALUE = 7;
			static const int COMMENTLINE = 8;
			SpiceLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<SpiceLexer> CreateSpiceLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<SpiceLexer>(editor);
	}
	class CMAKELexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("cmake");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int STRINGDQ = 2;
			static const int STRINGLQ = 3;
			static const int STRINGRQ = 4;
			static const int COMMANDS = 5;
			static const int PARAMETERS = 6;
			static const int VARIABLE = 7;
			static const int USERDEFINED = 8;
			static const int WHILEDEF = 9;
			static const int FOREACHDEF = 10;
			static const int IFDEFINEDEF = 11;
			static const int MACRODEF = 12;
			static const int STRINGVAR = 13;
			static const int NUMBER = 14;
			CMAKELexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<CMAKELexer> CreateCMAKELexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<CMAKELexer>(editor);
	}
	class GapLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("gap");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int IDENTIFIER = 1;
			static const int KEYWORD = 2;
			static const int KEYWORD2 = 3;
			static const int KEYWORD3 = 4;
			static const int KEYWORD4 = 5;
			static const int STRING = 6;
			static const int CHAR = 7;
			static const int OPERATOR = 8;
			static const int COMMENT = 9;
			static const int NUMBER = 10;
			static const int STRINGEOL = 11;
			GapLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<GapLexer> CreateGapLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<GapLexer>(editor);
	}
	class PLMLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("plm");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int STRING = 2;
			static const int NUMBER = 3;
			static const int IDENTIFIER = 4;
			static const int OPERATOR = 5;
			static const int CONTROL = 6;
			static const int KEYWORD = 7;
			PLMLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<PLMLexer> CreatePLMLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<PLMLexer>(editor);
	}
	class ProgressLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("progress");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int NUMBER = 1;
			static const int WORD = 2;
			static const int STRING = 3;
			static const int CHARACTER = 4;
			static const int PREPROCESSOR = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int BLOCK = 8;
			static const int END = 9;
			static const int COMMENT = 10;
			static const int TASKMARKER = 11;
			static const int LINECOMMENT = 12;
			ProgressLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<ProgressLexer> CreateProgressLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<ProgressLexer>(editor);
	}
	class ABAQUSLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("abaqus");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTBLOCK = 2;
			static const int NUMBER = 3;
			static const int STRING = 4;
			static const int OPERATOR = 5;
			static const int WORD = 6;
			static const int PROCESSOR = 7;
			static const int COMMAND = 8;
			static const int SLASHCOMMAND = 9;
			static const int STARCOMMAND = 10;
			static const int ARGUMENT = 11;
			static const int FUNCTION = 12;
			ABAQUSLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<ABAQUSLexer> CreateABAQUSLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<ABAQUSLexer>(editor);
	}
	class AsymptoteLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("asymptote");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int NUMBER = 3;
			static const int WORD = 4;
			static const int STRING = 5;
			static const int CHARACTER = 6;
			static const int OPERATOR = 7;
			static const int IDENTIFIER = 8;
			static const int STRINGEOL = 9;
			static const int COMMENTLINEDOC = 10;
			static const int WORD2 = 11;
			AsymptoteLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<AsymptoteLexer> CreateAsymptoteLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<AsymptoteLexer>(editor);
	}
	class RLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("r");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int KWORD = 2;
			static const int BASEKWORD = 3;
			static const int OTHERKWORD = 4;
			static const int NUMBER = 5;
			static const int STRING = 6;
			static const int STRING2 = 7;
			static const int OPERATOR = 8;
			static const int IDENTIFIER = 9;
			static const int INFIX = 10;
			static const int INFIXEOL = 11;
			RLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<RLexer> CreateRLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<RLexer>(editor);
	}
	class MagikSFLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("magiksf");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int HYPER_COMMENT = 16;
			static const int STRING = 2;
			static const int CHARACTER = 3;
			static const int NUMBER = 4;
			static const int IDENTIFIER = 5;
			static const int OPERATOR = 6;
			static const int FLOW = 7;
			static const int CONTAINER = 8;
			static const int BRACKET_BLOCK = 9;
			static const int BRACE_BLOCK = 10;
			static const int SQBRACKET_BLOCK = 11;
			static const int UNKNOWN_KEYWORD = 12;
			static const int KEYWORD = 13;
			static const int PRAGMA = 14;
			static const int SYMBOL = 15;
			MagikSFLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<MagikSFLexer> CreateMagikSFLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<MagikSFLexer>(editor);
	}
	class PowerShellLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("powershell");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int STRING = 2;
			static const int CHARACTER = 3;
			static const int NUMBER = 4;
			static const int VARIABLE = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int KEYWORD = 8;
			static const int CMDLET = 9;
			static const int ALIAS = 10;
			static const int FUNCTION = 11;
			static const int USER1 = 12;
			static const int COMMENTSTREAM = 13;
			static const int HERE_STRING = 14;
			static const int HERE_CHARACTER = 15;
			static const int COMMENTDOCKEYWORD = 16;
			PowerShellLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<PowerShellLexer> CreatePowerShellLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<PowerShellLexer>(editor);
	}
	class MySQLLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("mysql");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int VARIABLE = 3;
			static const int SYSTEMVARIABLE = 4;
			static const int KNOWNSYSTEMVARIABLE = 5;
			static const int NUMBER = 6;
			static const int MAJORKEYWORD = 7;
			static const int KEYWORD = 8;
			static const int DATABASEOBJECT = 9;
			static const int PROCEDUREKEYWORD = 10;
			static const int STRING = 11;
			static const int SQSTRING = 12;
			static const int DQSTRING = 13;
			static const int OPERATOR = 14;
			static const int FUNCTION = 15;
			static const int IDENTIFIER = 16;
			static const int QUOTEDIDENTIFIER = 17;
			static const int USER1 = 18;
			static const int USER2 = 19;
			static const int USER3 = 20;
			static const int HIDDENCOMMAND = 21;
			static const int PLACEHOLDER = 22;
			MySQLLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<MySQLLexer> CreateMySQLLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<MySQLLexer>(editor);
	}
	class PoLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("po");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int MSGID = 2;
			static const int MSGID_TEXT = 3;
			static const int MSGSTR = 4;
			static const int MSGSTR_TEXT = 5;
			static const int MSGCTXT = 6;
			static const int MSGCTXT_TEXT = 7;
			static const int FUZZY = 8;
			static const int PROGRAMMER_COMMENT = 9;
			static const int REFERENCE = 10;
			static const int FLAGS = 11;
			static const int MSGID_TEXT_EOL = 12;
			static const int MSGSTR_TEXT_EOL = 13;
			static const int MSGCTXT_TEXT_EOL = 14;
			static const int ERROR = 15;
			PoLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<PoLexer> CreatePoLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<PoLexer>(editor);
	}
	class PascalLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("pascal");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int IDENTIFIER = 1;
			static const int COMMENT = 2;
			static const int COMMENT2 = 3;
			static const int COMMENTLINE = 4;
			static const int PREPROCESSOR = 5;
			static const int PREPROCESSOR2 = 6;
			static const int NUMBER = 7;
			static const int HEXNUMBER = 8;
			static const int WORD = 9;
			static const int STRING = 10;
			static const int STRINGEOL = 11;
			static const int CHARACTER = 12;
			static const int OPERATOR = 13;
			static const int ASM = 14;
			PascalLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<PascalLexer> CreatePascalLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<PascalLexer>(editor);
	}
	class SORCUSLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("sorcus");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMAND = 1;
			static const int PARAMETER = 2;
			static const int COMMENTLINE = 3;
			static const int STRING = 4;
			static const int STRINGEOL = 5;
			static const int IDENTIFIER = 6;
			static const int OPERATOR = 7;
			static const int NUMBER = 8;
			static const int CONSTANT = 9;
			SORCUSLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<SORCUSLexer> CreateSORCUSLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<SORCUSLexer>(editor);
	}
	class PowerProLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("powerpro");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENTBLOCK = 1;
			static const int COMMENTLINE = 2;
			static const int NUMBER = 3;
			static const int WORD = 4;
			static const int WORD2 = 5;
			static const int WORD3 = 6;
			static const int WORD4 = 7;
			static const int DOUBLEQUOTEDSTRING = 8;
			static const int SINGLEQUOTEDSTRING = 9;
			static const int LINECONTINUE = 10;
			static const int OPERATOR = 11;
			static const int IDENTIFIER = 12;
			static const int STRINGEOL = 13;
			static const int VERBATIM = 14;
			static const int ALTQUOTE = 15;
			static const int FUNCTION = 16;
			PowerProLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<PowerProLexer> CreatePowerProLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<PowerProLexer>(editor);
	}
	class SMLLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("sml");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int IDENTIFIER = 1;
			static const int TAGNAME = 2;
			static const int KEYWORD = 3;
			static const int KEYWORD2 = 4;
			static const int KEYWORD3 = 5;
			static const int LINENUM = 6;
			static const int OPERATOR = 7;
			static const int NUMBER = 8;
			static const int CHAR = 9;
			static const int STRING = 11;
			static const int COMMENT = 12;
			static const int COMMENT1 = 13;
			static const int COMMENT2 = 14;
			static const int COMMENT3 = 15;
			SMLLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<SMLLexer> CreateSMLLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<SMLLexer>(editor);
	}
	class MarkdownLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("markdown");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int LINE_BEGIN = 1;
			static const int STRONG1 = 2;
			static const int STRONG2 = 3;
			static const int EM1 = 4;
			static const int EM2 = 5;
			static const int HEADER1 = 6;
			static const int HEADER2 = 7;
			static const int HEADER3 = 8;
			static const int HEADER4 = 9;
			static const int HEADER5 = 10;
			static const int HEADER6 = 11;
			static const int PRECHAR = 12;
			static const int ULIST_ITEM = 13;
			static const int OLIST_ITEM = 14;
			static const int BLOCKQUOTE = 15;
			static const int STRIKEOUT = 16;
			static const int HRULE = 17;
			static const int LINK = 18;
			static const int CODE = 19;
			static const int CODE2 = 20;
			static const int CODEBK = 21;
			MarkdownLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<MarkdownLexer> CreateMarkdownLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<MarkdownLexer>(editor);
	}
	class Txt2tagsLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("txt2tags");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int LINE_BEGIN = 1;
			static const int STRONG1 = 2;
			static const int STRONG2 = 3;
			static const int EM1 = 4;
			static const int EM2 = 5;
			static const int HEADER1 = 6;
			static const int HEADER2 = 7;
			static const int HEADER3 = 8;
			static const int HEADER4 = 9;
			static const int HEADER5 = 10;
			static const int HEADER6 = 11;
			static const int PRECHAR = 12;
			static const int ULIST_ITEM = 13;
			static const int OLIST_ITEM = 14;
			static const int BLOCKQUOTE = 15;
			static const int STRIKEOUT = 16;
			static const int HRULE = 17;
			static const int LINK = 18;
			static const int CODE = 19;
			static const int CODE2 = 20;
			static const int CODEBK = 21;
			static const int COMMENT = 22;
			static const int OPTION = 23;
			static const int PREPROC = 24;
			static const int POSTPROC = 25;
			Txt2tagsLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<Txt2tagsLexer> CreateTxt2tagsLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<Txt2tagsLexer>(editor);
	}
	class A68kLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("a68k");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER_DEC = 2;
			static const int NUMBER_BIN = 3;
			static const int NUMBER_HEX = 4;
			static const int STRING1 = 5;
			static const int OPERATOR = 6;
			static const int CPUINSTRUCTION = 7;
			static const int EXTINSTRUCTION = 8;
			static const int REGISTER = 9;
			static const int DIRECTIVE = 10;
			static const int MACRO_ARG = 11;
			static const int LABEL = 12;
			static const int STRING2 = 13;
			static const int IDENTIFIER = 14;
			static const int MACRO_DECLARATION = 15;
			static const int COMMENT_WORD = 16;
			static const int COMMENT_SPECIAL = 17;
			static const int COMMENT_DOXYGEN = 18;
			A68kLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<A68kLexer> CreateA68kLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<A68kLexer>(editor);
	}
	class ModulaLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("modula");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int DOXYCOMM = 2;
			static const int DOXYKEY = 3;
			static const int KEYWORD = 4;
			static const int RESERVED = 5;
			static const int NUMBER = 6;
			static const int BASENUM = 7;
			static const int FLOAT = 8;
			static const int STRING = 9;
			static const int STRSPEC = 10;
			static const int CHAR = 11;
			static const int CHARSPEC = 12;
			static const int PROC = 13;
			static const int PRAGMA = 14;
			static const int PRGKEY = 15;
			static const int OPERATOR = 16;
			static const int BADSTR = 17;
			ModulaLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<ModulaLexer> CreateModulaLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<ModulaLexer>(editor);
	}
	class CoffeeScriptLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("coffeescript");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTDOC = 3;
			static const int NUMBER = 4;
			static const int WORD = 5;
			static const int STRING = 6;
			static const int CHARACTER = 7;
			static const int UUID = 8;
			static const int PREPROCESSOR = 9;
			static const int OPERATOR = 10;
			static const int IDENTIFIER = 11;
			static const int STRINGEOL = 12;
			static const int VERBATIM = 13;
			static const int REGEX = 14;
			static const int COMMENTLINEDOC = 15;
			static const int WORD2 = 16;
			static const int COMMENTDOCKEYWORD = 17;
			static const int COMMENTDOCKEYWORDERROR = 18;
			static const int GLOBALCLASS = 19;
			static const int STRINGRAW = 20;
			static const int TRIPLEVERBATIM = 21;
			static const int COMMENTBLOCK = 22;
			static const int VERBOSE_REGEX = 23;
			static const int VERBOSE_REGEX_COMMENT = 24;
			static const int INSTANCEPROPERTY = 25;
			CoffeeScriptLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<CoffeeScriptLexer> CreateCoffeeScriptLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<CoffeeScriptLexer>(editor);
	}
	class AVSLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("avs");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENTBLOCK = 1;
			static const int COMMENTBLOCKN = 2;
			static const int COMMENTLINE = 3;
			static const int NUMBER = 4;
			static const int OPERATOR = 5;
			static const int IDENTIFIER = 6;
			static const int STRING = 7;
			static const int TRIPLESTRING = 8;
			static const int KEYWORD = 9;
			static const int FILTER = 10;
			static const int PLUGIN = 11;
			static const int FUNCTION = 12;
			static const int CLIPPROP = 13;
			static const int USERDFN = 14;
			AVSLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<AVSLexer> CreateAVSLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<AVSLexer>(editor);
	}
	class ECLLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("ecl");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int NUMBER = 3;
			static const int STRING = 4;
			static const int WORD0 = 5;
			static const int OPERATOR = 6;
			static const int CHARACTER = 7;
			static const int UUID = 8;
			static const int PREPROCESSOR = 9;
			static const int UNKNOWN = 10;
			static const int IDENTIFIER = 11;
			static const int STRINGEOL = 12;
			static const int VERBATIM = 13;
			static const int REGEX = 14;
			static const int COMMENTLINEDOC = 15;
			static const int WORD1 = 16;
			static const int COMMENTDOCKEYWORD = 17;
			static const int COMMENTDOCKEYWORDERROR = 18;
			static const int WORD2 = 19;
			static const int WORD3 = 20;
			static const int WORD4 = 21;
			static const int WORD5 = 22;
			static const int COMMENTDOC = 23;
			static const int ADDED = 24;
			static const int DELETED = 25;
			static const int CHANGED = 26;
			static const int MOVED = 27;
			ECLLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<ECLLexer> CreateECLLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<ECLLexer>(editor);
	}
	class OScriptLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("oscript");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int LINE_COMMENT = 1;
			static const int BLOCK_COMMENT = 2;
			static const int DOC_COMMENT = 3;
			static const int PREPROCESSOR = 4;
			static const int NUMBER = 5;
			static const int SINGLEQUOTE_STRING = 6;
			static const int DOUBLEQUOTE_STRING = 7;
			static const int CONSTANT = 8;
			static const int IDENTIFIER = 9;
			static const int GLOBAL = 10;
			static const int KEYWORD = 11;
			static const int OPERATOR = 12;
			static const int LABEL = 13;
			static const int TYPE = 14;
			static const int FUNCTION = 15;
			static const int OBJECT = 16;
			static const int PROPERTY = 17;
			static const int METHOD = 18;
			OScriptLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<OScriptLexer> CreateOScriptLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<OScriptLexer>(editor);
	}
	class VisualPrologLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("visualprolog");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int KEY_MAJOR = 1;
			static const int KEY_MINOR = 2;
			static const int KEY_DIRECTIVE = 3;
			static const int COMMENT_BLOCK = 4;
			static const int COMMENT_LINE = 5;
			static const int COMMENT_KEY = 6;
			static const int COMMENT_KEY_ERROR = 7;
			static const int IDENTIFIER = 8;
			static const int VARIABLE = 9;
			static const int ANONYMOUS = 10;
			static const int NUMBER = 11;
			static const int OPERATOR = 12;
			static const int CHARACTER = 13;
			static const int CHARACTER_TOO_MANY = 14;
			static const int CHARACTER_ESCAPE_ERROR = 15;
			static const int STRING = 16;
			static const int STRING_ESCAPE = 17;
			static const int STRING_ESCAPE_ERROR = 18;
			static const int STRING_EOL_OPEN = 19;
			static const int STRING_VERBATIM = 20;
			static const int STRING_VERBATIM_SPECIAL = 21;
			static const int STRING_VERBATIM_EOL = 22;
			VisualPrologLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<VisualPrologLexer> CreateVisualPrologLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<VisualPrologLexer>(editor);
	}
	class StructuredTextLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("structuredtext");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int KEYWORD = 3;
			static const int TYPE = 4;
			static const int FUNCTION = 5;
			static const int FB = 6;
			static const int NUMBER = 7;
			static const int HEXNUMBER = 8;
			static const int PRAGMA = 9;
			static const int OPERATOR = 10;
			static const int CHARACTER = 11;
			static const int STRING1 = 12;
			static const int STRING2 = 13;
			static const int STRINGEOL = 14;
			static const int IDENTIFIER = 15;
			static const int DATETIME = 16;
			static const int VARS = 17;
			static const int PRAGMAS = 18;
			StructuredTextLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<StructuredTextLexer> CreateStructuredTextLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<StructuredTextLexer>(editor);
	}
	class KVIrcLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("kvirc");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTBLOCK = 2;
			static const int STRING = 3;
			static const int WORD = 4;
			static const int KEYWORD = 5;
			static const int FUNCTION_KEYWORD = 6;
			static const int FUNCTION = 7;
			static const int VARIABLE = 8;
			static const int NUMBER = 9;
			static const int OPERATOR = 10;
			static const int STRING_FUNCTION = 11;
			static const int STRING_VARIABLE = 12;
			KVIrcLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<KVIrcLexer> CreateKVIrcLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<KVIrcLexer>(editor);
	}
	class RustLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("rust");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENTBLOCK = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTBLOCKDOC = 3;
			static const int COMMENTLINEDOC = 4;
			static const int NUMBER = 5;
			static const int WORD = 6;
			static const int WORD2 = 7;
			static const int WORD3 = 8;
			static const int WORD4 = 9;
			static const int WORD5 = 10;
			static const int WORD6 = 11;
			static const int WORD7 = 12;
			static const int STRING = 13;
			static const int STRINGR = 14;
			static const int CHARACTER = 15;
			static const int OPERATOR = 16;
			static const int IDENTIFIER = 17;
			static const int LIFETIME = 18;
			static const int MACRO = 19;
			static const int LEXERROR = 20;
			static const int BYTESTRING = 21;
			static const int BYTESTRINGR = 22;
			static const int BYTECHARACTER = 23;
			RustLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<RustLexer> CreateRustLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<RustLexer>(editor);
	}
	class DMAPLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("dmap");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int NUMBER = 2;
			static const int STRING1 = 3;
			static const int STRING2 = 4;
			static const int STRINGEOL = 5;
			static const int OPERATOR = 6;
			static const int IDENTIFIER = 7;
			static const int WORD = 8;
			static const int WORD2 = 9;
			static const int WORD3 = 10;
			DMAPLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<DMAPLexer> CreateDMAPLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<DMAPLexer>(editor);
	}
	class DMISLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("dmis");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int STRING = 2;
			static const int NUMBER = 3;
			static const int KEYWORD = 4;
			static const int MAJORWORD = 5;
			static const int MINORWORD = 6;
			static const int UNSUPPORTED_MAJOR = 7;
			static const int UNSUPPORTED_MINOR = 8;
			static const int LABEL = 9;
			DMISLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<DMISLexer> CreateDMISLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<DMISLexer>(editor);
	}
	class REGLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("reg");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int VALUENAME = 2;
			static const int STRING = 3;
			static const int HEXDIGIT = 4;
			static const int VALUETYPE = 5;
			static const int ADDEDKEY = 6;
			static const int DELETEDKEY = 7;
			static const int ESCAPED = 8;
			static const int KEYPATH_GUID = 9;
			static const int STRING_GUID = 10;
			static const int PARAMETER = 11;
			static const int OPERATOR = 12;
			REGLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<REGLexer> CreateREGLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<REGLexer>(editor);
	}
	class BibTeXLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("bibtex");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int ENTRY = 1;
			static const int UNKNOWN_ENTRY = 2;
			static const int KEY = 3;
			static const int PARAMETER = 4;
			static const int VALUE = 5;
			static const int COMMENT = 6;
			BibTeXLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<BibTeXLexer> CreateBibTeXLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<BibTeXLexer>(editor);
	}
	class SrecLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("srec");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int RECSTART = 1;
			static const int RECTYPE = 2;
			static const int RECTYPE_UNKNOWN = 3;
			static const int BYTECOUNT = 4;
			static const int BYTECOUNT_WRONG = 5;
			static const int NOADDRESS = 6;
			static const int DATAADDRESS = 7;
			static const int RECCOUNT = 8;
			static const int STARTADDRESS = 9;
			static const int ADDRESSFIELD_UNKNOWN = 10;
			static const int EXTENDEDADDRESS = 11;
			static const int DATA_ODD = 12;
			static const int DATA_EVEN = 13;
			static const int DATA_UNKNOWN = 14;
			static const int DATA_EMPTY = 15;
			static const int CHECKSUM = 16;
			static const int CHECKSUM_WRONG = 17;
			static const int GARBAGE = 18;
			SrecLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<SrecLexer> CreateSrecLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<SrecLexer>(editor);
	}
	class IHexLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("ihex");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int RECSTART = 1;
			static const int RECTYPE = 2;
			static const int RECTYPE_UNKNOWN = 3;
			static const int BYTECOUNT = 4;
			static const int BYTECOUNT_WRONG = 5;
			static const int NOADDRESS = 6;
			static const int DATAADDRESS = 7;
			static const int RECCOUNT = 8;
			static const int STARTADDRESS = 9;
			static const int ADDRESSFIELD_UNKNOWN = 10;
			static const int EXTENDEDADDRESS = 11;
			static const int DATA_ODD = 12;
			static const int DATA_EVEN = 13;
			static const int DATA_UNKNOWN = 14;
			static const int DATA_EMPTY = 15;
			static const int CHECKSUM = 16;
			static const int CHECKSUM_WRONG = 17;
			static const int GARBAGE = 18;
			IHexLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<IHexLexer> CreateIHexLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<IHexLexer>(editor);
	}
	class TEHexLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("tehex");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int RECSTART = 1;
			static const int RECTYPE = 2;
			static const int RECTYPE_UNKNOWN = 3;
			static const int BYTECOUNT = 4;
			static const int BYTECOUNT_WRONG = 5;
			static const int NOADDRESS = 6;
			static const int DATAADDRESS = 7;
			static const int RECCOUNT = 8;
			static const int STARTADDRESS = 9;
			static const int ADDRESSFIELD_UNKNOWN = 10;
			static const int EXTENDEDADDRESS = 11;
			static const int DATA_ODD = 12;
			static const int DATA_EVEN = 13;
			static const int DATA_UNKNOWN = 14;
			static const int DATA_EMPTY = 15;
			static const int CHECKSUM = 16;
			static const int CHECKSUM_WRONG = 17;
			static const int GARBAGE = 18;
			TEHexLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<TEHexLexer> CreateTEHexLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<TEHexLexer>(editor);
	}
	class JSONLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("json");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int NUMBER = 1;
			static const int STRING = 2;
			static const int STRINGEOL = 3;
			static const int PROPERTYNAME = 4;
			static const int ESCAPESEQUENCE = 5;
			static const int LINECOMMENT = 6;
			static const int BLOCKCOMMENT = 7;
			static const int OPERATOR = 8;
			static const int URI = 9;
			static const int COMPACTIRI = 10;
			static const int KEYWORD = 11;
			static const int LDKEYWORD = 12;
			static const int ERROR = 13;
			JSONLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<JSONLexer> CreateJSONLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<JSONLexer>(editor);
	}
	class EDIFACTLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("edifact");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int SEGMENTSTART = 1;
			static const int SEGMENTEND = 2;
			static const int SEP_ELEMENT = 3;
			static const int SEP_COMPOSITE = 4;
			static const int SEP_RELEASE = 5;
			static const int UNA = 6;
			static const int UNH = 7;
			static const int BADSEGMENT = 8;
			EDIFACTLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<EDIFACTLexer> CreateEDIFACTLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<EDIFACTLexer>(editor);
	}
	class STATALexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("stata");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTBLOCK = 3;
			static const int NUMBER = 4;
			static const int OPERATOR = 5;
			static const int IDENTIFIER = 6;
			static const int STRING = 7;
			static const int TYPE = 8;
			static const int WORD = 9;
			static const int GLOBAL_MACRO = 10;
			static const int MACRO = 11;
			STATALexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<STATALexer> CreateSTATALexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<STATALexer>(editor);
	}
	class SASLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("sas");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTBLOCK = 3;
			static const int NUMBER = 4;
			static const int OPERATOR = 5;
			static const int IDENTIFIER = 6;
			static const int STRING = 7;
			static const int TYPE = 8;
			static const int WORD = 9;
			static const int GLOBAL_MACRO = 10;
			static const int MACRO = 11;
			static const int MACRO_KEYWORD = 12;
			static const int BLOCK_KEYWORD = 13;
			static const int MACRO_FUNCTION = 14;
			static const int STATEMENT = 15;
			SASLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<SASLexer> CreateSASLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<SASLexer>(editor);
	}
	class NimLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("nim");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTDOC = 2;
			static const int COMMENTLINE = 3;
			static const int COMMENTLINEDOC = 4;
			static const int NUMBER = 5;
			static const int STRING = 6;
			static const int CHARACTER = 7;
			static const int WORD = 8;
			static const int TRIPLE = 9;
			static const int TRIPLEDOUBLE = 10;
			static const int BACKTICKS = 11;
			static const int FUNCNAME = 12;
			static const int STRINGEOL = 13;
			static const int NUMERROR = 14;
			static const int OPERATOR = 15;
			static const int IDENTIFIER = 16;
			NimLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<NimLexer> CreateNimLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<NimLexer>(editor);
	}
	class CILLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("cil");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTLINE = 2;
			static const int WORD = 3;
			static const int WORD2 = 4;
			static const int WORD3 = 5;
			static const int STRING = 6;
			static const int LABEL = 7;
			static const int OPERATOR = 8;
			static const int IDENTIFIER = 9;
			static const int STRINGEOL = 10;
			CILLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<CILLexer> CreateCILLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<CILLexer>(editor);
	}
	class X12Lexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("x12");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int BAD = 1;
			static const int ENVELOPE = 2;
			static const int FUNCTIONGROUP = 3;
			static const int TRANSACTIONSET = 4;
			static const int SEGMENTHEADER = 5;
			static const int SEGMENTEND = 6;
			static const int SEP_ELEMENT = 7;
			static const int SEP_SUBELEMENT = 8;
			X12Lexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<X12Lexer> CreateX12Lexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<X12Lexer>(editor);
	}
	class DataflexLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("dataflex");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int IDENTIFIER = 1;
			static const int METATAG = 2;
			static const int IMAGE = 3;
			static const int COMMENTLINE = 4;
			static const int PREPROCESSOR = 5;
			static const int PREPROCESSOR2 = 6;
			static const int NUMBER = 7;
			static const int HEXNUMBER = 8;
			static const int WORD = 9;
			static const int STRING = 10;
			static const int STRINGEOL = 11;
			static const int SCOPEWORD = 12;
			static const int OPERATOR = 13;
			static const int ICODE = 14;
			DataflexLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<DataflexLexer> CreateDataflexLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<DataflexLexer>(editor);
	}
	class HollywoodLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("hollywood");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int COMMENT = 1;
			static const int COMMENTBLOCK = 2;
			static const int NUMBER = 3;
			static const int KEYWORD = 4;
			static const int STDAPI = 5;
			static const int PLUGINAPI = 6;
			static const int PLUGINMETHOD = 7;
			static const int STRING = 8;
			static const int STRINGBLOCK = 9;
			static const int PREPROCESSOR = 10;
			static const int OPERATOR = 11;
			static const int IDENTIFIER = 12;
			static const int CONSTANT = 13;
			static const int HEXNUMBER = 14;
			HollywoodLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<HollywoodLexer> CreateHollywoodLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<HollywoodLexer>(editor);
	}
	class RakuLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("raku");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int ERROR = 1;
			static const int COMMENTLINE = 2;
			static const int COMMENTEMBED = 3;
			static const int POD = 4;
			static const int CHARACTER = 5;
			static const int HEREDOC_Q = 6;
			static const int HEREDOC_QQ = 7;
			static const int STRING = 8;
			static const int STRING_Q = 9;
			static const int STRING_QQ = 10;
			static const int STRING_Q_LANG = 11;
			static const int STRING_VAR = 12;
			static const int REGEX = 13;
			static const int REGEX_VAR = 14;
			static const int ADVERB = 15;
			static const int NUMBER = 16;
			static const int PREPROCESSOR = 17;
			static const int OPERATOR = 18;
			static const int WORD = 19;
			static const int FUNCTION = 20;
			static const int IDENTIFIER = 21;
			static const int TYPEDEF = 22;
			static const int MU = 23;
			static const int POSITIONAL = 24;
			static const int ASSOCIATIVE = 25;
			static const int CALLABLE = 26;
			static const int GRAMMAR = 27;
			static const int CLASS = 28;
			RakuLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<RakuLexer> CreateRakuLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<RakuLexer>(editor);
	}
	class FSharpLexer : public BaseLexer
	{
		private:
			void InitLexer()
			{
				_lexer = CreateLexer("fsharp");
				_editor->GetCall()->SetILexer(_lexer);
			}
		public:
			static const int DEFAULT = 0;
			static const int KEYWORD = 1;
			static const int KEYWORD2 = 2;
			static const int KEYWORD3 = 3;
			static const int KEYWORD4 = 4;
			static const int KEYWORD5 = 5;
			static const int IDENTIFIER = 6;
			static const int QUOT_IDENTIFIER = 7;
			static const int COMMENT = 8;
			static const int COMMENTLINE = 9;
			static const int PREPROCESSOR = 10;
			static const int LINENUM = 11;
			static const int OPERATOR = 12;
			static const int NUMBER = 13;
			static const int CHARACTER = 14;
			static const int STRING = 15;
			static const int VERBATIM = 16;
			static const int QUOTATION = 17;
			static const int ATTRIBUTE = 18;
			static const int FORMAT_SPEC = 19;
			FSharpLexer(shared_ptr<SyntaxEditor> editor) : BaseLexer(editor)
			{
				InitLexer();
			}
	};

	inline shared_ptr<FSharpLexer> CreateFSharpLexer(shared_ptr<SyntaxEditor> editor)
	{
		return make_shared<FSharpLexer>(editor);
	}
}
