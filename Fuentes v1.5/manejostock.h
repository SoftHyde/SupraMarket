#ifndef MANEJOSTOCK_H
#define MANEJOSTOCK_H
#include <vector>
#include "producto.h"
using namespace std;

class manejostock {
private:
	vector<producto> vecstock;
protected:
public:
	manejostock();
	bool guardar();
	void agregar(producto prod);
	void eliminar(int indice);
	int cantprod();
	void reemplazar(producto prod, int indice);
	producto accederprod(int indice);
	void buscar(string texto,vector<int> &vecpos);
	int buscar(string texto);
	~manejostock();
};

#endif

