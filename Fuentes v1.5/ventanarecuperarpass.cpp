#include "ventanarecuperarpass.h"
#include <wx/msgdlg.h>

ventanarecuperarpass::ventanarecuperarpass(wxWindow *parent) : MyDialog17(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
}

ventanarecuperarpass::~ventanarecuperarpass() {
	
}

void ventanarecuperarpass::clickverificar( wxCommandEvent& event )  {
	if (nuevouser.verresp()!=textorespuesta->GetValue().c_str()) wxMessageBox("La respuesta es incorrecta","Error",wxOK);
	else{
		labelpregunta->Hide();
		textorespuesta->Hide();
		botonver->Hide();
		labelpass->Show();
		textopass->Show();
		textopass->SetValue(nuevouser.verpass());
		Layout();
	}
}

void ventanarecuperarpass::clickfinalizar( wxCommandEvent& event )  {
	EndModal(1);
}

void ventanarecuperarpass::clickbuscar( wxCommandEvent& event )  {
	int resp=nueva_lista.buscaruser(textousuario->GetValue().c_str());
	if (resp==-1) wxMessageBox("El usuario no existe","Error",wxOK);
	else{
		nuevouser=nueva_lista.accederusuario(resp);
		labelingrese->Hide();
		textousuario->Hide();
		botonbuscar->Hide();
		labelpregunta->Show();
		textorespuesta->Show();
		botonver->Show();
		labelpregunta->SetLabel(nueva_lista.verpregunta(nuevouser.verpreg()));
		Layout();
		event.Skip();
	}
}
