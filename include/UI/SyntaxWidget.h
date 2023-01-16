#pragma once
#include "UltraEngine.h"
#include "../Utilities.h"

using namespace UltraEngine;
using namespace Scintilla;

class TextEditorNotification : public Object {
public:
	Sci_Position position;
	int ch;
	int modifiers;
	int modificationType;
	String text;
	Sci_Position length;
	Sci_Position linesAdded;
	int message;
	Sci_Position line;
	int foldLevelNow;
	int foldLevelPrev;
	int margin;
	int listType;
	int x;
	int y;
	int token;
	Sci_Position annotationLinesAdded;
	int updated;
	int listCompletionMethod;
	int characterSource;
};

bool ScrollchangedWatcherCallback(const Event& ev, shared_ptr<Object> extra);

enum class SCNEVENT : int
{
	NONE = -1,
	STYLENEEDED = 99999,
	CHARADDED,
	SAVEPOINTREACHED,
	SAVEPOINTLEFT,
	MODIFYATTEMPTRO,
	KEY,
	SCI_DOUBLECLICK,
	UPDATEUI,
	MODIFIED,
	MACRORECORD,
	MARGINCLICK,
	NEEDSHOWN,
	PAINTED,
	USERLISTSELECTION,
	URIDROPPED,
	DWELLSTART,
	DWELLEND,
	ZOOM,
	HOTSPOTCLICK,
	HOTSPOTDOUBLECLICK,
	HOTSPOTRELEASECLICK,
	INDICATORCLICK,
	INDICATORRELEASE,
	CALLTIPCLICK,
	AUTOCSELECTION,
	AUTOCCANCELLED,
	AUTOCCHARDELETED,
	FOCUSIN,
	FOCUSOUT,
	AUTOCCOMPLETED,
	MARGINRIGHTCLICK,
	AUTOCSELECTIONCHANGE
};

inline SCNEVENT operator==(SCNEVENT a, int b)
{
	return static_cast<SCNEVENT>(static_cast<int>(a) == b);
};

class SyntaxEditor : public Widget
{
private:
	static bool SCI_REGISTERED;
	static vector<shared_ptr<SyntaxEditor>> SytaxEditorMap;
	
	HINSTANCE hInstance = 0;
	HWND hwnd = 0;
	Scintilla::FunctionDirect fn;
	intptr_t ptr;

	float slidersize = 20;
	shared_ptr<Widget> _horizontalSlider;
	shared_ptr<Widget> _verticalSlider;
	bool scintillaVisible = false;

	shared_ptr<Scintilla::ScintillaCall> _scintillaCall;

	void ProcessNotification(SCNotification* n);
	void SetFnPtr(Scintilla::FunctionDirect fn_, intptr_t ptr_) noexcept;
	bool IsValid() const noexcept;
	bool InitScintilla(const int x, const int y, const int width, const int height);
	iVec4 GetScintillaWindowShape();
	void UpdateSliderLocation();
	void UpdateSliderVisibility();
	void UpdateSliderValues(bool updateFromScintilla = false);

	virtual void UpdateLayout() override; 
	virtual void Draw__(const int x, const int y, const int width, const int height) override;
	virtual bool Initialize(const WString& text, const int x, const int y, const int width, const int height, shared_ptr<Widget> parent, const int style) override;

public:
	friend bool ScrollchangedWatcherCallback(const Event& ev, shared_ptr<Object> extra);
	friend shared_ptr<SyntaxEditor> CreateSyntaxEditor(const int x, const int y, const int width, const int height, shared_ptr<Widget> parent);
	friend LRESULT CALLBACK HandleScintillaNotifications(int nCode, WPARAM wParam, LPARAM lParam);
	virtual void Hide(), Show()  override;
	shared_ptr<Scintilla::ScintillaCall> GetCall() { return _scintillaCall; };
	virtual WString GetText(const bool selected = false) override;
	virtual void SetText(const WString& text) override;
	virtual void AddText(const WString& text) override;
	virtual void SelectText(const int position, const int length) override;
	virtual void Cut() override;
	virtual void Copy() override;
	virtual void Paste() override;


	

};

shared_ptr<SyntaxEditor> CreateSyntaxEditor(const int x, const int y, const int width, const int height, shared_ptr<Widget> parent);