#include "VentanaPrincipal.h"
#include "agregarproductoventa.h"
#include "descuento.h"
#include <wx/msgdlg.h>
#include "stock.h"
#include "acercade.h"
#include "historial.h"
#include "nombredeudor.h"
#include "editardeuda.h"
#include "gastoexterno.h"
#include "nombrecompraconfecha.h"
#include "agregarproducto.h"
#include "loginpantalla.h"
#include "ventananuevouser.h"
#include "deudor.h"
#include "cliente.h"
#include "ventanacantidad.h"
#include "ventanacreacionprimeruser.h"
#include "windows.h"
#include "ExcelManipulator.h"
#include <cstring>
#include <wx/string.h>
#include <wx/icon.h>
#include <algorithm>
#include "ventanacambiarpass.h"

VentanaPrincipal::VentanaPrincipal(wxWindow *parent):Frame0(parent){
	
	SetTitle("Supra Market");
	this->SetIcon(wxIcon(wxString()<<"Logotipo.PNG",wxBITMAP_TYPE_PNG));
	//aca comienza la verificacion para resolver si es la primera vez que se abre el programa desde su instalacion
	ifstream archi("num.ver", ios_base::in);
	char a;
	archi >> a; // lee una caracter del archivo
	archi.close();
	if (a=='0'){
		ventanacreacionprimeruser nueva_ventana(this);
		if (nueva_ventana.ShowModal()==1) {
			ofstream archi("num.ver", ios_base::in);
			a='1';
			archi<<a;
			archi.close();
		}
		else{
			Close();
		}
	}
	//luego de la verificacion aparece la pantalla de inicio de sesion y se verifica primero si el usuario existe
	//luego si este existe se verifica la contraseña y si las dos coinciden se abre la ventana principal del programa
	listausuarios nueva_lista_user;
	while(true){
		loginpantalla nueva_ventana(this);
		if (nueva_ventana.ShowModal()==0){
			Close();
		}
		else{
			if (nueva_lista_user.buscaruser(nueva_ventana.veruser())==-1){
				wxMessageBox("No se ha encontrado el usuario, intente nuevamente","Error",wxOK);
			}
			else if (nueva_lista_user.verificar(nueva_ventana.verpass(),nueva_lista_user.buscaruser(nueva_ventana.veruser()))==false){
				wxMessageBox("Usuario o contraseña incorrecto, intente nuevamente","Error",wxOK);
			}
			else {
				//
				struct tm *tiempo;
				time_t fecha_sistema;
				time(&fecha_sistema);
				tiempo=localtime(&fecha_sistema);
				anio=tiempo->tm_year + 1900;
				mes=tiempo->tm_mon + 1;
				dia=tiempo->tm_mday;
				
				for (int i=0; i<nueva_lista.cantclientes(); i++){
					if (nueva_lista.accedercliente(i).verdia()==dia && nueva_lista.accedercliente(i).vermes()==mes && nueva_lista.accedercliente(i).veranio()==anio){
						wxMessageBox("Hoy es el dia de entrega de los productos del comprador " + nueva_lista.accedercliente(i).vernombre(),"Advertencia",wxOK);
					}
				}
				
				//struct creado para establecer la fecha del sistema
				//en el for. se cargan los datos obtenidos del archivo en la grilla de deudas y se setean el color de advertencia
				//con respecto a la fehca obtenida del sistema en el struct anterior
				for (int i=0; i<nueva_deuda.cantdeudores();i++){
					grilla_deudas->AppendRows(1);
					grilla_deudas->SetCellValue(nueva_deuda.accederdeudor(i).verapellido()+", "+nueva_deuda.accederdeudor(i).vernombre(),i,0);
					grilla_deudas->SetCellValue(nueva_deuda.accederdeudor(i).verdescripcion(),i,2);
					mystring=wxString::Format(wxT("%f"),(nueva_deuda.accederdeudor(i).vermonto()));
					grilla_deudas->SetCellValue("$ " + mystring,i,3);
					grilla_deudas->SetCellValue(wxString::Format(wxT("%i"),nueva_deuda.accederdeudor(i).verdia())+"/"+wxString::Format(wxT("%i"),(nueva_deuda.accederdeudor(i).vermes()))+"/"+wxString::Format(wxT("%i"),(nueva_deuda.accederdeudor(i).veranio())),i,1);
					if(nueva_deuda.accederdeudor(i).vermes()<(mes)){
						grilla_deudas->SetCellBackgroundColour(i,0, *wxRED);
						grilla_deudas->SetCellBackgroundColour(i,1, *wxRED);
						grilla_deudas->SetCellBackgroundColour(i,2, *wxRED);
						grilla_deudas->SetCellBackgroundColour(i,3, *wxRED);
					}
					else if (nueva_deuda.accederdeudor(i).vermes()>=mes && nueva_deuda.accederdeudor(i).veranio()<anio){
						grilla_deudas->SetCellBackgroundColour(i,0, *wxRED);
						grilla_deudas->SetCellBackgroundColour(i,1, *wxRED);
						grilla_deudas->SetCellBackgroundColour(i,2, *wxRED);
						grilla_deudas->SetCellBackgroundColour(i,3, *wxRED);
					}
					else {
						grilla_deudas->SetCellBackgroundColour(i,0, *wxWHITE);
						grilla_deudas->SetCellBackgroundColour(i,1, *wxWHITE);
						grilla_deudas->SetCellBackgroundColour(i,2, *wxWHITE);
						grilla_deudas->SetCellBackgroundColour(i,3, *wxWHITE);
					}
				}
				cantdeudas=nueva_deuda.cantdeudores();
				mystring=wxString::Format(wxT("%i"),cantdeudas);
				textototaldeudas->SetValue(mystring);
				//se hace lo mismo que en la grilla de deudas, se extraen los clientes con ventas programadas del archivo y se setean en la grilla
				//con sus respectivos colores
				for (int i=0; i<nueva_lista.cantclientes();i++){
					grilla_productos_a_entregar->AppendRows(1);
					grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(i).verapellido()+", "+nueva_lista.accedercliente(i).vernombre(),i,0);
					grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(i).verdetalle(),i,2);
					grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(i).vermodificaciones(),i,3);
					mystring=wxString::Format(wxT("%f"),(nueva_lista.accedercliente(i).vermonto()));
					grilla_productos_a_entregar->SetCellValue("$ " + mystring,i,4);
					grilla_productos_a_entregar->SetCellValue(wxString::Format(wxT("%i"),nueva_lista.accedercliente(i).verdia())+"/"+wxString::Format(wxT("%i"),(nueva_lista.accedercliente(i).vermes()))+"/"+wxString::Format(wxT("%i"),(nueva_lista.accedercliente(i).veranio())),i,1);
					if(nueva_lista.accedercliente(i).vermes()>mes && nueva_lista.accedercliente(i).veranio()==anio){
						grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxRED);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxRED);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxRED);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxRED);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxRED);
					}
					else if (nueva_lista.accedercliente(i).veranio()>anio){
						grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxRED);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxRED);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxRED);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxRED);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxRED);
					}
					else if (nueva_lista.accedercliente(i).vermes()==mes && nueva_lista.accedercliente(i).veranio()==anio && nueva_lista.accedercliente(i).verdia()>dia){
						grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxRED);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxRED);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxRED);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxRED);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxRED);
					}
					else if (nueva_lista.accedercliente(i).verdia()==dia && nueva_lista.accedercliente(i).vermes()==mes && nueva_lista.accedercliente(i).veranio()==anio){
						grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxBLUE);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxBLUE);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxBLUE);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxBLUE);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxBLUE);
					}
					else {
						grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxWHITE);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxWHITE);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxWHITE);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxWHITE);
						grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxWHITE);
					}
				}
				cantcomprasconfecha=nueva_lista.cantclientes();
				
				grilla_venta->SetSelectionMode(wxGrid::wxGridSelectRows);
				grilla_deudas->SetSelectionMode(wxGrid::wxGridSelectRows);
				grilla_productos_a_entregar->SetSelectionMode(wxGrid::wxGridSelectRows);
				totalcobrarventa->SetValue("$ " + wxString::Format(wxT("%f"),0.0));
				statusbar->SetLabel("Listo");
				
				Show();
				break;
			}
		}
	}
}

