#include "descuento.h"
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/icon.h>

descuento::descuento(wxWindow *parent) : MyDialog1(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
}

descuento::~descuento() {
}

void descuento::clickaceptar( wxCommandEvent& event )  {
	if (textodescuento->GetValue()<0){
		wxMessageBox("El descuento debe ser un numero positivo","Error",wxOK);
	}
	else{
		int resp=wxMessageBox("Al aplicar descuento se considerara cerrada y finalizada la venta, asegurese que todos los productos hayan sido ingresados - ¿Seguro desea aplicar el descuento?","Atención",wxYES_NO);
		if (resp==wxYES){
			wxString mystring=textodescuento->GetValue();
			desc=wxAtoi(mystring);
			EndModal(1);
		}
		else{
			EndModal(0);
		}
	}
}

int descuento::ver_desc(){
	return desc;
}

void descuento::clickcancelar( wxCommandEvent& event )  {
	EndModal(0);
}

void descuento::enteraceptar( wxCommandEvent& event )  {
	clickaceptar(event);
}

void descuento::clickcrear( wxCommandEvent& event )  {
	event.Skip();
}

void descuento::cliclcancelar( wxCommandEvent& event )  {
	event.Skip();
}

