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
    EVT_SIZE(_18_Text_Editor_Frame::OnSize)
    EVT_CLOSE(_18_Text_Editor_Frame::OnClose)
    EVT_BUTTON(idBtnQuit, _18_Text_Editor_Frame::OnQuit)
    EVT_BUTTON(idBtnNew, _18_Text_Editor_Frame::OnNew)
    EVT_BUTTON(idBtnSave, _18_Text_Editor_Frame::OnSave)
    EVT_BUTTON(idBtnLoad, _18_Text_Editor_Frame::OnLoad)
    EVT_MENU(idMenuQuit, _18_Text_Editor_Frame::OnQuit)
    EVT_MENU(idMenuAbout, _18_Text_Editor_Frame::OnAbout)
    EVT_MENU(idMenuSave, _18_Text_Editor_Frame::OnSave)
    EVT_MENU(idMenuLoad, _18_Text_Editor_Frame::OnLoad)
    EVT_MENU(idMenuNew, _18_Text_Editor_Frame::OnNew)
END_EVENT_TABLE()

_18_Text_Editor_Frame::_18_Text_Editor_Frame(wxFrame *dlg, const wxString &title)
    : wxFrame(dlg, -1, title,wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE)
{
    this->SetSizeHints(wxDefaultSize, wxDefaultSize);

    //main box sizer
    wxBoxSizer* bSizer1;
    bSizer1 = new wxBoxSizer(wxHORIZONTAL);

    //left part begin
    wxBoxSizer* bSizerLeft;
    bSizerLeft = new wxBoxSizer(wxVERTICAL);
    m_staticText1 = new wxStaticText(this, wxID_ANY, wxT("wxWidgets Text editor"), wxDefaultPosition, wxDefaultSize, 0);
    m_staticText1->SetFont(wxFont(20, 74, 90, 90, false, wxT("Arial")));
    bSizerLeft->Add(m_staticText1, 0, wxEXPAND, 5);

    //top buttons
    wxBoxSizer* bSizer2;
    bSizer2 = new wxBoxSizer(wxHORIZONTAL);

    BtnNew = new wxButton(this, idBtnNew, wxT("&New file"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(BtnNew, 0, wxALL, 5);
    BtnLoad = new wxButton(this, idBtnLoad, wxT("&Load"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(BtnLoad, 0, wxALL, 5);
    BtnSave = new wxButton(this, idBtnSave, wxT("&Save"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(BtnSave, 0, wxALL, 5);
    BtnQuit = new wxButton(this, idBtnQuit, wxT("&Quit"), wxDefaultPosition, wxDefaultSize, 0);
    bSizer2->Add(BtnQuit, 0, wxALL, 5);

    bSizerLeft->Add(bSizer2, 0, wxEXPAND, 1);

    TextArea1 = new wxTextCtrl(this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxSize(340, 100), wxTE_MULTILINE);
    TextArea1->SetDefaultStyle(wxTextAttr(*wxRED));
    TextArea1->AppendText("");
    bSizerLeft->Add(TextArea1, 0, wxALL, 1);


    //add main menu to Main frame
    wxMenuBar* mainMenu = new wxMenuBar();

    wxMenu* fileMenu = new wxMenu;
    fileMenu->Append(idMenuNew,wxT("&New file"), wxT("New file"));
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

    //TextArea1->SetDefaultStyle();

    // add left and right to Main
    bSizer1->Add(bSizerLeft, 0, wxEXPAND, 5);
    this->SetSizer(bSizer1);
    this->Layout();
    bSizer1->Fit(this);
}


_18_Text_Editor_Frame::~_18_Text_Editor_Frame()
{
}

void _18_Text_Editor_Frame::OnNew(wxCommandEvent& event){
    int ans = this->isEmptyOnClose();
    if(!ans){
        TextArea1->Clear();
    }
}

void _18_Text_Editor_Frame::OnLoad(wxCommandEvent& event)
{
    int ans = this->isEmptyOnClose();
    if(!ans){
        wxString caption = wxT("Choose a file");
        wxString wildcard = wxT ("TXT files (*.txt)|*.txt|CPP files (*.cpp)|*.cpp");
        wxString defaultDir = wxT("c:\\");
        wxString defaultFilename = wxEmptyString;
        wxFileDialog frame(this, caption, defaultDir, defaultFilename, wildcard, wxFD_OPEN);
        if(frame.ShowModal()==wxID_OK){
            wxString path = frame.GetPath();
            //int filterIndex = frame.GetFilterIndex();
            TextArea1->LoadFile(path);
        }
    }
}

void _18_Text_Editor_Frame::OnSave(wxCommandEvent& event)
{
    this->saveFile();
}

int _18_Text_Editor_Frame::saveFile(){
    wxString caption = wxT("Choose a file");
    wxString wildcard = wxT ("TXT files (*.txt)|*.txt|CPP files (*.cpp)|*.cpp");
    wxString defaultDir = wxT("c:\\");
    wxString defaultFilename = wxEmptyString;
    wxFileDialog frame(this, caption, defaultDir, defaultFilename, wildcard, wxFD_SAVE);
    if(frame.ShowModal()==wxID_OK){
        wxString path = frame.GetPath();
        //int filterIndex = frame.GetFilterIndex();
        bool saveFileAns = TextArea1->SaveFile(path);
        if(saveFileAns==true)return 0;
    }
    return 1;
}


void _18_Text_Editor_Frame::OnClose(wxCloseEvent &event)
{
    wxCommandEvent closeEvent;
    this->OnQuit(closeEvent);
}

void _18_Text_Editor_Frame::OnQuit(wxCommandEvent &event)
{
    int ans = this->isEmptyOnClose();
    if(!ans){
        Destroy();
    }
}

void _18_Text_Editor_Frame::OnAbout(wxCommandEvent &event)
{
    wxString msg = wxbuildinfo(long_f);
    msg+='\n'+TextArea1->GetValue();
    wxMessageBox(msg, _("Welcome to..."));
}

void _18_Text_Editor_Frame::OnSize(wxSizeEvent &event)
{
wxSize newSize = event.GetSize();
//wxString textToAppend = wxString::Format(wxT("%i"),newSize.GetWidth());
//textToAppend+=" "+wxString::Format(wxT("%i"),newSize.GetHeight())+'\n';
TextArea1->SetSize(wxSize(newSize.GetWidth()-10,newSize.GetHeight()-135));
//TextArea1->AppendText(textToAppend);//+" "+wxT(newSize.GetHeight())+"\n");
}

int _18_Text_Editor_Frame::isEmptyOnClose(){
    if(!TextArea1->IsEmpty()){
        int answer = wxMessageBox("Do you want to save changes?", "Confirm",
            wxYES_NO | wxCANCEL);
        wxCommandEvent saveEvent;
        if (answer == wxYES){
            int saveAns = this->saveFile();
            if(!saveAns){
                return 0;
            }else return 1;
        }
        if(answer== wxCANCEL)return 1;
    }
    return 0;
}
//TODO :
// - add change encoding
// - change UI
// - add syntax highlight
