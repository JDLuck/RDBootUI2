#ifndef __BASE_H
#define __BASE_H

#define WIN_TITLE "RDBootUI2"

class MainApp: public wxApp
{
    public:
        virtual bool OnInit();
};

class MainFrame: public wxFrame
{
    public:
        MainFrame( const wxString &title, const wxPoint &pos, const wxSize &size );

/* Buttons */
        wxButton *btnOpen;
        wxButton *btnProgram;
        wxButton *btnAuto;
        wxButton *btnDevice;

/* MenuBar */        
        wxMenuBar* MainMenu;

/* Strings */
        wxString CurrentDocPath;

/* Functions */
        void OpenFile(wxCommandEvent& event);
        void OnExit( wxCommandEvent& event );

        DECLARE_EVENT_TABLE()
};

enum
{
    BUTTON_Hello = wxID_HIGHEST + 1, // declares an id which will be used to call our button
    MENU_Open
};

#endif
