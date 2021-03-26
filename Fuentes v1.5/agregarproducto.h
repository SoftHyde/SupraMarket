#ifndef AGREGARPRODUCTO_H
#define AGREGARPRODUCTO_H
#include "Ventanas.h"
#include "producto.h"

class agregarproducto : public MyDialog8 {
	producto p;
private:
	
protected:
	void checksaldoon( wxCommandEvent& event ) ;
	void enteraceptar( wxCommandEvent& event ) ;
	void clickaceptar( wxCommandEvent& event ) ;
	void clickagregar( wxCommandEvent& event ) ;
	void clickcancelar( wxCommandEvent& event ) ;
	
public:
	agregarproducto(wxWindow *parent=NULL);
	agregarproducto(wxWindow *parent,producto p);
	agregarproducto(wxWindow *parent,producto p,bool esventa);
	producto verprod();
	~agregarproducto();
};

#endif
