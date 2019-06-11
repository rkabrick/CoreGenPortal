//
// _COREINFOWIN_CPP_
//
// Copyright (C) 2017-2019 Tactical Computing Laboratories, LLC
// All Rights Reserved
// contact@tactcomplabs.com
//
// See LICENSE in the top level directory for licensing details
//

#include "CoreGenPortal/PortalCore/CoreInfoWin.h"

CoreInfoWin::CoreInfoWin( wxWindow *parent,
                          wxWindowID id,
                          CoreGenNode *Node ){
  if( Node->GetType() == CGSoc ){
    CoreSocInfoWin *Win = new CoreSocInfoWin( parent, id,
                                              wxString(Node->GetName()),
                                              static_cast<CoreGenSoC *>(Node) );
    Win->ShowModal();
    delete Win;
  }else if( Node->GetType() == CGCore ){
    CoreCoreInfoWin *Win = new CoreCoreInfoWin( parent, id,
                                                wxString(Node->GetName()),
                                                static_cast<CoreGenCore *>(Node) );
    Win->ShowModal();
    delete Win;
  }else if( Node->GetType() == CGInstF ){
    CoreInstFormatInfoWin *Win = new CoreInstFormatInfoWin(parent, id,
                                                           wxString(Node->GetName()),
                                                           static_cast<CoreGenInstFormat *>(Node));
    Win->ShowModal();
    delete Win;
  }else if( Node->GetType() == CGInst ){
    CoreInstInfoWin *Win = new CoreInstInfoWin( parent, id,
                                                wxString(Node->GetName()),
                                                static_cast<CoreGenInst *>(Node) );
    Win->ShowModal();
    delete Win;
  }else if( Node->GetType() == CGPInst ){
    CorePInstInfoWin *Win = new CorePInstInfoWin( parent, id,
                                                  wxString(Node->GetName()),
                                                  static_cast<CoreGenPseudoInst *>(Node) );
    Win->ShowModal();
    delete Win;
  }else if( Node->GetType() == CGRegC ){
    CoreRegClassInfoWin *Win = new CoreRegClassInfoWin( parent, id,
                                                  wxString(Node->GetName()),
                                                  static_cast<CoreGenRegClass *>(Node) );
    Win->ShowModal();
    delete Win;
  }else if( Node->GetType() == CGReg ){
    CoreRegInfoWin *Win = new CoreRegInfoWin( parent, id,
                                              wxString(Node->GetName()),
                                              static_cast<CoreGenReg *>(Node) );
    Win->ShowModal();
    delete Win;
  }else if( Node->GetType() == CGISA ){
    CoreISAInfoWin *Win = new CoreISAInfoWin( parent, id,
                                              wxString(Node->GetName()),
                                              static_cast<CoreGenISA *>(Node) );
    Win->ShowModal();
    delete Win;
  }else if( Node->GetType() == CGCache ){
    CoreCacheInfoWin *Win = new CoreCacheInfoWin( parent, id,
                                              wxString(Node->GetName()),
                                              static_cast<CoreGenCache *>(Node) );
    Win->ShowModal();
    delete Win;
  }else if( Node->GetType() == CGEnc ){
    CoreEncodingInfoWin *Win = new CoreEncodingInfoWin( parent, id,
                                              wxString(Node->GetName()),
                                              static_cast<CoreGenEncoding *>(Node) );
    Win->ShowModal();
    delete Win;
  }else if( Node->GetType() == CGExt ){
  }else if( Node->GetType() == CGComm ){
  }else if( Node->GetType() == CGSpad ){
  }else if( Node->GetType() == CGMCtrl ){
  }else if( Node->GetType() == CGVTP ){
  }else if( Node->GetType() == CGPlugin ){
  }
}

CoreInfoWin::~CoreInfoWin(){
}

// EOF
