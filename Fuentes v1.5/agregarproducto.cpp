#include "agregarproducto.h"
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/icon.h>

agregarproducto::agregarproducto(wxWindow *parent) : MyDialog8(parent) {
	SetTitle("Agregar producto");
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
}

agregarproducto::agregarproducto(wxWindow *parent,producto p) : MyDialog8(parent) {
	SetTitle("Modificar producto");
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
	wxString mystring;
	textonombre->SetValue(p.vernombre());
	mystring=wxString::Format(wxT("%i"),p.vercantidad());
	textocantidad->SetValue(mystring);
	mystring=wxString::Format(wxT("%i"),p.vercodigo());
	textocodigo->SetValue(mystring);
	mystring=wxString::Format(wxT("%f"),p.vercosto());
	textocosto->SetValue(mystring);
	textoobservacion->SetValue(p.verobservacion());
	mystring=wxString::Format(wxT("%i"),p.verdia());
	textodia->SetValue(mystring);
	mystring=wxString::Format(wxT("%i"),p.vermes());
	textomes->SetValue(mystring);
	mystring=wxString::Format(wxT("%i"),p.veranio());
	textoanio->SetValue(mystring);
}

agregarproducto::agregarproducto(wxWindow *parent,producto p, bool esventa) : MyDialog8(parent) {
	SetTitle("Modificar producto");
	wxString mystring;
	textonombre->SetValue(p.vernombre());
	mystring=wxString::Format(wxT("%i"),p.vercantidad());
	textocantidad->SetValue(mystring);
	mystring=wxString::Format(wxT("%i"),p.vercodigo());
	textocodigo->SetValue(mystring);
	mystring=wxString::Format(wxT("%f"),p.vercosto());
	textocosto->SetValue(mystring);
	textoobservacion->SetValue(p.verobservacion());
	mystring=wxString::Format(wxT("%i"),p.verdia());
	textodia->SetValue(mystring);
	textodia->Disable();
	mystring=wxString::Format(wxT("%i"),p.vermes());
	textomes->SetValue(mystring);
	textomes->Disable();
	mystring=wxString::Format(wxT("%i"),p.veranio());
	textoanio->SetValue(mystring);
	textoanio->Disable();
	textocantidad->Disable();
}

agregarproducto::~agregarproducto() {
	
}
void agregarproducto::clickagregar( wxCommandEvent& event ) {
	wxString mystring;
	string aux;
	mystring=textonombre->GetValue();
	aux=std::string(mystring.mb_str());
	p.modificadnombre(aux);
	p.modificarcantidad(atoi(textocantidad->GetValue()));
	p.modificarcodigo(atoi(textocodigo->GetValue()));
	p.modificarcosto(atof(textocosto->GetValue()));
	mystring=textoobservacion->GetValue();
	aux=std::string(mystring.mb_str());
	p.modificarobservacion(aux);
	p.modificardia(atoi(textodia->GetValue()));
	p.modificarmes(atoi(textomes->GetValue()));
	p.modificaranio(atoi(textoanio->GetValue()));
	string errores= p.ValidarDatos();
	if (errores.size()){
		wxMessageBox(errores,"Error",wxOK);
	}
	else {
		EndModal(1);
	}
}

producto agregarproducto::verprod(){
	return p;
}

void agregarproducto::clickcancelar( wxCommandEvent& event )  {
	EndModal(0);
}

void agregarproducto::checksaldoon( wxCommandEvent& event )  {
	event.Skip();
}

void agregarproducto::enteraceptar( wxCommandEvent& event )  {
	clickagregar(event);
}

void agregarproducto::clickaceptar( wxCommandEvent& event )  {
	event.Skip();
}