void VentanaPrincipal::OnBotonCerrar( wxCommandEvent& event ) { 
	Close();
}

void VentanaPrincipal::clickgrillaproductos( wxGridEvent& event )  {
	//se actualzia la barra de estado para dar informacion
	statusbar->SetLabel("Haga doble click para editar el producto de la venta");
	event.Skip();
}

void VentanaPrincipal::clickagregarprod( wxCommandEvent& event )  {
	//se crea un cuadro de dialogo en donde aparecen todos los productos contenidos en el stock
	agregarproductoventa nueva_ventana(this);
	if (nueva_ventana.ShowModal()==1){
		//una ves seleccionado el producto a agregar, aparece otro cuadro de dialogo que nos permite indicar que cantidad 
		//queremos sustraer del stock
		ventanacantidad nueva_ventana2(this,nueva_ventana.verprod().vercantidad());
		if(nueva_ventana2.ShowModal()==1){
			//concretado la indicacion de cantidad, se colocan los valores en la grilla
			grilla_venta->AppendRows(1);
			//creo una instancia del stock para usar en el programa
			
			producto p=nueva_ventana.verprod();
			int fila=nueva_ventana.verfilastock();
			int cantidadinicial=p.vercantidad();
			p.modificarcantidad(cantidadinicial-nueva_ventana2.vercant());
			nuevo_stock->reemplazar(p,fila);
			nuevo_stock->guardar();
			p.modificarcantidad(nueva_ventana2.vercant());
			nueva_venta.agregarproducto(p);
			int aux=(nueva_venta.cantidad_productos())-1;
			grilla_venta->SetCellValue(nueva_venta.accederprod(aux).vernombre(),aux,0);
			mystring=wxString::Format(wxT("%i"),(nueva_venta.accederprod(aux).vercantidad()));
			grilla_venta->SetCellValue(mystring,aux,1);
			mystring=wxString::Format(wxT("%f"),nueva_venta.totalprod(aux));
			grilla_venta->SetCellValue("$ " + mystring,aux,3);
			//notar que la fecha que aparece en la grilla es la misma del sistema, y no la fecha que aparece en la grila de stock
			grilla_venta->SetCellValue(wxString::Format(wxT("%i"),dia)+"/"+wxString::Format(wxT("%i"),mes)+"/"+wxString::Format(wxT("%i"),anio),aux,2);
			grilla_venta->SetCellValue(nueva_venta.accederprod(aux).verobservacion(),aux,4);
			mystring=wxString::Format(wxT("%f"),nueva_venta.vertotal());
			totalcobrarventa->SetValue("$ " + mystring);
		}
	}
}
//primero aparece un cuadro de advertencia, indicando que se eliminara el elemento
//y luego se elimina el producto de la grilla y del vector de productos en venta
void VentanaPrincipal::clickeliminarprod( wxCommandEvent& event )  {
	if (nueva_venta.cantidad_productos()==0){
		wxMessageBox("No es posible eliminar un producto ya que la lista esta vacía", "Error", wxOK);
	}
	else{
		int fila= grilla_venta->GetGridCursorRow();
		int respuesta= wxMessageBox("¿Eliminar el producto de la venta?",grilla_venta->GetCellValue(fila,0), wxYES_NO);
		if (respuesta==wxYES){
			int numstock=nuevo_stock->buscar(nueva_venta.accederprod(fila).vernombre());
			producto prod=nuevo_stock->accederprod(numstock);
			prod.modificarcantidad(prod.vercantidad()+nueva_venta.accederprod(fila).vercantidad());
			nuevo_stock->reemplazar(prod,nuevo_stock->buscar(nueva_venta.accederprod(fila).vernombre()));
			nuevo_stock->guardar();
			nueva_venta.eliminarproducto(fila);
			grilla_venta->DeleteRows(fila,1);
			mystring=wxString::Format(wxT("%f"),nueva_venta.vertotal());
			totalcobrarventa->SetValue("$ " + mystring);
		}
	}
}
//se borra completamente el vector de venta y el contenido de la grilla
//ademas se habilitan los botones en caso de que se haya aplicado descuento y por lo cual los botones se hayan deshablitado
void VentanaPrincipal::clickcancelarcompra( wxCommandEvent& event )  {
	if (nueva_venta.cantidad_productos()==0){
		wxMessageBox("No hay venta para cancelar","Error",wxOK);
	}
	else{
		int respuesta= wxMessageBox("¿Cancelar la venta?",grilla_venta->GetCellValue(0,0), wxYES_NO);
		if (respuesta==wxYES){
			for(int i=0; i<=nueva_venta.cantidad_productos(); i++){
				grilla_venta->DeleteRows(0,1);
			}
			for (int i=0; i<nueva_venta.cantidad_productos(); i++){
				grilla_venta->SelectRow(i);
				int numstock=nuevo_stock->buscar(nueva_venta.accederprod(i).vernombre());
				producto prod=nuevo_stock->accederprod(numstock);
				prod.modificarcantidad(prod.vercantidad()+nueva_venta.accederprod(i).vercantidad());
				nuevo_stock->reemplazar(prod,nuevo_stock->buscar(nueva_venta.accederprod(i).vernombre()));
				nuevo_stock->guardar();
				grilla_venta->DeleteRows(i,1);
			}
			nueva_venta.eliminarventa();
			mystring=wxString::Format(wxT("%f"),nueva_venta.vertotal());
			totalcobrarventa->SetValue("$ " + mystring);
			labeltotalacobrar->SetLabel("Total a cobrar");
			botonagregaraventa->Enable();
			botonquitarproductoventa->Enable();
			botondescuentoventa->Enable();
			grilla_venta->Enable();
		}
	}
}
//aqui le crea una instancia de la ventana que solicita el porcentaje de descuento
//y se actualiza el total de la venta
void VentanaPrincipal::clickdescuento( wxCommandEvent& event )  {
	if (nueva_venta.cantidad_productos()==0){
		wxMessageBox("No es posible asignar un descuento ya que la lista de productos de la venta esta vacia","Error",wxOK);
	}
	else{
		descuento nueva_ventana(this);
		if (nueva_ventana.ShowModal()==1){
			labeltotalacobrar->SetLabel("Total a cobrar con descuento aplicado");
			porcentdesc=nueva_ventana.ver_desc();
			nueva_venta.aplicardesc(porcentdesc);
			mystring=wxString::Format(wxT("%f"),nueva_venta.vertotal());
			totalcobrarventa->SetValue("$ " + mystring);
			botonagregaraventa->Disable();
			botonquitarproductoventa->Disable();
			botondescuentoventa->Disable();
			grilla_venta->Disable();
		}
	}
}

