#ifndef GASTO_H
#define GASTO_H
#include <string>
using namespace std;

struct regasto{
	char regdesc[256];
	float regcosto;
	int regdia, regmes, reganio;
};

class gasto {
private:
	int dia,mes,anio;
	string desc;
	float costo;
protected:
public:
	gasto(int _dia=0, int _mes=0, int _anio=0, string aux="", float _costo=0);
	int verdia() const;
	int vermes() const;
	int veranio() const;
	string verdesc() const;
	float vercosto() const;
	void modificardia(int _dia);
	void modificarmes(int _mes);
	void modificaranio(int _anio);
	void modificardesc(string _desc);
	void modificarcosto(int _costo);
	
	string ValidarDatos();
	
	void guardar(ofstream &archi);
	gasto leer(ifstream &archi);
	~gasto();
};

#endif

