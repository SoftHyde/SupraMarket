#include "usuariosimple.h"
#include <fstream>

usuariosimple::usuariosimple() {
}

void usuariosimple::guardar(ofstream &archi){
	reg aux;
	strcpy(aux.charuser,user.c_str());
	strcpy(aux.charpass,pass.c_str());
	aux.charpreg=preg;
	strcpy(aux.charresp,respuesta.c_str());
	archi.write((char*)&aux,sizeof(aux));
}

usuariosimple usuariosimple::leer(ifstream &archi){
	reg aux;
	archi.read((char*)&aux,sizeof(aux));
	user=aux.charuser;
	pass=aux.charpass;
	respuesta=aux.charresp;
	preg=aux.charpreg;
	return *this;
}

string usuariosimple::veruser(){
	return user;
}
string usuariosimple::verpass(){
	return pass;
}
string usuariosimple::verresp(){
	return respuesta;
}
int usuariosimple::verpreg(){
	return preg;
}
void usuariosimple::moduser(string _user){
	user=_user;
}
void usuariosimple::modpass(string _pass){
	pass=_pass;
}
void usuariosimple::modpreg(int i){
	preg=i;
}
void usuariosimple::modresp(string resp){
	respuesta=resp;
}

string usuariosimple::validardatos(){
	string errores;
	if (pass.size()==0) errores+="La contraseña no puede estar vacia\n";
	if (user.size()==0) errores+="El nombre de usuario no puede estar vacío\n";
	if (pass==user) errores+="La contraseña no puede ser igual al usuario, escoja otra contraseña\n";
	if (respuesta.size()==0) errores+="La respuesta no puede estar vacia\n";
	return errores;
}

usuariosimple::~usuariosimple() {
	
}

