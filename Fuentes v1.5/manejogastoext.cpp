#include "manejogastoext.h"
#include <fstream>

manejogastoext::manejogastoext() {
	ifstream archi("extgast.list",ios::binary|ios::ate);
	if (archi.is_open()) {
		int tamanio_archivo = archi.tellg();
		int cantidad_personas = tamanio_archivo/sizeof(regasto);
		vecgasto.resize(cantidad_personas);
		archi.seekg(0,ios::beg);
		for (int i=0;i<cantidad_personas;i++){
			reemplazar(accedergasto(i).leer(archi),i);
		}
		archi.close();
	}
}

void manejogastoext::buscar(int _dia, int _mes, int _anio, vector<int> &vecpos){
	for (unsigned int i=0;i<vecgasto.size();i++){
		gasto d=*(vecgasto.begin()+i);
		int dia=d.verdia();
		int mes=d.vermes();
		int anio=d.veranio();
		if (_dia==dia && _mes==mes && _anio==anio){
			vecpos.push_back(i);
		}
	}
}

float manejogastoext::totalgasto(int _dia, int _mes, int _anio){
	vector<int> vecpos;
	buscar(_dia, _mes, _anio,vecpos);
	float aux=0;
	for(unsigned int i=0; i<vecpos.size();i++){
		aux+=accedergasto(*(vecpos.begin()+i)).vercosto();
	}
	return aux;
}

void manejogastoext::agregar(gasto aux){
	vecgasto.push_back(aux);
}

void manejogastoext::eliminar(int indice){
	vecgasto.erase(vecgasto.begin()+indice);
}

gasto manejogastoext::accedergasto(int indice){
	return *(vecgasto.begin()+indice);
}

int manejogastoext::cantgasto(){
	return vecgasto.size();
}

void manejogastoext::reemplazar(gasto aux,int indice){
	vector<gasto>::iterator it=vecgasto.begin();
	it=vecgasto.erase(it+indice);
	it=vecgasto.insert(it,aux);
}

bool manejogastoext::guardar(){
	ofstream archi("extgast.list",ios::binary|ios::trunc);
	if (!archi.is_open()) return false;
	int cantidad_personas = cantgasto();
	for (int i=0;i<cantidad_personas;i++)
		accedergasto(i).guardar(archi);
	archi.close();
	return true;
}

manejogastoext::~manejogastoext() {
	
}

