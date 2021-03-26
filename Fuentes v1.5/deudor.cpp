#include "deudor.h"
#include <fstream>
#include <string>
using namespace std;

deudor::deudor(string nomb, string ape, float mont, string desc, int _dia, int _mes, int _anio) {
	nombre=nomb;
	apellido=ape;
	monto=mont;
	descripcion=desc;
	dia=_dia;
	mes=_mes;
	anio=_anio;
}

int deudor::verdia() const{
	return dia;
}
int deudor::vermes() const{
	return mes;
}
int deudor::veranio()const{
	return anio;
}
float deudor::vermonto()const{
	return monto;
}
string deudor::vernombre()const{
	return nombre;
}
string deudor::verapellido()const{
	return apellido;
}
wxString deudor::verdescripcion()const{
	return descripcion;
}

void deudor::modnombre(string _nombre){
	nombre=_nombre;
}
void deudor::modapellido(string _apellido){
	apellido=_apellido;
}
void deudor::moddia(int _dia){
	dia=_dia;
}
void deudor::modmes(int _mes){
	mes=_mes;
}
void deudor::modanio(int _anio){
	anio=_anio;
}
void deudor::modmonto(float _monto){
	monto=_monto;
}
void deudor::moddescripcion(wxString _descripcion){
	descripcion=_descripcion;
}

void deudor::guardar(ofstream &archi){
	regdeudor aux;
	strcpy(aux.regnombre,nombre.c_str());
	strcpy(aux.regapellido,apellido.c_str());
	strcpy(aux.regdescripcion,descripcion);
	aux.regdia=dia;
	aux.regmes=mes;
	aux.reganio=anio;
	aux.regmonto=monto;
	archi.write((char*)&aux,sizeof(aux));
}
deudor deudor::leer(ifstream &archi){
	regdeudor aux;
	archi.read((char*)&aux,sizeof(aux));
	nombre=aux.regnombre;
	wxString auxstring(aux.regdescripcion);
	descripcion=auxstring;
	apellido=aux.regapellido;
	dia=aux.regdia;
	mes=aux.regmes;
	anio=aux.reganio;
	monto=aux.regmonto;
	return *this;
}

string deudor::ValidarDatos() {
	string errores;
	if (nombre.size()==0) errores+="El nombre no puede estar vacio\n";
	if (nombre.size()>256) errores+="El nombre es demasiado largo\n";
	if (apellido.size()==0) errores+="El nombre no puede estar vacio\n";
	if (apellido.size()>256) errores+="El nombre es demasiado largo\n";
	if (monto<0) errores+="El costo no puede ser negativo\n";
	if (dia<1 || dia>31) errores+="El dia debe estar entre 1 y 31\n";
	if (mes<1 || mes>12) errores+="El mes debe estar entre 1 y 12\n";
	if (anio<=1900) errores+="El año no puede ser menor a 1900\n";
	return errores;
}

bool comparar_por_nombre(deudor p1,deudor p2){
	string s1=p1.verapellido() + ", " + p1.vernombre();
	string s2=p2.verapellido() + ", " + p2.vernombre();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}

bool comparar_por_fecha(deudor p1,deudor p2){
	if (p1.veranio()!=p2.veranio()) return p1.veranio()<p2.veranio();
	else if (p1.veranio()==p2.veranio() && p1.vermes()!=p2.vermes()) return p1.vermes()<p2.vermes();
	else return p1.verdia()<p2.verdia();
}

bool comparar_por_total(deudor p1,deudor p2){
	float pri, seg;
	pri=p1.vermonto();
	seg=p2.vermonto();
	return pri<seg;
}


deudor::~deudor() {
	
}

