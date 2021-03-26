#ifndef STOCK_H
#define STOCK_H
#include "Ventanas.h"
#include "manejostock.h"
#include "Singletonstock.h"

class stock : public MyDialog2 {
private:
	manejostock *nuevo_stock=Singletonstock::ObtenerInstancia();
	int pos;
	wxString mystring;
	bool guardado;
protected:
	void seseleccionogrilla( wxCommandEvent& event ) ;
	void busquedaonfly( wxCommandEvent& event ) ;
	void cerrarventana( wxCloseEvent& event ) ;
	void clickagregarstock( wxCommandEvent& event ) ;
	void clickeliminarstock( wxCommandEvent& event ) ;
	void clickmodificarstock( wxCommandEvent& event ) ;
	void clickguardarstock( wxCommandEvent& event ) ;
public:
	stock(wxWindow *parent=NULL);
	~stock();
};

#endif

