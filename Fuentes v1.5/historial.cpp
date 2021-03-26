#include "historial.h"
#include <wx/datetime.h>
#include <vector>
#include <wx/string.h>
#include <wx/icon.h>

historial::historial(wxWindow *parent) : MyDialog5(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
	struct tm *tiempo;
	time_t fecha_sistema;
	time(&fecha_sistema);
	tiempo=localtime(&fecha_sistema);
	anio=tiempo->tm_year + 1900;
	mes=tiempo->tm_mon + 1;
	dia=tiempo->tm_mday;
	
	paneldetalles->SetLabel("Seleccione alguna fila del historial y los detalles se mostrarán en este panel");
	grilla_historial->SetGridCursor(0,0);
	grilla_historial->SelectRow(0);
	grilla_historial->SetSelectionMode(wxGrid::wxGridSelectRows);
	elementohistorial aux;
	for (int i=0; i<nuevo_historial->cantprod();i++){
		grilla_historial->AppendRows(1);
		mystring=wxString::Format(wxT("%f"),(nuevo_historial->accederprod(i).vercosto()));
		grilla_historial->SetCellValue(mystring,i,1);
		grilla_historial->SetCellValue(wxString::Format(wxT("%i"),nuevo_historial->accederprod(i).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_historial->accederprod(i).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_historial->accederprod(i).veranio())),i,0);
		grilla_historial->SetCellValue(nuevo_historial->accederprod(i).verdetalles(),i,2);
		montoaux+=nuevo_historial->accederprod(i).vercosto();
	}
	labeltotalmes->SetLabel("Total recaudado");
	textototalrecaudado->SetValue(wxString::Format(wxT("%f"),montoaux));
}

historial::~historial() {
	
}

void historial::clickelegirfecha( wxCalendarEvent& event )  {
	vector<int> vecpos;
	montoaux=0;
	wxDateTime fecha=cosofecha->GetDate();
	int dia= fecha.GetDay();
	int mes=fecha.GetMonth();
	int anio=fecha.GetYear();
	nuevo_historial->buscar(dia,(mes+1),anio,vecpos);
	grilla_historial->DeleteRows(0,nuevo_historial->cantprod());
	grilla_historial->AppendRows(vecpos.size());
	for(unsigned int i=0; i<vecpos.size();i++){
		grilla_historial->SetCellValue(nuevo_historial->accederprod(*(vecpos.begin()+i)).verdetalles(),i,2);
		mystring=wxString::Format(wxT("%f"),(nuevo_historial->accederprod(*(vecpos.begin()+i)).vercosto()));
		grilla_historial->SetCellValue(mystring,i,1);
		grilla_historial->SetCellValue(wxString::Format(wxT("%i"),nuevo_historial->accederprod(*(vecpos.begin()+i)).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_historial->accederprod(*(vecpos.begin()+i)).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_historial->accederprod(*(vecpos.begin()+i)).veranio())),i,0);
		montoaux+=nuevo_historial->accederprod(*(vecpos.begin()+i)).vercosto();
	}
	labeltotalmes->SetLabel("Total recaudado en el dia");
	textototalrecaudado->SetValue(wxString::Format(wxT("%f"),montoaux));
}

void historial::clickcelda( wxGridEvent& event )  {
	event.Skip();
	elementohistorial aux;
	aux=nuevo_historial->accederprod(event.GetRow());
	paneldetalles->SetLabel("Detalles: " + aux.verdetalles());
}


void historial::checkfiltromes( wxCommandEvent& event )  {
	if (check->IsChecked()){
		paneldetalles->SetLabel("Seleccione alguna fila del historial y los detalles se mostrarán en este panel");
		cosofecha->Disable();
		choisermes->Enable();
		textototalrecaudado->SetValue(wxString::Format(wxT("%f"),0.0));
		grilla_historial->DeleteRows(0,grilla_historial->GetNumberRows());
		grilla_historial->AppendRows(nuevo_historial->cantprod());
		for(int i=0; i<nuevo_historial->cantprod();i++){
			grilla_historial->SetCellValue(nuevo_historial->accederprod(i).verdetalles(),i,2);
			mystring=wxString::Format(wxT("%f"),(nuevo_historial->accederprod(i).vercosto()));
			grilla_historial->SetCellValue(mystring,i,1);
			grilla_historial->SetCellValue(wxString::Format(wxT("%i"),nuevo_historial->accederprod(i).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_historial->accederprod(i).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_historial->accederprod(i).veranio())),i,0);
		}
		labeltotalmes->SetLabel("Total recaudado en el mes");
		textototalrecaudado->SetValue(wxString::Format(wxT("%f"),0.0));
	}
	else{
		paneldetalles->SetLabel("Seleccione alguna fila del historial y los detalles se mostrarán en este panel");
		cosofecha->Enable();
		montoaux=0;
		choisermes->Disable();
		grilla_historial->DeleteRows(0,grilla_historial->GetNumberRows());
		grilla_historial->AppendRows(nuevo_historial->cantprod());
		for(int i=0; i<nuevo_historial->cantprod();i++){
			grilla_historial->SetCellValue(nuevo_historial->accederprod(i).verdetalles(),i,2);
			mystring=wxString::Format(wxT("%f"),(nuevo_historial->accederprod(i).vercosto()));
			grilla_historial->SetCellValue(mystring,i,1);
			grilla_historial->SetCellValue(wxString::Format(wxT("%i"),nuevo_historial->accederprod(i).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_historial->accederprod(i).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_historial->accederprod(i).veranio())),i,0);
			montoaux+=nuevo_historial->accederprod(i).vercosto();
		}
		labeltotalmes->SetLabel("Total recaudado");
		textototalrecaudado->SetValue(wxString::Format(wxT("%f"),montoaux));
	}
	
}

void historial::eligiomes( wxCommandEvent& event )  {
	int aux=choisermes->GetSelection();
	vector<int> vecpos;
	montoaux=0;
	nuevo_historial->buscar(aux+1,anio,vecpos);
	grilla_historial->DeleteRows(0,grilla_historial->GetNumberRows());
	grilla_historial->AppendRows(vecpos.size());
	for(unsigned int i=0; i<vecpos.size();i++){
		grilla_historial->SetCellValue(nuevo_historial->accederprod(*(vecpos.begin()+i)).verdetalles(),i,2);
		mystring=wxString::Format(wxT("%f"),(nuevo_historial->accederprod(*(vecpos.begin()+i)).vercosto()));
		grilla_historial->SetCellValue(mystring,i,1);
		grilla_historial->SetCellValue(wxString::Format(wxT("%i"),nuevo_historial->accederprod(*(vecpos.begin()+i)).verdia())+"/"+wxString::Format(wxT("%i"),(nuevo_historial->accederprod(*(vecpos.begin()+i)).vermes()))+"/"+wxString::Format(wxT("%i"),(nuevo_historial->accederprod(*(vecpos.begin()+i)).veranio())),i,0);
		montoaux+=nuevo_historial->accederprod(*(vecpos.begin()+i)).vercosto();
	}
	labeltotalmes->SetLabel("Total recaudado");
	textototalrecaudado->SetValue(wxString::Format(wxT("%f"),montoaux));
}

