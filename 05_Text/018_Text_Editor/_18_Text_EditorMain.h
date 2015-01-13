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
class _18_Text_Editor_Dialog: public wxDialog
{
    public:
        _18_Text_Editor_Dialog(wxDialog *dlg, const wxString& title);
        ~_18_Text_Editor_Dialog();

    protected:
        enum
        {
            idBtnQuit = 1000,
            idBtnAbout,
            idBtnLoad,
            idBtnSave
        };
        wxStaticText* m_staticText1;
        wxButton* BtnAbout;
        wxButton* BtnLoad;
        wxButton* BtnSave;
        wxStaticLine* m_staticline1;
        wxStaticLine* m_staticline2;
        wxButton* BtnQuit;
        wxTextCtrl* TextArea1;

    private:
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnLoad(wxCommandEvent& event);
        void OnSave(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};

#endif // _18_Text_EditorMain_H
