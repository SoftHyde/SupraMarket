#ifndef VentanaPrincipal_H
#define VentanaPrincipal_H
#include "Ventanas.h"
#include <vector>
#include "producto.h"
#include "deuda.h"
#include "venta.h"
#include "productoentregar.h"
#include "listausuarios.h"
#include "manejohistorial.h"
#include "manejostock.h"
#include "Singletonstock.h"
#include "singletonhistorial.h"

class VentanaPrincipal:public Frame0 {
protected:
	void clickeditarpass( wxCommandEvent& event ) ;
	void clickvolverfab( wxCommandEvent& event ) ;
	void clickordenargrillaencargo( wxGridEvent& event ) ;
	void clickmanualdeusuario( wxCommandEvent& event ) ;
	void clickordenardeudas( wxGridEvent& event ) ;
	void clickexportarhistorial( wxCommandEvent& event ) ;
	void clickexportarstock( wxCommandEvent& event ) ;
	void clicknuevouser( wxCommandEvent& event ) ;
	void clickfinalizaranticipado( wxCommandEvent& event ) ;
	void clickeliminaranticipado( wxCommandEvent& event ) ;
	void click_producto_a_entregar( wxCommandEvent& event ) ;
	void selecciongrilla( wxCommandEvent& event ) ;
	void clickvergastosexternos( wxCommandEvent& event ) ;
	void clickeditarventa( wxGridEvent& event ) ;
	void clickeditardeuda( wxGridEvent& event ) ;
	void clicksaldardeuda( wxCommandEvent& event ) ;
	deuda nueva_deuda;
	productoentregar nueva_lista;
	venta nueva_venta;
	int porcentdesc=0;
	wxString mystring;
	manejostock *nuevo_stock=Singletonstock::ObtenerInstancia();
	manejohistorial *nuevo_histo=singletonhistorial::ObtenerInstancia();
	int cantdeudas;
	int cantcomprasconfecha;
	int dia;
	int mes;
	int anio;
	void clickgrillaproductos( wxGridEvent& event ) ;
	void clickagregarprod( wxCommandEvent& event ) ;
	void clickeliminarprod( wxCommandEvent& event ) ;
	void clickcancelarcompra( wxCommandEvent& event ) ;
	void clickdescuento( wxCommandEvent& event ) ;
	void clickdeuda( wxCommandEvent& event ) ;
	void clickchaucompra( wxCommandEvent& event ) ;
	void cancelarbusqueda( wxCommandEvent& event ) ;
	void busquedaonthefly( wxCommandEvent& event ) ;
	void clickgrilladeudores( wxGridEvent& event ) ;
	void clickagregardeudor( wxCommandEvent& event ) ;
	void clickeliminardeudor( wxCommandEvent& event ) ;
	void clickverstock( wxCommandEvent& event ) ;
	void clickverhistorial( wxCommandEvent& event ) ;
	void clickacercade( wxCommandEvent& event ) ;

public:
	VentanaPrincipal(wxWindow *parent=NULL);
	void OnBotonCerrar(wxCommandEvent &evt);
};

#endif
