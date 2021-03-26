#include "nombredeudor.h"
#include <wx/icon.h>
#include <wx/string.h>
#include <wx/msgdlg.h>

nombredeudor::nombredeudor(wxWindow *parent) : MyDialog81(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
}

nombredeudor::~nombredeudor() {
	
}

void nombredeudor::clickaceptar( wxCommandEvent& event )  {
	if (checksaldo->IsEnabled()){
		if (textosaldo->GetValue()<0){
			wxMessageBox("El saldo debe ser un numero positivo","Error",wxOK);
		}
		else{
			saldo=atof(textosaldo->GetValue());
		}
	}
	else saldo=0;
	wxString aux=textonombre->GetValue();
	nombre = std::string(aux.mb_str());
	aux=textoapellido->GetValue();
	apellido=std::string(aux.mb_str());
	EndModal(1);
}

string nombredeudor::vernombre(){
	return nombre;
}

string nombredeudor::verapellido(){
	return apellido;
}

float nombredeudor::versaldo(){
	return saldo;
}

void nombredeudor::clickcancelar( wxCommandEvent& event )  {
	EndModal(0);
}

void nombredeudor::enteragregar( wxCommandEvent& event )  {
	clickaceptar(event);
}

void nombredeudor::checksaldoon( wxCommandEvent& event )  {
	if (checksaldo->IsChecked()){
		textosaldo->Enable();
	}
	else{
		textosaldo->Disable();
	}
}

void nombredeudor::enteraceptar( wxCommandEvent& event )  {
	clickaceptar(event);
}

