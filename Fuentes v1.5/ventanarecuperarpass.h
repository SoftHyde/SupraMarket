#ifndef VENTANARECUPERARPASS_H
#define VENTANARECUPERARPASS_H
#include "Ventanas.h"
#include "usuariosimple.h"
#include "listausuarios.h"

class ventanarecuperarpass : public MyDialog17 {
	
private:
	usuariosimple nuevouser;
	listausuarios nueva_lista;
	
protected:
	void clickbuscar( wxCommandEvent& event ) ;
	void clickverificar( wxCommandEvent& event ) ;
	void clickfinalizar( wxCommandEvent& event ) ;
	
public:
	ventanarecuperarpass(wxWindow *parent=NULL);
	~ventanarecuperarpass();
};

#endif

