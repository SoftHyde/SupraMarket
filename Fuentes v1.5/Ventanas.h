///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#ifndef __VENTANAS_H__
#define __VENTANAS_H__

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/grid.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/bmpbuttn.h>
#include <wx/button.h>
#include <wx/statbmp.h>
#include <wx/srchctrl.h>
#include <wx/choice.h>
#include <wx/menu.h>
#include <wx/statusbr.h>
#include <wx/frame.h>
#include <wx/dialog.h>
#include <wx/checkbox.h>
#include <wx/datectrl.h>
#include <wx/dateevt.h>
#include <wx/hyperlink.h>
#include <wx/calctrl.h>
#include <wx/statline.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Frame0
///////////////////////////////////////////////////////////////////////////////
class Frame0 : public wxFrame 
{
	private:
	
	protected:
		wxStaticText* m_staticText11;
		wxGrid* grilla_venta;
		wxStaticText* labeltotalacobrar;
		wxTextCtrl* totalcobrarventa;
		wxBitmapButton* botonagregaraventa;
		wxBitmapButton* botonquitarproductoventa;
		wxStaticBitmap* m_bitmap3;
		wxStaticText* m_staticText19;
		wxBitmapButton* botoncancelarventa;
		wxBitmapButton* botonconcretar;
		wxBitmapButton* botondeuda;
		wxBitmapButton* botondescuentoventa;
		wxBitmapButton* botonfinalizar;
		wxStaticText* labeltitulodeudas;
		wxSearchCtrl* buscardeudor;
		wxChoice* selectorgrilla;
		wxGrid* grilla_deudas;
		wxGrid* grilla_productos_a_entregar;
		wxStaticText* labeltotaldeudas;
		wxTextCtrl* textototaldeudas;
		wxBitmapButton* boton1grilladeuda;
		wxBitmapButton* boton2grilladeuda;
		wxBitmapButton* boton1grillaproductos;
		wxBitmapButton* boton2grillaproductos;
		wxMenuBar* m_menubar1;
		wxMenu* m_menu1;
		wxMenu* m_menu3;
		wxMenu* m_menu4;
		wxMenu* m_menu2;
		wxStatusBar* statusbar;
		
