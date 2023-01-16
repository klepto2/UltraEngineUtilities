#pragma once

namespace SyntaxEditorEnums
{
	enum class WhiteSpace
	{
		Invisible = 0,
		VisibleAlways = 1,
		VisibleAfterIndent = 2,
		VisibleOnlyInIndent = 3,
	};

	enum class TabDrawMode
	{
		LongArrow = 0,
		StrikeOut = 1,
	};

	enum class EndOfLine
	{
		CrLf = 0,
		Cr = 1,
		Lf = 2,
	};

	enum class IMEInteraction
	{
		Windowed = 0,
		Inline = 1,
	};

	enum class Alpha
	{
		Transparent = 0,
		Opaque = 255,
		NoAlpha = 256,
	};

	enum class CursorShape
	{
		Normal = -1,
		Arrow = 2,
		Wait = 4,
		ReverseArrow = 7,
	};

	enum class MarkerSymbol
	{
		Circle = 0,
		RoundRect = 1,
		Arrow = 2,
		SmallRect = 3,
		ShortArrow = 4,
		Empty = 5,
		ArrowDown = 6,
		Minus = 7,
		Plus = 8,
		// Shapes used for outlining column.
		VLine = 9,
		LCorner = 10,
		TCorner = 11,
		BoxPlus = 12,
		BoxPlusConnected = 13,
		BoxMinus = 14,
		BoxMinusConnected = 15,
		LCornerCurve = 16,
		TCornerCurve = 17,
		CirclePlus = 18,
		CirclePlusConnected = 19,
		CircleMinus = 20,
		CircleMinusConnected = 21,
		// Invisible mark that only sets the line background colour.
		Background = 22,
		DotDotDot = 23,
		Arrows = 24,
		Pixmap = 25,
		FullRect = 26,
		LeftRect = 27,
		Available = 28,
		Underline = 29,
		RgbaImage = 30,
		Bookmark = 31,
		VerticalBookmark = 32,
		Character = 10000,
	};

	enum class MarkerOutline
	{
		// Markers used for outlining column.
		FolderEnd = 25,
		FolderOpenMid = 26,
		FolderMidTail = 27,
		FolderTail = 28,
		FolderSub = 29,
		Folder = 30,
		FolderOpen = 31,
	};

	enum class MarginType
	{
		Symbol = 0,
		Number = 1,
		Back = 2,
		Fore = 3,
		Text = 4,
		RText = 5,
		Colour = 6,
	};

	// Styles in range 32..39 are predefined for parts of the UI and are not used as normal styles.
	enum class StylesCommon
	{
		Default = 32,
		LineNumber = 33,
		BraceLight = 34,
		BraceBad = 35,
		ControlChar = 36,
		IndentGuide = 37,
		CallTip = 38,
		FoldDisplayText = 39,
		LastPredefined = 39,
		Max = 255,
	};

	// Character set identifiers are used in StyleSetCharacterSet.
	// The values are the same as the Windows *_CHARSET values.
	enum class CharacterSet
	{
		Ansi = 0,
		Default = 1,
		Baltic = 186,
		ChineseBig5 = 136,
		EastEurope = 238,
		GB2312 = 134,
		Greek = 161,
		Hangul = 129,
		Mac = 77,
		Oem = 255,
		Russian = 204,
		Oem866 = 866,
		Cyrillic = 1251,
		ShiftJis = 128,
		Symbol = 2,
		Turkish = 162,
		Johab = 130,
		Hebrew = 177,
		Arabic = 178,
		Vietnamese = 163,
		Thai = 222,
		Iso885915 = 1000,
	};

	enum class CaseVisible
	{
		Mixed = 0,
		Upper = 1,
		Lower = 2,
		Camel = 3,
	};

	enum class FontWeight
	{
		Normal = 400,
		SemiBold = 600,
		Bold = 700,
	};

	enum class Element
	{
		List = 0,
		ListBack = 1,
		ListSelected = 2,
		ListSelectedBack = 3,
	};

	// Indicator style enumeration and some constants
	enum class IndicatorStyle
	{
		Plain = 0,
		Squiggle = 1,
		TT = 2,
		Diagonal = 3,
		Strike = 4,
		Hidden = 5,
		Box = 6,
		RoundBox = 7,
		StraightBox = 8,
		Dash = 9,
		Dots = 10,
		SquiggleLow = 11,
		DotBox = 12,
		SquigglePixmap = 13,
		CompositionThick = 14,
		CompositionThin = 15,
		FullBox = 16,
		TextFore = 17,
		Point = 18,
		PointCharacter = 19,
		Gradient = 20,
		GradientCentre = 21,
		// INDIC_CONTAINER, INDIC_IME, INDIC_IME_MAX, and INDIC_MAX are indicator numbers,
		// not IndicatorStyles so should not really be in the INDIC_ enumeration.
		// They are redeclared in IndicatorNumbers INDICATOR_.
		Container = 8,
		Ime = 32,
		ImeMax = 35,
		Max = 35,
	};

	enum class IndicatorNumbers
	{
		Container = 8,
		Ime = 32,
		ImeMax = 35,
		Max = 35,
	};

	enum class IndicValue
	{
		Bit = 0x1000000,
		Mask = 0xFFFFFF,
	};

	enum class IndicFlag
	{
		ValueFore = 1,
	};

	enum class IndentView
	{
		None = 0,
		Real = 1,
		LookForward = 2,
		LookBoth = 3,
	};

	enum class PrintOption
	{
		// PrintColourMode - use same colours as screen.
		// with the exception of line number margins, which use a white background
		Normal = 0,
		// PrintColourMode - invert the light value of each style for printing.
		InvertLight = 1,
		// PrintColourMode - force black text on white background for printing.
		BlackOnWhite = 2,
		// PrintColourMode - text stays coloured, but all background is forced to be white for printing.
		ColourOnWhite = 3,
		// PrintColourMode - only the default-background is forced to be white for printing.
		ColourOnWhiteDefaultBG = 4,
		// PrintColourMode - use same colours as screen, including line number margins.
		ScreenColours = 5,
	};

