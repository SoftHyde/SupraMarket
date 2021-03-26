#ifndef MANEJOOPCIONES_H
#define MANEJOOPCIONES_H
#include <vector>
using namespace std;

class manejoopciones {
private:
	vector<bool> vecopciones;
	bool a;
protected:
public:
	manejoopciones();
	bool guardar();
	int cantopc();
	~manejoopciones();
};

#endif

