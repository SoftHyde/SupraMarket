#include "manejoopciones.h"
#include <fstream>

manejoopciones::manejoopciones() {
	ifstream archi("archi.option",ios::ate);
	if (archi.is_open()) {
		int tamanio_archivo = archi.tellg();
		int cantidad = tamanio_archivo/sizeof(bool);
		vecopciones.resize(cantidad);
		archi.seekg(0,ios::beg);
		for (int i=0;i<cantidad;i++){
			archi>>a;
			vecopciones.push_back(a);
		}
		archi.close();
	}
}

int manejoopciones::cantopc(){
	return vecopciones.size();
}

bool manejoopciones::guardar(){
	ofstream archi("archi.option",ios::trunc);
	if (!archi.is_open()) return false;
	int cantidad= cantopc();
	for (int i=0;i<cantidad;i++)
		archi<<*(vecopciones.begin()+i);
	archi.close();
	return true;
}

manejoopciones::~manejoopciones() {
	
}

