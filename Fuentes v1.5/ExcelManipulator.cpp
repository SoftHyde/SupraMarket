#include <vole/vole.hpp>
#include <comstl/util/initialisers.hpp>
#include <comstl/util/variant.hpp>
#include <winstl/error/error_desc.hpp>
#include <windows.h>
#include "ExcelManipulator.h"
#include <iostream>
using namespace std;
void *ExcelManipulator::coinit=NULL;
using comstl::ole_init;
using vole::object;
using vole::collection;
using vole::invocation_exception;

// declare los punteros como void* en el .h para no "ensuciar" con includes, namespaces o forward declarations
#define _xlApp ((object*)xlApp)
#define _xlBook ((object*)xlBook)
#define _xlSheet ((object*)xlSheet)

#ifdef __WIN32__
static BOOL FileExists(LPCTSTR szPath) {
	DWORD dwAttrib = GetFileAttributes(szPath);
	return (dwAttrib != INVALID_FILE_ATTRIBUTES && !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));
}

#endif

ExcelManipulator::ExcelManipulator() {
	opened=false;
	xlApp=NULL; xlBook=NULL; xlSheet=NULL;
}

ExcelManipulator::ExcelManipulator(const char *fname, bool visible) {
	opened=false;
	xlApp=NULL; xlBook=NULL; xlSheet=NULL;
	Open(fname,visible);
}

bool ExcelManipulator::Open(const char *fname, bool visible) {
	if (opened) return false;
#ifdef __WIN32__
	// los paths son relativos a quien sabe que, asi que aca se convierten en absolutos
	int fl=strlen(fname);
	char *path=new char[1024+fl+1];
	if (fl>0&&(fname[0]=='\\'||fname[1]==':')) {
		strcpy(path,fname);
	} else {
		int sl=GetCurrentDirectory(1024,path);
		if (path[sl]!='\\') path[sl++]='\\';
		strcpy(path+sl,fname);
	}
	try {
		if ( fname[0] && !FileExists(fname) ) { opened=false; return false; }
		xlApp=xlBook=xlSheet=NULL;
		if (!coinit) coinit = new ole_init();
		xlApp = new object( object::create(L"Excel.Application", CLSCTX_LOCAL_SERVER, vole::coercion_level::naturalPromotion) );
		if (visible) _xlApp->put_property(L"Visible", 1);
		collection xlBooks = _xlApp->get_property<collection>(L"Workbooks") ;
		if (fname[0]=='\0') {
			xlBook = new object( xlBooks.get_property<object>(L"Add") );
		} else {
			xlBook = new object( xlBooks.get_property<object>(L"Open",(const char *)path) );
		}
		xlSheet = new object( _xlApp->get_property<object>(L"ActiveSheet") );
		opened=true;
	} catch(vole::vole_exception &x) {
		opened=false;
	} catch(std::exception &x) {
		opened=false;
	}
	delete path;
#else
	opened=false;
#endif
	return opened;
}
bool ExcelManipulator::IsOpen() { 
	return opened;
}
void ExcelManipulator::SetValue(int x, int y, const char *value) {
#ifdef __WIN32__
	try {
		_xlSheet->get_property<object>(L"Cells", x,y).put_property(L"Value", value);
	} catch (invocation_exception e) {}
#endif
}
void ExcelManipulator::SetValue(int x, int y, int value) {
#ifdef __WIN32__
	try {
		_xlSheet->get_property<object>(L"Cells", x,y).put_property(L"Value", value);
	} catch (invocation_exception e) {}
#endif
}
void ExcelManipulator::SetValue(int x, int y, float value) {
#ifdef __WIN32__
	try {
		_xlSheet->get_property<object>(L"Cells", x,y).put_property(L"Value", value);
	} catch (invocation_exception e) {}
#endif
}
void ExcelManipulator::SetValue(int x, int y, double value) {
#ifdef __WIN32__
	try {
		_xlSheet->get_property<object>(L"Cells", x,y).put_property(L"Value", value);
	} catch (invocation_exception e) {}
#endif
}
void ExcelManipulator::Print() {
#ifdef __WIN32__
	try {
		_xlSheet->invoke_method_v(L"PrintOut");
	} catch (invocation_exception e) {}
#endif
}

void ExcelManipulator::SaveAs(const char *fname) {
#ifdef __WIN32__
	try {
		_xlApp->put_property(L"DisplayAlerts",0); // para que no moleste el comprobador de compatibilidad en los office nuevos
		// los paths son relativos a quien sabe que, asi que aca se convierten en absolutos
		int fl=strlen(fname); if (fl==0) return;
		char *path=new char[1024+fl+1];
		if (fl>0&&(fname[0]=='\\'||fname[1]==':')) {
			strcpy(path,fname);
		} else {
			int sl=GetCurrentDirectory(1024,path);
			if (path[sl]!='\\') path[sl++]='\\';
			strcpy(path+sl,fname);
		}
		_xlBook->invoke_method_v(L"SaveAs",path);
	} catch (invocation_exception e) {}
#endif
}

void ExcelManipulator::Close() {
#ifdef __WIN32__
	try {
		_xlBook->put_property(L"Saved", 1);
		_xlApp->invoke_method_v(L"Quit");
		delete _xlApp;
		delete _xlBook;
		delete _xlSheet;
		xlApp=NULL; xlBook=NULL; xlSheet=NULL;
		opened=false;
	} catch (invocation_exception e) {}
#endif
}
ExcelManipulator::~ExcelManipulator() {
#ifdef __WIN32__
	if (opened) Close();
	delete _xlApp;
	delete _xlBook;
	delete _xlSheet;
#endif
}

bool ExcelManipulator::SelectSheet (int number) {
#ifdef __WIN32__
	try {
		collection xlSheets=_xlBook->get_property<collection>(L"Sheets");
		int n=xlSheets.get_Count();
		if (number<1||number>n) return false;
		xlSheets.get_property<object>(L"Item",number).invoke_method_v(L"Select");
		delete _xlSheet;
		xlSheet = new object(_xlApp->get_property<object>(L"ActiveSheet") );
		return true;
	} catch (invocation_exception e) {}
#endif
}

