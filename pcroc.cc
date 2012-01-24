/*
  Name: Pseudocroc (pcroc.cc)
  Copyright: Copyleft

  string Author
    if (codeCompiles && codeWorks)
      Author = "Victor Manuel Macias Aguayo";
    else
      Author = "???";

  cout <<  "Author: " << Author << endl;

  Description: Function definitions por C-to-Pseudo-C language translator

  El siguente codigo es como una mujer, no lo comprendas, solo amalo!!!
*/

#include"pcroc.h"

using namespace std;

//Aqui se lleva a cabo la magia!
void toPseudo(ifstream &input, ofstream &output, const int &tab){

	string in;

	while(!input.eof()){
		getline(input, in);		

		keyWords(in);
		semiColons(in);
		counters(in);
		assign(in);
		keys(in, tab);
		boolExp(in);

		output << in << endl;
	}

	return;
}


/*******************************************************************************
 * void keyWords(string &in);
 * Cambia mayor parte de las palabras reservadas del lenguaje.
 * Ya casi!!!
*******************************************************************************/
void keyWords(string &in){

  if (in.find("printf") != string::npos)
  	printF(in);
  
  else if (in.find("scanf") != string::npos)
  	scanF(in);
  	
  else{
  	
	  if (in.find("main") != string::npos)
  		in.replace(in.begin()+in.find("main"), in.begin()+in.find("main")+4, "Principal");
  		
	  if (in.find("void") != string::npos)
  		in.replace(in.begin()+in.find("void"), in.begin()+in.find("void")+4, "nada");
  	  
	  else if (in.find("char ") != string::npos)
	    in.replace(in.begin()+in.find("char "), in.begin()+in.find("char ")+4, "caracter" );
	    
	  else if (in.find("long") != string::npos)
	    in.replace(in.begin()+in.find("long"), in.begin()+in.find("long")+4, "largo");

    if (in.find("int") != string::npos)
      in.replace(in.begin()+in.find("int"), in.begin()+in.find("int")+3, "entero");

 	  else if (in.find("float") != string::npos)
 	    in.replace(in.begin()+in.find("float"), in.begin()+in.find("float")+5, "real");

		else if (in.find("double") != string::npos)
  	  in.replace(in.begin()+in.find("double"), in.begin()+in.find("double")+6, "doble");

	  else if (in.find("for") != string::npos)
	    in.replace(in.begin()+in.find("for"), in.begin()+in.find("for")+3, "desde");

	  else if (in.find("do") != string::npos)
	    in.replace(in.begin()+in.find("do"), in.begin()+in.find("do")+2, "hacer");

	  else if (in.find("while") != string::npos)
	    in.replace(in.begin()+in.find("while"), in.begin()+in.find("while")+5, "mientras");

	  else if (in.find("if") != string::npos)
	    in.replace(in.begin()+in.find("if"), in.begin()+in.find("if")+2, "si");

	  else if (in.find("else") != string::npos)
	    in.replace(in.begin()+in.find("else"), in.begin()+in.find("else")+4, "si no");

  	else if (in.find("switch") != string::npos)
	    in.replace(in.begin()+in.find("switch"), in.begin()+in.find("switch")+6, "segun_sea");

	  else if (in.find("case") != string::npos)
	    in.replace(in.begin()+in.find("case"), in.begin()+in.find("case")+4, "caso");

	  else if (in.find("break") != string::npos)
  	    in.replace(in.begin()+in.find("break"), in.begin()+in.find("break")+5, "salir");

	  else if (in.find("default:") != string::npos)
  	  in.replace(in.begin()+in.find("default:"), in.begin()+in.find("default:")+8, "caso_contrario:");

  	else if (in.find("return") != string::npos)
	    in.replace(in.begin()+in.find("return"), in.begin()+in.find("return")+6, "regresa");
	}
	
	return;
}


/*******************************************************************************
 * void counters(string &in);
 * Expande los contadores...
 *
 * Soy un genio!
*******************************************************************************/
void counters(string &in){

	for (int i=0; i<in.length(); i++){
		if (in[i]=='+' && in[i+1]=='+')
			in.replace(in.begin()+i, in.begin()+i+2, getCount('+',i-1, in));

		else if (in[i]=='-' && in[i+1]=='-')
			in.replace(in.begin()+i, in.begin()+i+2, getCount('-',i-1, in));

  }

  return;
}


/*******************************************************************************
 * void getCount(string &in);
 * Regresa la variable del contador actual
 *
 * Los reto a hacerlo de manera mas sencilla...
*******************************************************************************/
string getCount(const char &sign, const int &i, const string &in){
  int j=i;

  while (in[j]!=' ' && in[j]!=';' && in[j]!='(' && j>0)
    j--;
    
  j++;

  return ("=" + in.substr(j, i-j+1) + sign + "1");
}


/*******************************************************************************
 * void assign(string &in);
 * Cambia los iguales por arrobas para cambio facil y cambia los dobles iguales
 * por iguales normalitos... Nada fuera de lo común...
*******************************************************************************/
void assign(string &in){

	for (int i = 0; i < in.length(); i++)

		if (in[i] == '=' && in[i-1]!='<' && in[i-1]!='>' && in[i-1]!='!')
			in[i] = '@';


	for (int i = 0; i < in.length(); i++)
		if (in[i] == '@' && in[i+1] == '@')
        in.replace(in.begin()+i, in.begin()+i+2, "=");
				
	return;
}