	enum class FindOption
	{
		None = 0x0,
		WholeWord = 0x2,
		MatchCase = 0x4,
		WordStart = 0x00100000,
		RegExp = 0x00200000,
		Posix = 0x00400000,
		Cxx11RegEx = 0x00800000,
	};

	enum class FoldLevel
	{
		Base = 0x400,
		WhiteFlag = 0x1000,
		HeaderFlag = 0x2000,
		NumberMask = 0x0FFF,
	};

	enum class FoldDisplayTextStyle
	{
		Hidden = 0,
		Standard = 1,
		Boxed = 2,
	};

	enum class FoldAction
	{
		Contract = 0,
		Expand = 1,
		Toggle = 2,
	};

	enum class AutomaticFold
	{
		Show = 0x0001,
		Click = 0x0002,
		Change = 0x0004,
	};

	enum class FoldFlag
	{
		LineBeforeExpanded = 0x0002,
		LineBeforeContracted = 0x0004,
		LineAfterExpanded = 0x0008,
		LineAfterContracted = 0x0010,
		LevelNumbers = 0x0040,
		LineState = 0x0080,
	};

	enum class IdleStyling
	{
		None = 0,
		ToVisible = 1,
		AfterVisible = 2,
		All = 3,
	};

	enum class Wrap
	{
		None = 0,
		Word = 1,
		Char = 2,
		WhiteSpace = 3,
	};

	enum class WrapVisualFlag
	{
		None = 0x0000,
		End = 0x0001,
		Start = 0x0002,
		Margin = 0x0004,
	};

	enum class WrapVisualLocation
	{
		Default = 0x0000,
		EndByText = 0x0001,
		StartByText = 0x0002,
	};

	enum class WrapIndentMode
	{
		Fixed = 0,
		Same = 1,
		Indent = 2,
		DeepIndent = 3,
	};

	enum class LineCache
	{
		None = 0,
		Caret = 1,
		Page = 2,
		Document = 3,
	};

	enum class PhasesDraw
	{
		One = 0,
		Two = 1,
		Multiple = 2,
	};

	// Control font anti-aliasing.
	enum class FontQuality
	{
		QualityMask = 0xF,
		QualityDefault = 0,
		QualityNonAntialiased = 1,
		QualityAntialiased = 2,
		QualityLcdOptimized = 3,
	};

	enum class MultiPaste
	{
		Once = 0,
		Each = 1,
	};

	enum class Accessibility
	{
		Disabled = 0,
		Enabled = 1,
	};

	enum class EdgeVisualStyle
	{
		None = 0,
		Line = 1,
		Background = 2,
		MultiLine = 3,
	};

	enum class PopUp
	{
		Never = 0,
		All = 1,
		Text = 2,
	};

	enum class DocumentOption
	{
		Default = 0,
		StylesNone = 0x1,
		TextLarge = 0x100,
	};

	enum class Status
	{
		Ok = 0,
		Failure = 1,
		BadAlloc = 2,
		WarnStart = 1000,
		RegEx = 1001,
	};

	// Constants for use with SetVisiblePolicy, similar to SetCaretPolicy.
	enum class VisiblePolicy
	{
		Slop = 0x01,
		Strict = 0x04,
	};

	enum class CaretPolicy
	{
		// Caret policy, used by SetXCaretPolicy and SetYCaretPolicy.
		// If CARET_SLOP is set, we can define a slop value: caretSlop.
		// This value defines an unwanted zone (UZ) where the caret is... unwanted.
		// This zone is defined as a number of pixels near the vertical margins,
		// and as a number of lines near the horizontal margins.
		// By keeping the caret away from the edges, it is seen within its context,
		// so it is likely that the identifier that the caret is on can be completely seen,
		// and that the current line is seen with some of the lines following it which are
		// often dependent on that line.
		Slop = 0x01,
		// If CARET_STRICT is set, the policy is enforced... strictly.
		// The caret is centred on the display if slop is not set,
		// and cannot go in the UZ if slop is set.
		Strict = 0x04,
		// If CARET_JUMPS is set, the display is moved more energetically
		// so the caret can move in the same direction longer before the policy is applied again.
		Jumps = 0x10,
		// If CARET_EVEN is not set, instead of having symmetrical UZs,
		// the left and bottom UZs are extended up to right and top UZs respectively.
		// This way, we favour the displaying of useful information: the beginning of lines,
		// where most code reside, and the lines after the caret, eg. the body of a function.
		Even = 0x08,
	};

	enum class SelectionMode
	{
		Stream = 0,
		Rectangle = 1,
		Lines = 2,
		Thin = 3,
	};

	enum class CaseInsensitiveBehaviour
	{
		RespectCase = 0,
		IgnoreCase = 1,
	};

	enum class MultiAutoComplete
	{
		Once = 0,
		Each = 1,
	};

	enum class Ordering
	{
		PreSorted = 0,
		PerformSort = 1,
		Custom = 2,
	};

	enum class CaretSticky
	{
		Off = 0,
		On = 1,
		WhiteSpace = 2,
	};

	enum class CaretStyle
	{
		Invisible = 0,
		Line = 1,
		Block = 2,
		OverstrikeBar = 0,
		OverstrikeBlock = 0x10,
		InsMask = 0xF,
		BlockAfter = 0x100,
	};

	enum class MarginOption
	{
		None = 0,
		SubLineSelect = 1,
	};

	enum class AnnotationVisible
	{
		Hidden = 0,
		Standard = 1,
		Boxed = 2,
		Indented = 3,
	};

	enum class UndoFlags
	{
		None = 0,
		MayCoalesce = 1,
	};

