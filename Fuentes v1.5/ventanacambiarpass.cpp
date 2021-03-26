#include "ventanacambiarpass.h"
#include <wx/msgdlg.h>

ventanacambiarpass::ventanacambiarpass(wxWindow *parent) : MyDialog16(parent) {
	labelmal->Hide();
}

ventanacambiarpass::~ventanacambiarpass() {
	
}

void ventanacambiarpass::clickaceptar( wxCommandEvent& event )  {
	int res=nuevalista.buscaruser(textoactualuser->GetValue().c_str());
	if (res==-1){
		labelmal->Show();
		Layout();
	}
	else{
		bool aux=nuevalista.verificar(textoactualpass->GetValue().c_str(),res);
		if (!aux){
			labelmal->Show();
			Layout();
		}
		else{
			if (textonuevapass->IsEmpty()) {
				labelmal->Hide();
				Layout();
				wxMessageBox("Necesita ingresar su nueva contraseña","Error",wxOK);
			}
			else if (textonuevapass->GetValue()==textoactualpass->GetValue()){
				labelmal->Hide();
				Layout();
				wxMessageBox("Su nueva contraseña debe ser distinta a la actual","Error",wxOK);
			}
			else{
				labelmal->Hide();
				Layout();
				usuariosimple nuevo;
				nuevo.moduser(textoactualuser->GetValue().c_str());
				nuevo.modpass(textonuevapass->GetValue().c_str());
				nuevalista.reemplazar(nuevo,res);
				nuevalista.guardar();
				EndModal(1);
			}
		}
	}
}

void ventanacambiarpass::clickcancelar( wxCommandEvent& event )  {
	EndModal(0);
}

void ventanacambiarpass::clickuser( wxFocusEvent& event )  {
	labelmal->Hide();
	Layout();
	event.Skip();
}

void ventanacambiarpass::clickpass( wxFocusEvent& event )  {
	labelmal->Hide();
	Layout();
	event.Skip();
}