/*******************************************************************************
 * void keys(string &in, const int &tab);
 * Cambia las llaves por Inicio y Fin
 *
 * Waters! (Aguas!)
 * Por favor no toques nada, funciona de maravillas... Hasta indenta!
 * No lo podras optimizar, creeme... Lo intente... Muchas horas...
 *
 * Aunque estoy casi seguro que esos booleanos no son tan utiles como creo...
*******************************************************************************/
void keys(string &in, const int &tab){
	bool bani = true;
  bool banf = true;
	int ind;

	for (ind = 0; ind < in.length()-1 && bani ; ind++)
		if (in[ind]!=' ')
			bani = banf = false;
			

	for (int i = 0; i < in.length(); i++){

		if(in[i]=='{'){

			if (i==0 || bani)
        in.replace(in.begin()+i, in.begin()+i+1, "Inicio");

			else{
				in.replace(in.begin()+i, in.begin()+i+1,"\n");

				for (int j=0; j<ind-1; j++)
					in += " ";

				in += "Inicio";
			}

		}

		else if (in[i]=='}'){

			if (i==0 || banf)
				in.replace(in.begin()+i, in.begin()+i+1, "Fin");

			else{
				in.replace(in.begin()+i, in.begin()+i+1,"\n");

				for (int j=0; j<ind-(1+tab); j++)
					in += " ";

				in += "Fin";
			}

		}

	}

	return;
}


/*******************************************************************************
  void semicolons (string &);
  Cambia los ; por , y si es el ; final lo elimina
*******************************************************************************/
void semiColons(string &in){

	for (int i=0; i < in.length(); i++)
		if (in[i] == ';')
			if (i == in.length()-1)
				in[i] = '\0';
			else
				in[i] = ',';

	return;
}


/*******************************************************************************
 * void boolExp(string &in);
 * Cambia las comparativas && || y !=
*******************************************************************************/
void boolExp(string &in){

	for (int i = 0; i< in.length(); i++)
		if (in[i]==in[i+1]){
			switch(in[i]){
			case '&':
				in.replace(in.begin()+i, in.begin()+i+2, "y");
				break;

			case '|':
				in.replace(in.begin()+i, in.begin()+i+2, "o");
				break;
			}
		}

		else if (in[i]=='!' && in[i+1]=='=')
      in.replace(in.begin()+i, in.begin()+i+2, "<>");

	return;
}



/*******************************************************************************
 * Solo los puros de corazon y espiritu podran entender lo que el
 * siguiente codigo hace linea por linea...
 *
 * void printF(string &in);
 * Cambia los especialmente molestos printf!!!
 *
 * Waters! (Aguas!)
 * La funcion esta (casi) perfecta asi, ya no la toques!!! Solo yo y
 * Dios (y de mi ya no estoy tan seguro) entendemos como funciona, por ahora...
 * Si crees haberla entendido, ESTAS MAL!!! NO ES COMO PIENSAS!!!
 * HEREJE!!!
 *
 * No lleva comentarios adicionales, me costo uno escribir todo esto...
 * Que te cueste los dos leerlo... nwn Suerte!!!
*******************************************************************************/
void printF(string &in){
  int pos= in.find("printf");

  if (pos != string::npos){

    in.replace(in.begin()+pos, in.begin()+pos+7, "Imprime ");

		in.erase(in.begin()+in.rfind(')'), in.begin()+in.rfind(')')+1);

    int ap=in.rfind('"');
    int coma=in.rfind(',', ap+2);

    if (coma != ap && coma>ap){

      string str, var;
      int start = in.find('"'), pos;

      str = in.substr(start-1, ap-(start-2));

      var = in.substr(coma);

			in.erase(in.begin()+in.find("Imprime")+7, in.end());

      while(str.rfind('%') != string::npos){
        pos = str.rfind('%');
        str.replace(str.begin()+pos-1, str.begin()+pos+2, ("\"," + var.substr(var.rfind(',')+1, var.size()) + ", \""));
        var.erase(var.rfind(','));
     }

      var = ";,";
      str.erase(str.begin()+str.rfind(var), str.begin()+str.rfind(var)+1);

      var = "\"\",";
      while(str.rfind(var) != string::npos)
        str.erase(str.begin()+str.rfind(var), str.begin()+str.rfind(var)+3);

			//Luego del trabajo sucio, hay que limpiar!!!
			if (str.find('(') != string::npos && str.find('(') < str.find('"'))
				str.erase(str.begin()+str.find('(')-1, str.begin()+str.find('('));

			if (str.find(", \"\"") != string::npos)
				str.erase(str.begin()+str.find(", \"\""), str.begin()+str.find(", \"\"")+4);

      in += str;
    }
  }

	return;
}

/*******************************************************************************
 * void scanF(string &in);
 * Cambia los scanf!!!
 *
 * Nada dificil, algunos artilugios pero funciona nice.
*******************************************************************************/
void scanF(string &in){

	if (in.find("scanf") != string::npos)
		in.replace(in.begin()+in.find("scanf"), in.begin()+in.find("scanf")+6, "Leer");
	
	string var;
	int pos = in.find(",");
	
	var = in.substr(pos);
	
	in.erase(in.begin()+pos, in.end());
	
	var.erase(var.begin()+var.rfind(")"), var.end());
	
	while (var.rfind('&') != string::npos){
		in.replace(in.begin()+in.rfind("%"), in.begin()+in.rfind("%")+2, (var.substr(var.rfind("&")+1)+ ","));
		
		var.erase(var.begin()+var.rfind(","), var.end());
	}
	
	while (in.find("\"") != string::npos)
		in.replace(in.begin()+in.find("\""), in.begin()+in.find("\"")+1, " ");
		
	in.replace(in.begin()+in.rfind(","), in.begin()+in.rfind(",")+1, "");
		
	return;
}

// @Override
// system("pause"){
void pausa(void){
  cout << endl << "Presiona enter para continuar..." << endl;
  getchar();
  return;
}
// }
// xD


