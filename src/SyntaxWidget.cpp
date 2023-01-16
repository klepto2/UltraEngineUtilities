#include "UltraEngine.h"
#include "../include/Utilities.h"
#include <Windows.h>

bool SyntaxEditor::SCI_REGISTERED = false;
vector<shared_ptr<SyntaxEditor>> SyntaxEditor::SytaxEditorMap;


bool ScrollchangedWatcherCallback(const Event& ev, shared_ptr<Object> extra)
{
	auto editor = extra->As<SyntaxEditor>();
	if (editor != NULL)
	{
		editor->UpdateSliderValues();
		return false;
	}

	return true;
}

shared_ptr<SyntaxEditor> CreateSyntaxEditor(const int x, const int y, const int width, const int height, shared_ptr<Widget> parent)
{
	auto widget = make_shared<SyntaxEditor>();
	widget->Initialize("", x, y, width, height, parent, 0);
	float scale = widget->gui->scale;
	widget->_verticalSlider = CreateSlider(width - widget->slidersize * scale, 0, widget->slidersize * scale, height, widget, SLIDER_VERTICAL | SLIDER_SCROLLBAR);
	widget->_horizontalSlider = CreateSlider(0, width - widget->slidersize * scale, width, widget->slidersize * scale, widget, SLIDER_HORIZONTAL | SLIDER_SCROLLBAR);
	SyntaxEditor::SytaxEditorMap.push_back(widget);
	ListenEvent(EVENT_NONE, widget->_verticalSlider,&ScrollchangedWatcherCallback, widget);
	ListenEvent(EVENT_NONE, widget->_horizontalSlider, &ScrollchangedWatcherCallback, widget);
	widget->UpdateLayout();
	return widget;
}

void SyntaxEditor::UpdateSliderLocation()
{
	int hscrollwidthlimiter = 0;
	int vscrollheightlimiter = 0;

	if (!_verticalSlider->GetHidden())
	{
		hscrollwidthlimiter = slidersize * gui->scale;
	}

	if (!_horizontalSlider->GetHidden())
	{
		vscrollheightlimiter = slidersize * gui->scale;
	}

	_horizontalSlider->SetShape(0, this->size.y - slidersize * gui->scale, this->size.x - hscrollwidthlimiter, slidersize * gui->scale);
	_verticalSlider->SetShape(this->size.x - slidersize * gui->scale, 0, slidersize * gui->scale, this->size.y - vscrollheightlimiter);
}

void SyntaxEditor::UpdateSliderVisibility()
{
	if (GetCall()->ScrollWidth() > GetSize().y)
	{
		_horizontalSlider->SetHidden(false);
	}
	else
	{
		_horizontalSlider->SetHidden(true);
	}

	if (GetCall()->LineCount() > GetCall()->LinesOnScreen())
	{
		_verticalSlider->SetHidden(false);
	}
	else
	{
		_verticalSlider->SetHidden(true);
	}
}

void SyntaxEditor::UpdateSliderValues(bool updateFromScintilla)
{
	auto shape = GetScintillaWindowShape();
	int margin_count = GetCall()->Margins();
	int msize = GetCall()->MarginLeft() + GetCall()->MarginRight();
	for (int m = 0; m < margin_count; m++)
	{
		msize += GetCall()->MarginWidthN(m);
	}

	auto range = _horizontalSlider->GetRange();
	if (range.x != (shape.width - msize) / 10 || range.y != GetCall()->ScrollWidth() / 10)
	{
		_horizontalSlider->SetRange((shape.width - msize) / 10, GetCall()->ScrollWidth() / 10);
		_horizontalSlider->SetValue(GetCall()->XOffset() / 10.0);
	}

	int lc = GetCall()->LineCount();
	int l = GetCall()->LinesOnScreen();
	range = _verticalSlider->GetRange();

	if (range.x != l || range.y != lc)
	{
		_verticalSlider->SetRange(GetCall()->LinesOnScreen(), GetCall()->LineCount());
		_verticalSlider->SetValue(GetCall()->FirstVisibleLine());
	}

	if (updateFromScintilla)
	{
		_horizontalSlider->SetValue(GetCall()->XOffset() / 10.0);
		_verticalSlider->SetValue(GetCall()->FirstVisibleLine());
		UpdateLayout();
	}
	else
	{
		GetCall()->SetXOffset(_horizontalSlider->GetValue() * 10.0);
		GetCall()->SetFirstVisibleLine(_verticalSlider->GetValue());
	}

}

