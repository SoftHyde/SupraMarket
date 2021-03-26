/**
* @brief Esta clase permite modificar e imprimir una planilla de ExcelManipulator
*
* ExcelManipulator v20130726
*
* Esta clase permite abrir una planilla de calculo de Excel, modificarla, guardarla
* imprimirla, etc. La idea es que el programador diseñe el formulario que desea
* imprimir con Excel, y deje en blanco los campos a completar. Luego, desde la
* aplicacion que debe imprimir, se utiliza esta clase para completar esos campos.
*
* La clase utiliza al mismisimo Excel, cargandolo en memoria (de forma oculta si se 
* quiere, para que el usuario de la aplicacion no lo note) y le envia los comandos 
* para editar e imprimir la planilla. Todo se realiza a traves de un objeto OLE,
* razon por la cual la implementacion depende de la biblioteca vole, que a su
* vez depende de la biblioteca stlsoft. En la carpeta include se incluyen las
* versiones 0.6.5 de vole y 1.9.104 de stlsoft descargadas de vole.sourceforge.net
* y www.stlsoft.org respectivamente. Ambas se distribuye bajo la licensia 
* BSD-form. La clase ExcelManipulator se puede copiar, modificar, distribuir
* libremente de cualquier forma y con cualquier fin.
*
* Lo bueno de esta biblioteca es que hace muy facil la impresion de formularios
* y planillas, ya que se las diseña con Excel directamente. Ademas, si hay que
* cambiar la planilla, basta con modificar el xls, y no es necesario recompilar.
* Como desventaja, es muy costoso levantar en memoria todo un Excel para imprimir
* cosas simples, y ademas depende de que este instalado. En consecuencia, tampoco
* funciona en GNU/Linux. Sin embargo, la biblioteca compila sin errores en GNU/Linux
* pero en ese caso ningun metodo hace nada.
*
* El procedimiento para usar esta biblioteca es entonces:
* -# Diseñar el formulario con Excel y guardarlo 
* -# Crear una instancia de ExcelManipulator, pasandolo al constructor la ruta 
*    al archivo de xls creado en el punto anterior
* -# Utilizar los metodos SetValue para completar las celdas en blanco
* -# Utilizar el metodo Print para imprimir el formulario
* -# Utilizar el metodo Close para descargar la planilla de la memoria
*
*
* Hay dos formas de utilizar esta biblioteca desde un proyecto de ZinjaI:
* - La forma mas recomendable es copiar los archivo ExcelManipulator.h y 
* libExcelManipulator.a , y configurar el proyecto cliente en ZinjaI 
* para enlazar contra dicho .a. Para esto, en el menu Ejecucion -> 
* Opciones... -> pestaña Enlazado, en el campo "Bibliotecas a enlazar" colocar
* "ExcelManipulator" (sin el prefijo lib ni la extension .a), y agregar el 
* directorio donde se encuentren en los campos "Directorios adicionales para 
* buscar bibliotecas" de la misma pestaña, y "Directorios adicionales para buscar 
* cabeceras" de la pestaña compilacion (si estan en la carpeta de proyecto el  
* directorio seria . (punto) y solo es necesario en la pestaña Enlazado).
* Para poder utilizar este archivo .a debe tener una versión de ZinjaI igual o 
* superior a 20130726.
* - La segunda forma es copiar ExcelManipulator.h, ExcelManipulator.cpp y toda la
* carpeta include al directorio del proyecto cliente y adjuntar al projecto los
* dos primeros archivos (utilizand "Abrir..." del menu "Archivo" y respondiendo
* que Si a la pregunta. Luego se debe agregar la carpeta "include" en el campo
* "Directorios adicionales para buscar cabeceras de las opciones de compilacion
* del proyecto, y las bibliotecas "ole32 oleaut32 uuid" a la lista de "Bibliotecas
* a enlazar" de las opciones de enlazado.
*
* por Pablo Novara (zaskar_84@yahoo.com.ar), ultima modificacion: 07-11-2012
**/

class ExcelManipulator {
	bool opened; 
	static void *coinit;
	void *xlApp, *xlBook, *xlSheet;
public:
	
	/**
	* @brief Constructor, crea la instancia de Excel sin incializar nada
	*
	* Despues de utiliza este constructor se debe invocar al metodo Open para
	* comenzar a trabajar
	**/
	ExcelManipulator();
	
