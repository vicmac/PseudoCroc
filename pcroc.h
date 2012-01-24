/*
  Name: Pseudocroc (pcroc.h)
  Copyright: Copyleft

string Author
    if (codeCompiles && codeWorks)
      Author = "Victor Manuel Macías Aguayo";
    else
      Author = "???";

  cout << "  Author: " << Author << endl;

  Description: Function prototypes for C to Pseudo-C-language translator

*/

#ifndef PCROC_H
#define PCROC_H

#include<iostream>
#include<fstream>
#include<string>

using namespace std;

void toPseudo(ifstream &, ofstream &, const int &);
void keyWords(string &);
void counters(string &);
void assign(string &);
void keys(string &, const int &);
void semiColons(string &);
void boolExp(string &);
void printF(string &);
void scanF(string &);

string getCount(const char &, const int &, const string &);

void pausa(void);

#endif
