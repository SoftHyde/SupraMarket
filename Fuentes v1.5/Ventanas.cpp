///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version Jun 17 2015)
// http://www.wxformbuilder.org/
//
// PLEASE DO "NOT" EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "Ventanas.h"

///////////////////////////////////////////////////////////////////////////

Frame0::Frame0( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHTTEXT ) );
	
	wxBoxSizer* bSizer1;
	bSizer1 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText11 = new wxStaticText( this, wxID_ANY, wxT("Nueva Venta"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText11->Wrap( -1 );
	bSizer4->Add( m_staticText11, 0, wxALL|wxEXPAND, 5 );
	
	grilla_venta = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_venta->CreateGrid( 0, 5 );
	grilla_venta->EnableEditing( false );
	grilla_venta->EnableGridLines( true );
	grilla_venta->EnableDragGridSize( false );
	grilla_venta->SetMargins( 0, 0 );
	
	// Columns
	grilla_venta->SetColSize( 0, 161 );
	grilla_venta->SetColSize( 1, 80 );
	grilla_venta->SetColSize( 2, 108 );
	grilla_venta->SetColSize( 3, 101 );
	grilla_venta->SetColSize( 4, 99 );
	grilla_venta->EnableDragColMove( false );
	grilla_venta->EnableDragColSize( true );
	grilla_venta->SetColLabelSize( 30 );
	grilla_venta->SetColLabelValue( 0, wxT("Nombre del Producto") );
	grilla_venta->SetColLabelValue( 1, wxT("Cantidad") );
	grilla_venta->SetColLabelValue( 2, wxT("Fecha") );
	grilla_venta->SetColLabelValue( 3, wxT("Subtotal") );
	grilla_venta->SetColLabelValue( 4, wxT("Observación") );
	grilla_venta->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_venta->EnableDragRowSize( true );
	grilla_venta->SetRowLabelSize( 1 );
	grilla_venta->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_venta->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer4->Add( grilla_venta, 1, wxEXPAND|wxALL, 5 );
	
	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxHORIZONTAL );
	
	labeltotalacobrar = new wxStaticText( this, wxID_ANY, wxT("Total a Cobrar"), wxDefaultPosition, wxDefaultSize, 0 );
	labeltotalacobrar->Wrap( -1 );
	bSizer5->Add( labeltotalacobrar, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	totalcobrarventa = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	totalcobrarventa->Enable( false );
	
	bSizer5->Add( totalcobrarventa, 0, wxALL|wxALIGN_BOTTOM, 5 );
	
	
	bSizer4->Add( bSizer5, 0, wxALIGN_RIGHT|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxHORIZONTAL );
	
	botonagregaraventa = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Añadir small.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	botonagregaraventa->SetToolTip( wxT("Añade un producto del stock a la venta actual") );
	
	bSizer32->Add( botonagregaraventa, 1, wxEXPAND|wxALL, 5 );
	
	botonquitarproductoventa = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Quitar Small.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	botonquitarproductoventa->SetToolTip( wxT("Elimina el producto seleccionado de la venta") );
	
	bSizer32->Add( botonquitarproductoventa, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer4->Add( bSizer32, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer4, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap3 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Icons/Principal.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_bitmap3, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Bienvenido a Supra Market!"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText19->Wrap( -1 );
	bSizer6->Add( m_staticText19, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	botoncancelarventa = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cancelar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	botoncancelarventa->SetToolTip( wxT("Cancela totalmente la venta") );
	
	bSizer6->Add( botoncancelarventa, 1, wxALL|wxEXPAND, 5 );
	
	botonconcretar = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Encargo.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	botonconcretar->SetToolTip( wxT("Añade la venta a la grilla de encargos") );
	
	bSizer6->Add( botonconcretar, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	botondeuda = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/deuda.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	botondeuda->SetToolTip( wxT("Añade la venta a la grilla de deudas") );
	
	bSizer17->Add( botondeuda, 1, wxALL|wxEXPAND, 5 );
	
	botondescuentoventa = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/descuento.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	botondescuentoventa->SetToolTip( wxT("Aplica un descuento sobre el total de la venta") );
	
	bSizer17->Add( botondescuentoventa, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer6->Add( bSizer17, 1, wxEXPAND, 5 );
	
	botonfinalizar = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/FINALIZAR.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	botonfinalizar->SetToolTip( wxT("Finaliza la venta y la añade al historial") );
	
	bSizer6->Add( botonfinalizar, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer6, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxHORIZONTAL );
	
	labeltitulodeudas = new wxStaticText( this, wxID_ANY, wxT("Deudas"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	labeltitulodeudas->Wrap( -1 );
	bSizer14->Add( labeltitulodeudas, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	buscardeudor = new wxSearchCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	buscardeudor->ShowSearchButton( false );
	#endif
	buscardeudor->ShowCancelButton( true );
	buscardeudor->SetToolTip( wxT("Filtra la grilla segun su busqueda") );
	
	bSizer14->Add( buscardeudor, 1, wxALL|wxEXPAND, 5 );
	
	wxString selectorgrillaChoices[] = { wxT("Deudas"), wxT("Productos a Entregar") };
	int selectorgrillaNChoices = sizeof( selectorgrillaChoices ) / sizeof( wxString );
	selectorgrilla = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, selectorgrillaNChoices, selectorgrillaChoices, wxCB_SORT );
	selectorgrilla->SetSelection( 0 );
	selectorgrilla->SetToolTip( wxT("Elige la grilla que quiere visualizar") );
	
	bSizer14->Add( selectorgrilla, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer16->Add( bSizer14, 0, wxEXPAND, 5 );
	
	grilla_deudas = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_deudas->CreateGrid( 0, 4 );
	grilla_deudas->EnableEditing( false );
	grilla_deudas->EnableGridLines( true );
	grilla_deudas->EnableDragGridSize( false );
	grilla_deudas->SetMargins( 0, 0 );
	
	// Columns
	grilla_deudas->SetColSize( 0, 145 );
	grilla_deudas->SetColSize( 1, 117 );
	grilla_deudas->SetColSize( 2, 168 );
	grilla_deudas->SetColSize( 3, 85 );
	grilla_deudas->EnableDragColMove( false );
	grilla_deudas->EnableDragColSize( true );
	grilla_deudas->SetColLabelSize( 30 );
	grilla_deudas->SetColLabelValue( 0, wxT("Nombre y Apellido") );
	grilla_deudas->SetColLabelValue( 1, wxT("Fecha") );
	grilla_deudas->SetColLabelValue( 2, wxT("Descripción") );
	grilla_deudas->SetColLabelValue( 3, wxT("Monto") );
	grilla_deudas->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_deudas->EnableDragRowSize( true );
	grilla_deudas->SetRowLabelSize( 1 );
	grilla_deudas->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_deudas->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	grilla_deudas->SetToolTip( wxT("Haga click en algún titular de la grilla para ordenarla (no válido para el titular \"Descripción\")") );
	
	bSizer16->Add( grilla_deudas, 1, wxALL|wxEXPAND, 5 );
	
	grilla_productos_a_entregar = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_productos_a_entregar->CreateGrid( 0, 5 );
	grilla_productos_a_entregar->EnableEditing( false );
	grilla_productos_a_entregar->EnableGridLines( true );
	grilla_productos_a_entregar->EnableDragGridSize( false );
	grilla_productos_a_entregar->SetMargins( 0, 0 );
	
	// Columns
	grilla_productos_a_entregar->SetColSize( 0, 148 );
	grilla_productos_a_entregar->SetColSize( 1, 122 );
	grilla_productos_a_entregar->SetColSize( 2, 150 );
	grilla_productos_a_entregar->SetColSize( 3, 195 );
	grilla_productos_a_entregar->SetColSize( 4, 80 );
	grilla_productos_a_entregar->EnableDragColMove( false );
	grilla_productos_a_entregar->EnableDragColSize( true );
	grilla_productos_a_entregar->SetColLabelSize( 30 );
	grilla_productos_a_entregar->SetColLabelValue( 0, wxT("Nombre y Apellido") );
	grilla_productos_a_entregar->SetColLabelValue( 1, wxT("Fecha de Entrega") );
	grilla_productos_a_entregar->SetColLabelValue( 2, wxT("Detalles") );
	grilla_productos_a_entregar->SetColLabelValue( 3, wxT("Modificaciones") );
	grilla_productos_a_entregar->SetColLabelValue( 4, wxT("Monto") );
	grilla_productos_a_entregar->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_productos_a_entregar->EnableDragRowSize( true );
	grilla_productos_a_entregar->SetRowLabelSize( 1 );
	grilla_productos_a_entregar->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_productos_a_entregar->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	grilla_productos_a_entregar->Hide();
	grilla_productos_a_entregar->SetToolTip( wxT("Haga click en algún titular de la grilla para ordenarla (no válido para los titulares \"Modificaciones\" y \"Detalles\")") );
	
	bSizer16->Add( grilla_productos_a_entregar, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer30;
	bSizer30 = new wxBoxSizer( wxHORIZONTAL );
	
	labeltotaldeudas = new wxStaticText( this, wxID_ANY, wxT("Total de deudas"), wxDefaultPosition, wxDefaultSize, 0 );
	labeltotaldeudas->Wrap( -1 );
	bSizer30->Add( labeltotaldeudas, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textototaldeudas = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	textototaldeudas->Enable( false );
	
	bSizer30->Add( textototaldeudas, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer16->Add( bSizer30, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );
	
	boton1grilladeuda = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Saldar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	boton1grilladeuda->SetToolTip( wxT("Salda la deuda seleccionada y la añade al historial") );
	
	bSizer18->Add( boton1grilladeuda, 1, wxALL|wxEXPAND, 5 );
	
	boton2grilladeuda = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Eliminar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	boton2grilladeuda->SetToolTip( wxT("Elimina la deuda seleccionada") );
	
	bSizer18->Add( boton2grilladeuda, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer16->Add( bSizer18, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );
	
	boton1grillaproductos = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Finalizar Small.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	boton1grillaproductos->Hide();
	boton1grillaproductos->SetToolTip( wxT("Finaliza el encargo seleccionado y lo añade al historial") );
	
	bSizer54->Add( boton1grillaproductos, 1, wxALL|wxEXPAND, 5 );
	
	boton2grillaproductos = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Eliminar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	boton2grillaproductos->Hide();
	boton2grillaproductos->SetToolTip( wxT("Elimina el encargo seleccionad") );
	
	bSizer54->Add( boton2grillaproductos, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer16->Add( bSizer54, 0, wxEXPAND, 5 );
	
	
	bSizer1->Add( bSizer16, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer1 );
	this->Layout();
	m_menubar1 = new wxMenuBar( 0 );
	m_menu1 = new wxMenu();
	wxMenuItem* m_menuItem63;
	m_menuItem63 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Crear nuevo usuario") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem63 );
	
	wxMenuItem* m_menuItem10;
	m_menuItem10 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Editar contraseña") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu1->Append( m_menuItem10 );
	
	wxMenuItem* m_menuItem9;
	m_menuItem9 = new wxMenuItem( m_menu1, wxID_ANY, wxString( wxT("Volver a estado de fábrica") ) , wxEmptyString, wxITEM_NORMAL );
	#ifdef __WXMSW__
	m_menuItem9->SetBitmaps( wxBitmap( wxT("Icons/cerrarsmall.png"), wxBITMAP_TYPE_ANY ) );
	#elif (defined( __WXGTK__ ) || defined( __WXOSX__ ))
	m_menuItem9->SetBitmap( wxBitmap( wxT("Icons/cerrarsmall.png"), wxBITMAP_TYPE_ANY ) );
	#endif
	m_menu1->Append( m_menuItem9 );
	
	m_menubar1->Append( m_menu1, wxT("Archivo") ); 
	
	m_menu3 = new wxMenu();
	wxMenuItem* m_menuItem3;
	m_menuItem3 = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("Stock") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem3 );
	
	wxMenuItem* m_menuItem61;
	m_menuItem61 = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("Historial") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem61 );
	
	wxMenuItem* m_menuItem62;
	m_menuItem62 = new wxMenuItem( m_menu3, wxID_ANY, wxString( wxT("Gastos externos") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu3->Append( m_menuItem62 );
	
	m_menubar1->Append( m_menu3, wxT("Ver") ); 
	
	m_menu4 = new wxMenu();
	wxMenuItem* m_menuItem7;
	m_menuItem7 = new wxMenuItem( m_menu4, wxID_ANY, wxString( wxT("Exportar historial completo") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem7 );
	
	wxMenuItem* m_menuItem8;
	m_menuItem8 = new wxMenuItem( m_menu4, wxID_ANY, wxString( wxT("Exportar stock completo") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu4->Append( m_menuItem8 );
	
	m_menubar1->Append( m_menu4, wxT("Exportar") ); 
	
	m_menu2 = new wxMenu();
	wxMenuItem* m_menuItem6;
	m_menuItem6 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Acerca de") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem6 );
	
	wxMenuItem* m_menuItem81;
	m_menuItem81 = new wxMenuItem( m_menu2, wxID_ANY, wxString( wxT("Manual de usuario") ) , wxEmptyString, wxITEM_NORMAL );
	m_menu2->Append( m_menuItem81 );
	
	m_menubar1->Append( m_menu2, wxT("Ayuda") ); 
	
	this->SetMenuBar( m_menubar1 );
	
	statusbar = this->CreateStatusBar( 1, wxST_SIZEGRIP, wxID_ANY );
	
	this->Centre( wxBOTH );
	
	// Connect Events
	grilla_venta->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( Frame0::clickgrillaproductos ), NULL, this );
	grilla_venta->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( Frame0::clickeditarventa ), NULL, this );
	botonagregaraventa->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickagregarprod ), NULL, this );
	botonquitarproductoventa->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickeliminarprod ), NULL, this );
	botoncancelarventa->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickcancelarcompra ), NULL, this );
	botonconcretar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::click_producto_a_entregar ), NULL, this );
	botondeuda->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickdeuda ), NULL, this );
	botondescuentoventa->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickdescuento ), NULL, this );
	botonfinalizar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickchaucompra ), NULL, this );
	buscardeudor->Connect( wxEVT_COMMAND_SEARCHCTRL_CANCEL_BTN, wxCommandEventHandler( Frame0::cancelarbusqueda ), NULL, this );
	buscardeudor->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Frame0::busquedaonthefly ), NULL, this );
	selectorgrilla->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Frame0::selecciongrilla ), NULL, this );
	grilla_deudas->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( Frame0::clickgrilladeudores ), NULL, this );
	grilla_deudas->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( Frame0::clickeditardeuda ), NULL, this );
	grilla_deudas->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( Frame0::clickordenardeudas ), NULL, this );
	grilla_productos_a_entregar->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( Frame0::clickgrilladeudores ), NULL, this );
	grilla_productos_a_entregar->Connect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( Frame0::clickeditardeuda ), NULL, this );
	grilla_productos_a_entregar->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( Frame0::clickordenargrillaencargo ), NULL, this );
	boton1grilladeuda->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clicksaldardeuda ), NULL, this );
	boton2grilladeuda->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickeliminardeudor ), NULL, this );
	boton1grillaproductos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickfinalizaranticipado ), NULL, this );
	boton2grillaproductos->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickeliminaranticipado ), NULL, this );
	this->Connect( m_menuItem63->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clicknuevouser ) );
	this->Connect( m_menuItem10->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickeditarpass ) );
	this->Connect( m_menuItem9->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickvolverfab ) );
	this->Connect( m_menuItem3->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickverstock ) );
	this->Connect( m_menuItem61->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickverhistorial ) );
	this->Connect( m_menuItem62->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickvergastosexternos ) );
	this->Connect( m_menuItem7->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickexportarhistorial ) );
	this->Connect( m_menuItem8->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickexportarstock ) );
	this->Connect( m_menuItem6->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickacercade ) );
	this->Connect( m_menuItem81->GetId(), wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickmanualdeusuario ) );
}

