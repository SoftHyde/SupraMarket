#ifndef LISTAUSUARIOS_H
#define LISTAUSUARIOS_H
#include <fstream>
#include "usuariosimple.h"
#include <vector>

class listausuarios {
private:
	vector<usuariosimple> vecusuarios;
	string vecpreg[9];
protected:
public:
	listausuarios();
	bool guardarusuario(usuariosimple nuevo);
	usuariosimple accederusuario(int indice);
	int cantdatos();
	bool guardar();
	void reemplazar(usuariosimple prod,int indice);
	int buscaruser(string user_a_buscar);
	bool verificar(string pass_a_usar, int indice);
	bool verificarresp(string resp, int indice);
	string verpregunta(int indice);
	~listausuarios();
};

#endif

