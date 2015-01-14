/***************************************************************
 * Name:      _18_Text_EditorMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    Dmytro Frolov (dimaf@i.ua)
 * Created:   2015-01-11
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "_18_Text_EditorMain.h"

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild(wxVERSION_STRING);

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("-Windows");
#elif defined(__WXMAC__)
        wxbuild << _T("-Mac");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("-Unicode build");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}


BEGIN_EVENT_TABLE(_18_Text_Editor_Frame, wxFrame)
    EVT_CLOSE(_18_Text_Editor_Frame::OnClose)
    EVT_BUTTON(idBtnQuit, _18_Text_Editor_Frame::OnQuit)
    EVT_BUTTON(idBtnAbout, _18_Text_Editor_Frame::OnAbout)
    EVT_BUTTON(idBtnSave, _18_Text_Editor_Frame::OnSave)
    EVT_BUTTON(idBtnLoad, _18_Text_Editor_Frame::OnLoad)
    EVT_MENU(idMenuQuit, _18_Text_Editor_Frame::OnQuit)
    EVT_MENU(idMenuAbout, _18_Text_Editor_Frame::OnAbout)
    EVT_MENU(idMenuSave, _18_Text_Editor_Frame::OnSave)
    EVT_MENU(idMenuLoad, _18_Text_Editor_Frame::OnLoad)
END_EVENT_TABLE()

_18_Text_Editor_Frame::_18_Text_Editor_Frame(wxFrame *dlg, const wxString &title)
    : wxFrame(dlg, -1, title,wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE & ~(wxRESIZE_BORDER | wxMAXIMIZE_BOX))
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    //main box sizer
    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer(wxHORIZONTAL);

    //left part
    wxBoxSizer* bSizerLeft;
    bSizerLeft = new wxBoxSizer(wxVERTICAL);
    m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("Welcome To wxWidgets\nText editor"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText1->SetFont(wxFont(20, 74, 90, 90, false, wxT("Arial")));
    bSizerLeft->Add(m_staticText1, 0, wxEXPAND, 5);
    TextArea1 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(240, 100), wxTE_MULTILINE);
    TextArea1->SetDefaultStyle(wxTextAttr(*wxRED));
    TextArea1->AppendText("");
    bSizerLeft->Add(TextArea1, 0, wxALL, 5);

    //right part
    wxBoxSizer* bSizer2;
    bSizer2 = new wxBoxSizer(wxVERTICAL);

    BtnLoad = new wxButton(this, idBtnLoad, wxT("&Load"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(BtnLoad, 0, wxALL, 5);
    BtnSave = new wxButton(this, idBtnSave, wxT("&Save"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(BtnSave, 0, wxALL, 5);
    m_staticline1 = new wxStaticLine(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL);
    bSizer2->Add(m_staticline1, 0, wxALL|wxEXPAND, 5);
    BtnAbout = new wxButton(this, idBtnAbout, wxT("&About"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(BtnAbout, 0, wxALL, 5);
    BtnQuit = new wxButton(this, idBtnQuit, wxT("&Quit"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(BtnQuit, 0, wxALL, 5);

    //add main menu to Main frame
    wxMenuBar* mainMenu = new wxMenuBar();

    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(idMenuLoad,wxT("&Load"), wxT("Load file"));
    fileMenu->Append(idMenuSave,wxT("&Save"), wxT("Save file"));
    fileMenu->Append(idMenuQuit,wxT("E&xit"), wxT("Exit"));

    wxMenu* helpMenu = new wxMenu;
    helpMenu->Append(idMenuAbout, wxT("&About"), wxT("About the program"));

    mainMenu->Append(fileMenu, wxT("&File"));
    mainMenu->Append(helpMenu, wxT("&Help"));

    this->SetMenuBar(mainMenu);

    //add status bar to Main frame
    this->CreateStatusBar(2);
    this->SetStatusText(wxT("Edit some text file!"));

    // add left and right to Main
    bSizer1->Add(bSizerLeft, 0, wxEXPAND, 5);
    bSizer1->Add(bSizer2, 1, wxEXPAND, 5);
    this->SetSizer(bSizer1);
    this->Layout();
    bSizer1->Fit(this);
}


_18_Text_Editor_Frame::~_18_Text_Editor_Frame()
{
}

void _18_Text_Editor_Frame::OnSave(wxCommandEvent& event)
{
    wxString caption = wxT("Choose a file");
    wxString wildcard = wxT ("TXT files (*.txt)|*.txt|CPP files (*.cpp)|*.cpp");
    wxString defaultDir = wxT("c:\\");
    wxString defaultFilename = wxEmptyString;
    wxFileDialog frame(this, caption, defaultDir, defaultFilename, wildcard, wxFD_SAVE);
    if(frame.ShowModal()==wxID_OK){
        wxString path = frame.GetPath();
        int filterIndex = frame.GetFilterIndex();
        TextArea1->SaveFile(path);
    }
}

void _18_Text_Editor_Frame::OnLoad(wxCommandEvent& event)
{
    wxString caption = wxT("Choose a file");
    wxString wildcard = wxT ("TXT files (*.txt)|*.txt|CPP files (*.cpp)|*.cpp");
    wxString defaultDir = wxT("c:\\");
    wxString defaultFilename = wxEmptyString;
    wxFileDialog frame(this, caption, defaultDir, defaultFilename, wildcard, wxFD_OPEN);
    if(frame.ShowModal()==wxID_OK){
        wxString path = frame.GetPath();
        int filterIndex = frame.GetFilterIndex();
        TextArea1->LoadFile(path);
    }
}

void _18_Text_Editor_Frame::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void _18_Text_Editor_Frame::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void _18_Text_Editor_Frame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    msg+='\n'+TextArea1->GetValue();
    wxMessageBox(msg, _("Welcome to..."));
}


//TODO :
// - add change encoding
// - change UI
// - add syntax highlight
