#include "ventananuevouser.h"
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/icon.h>

ventananuevouser::ventananuevouser(wxWindow *parent) : MyDialog14(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
}

void ventananuevouser::clickcrear( wxCommandEvent& event )  {
	usuariosimple nuevo_user;
	nuevo_user.moduser(textouser->GetValue().c_str());
	nuevo_user.modpass(textopass->GetValue().c_str());
	nuevo_user.modpreg(choiserpreg->GetSelection());
	nuevo_user.modresp(textoresp->GetValue().c_str());
	string errores= nuevo_user.validardatos();
	if (errores.size()){
		wxMessageBox(errores,"Error",wxOK);
	}
	else {
		if (nueva_lista.guardarusuario(nuevo_user)==true){
			nueva_lista.guardar();
			EndModal(1);
		}
		else {
			wxMessageBox("El usuario ya existe. Por favor escoja otro nombre de ususario","Error", wxOK);
		}
	}
}

void ventananuevouser::cliclcancelar( wxCommandEvent& event )  {
	EndModal(0);
}

ventananuevouser::~ventananuevouser() {
	
}

void ventananuevouser::enteraceptar( wxCommandEvent& event )  {
	clickcrear(event);
}

