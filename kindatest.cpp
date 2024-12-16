#include <wx/wx.h>

class MyApp : public wxApp
{
public:
	bool OnInit() override;
};

wxIMPLEMENT_APP(MyApp);

class MyFrame : public wxFrame
{
public:
	MyFrame();

private:
	void OnClicked(wxCommandEvent& event);
	void OnExit(wxCommandEvent& event);
};

bool MyApp::OnInit()
{
	MyFrame* frame = new MyFrame();
	frame->Show();
	return true;
}

enum
{
	buttonID = 1,
	textID = 2
};

MyFrame::MyFrame() : wxFrame(nullptr, wxID_ANY, "Calculator", wxDefaultPosition, wxSize(400, 300))
{
	wxPanel* panel = new wxPanel(this);
	wxButton* button = new wxButton(panel, buttonID, "Calculate", wxPoint(280, 95), wxSize(75, 35));
	wxStaticText* text = new wxStaticText(panel, wxID_ANY, "Enter your calculation:", wxPoint(50, 75));
	wxTextCtrl* textbox = new wxTextCtrl(panel, textID, "", wxPoint(50, 100), wxSize(200, -1));
	button->Bind(wxEVT_BUTTON, &MyFrame::OnClicked, this, buttonID);
	long int begin, end;
	textbox->GetSelection(&begin, &end);
	if (begin != end)
	{
		textbox->Remove(begin, end);
	}
}

void MyFrame::OnExit(wxCommandEvent& event)
{
	Close(true);
}

void MyFrame::OnClicked(wxCommandEvent& event)
{
	wxMessageBox("Hello World!", "Output Calculations", wxOK | wxICON_INFORMATION);

}




