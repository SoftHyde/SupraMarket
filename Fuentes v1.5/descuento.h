#ifndef DESCUENTO_H
#define DESCUENTO_H
#include "Ventanas.h"

class descuento : public MyDialog1 {
	
private:
	int desc;
protected:
	void enteraceptar( wxCommandEvent& event ) ;
	void clickcrear( wxCommandEvent& event ) ;
	void cliclcancelar( wxCommandEvent& event ) ;
	void clickaceptar( wxCommandEvent& event ) ;
	void clickcancelar( wxCommandEvent& event ) ;
	
public:
	descuento(wxWindow *parent=NULL);
	int ver_desc();
	~descuento();
};

#endif

