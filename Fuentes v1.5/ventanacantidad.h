#ifndef VENTANACANTIDAD_H
#define VENTANACANTIDAD_H
#include "Ventanas.h"

class ventanacantidad : public MyDialog141 {
	
private:
	int cant;
	int cantoriginal;
protected:
	void entertexto( wxCommandEvent& event ) ;
	void clickaceptar( wxCommandEvent& event ) ;
	void clickcancelar( wxCommandEvent& event ) ;
	
public:
	ventanacantidad(wxWindow *parent=NULL);
	ventanacantidad(wxWindow *parent,int _cantoriginal);
	int vercant();
	~ventanacantidad();
};

#endif