	enum class VirtualSpace
	{
		None = 0,
		RectangularSelection = 1,
		UserAccessible = 2,
		NoWrapLineStart = 4,
	};

	enum class Technology
	{
		Default = 0,
		DirectWrite = 1,
		DirectWriteRetain = 2,
		DirectWriteDC = 3,
	};

	// Line end types which may be used in addition to LF, CR, and CRLF
	// SC_LINE_END_TYPE_UNICODE includes U+2028 Line Separator,
	// U+2029 Paragraph Separator, and U+0085 Next Line
	enum class LineEndType
	{
		Default = 0,
		Unicode = 1,
	};

	enum class EOLAnnotationVisible
	{
		Hidden = 0x0,
		Standard = 0x1,
		Boxed = 0x2,
		Stadium = 0x100,
		FlatCircle = 0x101,
		AngleCircle = 0x102,
		CircleFlat = 0x110,
		Flats = 0x111,
		AngleFlat = 0x112,
		CircleAngle = 0x120,
		FlatAngle = 0x121,
		Angles = 0x122,
	};

	enum class Supports
	{
		LineDrawsFinal = 0,
		PixelDivisions = 1,
		FractionalStrokeWidth = 2,
		TranslucentStroke = 3,
		PixelModification = 4,
	};

	enum class TypeProperty
	{
		Boolean = 0,
		Integer = 1,
		String = 2,
	};

	// Notifications
	// Type of modification and the action which caused the modification.
	// These are defined as a bit mask to make it easy to specify which notifications are wanted.
	// One bit is set from each of SC_MOD_* and SC_PERFORMED_*.
	enum class ModificationFlags
	{
		None = 0x0,
		InsertText = 0x1,
		DeleteText = 0x2,
		ChangeStyle = 0x4,
		ChangeFold = 0x8,
		User = 0x10,
		Undo = 0x20,
		Redo = 0x40,
		MultiStepUndoRedo = 0x80,
		LastStepInUndoRedo = 0x100,
		ChangeMarker = 0x200,
		BeforeInsert = 0x400,
		BeforeDelete = 0x800,
		MultilineUndoRedo = 0x1000,
		StartAction = 0x2000,
		ChangeIndicator = 0x4000,
		ChangeLineState = 0x8000,
		ChangeMargin = 0x10000,
		ChangeAnnotation = 0x20000,
		Container = 0x40000,
		LexerState = 0x80000,
		InsertCheck = 0x100000,
		ChangeTabStops = 0x200000,
		ChangeEOLAnnotation = 0x400000,
		EventMaskAll = 0x7FFFFF,
	};

	enum class Update
	{
		Content = 0x1,
		Selection = 0x2,
		VScroll = 0x4,
		HScroll = 0x8,
	};

	// Symbolic key codes and modifier flags.
	// ASCII and other printable characters below 256.
	// Extended keys above 300.
	enum class Keys
	{
		Down = 300,
		Up = 301,
		Left = 302,
		Right = 303,
		Home = 304,
		End = 305,
		Prior = 306,
		Next = 307,
		Delete = 308,
		Insert = 309,
		Escape = 7,
		Back = 8,
		Tab = 9,
		Return = 13,
		Add = 310,
		Subtract = 311,
		Divide = 312,
		Win = 313,
		RWin = 314,
		Menu = 315,
	};

	enum class KeyMod
	{
		Norm = 0,
		Shift = 1,
		Ctrl = 2,
		Alt = 4,
		Super = 8,
		Meta = 16,
	};

	enum class CompletionMethods
	{
		FillUp = 1,
		DoubleClick = 2,
		Tab = 3,
		Newline = 4,
		Command = 5,
	};

	// characterSource for SCN_CHARADDED
	enum class CharacterSource
	{
		// Direct input characters.
		DirectInput = 0,
		// IME (inline mode) or dead key tentative input characters.
		TentativeInput = 1,
		// IME (either inline or windowed mode) full composited string.
		ImeResult = 2,
	};

	enum class Bidirectional
	{
		Disabled = 0,
		L2r = 1,
		R2l = 2,
	};

	enum class LineCharacterIndexType
	{
		None = 0,
		Utf32 = 1,
		Utf16 = 2,
	};

