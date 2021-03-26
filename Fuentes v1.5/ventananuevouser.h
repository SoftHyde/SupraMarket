#ifndef VENTANANUEVOUSER_H
#define VENTANANUEVOUSER_H
#include "Ventanas.h"
#include "usuariosimple.h"
#include "listausuarios.h"
using namespace std;

class ventananuevouser : public MyDialog14 {
	
private:
	listausuarios nueva_lista;
protected:
	void enteraceptar( wxCommandEvent& event ) ;
	void clickcrear( wxCommandEvent& event ) ;
	void cliclcancelar( wxCommandEvent& event ) ;
	
public:
	ventananuevouser(wxWindow *parent=NULL);
	~ventananuevouser();
};

#endif

