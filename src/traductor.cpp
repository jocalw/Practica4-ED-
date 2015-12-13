#include "traductor.h"

using namespace std;

//Constructores
Traductor::Traductor(){}

Traductor::Traductor(map<string, Palabra> t){
	diccionario=t;
}

//Consultores
Palabra Traductor::GetPalabra(string p){
	Palabra aux= diccionario[p];
	return aux;
}

vector<string> Traductor::GetTraducciones(string a){
	Palabra aux;
	vector<string> t;
	map<string, Palabra>::iterator it;
	it=diccionario.begin();

	t.push_back("No encontrado");

	while(it!=diccionario.end()){
		aux=it->second;

		if(a.compare(aux.GetClave())==0)
			return aux.GetTraduccion();
		++it;
	}
	return t;
}

//Sobrecarga operador >>
istream& operator>>(istream& is, Traductor& t){
	bool fLinea=false, fFichero=false, clave=false;
	Palabra aux;
	char letra;
	string traduc;

	while(!fFichero){
		while(!fLinea){
			is.get(letra);
			while(letra!=';' && letra!='\n'){
				if(!clave)
					aux.InsertLet(letra);
				else
					traduc+=letra;
				is.get(letra);
			}

			if(!clave)
				clave=true;
			else
			{	
				aux.InsertTraduc(traduc);
				traduc.clear();
			}
			if(letra=='\n')
				fLinea=true;
			if(is.eof()){
				fFichero=true;
				fLinea=true;
			}
		}
		clave=false;
		fLinea=false;
		t.diccionario.insert(pair<string, Palabra>(aux.GetClave(), aux));
		aux.clear();
		if(is.eof())
			fFichero=true;
	}
	return is;
}

//Otras funciones
void Traductor::print(){
	map<string, Palabra>::iterator it;
	Palabra aux;

	for(it=diccionario.begin(); it!=diccionario.end(); ++it){
		aux=it->second;
		aux.print();
	}
}

bool Traductor::buscarPalabra(string a){
	string aux;
	map<string, Palabra>::iterator it;
	it=diccionario.begin();

	while(it!=diccionario.end()){
		aux=it->first;
		if(a.compare(aux)==0)
			return true;
		++it;
	}
	return false;
}

bool Traductor::empty(){
	return diccionario.empty();
}

void Traductor::InsertaTraduccion(string c, string t){
	map<string, Palabra>::iterator it;
	Palabra aux;

	it=diccionario.find(c);
	it->second.InsertTraduc(t);
	aux=it->second;

	diccionario.insert(it, pair<string, Palabra>(c, aux));
}

void Traductor::InsertaPalabra(string c, string t){
	Palabra aux;

	aux.SetClave(c);
	aux.InsertTraduc(t);
	
	diccionario.insert(pair<string, Palabra>(c, aux));
}
