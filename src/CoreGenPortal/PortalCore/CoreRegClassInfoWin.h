//
// _COREREGCLASSINFOWIN_H_
//
// Copyright (C) 2017-2020 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#ifndef _COREREGCLASSINFOWIN_H_
#define _COREREGCLASSINFOWIN_H_

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
#include <wx/scrolwin.h>

//-- COREGEN HEADERS
#include "CoreGen/CoreGenBackend/CoreGenBackend.h"

#include "CoreGenPortal/PortalMainFrame.h"

class CoreRegClassInfoWin : public wxDialog {
public:
  CoreRegClassInfoWin( wxWindow* parent,
                 wxWindowID id = wxID_ANY,
                 const wxString& title = wxT("RegClass Node"),
                 CoreGenRegClass *Node = nullptr);
  ~CoreRegClassInfoWin();

protected:
  CoreGenRegClass *RegClassNode;  ///< RegClassNode
  // window handlers
  wxScrolledWindow *Wnd;         ///< scrolling window handler

  // box sizers
  wxBoxSizer *OuterSizer;         ///< outer sizer
  wxBoxSizer *InnerSizer;         ///< inner sizer
  wxBoxSizer *RegClassNameSizer;  ///< regclass name sizer
  wxBoxSizer *ReadPortsSizer;     ///< read ports sizer
  wxBoxSizer *WritePortsSizer;    ///< write ports sizer
  wxBoxSizer *RegNameSizer;       ///< reg name sizer

  // static lines
  wxStaticLine* FinalStaticLine;  ///< final static line

  wxStaticText *RegClassNameText; ///< static text for SoC name
  wxStaticText *ReadPortsText;    ///< static text for read ports
  wxStaticText *WritePortsText;   ///< static text for write ports
  wxStaticText *RegNameText;      ///< static text for inst format

  wxTextCtrl *RegClassNameCtrl;   ///< instruction name
  wxTextCtrl *ReadPortsCtrl;      ///< number of read ports
  wxTextCtrl *WritePortsCtrl;     ///< number of write ports
  wxTextCtrl *RegNameCtrl;        ///< instruction format name

  // buttons
  wxStdDialogButtonSizer* m_socbuttonsizer;   ///< button sizer
  wxButton *m_userOK;                         ///< ok button
  wxButton *m_userSAVE;                       ///< save button

private:
  // Event handler functions
  /// Declares the event table
  wxDECLARE_EVENT_TABLE();

  /// handles the 'ok' button press
  void OnPressOk( wxCommandEvent& event );

  /// handles 'save' click
  void OnSave( wxCommandEvent& save );
};

#endif

// EOF
