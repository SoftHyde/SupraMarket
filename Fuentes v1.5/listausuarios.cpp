#include "listausuarios.h"
#include "usuariosimple.h"

listausuarios::listausuarios() {
	ifstream archi("users.list",ios::binary|ios::ate);
	if (archi.is_open()) {
		int tamanio_archivo = archi.tellg();
		int cantidad_personas = tamanio_archivo/sizeof(reg);
		vecusuarios.resize(cantidad_personas);
		archi.seekg(0,ios::beg);
		for (int i=0;i<cantidad_personas;i++){
			reemplazar(accederusuario(i).leer(archi),i);
		}
		archi.close();
	}
	vecpreg[0]="¿Cual fue el primer automovil que compraste?";
	vecpreg[1]="¿Cual es el nombre de tu mascota?";
	vecpreg[2]="¿Como se llama tu equipo favorito?";
	vecpreg[3]="¿En que año finalizaste la escuela secundaria?";
	vecpreg[4]="¿Cual es tu pasatiempo favorito?";
	vecpreg[5]="¿Donde vivias cuando eras menor?";
	vecpreg[6]="¿Cual fue tu primer videojuego?";
	vecpreg[7]="¿Cual es el segundo nombre de tu mama?";
	vecpreg[8]="¿Cual es el segundo nombre de tu papa?";
}

void listausuarios::reemplazar(usuariosimple prod,int indice){
	vector<usuariosimple>::iterator it=vecusuarios.begin();
	it=vecusuarios.erase(it+indice);
	it=vecusuarios.insert(it,prod);
}

bool listausuarios::guardarusuario(usuariosimple nuevo){
	for (unsigned int i=0; i<vecusuarios.size(); i++){
		if (nuevo.veruser()==accederusuario(i).veruser()){
			return false;
		}
	}
	vecusuarios.push_back(nuevo);
	return true;
}

usuariosimple listausuarios::accederusuario(int indice){
	return *(vecusuarios.begin()+indice);
}

int listausuarios::cantdatos(){
	return vecusuarios.size();
}

bool listausuarios::guardar(){
	ofstream archi("users.list",ios::binary|ios::trunc);
	if (!archi.is_open()) return false;
	int cantidad_personas = cantdatos();
	for (int i=0;i<cantidad_personas;i++)
		accederusuario(i).guardar(archi);
	archi.close();
	return true;
}

int listausuarios::buscaruser(string user_a_buscar){
	for (unsigned int i=0; i<vecusuarios.size();i++){
		if (accederusuario(i).veruser()==user_a_buscar) 
		return i;
	}
	return -1;
}

bool listausuarios::verificar(string pass_a_usar, int indice){
	if (accederusuario(indice).verpass()==pass_a_usar) return true;
	else return false;
}

bool listausuarios::verificarresp(string resp, int indice){
	if (accederusuario(indice).verresp()==resp) return true;
	else return false;
}

string listausuarios::verpregunta(int indice){
	return vecpreg[indice];
}

listausuarios::~listausuarios() {
	
}
