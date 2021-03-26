#include "ventanacantidad.h"
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/icon.h>

ventanacantidad::ventanacantidad(wxWindow *parent) : MyDialog141(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
}

ventanacantidad::ventanacantidad(wxWindow *parent,int _cantoriginal) : MyDialog141(parent) {
	cantoriginal=_cantoriginal;
}

void ventanacantidad::clickaceptar( wxCommandEvent& event )  {
	cant=atoi(textocantidad->GetValue());
	if (cant>cantoriginal){
		wxMessageBox("La cantidad ingresada debe ser inferior a la cantidad que se tiene en el stock del producto. (" + wxString::Format(wxT("%i"),cantoriginal) +")","Error",wxOK);
	}
	else if (cant<0 || cant==0){
		wxMessageBox("La cantidad debe ser un número positivo","Error",wxOK);
	}
	else EndModal(1);
	
}

void ventanacantidad::clickcancelar( wxCommandEvent& event )  {
	EndModal(0);
}

int ventanacantidad::vercant(){
	return cant;
}

ventanacantidad::~ventanacantidad() {
	
}

void ventanacantidad::entertexto( wxCommandEvent& event )  {
	clickaceptar(event);
}