Frame0::~Frame0()
{
	// Disconnect Events
	grilla_venta->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( Frame0::clickgrillaproductos ), NULL, this );
	grilla_venta->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( Frame0::clickeditarventa ), NULL, this );
	botonagregaraventa->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickagregarprod ), NULL, this );
	botonquitarproductoventa->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickeliminarprod ), NULL, this );
	botoncancelarventa->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickcancelarcompra ), NULL, this );
	botonconcretar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::click_producto_a_entregar ), NULL, this );
	botondeuda->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickdeuda ), NULL, this );
	botondescuentoventa->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickdescuento ), NULL, this );
	botonfinalizar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickchaucompra ), NULL, this );
	buscardeudor->Disconnect( wxEVT_COMMAND_SEARCHCTRL_CANCEL_BTN, wxCommandEventHandler( Frame0::cancelarbusqueda ), NULL, this );
	buscardeudor->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( Frame0::busquedaonthefly ), NULL, this );
	selectorgrilla->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( Frame0::selecciongrilla ), NULL, this );
	grilla_deudas->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( Frame0::clickgrilladeudores ), NULL, this );
	grilla_deudas->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( Frame0::clickeditardeuda ), NULL, this );
	grilla_deudas->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( Frame0::clickordenardeudas ), NULL, this );
	grilla_productos_a_entregar->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( Frame0::clickgrilladeudores ), NULL, this );
	grilla_productos_a_entregar->Disconnect( wxEVT_GRID_CELL_LEFT_DCLICK, wxGridEventHandler( Frame0::clickeditardeuda ), NULL, this );
	grilla_productos_a_entregar->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( Frame0::clickordenargrillaencargo ), NULL, this );
	boton1grilladeuda->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clicksaldardeuda ), NULL, this );
	boton2grilladeuda->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickeliminardeudor ), NULL, this );
	boton1grillaproductos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickfinalizaranticipado ), NULL, this );
	boton2grillaproductos->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Frame0::clickeliminaranticipado ), NULL, this );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clicknuevouser ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickeditarpass ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickvolverfab ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickverstock ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickverhistorial ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickvergastosexternos ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickexportarhistorial ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickexportarstock ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickacercade ) );
	this->Disconnect( wxID_ANY, wxEVT_COMMAND_MENU_SELECTED, wxCommandEventHandler( Frame0::clickmanualdeusuario ) );
	
}

