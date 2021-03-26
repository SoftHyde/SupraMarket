#ifndef AGREGARGASTO_H
#define AGREGARGASTO_H
#include "Ventanas.h"
#include "gasto.h"

class agregargasto : public MyDialog10 {
	gasto g;
private:
	
protected:
	void enteraceptar( wxCommandEvent& event ) ;
	void clickaceptar( wxCommandEvent& event ) ;
	void clickcancelar( wxCommandEvent& event ) ;
	
public:
	agregargasto(wxWindow *parent=NULL);
	agregargasto(wxWindow *parent,gasto aux);
	gasto vergasto();
	~agregargasto();
};

#endif

