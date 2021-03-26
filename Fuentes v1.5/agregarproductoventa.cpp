#include "agregarproductoventa.h"
#include <wx/msgdlg.h>
#include <wx/string.h>
#include <wx/icon.h>

agregarproductoventa::agregarproductoventa(wxWindow *parent) : MyDialog3(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
	grillaagregarproducto->SetSelectionMode(wxGrid::wxGridSelectRows);
	for (int i=0; i<nuevo_stock->cantprod();i++){
		grillaagregarproducto->AppendRows(1);
		grillaagregarproducto->SetCellValue(nuevo_stock->accederprod(i).vernombre(),i,0);
		mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vercantidad()));
		grillaagregarproducto->SetCellValue(mystring,i,1);
		mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vercodigo()));
		grillaagregarproducto->SetCellValue(mystring,i,2);
		mystring=wxString::Format(wxT("%f"),(nuevo_stock->accederprod(i).vercosto()));
		grillaagregarproducto->SetCellValue(mystring,i,3);
		grillaagregarproducto->SetCellValue(wxString::Format(wxT("%i"),nuevo_stock->accederprod(i).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).veranio())),i,4);
		grillaagregarproducto->SetCellValue(nuevo_stock->accederprod(i).verobservacion(),i,5);
		if (nuevo_stock->accederprod(i).vercantidad()<10 && nuevo_stock->accederprod(i).vercantidad()!=0){
			grillaagregarproducto->SetCellBackgroundColour(i,0, *wxCYAN);
			grillaagregarproducto->SetCellBackgroundColour(i,1, *wxCYAN);
			grillaagregarproducto->SetCellBackgroundColour(i,2, *wxCYAN);
			grillaagregarproducto->SetCellBackgroundColour(i,3, *wxCYAN);
			grillaagregarproducto->SetCellBackgroundColour(i,4, *wxCYAN);
			grillaagregarproducto->SetCellBackgroundColour(i,5, *wxCYAN);
		}
		else if (nuevo_stock->accederprod(i).vercantidad()==0){
			grillaagregarproducto->SetCellBackgroundColour(i,0, *wxRED);
			grillaagregarproducto->SetCellBackgroundColour(i,1, *wxRED);
			grillaagregarproducto->SetCellBackgroundColour(i,2, *wxRED);
			grillaagregarproducto->SetCellBackgroundColour(i,3, *wxRED);
			grillaagregarproducto->SetCellBackgroundColour(i,4, *wxRED);
			grillaagregarproducto->SetCellBackgroundColour(i,5, *wxRED);
		}
		else{
			grillaagregarproducto->SetCellBackgroundColour(i,0, *wxWHITE);
			grillaagregarproducto->SetCellBackgroundColour(i,1, *wxWHITE);
			grillaagregarproducto->SetCellBackgroundColour(i,2, *wxWHITE);
			grillaagregarproducto->SetCellBackgroundColour(i,3, *wxWHITE);
			grillaagregarproducto->SetCellBackgroundColour(i,4, *wxWHITE);
			grillaagregarproducto->SetCellBackgroundColour(i,5, *wxWHITE);
		}
	}
}

agregarproductoventa::~agregarproductoventa() {
	
}

void agregarproductoventa::buscaronfly( wxCommandEvent& event )  {
	vector<int> vecpos;
	manejostock *nuevo_stock=Singletonstock::ObtenerInstancia();
	nuevo_stock->buscar(buscadorcod->GetValue().c_str(),vecpos);
	grillaagregarproducto->DeleteRows(0,nuevo_stock->cantprod());
	grillaagregarproducto->AppendRows(vecpos.size());
	for(unsigned int i=0; i<vecpos.size();i++){
		grillaagregarproducto->SetCellValue(nuevo_stock->accederprod(*(vecpos.begin()+i)).vernombre(),i,0);
		mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(*(vecpos.begin()+i)).vercantidad()));
		grillaagregarproducto->SetCellValue(mystring,i,1);
		mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(*(vecpos.begin()+i)).vercodigo()));
		grillaagregarproducto->SetCellValue(mystring,i,2);
		mystring=wxString::Format(wxT("%f"),(nuevo_stock->accederprod(*(vecpos.begin()+i)).vercosto()));
		grillaagregarproducto->SetCellValue(mystring,i,3);
		grillaagregarproducto->SetCellValue(wxString::Format(wxT("%i"),nuevo_stock->accederprod(*(vecpos.begin()+i)).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(*(vecpos.begin()+i)).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(*(vecpos.begin()+i)).veranio())),i,4);
		grillaagregarproducto->SetCellValue(nuevo_stock->accederprod(*(vecpos.begin()+i)).verobservacion(),i,5);
	}
}

void agregarproductoventa::clickbotoncancelar( wxCommandEvent& event )  {
	EndModal(0);
}

void agregarproductoventa::clickbotonagregar( wxCommandEvent& event )  {
	manejostock *nuevo_stock=Singletonstock::ObtenerInstancia();
	if (nuevo_stock->cantprod()==0){
		wxMessageBox("No se selecciono ningún producto","Error", wxOK);
	}
	else{
		p=nuevo_stock->accederprod(grillaagregarproducto->GetGridCursorRow());
		EndModal(1);
	}
}

producto agregarproductoventa::verprod(){
	return p;
}

int agregarproductoventa::verfilastock(){
	return grillaagregarproducto->GetGridCursorRow();
}

void agregarproductoventa::clickcancelar( wxCommandEvent& event )  {
	buscadorcod->Clear();
}

