#include "agregargasto.h"
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/icon.h>
#include <wx/datetime.h>

agregargasto::agregargasto(wxWindow *parent) : MyDialog10(parent) {
	SetTitle("Agregar gasto");
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
}

agregargasto::agregargasto(wxWindow *parent,gasto aux) : MyDialog10(parent) {
	SetTitle("Modificar gasto");
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
	wxString mystring;
	textodesc->SetValue(aux.verdesc());
	mystring=wxString::Format(wxT("%f"),aux.vercosto());
	textocosto->SetValue(mystring);
	mystring=wxString::Format(wxT("%i"),aux.verdia());
	textodia->SetValue(mystring);
	mystring=wxString::Format(wxT("%i"),aux.vermes());
	textomes->SetValue(mystring);
	mystring=wxString::Format(wxT("%i"),aux.veranio());
	textoanio->SetValue(mystring);
}

agregargasto::~agregargasto() {
	
}

void agregargasto::clickaceptar( wxCommandEvent& event )  {
	wxString mystring;
	string aux;
	mystring=textodesc->GetValue();
	aux=std::string(mystring.mb_str());
	g.modificardesc(aux);
	g.modificarcosto(atof(textocosto->GetValue()));
	g.modificardia(atoi(textodia->GetValue()));
	g.modificarmes(atoi(textomes->GetValue()));
	g.modificaranio(atoi(textoanio->GetValue()));
	string errores= g.ValidarDatos();
	if (errores.size()){
		wxMessageBox(errores,"Error",wxOK);
	}
	else {
		EndModal(1);
	}
}

void agregargasto::clickcancelar( wxCommandEvent& event )  {
	EndModal(0);
}

gasto agregargasto::vergasto(){
	return g;
}


void agregargasto::enteraceptar( wxCommandEvent& event )  {
	clickaceptar(event);
}

