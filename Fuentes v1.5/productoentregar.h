#ifndef PRODUCTOENTREGAR_H
#define PRODUCTOENTREGAR_H
#include <string>
#include <wx/string.h>
#include <vector>
#include "cliente.h"
using namespace std;

enum CriterioOrdenproductoentregar { ORDEN_NOMBRE2, ORDEN_FECHA2, ORDEN_TOTAL2 };

class productoentregar {
private:
	vector<cliente> veccliente;
protected:
public:
	productoentregar();
	bool guardar();
	void buscar(string texto,vector<int> &vecpos);
	void agregarcliente(cliente p);
	void eliminarcliente(int indice);
	int cantclientes();
	void reemplazar(cliente d,int indice);
	cliente accedercliente(int indice);
	void Ordenar(CriterioOrdenproductoentregar criterio);
	~productoentregar();
};

#endif