MyDialog14::MyDialog14( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer58;
	bSizer58 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText42 = new wxStaticText( this, wxID_ANY, wxT("Escoja su nombre de usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText42->Wrap( -1 );
	bSizer58->Add( m_staticText42, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	textouser = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( textouser, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_staticText43 = new wxStaticText( this, wxID_ANY, wxT("Escoja su contraseña"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText43->Wrap( -1 );
	bSizer58->Add( m_staticText43, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	textopass = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( textopass, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_staticText56 = new wxStaticText( this, wxID_ANY, wxT("Escoja su pregunta de seguridad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText56->Wrap( -1 );
	bSizer58->Add( m_staticText56, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxString choiserpregChoices[] = { wxT("¿Cual fue tu primer automovil que compraste?"), wxT("¿Cual es el nombre de tu mascota?"), wxT("¿Como se llama tu equipo favorito?"), wxT("¿En que año finalizaste la escuela secundaria?"), wxT("¿Cual era tu pasatiempo favorito?"), wxT("¿Donde vivias cuando eras menor?"), wxT("¿Cual fue tu primer videojuego?"), wxT("¿Cual es el segundo nombre de tu mama?"), wxT("¿Cual es el segundo nombre de tu papa?") };
	int choiserpregNChoices = sizeof( choiserpregChoices ) / sizeof( wxString );
	choiserpreg = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiserpregNChoices, choiserpregChoices, 0 );
	choiserpreg->SetSelection( 0 );
	bSizer58->Add( choiserpreg, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText57 = new wxStaticText( this, wxID_ANY, wxT("Escriba su respuesta"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText57->Wrap( -1 );
	bSizer58->Add( m_staticText57, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	textoresp = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer58->Add( textoresp, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer59;
	bSizer59 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton34 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/aceptar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton34->SetToolTip( wxT("Añade nuevo usuario") );
	
	bSizer59->Add( m_bpButton34, 1, wxALL|wxEXPAND, 5 );
	
	m_bpButton35 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cancel.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton35->SetToolTip( wxT("Cancelar cambios") );
	
	bSizer59->Add( m_bpButton35, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer58->Add( bSizer59, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer58 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	textopass->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog14::enteraceptar ), NULL, this );
	m_bpButton34->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog14::clickcrear ), NULL, this );
	m_bpButton35->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog14::cliclcancelar ), NULL, this );
}

MyDialog14::~MyDialog14()
{
	// Disconnect Events
	textopass->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog14::enteraceptar ), NULL, this );
	m_bpButton34->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog14::clickcrear ), NULL, this );
	m_bpButton35->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog14::cliclcancelar ), NULL, this );
	
}

MyDialog81::MyDialog81( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer50;
	bSizer50 = new wxBoxSizer( wxHORIZONTAL );
	
	checksaldo = new wxCheckBox( this, wxID_ANY, wxT("Saldo pagado"), wxDefaultPosition, wxDefaultSize, 0 );
	checksaldo->SetToolTip( wxT("Añade un saldo que disminuye el monto total de la deuda") );
	
	bSizer50->Add( checksaldo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textosaldo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	textosaldo->Enable( false );
	
	bSizer50->Add( textosaldo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer37->Add( bSizer50, 1, wxEXPAND, 5 );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Ingrese el nombre del deudor:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText23->Wrap( -1 );
	bSizer37->Add( m_staticText23, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	textonombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer37->Add( textonombre, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Ingrese el apellido del deudor:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText24->Wrap( -1 );
	bSizer37->Add( m_staticText24, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	textoapellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer37->Add( textoapellido, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button13 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/aceptar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	
	m_button13->SetBitmapDisabled( wxBitmap( wxT("Icons/aceptar.PNG"), wxBITMAP_TYPE_ANY ) );
	m_button13->SetToolTip( wxT("Agregar venta a la grilla de deudas") );
	
	bSizer38->Add( m_button13, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button14 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cancel.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_button14->SetToolTip( wxT("Cancelar cambios") );
	
	bSizer38->Add( m_button14, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer37->Add( bSizer38, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	this->SetSizer( bSizer37 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	checksaldo->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog81::checksaldoon ), NULL, this );
	textoapellido->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog81::enteraceptar ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog81::clickaceptar ), NULL, this );
	m_button14->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog81::clickcancelar ), NULL, this );
}

MyDialog81::~MyDialog81()
{
	// Disconnect Events
	checksaldo->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog81::checksaldoon ), NULL, this );
	textoapellido->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog81::enteraceptar ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog81::clickaceptar ), NULL, this );
	m_button14->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog81::clickcancelar ), NULL, this );
	
}

MyDialog11::MyDialog11( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer52;
	bSizer52 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer62;
	bSizer62 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText45 = new wxStaticText( this, wxID_ANY, wxT("Ingrese la fecha de entrega"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText45->Wrap( -1 );
	bSizer62->Add( m_staticText45, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	cosofecha = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN );
	cosofecha->SetToolTip( wxT("Escoja la fecha de entrega") );
	
	bSizer62->Add( cosofecha, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer52->Add( bSizer62, 1, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText37 = new wxStaticText( this, wxID_ANY, wxT("Ingrese el nombre del comprador:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText37->Wrap( -1 );
	bSizer52->Add( m_staticText37, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	textonombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer52->Add( textonombre, 0, wxALL|wxEXPAND, 5 );
	
	m_staticText38 = new wxStaticText( this, wxID_ANY, wxT("Ingrese el apellido del comprador:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText38->Wrap( -1 );
	bSizer52->Add( m_staticText38, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	textoapellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer52->Add( textoapellido, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText401 = new wxStaticText( this, wxID_ANY, wxT("Ingrese las modificaciones de los productos:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText401->Wrap( -1 );
	bSizer52->Add( m_staticText401, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	textomodificaciones = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer52->Add( textomodificaciones, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer54;
	bSizer54 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton29 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/aceptar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton29->SetToolTip( wxT("Agregar encargo a la grilla") );
	
	bSizer54->Add( m_bpButton29, 1, wxALL|wxEXPAND, 5 );
	
	m_bpButton30 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cancel.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton30->SetToolTip( wxT("Cancelar cambios") );
	
	bSizer54->Add( m_bpButton30, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer52->Add( bSizer54, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer52 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	textomodificaciones->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog11::enteraceptar ), NULL, this );
	m_bpButton29->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog11::clickaceptar ), NULL, this );
	m_bpButton30->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog11::clickcancelar ), NULL, this );
}

MyDialog11::~MyDialog11()
{
	// Disconnect Events
	textomodificaciones->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog11::enteraceptar ), NULL, this );
	m_bpButton29->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog11::clickaceptar ), NULL, this );
	m_bpButton30->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog11::clickcancelar ), NULL, this );
	
}

MyDialog7::MyDialog7( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer33->Add( m_staticText20, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textonombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( textonombre, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer32->Add( bSizer33, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer40;
	bSizer40 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText26 = new wxStaticText( this, wxID_ANY, wxT("Apellido"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText26->Wrap( -1 );
	bSizer40->Add( m_staticText26, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textoapellido = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer40->Add( textoapellido, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer32->Add( bSizer40, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Descripción"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer34->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textodesc = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( textodesc, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer32->Add( bSizer34, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer55;
	bSizer55 = new wxBoxSizer( wxHORIZONTAL );
	
	labelmodificaciones = new wxStaticText( this, wxID_ANY, wxT("Modificaciones"), wxDefaultPosition, wxDefaultSize, 0 );
	labelmodificaciones->Wrap( -1 );
	labelmodificaciones->Hide();
	
	bSizer55->Add( labelmodificaciones, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textomodificaciones = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	textomodificaciones->Hide();
	
	bSizer55->Add( textomodificaciones, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer32->Add( bSizer55, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Monto Total"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText22->Wrap( -1 );
	bSizer35->Add( m_staticText22, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textomonto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( textomonto, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer32->Add( bSizer35, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer39;
	bSizer39 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText23 = new wxStaticText( this, wxID_ANY, wxT("Día"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText23->Wrap( -1 );
	bSizer39->Add( m_staticText23, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textodia = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( textodia, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Mes"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText24->Wrap( -1 );
	bSizer39->Add( m_staticText24, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textomes = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( textomes, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Año"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText25->Wrap( -1 );
	bSizer39->Add( m_staticText25, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textoanio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer39->Add( textoanio, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer32->Add( bSizer39, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button11 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/aceptar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_button11->SetToolTip( wxT("Aceptar cambios") );
	
	bSizer36->Add( m_button11, 1, wxALL|wxEXPAND, 5 );
	
	m_button12 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cancel.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_button12->SetToolTip( wxT("Cancelar cambios") );
	
	bSizer36->Add( m_button12, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer32->Add( bSizer36, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer32 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	textomonto->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog7::enteraceptar ), NULL, this );
	textoanio->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog7::enteraceptar ), NULL, this );
	m_button11->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog7::clickaceptar ), NULL, this );
	m_button12->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog7::clickcancelar ), NULL, this );
}

MyDialog7::~MyDialog7()
{
	// Disconnect Events
	textomonto->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog7::enteraceptar ), NULL, this );
	textoanio->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog7::enteraceptar ), NULL, this );
	m_button11->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog7::clickaceptar ), NULL, this );
	m_button12->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog7::clickcancelar ), NULL, this );
	
}

MyDialog6::MyDialog6( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer28;
	bSizer28 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bitmap3 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Icons/Super_Sonic_(Modern).png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	m_bitmap3->SetToolTip( wxT("Super Sonic ;)") );
	
	bSizer28->Add( m_bitmap3, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText24 = new wxStaticText( this, wxID_ANY, wxT("Supra Market es un entorno de gestion administrativo de comercio general, adaptable a multiples estilos de negosios. Sirve para gestionar tanto ventas minoritarias como mayoritarias, con soporte de descuentos, uso de tarjetas de credito/debito, grupo de deudores y mas. Para cualquier consulta sobre el uso del programa, emitir una critica, reportar un error o solicitar una nueva funcionalidad, por favor contactese con nosotros mediante los siguientes mails:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText24->Wrap( -1 );
	bSizer35->Add( m_staticText24, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText25 = new wxStaticText( this, wxID_ANY, wxT("Guillermo Yarull"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText25->Wrap( -1 );
	bSizer35->Add( m_staticText25, 0, wxALL|wxEXPAND, 5 );
	
	m_hyperlink1 = new wxHyperlinkCtrl( this, wxID_ANY, wxT("gyarull95@gmail.com"), wxT("mailto:[gyarull95@gmail.com]"), wxDefaultPosition, wxDefaultSize, wxHL_ALIGN_LEFT|wxHL_DEFAULT_STYLE );
	m_hyperlink1->SetToolTip( wxT("Se abrira su aplicación predeterminada de correo con el destinatario fijado") );
	
	bSizer35->Add( m_hyperlink1, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticText22 = new wxStaticText( this, wxID_ANY, wxT("Lucas Ríos"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText22->Wrap( -1 );
	bSizer35->Add( m_staticText22, 0, wxALL|wxEXPAND, 5 );
	
	m_hyperlink2 = new wxHyperlinkCtrl( this, wxID_ANY, wxT("lukks.10@live.com.ar"), wxT("mailto:[lukks.10@live.com.ar]"), wxDefaultPosition, wxDefaultSize, wxHL_ALIGN_LEFT|wxHL_DEFAULT_STYLE );
	m_hyperlink2->SetToolTip( wxT("Se abrira su aplicación predeterminada de correo con el destinatario fijado") );
	
	bSizer35->Add( m_hyperlink2, 0, wxALL|wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	
	bSizer28->Add( bSizer35, 1, wxEXPAND, 5 );
	
	m_bitmap2 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Icons/Thresh.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	m_bitmap2->SetToolTip( wxT("Espartaco!") );
	
	bSizer28->Add( m_bitmap2, 0, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer28 );
	this->Layout();
	
	this->Centre( wxBOTH );
}

MyDialog6::~MyDialog6()
{
}

MyDialog8::MyDialog8( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer32;
	bSizer32 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer33;
	bSizer33 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText17 = new wxStaticText( this, wxID_ANY, wxT("Nombre"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText17->Wrap( -1 );
	bSizer33->Add( m_staticText17, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textonombre = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer33->Add( textonombre, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer32->Add( bSizer33, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer34;
	bSizer34 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText18 = new wxStaticText( this, wxID_ANY, wxT("Cantidad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText18->Wrap( -1 );
	bSizer34->Add( m_staticText18, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textocantidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer34->Add( textocantidad, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer32->Add( bSizer34, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer35;
	bSizer35 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText19 = new wxStaticText( this, wxID_ANY, wxT("Código"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText19->Wrap( -1 );
	bSizer35->Add( m_staticText19, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textocodigo = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer35->Add( textocodigo, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer32->Add( bSizer35, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer36;
	bSizer36 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText20 = new wxStaticText( this, wxID_ANY, wxT("Costo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText20->Wrap( -1 );
	bSizer36->Add( m_staticText20, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textocosto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer36->Add( textocosto, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer32->Add( bSizer36, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer37;
	bSizer37 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText21 = new wxStaticText( this, wxID_ANY, wxT("Observación"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText21->Wrap( -1 );
	bSizer37->Add( m_staticText21, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textoobservacion = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer37->Add( textoobservacion, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer32->Add( bSizer37, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer41;
	bSizer41 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText27 = new wxStaticText( this, wxID_ANY, wxT("Día"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText27->Wrap( -1 );
	bSizer41->Add( m_staticText27, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textodia = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( textodia, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText28 = new wxStaticText( this, wxID_ANY, wxT("Mes"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText28->Wrap( -1 );
	bSizer41->Add( m_staticText28, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textomes = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( textomes, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText29 = new wxStaticText( this, wxID_ANY, wxT("Año"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText29->Wrap( -1 );
	bSizer41->Add( m_staticText29, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textoanio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer41->Add( textoanio, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer32->Add( bSizer41, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer38;
	bSizer38 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button20 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/aceptar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_button20->SetToolTip( wxT("Aceptar cambios") );
	
	bSizer38->Add( m_button20, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_button21 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cancel.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_button21->SetToolTip( wxT("Cancelar cambios") );
	
	bSizer38->Add( m_button21, 1, wxALL|wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer32->Add( bSizer38, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer32 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	textoanio->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog8::enteraceptar ), NULL, this );
	m_button20->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog8::clickagregar ), NULL, this );
	m_button21->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog8::clickcancelar ), NULL, this );
}

MyDialog8::~MyDialog8()
{
	// Disconnect Events
	textoanio->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog8::enteraceptar ), NULL, this );
	m_button20->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog8::clickagregar ), NULL, this );
	m_button21->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog8::clickcancelar ), NULL, this );
	
}

MyDialog5::MyDialog5( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer26;
	bSizer26 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxHORIZONTAL );
	
	check = new wxCheckBox( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer66->Add( check, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_staticText46 = new wxStaticText( this, wxID_ANY, wxT("Filtrar por mes (Año actual)"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText46->Wrap( -1 );
	m_staticText46->SetToolTip( wxT("Habilitar/Desabilitar  filtro por mes") );
	
	bSizer66->Add( m_staticText46, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString choisermesChoices[] = { wxT("Enero"), wxT("Febrero"), wxT("Marzo"), wxT("Abril"), wxT("Mayo"), wxT("Junio"), wxT("Julio"), wxT("Agosto"), wxT("Septiembre"), wxT("Octubre"), wxT("Noviembre"), wxT("Diciembre") };
	int choisermesNChoices = sizeof( choisermesChoices ) / sizeof( wxString );
	choisermes = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choisermesNChoices, choisermesChoices, 0 );
	choisermes->SetSelection( 0 );
	choisermes->Enable( false );
	choisermes->SetToolTip( wxT("Elija el mes (año actual) con el que desea filtrar la lista") );
	
	bSizer66->Add( choisermes, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer26->Add( bSizer66, 0, wxEXPAND, 5 );
	
	grilla_historial = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_historial->CreateGrid( 0, 3 );
	grilla_historial->EnableEditing( false );
	grilla_historial->EnableGridLines( true );
	grilla_historial->EnableDragGridSize( false );
	grilla_historial->SetMargins( 0, 0 );
	
	// Columns
	grilla_historial->SetColSize( 0, 118 );
	grilla_historial->SetColSize( 1, 93 );
	grilla_historial->SetColSize( 2, 187 );
	grilla_historial->EnableDragColMove( false );
	grilla_historial->EnableDragColSize( true );
	grilla_historial->SetColLabelSize( 30 );
	grilla_historial->SetColLabelValue( 0, wxT("Fecha") );
	grilla_historial->SetColLabelValue( 1, wxT("Total Pagado") );
	grilla_historial->SetColLabelValue( 2, wxT("Detalles") );
	grilla_historial->SetColLabelValue( 3, wxEmptyString );
	grilla_historial->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_historial->EnableDragRowSize( true );
	grilla_historial->SetRowLabelSize( 1 );
	grilla_historial->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_historial->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer26->Add( grilla_historial, 1, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxHORIZONTAL );
	
	labeltotalmes = new wxStaticText( this, wxID_ANY, wxT("Total recaudado del mes"), wxDefaultPosition, wxDefaultSize, 0 );
	labeltotalmes->Wrap( -1 );
	bSizer68->Add( labeltotalmes, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textototalrecaudado = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	textototalrecaudado->Enable( false );
	
	bSizer68->Add( textototalrecaudado, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer26->Add( bSizer68, 0, wxEXPAND, 5 );
	
	
	bSizer25->Add( bSizer26, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxVERTICAL );
	
	cosofecha = new wxCalendarCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxCAL_SHOW_HOLIDAYS|wxCAL_SUNDAY_FIRST );
	cosofecha->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	cosofecha->SetToolTip( wxT("Escoja la fecha para filtrar la grilla del historial") );
	
	bSizer27->Add( cosofecha, 1, wxALL|wxEXPAND, 5 );
	
	m_staticText15 = new wxStaticText( this, wxID_ANY, wxT("Detalles"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText15->Wrap( -1 );
	bSizer27->Add( m_staticText15, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	paneldetalles = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE|wxTE_READONLY );
	paneldetalles->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOTEXT ) );
	paneldetalles->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	paneldetalles->Enable( false );
	paneldetalles->SetToolTip( wxT("Detalles completos del elemento del historial seleccionado en la grilla") );
	
	bSizer27->Add( paneldetalles, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer25->Add( bSizer27, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer25 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	check->Connect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog5::checkfiltromes ), NULL, this );
	choisermes->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog5::eligiomes ), NULL, this );
	grilla_historial->Connect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( MyDialog5::clickcelda ), NULL, this );
	cosofecha->Connect( wxEVT_CALENDAR_DOUBLECLICKED, wxCalendarEventHandler( MyDialog5::clickelegirfecha ), NULL, this );
	cosofecha->Connect( wxEVT_CALENDAR_SEL_CHANGED, wxCalendarEventHandler( MyDialog5::clickelegirfecha ), NULL, this );
}

MyDialog5::~MyDialog5()
{
	// Disconnect Events
	check->Disconnect( wxEVT_COMMAND_CHECKBOX_CLICKED, wxCommandEventHandler( MyDialog5::checkfiltromes ), NULL, this );
	choisermes->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog5::eligiomes ), NULL, this );
	grilla_historial->Disconnect( wxEVT_GRID_CELL_LEFT_CLICK, wxGridEventHandler( MyDialog5::clickcelda ), NULL, this );
	cosofecha->Disconnect( wxEVT_CALENDAR_DOUBLECLICKED, wxCalendarEventHandler( MyDialog5::clickelegirfecha ), NULL, this );
	cosofecha->Disconnect( wxEVT_CALENDAR_SEL_CHANGED, wxCalendarEventHandler( MyDialog5::clickelegirfecha ), NULL, this );
	
}

MyDialog3::MyDialog3( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText7 = new wxStaticText( this, wxID_ANY, wxT("Ingrese código o nombre del artículo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText7->Wrap( -1 );
	bSizer16->Add( m_staticText7, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	buscadorcod = new wxSearchCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	buscadorcod->ShowSearchButton( false );
	#endif
	buscadorcod->ShowCancelButton( true );
	buscadorcod->SetToolTip( wxT("Ingrese el nombre o código del articulo para filtrar la lista") );
	
	bSizer16->Add( buscadorcod, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer15->Add( bSizer16, 0, wxEXPAND, 5 );
	
	grillaagregarproducto = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grillaagregarproducto->CreateGrid( 0, 6 );
	grillaagregarproducto->EnableEditing( false );
	grillaagregarproducto->EnableGridLines( true );
	grillaagregarproducto->EnableDragGridSize( false );
	grillaagregarproducto->SetMargins( 0, 0 );
	
	// Columns
	grillaagregarproducto->SetColSize( 0, 107 );
	grillaagregarproducto->SetColSize( 1, 65 );
	grillaagregarproducto->SetColSize( 2, 80 );
	grillaagregarproducto->SetColSize( 3, 93 );
	grillaagregarproducto->SetColSize( 4, 107 );
	grillaagregarproducto->SetColSize( 5, 140 );
	grillaagregarproducto->EnableDragColMove( false );
	grillaagregarproducto->EnableDragColSize( true );
	grillaagregarproducto->SetColLabelSize( 30 );
	grillaagregarproducto->SetColLabelValue( 0, wxT("Nombre") );
	grillaagregarproducto->SetColLabelValue( 1, wxT("Cant.") );
	grillaagregarproducto->SetColLabelValue( 2, wxT("Código") );
	grillaagregarproducto->SetColLabelValue( 3, wxT("Costo p/unidad") );
	grillaagregarproducto->SetColLabelValue( 4, wxT("Fecha") );
	grillaagregarproducto->SetColLabelValue( 5, wxT("Observaciones") );
	grillaagregarproducto->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grillaagregarproducto->EnableDragRowSize( true );
	grillaagregarproducto->SetRowLabelSize( 1 );
	grillaagregarproducto->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grillaagregarproducto->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer15->Add( grillaagregarproducto, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button13 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Agregar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_button13->SetToolTip( wxT("Agregar producto seleccionado a la venta actual") );
	
	bSizer17->Add( m_button13, 1, wxALL|wxEXPAND, 5 );
	
	m_button14 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cancel.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_button14->SetToolTip( wxT("Cancelar selección") );
	
	bSizer17->Add( m_button14, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer15->Add( bSizer17, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer15 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	buscadorcod->Connect( wxEVT_COMMAND_SEARCHCTRL_CANCEL_BTN, wxCommandEventHandler( MyDialog3::clickcancelar ), NULL, this );
	buscadorcod->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyDialog3::buscaronfly ), NULL, this );
	m_button13->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::clickbotonagregar ), NULL, this );
	m_button14->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::clickbotoncancelar ), NULL, this );
}

MyDialog3::~MyDialog3()
{
	// Disconnect Events
	buscadorcod->Disconnect( wxEVT_COMMAND_SEARCHCTRL_CANCEL_BTN, wxCommandEventHandler( MyDialog3::clickcancelar ), NULL, this );
	buscadorcod->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyDialog3::buscaronfly ), NULL, this );
	m_button13->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::clickbotonagregar ), NULL, this );
	m_button14->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog3::clickbotoncancelar ), NULL, this );
	
}

MyDialog1::MyDialog1( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText2 = new wxStaticText( this, wxID_ANY, wxT("Establezca el porcentaje de descuento:"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText2->Wrap( -1 );
	bSizer6->Add( m_staticText2, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer7;
	bSizer7 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText3 = new wxStaticText( this, wxID_ANY, wxT("%"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText3->Wrap( -1 );
	bSizer7->Add( m_staticText3, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textodescuento = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer7->Add( textodescuento, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer6->Add( bSizer7, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer8;
	bSizer8 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button17 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/aceptar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_button17->SetToolTip( wxT("Aplicar descuento") );
	
	bSizer8->Add( m_button17, 1, wxALL|wxEXPAND, 5 );
	
	m_button18 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cancel.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_button18->SetToolTip( wxT("Cancelar descuento") );
	
	bSizer8->Add( m_button18, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer6->Add( bSizer8, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer6 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	textodescuento->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog1::enteraceptar ), NULL, this );
	m_button17->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::clickaceptar ), NULL, this );
	m_button18->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::clickcancelar ), NULL, this );
}

MyDialog1::~MyDialog1()
{
	// Disconnect Events
	textodescuento->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog1::enteraceptar ), NULL, this );
	m_button17->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::clickaceptar ), NULL, this );
	m_button18->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog1::clickcancelar ), NULL, this );
	
}

MyDialog2::MyDialog2( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer9;
	bSizer9 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxHORIZONTAL );
	
	buscador = new wxSearchCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	#ifndef __WXMAC__
	buscador->ShowSearchButton( false );
	#endif
	buscador->ShowCancelButton( false );
	buscador->SetToolTip( wxT("Ingrese el nombre o código de un producto para filtrar la lista") );
	
	bSizer69->Add( buscador, 1, wxALL|wxEXPAND, 5 );
	
	wxString choisergrillaChoices[] = { wxT("Todos los Productos"), wxT("Productos con menos de 10 unidades"), wxT("Productos sin unidades ") };
	int choisergrillaNChoices = sizeof( choisergrillaChoices ) / sizeof( wxString );
	choisergrilla = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choisergrillaNChoices, choisergrillaChoices, 0 );
	choisergrilla->SetSelection( 0 );
	choisergrilla->SetToolTip( wxT("Elegir filtro de la grilla de stock") );
	
	bSizer69->Add( choisergrilla, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer10->Add( bSizer69, 0, wxEXPAND, 5 );
	
	grilla_stock = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_stock->CreateGrid( 0, 6 );
	grilla_stock->EnableEditing( false );
	grilla_stock->EnableGridLines( true );
	grilla_stock->EnableDragGridSize( false );
	grilla_stock->SetMargins( 0, 0 );
	
	// Columns
	grilla_stock->SetColSize( 0, 97 );
	grilla_stock->SetColSize( 1, 67 );
	grilla_stock->SetColSize( 2, 80 );
	grilla_stock->SetColSize( 3, 103 );
	grilla_stock->SetColSize( 4, 92 );
	grilla_stock->SetColSize( 5, 116 );
	grilla_stock->EnableDragColMove( false );
	grilla_stock->EnableDragColSize( true );
	grilla_stock->SetColLabelSize( 30 );
	grilla_stock->SetColLabelValue( 0, wxT("Nombre") );
	grilla_stock->SetColLabelValue( 1, wxT("Cant.") );
	grilla_stock->SetColLabelValue( 2, wxT("Código") );
	grilla_stock->SetColLabelValue( 3, wxT("Costo p/unidad") );
	grilla_stock->SetColLabelValue( 4, wxT("Fecha") );
	grilla_stock->SetColLabelValue( 5, wxT("Observaciones") );
	grilla_stock->SetColLabelValue( 6, wxT("Fecha") );
	grilla_stock->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_stock->EnableDragRowSize( true );
	grilla_stock->SetRowLabelSize( 1 );
	grilla_stock->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_stock->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer10->Add( grilla_stock, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer9->Add( bSizer10, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );
	
	m_button7 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Agregar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_button7->SetToolTip( wxT("Agregar producto al stock") );
	
	bSizer11->Add( m_button7, 1, wxALL|wxEXPAND, 5 );
	
	m_button8 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cancel.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_button8->SetToolTip( wxT("Eliminar producto seleccionado de la grilla de stock") );
	
	bSizer11->Add( m_button8, 1, wxALL|wxEXPAND, 5 );
	
	m_button9 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Editar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_button9->SetToolTip( wxT("Modificar producto seleccionado del stock") );
	
	bSizer11->Add( m_button9, 1, wxALL|wxEXPAND, 5 );
	
	m_button10 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Guardar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_button10->SetToolTip( wxT("Guardar cambios") );
	
	bSizer11->Add( m_button10, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer9->Add( bSizer11, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer9 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialog2::cerrarventana ) );
	buscador->Connect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyDialog2::busquedaonfly ), NULL, this );
	choisergrilla->Connect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog2::seseleccionogrilla ), NULL, this );
	m_button7->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog2::clickagregarstock ), NULL, this );
	m_button8->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog2::clickeliminarstock ), NULL, this );
	m_button9->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog2::clickmodificarstock ), NULL, this );
	m_button10->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog2::clickguardarstock ), NULL, this );
}

MyDialog2::~MyDialog2()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialog2::cerrarventana ) );
	buscador->Disconnect( wxEVT_COMMAND_TEXT_UPDATED, wxCommandEventHandler( MyDialog2::busquedaonfly ), NULL, this );
	choisergrilla->Disconnect( wxEVT_COMMAND_CHOICE_SELECTED, wxCommandEventHandler( MyDialog2::seseleccionogrilla ), NULL, this );
	m_button7->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog2::clickagregarstock ), NULL, this );
	m_button8->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog2::clickeliminarstock ), NULL, this );
	m_button9->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog2::clickmodificarstock ), NULL, this );
	m_button10->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog2::clickguardarstock ), NULL, this );
	
}

MyDialog9::MyDialog9( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer42;
	bSizer42 = new wxBoxSizer( wxHORIZONTAL );
	
	wxBoxSizer* bSizer43;
	bSizer43 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer76;
	bSizer76 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton41 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cerrarsmall.png"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton41->SetToolTip( wxT("Cancela el filtro de fecha y vuelve a mostrar la grilla completa") );
	
	bSizer76->Add( m_bpButton41, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	cosofecha = new wxDatePickerCtrl( this, wxID_ANY, wxDefaultDateTime, wxDefaultPosition, wxDefaultSize, wxDP_DEFAULT|wxDP_DROPDOWN );
	cosofecha->SetToolTip( wxT("Filtrar grilla de gastos por fecha") );
	
	bSizer76->Add( cosofecha, 1, wxALL, 5 );
	
	
	bSizer43->Add( bSizer76, 0, wxEXPAND, 5 );
	
	grilla_gastos_externos = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );
	
	// Grid
	grilla_gastos_externos->CreateGrid( 0, 3 );
	grilla_gastos_externos->EnableEditing( false );
	grilla_gastos_externos->EnableGridLines( true );
	grilla_gastos_externos->EnableDragGridSize( false );
	grilla_gastos_externos->SetMargins( 0, 0 );
	
	// Columns
	grilla_gastos_externos->SetColSize( 0, 106 );
	grilla_gastos_externos->SetColSize( 1, 238 );
	grilla_gastos_externos->SetColSize( 2, 92 );
	grilla_gastos_externos->EnableDragColMove( false );
	grilla_gastos_externos->EnableDragColSize( true );
	grilla_gastos_externos->SetColLabelSize( 30 );
	grilla_gastos_externos->SetColLabelValue( 0, wxT("Fecha") );
	grilla_gastos_externos->SetColLabelValue( 1, wxT("Descripción") );
	grilla_gastos_externos->SetColLabelValue( 2, wxT("Costo") );
	grilla_gastos_externos->SetColLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Rows
	grilla_gastos_externos->EnableDragRowSize( true );
	grilla_gastos_externos->SetRowLabelSize( 1 );
	grilla_gastos_externos->SetRowLabelAlignment( wxALIGN_CENTRE, wxALIGN_CENTRE );
	
	// Label Appearance
	
	// Cell Defaults
	grilla_gastos_externos->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	bSizer43->Add( grilla_gastos_externos, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxHORIZONTAL );
	
	labeltotal = new wxStaticText( this, wxID_ANY, wxT("Gastos del dia"), wxDefaultPosition, wxDefaultSize, 0 );
	labeltotal->Wrap( -1 );
	labeltotal->Hide();
	
	bSizer69->Add( labeltotal, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textototalgastos = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	textototalgastos->Enable( false );
	textototalgastos->Hide();
	
	bSizer69->Add( textototalgastos, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer43->Add( bSizer69, 0, wxEXPAND, 5 );
	
	
	bSizer42->Add( bSizer43, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxVERTICAL );
	
	m_bpButton27 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Agregar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton27->SetToolTip( wxT("Agregar un nuevo gasto") );
	
	bSizer45->Add( m_bpButton27, 1, wxALL|wxEXPAND, 5 );
	
	m_bpButton28 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cancel.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton28->SetToolTip( wxT("Eliminar gasto seleccionado de la grilla") );
	
	bSizer45->Add( m_bpButton28, 1, wxALL|wxEXPAND, 5 );
	
	m_bpButton29 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Editar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton29->SetToolTip( wxT("Modificar gasto seleccionado de la grilla") );
	m_bpButton29->SetHelpText( wxT("Editar la fila seleccionada") );
	
	bSizer45->Add( m_bpButton29, 1, wxALL|wxEXPAND, 5 );
	
	m_bpButton30 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/Guardar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton30->SetToolTip( wxT("Guardar cambios") );
	
	bSizer45->Add( m_bpButton30, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer42->Add( bSizer45, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer42 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialog9::cerrarventana ) );
	m_bpButton41->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog9::clickcancelarfiltro ), NULL, this );
	cosofecha->Connect( wxEVT_DATE_CHANGED, wxDateEventHandler( MyDialog9::fechacambio ), NULL, this );
	m_bpButton27->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog9::clickagregar ), NULL, this );
	m_bpButton28->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog9::clickeliminar ), NULL, this );
	m_bpButton29->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog9::clickmodificar ), NULL, this );
	m_bpButton30->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog9::clickguardar ), NULL, this );
}

MyDialog9::~MyDialog9()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialog9::cerrarventana ) );
	m_bpButton41->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog9::clickcancelarfiltro ), NULL, this );
	cosofecha->Disconnect( wxEVT_DATE_CHANGED, wxDateEventHandler( MyDialog9::fechacambio ), NULL, this );
	m_bpButton27->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog9::clickagregar ), NULL, this );
	m_bpButton28->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog9::clickeliminar ), NULL, this );
	m_bpButton29->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog9::clickmodificar ), NULL, this );
	m_bpButton30->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog9::clickguardar ), NULL, this );
	
}

MyDialog10::MyDialog10( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer45;
	bSizer45 = new wxBoxSizer( wxVERTICAL );
	
	wxBoxSizer* bSizer46;
	bSizer46 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText30 = new wxStaticText( this, wxID_ANY, wxT("Costo"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText30->Wrap( -1 );
	bSizer46->Add( m_staticText30, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textocosto = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer46->Add( textocosto, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer45->Add( bSizer46, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer47;
	bSizer47 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText31 = new wxStaticText( this, wxID_ANY, wxT("Descripción"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText31->Wrap( -1 );
	bSizer47->Add( m_staticText31, 0, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textodesc = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer47->Add( textodesc, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer45->Add( bSizer47, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer48;
	bSizer48 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText32 = new wxStaticText( this, wxID_ANY, wxT("Día"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText32->Wrap( -1 );
	bSizer48->Add( m_staticText32, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textodia = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer48->Add( textodia, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText33 = new wxStaticText( this, wxID_ANY, wxT("Mes"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText33->Wrap( -1 );
	bSizer48->Add( m_staticText33, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textomes = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer48->Add( textomes, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	m_staticText34 = new wxStaticText( this, wxID_ANY, wxT("Año"), wxDefaultPosition, wxDefaultSize, wxALIGN_RIGHT );
	m_staticText34->Wrap( -1 );
	bSizer48->Add( m_staticText34, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textoanio = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer48->Add( textoanio, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer45->Add( bSizer48, 0, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer49;
	bSizer49 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton27 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/aceptar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton27->SetToolTip( wxT("Aceptar cambios") );
	
	bSizer49->Add( m_bpButton27, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	m_bpButton28 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cancel.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton28->SetToolTip( wxT("Cancelar cambios") );
	
	bSizer49->Add( m_bpButton28, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer45->Add( bSizer49, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer45 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	textoanio->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog10::enteraceptar ), NULL, this );
	m_bpButton27->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog10::clickaceptar ), NULL, this );
	m_bpButton28->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog10::clickcancelar ), NULL, this );
}

MyDialog10::~MyDialog10()
{
	// Disconnect Events
	textoanio->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog10::enteraceptar ), NULL, this );
	m_bpButton27->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog10::clickaceptar ), NULL, this );
	m_bpButton28->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog10::clickcancelar ), NULL, this );
	
}

MyDialog141::MyDialog141( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer60;
	bSizer60 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText44 = new wxStaticText( this, wxID_ANY, wxT("Indique la cantidad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText44->Wrap( -1 );
	bSizer60->Add( m_staticText44, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	textocantidad = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer60->Add( textocantidad, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer61;
	bSizer61 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bpButton36 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/aceptar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton36->SetToolTip( wxT("Aceptar cantidad ingresada") );
	
	bSizer61->Add( m_bpButton36, 1, wxALL|wxEXPAND, 5 );
	
	m_bpButton37 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cancel.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton37->SetToolTip( wxT("Cancelar cambios") );
	
	bSizer61->Add( m_bpButton37, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer60->Add( bSizer61, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer60 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	textocantidad->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog141::entertexto ), NULL, this );
	m_bpButton36->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog141::clickaceptar ), NULL, this );
	m_bpButton37->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog141::clickcancelar ), NULL, this );
}

MyDialog141::~MyDialog141()
{
	// Disconnect Events
	textocantidad->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog141::entertexto ), NULL, this );
	m_bpButton36->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog141::clickaceptar ), NULL, this );
	m_bpButton37->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog141::clickcancelar ), NULL, this );
	
}

MyDialog13::MyDialog13( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOW ) );
	
	wxBoxSizer* bSizer56;
	bSizer56 = new wxBoxSizer( wxVERTICAL );
	
	m_bitmap4 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Icons/Login.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxSize( -1,-1 ), 0 );
	m_bitmap4->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	
	bSizer56->Add( m_bitmap4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	textousuario = new wxTextCtrl( this, wxID_ANY, wxT("Ingrese el nombre de usuario"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	textousuario->SetFont( wxFont( 9, 74, 93, 90, false, wxT("Arial") ) );
	textousuario->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DDKSHADOW ) );
	
	bSizer56->Add( textousuario, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_staticline1 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer56->Add( m_staticline1, 0, wxEXPAND | wxALL, 5 );
	
	textopass = new wxTextCtrl( this, wxID_ANY, wxT("contraseña"), wxDefaultPosition, wxDefaultSize, wxTE_CENTRE|wxTE_PASSWORD );
	textopass->SetFont( wxFont( 9, 74, 93, 90, false, wxT("Arial") ) );
	textopass->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_3DDKSHADOW ) );
	
	bSizer56->Add( textopass, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	m_hyperlink4 = new wxHyperlinkCtrl( this, wxID_ANY, wxT("Olvide mi contraseña"), wxEmptyString, wxDefaultPosition, wxDefaultSize, wxHL_ALIGN_CENTRE|wxHL_DEFAULT_STYLE );
	
	m_hyperlink4->SetHoverColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_hyperlink4->SetNormalColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_hyperlink4->SetVisitedColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_hyperlink4->SetFont( wxFont( 8, 74, 90, 90, true, wxT("Arial") ) );
	m_hyperlink4->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_HIGHLIGHT ) );
	m_hyperlink4->SetToolTip( wxT("Se abrira una ventana que le ayudara a recuperar su contraseña") );
	
	bSizer56->Add( m_hyperlink4, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline2 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer56->Add( m_staticline2, 0, wxEXPAND | wxALL, 5 );
	
	wxBoxSizer* bSizer57;
	bSizer57 = new wxBoxSizer( wxHORIZONTAL );
	
	m_button3 = new wxButton( this, wxID_ANY, wxT("Login"), wxDefaultPosition, wxDefaultSize, 0 );
	m_button3->SetToolTip( wxT("Iniciar sesión") );
	
	bSizer57->Add( m_button3, 1, wxALL|wxALIGN_CENTER_VERTICAL|wxEXPAND, 5 );
	
	
	bSizer56->Add( bSizer57, 0, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer56 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialog13::Onbotoncerrar ) );
	textousuario->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MyDialog13::yanofocususer ), NULL, this );
	textousuario->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( MyDialog13::focususer ), NULL, this );
	textopass->Connect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MyDialog13::yanofocuspass ), NULL, this );
	textopass->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( MyDialog13::focuspass ), NULL, this );
	textopass->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog13::enterpass ), NULL, this );
	m_hyperlink4->Connect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( MyDialog13::clickolvidepass ), NULL, this );
	m_button3->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog13::clicklogin ), NULL, this );
}

