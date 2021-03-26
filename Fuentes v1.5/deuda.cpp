#include "deuda.h"
#include <cstring>
#include <fstream>
#include <algorithm>
#include "utilidades.h"

deuda::deuda() {
	ifstream archi("deud.list",ios::binary|ios::ate);
	if (archi.is_open()) {
		int tamanio_archivo = archi.tellg();
		int cantidad_personas = tamanio_archivo/sizeof(regdeudor);
		vecdeu.resize(cantidad_personas);
		archi.seekg(0,ios::beg);
		for (int i=0;i<cantidad_personas;i++){
			reemplazar(accederdeudor(i).leer(archi),i);
		}
		archi.close();
	}
}

void deuda::agregardeudor(deudor p){
	vecdeu.push_back(p);
}

int deuda::cantdeudores(){
	return vecdeu.size();
}

void deuda::buscar(string texto,vector<int> &vecpos){
	for (unsigned int i=0;i<vecdeu.size();i++){
		deudor d=*(vecdeu.begin()+i);
		string nombre=d.vernombre();
		string ape=d.verapellido();
		string comp=ape+","+nombre;
		string comp2=ape+", "+nombre;
		string comp3=ape+" "+nombre;
		pasar_a_minusculas(texto);
		if (nombre.find(texto,0)!=string::npos || ape.find(texto,0) !=string::npos || comp.find(texto,0)!= string::npos || comp2.find(texto,0)!= string::npos || comp3.find(texto,0)!= string::npos){
			vecpos.push_back(i);
		}
	}
}

deudor deuda::accederdeudor(int indice){
	return *(vecdeu.begin()+indice);
}

void deuda::eliminardeudor(int indice){
	vecdeu.erase(vecdeu.begin()+indice);
}

void deuda::reemplazar(deudor d,int indice){
	vector<deudor>::iterator it=vecdeu.begin();
	it=vecdeu.erase(it+indice);
	it=vecdeu.insert(it,d);
}

bool deuda::guardar(){
	ofstream archi("deud.list",ios::binary|ios::trunc);
	if (!archi.is_open()) return false;
	int cantidad_personas = cantdeudores();
	for (int i=0;i<cantidad_personas;i++)
		accederdeudor(i).guardar(archi);
	archi.close();
	return true;
}

void deuda::Ordenar(CriterioOrden criterio) {
	switch (criterio) {
	case ORDEN_NOMBRE: 
		sort(vecdeu.begin(),vecdeu.end(),comparar_por_nombre);
		break;
	case ORDEN_FECHA: 
		sort(vecdeu.begin(),vecdeu.end(),comparar_por_fecha); 
		break;
	case ORDEN_TOTAL: 
		sort(vecdeu.begin(),vecdeu.end(),comparar_por_total); 
		break;
	};
}


deuda::~deuda() {
	
}

