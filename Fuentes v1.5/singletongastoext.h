#ifndef SINGLETONGASTOEXT_H
#define SINGLETONGASTOEXT_H
#include "manejogastoext.h"

/**
* @brief Esta clase se encarga de que exista una y solo una instancia de Agenda
*
* Esta clase no necesita ser instanciada, sino que solo se debe utilizar el 
* método estático ObtenerInstancia(), que devuelve la instancia, creandola
* si es la primera vez que se lo invoca.
**/
class singletongastoext:public manejogastoext {
private:
	static singletongastoext *instancia; ///< puntero a la unica instancia, inicializado en NULL en el cpp
	singletongastoext(){}; ///< constructor privado, para que nadie pueda construir una instancia si no es mediante ObtenerInstancia()
	singletongastoext(const singletongastoext &);
public:
	/**
	* @brief Método para crear/obtener la única instancia de la clase
	*
	* Si no hay una instancia creada (solo la primera vez que se invoca) crea una.
	* Si ya había una instancia creada, retorna esa instancia.
	**/
	static singletongastoext *ObtenerInstancia() {
		if (!instancia) instancia=new singletongastoext();
		return instancia;
	}
};

#endif
