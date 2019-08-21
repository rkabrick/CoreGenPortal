//
// _CORESPECDOCWIN_H_
//
// Copyright (C) 2017-2019 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#ifndef _CORESPECDOCWIN_H_
#define _CORESPECDOCWIN_H_

//-- WX HEADERS
#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/listbox.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/sizer.h>
#include <wx/dirctrl.h>
#include <wx/aui/auibook.h>
#include <wx/stattext.h>
#include <wx/frame.h>
#include <wx/panel.h>
#include <wx/textctrl.h>
#include <wx/choice.h>
#include <wx/statline.h>
#include <wx/button.h>
#include <wx/dialog.h>
#include <wx/checkbox.h>
#include <wx/msgdlg.h>
#include <wx/textctrl.h>
#include <wx/richtext/richtextctrl.h>

#include <string>
#include <sstream>

class CoreSpecDocWin : public wxDialog {
public:
  CoreSpecDocWin( wxWindow* parent,
                wxWindowID id = wxID_ANY,
                const wxString& title = wxT("Specification Document Build"),
                std::ostringstream *SpecDocBuf = nullptr );
  ~CoreSpecDocWin();

protected:
  // window handlers
  wxScrolledWindow *Wnd;          ///< scrolling window handler

  // static lines
  wxStaticLine* FinalStaticLine;  ///< final static line

  // box sizers
  wxBoxSizer *OuterSizer;         ///< outer sizer
  wxBoxSizer *InnerSizer;         ///< inner sizer
  wxBoxSizer *SpecDocWinSizer;    ///< Statistics window sizer

  wxRichTextCtrl *SpecDocResults; ///< statistics results

  // buttons
  wxStdDialogButtonSizer* m_socbuttonsizer;   ///< button sizer
  wxButton *m_userOK;                         ///< ok button

private:
  // Event handler functions
  /// Declares the event table
  wxDECLARE_EVENT_TABLE();

  /// handles the 'ok' button press
  void OnPressOk( wxCommandEvent& event );
};

#endif

// EOF
