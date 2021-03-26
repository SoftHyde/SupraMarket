#ifndef VENTA_H
#define VENTA_H
#include <string>
#include "producto.h"
#include <vector>
using namespace std;

class venta {
private:
	vector<producto> vec;
	float total=0;
protected:
public:
	venta();
	producto accederprod(int indice);
	void aplicardesc(int desc);
	bool guardar();
	int cantidad_productos();
	void agregarproducto(const producto &prod);
	void eliminarproducto(int fila);
	float vertotal();
	float totalprod(int indice);
	void eliminarventa();
	void reemplazar(producto prod, int indice);
	~venta();
};

#endif