MyDialog13::~MyDialog13()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialog13::Onbotoncerrar ) );
	textousuario->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MyDialog13::yanofocususer ), NULL, this );
	textousuario->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( MyDialog13::focususer ), NULL, this );
	textopass->Disconnect( wxEVT_KILL_FOCUS, wxFocusEventHandler( MyDialog13::yanofocuspass ), NULL, this );
	textopass->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( MyDialog13::focuspass ), NULL, this );
	textopass->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog13::enterpass ), NULL, this );
	m_hyperlink4->Disconnect( wxEVT_COMMAND_HYPERLINK, wxHyperlinkEventHandler( MyDialog13::clickolvidepass ), NULL, this );
	m_button3->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog13::clicklogin ), NULL, this );
	
}

MyDialog17::MyDialog17( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer80;
	bSizer80 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText58 = new wxStaticText( this, wxID_ANY, wxT("Por favor ingrese su nombre de usuario\nsi el usuario esta en nuestra base de datos\nle mostraremos su pregunta de seguridad\npara que pueda ver su contraseña"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText58->Wrap( -1 );
	bSizer80->Add( m_staticText58, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	m_staticline4 = new wxStaticLine( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, wxLI_HORIZONTAL );
	bSizer80->Add( m_staticline4, 0, wxEXPAND | wxALL, 5 );
	
	labelingrese = new wxStaticText( this, wxID_ANY, wxT("Ingrese su nombre de usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	labelingrese->Wrap( -1 );
	bSizer80->Add( labelingrese, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	textousuario = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer80->Add( textousuario, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	botonbuscar = new wxButton( this, wxID_ANY, wxT("Buscar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer80->Add( botonbuscar, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	labelpregunta = new wxStaticText( this, wxID_ANY, wxT("MyLabel"), wxDefaultPosition, wxDefaultSize, 0 );
	labelpregunta->Wrap( -1 );
	labelpregunta->Hide();
	
	bSizer80->Add( labelpregunta, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	textorespuesta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	textorespuesta->Hide();
	
	bSizer80->Add( textorespuesta, 0, wxALL|wxEXPAND, 5 );
	
	botonver = new wxButton( this, wxID_ANY, wxT("Verificar"), wxDefaultPosition, wxDefaultSize, 0 );
	botonver->Hide();
	
	bSizer80->Add( botonver, 0, wxALL|wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );
	
	labelpass = new wxStaticText( this, wxID_ANY, wxT("Esta es su contraseña\nanótela para no olvidarla!"), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	labelpass->Wrap( -1 );
	labelpass->Hide();
	
	bSizer80->Add( labelpass, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	textopass = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_CENTRE );
	textopass->Enable( false );
	textopass->Hide();
	
	bSizer80->Add( textopass, 0, wxALL|wxEXPAND, 5 );
	
	m_bpButton42 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/aceptar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	bSizer80->Add( m_bpButton42, 1, wxALL|wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer80 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	botonbuscar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog17::clickbuscar ), NULL, this );
	botonver->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog17::clickverificar ), NULL, this );
	m_bpButton42->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog17::clickfinalizar ), NULL, this );
}

MyDialog17::~MyDialog17()
{
	// Disconnect Events
	botonbuscar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog17::clickbuscar ), NULL, this );
	botonver->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog17::clickverificar ), NULL, this );
	m_bpButton42->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog17::clickfinalizar ), NULL, this );
	
}

