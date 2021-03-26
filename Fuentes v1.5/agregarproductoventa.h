#ifndef AGREGARPRODUCTOVENTA_H
#define AGREGARPRODUCTOVENTA_H
#include "Ventanas.h"
#include <wx/string.h>
#include "producto.h"
#include "manejostock.h"
#include "Singletonstock.h"


class agregarproductoventa : public MyDialog3 {
	
private:
	manejostock *nuevo_stock=Singletonstock::ObtenerInstancia();
	wxString mystring;
	producto p;
protected:
	void clickcancelar( wxCommandEvent& event ) ;
	void clickbotonagregar( wxCommandEvent& event ) ;
	void clickbotoncancelar( wxCommandEvent& event ) ;
	void buscaronfly( wxCommandEvent& event ) ;
	
public:
	agregarproductoventa(wxWindow *parent=NULL);
	producto verprod();
	int verfilastock();
	~agregarproductoventa();
};

#endif

