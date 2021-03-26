#ifndef SINGLETONSTOCK_H
#define SINGLETONSTOCK_H
#include "manejostock.h"

/**
* @brief Esta clase se encarga de que exista una y solo una instancia de Agenda
*
* Esta clase no necesita ser instanciada, sino que solo se debe utilizar el 
* m�todo est�tico ObtenerInstancia(), que devuelve la instancia, creandola
* si es la primera vez que se lo invoca.
**/
class Singletonstock:public manejostock {
private:
	static Singletonstock *instancia; ///< puntero a la unica instancia, inicializado en NULL en el cpp
	Singletonstock(){}; ///< constructor privado, para que nadie pueda construir una instancia si no es mediante ObtenerInstancia()
	Singletonstock(const Singletonstock &);
public:
	/**
	* @brief M�todo para crear/obtener la �nica instancia de la clase
	*
	* Si no hay una instancia creada (solo la primera vez que se invoca) crea una.
	* Si ya hab�a una instancia creada, retorna esa instancia.
	**/
	static Singletonstock *ObtenerInstancia() {
		if (!instancia) instancia=new Singletonstock();
		return instancia;
	}
};

#endif