void VentanaPrincipal::clickdeuda( wxCommandEvent& event )  {
	if (nueva_venta.cantidad_productos()==0){
		wxMessageBox("No es posible agregar una deuda a la lista si no posee un monto a pagar", "Error", wxOK);
	}
	else {
		//se crea un deudor con los datos de la venta
		deudor nuevo_deudor;
		nuevo_deudor.modanio(anio);
		nuevo_deudor.moddia(dia);
		nuevo_deudor.modmes(mes);
		nombredeudor nueva_ventana(this);
		if (nueva_ventana.ShowModal()==1){
			cantdeudas++;
			//se completan lso datos del deudor y se agregan al vector de deudas
			mystring=wxString::Format(wxT("%i"),cantdeudas);
			textototaldeudas->SetValue(mystring);
			nuevo_deudor.modmonto(nueva_venta.vertotal()-nueva_ventana.versaldo());
			elementohistorial aux;
			aux.modificardia(dia);
			aux.modificarmes(mes);
			aux.modificaranio(anio);
			aux.modificarcosto(nueva_ventana.versaldo());
			aux.modificardetalles("Saldo pagado por " + nueva_ventana.verapellido() + ", " + nueva_ventana.vernombre());
			nuevo_histo->agregar(aux);
			nuevo_histo->guardar();
			nuevo_deudor.modnombre(nueva_ventana.vernombre());
			nuevo_deudor.modapellido(nueva_ventana.verapellido());
			for (int i=0; i<nueva_venta.cantidad_productos(); i++){
				if (nuevo_deudor.verdescripcion()==""){
					nuevo_deudor.moddescripcion(nuevo_deudor.verdescripcion() + nueva_venta.accederprod(i).vernombre());
				}
				else{
					nuevo_deudor.moddescripcion(nuevo_deudor.verdescripcion() +" - " + nueva_venta.accederprod(i).vernombre());
				}
			}
			//se actualiza la grilla de deudas
			nueva_deuda.agregardeudor(nuevo_deudor);
			grilla_deudas->AppendRows(1);
			for (int i=0; i<nueva_deuda.cantdeudores(); i++){
				grilla_deudas->SetCellValue(nueva_deuda.accederdeudor(i).verapellido() + ", " + nueva_deuda.accederdeudor(i).vernombre(),i,0);
				grilla_deudas->SetCellValue(wxString::Format(wxT("%i"),nueva_deuda.accederdeudor(i).verdia())+"/"+wxString::Format(wxT("%i"),nueva_deuda.accederdeudor(i).vermes())+"/"+wxString::Format(wxT("%i"),nueva_deuda.accederdeudor(i).veranio()),i,1);
				grilla_deudas->SetCellValue(nueva_deuda.accederdeudor(i).verdescripcion(),i,2);
				mystring=wxString::Format(wxT("%f"),(nueva_deuda.accederdeudor(i).vermonto()));
				grilla_deudas->SetCellValue("$ " + mystring,i,3);
			}
			nueva_deuda.guardar();
			for(int i=0; i<=nueva_venta.cantidad_productos(); i++){
				grilla_venta->DeleteRows(0,1);
			}
			//se eliminan los datos de la venta
			nueva_venta.eliminarventa();
			mystring=wxString::Format(wxT("%f"),nueva_venta.vertotal());
			totalcobrarventa->SetValue("$ " + mystring);
			labeltotalacobrar->SetLabel("Total a cobrar");
			botonagregaraventa->Enable();
			botonquitarproductoventa->Enable();
			botondescuentoventa->Enable();
			grilla_venta->Enable();
		}
	}
}

void VentanaPrincipal::clickchaucompra( wxCommandEvent& event )  {
	if (nueva_venta.cantidad_productos()==0){
		wxMessageBox("No se puede finalizar una venta si no posee un monto a pagar","Error", wxOK);
	}
	else {
		//se crea un elemento del historial con los datos de la venta
		int respuesta= wxMessageBox("Finalizar la venta?",grilla_venta->GetCellValue(0,0), wxYES_NO);
		if (respuesta==wxYES){
			for(int i=0; i<=nueva_venta.cantidad_productos(); i++){
				grilla_venta->DeleteRows(0,1);
			}
			elementohistorial e;
			e.modificaranio(anio);
			e.modificarmes(mes);
			e.modificardia(dia);
			e.modificarcosto(nueva_venta.vertotal());
			for (int i=0; i<nueva_venta.cantidad_productos(); i++){
				if (e.verdetalles()==""){
					e.modificardetalles(e.verdetalles() + nueva_venta.accederprod(i).vernombre()); 
				}
				else{
					e.modificardetalles(e.verdetalles() + " - " + nueva_venta.accederprod(i).vernombre()); 
				}
			}
			//se agrega el elemento al historial y se limpia todo lo referido a la venta de la grilal de ventas
			nuevo_histo->agregar(e);
			nuevo_histo->guardar();
			nueva_venta.eliminarventa();
			mystring=wxString::Format(wxT("%f"),nueva_venta.vertotal());
			totalcobrarventa->SetValue("$ " + mystring);
			labeltotalacobrar->SetLabel("Total a cobrar");
			botonagregaraventa->Enable();
			botonquitarproductoventa->Enable();
			botondescuentoventa->Enable();
			grilla_venta->Enable();
		}
	}
}

void VentanaPrincipal::cancelarbusqueda( wxCommandEvent& event )  {
	//cuando se hace click en cancelar busqueda se vuelven a colocar los labels originales
	buscardeudor->Clear();
	if (selectorgrilla->GetSelection()==0){
		labeltotaldeudas->SetLabel("Total de deudas");
		event.Skip();
	}
	else{
		labeltotaldeudas->SetLabel("Total de productos a entregar");
		event.Skip();
	}
}

