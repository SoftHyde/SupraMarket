#include "nombrecompraconfecha.h"
#include <wx/msgdlg.h>
#include <wx/datetime.h>
#include <wx/string.h>
#include <wx/icon.h>

nombrecompraconfecha::nombrecompraconfecha(wxWindow *parent) : MyDialog11(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
}

nombrecompraconfecha::~nombrecompraconfecha() {
	
}


void nombrecompraconfecha::clickaceptar( wxCommandEvent& event )  {
	wxString aux=textonombre->GetValue();
	nombre = std::string(aux.mb_str());
	aux=textoapellido->GetValue();
	apellido=std::string(aux.mb_str());
	mod=textomodificaciones->GetValue();
	wxDateTime fecha=cosofecha->GetValue();
	dia=fecha.GetDay();
	mes=fecha.GetMonth();
	mes++;
	anio=fecha.GetYear();
	EndModal(1);
}

string nombrecompraconfecha::vernombre(){
	return nombre;
}

string nombrecompraconfecha::verapellido(){
	return apellido;
}

wxString nombrecompraconfecha::vermod(){
	return mod;
}

int nombrecompraconfecha::verdia(){
	return dia;
}
int nombrecompraconfecha::vermes(){
	return mes;
}
int nombrecompraconfecha::veranio(){
	return anio;
}

void nombrecompraconfecha::clickcancelar( wxCommandEvent& event )  {
	EndModal(0);
}

void nombrecompraconfecha::enteraceptar( wxCommandEvent& event )  {
	clickaceptar(event);
}

