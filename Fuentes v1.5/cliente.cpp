#include "cliente.h"
#include <fstream>
#include "utilidades.h"

cliente::cliente() {
	
}

wxString cliente::vermodificaciones(){
	return modificaciones;
}
string cliente::vernombre(){
	return nombre;
}
string cliente::verapellido(){
	return apellido;
}
wxString cliente::verdetalle(){
	return detalles;
}
int cliente::verdia(){
	return dia;
}
int cliente::vermes(){
	return mes;
}
int cliente::veranio(){
	return anio;
}
float cliente::vermonto(){
	return monto;
}

void cliente::modmodificaciones(wxString _modificaciones){
	modificaciones=_modificaciones;
}
void cliente::modnombre(string _nombre){
	nombre=_nombre;
}
void cliente::modapellido(string _apellido){
	apellido=_apellido;
}
void cliente::moddetalles(wxString _detalles){
	detalles=_detalles;
}
void cliente::moddia(int _dia){
	dia=_dia;
}
void cliente::modmes(int _mes){
	mes=_mes;
}
void cliente::modanio(int _anio){
	anio=_anio;
}
void cliente::modmonto(float _monto){
	monto=_monto;
}



void cliente::guardar(ofstream &archi){
	regcliente aux;
	strcpy(aux.regnombre,nombre.c_str());
	strcpy(aux.regapellido,apellido.c_str());
	strcpy(aux.regdetalles,detalles);
	strcpy(aux.regmodificaciones,modificaciones);
	aux.regdia=dia;
	aux.regmes=mes;
	aux.reganio=anio;
	aux.regmonto=monto;
	archi.write((char*)&aux,sizeof(aux));
}
cliente cliente::leer(ifstream &archi){
	regcliente aux;
	archi.read((char*)&aux,sizeof(aux));
	nombre=aux.regnombre;
	wxString auxstring(aux.regdetalles);
	detalles=auxstring;
	wxString auxstring2(aux.regmodificaciones);
	modificaciones=auxstring2;
	apellido=aux.regapellido;
	dia=aux.regdia;
	mes=aux.regmes;
	anio=aux.reganio;
	monto=aux.regmonto;
	return *this;
}

string cliente::ValidarDatos() {
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
cliente::~cliente() {
	
}

bool comparar_por_nombre(cliente p1,cliente p2){
	string s1=p1.verapellido() + ", " + p1.vernombre();
	string s2=p2.verapellido() + ", " + p2.vernombre();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}

bool comparar_por_fecha(cliente p1,cliente p2){
	if (p1.veranio()!=p2.veranio()) return p1.veranio()<p2.veranio();
	else if (p1.veranio()==p2.veranio() && p1.vermes()!=p2.vermes()) return p1.vermes()<p2.vermes();
	else return p1.verdia()<p2.verdia();
}

bool comparar_por_total(cliente p1,cliente p2){
	float pri, seg;
	pri=p1.vermonto();
	seg=p2.vermonto();
	return pri<seg;
}