void VentanaPrincipal::busquedaonthefly( wxCommandEvent& event )  {
	//se utiliza la funcion buscar de las clases deuda yproducto a entregar para crear el vector de posiciones
	//y luego actualizar la grilla con los elementos cuyas posiciones estan en el vector pos cada vez que se ingresa un caracter en la barra de busqueda
	vector<int> vecpos;
	if (selectorgrilla->GetSelection()==0){
		labeltotaldeudas->SetLabel("Total de deudas coincidentes con: "+buscardeudor->GetValue());
		nueva_deuda.buscar(buscardeudor->GetValue().c_str(),vecpos);
		grilla_deudas->DeleteRows(0,nueva_deuda.cantdeudores());
		grilla_deudas->AppendRows(vecpos.size());
		for(unsigned int i=0; i<vecpos.size();i++){
			grilla_deudas->SetCellValue(nueva_deuda.accederdeudor(*(vecpos.begin()+i)).verapellido() + ", " + nueva_deuda.accederdeudor(*(vecpos.begin()+i)).vernombre(),i,0);
			grilla_deudas->SetCellValue(wxString::Format(wxT("%i"),nueva_deuda.accederdeudor(*(vecpos.begin()+i)).verdia())+"/"+wxString::Format(wxT("%i"),nueva_deuda.accederdeudor(*(vecpos.begin()+i)).vermes())+"/"+wxString::Format(wxT("%i"),nueva_deuda.accederdeudor(*(vecpos.begin()+i)).veranio()),i,1);
			grilla_deudas->SetCellValue(nueva_deuda.accederdeudor(*(vecpos.begin()+i)).verdescripcion(),i,2);
			mystring=wxString::Format(wxT("%f"),(nueva_deuda.accederdeudor(*(vecpos.begin()+i)).vermonto()));
			grilla_deudas->SetCellValue("$ " + mystring,i,3);
			if(nueva_deuda.accederdeudor(*(vecpos.begin()+i)).vermes()<(mes)){
				grilla_deudas->SetCellBackgroundColour(i,0, *wxRED);
				grilla_deudas->SetCellBackgroundColour(i,1, *wxRED);
				grilla_deudas->SetCellBackgroundColour(i,2, *wxRED);
				grilla_deudas->SetCellBackgroundColour(i,3, *wxRED);
			}
			else if (nueva_deuda.accederdeudor(*(vecpos.begin()+i)).vermes()>=mes && nueva_deuda.accederdeudor(*(vecpos.begin()+i)).veranio()<anio){
				grilla_deudas->SetCellBackgroundColour(i,0, *wxRED);
				grilla_deudas->SetCellBackgroundColour(i,1, *wxRED);
				grilla_deudas->SetCellBackgroundColour(i,2, *wxRED);
				grilla_deudas->SetCellBackgroundColour(i,3, *wxRED);
			}
			else {
				grilla_deudas->SetCellBackgroundColour(i,0, *wxWHITE);
				grilla_deudas->SetCellBackgroundColour(i,1, *wxWHITE);
				grilla_deudas->SetCellBackgroundColour(i,2, *wxWHITE);
				grilla_deudas->SetCellBackgroundColour(i,3, *wxWHITE);
			}
		}
		mystring=wxString::Format(wxT("%i"),vecpos.size());
		textototaldeudas->SetValue(mystring);
	}
	else{
		labeltotaldeudas->SetLabel("Total de productos a entregar coincidentes con: "+buscardeudor->GetValue());
		nueva_lista.buscar(buscardeudor->GetValue().c_str(),vecpos);
		grilla_productos_a_entregar->DeleteRows(0,nueva_lista.cantclientes());
		grilla_productos_a_entregar->AppendRows(vecpos.size());
		for(unsigned int i=0; i<vecpos.size();i++){
			grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(*(vecpos.begin()+i)).verapellido() + ", " + nueva_lista.accedercliente(*(vecpos.begin()+i)).vernombre(),i,0);
			grilla_productos_a_entregar->SetCellValue(wxString::Format(wxT("%i"),nueva_lista.accedercliente(*(vecpos.begin()+i)).verdia())+"/"+wxString::Format(wxT("%i"),nueva_lista.accedercliente(*(vecpos.begin()+i)).vermes())+"/"+wxString::Format(wxT("%i"),nueva_lista.accedercliente(*(vecpos.begin()+i)).veranio()),i,1);
			grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(*(vecpos.begin()+i)).verdetalle(),i,2);
			mystring=wxString::Format(wxT("%f"),(nueva_lista.accedercliente(*(vecpos.begin()+i)).vermonto()));
			grilla_productos_a_entregar->SetCellValue("$ " + mystring,i,4);
			grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(*(vecpos.begin()+i)).vermodificaciones(),i,3);
			if(nueva_lista.accedercliente(*(vecpos.begin()+i)).vermes()<mes && nueva_lista.accedercliente(*(vecpos.begin()+i)).veranio()==anio){
				grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxRED);
			}
			else if (nueva_lista.accedercliente(*(vecpos.begin()+i)).veranio()<anio){
				grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxRED);
			}
			else if (nueva_lista.accedercliente(*(vecpos.begin()+i)).vermes()==mes && nueva_lista.accedercliente(*(vecpos.begin()+i)).veranio()==anio && nueva_lista.accedercliente(*(vecpos.begin()+i)).verdia()<dia){
				grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxRED);
			}
			else if (nueva_lista.accedercliente(*(vecpos.begin()+i)).verdia()==dia && nueva_lista.accedercliente(*(vecpos.begin()+i)).vermes()==mes && nueva_lista.accedercliente(*(vecpos.begin()+i)).veranio()==anio){
				grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxBLUE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxBLUE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxBLUE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxBLUE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxBLUE);
			}
			else {
				grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxWHITE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxWHITE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxWHITE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxWHITE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxWHITE);
			}
		}
		mystring=wxString::Format(wxT("%i"),vecpos.size());
		textototaldeudas->SetValue(mystring);
	}
}
//se setea un label a la barra de estado para brindar informacion adicional
void VentanaPrincipal::clickgrilladeudores( wxGridEvent& event )  {
	if (selectorgrilla->GetSelection()==0){
		statusbar->SetLabel("Haga doble click para editar la deuda");
		event.Skip();
	}
	else{
		statusbar->SetLabel("Haga doble click para editar el trabajo programado");
		event.Skip();
	}
}
//se elimina un deudor y sus registros sew borran sin llevarlos al historial
void VentanaPrincipal::clickeliminardeudor( wxCommandEvent& event )  {
	if(nueva_deuda.cantdeudores()==0){
		wxMessageBox("No existe ninguna deuda que eliminar","Error",wxOK);
	}
	else{
		int fila= grilla_deudas->GetGridCursorRow();
		int respuesta= wxMessageBox("Si elimina esta deuda, los datos se perderán y no seran registrados en el historial - ¿Esta seguro que desea eliminar esta deuda?", grilla_deudas->GetCellValue(fila,0),wxYES_NO);
		if (respuesta==wxYES){
			cantdeudas--;
			mystring=wxString::Format(wxT("%i"),cantdeudas);
			textototaldeudas->SetValue(mystring);
			nueva_deuda.eliminardeudor(fila);
			grilla_deudas->DeleteRows(fila,1);
			nueva_deuda.guardar();
		}
	}
}
//se abre la ventana de stock
void VentanaPrincipal::clickverstock( wxCommandEvent& event )  {
	stock nueva_ventana(this);
	nueva_ventana.ShowModal();
}

