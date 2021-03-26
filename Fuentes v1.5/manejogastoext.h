#ifndef MANEJOGASTOEXT_H
#define MANEJOGASTOEXT_H
#include <vector>
#include "gasto.h"
using namespace std;

class manejogastoext {
private:
	vector<gasto> vecgasto;
protected:
public:
	manejogastoext();
	bool guardar();
	void agregar(gasto aux);
	void eliminar(int indice);
	int cantgasto();
	void reemplazar(gasto aux, int indice);
	gasto accedergasto(int indice);
	void buscar(int _dia, int _mes, int _anio, vector<int> &vecpos);
	float totalgasto(int _dia, int _mes, int _anio);
	~manejogastoext();
};

#endif

