/***************************************************************
 * Name:      _18_Text_EditorApp.cpp
 * Purpose:   Code for Application Class
 * Author:    Dmytro Frolov (dimaf@i.ua)
 * Created:   2015-01-11
 **************************************************************/

#ifdef WX_PRECOMP
#include "wx_pch.h"
#endif

#ifdef __BORLANDC__
#pragma hdrstop
#endif //__BORLANDC__

#include "_18_Text_EditorApp.h"
#include "_18_Text_EditorMain.h"

IMPLEMENT_APP(_18_Text_EditorApp);

bool _18_Text_EditorApp::OnInit()
{

    _18_Text_Editor_Dialog* dlg = new _18_Text_Editor_Dialog(0L, _("wxWidgets Text Editor"));
    dlg->SetIcon(wxICON(aaaa)); // To Set App Icon
    dlg->Show();
    return true;
}
