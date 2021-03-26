#ifndef DEUDOR_H
#define DEUDOR_H
#include <string>
#include <wx/string.h>
#include "utilidades.h"
using namespace std;

struct regdeudor{
	char regnombre[50];
	char regapellido[50];
	char regdescripcion[256];
	int regdia, regmes, reganio;
	float regmonto;
};

class deudor {
private:
	string nombre="";
	string apellido="";
	wxString descripcion="";
	int dia;
	int mes;
	int anio;
	float monto;
protected:
public:
	deudor(string nomb="", string ape="", float mont=0, string desc="", int _dia=0, int _mes=0, int _anio=0);
	int verdia() const;
	int vermes() const;
	int veranio() const;
	float vermonto() const;
	string vernombre() const;
	string verapellido() const;
	wxString verdescripcion() const;
	
	void modnombre(string _nombre);
	void modapellido(string _apellido);
	void moddia(int _dia);
	void modmes(int _mes);
	void modanio(int _anio);
	void modmonto(float _monto);
	void moddescripcion(wxString _descripcion);
	
	string ValidarDatos();
	
	void guardar(ofstream &archi);
	deudor leer(ifstream &archi);
	
	~deudor();
};

bool comparar_por_nombre(deudor p1,deudor p2);
bool comparar_por_fecha(deudor p1,deudor p2);
bool comparar_por_total(deudor p1,deudor p2);


#endif

