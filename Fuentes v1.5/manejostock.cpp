#include "manejostock.h"
#include <iterator>
#include <fstream>
#include <sstream>

manejostock::manejostock() {
	ifstream archi("prod.list",ios::binary|ios::ate);
	if (archi.is_open()) {
		int tamanio_archivo = archi.tellg();
		int cantidad_personas = tamanio_archivo/sizeof(regprod);
		vecstock.resize(cantidad_personas);
		archi.seekg(0,ios::beg);
		for (int i=0;i<cantidad_personas;i++){
			reemplazar(accederprod(i).leer(archi),i);
		}
		archi.close();
	}
}

void manejostock::agregar(producto prod){
	vecstock.push_back(prod);
}

void manejostock::eliminar(int indice){
	vecstock.erase(vecstock.begin()+indice);
}

producto manejostock::accederprod(int indice){
	return *(vecstock.begin()+indice);
}

int manejostock::cantprod(){
	return vecstock.size();
}

void manejostock::reemplazar(producto prod,int indice){
	vector<producto>::iterator it=vecstock.begin();
	it=vecstock.erase(it+indice);
	it=vecstock.insert(it,prod);
}

bool manejostock::guardar(){
	ofstream archi("prod.list",ios::binary|ios::trunc);
	if (!archi.is_open()) return false;
	int cantidad_personas = cantprod();
	for (int i=0;i<cantidad_personas;i++)
		accederprod(i).guardar(archi);
	archi.close();
	return true;
}

void manejostock::buscar(string texto,vector<int> &vecpos){
	for (unsigned int i=0;i<vecstock.size();i++){
		producto d=*(vecstock.begin()+i);
		string nombre= d.vernombre();
		std::stringstream ss;
		ss << d.vercodigo();
		string cod=ss.str();
		pasar_a_minusculas(texto);
		if (cod.find(texto,0)!=string::npos || nombre.find(texto,0)!=string::npos){
			vecpos.push_back(i);
		}
	}
}

int manejostock::buscar(string texto){
	for (unsigned int i=0;i<vecstock.size();i++){
		producto d=*(vecstock.begin()+i);
		string nombre= d.vernombre();
		pasar_a_minusculas(texto);
		if (nombre.find(texto,0)!=string::npos){
			return i;
		}
	}
}

manejostock::~manejostock() {
	
}