	/**
	* @brief Constructor, crea la instancia de Excel y abre un documento
	*
	* @param fname    Ruta del archivo de excel (generalmente un .xls) que 
	*                 se debe abrir. Si esta en blanco se crea una planilla nueva.
	* @param visible  Si es true, la instancia de excel que realiza las
	*                 modificaciones sera visible, para poder observar
	*                 los cambios que la clase realiza en el documento. No
	*                 se debe cerrar manualmente esa ventana de Excel, sino
	*                 llamar al metodo Close, porque si se generara un error.
	*                 En general, este argumento deberia ser false en la version 
	*                 final del programa cliente, pero true durante la depuracion
	*                 del algoritmo que completa la planilla.
	**/
	ExcelManipulator(const char *fname="", bool visible=false);
	
	/**
	* @brief Crea la instancia de Excel y abre un documento
	*
	* Se utiliza cuando se creo la instancia de la clase con el constructor por
	* defecto, o cuando se invoco a Close para reiniciar el estado del objeto.
	*
	* @param fname    Ruta del archivo de excel (generalmente un .xls) que 
	*                 se debe abrir. Si esta en blanco se crea una planilla nueva.
	* @param visible  Si es true, la instancia de excel que realiza las
	*                 modificaciones sera visible, para poder observar
	*                 los cambios que la clase realiza en el documento. No
	*                 se debe cerrar manualmente esa ventana de Excel, sino
	*                 llamar al metodo Close, porque si se generara un error.
	*                 En general, este argumento deberia ser false en la version 
	*                 final del programa cliente, pero true durante la depuracion
	*                 del algoritmo que completa la planilla.
	**/
	bool Open(const char *fname="", bool visible=false);
	
	/**
	* @brief Indica si el documento se pudo abrir correctamente y esta listo
	*        para ser editador/impreso.
	*
	* @retval true   si se abrio correctamente
	* @retval false  si no pudo abrirse (por ejemplo, porque excel no esta instalado)
	**/
	bool IsOpen();
	
	/**
	* @brief Selecciona una hoja en un archivo con muchas hojas
	*
	* @param number  número de hoja a seleccionar (base 1)
	* @retval true si la hoja existía y se pudo seleccionar
	* @retval false si el número de hoja no era válido
	**/
	bool SelectSheet(int number);
	
	/**
	* @brief Asigna un valor de texto a una celda
	*
	* @param row    fila de la celda a modificar (en base 1)
	* @param col    columna de la celda a modificar (en base 1)
	* @param value  valor a colocar en esa celda
	**/
	void SetValue(int row, int col, const char *value);
	
	/**
	* @brief Asigna un valor entero a una celda
	*
	* @param row    fila de la celda a modificar (en base 1)
	* @param col    columna de la celda a modificar (en base 1)
	* @param value  valor a colocar en esa celda
	**/
	void SetValue(int row, int col, int value);
	
	/**
	* @brief Asigna un valor flotante a una celda
	*
	* @param row    fila de la celda a modificar (en base 1)
	* @param col    columna de la celda a modificar (en base 1)
	* @param value  valor a colocar en esa celda
	**/
	void SetValue(int row, int col, float value);
	
	/**
	* @brief Asigna un valor double a una celda
	*
	* @param row    fila de la celda a modificar (en base 1)
	* @param col    columna de la celda a modificar (en base 1)
	* @param value  valor a colocar en esa celda
	**/
	void SetValue(int row, int col, double value);
	
	/**
	* @brief Imprime la planilla 
	*
	* Este metodo imprime directamente en la impresora predeterminada sin pedir 
	* confirmacion ni mostrar dialogo alguno.
	**/
	void Print();
	
	/**
	* @brief Guarda la planilla modificada
	*
	* Este metodo imprime guarda la planilla modificada en el archivo que recibe
	* como argumento. Si el archivo ya existe lo sobreescribe sin preguntar.
	*
	* @param fname    Ruta del archivo de excel (generalmente un .xls) donde se 
	*                 debe guadar. No puede ser una cadena vacia.
	**/
	void SaveAs(const char *fname);
	
	/**
	* @brief Cierra la instancia de Excel utilizada por la clase
	*
	* Se pierden los cambios realizados a la planilla. Luego de llamar a Close
	* el objeto queda como si se hubiese construido con el constructor por
	* defecto, listo para utilizarse llamando al metodo Open.
	**/
	void Close();
	
	/**
	* @brief Llama a Close si no se ha llamado manualmente antes
	**/
	~ExcelManipulator();
};