MyDialog15::MyDialog15( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer66;
	bSizer66 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bitmap6 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Icons/Registro.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer66->Add( m_bitmap6, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer67;
	bSizer67 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText46 = new wxStaticText( this, wxID_ANY, wxT("Bienvenido a Supra Market!\nPara poder comenzar necesita crear un usuario y contraseña que le permitira el ingreso al programa, mas adelante tendrá la posibilidad de brindar acceso a otras personas mediante la creación de mas usuarios."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText46->Wrap( -1 );
	bSizer67->Add( m_staticText46, 1, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer69;
	bSizer69 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText48 = new wxStaticText( this, wxID_ANY, wxT("Ingrese su nuevo nombre de usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText48->Wrap( -1 );
	bSizer69->Add( m_staticText48, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textouser = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer69->Add( textouser, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer67->Add( bSizer69, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer68;
	bSizer68 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText47 = new wxStaticText( this, wxID_ANY, wxT("Ingrese su nueva contraseña"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText47->Wrap( -1 );
	bSizer68->Add( m_staticText47, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textopass = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer68->Add( textopass, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer67->Add( bSizer68, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer77;
	bSizer77 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText54 = new wxStaticText( this, wxID_ANY, wxT("Escoja su pregunta de seguridad"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText54->Wrap( -1 );
	bSizer77->Add( m_staticText54, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	wxString choiserrespuestaChoices[] = { wxT("¿Cual fue el primer automovil que compraste?"), wxT("¿Cual es el nombre de tu mascota?"), wxT("¿Como se llama tu equipo favorito?"), wxT("¿En que año finalizaste la escuela secundaria?"), wxT("¿Cual es tu pasatiempo favorito?"), wxT("¿Donde vivias cuando eras menor?"), wxT("¿Cual fue tu primer videojuego?"), wxT("¿Cual es el segundo nombre de tu mama?"), wxT("¿Cual es el segundo nombre de tu papa?") };
	int choiserrespuestaNChoices = sizeof( choiserrespuestaChoices ) / sizeof( wxString );
	choiserrespuesta = new wxChoice( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, choiserrespuestaNChoices, choiserrespuestaChoices, 0 );
	choiserrespuesta->SetSelection( 0 );
	bSizer77->Add( choiserrespuesta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer67->Add( bSizer77, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer79;
	bSizer79 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText55 = new wxStaticText( this, wxID_ANY, wxT("Ingrese su respuesta"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText55->Wrap( -1 );
	bSizer79->Add( m_staticText55, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textorespuesta = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer79->Add( textorespuesta, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer67->Add( bSizer79, 1, wxEXPAND, 5 );
	
	m_bpButton39 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/aceptar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton39->SetToolTip( wxT("Crear nuevo usuario") );
	
	bSizer67->Add( m_bpButton39, 0, wxALL|wxEXPAND, 5 );
	
	
	bSizer66->Add( bSizer67, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer66 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	this->Connect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialog15::onbotoncerrar ) );
	textopass->Connect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog15::enterpass ), NULL, this );
	m_bpButton39->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog15::clickbotonaceptar ), NULL, this );
}

MyDialog15::~MyDialog15()
{
	// Disconnect Events
	this->Disconnect( wxEVT_CLOSE_WINDOW, wxCloseEventHandler( MyDialog15::onbotoncerrar ) );
	textopass->Disconnect( wxEVT_COMMAND_TEXT_ENTER, wxCommandEventHandler( MyDialog15::enterpass ), NULL, this );
	m_bpButton39->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog15::clickbotonaceptar ), NULL, this );
	
}

MyDialog16::MyDialog16( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxDialog( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	
	wxBoxSizer* bSizer70;
	bSizer70 = new wxBoxSizer( wxHORIZONTAL );
	
	m_bitmap6 = new wxStaticBitmap( this, wxID_ANY, wxBitmap( wxT("Icons/Registro.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer70->Add( m_bitmap6, 0, wxALL, 5 );
	
	wxBoxSizer* bSizer71;
	bSizer71 = new wxBoxSizer( wxVERTICAL );
	
	m_staticText49 = new wxStaticText( this, wxID_ANY, wxT("Para poder cambiar su contraseña\ndebera ingresar su nombre de usuario y contraseña actual\npara que podamos verificar su identidad."), wxDefaultPosition, wxDefaultSize, wxALIGN_CENTRE );
	m_staticText49->Wrap( -1 );
	bSizer71->Add( m_staticText49, 0, wxALL|wxEXPAND, 5 );
	
	wxBoxSizer* bSizer73;
	bSizer73 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText51 = new wxStaticText( this, wxID_ANY, wxT("Nombre de usuario actual"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText51->Wrap( -1 );
	bSizer73->Add( m_staticText51, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textoactualuser = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer73->Add( textoactualuser, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer71->Add( bSizer73, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer72;
	bSizer72 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText50 = new wxStaticText( this, wxID_ANY, wxT("Contraseña actual"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText50->Wrap( -1 );
	bSizer72->Add( m_staticText50, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textoactualpass = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer72->Add( textoactualpass, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer71->Add( bSizer72, 1, wxEXPAND, 5 );
	
	wxBoxSizer* bSizer74;
	bSizer74 = new wxBoxSizer( wxHORIZONTAL );
	
	m_staticText53 = new wxStaticText( this, wxID_ANY, wxT("Ingrese su nueva contraseña"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText53->Wrap( -1 );
	bSizer74->Add( m_staticText53, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	textonuevapass = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer74->Add( textonuevapass, 1, wxALL|wxALIGN_CENTER_VERTICAL, 5 );
	
	
	bSizer71->Add( bSizer74, 1, wxEXPAND, 5 );
	
	labelmal = new wxStaticText( this, wxID_ANY, wxT("Datos Incorrectos!"), wxDefaultPosition, wxDefaultSize, 0 );
	labelmal->Wrap( -1 );
	labelmal->SetFont( wxFont( 9, 74, 93, 92, false, wxT("Arial") ) );
	labelmal->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );
	labelmal->Hide();
	
	bSizer71->Add( labelmal, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );
	
	wxBoxSizer* bSizer75;
	bSizer75 = new wxBoxSizer( wxHORIZONTAL );
	
	botonaceptar = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/aceptar.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	botonaceptar->SetToolTip( wxT("Aceptar cambios") );
	
	bSizer75->Add( botonaceptar, 1, wxALL|wxEXPAND, 5 );
	
	m_bpButton40 = new wxBitmapButton( this, wxID_ANY, wxBitmap( wxT("Icons/cancel.PNG"), wxBITMAP_TYPE_ANY ), wxDefaultPosition, wxDefaultSize, wxBU_AUTODRAW );
	m_bpButton40->SetToolTip( wxT("Cancelar cambios") );
	
	bSizer75->Add( m_bpButton40, 1, wxALL|wxEXPAND, 5 );
	
	
	bSizer71->Add( bSizer75, 0, wxEXPAND, 5 );
	
	
	bSizer70->Add( bSizer71, 1, wxEXPAND, 5 );
	
	
	this->SetSizer( bSizer70 );
	this->Layout();
	
	this->Centre( wxBOTH );
	
	// Connect Events
	textoactualuser->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( MyDialog16::clickuser ), NULL, this );
	textoactualpass->Connect( wxEVT_SET_FOCUS, wxFocusEventHandler( MyDialog16::clickpass ), NULL, this );
	botonaceptar->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog16::clickaceptar ), NULL, this );
	m_bpButton40->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog16::clickcancelar ), NULL, this );
}

MyDialog16::~MyDialog16()
{
	// Disconnect Events
	textoactualuser->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( MyDialog16::clickuser ), NULL, this );
	textoactualpass->Disconnect( wxEVT_SET_FOCUS, wxFocusEventHandler( MyDialog16::clickpass ), NULL, this );
	botonaceptar->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog16::clickaceptar ), NULL, this );
	m_bpButton40->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( MyDialog16::clickcancelar ), NULL, this );
	
}