//se abre la ventana de historial
void VentanaPrincipal::clickverhistorial( wxCommandEvent& event )  {
	historial nueva_ventana(this);
	nueva_ventana.ShowModal();
}

//se abre la ventana de acerca de
void VentanaPrincipal::clickacercade( wxCommandEvent& event )  {
	acercade nueva_ventana(this);
	nueva_ventana.ShowModal();
}

//se obtiene la venta de la grilal y se modician sus valores
void VentanaPrincipal::clickeditarventa( wxGridEvent& event )  {
	agregarproducto nueva_ventana(this,nueva_venta.accederprod(grilla_venta->GetGridCursorRow()),true);
	if (nueva_ventana.ShowModal()==1){
		int pos=grilla_venta->GetGridCursorRow();
		nueva_venta.reemplazar(nueva_ventana.verprod(),pos);
		grilla_venta->SetCellValue(nueva_venta.accederprod(pos).vernombre(),pos,0);
		mystring=wxString::Format(wxT("%i"),(nueva_venta.accederprod(pos).vercantidad()));
		grilla_venta->SetCellValue(mystring,pos,1);
		mystring=wxString::Format(wxT("%f"),nueva_venta.totalprod(pos));
		grilla_venta->SetCellValue("$ " + mystring,pos,3);
		grilla_venta->SetCellValue(wxString::Format(wxT("%i"),dia)+"/"+wxString::Format(wxT("%i"),mes)+"/"+wxString::Format(wxT("%i"),anio),pos,2);
		grilla_venta->SetCellValue(nueva_venta.accederprod(pos).verobservacion(),pos,4);
		mystring=wxString::Format(wxT("%f"),nueva_venta.vertotal());
		totalcobrarventa->SetValue("$ " + mystring);
	}
}
//se obtiene la venta programada de la grilla y se modifican sus valores en su vector inclusive
void VentanaPrincipal::clickeditardeuda( wxGridEvent& event )  {
	if (selectorgrilla->GetSelection()==0){
		editardeuda nueva_ventana(this,nueva_deuda.accederdeudor(grilla_deudas->GetGridCursorRow()));
		if (nueva_ventana.ShowModal()==1){
			int pos=grilla_deudas->GetGridCursorRow();
			nueva_deuda.reemplazar(nueva_ventana.verdeudor(),pos);
			grilla_deudas->SetCellValue(nueva_deuda.accederdeudor(pos).verapellido()+", "+nueva_deuda.accederdeudor(pos).vernombre(),pos,0);
			grilla_deudas->SetCellValue(wxString::Format(wxT("%i"),nueva_deuda.accederdeudor(pos).verdia())+"/"+wxString::Format(wxT("%i"),nueva_deuda.accederdeudor(pos).vermes())+"/"+wxString::Format(wxT("%i"),nueva_deuda.accederdeudor(pos).veranio()),pos,1);
			grilla_deudas->SetCellValue(nueva_deuda.accederdeudor(pos).verdescripcion(),pos,2);
			mystring=wxString::Format(wxT("%f"),nueva_deuda.accederdeudor(pos).vermonto());
			grilla_deudas->SetCellValue("$ " + mystring,pos,3);
			if(nueva_deuda.accederdeudor(pos).vermes()<(mes)){
				grilla_deudas->SetCellBackgroundColour(pos,0, *wxRED);
				grilla_deudas->SetCellBackgroundColour(pos,1, *wxRED);
				grilla_deudas->SetCellBackgroundColour(pos,2, *wxRED);
				grilla_deudas->SetCellBackgroundColour(pos,3, *wxRED);
			}
			else if (nueva_deuda.accederdeudor(pos).vermes()>=mes && nueva_deuda.accederdeudor(pos).veranio()<anio){
				grilla_deudas->SetCellBackgroundColour(pos,0, *wxRED);
				grilla_deudas->SetCellBackgroundColour(pos,1, *wxRED);
				grilla_deudas->SetCellBackgroundColour(pos,2, *wxRED);
				grilla_deudas->SetCellBackgroundColour(pos,3, *wxRED);
			}
			else {
				grilla_deudas->SetCellBackgroundColour(pos,0, *wxWHITE);
				grilla_deudas->SetCellBackgroundColour(pos,1, *wxWHITE);
				grilla_deudas->SetCellBackgroundColour(pos,2, *wxWHITE);
				grilla_deudas->SetCellBackgroundColour(pos,3, *wxWHITE);
			}
			nueva_deuda.guardar();
		}
	}
	else {
		//lo mismo pero para deudas
		editardeuda nueva_ventana(this,nueva_lista.accedercliente(grilla_productos_a_entregar->GetGridCursorRow()));
		if (nueva_ventana.ShowModal()==1){
			int pos=grilla_productos_a_entregar->GetGridCursorRow();
			nueva_lista.reemplazar(nueva_ventana.vercliente(),pos);
			grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(pos).verapellido()+", "+nueva_lista.accedercliente(pos).vernombre(),pos,0);
			grilla_productos_a_entregar->SetCellValue(wxString::Format(wxT("%i"),nueva_lista.accedercliente(pos).verdia())+"/"+wxString::Format(wxT("%i"),nueva_lista.accedercliente(pos).vermes())+"/"+wxString::Format(wxT("%i"),nueva_lista.accedercliente(pos).veranio()),pos,1);
			grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(pos).verdetalle(),pos,2);
			mystring=wxString::Format(wxT("%f"),nueva_lista.accedercliente(pos).vermonto());
			grilla_productos_a_entregar->SetCellValue("$ " + mystring,pos,4);
			grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(pos).vermodificaciones(),pos,3);
			if(nueva_lista.accedercliente(pos).vermes()<mes && nueva_lista.accedercliente(pos).veranio()==anio){
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,0, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,1, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,2, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,3, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,4, *wxRED);
			}
			else if (nueva_lista.accedercliente(pos).veranio()<anio){
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,0, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,1, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,2, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,3, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,4, *wxRED);
			}
			else if (nueva_lista.accedercliente(pos).vermes()==mes && nueva_lista.accedercliente(pos).veranio()==anio && nueva_lista.accedercliente(pos).verdia()<dia){
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,0, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,1, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,2, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,3, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,4, *wxRED);
			}
			else if (nueva_lista.accedercliente(pos).verdia()==dia && nueva_lista.accedercliente(pos).vermes()==mes && nueva_lista.accedercliente(pos).veranio()==anio){
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,0, *wxBLUE);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,1, *wxBLUE);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,2, *wxBLUE);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,3, *wxBLUE);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,4, *wxBLUE);
			}
			else {
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,0, *wxWHITE);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,1, *wxWHITE);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,2, *wxWHITE);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,3, *wxWHITE);
				grilla_productos_a_entregar->SetCellBackgroundColour(pos,4, *wxWHITE);
			}
			nueva_lista.guardar();
		}
	}
}
//se eliminan los datos de la deuda y se agregan al historial como deuda saldada por...
void VentanaPrincipal::clicksaldardeuda( wxCommandEvent& event )  {
	if(nueva_deuda.cantdeudores()==0){
		wxMessageBox("No existe ninguna deuda que saldar","Error",wxOK);
	}
	else{
		int resp=wxMessageBox("Al saldar la deuda de " + nueva_deuda.accederdeudor(grilla_deudas->GetGridCursorRow()).verapellido() + ", " + nueva_deuda.accederdeudor(grilla_deudas->GetGridCursorRow()).vernombre() + " el registro se guardara en el historial y se borrara permanentemente de esta lista. ¿Desea continuar?", nueva_deuda.accederdeudor(grilla_deudas->GetGridCursorRow()).verapellido() + ", " + nueva_deuda.accederdeudor(grilla_deudas->GetGridCursorRow()).vernombre(),wxYES_NO);
		if (resp==wxYES){
			elementohistorial aux;
			int fila= grilla_deudas->GetGridCursorRow();
			deudor aux2=nueva_deuda.accederdeudor(fila);
			aux.modificarcosto(aux2.vermonto());
			aux.modificardia(aux2.verdia());
			aux.modificarmes(aux2.vermes());
			aux.modificaranio(aux2.veranio());
			aux.modificardetalles("Deuda pagada por " + aux2.verapellido() + ", " + aux2.vernombre() + ". Productos vendidos: " + aux2.verdescripcion().c_str());
			nuevo_histo->agregar(aux);
			nuevo_histo->guardar();
			cantdeudas--;
			mystring=wxString::Format(wxT("%i"),cantdeudas);
			textototaldeudas->SetValue(mystring);
			nueva_deuda.eliminardeudor(fila);
			grilla_deudas->DeleteRows(fila,1);
			nueva_deuda.guardar();
		}
	}
}

