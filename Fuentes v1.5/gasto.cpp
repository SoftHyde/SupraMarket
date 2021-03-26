#include "gasto.h"
#include <fstream>

gasto::gasto(int _dia, int _mes, int _anio, string aux, float _costo) {
	dia=_dia;
	mes=_mes;
	anio=_anio;
	desc=aux;
	costo=_costo;
}

int gasto::verdia() const{
	return dia;
}
int gasto::vermes() const{
	return mes;
}
int gasto::veranio() const{
	return anio;
}
string gasto::verdesc() const{
	return desc;
}
float gasto::vercosto() const{
	return costo;
}
void gasto::modificardia(int _dia){
	dia=_dia;
}
void gasto::modificarmes(int _mes){
	mes=_mes;
}
void gasto::modificaranio(int _anio){
	anio=_anio;
}
void gasto::modificardesc(string _desc){
	desc=_desc;
}
void gasto::modificarcosto(int _costo){
	costo=_costo;
}

void gasto::guardar(ofstream &archi){
	regasto aux;
	strcpy(aux.regdesc,desc.c_str());
	aux.regdia=dia;
	aux.regmes=mes;
	aux.reganio=anio;
	aux.regcosto=costo;
	archi.write((char*)&aux,sizeof(aux));
}
gasto gasto::leer(ifstream &archi){
	regasto aux;
	archi.read((char*)&aux,sizeof(aux));
	desc=aux.regdesc;
	dia=aux.regdia;
	mes=aux.regmes;
	anio=aux.reganio;
	costo=aux.regcosto;
	return *this;
}

string gasto::ValidarDatos() {
	string errores;
	if (desc.size()==0) errores+="El nombre no puede estar vacio\n";
	if (costo<0) errores+="El costo no puede ser negativo\n";
	if (dia<1 || dia>31) errores+="El dia debe estar entre 1 y 31\n";
	if (mes<1 || mes>12) errores+="El mes debe estar entre 1 y 12\n";
	if (anio<=1900) errores+="El año no puede ser menor a 1900\n";
	return errores;
}

gasto::~gasto() {
	
}