iVec4 SyntaxEditor::GetScintillaWindowShape()
{
	auto pos = GetPosition(true);
	auto size = this->ClientSize();
	int vScroll = 0;
	int hScroll = 0;

	if (!_horizontalSlider->GetHidden())
	{
		hScroll = _horizontalSlider->size.y;
	}

	if (!_verticalSlider->GetHidden())
	{
		vScroll = _verticalSlider->size.x;
	}

	return iVec4(pos.x, pos.y, size.x - vScroll, size.y - hScroll);
}

void SyntaxEditor::UpdateLayout()
{
	Widget::UpdateLayout();
	UpdateSliderVisibility();
	UpdateSliderLocation();
	auto shape = GetScintillaWindowShape();
	SetWindowPos(hwnd, HWND_TOP, shape.x, shape.y, shape.width, shape.height, SWP_NOREDRAW);
}

bool redrawing = false;

void SyntaxEditor::Draw__(const int x, const int y, const int width, const int height)
{
	if (collapsed || hidestate || redrawing)
	{
		return;
	}

	redrawing = true;

	UpdateSliderValues();

	Widget::Draw__(x, y, width, height);

	if (!scintillaVisible)
	{
		UpdateLayout();
		ShowWindow(hwnd, SW_SHOW);
		scintillaVisible = true;
	}
	else
	{
		UpdateWindow(hwnd);
	}

	redrawing = false;
}
void getPixels(HBITMAP hBitmap) {
	auto bitmap = Gdiplus::Bitmap(hBitmap, HPALETTE(0));
	Gdiplus::BitmapData bitmapData;
	Gdiplus::Rect rect(0, 0, bitmap.GetWidth(), bitmap.GetHeight());

	//get the bitmap data
	if (Gdiplus::Ok == bitmap.LockBits(
		&rect, //A rectangle structure that specifies the portion of the Bitmap to lock.
		Gdiplus::ImageLockModeRead | Gdiplus::ImageLockModeWrite, //ImageLockMode values that specifies the access level (read/write) for the Bitmap.
		bitmap.GetPixelFormat(),// PixelFormat values that specifies the data format of the Bitmap.
		&bitmapData //BitmapData that will contain the information about the lock operation.
	))
	{
		//get the lenght of the bitmap data in bytes
		int len = bitmapData.Height * std::abs(bitmapData.Stride);

		BYTE* buffer = new BYTE[len];
		//memcpy(bitmapData.Scan0, buffer, len);//copy it to an array of BYTEs

		//... 

		//cleanup
		bitmap.UnlockBits(&bitmapData);
		delete[]buffer;
	}
}