//se muestra la ventana de gastos externos
void VentanaPrincipal::clickvergastosexternos( wxCommandEvent& event )  {
	gastoexterno nueva_ventana(this);
	nueva_ventana.ShowModal();
}
//funcion para cuando cambia entr grilla de deudores y grilla de productos encargados
void VentanaPrincipal::selecciongrilla( wxCommandEvent& event )  {
	if (selectorgrilla->GetSelection()==1){
		labeltitulodeudas->SetLabel("Productos a entregar");
		labeltotaldeudas->SetLabel("Total de productos a entregar");
		textototaldeudas->SetValue(wxString::Format(wxT("%i"),cantcomprasconfecha));
		boton1grilladeuda->Hide();
		boton2grilladeuda->Hide();
		grilla_productos_a_entregar->Show();
		boton1grillaproductos->Show();
		boton2grillaproductos->Show();
		for (int i=0; i<nueva_lista.cantclientes();i++){
			if(nueva_lista.accedercliente(i).vermes()<mes && nueva_lista.accedercliente(i).veranio()==anio){
				grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxRED);
			}
			else if (nueva_lista.accedercliente(i).veranio()<anio){
				grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxRED);
			}
			else if (nueva_lista.accedercliente(i).vermes()==mes && nueva_lista.accedercliente(i).veranio()==anio && nueva_lista.accedercliente(i).verdia()<dia){
				grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxRED);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxRED);
			}
			else if (nueva_lista.accedercliente(i).verdia()==dia && nueva_lista.accedercliente(i).vermes()==mes && nueva_lista.accedercliente(i).veranio()==anio){
				grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxBLUE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxBLUE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxBLUE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxBLUE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxBLUE);
			}
			else {
				grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxWHITE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxWHITE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxWHITE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxWHITE);
				grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxWHITE);
			}
		}
		grilla_deudas->Hide();
		grilla_productos_a_entregar->ForceRefresh();
		Layout();
		
	}
	else{
		labeltitulodeudas->SetLabel("Deudas");
		labeltotaldeudas->SetLabel("Total de deudas");
		textototaldeudas->SetValue(wxString::Format(wxT("%i"),cantdeudas));
		boton1grilladeuda->Show();
		boton2grilladeuda->Show();
		grilla_productos_a_entregar->Hide();
		boton1grillaproductos->Hide();
		boton2grillaproductos->Hide();
		grilla_deudas->Show();
		for (int i=0; i<nueva_deuda.cantdeudores();i++){
			if(nueva_deuda.accederdeudor(i).vermes()<(mes)){
				grilla_deudas->SetCellBackgroundColour(i,0, *wxRED);
				grilla_deudas->SetCellBackgroundColour(i,1, *wxRED);
				grilla_deudas->SetCellBackgroundColour(i,2, *wxRED);
				grilla_deudas->SetCellBackgroundColour(i,3, *wxRED);
			}
			else if (nueva_deuda.accederdeudor(i).vermes()>=mes && nueva_deuda.accederdeudor(i).veranio()<anio){
				grilla_deudas->SetCellBackgroundColour(i,0, *wxRED);
				grilla_deudas->SetCellBackgroundColour(i,1, *wxRED);
				grilla_deudas->SetCellBackgroundColour(i,2, *wxRED);
				grilla_deudas->SetCellBackgroundColour(i,3, *wxRED);
			}
			else {
				grilla_deudas->SetCellBackgroundColour(i,0, *wxWHITE);
				grilla_deudas->SetCellBackgroundColour(i,1, *wxWHITE);
				grilla_deudas->SetCellBackgroundColour(i,2, *wxWHITE);
				grilla_deudas->SetCellBackgroundColour(i,3, *wxWHITE);
			}
		}
		grilla_deudas->ForceRefresh();
		Layout();
	}
}
//se toman todos lso datos de la venta y se crea una nueva venta por encargo y se agrega al vector correspondiente
//luego se borran todos los datos de la venta
void VentanaPrincipal::click_producto_a_entregar( wxCommandEvent& event )  {
	if (nueva_venta.cantidad_productos()==0){
		wxMessageBox("No es posible agregar a la lista de productos a entregar si no posee un monto a pagar", "Error", wxOK);
	}
	else {
		cliente nuevo_cliente;
		nombrecompraconfecha nueva_ventana(this);
		if (nueva_ventana.ShowModal()==1){
			cantcomprasconfecha++;
			mystring=wxString::Format(wxT("%i"),cantcomprasconfecha);
			textototaldeudas->SetValue(mystring);
			nuevo_cliente.modanio(nueva_ventana.veranio());
			nuevo_cliente.moddia(nueva_ventana.verdia());
			nuevo_cliente.modmes(nueva_ventana.vermes());
			nuevo_cliente.modmonto(nueva_venta.vertotal());
			nuevo_cliente.modnombre(nueva_ventana.vernombre());
			nuevo_cliente.modmodificaciones(nueva_ventana.vermod());
			nuevo_cliente.modapellido(nueva_ventana.verapellido());
			for (int i=0; i<nueva_venta.cantidad_productos(); i++){
				if (nuevo_cliente.verdetalle()==""){
					nuevo_cliente.moddetalles(nuevo_cliente.verdetalle() + nueva_venta.accederprod(i).vernombre());
				}
				else{
					nuevo_cliente.moddetalles(nuevo_cliente.verdetalle() + " - " + nueva_venta.accederprod(i).vernombre());
				}
			}
			nueva_lista.agregarcliente(nuevo_cliente);
			grilla_productos_a_entregar->AppendRows(1);
			for (int i=0; i<nueva_lista.cantclientes(); i++){
				grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(i).verapellido() + ", " + nueva_lista.accedercliente(i).vernombre(),i,0);
				grilla_productos_a_entregar->SetCellValue(wxString::Format(wxT("%i"),nueva_lista.accedercliente(i).verdia())+"/"+wxString::Format(wxT("%i"),nueva_lista.accedercliente(i).vermes())+"/"+wxString::Format(wxT("%i"),nueva_lista.accedercliente(i).veranio()),i,1);
				grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(i).verdetalle(),i,2);
				grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(i).vermodificaciones(),i,3);
				mystring=wxString::Format(wxT("%f"),(nueva_lista.accedercliente(i).vermonto()));
				grilla_productos_a_entregar->SetCellValue("$ " + mystring,i,4);
				if(nueva_lista.accedercliente(i).vermes()<mes && nueva_lista.accedercliente(i).veranio()==anio){
					grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxRED);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxRED);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxRED);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxRED);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxRED);
				}
				else if (nueva_lista.accedercliente(i).veranio()<anio){
					grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxRED);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxRED);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxRED);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxRED);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxRED);
				}
				else if (nueva_lista.accedercliente(i).vermes()==mes && nueva_lista.accedercliente(i).veranio()==anio && nueva_lista.accedercliente(i).verdia()<dia){
					grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxRED);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxRED);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxRED);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxRED);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxRED);
				}
				else if (nueva_lista.accedercliente(i).verdia()==dia && nueva_lista.accedercliente(i).vermes()==mes && nueva_lista.accedercliente(i).veranio()==anio){
					grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxBLUE);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxBLUE);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxBLUE);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxBLUE);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxBLUE);
				}
				else {
					grilla_productos_a_entregar->SetCellBackgroundColour(i,0, *wxWHITE);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,1, *wxWHITE);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,2, *wxWHITE);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,3, *wxWHITE);
					grilla_productos_a_entregar->SetCellBackgroundColour(i,4, *wxWHITE);
				}
			}
			nueva_lista.guardar();
			for(int i=0; i<=nueva_venta.cantidad_productos(); i++){
				grilla_venta->DeleteRows(0,1);
			}
			nueva_venta.eliminarventa();
			mystring=wxString::Format(wxT("%f"),nueva_venta.vertotal());
			totalcobrarventa->SetValue("$ " + mystring);
			labeltotalacobrar->SetLabel("Total a cobrar");
			botonagregaraventa->Enable();
			botonquitarproductoventa->Enable();
			botondescuentoventa->Enable();
			grilla_venta->Enable();
		}
	}
}


