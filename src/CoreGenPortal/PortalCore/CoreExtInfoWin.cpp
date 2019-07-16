//
// _COREEXTINFOWIN_CPP_
//
// Copyright (C) 2017-2019 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#include "CoreGenPortal/PortalCore/CoreExtInfoWin.h"

// Event Table
wxBEGIN_EVENT_TABLE(CoreExtInfoWin, wxDialog)
  EVT_BUTTON(wxID_OK, CoreExtInfoWin::OnPressOk)
  EVT_TEXT_ENTER(wxID_ANY, CoreExtInfoWin::OnPressEnter)
wxEND_EVENT_TABLE()

CoreExtInfoWin::CoreExtInfoWin( wxWindow* parent,
                              wxWindowID id,
                              const wxString& title,
                              CoreGenExt *Ext )
  : wxDialog( parent, id, title, wxDefaultPosition,
              wxSize(500,200), wxDEFAULT_DIALOG_STYLE|wxVSCROLL ){
  if( Ext == nullptr ){
    this->EndModal(wxID_OK);
  }

  this->ExtNode = Ext;

  // init the internals
  this->SetLayoutAdaptationMode(wxDIALOG_ADAPTATION_MODE_ENABLED);
  this->SetSizeHints( wxDefaultSize, wxDefaultSize );

  // create the outer box sizer
  OuterSizer = new wxBoxSizer( wxVERTICAL );

  // create the scrolled window
  Wnd = new wxScrolledWindow(this,
                             wxID_ANY,
                             wxDefaultPosition,
                             wxDefaultSize,
                             0,
                             wxT("Scroll"));

  // create the inner sizer
  InnerSizer = new wxBoxSizer( wxVERTICAL );

  // add all the interior data
  //-- extension name
  ExtNameSizer = new wxBoxSizer( wxHORIZONTAL );
  ExtNameText = new wxStaticText( Wnd,
                                  wxID_ANY,
                                  wxT("Extension Name"),
                                  wxDefaultPosition,
                                  wxSize(160,-1),
                                  0 );
  ExtNameText->Wrap(-1);
  ExtNameSizer->Add( ExtNameText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0 );

  ExtNameCtrl = new wxTextCtrl( Wnd,
                                0,
                                wxString(Ext->GetName()),
                                wxDefaultPosition,
                                wxSize(320,25),
                                wxTE_PROCESS_ENTER,
                                wxDefaultValidator,
                                wxT("ExtName") );
  ExtNameSizer->Add( ExtNameCtrl, 0, wxALL, 0 );
  InnerSizer->Add( ExtNameSizer, 0, wxALIGN_CENTER|wxALL, 5);

  //-- extension type
  ExtTypeSizer = new wxBoxSizer( wxHORIZONTAL );
  ExtTypeText = new wxStaticText( Wnd,
                                  wxID_ANY,
                                  wxT("Extension Type"),
                                  wxDefaultPosition,
                                  wxSize(160,-1),
                                  0 );
  ExtTypeText->Wrap(-1);
  ExtTypeSizer->Add( ExtTypeText, 0, wxALIGN_CENTER_VERTICAL|wxALL, 0 );

  ExtTypeCtrl = new wxTextCtrl( Wnd,
                                1,
                                wxEmptyString,
                                wxDefaultPosition,
                                wxSize(320,25),
                                wxTE_PROCESS_ENTER,
                                wxDefaultValidator,
                                wxT("ExtType") );
  switch(Ext->GetType()){
  case CGExtTemplate:
    ExtTypeCtrl->AppendText(wxT("Template extension"));
    break;
  case CGExtModule:
    ExtTypeCtrl->AppendText(wxT("Module extension"));
    break;
  case CGExtComm:
    ExtTypeCtrl->AppendText(wxT("Communications extension"));
    break;
  case CGExtUnk:
  default:
    ExtTypeCtrl->AppendText(wxT("Unknown extension"));
    break;
  }
  ExtTypeSizer->Add( ExtTypeCtrl, 0, wxALL, 0 );
  InnerSizer->Add( ExtTypeSizer, 0, wxALIGN_CENTER|wxALL, 5);

  // add the static line
  FinalStaticLine = new wxStaticLine( Wnd,
                                      wxID_ANY,
                                      wxDefaultPosition,
                                      wxDefaultSize,
                                      wxLI_HORIZONTAL );
  InnerSizer->Add( FinalStaticLine, 1, wxEXPAND | wxALL, 5 );

  // setup all the buttons
  m_socbuttonsizer = new wxStdDialogButtonSizer();
  m_userOK = new wxButton( Wnd, wxID_OK );
  m_socbuttonsizer->AddButton( m_userOK );
  m_socbuttonsizer->Realize();
  InnerSizer->Add( m_socbuttonsizer, 1, wxEXPAND, 5 );

  Wnd->SetScrollbars(20,20,50,50);
  Wnd->SetSizer( InnerSizer );
  Wnd->SetAutoLayout(true);
  Wnd->Layout();

  // draw the dialog box until we get more info
  OuterSizer->Add(Wnd, 1, wxEXPAND | wxALL, 5 );
  this->SetSizer( OuterSizer );
  this->SetAutoLayout( true );
  this->Layout();
}

void CoreExtInfoWin::OnPressOk(wxCommandEvent& ok){
  this->EndModal(wxID_OK);
}

void CoreExtInfoWin::OnPressEnter(wxCommandEvent& enter){
  PortalMainFrame *PMF = (PortalMainFrame*)this->GetParent();
  PMF->OnPressEnter(enter, this->ExtNode, CGExt);
}

CoreExtInfoWin::~CoreExtInfoWin(){
}

// EOF
