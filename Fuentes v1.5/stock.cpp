#include "stock.h"
#include "agregarproducto.h"
#include <wx/msgdlg.h>
#include <wx/grid.h>
#include <wx/string.h>
#include <wx/icon.h>

stock::stock(wxWindow *parent) : MyDialog2(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
	guardado=true;
	grilla_stock->SetSelectionMode(wxGrid::wxGridSelectRows);
	for (int i=0; i<nuevo_stock->cantprod();i++){
		grilla_stock->AppendRows(1);
		grilla_stock->SetCellValue(nuevo_stock->accederprod(i).vernombre(),i,0);
		mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vercantidad()));
		grilla_stock->SetCellValue(mystring,i,1);
		mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vercodigo()));
		grilla_stock->SetCellValue(mystring,i,2);
		mystring=wxString::Format(wxT("%f"),(nuevo_stock->accederprod(i).vercosto()));
		grilla_stock->SetCellValue(mystring,i,3);
		grilla_stock->SetCellValue(wxString::Format(wxT("%i"),nuevo_stock->accederprod(i).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).veranio())),i,4);
		grilla_stock->SetCellValue(nuevo_stock->accederprod(i).verobservacion(),i,5);
		if (nuevo_stock->accederprod(i).vercantidad()<10 && nuevo_stock->accederprod(i).vercantidad()!=0){
			grilla_stock->SetCellBackgroundColour(i,0, *wxCYAN);
			grilla_stock->SetCellBackgroundColour(i,1, *wxCYAN);
			grilla_stock->SetCellBackgroundColour(i,2, *wxCYAN);
			grilla_stock->SetCellBackgroundColour(i,3, *wxCYAN);
			grilla_stock->SetCellBackgroundColour(i,4, *wxCYAN);
			grilla_stock->SetCellBackgroundColour(i,5, *wxCYAN);
		}
		else if (nuevo_stock->accederprod(i).vercantidad()==0){
			grilla_stock->SetCellBackgroundColour(i,0, *wxRED);
			grilla_stock->SetCellBackgroundColour(i,1, *wxRED);
			grilla_stock->SetCellBackgroundColour(i,2, *wxRED);
			grilla_stock->SetCellBackgroundColour(i,3, *wxRED);
			grilla_stock->SetCellBackgroundColour(i,4, *wxRED);
			grilla_stock->SetCellBackgroundColour(i,5, *wxRED);
		}
		else{
			grilla_stock->SetCellBackgroundColour(i,0, *wxWHITE);
			grilla_stock->SetCellBackgroundColour(i,1, *wxWHITE);
			grilla_stock->SetCellBackgroundColour(i,2, *wxWHITE);
			grilla_stock->SetCellBackgroundColour(i,3, *wxWHITE);
			grilla_stock->SetCellBackgroundColour(i,4, *wxWHITE);
			grilla_stock->SetCellBackgroundColour(i,5, *wxWHITE);
		}
	}
}