//se crea un nuevo elemento del historial con los datos de la venta por encargo y se lo agrega al historial
//luego se elimina todo los detalles de la venta por encargo
void VentanaPrincipal::clickfinalizaranticipado( wxCommandEvent& event )  {
	if(nueva_lista.cantclientes()==0){
		wxMessageBox("No existe ninguna venta programada que finalizar","Error",wxOK);
	}
	else{
		int resp=wxMessageBox("Al finalizar la venta programada de " + nueva_lista.accedercliente(grilla_productos_a_entregar->GetGridCursorRow()).verapellido() + ", " + nueva_lista.accedercliente(grilla_productos_a_entregar->GetGridCursorRow()).vernombre() + " el registro se guardara en el historial y se borrara permanentemente de esta lista. ¿Desea continuar?", nueva_lista.accedercliente(grilla_productos_a_entregar->GetGridCursorRow()).verapellido()+", "+nueva_lista.accedercliente(grilla_productos_a_entregar->GetGridCursorRow()).vernombre(),wxYES_NO);
		if (resp==wxYES){	
			elementohistorial aux;
			int fila= grilla_productos_a_entregar->GetGridCursorRow();
			cliente aux2=nueva_lista.accedercliente(fila);
			aux.modificarcosto(aux2.vermonto());
			aux.modificardia(dia);
			aux.modificarmes(mes);
			aux.modificaranio(anio);
			aux.modificardetalles("Venta programada pagada por " + aux2.verapellido() + ", " + aux2.vernombre() + ". Productos vendidos: " + aux2.verdetalle().c_str());
			nuevo_histo->agregar(aux);
			nuevo_histo->guardar();
			cantcomprasconfecha--;
			mystring=wxString::Format(wxT("%i"),cantcomprasconfecha);
			textototaldeudas->SetValue(mystring);
			nueva_lista.eliminarcliente(fila);
			grilla_productos_a_entregar->DeleteRows(fila,1);
			nueva_lista.guardar();
		}
	}
}

//se eliminan los datos de la venta enticipada sin agregarlos al historial
void VentanaPrincipal::clickeliminaranticipado( wxCommandEvent& event )  {
	if(nueva_lista.cantclientes()==0){
		wxMessageBox("No existe ninguna venta programada que eliminar","Error",wxOK);
	}
	else{
		int fila= grilla_productos_a_entregar->GetGridCursorRow();
		int respuesta= wxMessageBox("Si elimina esta venta programada, se borraran completamente los registros de la venta - ¿Esta seguro que desea eliminarla?", grilla_productos_a_entregar->GetCellValue(fila,0),wxYES_NO);
		if (respuesta==wxYES){
			cantcomprasconfecha--;
			mystring=wxString::Format(wxT("%i"),cantcomprasconfecha);
			textototaldeudas->SetValue(mystring);
			nueva_lista.eliminarcliente(fila);
			grilla_productos_a_entregar->DeleteRows(fila,1);
			nueva_lista.guardar();
		}
	}
}

//se crea una ventana para crear un nuevo usuario
void VentanaPrincipal::clicknuevouser( wxCommandEvent& event )  {
	ventananuevouser nueva_ventana(this);
	nueva_ventana.ShowModal();
}

