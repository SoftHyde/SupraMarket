#include "acercade.h"
#include <wx/icon.h>
#include <wx/string.h>

acercade::acercade(wxWindow *parent) : MyDialog6(parent) {
	SetTitle("Acerca de Supra Market");
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
}

acercade::~acercade() {
	
}

