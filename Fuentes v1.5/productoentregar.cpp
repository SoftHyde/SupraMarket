#include "productoentregar.h"
#include <fstream>
#include <algorithm>
#include "utilidades.h"

productoentregar::productoentregar() {
	ifstream archi("prodtemp.list",ios::binary|ios::ate);
	if (archi.is_open()) {
		int tamanio_archivo = archi.tellg();
		int cantidad_personas = tamanio_archivo/sizeof(regcliente);
		veccliente.resize(cantidad_personas);
		archi.seekg(0,ios::beg);
		for (int i=0;i<cantidad_personas;i++){
			reemplazar(accedercliente(i).leer(archi),i);
		}
		archi.close();
	}
}

void productoentregar::agregarcliente(cliente p){
	veccliente.push_back(p);
}

int productoentregar::cantclientes(){
	return veccliente.size();
}
void productoentregar::buscar(string texto, vector<int> &vecpos){
	for (unsigned int i=0;i<veccliente.size();i++){
		cliente d=*(veccliente.begin()+i);
		string nombre=d.vernombre();
		string ape=d.verapellido();
		string comp=ape+","+nombre;
		pasar_a_minusculas(texto);
		if (nombre.find(texto,0)!=string::npos || ape.find(texto,0) !=string::npos || comp.find(texto,0)!= string::npos){
			vecpos.push_back(i);
		}
	}
}

cliente productoentregar::accedercliente(int indice){
	return *(veccliente.begin()+indice);
}

void productoentregar::eliminarcliente(int indice){
	veccliente.erase(veccliente.begin()+indice);
}

void productoentregar::reemplazar(cliente d,int indice){
	vector<cliente>::iterator it=veccliente.begin();
	it=veccliente.erase(it+indice);
	it=veccliente.insert(it,d);
}

bool productoentregar::guardar(){
	ofstream archi("prodtemp.list",ios::binary|ios::trunc);
	if (!archi.is_open()) return false;
	int cantidad_personas = cantclientes();
	for (int i=0;i<cantidad_personas;i++)
		accedercliente(i).guardar(archi);
	archi.close();
	return true;
}

void productoentregar::Ordenar(CriterioOrdenproductoentregar criterio) {
	switch (criterio) {
	case ORDEN_NOMBRE2: 
		sort(veccliente.begin(),veccliente.end(),comparar_por_nombre);
		break;
	case ORDEN_FECHA2: 
		sort(veccliente.begin(),veccliente.end(),comparar_por_fecha); 
		break;
	case ORDEN_TOTAL2: 
		sort(veccliente.begin(),veccliente.end(),comparar_por_total); 
		break;
	};
}


productoentregar::~productoentregar() {
	
}