//se abre el archivo excel con los datos cargados y se preg si se quiere imprimir, y se dal a opcion de guardar el archivo aparte
void VentanaPrincipal::clickexportarhistorial( wxCommandEvent& event )  {
	if (nuevo_histo->cantprod()==0){
		wxMessageBox("El historial esta vacío","Advertencia",wxOK);
	}
	else{
		ExcelManipulator e("historial.xlsx",true);
		if (!e.IsOpen()) { wxMessageBox("El archivo no se ha abierto correctamente","Error",wxOK);}
		char det[256];
		for (int i=0; i<nuevo_histo->cantprod(); i++){
			e.SetValue(i+3,1,wxString::Format(wxT("%i"),nuevo_histo->accederprod(i).verdia()) + "/" + wxString::Format(wxT("%i"),nuevo_histo->accederprod(i).vermes()) + "/" + wxString::Format(wxT("%i"),nuevo_histo->accederprod(i).veranio()));
			strcpy(det,nuevo_histo->accederprod(i).verdetalles().c_str());
			e.SetValue(i+3,2,det);
			e.SetValue(i+3,4,wxString::Format(wxT("%f"),nuevo_histo->accederprod(i).vercosto()));
		}
		remove("Historial guardado - Supra Market");
		e.SaveAs("Historial guardado - Supra Market");
		int resp=wxMessageBox("El archivo se ha guardado en el directorio de Supra Market - ¿Desea imprimir el archivo excel en un formato .PDF?","Atención",wxYES_NO);
		if (resp==wxYES){
			e.Print();
		}
	}
}

//se abre el archivo excel con los datos cargados y se preg si se quiere imprimir, y se dal a opcion de guardar el archivo aparte
void VentanaPrincipal::clickexportarstock( wxCommandEvent& event )  {
	if (nuevo_stock->cantprod()==0){
		wxMessageBox("El stock esta vacío","Advertencia",wxOK);
	}
	else{
		ExcelManipulator e("Stock.xlsx",true);
		if (!e.IsOpen()) { wxMessageBox("El archivo no se ha abierto correctamente","Error",wxOK);}
		char det[256];
		for (int i=0; i<nuevo_stock->cantprod(); i++){
			strcpy(det,nuevo_stock->accederprod(i).vernombre().c_str());
			e.SetValue(i+3,1,det);
			e.SetValue(i+3,2,wxString::Format(wxT("%i"),nuevo_stock->accederprod(i).vercantidad()));
			e.SetValue(i+3,3,wxString::Format(wxT("%i"),nuevo_stock->accederprod(i).vercodigo()));
			e.SetValue(i+3,4,wxString::Format(wxT("%f"),nuevo_stock->accederprod(i).vercosto()));
			strcpy(det,nuevo_stock->accederprod(i).verobservacion().c_str());
			e.SetValue(i+3,5,det);
		}
		remove("Stock guardado - Supra Market");
		e.SaveAs("Stock guardado - Supra Market");
		int resp=wxMessageBox("El archivo se ha guardado en el directorio de Supra Market - ¿Desea imprimir el archivo excel en un formato .PDF?","Atención",wxYES_NO);
		if (resp==wxYES){
			e.Print();
		}
	}
}

//se ordena la grilla de deudas
void VentanaPrincipal::clickordenardeudas( wxGridEvent& event )  {
	int columna=event.GetCol(), c_prod=nueva_deuda.cantdeudores();
	switch(columna) {
	case 0: nueva_deuda.Ordenar(ORDEN_NOMBRE); break;
	case 1: nueva_deuda.Ordenar(ORDEN_FECHA); break;
	case 3: nueva_deuda.Ordenar(ORDEN_TOTAL); break;
	}
	for (int i=0; i<c_prod; i++){
		grilla_deudas->SetCellValue(nueva_deuda.accederdeudor(i).verapellido() + ", " + nueva_deuda.accederdeudor(i).vernombre(),i,0);
		grilla_deudas->SetCellValue(wxString::Format(wxT("%i"),nueva_deuda.accederdeudor(i).verdia())+"/"+wxString::Format(wxT("%i"),nueva_deuda.accederdeudor(i).vermes())+"/"+wxString::Format(wxT("%i"),nueva_deuda.accederdeudor(i).veranio()),i,1);
		grilla_deudas->SetCellValue(nueva_deuda.accederdeudor(i).verdescripcion(),i,2);
		mystring=wxString::Format(wxT("%f"),(nueva_deuda.accederdeudor(i).vermonto()));
		grilla_deudas->SetCellValue("$ " + mystring,i,3);
	}
}

//se abre el lactor de pdf predeterminado y se muestra el manual
void VentanaPrincipal::clickmanualdeusuario( wxCommandEvent& event )  {
	ShellExecute(GetDesktopWindow(), "open", "Manual de Usuario.pdf", NULL, NULL, SW_SHOWNORMAL);
}

void VentanaPrincipal::clickordenargrillaencargo( wxGridEvent& event )  {
	int columna=event.GetCol(), c_prod=nueva_lista.cantclientes();
	switch(columna) {
	case 0: nueva_lista.Ordenar(ORDEN_NOMBRE2); break;
	case 1: nueva_lista.Ordenar(ORDEN_FECHA2); break;
	case 4: nueva_lista.Ordenar(ORDEN_TOTAL2); break;
	}
	for (int i=0; i<c_prod; i++){
		grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(i).verapellido() + ", " + nueva_lista.accedercliente(i).vernombre(),i,0);
		grilla_productos_a_entregar->SetCellValue(wxString::Format(wxT("%i"),nueva_lista.accedercliente(i).verdia())+"/"+wxString::Format(wxT("%i"),nueva_lista.accedercliente(i).vermes())+"/"+wxString::Format(wxT("%i"),nueva_lista.accedercliente(i).veranio()),i,1);
		grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(i).verdetalle(),i,2);
		mystring=wxString::Format(wxT("%f"),(nueva_lista.accedercliente(i).vermonto()));
		grilla_productos_a_entregar->SetCellValue("$ " + mystring,i,4);
		grilla_productos_a_entregar->SetCellValue(nueva_lista.accedercliente(i).vermodificaciones(),i,3);
	}
}
//aqui se borran fisicamente todos los archivos relacionados al programa y vuelve a su estado inicial
//incluso se borran los usuarios
void VentanaPrincipal::clickvolverfab( wxCommandEvent& event )  {
	int resp=wxMessageBox("Al hacer esto, el programa se cerrarar y se borrarán todos los registros del programa, incluida la lista de usuarios. ¿Está seguro que desea continuar?","Advertencia",wxYES_NO);
	if (resp==wxYES){
		remove("deud.list");
		remove("hist.list");
		remove("prod.list");
		remove("prodtemp.list");
		remove("users.list");
		wxMessageBox("El programa se cerrara...","Limpiesa completada",wxOK);
		ofstream archi("num.ver", ios_base::in);
		char a='0';
		archi<<a;
		archi.close();
		Close();
	}
}
//pantalla donde ingreso usuario y contraseña actual y si esta todo ok
//me permite cambiar mi contraseña
void VentanaPrincipal::clickeditarpass( wxCommandEvent& event )  {
	ventanacambiarpass nueva_ventana(this);
	nueva_ventana.ShowModal();
}

