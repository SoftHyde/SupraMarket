#ifndef SINGLETONHISTORIAL_H
#define SINGLETONHISTORIAL_H
#include "manejohistorial.h"

/**
* @brief Esta clase se encarga de que exista una y solo una instancia de Agenda
*
* Esta clase no necesita ser instanciada, sino que solo se debe utilizar el 
* m�todo est�tico ObtenerInstancia(), que devuelve la instancia, creandola
* si es la primera vez que se lo invoca.
**/
class singletonhistorial:public manejohistorial {
private:
	static singletonhistorial *instancia; ///< puntero a la unica instancia, inicializado en NULL en el cpp
	singletonhistorial(){}; ///< constructor privado, para que nadie pueda construir una instancia si no es mediante ObtenerInstancia()
	singletonhistorial(const singletonhistorial &);
public:
	/**
	* @brief M�todo para crear/obtener la �nica instancia de la clase
	*
	* Si no hay una instancia creada (solo la primera vez que se invoca) crea una.
	* Si ya hab�a una instancia creada, retorna esa instancia.
	**/
	static singletonhistorial *ObtenerInstancia() {
		if (!instancia) instancia=new singletonhistorial();
		return instancia;
	}
};

#endif
