#ifndef PRODUCTO_H
#define PRODUCTO_H
#include <string>
#include "utilidades.h"
using namespace std;

struct regprod{
	char snombre[100];
	int sdia, smes, sanio, scod, scant;
	float scosto;
	char sobservacion[256];
};

class producto {
private:
	string nombre;
	int cantidad;
	int codigo;
	float costo;
	string observacion;
	int dia,mes,anio;
protected:
	
public:
	producto(string nomb="", int cant=0, int cod=0, float cost=0, string obs="", int _dia=0, int _mes=0, int _anio=0);
	
	string vernombre() const;
	int vercodigo() const;
	float vercosto() const;
	string verobservacion() const;
	int vercantidad() const;
	int verdia() const;
	int vermes() const;
	int veranio() const;
	
	void modificadnombre(string nuevonombre);
	void modificarcodigo(int cod);
	void modificarcosto(float cost);
	void modificarobservacion( string obs);
	void modificarcantidad(int cant);
	void modificardia(int _dia);
	void modificarmes(int _mes);
	void modificaranio(int _anio);
	
	string ValidarDatos();
	
	void guardar(ofstream &archi);
	producto leer(ifstream &archi);
	
	~producto();
};

bool comparar_por_nombre(const producto &p1,const producto &p2);
bool comparar_por_cantidad(const producto &p1,const producto &p2);
bool comparar_por_codigo(const producto &p1,const producto &p2);
bool comparar_por_subtotal(const producto &p1,const producto &p2);

#endif

