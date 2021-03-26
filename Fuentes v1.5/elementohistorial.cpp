#include "elementohistorial.h"
#include <fstream>

elementohistorial::elementohistorial(float cost, string deta, int _dia, int _mes, int _anio) {
	costo=cost;
	detalles=deta;
	dia=_dia;
	mes=_mes;
	anio=_anio;
}

int elementohistorial::verdia() const{
	return dia;
}
int elementohistorial::vermes() const{
	return mes;
}
int elementohistorial::veranio() const{
	return anio;
}
float elementohistorial::vercosto() const{
	return costo;
}
string elementohistorial::verdetalles() const{
	return detalles;
}


void elementohistorial::modificardia(int _dia){
	dia=_dia;
}
void elementohistorial::modificarmes(int _mes){
	mes=_mes;
}
void elementohistorial::modificaranio(int _anio){
	anio=_anio;
}
void elementohistorial::modificarcosto(float cost){
	costo=cost;
}
void elementohistorial::modificardetalles( string det){
	detalles=det;
}


void elementohistorial::guardar(ofstream &archi){
	reghistorial aux;
	strcpy(aux.regdetalles,detalles.c_str());
	aux.regcosto=costo;
	aux.regdia=dia;
	aux.regmes=mes;
	aux.reganio=anio;
	archi.write((char*)&aux,sizeof(aux));
}
elementohistorial elementohistorial::leer(ifstream &archi){
	reghistorial aux;
	archi.read((char*)&aux,sizeof(aux));
	detalles=aux.regdetalles;
	costo=aux.regcosto;
	dia=aux.regdia;
	mes=aux.regmes;
	anio=aux.reganio;
	return *this;
}

elementohistorial::~elementohistorial() {
	
}

