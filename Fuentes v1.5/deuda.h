#ifndef DEUDA_H
#define DEUDA_H
#include <string>
#include <wx/string.h>
#include <vector>
#include "deudor.h"
using namespace std;

enum CriterioOrden { ORDEN_NOMBRE, ORDEN_FECHA, ORDEN_TOTAL };

class deuda {
private:
	vector<deudor> vecdeu;
protected:
public:
	deuda();
	bool guardar();
	void buscar(string texto,vector<int> &vecpos);
	void agregardeudor(deudor p);
	void eliminardeudor(int indice);
	int cantdeudores();
	void reemplazar(deudor d,int indice);
	deudor accederdeudor(int indice);
	void Ordenar(CriterioOrden criterio);
	~deuda();
};

#endif

