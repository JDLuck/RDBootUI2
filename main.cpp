/*
http://zetcode.com/gui/wxwidgets/firstprograms/
*/

#include <wx/wxprec.h>

#ifndef WX_PRECOMP
  #include <wx/wx.h>
#endif

#include "main.h"

IMPLEMENT_APP(MainApp) // Initializes the MainApp class and tells our program
// to run it
bool MainApp::OnInit()
{
  // Create an instance of our frame, or window
  MainFrame *MainWin = new MainFrame(_T(WIN_TITLE), wxPoint(1, 1), wxSize(67 + 33 + 34,200));
  MainWin->Show(TRUE); // show the window
  SetTopWindow(MainWin); // and finally, set it as the main window

  return TRUE;
}

BEGIN_EVENT_TABLE ( MainFrame, wxFrame )
    EVT_MENU(MENU_Open, MainFrame::OpenFile)
    EVT_BUTTON ( BUTTON_Hello, MainFrame::OnExit ) // Tell the OS to run MainFrame::OnExit when
END_EVENT_TABLE() // The button is pressed

MainFrame::MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size): wxFrame((wxFrame*)NULL,  - 1, title, pos, size)
{
  CreateStatusBar(2);
  MainMenu = new wxMenuBar();
  wxMenu* FileMenu = new wxMenu();
  FileMenu->Append(MENU_Open, wxT("&Open"), wxT("Open a file"));
  MainMenu->Append(FileMenu, wxT("File"));
  SetMenuBar(MainMenu);

  wxPanel *panel = new wxPanel(this, wxID_ANY);
  btnOpen = new wxButton(panel, wxID_EXIT, wxT("O"), wxPoint(1, 1), wxSize(32, 32));
  btnProgram = new wxButton(panel, wxID_EXIT, wxT("P"), wxPoint(1 + 33, 1), wxSize(32, 32));
  btnAuto = new wxButton(panel, wxID_EXIT, wxT("A"), wxPoint(34 + 33, 1), wxSize(32, 32));
  btnDevice = new wxButton(panel, wxID_EXIT, wxT("D"), wxPoint(67 + 33, 1), wxSize(32, 32));
}

void MainFrame::OpenFile(wxCommandEvent& WXUNUSED(event))
{
    wxFileDialog* OpenDialog = new wxFileDialog(
		this, _("Choose a file to open"), wxEmptyString, wxEmptyString,
		_("Intel Hex Files (*.hex)|*.hex|Elf Binary Files (*.elf)|*.elf"),
		wxFD_OPEN, wxDefaultPosition);

	if (OpenDialog->ShowModal() == wxID_OK)
	{
		CurrentDocPath = OpenDialog->GetPath();

		SetTitle(wxString("Edit - ") <<
			OpenDialog->GetFilename());
	}

	// Clean up after ourselves
	OpenDialog->Destroy();
}

void MainFrame::OnExit( wxCommandEvent& event )
{
  Close(TRUE); // Tells the OS to quit running this process
}
