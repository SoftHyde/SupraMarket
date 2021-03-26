#ifndef CLIENTE_H
#define CLIENTE_H
#include <string>
#include <wx/string.h>
using namespace std;

struct regcliente{
	char regnombre[100];
	char regapellido[100];
	char regdetalles[256];
	char regmodificaciones[256];
	int regdia, regmes, reganio;
	float regmonto;
};


class cliente {
private:
	string nombre="";
	string apellido="";
	wxString detalles="";
	wxString modificaciones="";
	int dia,mes,anio;
	float monto;
protected:
public:
	cliente();
	wxString vermodificaciones();
	string vernombre();
	string verapellido();
	wxString verdetalle();
	int verdia();
	int vermes();
	int veranio();
	float vermonto();
	void modmodificaciones(wxString _modificaciones);
	void modnombre(string _nombre);
	void modapellido(string _apellido);
	void moddetalles(wxString _detalles);
	void moddia(int _dia);
	void modmes(int _mes);
	void modanio(int _anio);
	void modmonto(float _monto);
	
	string ValidarDatos();
	
	void guardar(ofstream &archi);
	cliente leer(ifstream &archi);
	~cliente();
};

bool comparar_por_nombre(cliente p1,cliente p2);
bool comparar_por_fecha(cliente p1,cliente p2);
bool comparar_por_total(cliente p1,cliente p2);

#endif