void SyntaxEditor::ProcessNotification(SCNotification* n)
{
	auto notification = make_shared<TextEditorNotification>();
	notification->position = n->position;
	notification->ch = n->ch;
	notification->modifiers = n->modifiers;
	notification->modificationType = n->modificationType;
	notification->text = "";
	if (n->text != NULL)
	{
		notification->text = String(n->text);
	}
	notification->length = n->length;
	notification->linesAdded = n->linesAdded;
	notification->message = n->message;
	notification->line = n->line;
	notification->foldLevelNow = n->foldLevelNow;
	notification->foldLevelPrev = n->foldLevelPrev;
	notification->margin = n->margin;
	notification->listType = n->listType;
	notification->x = n->x;
	notification->y = n->y;
	notification->token = n->token;
	notification->annotationLinesAdded = n->annotationLinesAdded;
	notification->updated = n->updated;
	notification->listCompletionMethod = n->listCompletionMethod;
	notification->characterSource = n->characterSource;

	SCNEVENT id = SCNEVENT::NONE;
	switch (n->nmhdr.code)
	{
	case SCN_STYLENEEDED:
		id = SCNEVENT::STYLENEEDED;
		break;
	case SCN_CHARADDED:
		id = SCNEVENT::CHARADDED;
		break;
	case SCN_SAVEPOINTREACHED:
		id = SCNEVENT::SAVEPOINTREACHED;
		break;
	case SCN_SAVEPOINTLEFT:
		id = SCNEVENT::SAVEPOINTLEFT;
		break;
	case SCN_MODIFYATTEMPTRO:
		id = SCNEVENT::MODIFYATTEMPTRO;
		break;
	case SCN_KEY:
		id = SCNEVENT::KEY;
		break;
	case SCN_DOUBLECLICK:
		id = SCNEVENT::SCI_DOUBLECLICK;
		break;
	case SCN_UPDATEUI:
		if (n->updated & SC_UPDATE_V_SCROLL || n->updated & SC_UPDATE_H_SCROLL)
		{
			UpdateSliderValues(true);
		}
		id = SCNEVENT::UPDATEUI;
		break;
	case SCN_MODIFIED:
		UpdateSliderValues(true);
		id = SCNEVENT::MODIFIED;
		break;
	case SCN_MACRORECORD:
		id = SCNEVENT::MACRORECORD;
		break;
	case SCN_MARGINCLICK:
		id = SCNEVENT::MARGINCLICK;
		break;
	case SCN_NEEDSHOWN:
		id = SCNEVENT::NEEDSHOWN;
		break;
	case SCN_PAINTED:
	{
		id = SCNEVENT::PAINTED;
		/*
		PAINTSTRUCT ps;
		HDC hdc = BeginPaint(hwnd, &ps);
		InvalidateRect(hwnd, NULL, TRUE);
		::UpdateWindow(hwnd);
		// Create a memory device context (DC) associated with the bitmap
		HDC hMemDC = CreateCompatibleDC(hdc);
		HBITMAP hBitmap = CreateCompatibleBitmap(hdc, size.x, size.y);
		SelectObject(hMemDC, hBitmap);

		// Draw to the memory DC
		// ...
		// Copy the contents of the window's DC to the memory DC
		BitBlt(hMemDC, 0, 0, size.x, size.y, hdc, 0, 0, SRCCOPY);

		BITMAP bm;
		GetObjectW(hBitmap, sizeof(bm), &bm);
		int width = bm.bmWidth;
		int height = bm.bmHeight;

		// Create a BITMAPINFO struct
		BITMAPINFO bmi;
		ZeroMemory(&bmi, sizeof(bmi));
		bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
		bmi.bmiHeader.biWidth = width;
		bmi.bmiHeader.biHeight = height;
		bmi.bmiHeader.biPlanes = 1;
		bmi.bmiHeader.biBitCount = 32;
		bmi.bmiHeader.biCompression = BI_RGB;

		// Create a buffer to receive the pixel data
		//unsigned char* buffer = new unsigned char[width * height * 4];
		auto buffer = CreateBuffer(width * height * 4);
		
		// Copy the pixel data from the bitmap to the buffer
		HDC hdcc = CreateCompatibleDC(NULL);
		SelectObject(hdcc, hBitmap);
		GetDIBits(hdcc, hBitmap, 0, height,buffer->Data(), &bmi, DIB_RGB_COLORS);

		auto pixmap = CreatePixmap(width, height, TEXTURE_RGBA, buffer);
		pixmap->Save("test.dds");
		// Cleanup
		DeleteObject(hBitmap);
		DeleteDC(hMemDC);
		DeleteDC(hdcc);
		EndPaint(hwnd, &ps);
		*/
		break;
	}
	case SCN_USERLISTSELECTION:
		id = SCNEVENT::USERLISTSELECTION;
		break;
	case SCN_URIDROPPED:
		id = SCNEVENT::URIDROPPED;
		break;
	case SCN_DWELLSTART:
		id = SCNEVENT::DWELLSTART;
		break;
	case SCN_DWELLEND:
		id = SCNEVENT::DWELLEND;
		break;
	case SCN_ZOOM:
		id = SCNEVENT::ZOOM;
		break;
	case SCN_HOTSPOTCLICK:
		id = SCNEVENT::HOTSPOTCLICK;
		break;
	case SCN_HOTSPOTDOUBLECLICK:
		id = SCNEVENT::HOTSPOTDOUBLECLICK;
		break;
	case SCN_HOTSPOTRELEASECLICK:
		id = SCNEVENT::HOTSPOTRELEASECLICK;
		break;
	case SCN_INDICATORCLICK:
		id = SCNEVENT::INDICATORCLICK;
		break;
	case SCN_INDICATORRELEASE:
		id = SCNEVENT::INDICATORRELEASE;
		break;
	case SCN_CALLTIPCLICK:
		id = SCNEVENT::CALLTIPCLICK;
		break;
	case SCN_AUTOCSELECTION:
		id = SCNEVENT::AUTOCSELECTION;
		break;
	case SCN_AUTOCCANCELLED:
		id = SCNEVENT::AUTOCCANCELLED;
		break;
	case SCN_AUTOCCHARDELETED:
		id = SCNEVENT::AUTOCCHARDELETED;
		break;
	case SCN_FOCUSIN:
		id = SCNEVENT::FOCUSIN;
		break;
	case SCN_FOCUSOUT:
		id = SCNEVENT::FOCUSOUT;
		break;
	case SCN_AUTOCCOMPLETED:
		id = SCNEVENT::AUTOCCOMPLETED;
		break;
	case SCN_MARGINRIGHTCLICK:
		id = SCNEVENT::MARGINRIGHTCLICK;
		break;
	case SCN_AUTOCSELECTIONCHANGE:
		id = SCNEVENT::AUTOCSELECTIONCHANGE;
		break;
	}

	if (id != SCNEVENT::NONE)
	{
		EmitEvent((int)id, Self(), notification->ch, notification->x, notification->y, 0, 0, notification);
	}
}

