#include "palabra.h"

using namespace std;

//Constructores
Palabra::Palabra(){}

Palabra::Palabra(pair<string, set<string> > c){
	palabra=c;
}

//Modificadores y consultores
string Palabra::GetClave(){
	return palabra.first;
}

void Palabra::SetClave(string c){
	palabra.first=c;
}

vector<string> Palabra::GetTraduccion(){
	set<string>::iterator it;
	vector<string> tmp;

	for(it=palabra.second.begin(); it!=palabra.second.end(); ++it)
		tmp.push_back(*it);
	
	return tmp;
}

set<string> Palabra::GetTraducciones(){
	return palabra.second;
}

//Otras funciones
void Palabra::print(){
	set<string>::iterator it;
	cout << "Clave: " << palabra.first << " | ";

	for(it=palabra.second.begin(); it!=palabra.second.end(); ++it)
		cout << "Traduccion: " << *it << " ";

	cout << endl;
}

void Palabra::clear(){
	palabra.first="";
	set<string>::iterator it;

	for(it=palabra.second.begin(); it!=palabra.second.end(); ++it)
		palabra.second.erase(*it);

	palabra.second=palabra.second;
}

void Palabra::InsertLet(char c){
	string aux= palabra.first;
	aux+=c;
	palabra.first=aux;
}

void Palabra::InsertTraduc(string t){
	palabra.second.insert(t);
}

int Palabra::SizeTr(){
	return palabra.second.size();
}