#ifndef ELEMENTOHISTORIAL_H
#define ELEMENTOHISTORIAL_H
#include <string>
using namespace std;

struct reghistorial{
	float regcosto;
	int regdia, regmes, reganio;
	char regdetalles[256];
};

class elementohistorial {
private:
	float costo;
	string detalles;
	int dia,mes,anio;
protected:
public:
	elementohistorial(float cost=0, string deta="", int _dia=0, int _mes=0, int _anio=0 );
	int verdia() const;
	int vermes() const;
	int veranio() const;
	float vercosto() const;
	string verdetalles() const;
	
	void modificardia(int _dia);
	void modificarmes(int _mes);
	void modificaranio(int _anio);
	void modificarcosto(float cost);
	void modificardetalles( string obs);
	
	void guardar(ofstream &archi);
	elementohistorial leer(ifstream &archi);
	~elementohistorial();
};

#endif

