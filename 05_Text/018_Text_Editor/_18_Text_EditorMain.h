/***************************************************************
 * Name:      _18_Text_EditorMain.h
 * Purpose:   Defines Application Frame
 * Author:    Dmytro Frolov (dimaf@i.ua)
 * Created:   2015-01-11
 * Copyright: Dmytro Frolov ()
 * License:
 **************************************************************/

#ifndef _18_TEXT_EDITORMAIN_H
#define _18_TEXT_EDITORMAIN_H

#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

#include "_18_Text_EditorApp.h"


#include <wx/button.h>
#include <wx/statline.h>
class _18_Text_EditorDialog: public wxDialog
{
    public:
        _18_Text_EditorDialog(wxDialog *dlg, const wxString& title);
        ~_18_Text_EditorDialog();

    protected:
        enum
        {
            idBtnQuit = 1000,
            idBtnAbout
        };
        wxStaticText* m_staticText1;
        wxButton* BtnAbout;
        wxStaticLine* m_staticline1;
        wxButton* BtnQuit;

    private:
        void OnClose(wxCloseEvent& event);
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        DECLARE_EVENT_TABLE()
};

#endif // _18_TEXT_EDITORMAIN_H
