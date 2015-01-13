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


BEGIN_EVENT_TABLE(_18_Text_Editor_Dialog, wxDialog)
    EVT_CLOSE(_18_Text_Editor_Dialog::OnClose)
    EVT_BUTTON(idBtnQuit, _18_Text_Editor_Dialog::OnQuit)
    EVT_BUTTON(idBtnAbout, _18_Text_Editor_Dialog::OnAbout)
    EVT_BUTTON(idBtnSave, _18_Text_Editor_Dialog::OnSave)
    EVT_BUTTON(idBtnLoad, _18_Text_Editor_Dialog::OnLoad)
END_EVENT_TABLE()

_18_Text_Editor_Dialog::_18_Text_Editor_Dialog(wxDialog *dlg, const wxString &title)
    : wxDialog(dlg, -1, title)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    wxBoxSizer* bSizer1; //all screen
    wxBoxSizer* bSizerLeft; //left part
    bSizerLeft = new wxBoxSizer(wxVERTICAL);
    bSizer1 = new wxBoxSizer(wxHORIZONTAL);
    m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("Welcome To wxWidgets\nText editor"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText1->SetFont(wxFont(20, 74, 90, 90, false, wxT("Arial")));
    bSizerLeft->Add(m_staticText1, 0, wxEXPAND, 5);
    TextArea1 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(240, 100), wxTE_MULTILINE);
    TextArea1->SetDefaultStyle(wxTextAttr(*wxRED));
    TextArea1->AppendText("Red text\n");
    bSizerLeft->Add(TextArea1, 0, wxALL, 5);
    bSizer1->Add(bSizerLeft, 0, wxEXPAND, 5);
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
    bSizer1->Add(bSizer2, 1, wxEXPAND, 5);
    this->SetSizer(bSizer1);
    this->Layout();
    bSizer1->Fit(this);
}


_18_Text_Editor_Dialog::~_18_Text_Editor_Dialog()
{
}

void _18_Text_Editor_Dialog::OnSave(wxCommandEvent& event)
{
    wxString caption = wxT("Choose a file");
    wxString wildcard = wxT ("TXT files (*.txt)|*.txt|CPP files (*.cpp)|*.cpp");
    wxString defaultDir = wxT("c:\\");
    wxString defaultFilename = wxEmptyString;
    wxFileDialog dialog(this, caption, defaultDir, defaultFilename, wildcard, wxFD_SAVE);
    if(dialog.ShowModal()==wxID_OK){
        wxString path = dialog.GetPath();
        int filterIndex = dialog.GetFilterIndex();
        TextArea1->SaveFile(path);
    }
}

void _18_Text_Editor_Dialog::OnLoad(wxCommandEvent& event)
{
    wxString caption = wxT("Choose a file");
    wxString wildcard = wxT ("TXT files (*.txt)|*.txt|CPP files (*.cpp)|*.cpp");
    wxString defaultDir = wxT("c:\\");
    wxString defaultFilename = wxEmptyString;
    wxFileDialog dialog(this, caption, defaultDir, defaultFilename, wildcard, wxFD_OPEN);
    if(dialog.ShowModal()==wxID_OK){
        wxString path = dialog.GetPath();
        int filterIndex = dialog.GetFilterIndex();
        TextArea1->LoadFile(path);
    }
}

void _18_Text_Editor_Dialog::OnClose(wxCloseEvent &event)
{
    Destroy();
}

void _18_Text_Editor_Dialog::OnQuit(wxCommandEvent &event)
{
    Destroy();
}

void _18_Text_Editor_Dialog::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    msg+='\n'+TextArea1->GetValue();
    wxMessageBox(msg, _("Welcome to..."));
}


//TODO :
// - add change encoding
// - change UI
// - add syntax highlight
