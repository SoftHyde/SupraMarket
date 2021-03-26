#ifndef LOGINPANTALLA_H
#define LOGINPANTALLA_H
#include "Ventanas.h"
#include <string>
using namespace std;

class loginpantalla : public MyDialog13 {
	
private:
	string user;
	string pass;
protected:
	void clickolvidepass( wxHyperlinkEvent& event ) ;
	void enterpass( wxCommandEvent& event ) ;
	void Onbotoncerrar( wxCloseEvent& event ) ;
	void yanofocususer( wxFocusEvent& event ) ;
	void yanofocuspass( wxFocusEvent& event ) ;
	void focususer( wxFocusEvent& event ) ;
	void focuspass( wxFocusEvent& event ) ;
	void clicklogin( wxCommandEvent& event ) ;
	
public:
	loginpantalla(wxWindow *parent=NULL);
	string veruser();
	string verpass();
	~loginpantalla();
};

#endif

