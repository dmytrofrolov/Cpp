/***************************************************************
 * Name:      _18_Text_EditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Dmytro Frolov (dimaf@i.ua)
 * Created:   2015-01-11
 **************************************************************/

#ifndef _18_Text_EditorMain_H
#define _18_Text_EditorMain_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "_18_Text_EditorApp.h"


#include <wx/button.h>
#include <wx/statline.h>
class _18_Text_Editor_Frame: public wxFrame
{
    public:
        _18_Text_Editor_Frame(wxFrame *dlg, const wxString& title);
        ~_18_Text_Editor_Frame();

    protected:
        enum
        {
            idBtnQuit = 1000,
            idBtnNew,
            idBtnLoad,
            idBtnSave,

            idMenuNew,
            idMenuLoad,
            idMenuSave,
            idMenuQuit,
            idMenuAbout
        };
        wxStaticText* m_staticText1;
        wxButton* BtnNew;
        wxButton* BtnLoad;
        wxButton* BtnSave;
        wxStaticLine* m_staticline1;
        wxStaticLine* m_staticline2;
        wxButton* BtnQuit;
        wxTextCtrl* TextArea1;
        wxString fileName, filePath;

    private:
        void OnSize(wxSizeEvent& event);
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnNew(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnLoad(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        int saveFile();
        int isEmptyOnClose(); //if you want to close or load file, check if user want to save it
        DECLARE_EVENT_TABLE()
};

#endif // _18_Text_EditorMain_H
