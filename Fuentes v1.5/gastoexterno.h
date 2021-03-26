#ifndef GASTOEXTERNO_H
#define GASTOEXTERNO_H
#include "Ventanas.h"
#include "manejogastoext.h"
#include "singletongastoext.h"
using namespace std;

class gastoexterno : public MyDialog9 {
	
private:
	manejogastoext *nuevo_gasto=singletongastoext::ObtenerInstancia();
	int pos;
	wxString mystring;
	bool guardado;
protected:
	void clickcancelarfiltro( wxCommandEvent& event ) ;
	void cerrarventana( wxCloseEvent& event ) ;
	void fechacambio( wxDateEvent& event ) ;
	void clickagregar( wxCommandEvent& event ) ;
	void clickeliminar( wxCommandEvent& event ) ;
	void clickmodificar( wxCommandEvent& event ) ;
	void clickguardar( wxCommandEvent& event ) ;
	
public:
	gastoexterno(wxWindow *parent=NULL);
	~gastoexterno();
};

#endif