		// Virtual event handlers, overide them in your derived class
		virtual void clickgrillaproductos( wxGridEvent& event ) { event.Skip(); }
		virtual void clickeditarventa( wxGridEvent& event ) { event.Skip(); }
		virtual void clickagregarprod( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickeliminarprod( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickcancelarcompra( wxCommandEvent& event ) { event.Skip(); }
		virtual void click_producto_a_entregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickdeuda( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickdescuento( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickchaucompra( wxCommandEvent& event ) { event.Skip(); }
		virtual void cancelarbusqueda( wxCommandEvent& event ) { event.Skip(); }
		virtual void busquedaonthefly( wxCommandEvent& event ) { event.Skip(); }
		virtual void selecciongrilla( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickgrilladeudores( wxGridEvent& event ) { event.Skip(); }
		virtual void clickeditardeuda( wxGridEvent& event ) { event.Skip(); }
		virtual void clickordenardeudas( wxGridEvent& event ) { event.Skip(); }
		virtual void clickordenargrillaencargo( wxGridEvent& event ) { event.Skip(); }
		virtual void clicksaldardeuda( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickeliminardeudor( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickfinalizaranticipado( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickeliminaranticipado( wxCommandEvent& event ) { event.Skip(); }
		virtual void clicknuevouser( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickeditarpass( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickvolverfab( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickverstock( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickverhistorial( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickvergastosexternos( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickexportarhistorial( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickexportarstock( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickacercade( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickmanualdeusuario( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		Frame0( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 1488,648 ), long style = wxDEFAULT_FRAME_STYLE|wxMAXIMIZE|wxTAB_TRAVERSAL );
		
		~Frame0();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog14
///////////////////////////////////////////////////////////////////////////////
class MyDialog14 : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText42;
		wxTextCtrl* textouser;
		wxStaticText* m_staticText43;
		wxTextCtrl* textopass;
		wxStaticText* m_staticText56;
		wxChoice* choiserpreg;
		wxStaticText* m_staticText57;
		wxTextCtrl* textoresp;
		wxBitmapButton* m_bpButton34;
		wxBitmapButton* m_bpButton35;
		
		// Virtual event handlers, overide them in your derived class
		virtual void enteraceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickcrear( wxCommandEvent& event ) { event.Skip(); }
		virtual void cliclcancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog14( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Nuevo usuario invitado"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 306,326 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog14();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog81
///////////////////////////////////////////////////////////////////////////////
class MyDialog81 : public wxDialog 
{
	private:
	
	protected:
		wxCheckBox* checksaldo;
		wxTextCtrl* textosaldo;
		wxStaticText* m_staticText23;
		wxTextCtrl* textonombre;
		wxStaticText* m_staticText24;
		wxTextCtrl* textoapellido;
		wxBitmapButton* m_button13;
		wxBitmapButton* m_button14;
		
		// Virtual event handlers, overide them in your derived class
		virtual void checksaldoon( wxCommandEvent& event ) { event.Skip(); }
		virtual void enteraceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickaceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickcancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog81( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar deuda"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 242,276 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog81();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog11
///////////////////////////////////////////////////////////////////////////////
class MyDialog11 : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText45;
		wxStaticText* m_staticText37;
		wxTextCtrl* textonombre;
		wxStaticText* m_staticText38;
		wxTextCtrl* textoapellido;
		wxStaticText* m_staticText401;
		wxTextCtrl* textomodificaciones;
		wxBitmapButton* m_bpButton29;
		wxBitmapButton* m_bpButton30;
		
		// Virtual event handlers, overide them in your derived class
		virtual void enteraceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickaceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickcancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		wxDatePickerCtrl* cosofecha;
		
		MyDialog11( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar encargo"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 324,332 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog11();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog7
///////////////////////////////////////////////////////////////////////////////
class MyDialog7 : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText20;
		wxTextCtrl* textonombre;
		wxStaticText* m_staticText26;
		wxTextCtrl* textoapellido;
		wxStaticText* m_staticText21;
		wxTextCtrl* textodesc;
		wxStaticText* labelmodificaciones;
		wxTextCtrl* textomodificaciones;
		wxStaticText* m_staticText22;
		wxTextCtrl* textomonto;
		wxStaticText* m_staticText23;
		wxTextCtrl* textodia;
		wxStaticText* m_staticText24;
		wxTextCtrl* textomes;
		wxStaticText* m_staticText25;
		wxTextCtrl* textoanio;
		wxBitmapButton* m_button11;
		wxBitmapButton* m_button12;
		
		// Virtual event handlers, overide them in your derived class
		virtual void enteraceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickaceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickcancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog7( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Editar deuda"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 451,263 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog7();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog6
///////////////////////////////////////////////////////////////////////////////
class MyDialog6 : public wxDialog 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmap3;
		wxStaticText* m_staticText24;
		wxStaticText* m_staticText25;
		wxHyperlinkCtrl* m_hyperlink1;
		wxStaticText* m_staticText22;
		wxHyperlinkCtrl* m_hyperlink2;
		wxStaticBitmap* m_bitmap2;
	
	public:
		
		MyDialog6( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Acerca de"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 616,345 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog6();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog8
///////////////////////////////////////////////////////////////////////////////
class MyDialog8 : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText17;
		wxTextCtrl* textonombre;
		wxStaticText* m_staticText18;
		wxTextCtrl* textocantidad;
		wxStaticText* m_staticText19;
		wxTextCtrl* textocodigo;
		wxStaticText* m_staticText20;
		wxTextCtrl* textocosto;
		wxStaticText* m_staticText21;
		wxTextCtrl* textoobservacion;
		wxStaticText* m_staticText27;
		wxTextCtrl* textodia;
		wxStaticText* m_staticText28;
		wxTextCtrl* textomes;
		wxStaticText* m_staticText29;
		wxTextCtrl* textoanio;
		wxBitmapButton* m_button20;
		wxBitmapButton* m_button21;
		
		// Virtual event handlers, overide them in your derived class
		virtual void enteraceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickagregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickcancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog8( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar producto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 460,279 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog8();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog5
///////////////////////////////////////////////////////////////////////////////
class MyDialog5 : public wxDialog 
{
	private:
	
	protected:
		wxCheckBox* check;
		wxStaticText* m_staticText46;
		wxChoice* choisermes;
		wxGrid* grilla_historial;
		wxStaticText* labeltotalmes;
		wxTextCtrl* textototalrecaudado;
		wxCalendarCtrl* cosofecha;
		wxStaticText* m_staticText15;
		wxTextCtrl* paneldetalles;
		
		// Virtual event handlers, overide them in your derived class
		virtual void checkfiltromes( wxCommandEvent& event ) { event.Skip(); }
		virtual void eligiomes( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickcelda( wxGridEvent& event ) { event.Skip(); }
		virtual void clickelegirfecha( wxCalendarEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog5( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Historial"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 636,349 ), long style = wxDEFAULT_DIALOG_STYLE|wxRESIZE_BORDER ); 
		~MyDialog5();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog3
///////////////////////////////////////////////////////////////////////////////
class MyDialog3 : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText7;
		wxSearchCtrl* buscadorcod;
		wxGrid* grillaagregarproducto;
		wxBitmapButton* m_button13;
		wxBitmapButton* m_button14;
		
		// Virtual event handlers, overide them in your derived class
		virtual void clickcancelar( wxCommandEvent& event ) { event.Skip(); }
		virtual void buscaronfly( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickbotonagregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickbotoncancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog3( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar producto a la venta"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 620,369 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog3();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog1
///////////////////////////////////////////////////////////////////////////////
class MyDialog1 : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText2;
		wxStaticText* m_staticText3;
		wxTextCtrl* textodescuento;
		wxBitmapButton* m_button17;
		wxBitmapButton* m_button18;
		
		// Virtual event handlers, overide them in your derived class
		virtual void enteraceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickaceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickcancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog1( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Descuento"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 263,173 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog1();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog2
///////////////////////////////////////////////////////////////////////////////
class MyDialog2 : public wxDialog 
{
	private:
	
	protected:
		wxSearchCtrl* buscador;
		wxChoice* choisergrilla;
		wxGrid* grilla_stock;
		wxBitmapButton* m_button7;
		wxBitmapButton* m_button8;
		wxBitmapButton* m_button9;
		wxBitmapButton* m_button10;
		
		// Virtual event handlers, overide them in your derived class
		virtual void cerrarventana( wxCloseEvent& event ) { event.Skip(); }
		virtual void busquedaonfly( wxCommandEvent& event ) { event.Skip(); }
		virtual void seseleccionogrilla( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickagregarstock( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickeliminarstock( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickmodificarstock( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickguardarstock( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog2( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Stock"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 692,328 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog2();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog9
///////////////////////////////////////////////////////////////////////////////
class MyDialog9 : public wxDialog 
{
	private:
	
	protected:
		wxBitmapButton* m_bpButton41;
		wxDatePickerCtrl* cosofecha;
		wxGrid* grilla_gastos_externos;
		wxStaticText* labeltotal;
		wxTextCtrl* textototalgastos;
		wxBitmapButton* m_bpButton27;
		wxBitmapButton* m_bpButton28;
		wxBitmapButton* m_bpButton29;
		wxBitmapButton* m_bpButton30;
		
		// Virtual event handlers, overide them in your derived class
		virtual void cerrarventana( wxCloseEvent& event ) { event.Skip(); }
		virtual void clickcancelarfiltro( wxCommandEvent& event ) { event.Skip(); }
		virtual void fechacambio( wxDateEvent& event ) { event.Skip(); }
		virtual void clickagregar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickeliminar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickmodificar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickguardar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog9( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Gastos externos"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 558,327 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog9();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog10
///////////////////////////////////////////////////////////////////////////////
class MyDialog10 : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText30;
		wxTextCtrl* textocosto;
		wxStaticText* m_staticText31;
		wxTextCtrl* textodesc;
		wxStaticText* m_staticText32;
		wxTextCtrl* textodia;
		wxStaticText* m_staticText33;
		wxTextCtrl* textomes;
		wxStaticText* m_staticText34;
		wxTextCtrl* textoanio;
		wxBitmapButton* m_bpButton27;
		wxBitmapButton* m_bpButton28;
		
		// Virtual event handlers, overide them in your derived class
		virtual void enteraceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickaceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickcancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog10( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Agregar gasto"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 463,185 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog10();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog141
///////////////////////////////////////////////////////////////////////////////
class MyDialog141 : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText44;
		wxTextCtrl* textocantidad;
		wxBitmapButton* m_bpButton36;
		wxBitmapButton* m_bpButton37;
		
		// Virtual event handlers, overide them in your derived class
		virtual void entertexto( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickaceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickcancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog141( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 289,144 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog141();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog13
///////////////////////////////////////////////////////////////////////////////
class MyDialog13 : public wxDialog 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmap4;
		wxTextCtrl* textousuario;
		wxStaticLine* m_staticline1;
		wxTextCtrl* textopass;
		wxHyperlinkCtrl* m_hyperlink4;
		wxStaticLine* m_staticline2;
		wxButton* m_button3;
		
		// Virtual event handlers, overide them in your derived class
		virtual void Onbotoncerrar( wxCloseEvent& event ) { event.Skip(); }
		virtual void yanofocususer( wxFocusEvent& event ) { event.Skip(); }
		virtual void focususer( wxFocusEvent& event ) { event.Skip(); }
		virtual void yanofocuspass( wxFocusEvent& event ) { event.Skip(); }
		virtual void focuspass( wxFocusEvent& event ) { event.Skip(); }
		virtual void enterpass( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickolvidepass( wxHyperlinkEvent& event ) { event.Skip(); }
		virtual void clicklogin( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog13( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Iniciar sesión"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 397,369 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog13();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog17
///////////////////////////////////////////////////////////////////////////////
class MyDialog17 : public wxDialog 
{
	private:
	
	protected:
		wxStaticText* m_staticText58;
		wxStaticLine* m_staticline4;
		wxStaticText* labelingrese;
		wxTextCtrl* textousuario;
		wxButton* botonbuscar;
		wxStaticText* labelpregunta;
		wxTextCtrl* textorespuesta;
		wxButton* botonver;
		wxStaticText* labelpass;
		wxTextCtrl* textopass;
		wxBitmapButton* m_bpButton42;
		
		// Virtual event handlers, overide them in your derived class
		virtual void clickbuscar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickverificar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickfinalizar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog17( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Recuperar contraseña"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 281,255 ), long style = wxDEFAULT_DIALOG_STYLE|wxSTAY_ON_TOP ); 
		~MyDialog17();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog15
///////////////////////////////////////////////////////////////////////////////
class MyDialog15 : public wxDialog 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmap6;
		wxStaticText* m_staticText46;
		wxStaticText* m_staticText48;
		wxTextCtrl* textouser;
		wxStaticText* m_staticText47;
		wxTextCtrl* textopass;
		wxStaticText* m_staticText54;
		wxChoice* choiserrespuesta;
		wxStaticText* m_staticText55;
		wxTextCtrl* textorespuesta;
		wxBitmapButton* m_bpButton39;
		
		// Virtual event handlers, overide them in your derived class
		virtual void onbotoncerrar( wxCloseEvent& event ) { event.Skip(); }
		virtual void enterpass( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickbotonaceptar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog15( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Creación usuario principal"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 746,432 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog15();
	
};

///////////////////////////////////////////////////////////////////////////////
/// Class MyDialog16
///////////////////////////////////////////////////////////////////////////////
class MyDialog16 : public wxDialog 
{
	private:
	
	protected:
		wxStaticBitmap* m_bitmap6;
		wxStaticText* m_staticText49;
		wxStaticText* m_staticText51;
		wxTextCtrl* textoactualuser;
		wxStaticText* m_staticText50;
		wxTextCtrl* textoactualpass;
		wxStaticText* m_staticText53;
		wxTextCtrl* textonuevapass;
		wxStaticText* labelmal;
		wxBitmapButton* botonaceptar;
		wxBitmapButton* m_bpButton40;
		
		// Virtual event handlers, overide them in your derived class
		virtual void clickuser( wxFocusEvent& event ) { event.Skip(); }
		virtual void clickpass( wxFocusEvent& event ) { event.Skip(); }
		virtual void clickaceptar( wxCommandEvent& event ) { event.Skip(); }
		virtual void clickcancelar( wxCommandEvent& event ) { event.Skip(); }
		
	
	public:
		
		MyDialog16( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("Cambiar contraseña"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 622,379 ), long style = wxDEFAULT_DIALOG_STYLE ); 
		~MyDialog16();
	
};

#endif //__VENTANAS_H__
