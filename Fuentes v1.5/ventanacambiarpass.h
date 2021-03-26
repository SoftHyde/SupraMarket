#ifndef VENTANACAMBIARPASS_H
#define VENTANACAMBIARPASS_H
#include "Ventanas.h"
#include "listausuarios.h"

class ventanacambiarpass : public MyDialog16 {
	
private:
	listausuarios nuevalista;
protected:
	void clickuser( wxFocusEvent& event ) ;
	void clickpass( wxFocusEvent& event ) ;
	void clickaceptar( wxCommandEvent& event ) ;
	void clickcancelar( wxCommandEvent& event ) ;
	
public:
	ventanacambiarpass(wxWindow *parent=NULL);
	~ventanacambiarpass();
};

#endif

