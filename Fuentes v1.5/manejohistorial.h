#ifndef MANEJOHISTORIAL_H
#define MANEJOHISTORIAL_H
#include <vector>
#include "elementohistorial.h"
using namespace std;

class manejohistorial {
private:
	vector<elementohistorial> vechistory;
protected:
public:
	manejohistorial();
	bool guardar();
	void agregar(elementohistorial prod);
	int cantprod();
	elementohistorial accederprod(int indice);
	void reemplazar(elementohistorial prod, int indice);
	void buscar(int _dia, int _mes, int _anio, vector<int> &vecpos);
	void buscar(int mes,int anio,vector<int> &vecpos);
	~manejohistorial();
};

#endif