LRESULT CALLBACK HandleScintillaNotifications(int nCode, WPARAM wParam, LPARAM lParam)
{
	NMHDR* lpnmhdr;
	const CWPSTRUCT& cwps = *(CWPSTRUCT*)lParam;

	//Print();
	switch (cwps.message)
	{
	case WM_NOTIFY:
		lpnmhdr = (LPNMHDR)cwps.lParam;

		for (auto w : SyntaxEditor::SytaxEditorMap)
		{
			auto editor = w.get();
			if (editor->hwnd == lpnmhdr->hwndFrom)
			{
				editor->ProcessNotification(reinterpret_cast<SCNotification*>(cwps.lParam));
				break;
			}
		}
		break;
	case WM_PAINT:
		
		break;
	}

	return NULL;
}

bool SyntaxEditor::InitScintilla(const int x, const int y, const int width, const int height)
{
	auto parentWindow = gui->GetWindow();
	if (parentWindow == NULL)
	{
		parentWindow = ActiveWindow();
	}

	hInstance = (HINSTANCE)GetWindowLong(parentWindow->GetHandle(), GWLP_HINSTANCE);

	if (!SyntaxEditor::SCI_REGISTERED)
	{
		if (!Scintilla_RegisterClasses(hInstance))
		{
			return false;
		}

		SyntaxEditor::SCI_REGISTERED = true;
	}

	hwnd = CreateWindowA(
		"Scintilla",
		"Source",
		WS_CHILD | WS_TABSTOP | WS_CLIPCHILDREN | WS_EX_LAYERED | LWS_TRANSPARENT,
		x, y,
		width, height,
		parentWindow->GetHandle(),
		0,
		hInstance,
		0);



	Scintilla::FunctionDirect fn_ = reinterpret_cast<Scintilla::FunctionDirect>(
		SendMessage(hwnd, SCI_GETDIRECTFUNCTION, 0, 0));
	const sptr_t ptr_ = SendMessage(hwnd, SCI_GETDIRECTPOINTER, 0, 0);
	//SetFnPtr(fn_, ptr_);

	_scintillaCall = make_shared<Scintilla::ScintillaCall>();
	_scintillaCall->SetFnPtr(fn_, ptr_);


	::SetWindowsHookEx(WH_CALLWNDPROC, HandleScintillaNotifications, hInstance, GetCurrentThreadId());
	GetCall()->SetVScrollBar(false);
	GetCall()->SetHScrollBar(false);
	GetCall()->SetBufferedDraw(true);
}

bool SyntaxEditor::Initialize(const WString& text, const int x, const int y, const int width, const int height, shared_ptr<Widget> parent, const int style)
{
	if (Widget::Initialize(text, x, y, width, height, parent, style))
	{
		return InitScintilla(x,y,width,height);
	}

	return false;
}

void SyntaxEditor::Hide()
{
	Widget::Hide();
	ShowWindow(hwnd, SW_HIDE);
}

void SyntaxEditor::Show()
{
	Widget::Show();
	scintillaVisible = false;
}

bool SyntaxEditor::IsValid() const noexcept {
	return fn && ptr;
}

WString SyntaxEditor::GetText(const bool selected)
{
	if (!selected)
	{
		return WString(_scintillaCall->GetText(0));
	}
	else
	{
		return _scintillaCall->GetSelText();
	}
}

void SyntaxEditor::SetText(const WString& text)
{
	_scintillaCall->SetText(text.ToUtf8String().c_str());
}

void SyntaxEditor::AddText(const WString& text)
{
	_scintillaCall->AddText(_scintillaCall->Length(), text.ToUtf8String().c_str());
}

void SyntaxEditor::Cut()
{
	_scintillaCall->Cut();
}

void SyntaxEditor::Copy()
{
	_scintillaCall->Copy();
}

void SyntaxEditor::Paste()
{
	_scintillaCall->Paste();
}

void SyntaxEditor::SelectText(const int position, const int length)
{
	_scintillaCall->SetSelectionStart(position);
	_scintillaCall->SetSelectionEnd(position + length);
}




