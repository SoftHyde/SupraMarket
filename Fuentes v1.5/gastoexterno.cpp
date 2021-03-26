#include "gastoexterno.h"
#include "agregargasto.h"
#include <wx/msgdlg.h>
#include <wx/datetime.h>
#include <vector>
#include <wx/string.h>
#include <wx/icon.h>

gastoexterno::gastoexterno(wxWindow *parent) : MyDialog9(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
	guardado=true;
	mystring=wxString::Format(wxT("%f"),0.0);
	textototalgastos->SetValue(mystring);
	grilla_gastos_externos->SetSelectionMode(wxGrid::wxGridSelectRows);
	for (int i=0; i<nuevo_gasto->cantgasto();i++){
		grilla_gastos_externos->AppendRows(1);
		grilla_gastos_externos->SetCellValue(nuevo_gasto->accedergasto(i).verdesc(),i,1);
		mystring=wxString::Format(wxT("%f"),(nuevo_gasto->accedergasto(i).vercosto()));
		grilla_gastos_externos->SetCellValue(mystring,i,2);
		grilla_gastos_externos->SetCellValue(wxString::Format(wxT("%i"),nuevo_gasto->accedergasto(i).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_gasto->accedergasto(i).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_gasto->accedergasto(i).veranio())),i,0);
	}
}

gastoexterno::~gastoexterno() {
	
}

void gastoexterno::fechacambio( wxDateEvent& event )  {
	vector<int> vecpos;
	wxDateTime fecha=cosofecha->GetValue();
	labeltotal->Show();
	textototalgastos->Show();
	Layout();
	int dia= fecha.GetDay();
	int mes=fecha.GetMonth();
	int anio=fecha.GetYear();
	nuevo_gasto->buscar(dia,(mes+1),anio,vecpos);
	grilla_gastos_externos->DeleteRows(0,nuevo_gasto->cantgasto());
	grilla_gastos_externos->AppendRows(vecpos.size());
	for(unsigned int i=0; i<vecpos.size();i++){
		grilla_gastos_externos->SetCellValue(nuevo_gasto->accedergasto(*(vecpos.begin()+i)).verdesc(),i,1);
		mystring=wxString::Format(wxT("%f"),(nuevo_gasto->accedergasto(*(vecpos.begin()+i)).vercosto()));
		grilla_gastos_externos->SetCellValue(mystring,i,2);
		grilla_gastos_externos->SetCellValue(wxString::Format(wxT("%i"),nuevo_gasto->accedergasto(*(vecpos.begin()+i)).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_gasto->accedergasto(*(vecpos.begin()+i)).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_gasto->accedergasto(*(vecpos.begin()+i)).veranio())),i,0);
	}
	mystring=wxString::Format(wxT("%f"),nuevo_gasto->totalgasto(dia,mes+1,anio));
	textototalgastos->SetValue(mystring);
}

void gastoexterno::clickagregar( wxCommandEvent& event )  {
	agregargasto nueva_ventana(this);
	if (nueva_ventana.ShowModal()==1){
		guardado=false;
		labeltotal->Hide();
		textototalgastos->Hide();
		grilla_gastos_externos->AppendRows(1);
		nuevo_gasto->agregar(nueva_ventana.vergasto());
		pos=nuevo_gasto->cantgasto()-1;
		grilla_gastos_externos->SetCellValue(wxString::Format(wxT("%i"),(nuevo_gasto->accedergasto(pos).verdia()))+"/"+wxString::Format(wxT("%i"),(nuevo_gasto->accedergasto(pos).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_gasto->accedergasto(pos).veranio())),pos,0);
		mystring=wxString::Format(wxT("%f"),(nuevo_gasto->accedergasto(pos).vercosto()));
		grilla_gastos_externos->SetCellValue(mystring,pos,2);
		grilla_gastos_externos->SetCellValue(nuevo_gasto->accedergasto(pos).verdesc(),pos,1);
	}
}