void stock::clickagregarstock( wxCommandEvent& event )  {
	agregarproducto nueva_ventana(this);
	if (nueva_ventana.ShowModal()==1){
		guardado=false;
		grilla_stock->AppendRows(1);
		nuevo_stock->agregar(nueva_ventana.verprod());
		pos=nuevo_stock->cantprod()-1;
		grilla_stock->SetCellValue(nuevo_stock->accederprod(pos).vernombre(),pos,0);
		mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(pos).vercantidad()));
		grilla_stock->SetCellValue(mystring,pos,1);
		mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(pos).vercodigo()));
		grilla_stock->SetCellValue(mystring,pos,2);
		mystring=wxString::Format(wxT("%f"),(nuevo_stock->accederprod(pos).vercosto()));
		grilla_stock->SetCellValue(mystring,pos,3);
		grilla_stock->SetCellValue(wxString::Format(wxT("%i"),nuevo_stock->accederprod(pos).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(pos).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(pos).veranio())),pos,4);
		grilla_stock->SetCellValue(nuevo_stock->accederprod(pos).verobservacion(),pos,5);
		if (nuevo_stock->accederprod(pos).vercantidad()<10 && nuevo_stock->accederprod(pos).vercantidad()!=0){
			grilla_stock->SetCellBackgroundColour(pos,0, *wxCYAN);
			grilla_stock->SetCellBackgroundColour(pos,1, *wxCYAN);
			grilla_stock->SetCellBackgroundColour(pos,2, *wxCYAN);
			grilla_stock->SetCellBackgroundColour(pos,3, *wxCYAN);
			grilla_stock->SetCellBackgroundColour(pos,4, *wxCYAN);
			grilla_stock->SetCellBackgroundColour(pos,5, *wxCYAN);
		}
		else if (nuevo_stock->accederprod(pos).vercantidad()==0){
			grilla_stock->SetCellBackgroundColour(pos,0, *wxRED);
			grilla_stock->SetCellBackgroundColour(pos,1, *wxRED);
			grilla_stock->SetCellBackgroundColour(pos,2, *wxRED);
			grilla_stock->SetCellBackgroundColour(pos,3, *wxRED);
			grilla_stock->SetCellBackgroundColour(pos,4, *wxRED);
			grilla_stock->SetCellBackgroundColour(pos,5, *wxRED);
		}
		else{
			grilla_stock->SetCellBackgroundColour(pos,0, *wxWHITE);
			grilla_stock->SetCellBackgroundColour(pos,1, *wxWHITE);
			grilla_stock->SetCellBackgroundColour(pos,2, *wxWHITE);
			grilla_stock->SetCellBackgroundColour(pos,3, *wxWHITE);
			grilla_stock->SetCellBackgroundColour(pos,4, *wxWHITE);
			grilla_stock->SetCellBackgroundColour(pos,5, *wxWHITE);
		}
	}
}

void stock::clickeliminarstock( wxCommandEvent& event )  {
	if (nuevo_stock->cantprod()==0){
		wxMessageBox("No es posible eliminar un producto del stock si está vacio", "Error",wxOK);
	}
	else{
		guardado=false;
		int fila=grilla_stock->GetGridCursorRow();
		int respuesta=wxMessageBox("¿Esta seguro que desea eliminar el producto del stock?",grilla_stock->GetCellValue(fila,0),wxYES_NO);
		if (respuesta==wxYES){
			nuevo_stock->eliminar(fila);
			grilla_stock->DeleteRows(fila,1);
		}
	}
}

void stock::clickmodificarstock( wxCommandEvent& event )  {
	if (nuevo_stock->cantprod()==0){
		wxMessageBox("No es posible modificar un producto si el stock está vacio", "Error", wxOK);
	}
	else{
		agregarproducto nueva_ventana(this,nuevo_stock->accederprod(grilla_stock->GetGridCursorRow()));
		if (nueva_ventana.ShowModal()==1){
			guardado=false;
			pos=grilla_stock->GetGridCursorRow();
			nuevo_stock->reemplazar(nueva_ventana.verprod(),pos);
			grilla_stock->SetCellValue(nuevo_stock->accederprod(pos).vernombre(),pos,0);
			mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(pos).vercantidad()));
			grilla_stock->SetCellValue(mystring,pos,1);
			mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(pos).vercodigo()));
			grilla_stock->SetCellValue(mystring,pos,2);
			mystring=wxString::Format(wxT("%f"),(nuevo_stock->accederprod(pos).vercosto()));
			grilla_stock->SetCellValue(mystring,pos,3);
			grilla_stock->SetCellValue(wxString::Format(wxT("%i"),nuevo_stock->accederprod(pos).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(pos).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(pos).veranio())),pos,4);
			grilla_stock->SetCellValue(nuevo_stock->accederprod(pos).verobservacion(),pos,5);
			if (nuevo_stock->accederprod(pos).vercantidad()<10 && nuevo_stock->accederprod(pos).vercantidad()!=0){
				grilla_stock->SetCellBackgroundColour(pos,0, *wxCYAN);
				grilla_stock->SetCellBackgroundColour(pos,1, *wxCYAN);
				grilla_stock->SetCellBackgroundColour(pos,2, *wxCYAN);
				grilla_stock->SetCellBackgroundColour(pos,3, *wxCYAN);
				grilla_stock->SetCellBackgroundColour(pos,4, *wxCYAN);
				grilla_stock->SetCellBackgroundColour(pos,5, *wxCYAN);
			}
			else if (nuevo_stock->accederprod(pos).vercantidad()==0){
				grilla_stock->SetCellBackgroundColour(pos,0, *wxRED);
				grilla_stock->SetCellBackgroundColour(pos,1, *wxRED);
				grilla_stock->SetCellBackgroundColour(pos,2, *wxRED);
				grilla_stock->SetCellBackgroundColour(pos,3, *wxRED);
				grilla_stock->SetCellBackgroundColour(pos,4, *wxRED);
				grilla_stock->SetCellBackgroundColour(pos,5, *wxRED);
			}
			else{
				grilla_stock->SetCellBackgroundColour(pos,0, *wxWHITE);
				grilla_stock->SetCellBackgroundColour(pos,1, *wxWHITE);
				grilla_stock->SetCellBackgroundColour(pos,2, *wxWHITE);
				grilla_stock->SetCellBackgroundColour(pos,3, *wxWHITE);
				grilla_stock->SetCellBackgroundColour(pos,4, *wxWHITE);
				grilla_stock->SetCellBackgroundColour(pos,5, *wxWHITE);
			}
		}
	}
}

