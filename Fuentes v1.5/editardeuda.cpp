#include "editardeuda.h"
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/icon.h>


editardeuda::editardeuda(wxWindow *parent,deudor deu) : MyDialog7(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
	esdeuda=true;
	labelmodificaciones->Hide();
	textomodificaciones->Hide();
	textonombre->SetValue(deu.vernombre());
	textoapellido->SetValue(deu.verapellido());
	textodesc->SetValue(deu.verdescripcion());
	textomonto->SetValue(wxString::Format(wxT("%f"),deu.vermonto()));
	textodia->SetValue(wxString::Format(wxT("%i"),deu.verdia()));
	textomes->SetValue(wxString::Format(wxT("%i"),deu.vermes()));
	textoanio->SetValue(wxString::Format(wxT("%i"),deu.veranio()));
}

editardeuda::editardeuda(wxWindow *parent,cliente cli) : MyDialog7(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
	esdeuda=false;
	labelmodificaciones->Show();
	textomodificaciones->Show();
	SetTitle("Editar producto a entregar");
	textonombre->SetValue(cli.vernombre());
	textoapellido->SetValue(cli.verapellido());
	textodesc->SetValue(cli.verdetalle());
	textomonto->SetValue(wxString::Format(wxT("%f"),cli.vermonto()));
	textomodificaciones->SetValue(cli.vermodificaciones());
	textodia->SetValue(wxString::Format(wxT("%i"),cli.verdia()));
	textomes->SetValue(wxString::Format(wxT("%i"),cli.vermes()));
	textoanio->SetValue(wxString::Format(wxT("%i"),cli.veranio()));
}


void editardeuda::clickaceptar( wxCommandEvent& event )  {
	if (esdeuda==true){
		wxString mystring;
		string aux;
		mystring=textonombre->GetValue();
		aux=std::string(mystring.mb_str());
		d.modnombre(aux);
		mystring=textoapellido->GetValue();
		aux=std::string(mystring.mb_str());
		d.modapellido(aux);
		mystring=textodesc->GetValue();
		d.moddescripcion(mystring);
		d.modmonto(atof(textomonto->GetValue()));
		d.moddia(atoi(textodia->GetValue()));
		d.modmes(atoi(textomes->GetValue()));
		d.modanio(atoi(textoanio->GetValue()));
		string errores= d.ValidarDatos();
		if (errores.size()){
			wxMessageBox(errores,"Error",wxOK);
		}
		else {
			EndModal(1);
		}
	}
	else{
		wxString mystring;
		string aux;
		mystring=textonombre->GetValue();
		aux=std::string(mystring.mb_str());
		c.modnombre(aux);
		mystring=textoapellido->GetValue();
		aux=std::string(mystring.mb_str());
		c.modapellido(aux);
		mystring=textodesc->GetValue();
		c.moddetalles(mystring);
		c.modmonto(atof(textomonto->GetValue()));
		c.modmodificaciones(textomodificaciones->GetValue());
		c.moddia(atoi(textodia->GetValue()));
		c.modmes(atoi(textomes->GetValue()));
		c.modanio(atoi(textoanio->GetValue()));
		string errores= c.ValidarDatos();
		if (errores.size()){
			wxMessageBox(errores,"Error",wxOK);
		}
		else {
			EndModal(1);
		}
	}
	
}

void editardeuda::clickcancelar( wxCommandEvent& event )  {
	EndModal(0);
}

deudor editardeuda::verdeudor(){
	return d;
}

cliente editardeuda::vercliente(){
	return c;
}

editardeuda::~editardeuda() {
	
}

void editardeuda::enteraceptar( wxCommandEvent& event )  {
	clickaceptar(event);
}

