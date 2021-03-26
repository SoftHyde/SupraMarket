#ifndef EDITARDEUDA_H
#define EDITARDEUDA_H
#include "Ventanas.h"
#include "deuda.h"
#include "productoentregar.h"
#include <wx/datetime.h>

class editardeuda : public MyDialog7 {
	
private:
	deudor d;
	cliente c;
	bool esdeuda;
protected:
	void enteraceptar( wxCommandEvent& event ) ;
	void clickaceptar( wxCommandEvent& event ) ;
	void clickcancelar( wxCommandEvent& event ) ;
	
public:
	editardeuda(wxWindow *parent, deudor deu);
	editardeuda(wxWindow *parent, cliente cli);
	deudor verdeudor();
	cliente vercliente();
	~editardeuda();
};

#endif