	constexpr int InvalidPosition = -1;
	// Define start of Scintilla messages to be greater than all Windows edit (EM_*) messages
	// as many EM_ messages can be used although that use is deprecated.
	constexpr int SciStart = 2000;
	constexpr int SciOptionalStart = 3000;
	constexpr int SciLexerStart = 4000;
	// The SC_CP_UTF8 value can be used to enter Unicode mode.
	// This is the same value as CP_UTF8 in Windows
	constexpr int ScCpUtf8 = 65001;
	constexpr int MarkerMax = 31;
	// SC_MASK_FOLDERS doesn't go in an enumeration as larger than max 32-bit positive integer
	constexpr int ScMaskFolders = 0xFE000000;
	constexpr int ScMaxMargin = 4;
	constexpr int ScFontSizeMultiplier = 100;
	constexpr int ScTimeForever = 10000000;
	// Maximum value of keywordSet parameter of SetKeyWords.
	constexpr int KeywordsetMax = 8;
	// For compatibility, these go through the COMMAND notification rather than NOTIFY
	// and should have had exactly the same values as the EN_* constants.
	// Unfortunately the SETFOCUS and KILLFOCUS are flipped over from EN_*
	// As clients depend on these constants, this will not be changed.
	constexpr int ScenChange = 768;
	constexpr int ScenSetfocus = 512;
	constexpr int ScenKillfocus = 256;
	enum class ScintillaFunction
	{
		AddText = 2001,
		AddStyledText = 2002,
		InsertText = 2003,
		ChangeInsertion = 2672,
		ClearAll = 2004,
		DeleteRange = 2645,
		ClearDocumentStyle = 2005,
		GetLength = 2006,
		GetCharAt = 2007,
		GetCurrentPos = 2008,
		GetAnchor = 2009,
		GetStyleAt = 2010,
		Redo = 2011,
		SetUndoCollection = 2012,
		SelectAll = 2013,
		SetSavePoint = 2014,
		GetStyledText = 2015,
		CanRedo = 2016,
		MarkerLineFromHandle = 2017,
		MarkerDeleteHandle = 2018,
		MarkerHandleFromLine = 2732,
		MarkerNumberFromLine = 2733,
		GetUndoCollection = 2019,
		GetViewWS = 2020,
		SetViewWS = 2021,
		GetTabDrawMode = 2698,
		SetTabDrawMode = 2699,
		PositionFromPoint = 2022,
		PositionFromPointClose = 2023,
		GotoLine = 2024,
		GotoPos = 2025,
		SetAnchor = 2026,
		GetCurLine = 2027,
		GetEndStyled = 2028,
		ConvertEOLs = 2029,
		GetEOLMode = 2030,
		SetEOLMode = 2031,
		StartStyling = 2032,
		SetStyling = 2033,
		GetBufferedDraw = 2034,
		SetBufferedDraw = 2035,
		SetTabWidth = 2036,
		GetTabWidth = 2121,
		SetTabMinimumWidth = 2724,
		GetTabMinimumWidth = 2725,
		ClearTabStops = 2675,
		AddTabStop = 2676,
		GetNextTabStop = 2677,
		SetCodePage = 2037,
		SetFontLocale = 2760,
		GetFontLocale = 2761,
		GetIMEInteraction = 2678,
		SetIMEInteraction = 2679,
		MarkerDefine = 2040,
		MarkerSetFore = 2041,
		MarkerSetBack = 2042,
		MarkerSetBackSelected = 2292,
		MarkerSetForeTranslucent = 2294,
		MarkerSetBackTranslucent = 2295,
		MarkerSetBackSelectedTranslucent = 2296,
		MarkerSetStrokeWidth = 2297,
		MarkerEnableHighlight = 2293,
		MarkerAdd = 2043,
		MarkerDelete = 2044,
		MarkerDeleteAll = 2045,
		MarkerGet = 2046,
		MarkerNext = 2047,
		MarkerPrevious = 2048,
		MarkerDefinePixmap = 2049,
		MarkerAddSet = 2466,
		MarkerSetAlpha = 2476,
		SetMarginTypeN = 2240,
		GetMarginTypeN = 2241,
		SetMarginWidthN = 2242,
		GetMarginWidthN = 2243,
		SetMarginMaskN = 2244,
		GetMarginMaskN = 2245,
		SetMarginSensitiveN = 2246,
		GetMarginSensitiveN = 2247,
		SetMarginCursorN = 2248,
		GetMarginCursorN = 2249,
		SetMarginBackN = 2250,
		GetMarginBackN = 2251,
		SetMargins = 2252,
		GetMargins = 2253,
		StyleClearAll = 2050,
		StyleSetFore = 2051,
		StyleSetBack = 2052,
		StyleSetBold = 2053,
		StyleSetItalic = 2054,
		StyleSetSize = 2055,
		StyleSetFont = 2056,
		StyleSetEOLFilled = 2057,
		StyleResetDefault = 2058,
		StyleSetUnderline = 2059,
		StyleGetFore = 2481,
		StyleGetBack = 2482,
		StyleGetBold = 2483,
		StyleGetItalic = 2484,
		StyleGetSize = 2485,
		StyleGetFont = 2486,
		StyleGetEOLFilled = 2487,
		StyleGetUnderline = 2488,
		StyleGetCase = 2489,
		StyleGetCharacterSet = 2490,
		StyleGetVisible = 2491,
		StyleGetChangeable = 2492,
		StyleGetHotSpot = 2493,
		StyleSetCase = 2060,
		StyleSetSizeFractional = 2061,
		StyleGetSizeFractional = 2062,
		StyleSetWeight = 2063,
		StyleGetWeight = 2064,
		StyleSetCharacterSet = 2066,
		StyleSetHotSpot = 2409,
		SetElementColour = 2753,
		GetElementColour = 2754,
		ResetElementColour = 2755,
		GetElementIsSet = 2756,
		GetElementAllowsTranslucent = 2757,
		SetSelFore = 2067,
		SetSelBack = 2068,
		GetSelAlpha = 2477,
		SetSelAlpha = 2478,
		GetSelEOLFilled = 2479,
		SetSelEOLFilled = 2480,
		SetCaretFore = 2069,
		AssignCmdKey = 2070,
		ClearCmdKey = 2071,
		ClearAllCmdKeys = 2072,
		SetStylingEx = 2073,
		StyleSetVisible = 2074,
		GetCaretPeriod = 2075,
		SetCaretPeriod = 2076,
		SetWordChars = 2077,
		GetWordChars = 2646,
		SetCharacterCategoryOptimization = 2720,
		GetCharacterCategoryOptimization = 2721,
		BeginUndoAction = 2078,
		EndUndoAction = 2079,
		IndicSetStyle = 2080,
		IndicGetStyle = 2081,
		IndicSetFore = 2082,
		IndicGetFore = 2083,
		IndicSetUnder = 2510,
		IndicGetUnder = 2511,
		IndicSetHoverStyle = 2680,
		IndicGetHoverStyle = 2681,
		IndicSetHoverFore = 2682,
		IndicGetHoverFore = 2683,
		IndicSetFlags = 2684,
		IndicGetFlags = 2685,
		IndicSetStrokeWidth = 2751,
		IndicGetStrokeWidth = 2752,
		SetWhitespaceFore = 2084,
		SetWhitespaceBack = 2085,
		SetWhitespaceSize = 2086,
		GetWhitespaceSize = 2087,
		SetLineState = 2092,
		GetLineState = 2093,
		GetMaxLineState = 2094,
		GetCaretLineVisible = 2095,
		SetCaretLineVisible = 2096,
		GetCaretLineBack = 2097,
		SetCaretLineBack = 2098,
		GetCaretLineFrame = 2704,
		SetCaretLineFrame = 2705,
		StyleSetChangeable = 2099,
		AutoCShow = 2100,
		AutoCCancel = 2101,
		AutoCActive = 2102,
		AutoCPosStart = 2103,
		AutoCComplete = 2104,
		AutoCStops = 2105,
		AutoCSetSeparator = 2106,
		AutoCGetSeparator = 2107,
		AutoCSelect = 2108,
		AutoCSetCancelAtStart = 2110,
		AutoCGetCancelAtStart = 2111,
		AutoCSetFillUps = 2112,
		AutoCSetChooseSingle = 2113,
		AutoCGetChooseSingle = 2114,
		AutoCSetIgnoreCase = 2115,
		AutoCGetIgnoreCase = 2116,
		UserListShow = 2117,
		AutoCSetAutoHide = 2118,
		AutoCGetAutoHide = 2119,
		AutoCSetDropRestOfWord = 2270,
		AutoCGetDropRestOfWord = 2271,
		RegisterImage = 2405,
		ClearRegisteredImages = 2408,
		AutoCGetTypeSeparator = 2285,
		AutoCSetTypeSeparator = 2286,
		AutoCSetMaxWidth = 2208,
		AutoCGetMaxWidth = 2209,
		AutoCSetMaxHeight = 2210,
		AutoCGetMaxHeight = 2211,
		SetIndent = 2122,
		GetIndent = 2123,
		SetUseTabs = 2124,
		GetUseTabs = 2125,
		SetLineIndentation = 2126,
		GetLineIndentation = 2127,
		GetLineIndentPosition = 2128,
		GetColumn = 2129,
		CountCharacters = 2633,
		CountCodeUnits = 2715,
		SetHScrollBar = 2130,
		GetHScrollBar = 2131,
		SetIndentationGuides = 2132,
		GetIndentationGuides = 2133,
		SetHighlightGuide = 2134,
		GetHighlightGuide = 2135,
		GetLineEndPosition = 2136,
		GetCodePage = 2137,
		GetCaretFore = 2138,
		GetReadOnly = 2140,
		SetCurrentPos = 2141,
		SetSelectionStart = 2142,
		GetSelectionStart = 2143,
		SetSelectionEnd = 2144,
		GetSelectionEnd = 2145,
		SetEmptySelection = 2556,
		SetPrintMagnification = 2146,
		GetPrintMagnification = 2147,
		SetPrintColourMode = 2148,
		GetPrintColourMode = 2149,
		FindText = 2150,
		FormatRange = 2151,
		GetFirstVisibleLine = 2152,
		GetLine = 2153,
		GetLineCount = 2154,
		SetMarginLeft = 2155,
		GetMarginLeft = 2156,
		SetMarginRight = 2157,
		GetMarginRight = 2158,
		GetModify = 2159,
		SetSel = 2160,
		GetSelText = 2161,
		GetTextRange = 2162,
		HideSelection = 2163,
		PointXFromPosition = 2164,
		PointYFromPosition = 2165,
		LineFromPosition = 2166,
		PositionFromLine = 2167,
		LineScroll = 2168,
		ScrollCaret = 2169,
		ScrollRange = 2569,
		ReplaceSel = 2170,
		SetReadOnly = 2171,
		Null = 2172,
		CanPaste = 2173,
		CanUndo = 2174,
		EmptyUndoBuffer = 2175,
		Undo = 2176,
		Cut = 2177,
		Copy = 2178,
		Paste = 2179,
		Clear = 2180,
		SetText = 2181,
		GetText = 2182,
		GetTextLength = 2183,
		GetDirectFunction = 2184,
		GetDirectPointer = 2185,
		SetOvertype = 2186,
		GetOvertype = 2187,
		SetCaretWidth = 2188,
		GetCaretWidth = 2189,
		SetTargetStart = 2190,
		GetTargetStart = 2191,
		SetTargetStartVirtualSpace = 2728,
		GetTargetStartVirtualSpace = 2729,
		SetTargetEnd = 2192,
		GetTargetEnd = 2193,
		SetTargetEndVirtualSpace = 2730,
		GetTargetEndVirtualSpace = 2731,
		SetTargetRange = 2686,
		GetTargetText = 2687,
		TargetFromSelection = 2287,
		TargetWholeDocument = 2690,
		ReplaceTarget = 2194,
		ReplaceTargetRE = 2195,
		SearchInTarget = 2197,
		SetSearchFlags = 2198,
		GetSearchFlags = 2199,
		CallTipShow = 2200,
		CallTipCancel = 2201,
		CallTipActive = 2202,
		CallTipPosStart = 2203,
		CallTipSetPosStart = 2214,
		CallTipSetHlt = 2204,
		CallTipSetBack = 2205,
		CallTipSetFore = 2206,
		CallTipSetForeHlt = 2207,
		CallTipUseStyle = 2212,
		CallTipSetPosition = 2213,
		VisibleFromDocLine = 2220,
		DocLineFromVisible = 2221,
		WrapCount = 2235,
		SetFoldLevel = 2222,
		GetFoldLevel = 2223,
		GetLastChild = 2224,
		GetFoldParent = 2225,
		ShowLines = 2226,
		HideLines = 2227,
		GetLineVisible = 2228,
		GetAllLinesVisible = 2236,
		SetFoldExpanded = 2229,
		GetFoldExpanded = 2230,
		ToggleFold = 2231,
		ToggleFoldShowText = 2700,
		FoldDisplayTextSetStyle = 2701,
		FoldDisplayTextGetStyle = 2707,
		SetDefaultFoldDisplayText = 2722,
		GetDefaultFoldDisplayText = 2723,
		FoldLine = 2237,
		FoldChildren = 2238,
		ExpandChildren = 2239,
		FoldAll = 2662,
		EnsureVisible = 2232,
		SetAutomaticFold = 2663,
		GetAutomaticFold = 2664,
		SetFoldFlags = 2233,
		EnsureVisibleEnforcePolicy = 2234,
		SetTabIndents = 2260,
		GetTabIndents = 2261,
		SetBackSpaceUnIndents = 2262,
		GetBackSpaceUnIndents = 2263,
		SetMouseDwellTime = 2264,
		GetMouseDwellTime = 2265,
		WordStartPosition = 2266,
		WordEndPosition = 2267,
		IsRangeWord = 2691,
		SetIdleStyling = 2692,
		GetIdleStyling = 2693,
		SetWrapMode = 2268,
		GetWrapMode = 2269,
		SetWrapVisualFlags = 2460,
		GetWrapVisualFlags = 2461,
		SetWrapVisualFlagsLocation = 2462,
		GetWrapVisualFlagsLocation = 2463,
		SetWrapStartIndent = 2464,
		GetWrapStartIndent = 2465,
		SetWrapIndentMode = 2472,
		GetWrapIndentMode = 2473,
		SetLayoutCache = 2272,
		GetLayoutCache = 2273,
		SetScrollWidth = 2274,
		GetScrollWidth = 2275,
		SetScrollWidthTracking = 2516,
		GetScrollWidthTracking = 2517,
		TextWidth = 2276,
		SetEndAtLastLine = 2277,
		GetEndAtLastLine = 2278,
		TextHeight = 2279,
		SetVScrollBar = 2280,
		GetVScrollBar = 2281,
		AppendText = 2282,
		GetPhasesDraw = 2673,
		SetPhasesDraw = 2674,
		SetFontQuality = 2611,
		GetFontQuality = 2612,
		SetFirstVisibleLine = 2613,
		SetMultiPaste = 2614,
		GetMultiPaste = 2615,
		GetTag = 2616,
		LinesJoin = 2288,
		LinesSplit = 2289,
		SetFoldMarginColour = 2290,
		SetFoldMarginHiColour = 2291,
		SetAccessibility = 2702,
		GetAccessibility = 2703,
		LineDown = 2300,
		LineDownExtend = 2301,
		LineUp = 2302,
		LineUpExtend = 2303,
		CharLeft = 2304,
		CharLeftExtend = 2305,
		CharRight = 2306,
		CharRightExtend = 2307,
		WordLeft = 2308,
		WordLeftExtend = 2309,
		WordRight = 2310,
		WordRightExtend = 2311,
		Home = 2312,
		HomeExtend = 2313,
		LineEnd = 2314,
		LineEndExtend = 2315,
		DocumentStart = 2316,
		DocumentStartExtend = 2317,
		DocumentEnd = 2318,
		DocumentEndExtend = 2319,
		PageUp = 2320,
		PageUpExtend = 2321,
		PageDown = 2322,
		PageDownExtend = 2323,
		EditToggleOvertype = 2324,
		CancelModes = 2325,
		DeleteBack = 2326,
		Tab = 2327,
		BackTab = 2328,
		NewLine = 2329,
		FormFeed = 2330,
		VCHome = 2331,
		VCHomeExtend = 2332,
		ZoomIn = 2333,
		ZoomOut = 2334,
		DelWordLeft = 2335,
		DelWordRight = 2336,
		DelWordRightEnd = 2518,
		LineCut = 2337,
		LineDelete = 2338,
		LineTranspose = 2339,
		LineReverse = 2354,
		LineDuplicate = 2404,
		LowerCase = 2340,
		UpperCase = 2341,
		LineScrollDown = 2342,
		LineScrollUp = 2343,
		DeleteBackNotLine = 2344,
		HomeDisplay = 2345,
		HomeDisplayExtend = 2346,
		LineEndDisplay = 2347,
		LineEndDisplayExtend = 2348,
		HomeWrap = 2349,
		HomeWrapExtend = 2450,
		LineEndWrap = 2451,
		LineEndWrapExtend = 2452,
		VCHomeWrap = 2453,
		VCHomeWrapExtend = 2454,
		LineCopy = 2455,
		MoveCaretInsideView = 2401,
		LineLength = 2350,
		BraceHighlight = 2351,
		BraceHighlightIndicator = 2498,
		BraceBadLight = 2352,
		BraceBadLightIndicator = 2499,
		BraceMatch = 2353,
		BraceMatchNext = 2369,
		GetViewEOL = 2355,
		SetViewEOL = 2356,
		GetDocPointer = 2357,
		SetDocPointer = 2358,
		SetModEventMask = 2359,
		GetEdgeColumn = 2360,
		SetEdgeColumn = 2361,
		GetEdgeMode = 2362,
		SetEdgeMode = 2363,
		GetEdgeColour = 2364,
		SetEdgeColour = 2365,
		MultiEdgeAddLine = 2694,
		MultiEdgeClearAll = 2695,
		GetMultiEdgeColumn = 2749,
		SearchAnchor = 2366,
		SearchNext = 2367,
		SearchPrev = 2368,
		LinesOnScreen = 2370,
		UsePopUp = 2371,
		SelectionIsRectangle = 2372,
		SetZoom = 2373,
		GetZoom = 2374,
		CreateDocument = 2375,
		AddRefDocument = 2376,
		ReleaseDocument = 2377,
		GetDocumentOptions = 2379,
		GetModEventMask = 2378,
		SetCommandEvents = 2717,
		GetCommandEvents = 2718,
		SetFocus = 2380,
		GetFocus = 2381,
		SetStatus = 2382,
		GetStatus = 2383,
		SetMouseDownCaptures = 2384,
		GetMouseDownCaptures = 2385,
		SetMouseWheelCaptures = 2696,
		GetMouseWheelCaptures = 2697,
		SetCursor = 2386,
		GetCursor = 2387,
		SetControlCharSymbol = 2388,
		GetControlCharSymbol = 2389,
		WordPartLeft = 2390,
		WordPartLeftExtend = 2391,
		WordPartRight = 2392,
		WordPartRightExtend = 2393,
		SetVisiblePolicy = 2394,
		DelLineLeft = 2395,
		DelLineRight = 2396,
		SetXOffset = 2397,
		GetXOffset = 2398,
		ChooseCaretX = 2399,
		GrabFocus = 2400,
		SetXCaretPolicy = 2402,
		SetYCaretPolicy = 2403,
		SetPrintWrapMode = 2406,
		GetPrintWrapMode = 2407,
		SetHotspotActiveFore = 2410,
		GetHotspotActiveFore = 2494,
		SetHotspotActiveBack = 2411,
		GetHotspotActiveBack = 2495,
		SetHotspotActiveUnderline = 2412,
		GetHotspotActiveUnderline = 2496,
		SetHotspotSingleLine = 2421,
		GetHotspotSingleLine = 2497,
		ParaDown = 2413,
		ParaDownExtend = 2414,
		ParaUp = 2415,
		ParaUpExtend = 2416,
		PositionBefore = 2417,
		PositionAfter = 2418,
		PositionRelative = 2670,
		PositionRelativeCodeUnits = 2716,
		CopyRange = 2419,
		CopyText = 2420,
		SetSelectionMode = 2422,
		GetSelectionMode = 2423,
		GetMoveExtendsSelection = 2706,
		GetLineSelStartPosition = 2424,
		GetLineSelEndPosition = 2425,
		LineDownRectExtend = 2426,
		LineUpRectExtend = 2427,
		CharLeftRectExtend = 2428,
		CharRightRectExtend = 2429,
		HomeRectExtend = 2430,
		VCHomeRectExtend = 2431,
		LineEndRectExtend = 2432,
		PageUpRectExtend = 2433,
		PageDownRectExtend = 2434,
		StutteredPageUp = 2435,
		StutteredPageUpExtend = 2436,
		StutteredPageDown = 2437,
		StutteredPageDownExtend = 2438,
		WordLeftEnd = 2439,
		WordLeftEndExtend = 2440,
		WordRightEnd = 2441,
		WordRightEndExtend = 2442,
		SetWhitespaceChars = 2443,
		GetWhitespaceChars = 2647,
		SetPunctuationChars = 2648,
		GetPunctuationChars = 2649,
		SetCharsDefault = 2444,
		AutoCGetCurrent = 2445,
		AutoCGetCurrentText = 2610,
		AutoCSetCaseInsensitiveBehaviour = 2634,
		AutoCGetCaseInsensitiveBehaviour = 2635,
		AutoCSetMulti = 2636,
		AutoCGetMulti = 2637,
		AutoCSetOrder = 2660,
		AutoCGetOrder = 2661,
		Allocate = 2446,
		TargetAsUTF8 = 2447,
		SetLengthForEncode = 2448,
		EncodedFromUTF8 = 2449,
		FindColumn = 2456,
		GetCaretSticky = 2457,
		SetCaretSticky = 2458,
		ToggleCaretSticky = 2459,
		SetPasteConvertEndings = 2467,
		GetPasteConvertEndings = 2468,
		SelectionDuplicate = 2469,
		SetCaretLineBackAlpha = 2470,
		GetCaretLineBackAlpha = 2471,
		SetCaretStyle = 2512,
		GetCaretStyle = 2513,
		SetIndicatorCurrent = 2500,
		GetIndicatorCurrent = 2501,
		SetIndicatorValue = 2502,
		GetIndicatorValue = 2503,
		IndicatorFillRange = 2504,
		IndicatorClearRange = 2505,
		IndicatorAllOnFor = 2506,
		IndicatorValueAt = 2507,
		IndicatorStart = 2508,
		IndicatorEnd = 2509,
		SetPositionCache = 2514,
		GetPositionCache = 2515,
		CopyAllowLine = 2519,
		GetCharacterPointer = 2520,
		GetRangePointer = 2643,
		GetGapPosition = 2644,
		IndicSetAlpha = 2523,
		IndicGetAlpha = 2524,
		IndicSetOutlineAlpha = 2558,
		IndicGetOutlineAlpha = 2559,
		SetExtraAscent = 2525,
		GetExtraAscent = 2526,
		SetExtraDescent = 2527,
		GetExtraDescent = 2528,
		MarkerSymbolDefined = 2529,
		MarginSetText = 2530,
		MarginGetText = 2531,
		MarginSetStyle = 2532,
		MarginGetStyle = 2533,
		MarginSetStyles = 2534,
		MarginGetStyles = 2535,
		MarginTextClearAll = 2536,
		MarginSetStyleOffset = 2537,
		MarginGetStyleOffset = 2538,
		SetMarginOptions = 2539,
		GetMarginOptions = 2557,
		AnnotationSetText = 2540,
		AnnotationGetText = 2541,
		AnnotationSetStyle = 2542,
		AnnotationGetStyle = 2543,
		AnnotationSetStyles = 2544,
		AnnotationGetStyles = 2545,
		AnnotationGetLines = 2546,
		AnnotationClearAll = 2547,
		AnnotationSetVisible = 2548,
		AnnotationGetVisible = 2549,
		AnnotationSetStyleOffset = 2550,
		AnnotationGetStyleOffset = 2551,
		ReleaseAllExtendedStyles = 2552,
		AllocateExtendedStyles = 2553,
		AddUndoAction = 2560,
		CharPositionFromPoint = 2561,
		CharPositionFromPointClose = 2562,
		SetMouseSelectionRectangularSwitch = 2668,
		GetMouseSelectionRectangularSwitch = 2669,
		SetMultipleSelection = 2563,
		GetMultipleSelection = 2564,
		SetAdditionalSelectionTyping = 2565,
		GetAdditionalSelectionTyping = 2566,
		SetAdditionalCaretsBlink = 2567,
		GetAdditionalCaretsBlink = 2568,
		SetAdditionalCaretsVisible = 2608,
		GetAdditionalCaretsVisible = 2609,
		GetSelections = 2570,
		GetSelectionEmpty = 2650,
		ClearSelections = 2571,
		SetSelection = 2572,
		AddSelection = 2573,
		DropSelectionN = 2671,
		SetMainSelection = 2574,
		GetMainSelection = 2575,
		SetSelectionNCaret = 2576,
		GetSelectionNCaret = 2577,
		SetSelectionNAnchor = 2578,
		GetSelectionNAnchor = 2579,
		SetSelectionNCaretVirtualSpace = 2580,
		GetSelectionNCaretVirtualSpace = 2581,
		SetSelectionNAnchorVirtualSpace = 2582,
		GetSelectionNAnchorVirtualSpace = 2583,
		SetSelectionNStart = 2584,
		GetSelectionNStart = 2585,
		GetSelectionNStartVirtualSpace = 2726,
		SetSelectionNEnd = 2586,
		GetSelectionNEndVirtualSpace = 2727,
		GetSelectionNEnd = 2587,
		SetRectangularSelectionCaret = 2588,
		GetRectangularSelectionCaret = 2589,
		SetRectangularSelectionAnchor = 2590,
		GetRectangularSelectionAnchor = 2591,
		SetRectangularSelectionCaretVirtualSpace = 2592,
		GetRectangularSelectionCaretVirtualSpace = 2593,
		SetRectangularSelectionAnchorVirtualSpace = 2594,
		GetRectangularSelectionAnchorVirtualSpace = 2595,
		SetVirtualSpaceOptions = 2596,
		GetVirtualSpaceOptions = 2597,
		SetRectangularSelectionModifier = 2598,
		GetRectangularSelectionModifier = 2599,
		SetAdditionalSelFore = 2600,
		SetAdditionalSelBack = 2601,
		SetAdditionalSelAlpha = 2602,
		GetAdditionalSelAlpha = 2603,
		SetAdditionalCaretFore = 2604,
		GetAdditionalCaretFore = 2605,
		RotateSelection = 2606,
		SwapMainAnchorCaret = 2607,
		MultipleSelectAddNext = 2688,
		MultipleSelectAddEach = 2689,
		ChangeLexerState = 2617,
		ContractedFoldNext = 2618,
		VerticalCentreCaret = 2619,
		MoveSelectedLinesUp = 2620,
		MoveSelectedLinesDown = 2621,
		SetIdentifier = 2622,
		GetIdentifier = 2623,
		RGBAImageSetWidth = 2624,
		RGBAImageSetHeight = 2625,
		RGBAImageSetScale = 2651,
		MarkerDefineRGBAImage = 2626,
		RegisterRGBAImage = 2627,
		ScrollToStart = 2628,
		ScrollToEnd = 2629,
		SetTechnology = 2630,
		GetTechnology = 2631,
		CreateLoader = 2632,
		FindIndicatorShow = 2640,
		FindIndicatorFlash = 2641,
		FindIndicatorHide = 2642,
		VCHomeDisplay = 2652,
		VCHomeDisplayExtend = 2653,
		GetCaretLineVisibleAlways = 2654,
		SetCaretLineVisibleAlways = 2655,
		SetLineEndTypesAllowed = 2656,
		GetLineEndTypesAllowed = 2657,
		GetLineEndTypesActive = 2658,
		SetRepresentation = 2665,
		GetRepresentation = 2666,
		ClearRepresentation = 2667,
		EOLAnnotationSetText = 2740,
		EOLAnnotationGetText = 2741,
		EOLAnnotationSetStyle = 2742,
		EOLAnnotationGetStyle = 2743,
		EOLAnnotationClearAll = 2744,
		EOLAnnotationSetVisible = 2745,
		EOLAnnotationGetVisible = 2746,
		EOLAnnotationSetStyleOffset = 2747,
		EOLAnnotationGetStyleOffset = 2748,
		SupportsFeature = 2750,
		StartRecord = 3001,
		StopRecord = 3002,
		GetLexer = 4002,
		Colourise = 4003,
		SetProperty = 4004,
		SetKeyWords = 4005,
		GetProperty = 4008,
		GetPropertyExpanded = 4009,
		GetPropertyInt = 4010,
		GetLexerLanguage = 4012,
		PrivateLexerCall = 4013,
		PropertyNames = 4014,
		PropertyType = 4015,
		DescribeProperty = 4016,
		DescribeKeyWordSets = 4017,
		GetLineEndTypesSupported = 4018,
		AllocateSubStyles = 4020,
		GetSubStylesStart = 4021,
		GetSubStylesLength = 4022,
		GetStyleFromSubStyle = 4027,
		GetPrimaryStyleFromStyle = 4028,
		FreeSubStyles = 4023,
		SetIdentifiers = 4024,
		DistanceToSecondaryStyles = 4025,
		GetSubStyleBases = 4026,
		GetNamedStyles = 4029,
		NameOfStyle = 4030,
		TagsOfStyle = 4031,
		DescriptionOfStyle = 4032,
		SetILexer = 4033,
		GetBidirectional = 2708,
		SetBidirectional = 2709,
		GetLineCharacterIndex = 2710,
		AllocateLineCharacterIndex = 2711,
		ReleaseLineCharacterIndex = 2712,
		LineFromIndexPosition = 2713,
		IndexPositionFromLine = 2714,
	};

}
