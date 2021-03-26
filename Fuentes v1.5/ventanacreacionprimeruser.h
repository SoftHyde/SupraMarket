#ifndef VENTANACREACIONPRIMERUSER_H
#define VENTANACREACIONPRIMERUSER_H
#include "Ventanas.h"
#include "usuariosimple.h"
#include "listausuarios.h"
using namespace std;

class ventanacreacionprimeruser : public MyDialog15 {
	
private:
	listausuarios nueva_lista;
	
protected:
	void onbotoncerrar( wxCloseEvent& event ) ;
	void enterpass( wxCommandEvent& event ) ;
	void clickbotonaceptar( wxCommandEvent& event ) ;
	
public:
	ventanacreacionprimeruser(wxWindow *parent=NULL);
	~ventanacreacionprimeruser();
};

#endif

