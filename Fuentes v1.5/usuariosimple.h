#ifndef USUARIOSIMPLE_H
#define USUARIOSIMPLE_H
#include <string>
using namespace std;

struct reg{
	char charuser[50];
	char charpass[50];
	int charpreg;
	char charresp[100];
};

class usuariosimple {
private:
	string user;
	string pass;
	int preg;
	string respuesta;
protected:
public:
	string veruser();
	string verpass();
	int verpreg();
	string verresp();
	void moduser(string _user);
	void modpass(string _pass);
	void modpreg(int i);
	void modresp(string resp);
	usuariosimple();
	void guardar(ofstream &archi);
	string validardatos();
	usuariosimple leer(ifstream &archi);
	~usuariosimple();
};

#endif