void gastoexterno::clickeliminar( wxCommandEvent& event )  {
	if (nuevo_gasto->cantgasto()==0){
		wxMessageBox("No es posible eliminar un producto de los gastos externos si la lista está vacía", "Error",wxOK);
	}
	else{
		guardado=false;
		labeltotal->Hide();
		textototalgastos->Hide();
		int fila=grilla_gastos_externos->GetGridCursorRow();
		int respuesta=wxMessageBox("¿Esta seguro que desea eliminar el producto de la lista de gastos externos?",grilla_gastos_externos->GetCellValue(fila,0),wxYES_NO);
		if (respuesta==wxYES){
			nuevo_gasto->eliminar(fila);
			grilla_gastos_externos->DeleteRows(fila,1);
		}
	}
}

void gastoexterno::clickmodificar( wxCommandEvent& event )  {
	if (nuevo_gasto->cantgasto()==0){
		wxMessageBox("No es posible modificar un gasto si la lista está vacía", "Error", wxOK);
	}
	else{
		agregargasto nueva_ventana(this,nuevo_gasto->accedergasto(grilla_gastos_externos->GetGridCursorRow()));
		if (nueva_ventana.ShowModal()==1){
			guardado=false;
			labeltotal->Hide();
			textototalgastos->Hide();
			pos=grilla_gastos_externos->GetGridCursorRow();
			nuevo_gasto->reemplazar(nueva_ventana.vergasto(),pos);
			grilla_gastos_externos->SetCellValue(wxString::Format(wxT("%i"),(nuevo_gasto->accedergasto(pos).verdia()))+"/"+wxString::Format(wxT("%i"),(nuevo_gasto->accedergasto(pos).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_gasto->accedergasto(pos).veranio())),pos,0);
			mystring=wxString::Format(wxT("%f"),(nuevo_gasto->accedergasto(pos).vercosto()));
			grilla_gastos_externos->SetCellValue(mystring,pos,2);
			grilla_gastos_externos->SetCellValue(nuevo_gasto->accedergasto(pos).verdesc(),pos,1);
		}
	}
}

void gastoexterno::clickguardar( wxCommandEvent& event )  {
	if (nuevo_gasto->cantgasto()==0){
		wxMessageBox("La lista de gastos esta vacía", "Error", wxOK);
	}
	else{
		if (nuevo_gasto->guardar()==true){
			guardado=true;
			wxMessageBox("Los datos se guardaron exitosamente","Todo Ok",wxOK);
		}
		else{
			guardado=false;
			wxMessageBox("Los datos no se han guardado",":(",wxOK);
		}
	}
}

void gastoexterno::cerrarventana( wxCloseEvent& event )  {
	if (guardado==false){
		int resp=wxMessageBox("¿Desea salir sin guardar los cambios?","Cuidado",wxYES_NO);
		if (resp==wxYES) EndModal(0);
	}
	else EndModal(0);
}

void gastoexterno::clickcancelarfiltro( wxCommandEvent& event )  {
	labeltotal->Hide();
	textototalgastos->Hide();
	grilla_gastos_externos->DeleteRows(0,nuevo_gasto->cantgasto());
	for (int i=0; i<nuevo_gasto->cantgasto();i++){
		grilla_gastos_externos->AppendRows(1);
		grilla_gastos_externos->SetCellValue(nuevo_gasto->accedergasto(i).verdesc(),i,1);
		mystring=wxString::Format(wxT("%f"),(nuevo_gasto->accedergasto(i).vercosto()));
		grilla_gastos_externos->SetCellValue(mystring,i,2);
		grilla_gastos_externos->SetCellValue(wxString::Format(wxT("%i"),nuevo_gasto->accedergasto(i).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_gasto->accedergasto(i).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_gasto->accedergasto(i).veranio())),i,0);
	}
	Layout();
}

