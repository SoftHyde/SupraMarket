#ifndef NOMBREDEUDOR_H
#define NOMBREDEUDOR_H
#include "Ventanas.h"
#include <string>
using namespace std;

class nombredeudor : public MyDialog81 {
	
private:
	string nombre;
	string apellido;
	float saldo;
	
protected:
	void enteraceptar( wxCommandEvent& event ) ;
	void checksaldoon( wxCommandEvent& event ) ;
	void enteragregar( wxCommandEvent& event ) ;
	void clickaceptar( wxCommandEvent& event ) ;
	void clickcancelar( wxCommandEvent& event ) ;
	
public:
	nombredeudor(wxWindow *parent=NULL);
	string vernombre();
	string verapellido();
	float versaldo();
	~nombredeudor();
};

#endif