void stock::clickguardarstock( wxCommandEvent& event )  {
	if (nuevo_stock->cantprod()==0){
		wxMessageBox("La lista de productos del stock esta vacía","Error",wxOK);
	}
	else{
		if (nuevo_stock->guardar()==true){
			wxMessageBox("Los datos se guardaron exitosamente","Todo Ok",wxOK);
			guardado=true;
		}
		else{
			guardado=false;
			wxMessageBox("Los datos no se han guardado",":(",wxOK);
		}
	}
}

stock::~stock() {
	
}

void stock::cerrarventana( wxCloseEvent& event )  {
	if (guardado==false){
		int resp=wxMessageBox("¿Desea salir sin guardar los cambios?","Cuidado",wxYES_NO);
		if (resp==wxYES) EndModal(0);
	}
	else EndModal(0);
}

void stock::busquedaonfly( wxCommandEvent& event )  {
	vector<int> vecpos;
	manejostock *nuevo_stock=Singletonstock::ObtenerInstancia();
	nuevo_stock->buscar(buscador->GetValue().c_str(),vecpos);
	grilla_stock->DeleteRows(0,nuevo_stock->cantprod());
	grilla_stock->AppendRows(vecpos.size());
	for(unsigned int i=0; i<vecpos.size();i++){
		grilla_stock->SetCellValue(nuevo_stock->accederprod(*(vecpos.begin()+i)).vernombre(),i,0);
		mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(*(vecpos.begin()+i)).vercantidad()));
		grilla_stock->SetCellValue(mystring,i,1);
		mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(*(vecpos.begin()+i)).vercodigo()));
		grilla_stock->SetCellValue(mystring,i,2);
		mystring=wxString::Format(wxT("%f"),(nuevo_stock->accederprod(*(vecpos.begin()+i)).vercosto()));
		grilla_stock->SetCellValue(mystring,i,3);
		grilla_stock->SetCellValue(wxString::Format(wxT("%i"),nuevo_stock->accederprod(*(vecpos.begin()+i)).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(*(vecpos.begin()+i)).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(*(vecpos.begin()+i)).veranio())),i,4);
		grilla_stock->SetCellValue(nuevo_stock->accederprod(*(vecpos.begin()+i)).verobservacion(),i,5);
	}
}

