#ifndef HISTORIAL_H
#define HISTORIAL_H
#include "Ventanas.h"
#include <wx/string.h>
#include "manejohistorial.h"
#include "singletonhistorial.h"

class historial : public MyDialog5 {
	
private:
	manejohistorial *nuevo_historial=singletonhistorial::ObtenerInstancia();
	wxString mystring;
	float montoaux=0;
	int dia;
	int mes;
	int anio;
protected:
	void checkfiltromes( wxCommandEvent& event ) ;
	void eligiomes( wxCommandEvent& event ) ;
	void clickcelda( wxGridEvent& event ) ;
	void clickelegirfecha( wxCalendarEvent& event ) ;
	
public:
	historial(wxWindow *parent=NULL);
	~historial();
};

#endif

