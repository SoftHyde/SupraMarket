#include "producto.h"
#include <string>
#include <fstream>
#include <cstring>
using namespace std;

producto::producto(string nomb, int cant, int cod, float cost, string obs, int _dia, int _mes, int _anio) {
	nombre=nomb;
	cantidad=cant;
	codigo=cod;
	costo=cost;
	observacion=obs;
	dia=_dia;
	mes=_mes;
	anio=_anio;
}

string producto::vernombre() const{
	return nombre;
}
int producto::vercodigo() const{
	return codigo;
}
float producto::vercosto() const{
	return costo;
}
string producto::verobservacion() const{
	return observacion;
}
int producto::vercantidad() const{
	return cantidad;
}
int producto::verdia() const{
	return dia;
}
int producto::vermes() const{
	return mes;
}
int producto::veranio() const{
	return anio;
}



void producto::modificadnombre(string nuevonombre){
	nombre=nuevonombre;
}
void producto::modificarcodigo(int cod){
	codigo=cod;
}
void producto::modificarcosto(float cost){
	costo=cost;
}
void producto::modificarobservacion( string obs){
	observacion=obs;
}
void producto::modificarcantidad(int cant){
	cantidad=cant;
}
void producto::modificardia(int _dia){
	dia=_dia;
}
void producto::modificarmes(int _mes){
	mes=_mes;
}
void producto::modificaranio(int _anio){
	anio=_anio;
}


bool comparar_por_nombre(const producto &p1,const producto &p2){
	string s1=p1.vernombre();
	string s2=p2.vernombre();
	pasar_a_minusculas(s1);
	pasar_a_minusculas(s2);
	return s1<s2;
}

bool comparar_por_cantidad(const producto &p1,const producto &p2){
	return p1.vercantidad()<p2.vercantidad();
}

bool comparar_por_codigo(const producto &p1,const producto &p2){
	return p1.vercodigo()<p2.vercodigo();
}

bool comparar_por_subtotal(const producto &p1,const producto &p2){
	float pri, seg;
	pri=p1.vercantidad()*p1.vercosto();
	seg=p2.vercantidad()*p2.vercosto();
	return pri<seg;
}


void producto::guardar(ofstream &archi){
	regprod aux;
	strcpy(aux.snombre,nombre.c_str());
	strcpy(aux.sobservacion,observacion.c_str());
	aux.scosto=costo;
	aux.scant=cantidad;
	aux.scod=codigo;
	aux.sdia=dia;
	aux.smes=mes;
	aux.sanio=anio;
	archi.write((char*)&aux,sizeof(aux));
}
producto producto::leer(ifstream &archi){
	regprod aux;
	archi.read((char*)&aux,sizeof(aux));
	nombre=aux.snombre;
	observacion=aux.sobservacion;
	costo=aux.scosto;
	cantidad=aux.scant;
	codigo=aux.scod;
	dia=aux.sdia;
	mes=aux.smes;
	anio=aux.sanio;
	return *this;
}

string producto::ValidarDatos() {
	string errores;
	if (nombre.size()==0) errores+="El nombre no puede estar vacio\n";
	if (nombre.size()>256) errores+="El nombre es demasiado largo\n";
	if (costo<0) errores+="El costo no puede ser negativo\n";
	if (cantidad<0) errores+="La cantidad no puede ser negativa\n";
	if (codigo<0) errores+="El codigo no puede ser negativo\n";
	if (dia<1 || dia>31) errores+="El dia debe estar entre 1 y 31\n";
	if (mes<1 || mes>12) errores+="El mes debe estar entre 1 y 12\n";
	if (anio<=1900) errores+="El año no puede ser menor a 1900\n";
	return errores;
}

producto::~producto() {
	
}

