#include "ventanacreacionprimeruser.h"
#include <wx/string.h>
#include <wx/icon.h>
#include <wx/msgdlg.h>

ventanacreacionprimeruser::ventanacreacionprimeruser(wxWindow *parent) : MyDialog15(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
}

void ventanacreacionprimeruser::clickbotonaceptar( wxCommandEvent& event )  {
	usuariosimple nuevo_user;
	nuevo_user.moduser(textouser->GetValue().c_str());
	nuevo_user.modpass(textopass->GetValue().c_str());
	nuevo_user.modpreg(choiserrespuesta->GetSelection());
	nuevo_user.modresp(textorespuesta->GetValue().c_str());
	string errores=nuevo_user.validardatos();
	if (errores.size()){
		wxMessageBox(errores,"Error",wxOK);
	}
	else{
		if (nueva_lista.guardarusuario(nuevo_user)==true){
			nueva_lista.guardar();
			EndModal(1);
		}
		else {
			wxMessageBox("El usuario ya existe. Por favor escoja otro nombre de ususario","Error", wxOK);
		}
	}
}

ventanacreacionprimeruser::~ventanacreacionprimeruser() {
	
}

void ventanacreacionprimeruser::enterpass( wxCommandEvent& event )  {
	clickbotonaceptar(event);
}

void ventanacreacionprimeruser::onbotoncerrar( wxCloseEvent& event )  {
	EndModal(0);
}

