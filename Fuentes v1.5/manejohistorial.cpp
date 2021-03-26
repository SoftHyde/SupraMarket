#include "manejohistorial.h"
#include <fstream>

manejohistorial::manejohistorial() {
	ifstream archi("hist.list",ios::binary|ios::ate);
	if (archi.is_open()) {
		int tamanio_archivo = archi.tellg();
		int cantidad_personas = tamanio_archivo/sizeof(reghistorial);
		vechistory.resize(cantidad_personas);
		archi.seekg(0,ios::beg);
		for (int i=0;i<cantidad_personas;i++){
			reemplazar(accederprod(i).leer(archi),i);
		}
		archi.close();
	}
}

void manejohistorial::agregar(elementohistorial prod){
	vechistory.push_back(prod);
}

elementohistorial manejohistorial::accederprod(int indice){
	return *(vechistory.begin()+indice);
}

int manejohistorial::cantprod(){
	return vechistory.size();
}

void manejohistorial::reemplazar(elementohistorial prod,int indice){
	vector<elementohistorial>::iterator it=vechistory.begin();
	it=vechistory.erase(it+indice);
	it=vechistory.insert(it,prod);
}

bool manejohistorial::guardar(){
	ofstream archi("hist.list",ios::binary|ios::trunc);
	if (!archi.is_open()) return false;
	int cantidad_personas = cantprod();
	for (int i=0;i<cantidad_personas;i++)
		accederprod(i).guardar(archi);
	archi.close();
	return true;
}

void manejohistorial::buscar(int _dia, int _mes, int _anio, vector<int> &vecpos){
	for (unsigned int i=0;i<vechistory.size();i++){
		elementohistorial p=*(vechistory.begin()+i);
		int dia=p.verdia();
		int mes=p.vermes();
		int anio=p.veranio();
		if (_dia==dia && _mes==mes && _anio==anio){
			vecpos.push_back(i);
		}
	}
}

void manejohistorial::buscar(int mes, int anio,vector<int> &vecpos){
	for (unsigned int i=0;i<vechistory.size();i++){
		elementohistorial d=*(vechistory.begin()+i);
		int selec=d.vermes();
		int _anio=d.veranio();
		if (selec==mes && _anio==anio){
			vecpos.push_back(i);
		}
	}
}

manejohistorial::~manejohistorial() {
	
}

