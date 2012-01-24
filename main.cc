#include<iostream>
#include<fstream>
#include<string>
#include"pcroc.h"

using namespace std;

int main(){

unsigned int tab;
string aux;

	cout << "Pseudocroc!!!" << endl << endl; // Que efusivo!!! xD
	
	cout << "Cuantos son los espacios que usas por tabulacion???" << endl << "> ";

	do{
		cin >> tab; // Ingresa numero enteros, por favor!!!
		cin.ignore();
		if (tab<0)
			cout << "No es un numero valido... Intenta de nuevo" << endl << "> ";
	}
	while (tab<0);

	cout << "Ingresa el nombre del archivo que vas a abrir (con extension): " << endl;
  cout << "> ";

	getline(cin, aux);
	ifstream input (aux.c_str());

	if (input.fail()){
		cerr << "Fallo en la apertura del archivo de entrada... Saliendo del programa..." << endl;
		pausa();
		return 1;
	}


	aux.erase(aux.begin()+aux.find('.'), aux.end());
	aux += ".pseudo";  // Genio creativo para la extension


  cout << "El archivo creado sera llamado " << aux << "..." << endl;
	ofstream output(aux.c_str());

	toPseudo(input, output, tab);

	cout << endl << "Conversion exitosa..." << endl;  // De nuevo, que efusivo!!!

	
	input.close();
	output.close();

  pausa();

	return 0;
}
