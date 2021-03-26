#include "venta.h"
#include <algorithm>
#include "producto.h"
using namespace std;

venta::venta() {
}

int venta::cantidad_productos(){
	return vec.size();
}

void venta::agregarproducto(const producto &prod){
	vec.push_back(prod);
	total=total+totalprod(vec.size()-1);
}

void venta::eliminarproducto(int fila) {
	vec.erase(vec.begin()+fila);
	total=total-totalprod(fila);
}

producto venta::accederprod(int indice){
	return *(vec.begin()+indice);
}

float venta::vertotal(){
	return total;
}

float venta::totalprod(int indice){
	float aux;
	aux=accederprod(indice).vercosto() * accederprod(indice).vercantidad();
	return aux;
}

void venta::aplicardesc(int desc){
	float aux=(total*desc)/100;
	total=total-aux;
}

void venta::eliminarventa(){
	vec.clear();
	total=0;
}
void venta::reemplazar(producto prod,int indice){
	total=total-(accederprod(indice).vercosto()*accederprod(indice).vercantidad());
	vector<producto>::iterator it=vec.begin();
	it=vec.erase(it+indice);
	it=vec.insert(it,prod);
	total=total+(accederprod(indice).vercosto()*accederprod(indice).vercantidad());
}

venta::~venta() {
	
}

