#ifndef NOMBRECOMPRACONFECHA_H
#define NOMBRECOMPRACONFECHA_H
#include "Ventanas.h"
#include <string>
using namespace std;

class nombrecompraconfecha : public MyDialog11 {
	
private:
	string nombre;
	string apellido;
	wxString mod;
	int dia,mes,anio;
	
protected:
	void enteraceptar( wxCommandEvent& event ) ;
	void clickaceptar( wxCommandEvent& event ) ;
	void clickcancelar( wxCommandEvent& event ) ;
	
public:
	nombrecompraconfecha(wxWindow *parent=NULL);
	string vernombre();
	string verapellido();
	int verdia();
	int vermes();
	int veranio();
	wxString vermod();
	~nombrecompraconfecha();
};

#endif

