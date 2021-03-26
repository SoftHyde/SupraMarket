#include "loginpantalla.h"
#include <wx/string.h>
#include <wx/icon.h>
#include "ventanarecuperarpass.h"

loginpantalla::loginpantalla(wxWindow *parent) : MyDialog13(parent) {
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
}

loginpantalla::~loginpantalla() {
	
}

void loginpantalla::clicklogin( wxCommandEvent& event )  {
	user=textousuario->GetValue().c_str();
	pass=textopass->GetValue().c_str();
	EndModal(1);
}

void loginpantalla::focususer( wxFocusEvent& event )  {
	if (textousuario->GetValue()!=""){
		textousuario->SetValue("");
	}
}

void loginpantalla::focuspass( wxFocusEvent& event )  {
	if (textopass->GetValue()!=""){
		textopass->SetValue("");
	}
}

void loginpantalla::yanofocususer( wxFocusEvent& event )  {
	if (textousuario->GetValue()==""){
		textousuario->SetValue("Ingrese el nombre de usuario");
	}
}

void loginpantalla::yanofocuspass( wxFocusEvent& event )  {
	if (textopass->GetValue()==""){
		textopass->SetValue("contraseña");
	}
}	

string loginpantalla::veruser(){
	return user;
}

string loginpantalla::verpass(){
	return pass;
}

void loginpantalla::Onbotoncerrar( wxCloseEvent& event )  {
	EndModal(0);
}

void loginpantalla::enterpass( wxCommandEvent& event )  {
	clicklogin(event);
}

void loginpantalla::clickolvidepass( wxHyperlinkEvent& event )  {
	ventanarecuperarpass nueva_ventana;
	nueva_ventana.ShowModal();
}