void stock::seseleccionogrilla( wxCommandEvent& event )  {
	int aux=0;
	grilla_stock->DeleteRows(0,grilla_stock->GetNumberRows());
	if (choisergrilla->GetSelection()==0){
		for (int i=0; i<nuevo_stock->cantprod();i++){
			grilla_stock->AppendRows(1);
			grilla_stock->SetCellValue(nuevo_stock->accederprod(i).vernombre(),i,0);
			mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vercantidad()));
			grilla_stock->SetCellValue(mystring,i,1);
			mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vercodigo()));
			grilla_stock->SetCellValue(mystring,i,2);
			mystring=wxString::Format(wxT("%f"),(nuevo_stock->accederprod(i).vercosto()));
			grilla_stock->SetCellValue(mystring,i,3);
			grilla_stock->SetCellValue(wxString::Format(wxT("%i"),nuevo_stock->accederprod(i).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).veranio())),i,4);
			grilla_stock->SetCellValue(nuevo_stock->accederprod(i).verobservacion(),i,5);
			if (nuevo_stock->accederprod(i).vercantidad()<10 && nuevo_stock->accederprod(i).vercantidad()!=0){
				grilla_stock->SetCellBackgroundColour(i,0, *wxCYAN);
				grilla_stock->SetCellBackgroundColour(i,1, *wxCYAN);
				grilla_stock->SetCellBackgroundColour(i,2, *wxCYAN);
				grilla_stock->SetCellBackgroundColour(i,3, *wxCYAN);
				grilla_stock->SetCellBackgroundColour(i,4, *wxCYAN);
				grilla_stock->SetCellBackgroundColour(i,5, *wxCYAN);
			}
			else if (nuevo_stock->accederprod(i).vercantidad()==0){
				grilla_stock->SetCellBackgroundColour(i,0, *wxRED);
				grilla_stock->SetCellBackgroundColour(i,1, *wxRED);
				grilla_stock->SetCellBackgroundColour(i,2, *wxRED);
				grilla_stock->SetCellBackgroundColour(i,3, *wxRED);
				grilla_stock->SetCellBackgroundColour(i,4, *wxRED);
				grilla_stock->SetCellBackgroundColour(i,5, *wxRED);
			}
			else{
				grilla_stock->SetCellBackgroundColour(i,0, *wxWHITE);
				grilla_stock->SetCellBackgroundColour(i,1, *wxWHITE);
				grilla_stock->SetCellBackgroundColour(i,2, *wxWHITE);
				grilla_stock->SetCellBackgroundColour(i,3, *wxWHITE);
				grilla_stock->SetCellBackgroundColour(i,4, *wxWHITE);
				grilla_stock->SetCellBackgroundColour(i,5, *wxWHITE);
			}
		}
	}
	else if (choisergrilla->GetSelection()==1){
		for (int i=0; i<nuevo_stock->cantprod();i++){
			if (nuevo_stock->accederprod(i).vercantidad()<10 && nuevo_stock->accederprod(i).vercantidad()!=0){
				grilla_stock->AppendRows(1);
				grilla_stock->SetCellValue(nuevo_stock->accederprod(i).vernombre(),aux,0);
				mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vercantidad()));
				grilla_stock->SetCellValue(mystring,aux,1);
				mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vercodigo()));
				grilla_stock->SetCellValue(mystring,aux,2);
				mystring=wxString::Format(wxT("%f"),(nuevo_stock->accederprod(i).vercosto()));
				grilla_stock->SetCellValue(mystring,aux,3);
				grilla_stock->SetCellValue(wxString::Format(wxT("%i"),nuevo_stock->accederprod(i).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).veranio())),aux,4);
				grilla_stock->SetCellValue(nuevo_stock->accederprod(i).verobservacion(),aux,5);
				if (nuevo_stock->accederprod(i).vercantidad()<10 && nuevo_stock->accederprod(i).vercantidad()!=0){
					grilla_stock->SetCellBackgroundColour(aux,0, *wxCYAN);
					grilla_stock->SetCellBackgroundColour(aux,1, *wxCYAN);
					grilla_stock->SetCellBackgroundColour(aux,2, *wxCYAN);
					grilla_stock->SetCellBackgroundColour(aux,3, *wxCYAN);
					grilla_stock->SetCellBackgroundColour(aux,4, *wxCYAN);
					grilla_stock->SetCellBackgroundColour(aux,5, *wxCYAN);
				}
				else if (nuevo_stock->accederprod(i).vercantidad()==0){
					grilla_stock->SetCellBackgroundColour(aux,0, *wxRED);
					grilla_stock->SetCellBackgroundColour(aux,1, *wxRED);
					grilla_stock->SetCellBackgroundColour(aux,2, *wxRED);
					grilla_stock->SetCellBackgroundColour(aux,3, *wxRED);
					grilla_stock->SetCellBackgroundColour(aux,4, *wxRED);
					grilla_stock->SetCellBackgroundColour(aux,5, *wxRED);
				}
				else{
					grilla_stock->SetCellBackgroundColour(aux,0, *wxWHITE);
					grilla_stock->SetCellBackgroundColour(aux,1, *wxWHITE);
					grilla_stock->SetCellBackgroundColour(aux,2, *wxWHITE);
					grilla_stock->SetCellBackgroundColour(aux,3, *wxWHITE);
					grilla_stock->SetCellBackgroundColour(aux,4, *wxWHITE);
					grilla_stock->SetCellBackgroundColour(aux,5, *wxWHITE);
				}
				aux++;
			}
		}
	}
	else{
		for (int i=0; i<nuevo_stock->cantprod();i++){
			if (nuevo_stock->accederprod(i).vercantidad()==0){
				grilla_stock->AppendRows(1);
				grilla_stock->SetCellValue(nuevo_stock->accederprod(i).vernombre(),aux,0);
				mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vercantidad()));
				grilla_stock->SetCellValue(mystring,aux,1);
				mystring=wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vercodigo()));
				grilla_stock->SetCellValue(mystring,aux,2);
				mystring=wxString::Format(wxT("%f"),(nuevo_stock->accederprod(i).vercosto()));
				grilla_stock->SetCellValue(mystring,aux,3);
				grilla_stock->SetCellValue(wxString::Format(wxT("%i"),nuevo_stock->accederprod(i).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_stock->accederprod(i).veranio())),aux,4);
				grilla_stock->SetCellValue(nuevo_stock->accederprod(i).verobservacion(),aux,5);
				if (nuevo_stock->accederprod(i).vercantidad()<10 && nuevo_stock->accederprod(i).vercantidad()!=0){
					grilla_stock->SetCellBackgroundColour(aux,0, *wxCYAN);
					grilla_stock->SetCellBackgroundColour(aux,1, *wxCYAN);
					grilla_stock->SetCellBackgroundColour(aux,2, *wxCYAN);
					grilla_stock->SetCellBackgroundColour(aux,3, *wxCYAN);
					grilla_stock->SetCellBackgroundColour(aux,4, *wxCYAN);
					grilla_stock->SetCellBackgroundColour(aux,5, *wxCYAN);
				}
				else if (nuevo_stock->accederprod(i).vercantidad()==0){
					grilla_stock->SetCellBackgroundColour(aux,0, *wxRED);
					grilla_stock->SetCellBackgroundColour(aux,1, *wxRED);
					grilla_stock->SetCellBackgroundColour(aux,2, *wxRED);
					grilla_stock->SetCellBackgroundColour(aux,3, *wxRED);
					grilla_stock->SetCellBackgroundColour(aux,4, *wxRED);
					grilla_stock->SetCellBackgroundColour(aux,5, *wxRED);
				}
				else{
					grilla_stock->SetCellBackgroundColour(aux,0, *wxWHITE);
					grilla_stock->SetCellBackgroundColour(aux,1, *wxWHITE);
					grilla_stock->SetCellBackgroundColour(aux,2, *wxWHITE);
					grilla_stock->SetCellBackgroundColour(aux,3, *wxWHITE);
					grilla_stock->SetCellBackgroundColour(aux,4, *wxWHITE);
					grilla_stock->SetCellBackgroundColour(aux,5, *wxWHITE);
				}
				aux++;
			}
		}
	}
}

