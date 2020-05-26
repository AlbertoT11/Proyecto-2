#include <iostream>
#include <array>
#include <fstream>
#include <cstdlib>
#include <string>
#include "Actor.h"
#include "Pelicula.h"
#include "Hora.h"
#include "Funcion.h"
using namespace std;




int main() {

  // Escribe ahora un programa que tenga arreglos de objetos de tipo Actor (con un máximo de 20 actores) Función (con un máximo de 20 funciones) y Pelicula (con un máximo de 20 películas).
  Actor actores[20];
  Funcion funciones[20];
  Pelicula peliculas[20];

  // Carga los datos para el arreglo de Actores de un archivo de texto que contiene en cada renglón el id del Actor y el nombre del actor que es un string de varias palabras (hay un archivo de ejemplo disponible en Blackboard).

  ifstream archEnt("actores.txt");
	ifstream archEnt1("peliculas.txt");

  //string linea;

  
  int identificacion[10], largo = 0, i = 0, espacio, contador = 0;
	int numPeli, year, duracion, numActores, numeroPelicula, hour, minutos;
	int sala, numFunciones, estado = 0;
	string nombreActor, linea, generoPeli, tituloPeli, claveFuncion;
  

	while (!archEnt.eof())
	{
		getline(archEnt, linea);

		espacio = linea.find(" ");
		if(linea != "")
		{
			identificacion[0] = atoi(linea.substr(0, espacio).c_str());
			nombreActor = linea.substr(espacio + 1, largo - espacio);
			Actor actor(identificacion[0], nombreActor);
			actores[contador] = actor;
			contador++;
		}
	}
	archEnt.close();

  //Carga los datos para el arreglo de Películas de un archivo de texto que contiene en cada renglón el número de película, el año en que se hizo, su duración, su género (siempre será una palabra), la cantidad de actores que se agregarán y la lista de id de los actores, finalmente el título de la película que es un string que puede tener varias palabras (hay un archivo de ejemplo disponible en Blackboard).

	i = 0;
	while (!archEnt1.eof())
	{
		getline(archEnt1, linea);
		espacio = linea.find(" ");
		if(linea != "")
		{
			Pelicula pelicula;

			numPeli = atoi(linea.substr(0, espacio).c_str());
			pelicula.set_numPeli(numPeli);
			linea.erase(0, espacio + 1);
			espacio = linea.find(" ");

			year = atoi(linea.substr(0, espacio).c_str());
			pelicula.set_anio(year);
			linea.erase(0, espacio + 1);
			espacio = linea.find(" ");

			duracion = atoi(linea.substr(0, espacio).c_str());
			pelicula.set_duracion(duracion);
			linea.erase(0, espacio + 1);
			espacio = linea.find(" ");

			generoPeli = linea.substr(0, espacio);
			pelicula.set_genero(generoPeli);
			linea.erase(0, espacio + 1);
			espacio = linea.find(" ");

			numActores = atoi(linea.substr(0, espacio).c_str());

			int j = 0;

			while (numActores > 0)
			{
				linea.erase(0, espacio + 1);
				espacio = linea.find(" ");
				identificacion[j] = atoi(linea.substr(0, espacio).c_str());
				pelicula.addActor(identificacion[j]);
				j++;
				numActores--;
			}

			linea.erase(0, espacio + 1);
			espacio = linea.find(" ");
			largo = linea.length();
			tituloPeli = linea.substr(0, largo);
			pelicula.set_titulo(tituloPeli);
			peliculas[i] = pelicula;
			i++;
		}
	}
	int totalPeliculas = i;
	archEnt1.close();
  
 //cout<<peliculas[1].getCantAct();

  //Pide al usuario que teclee los datos para cada una de las funciones disponibles del día.

int cantFunciones;
string cveFuncion;
Hora hora;
int hh;
int mm;
/*for(int j=0; j<peliculas[1].getCantAct(); j++){
    cout << peliculas[1].getlistaActor(j) << " ";
}*/
cout << "\nTeclee la cantidad de funciones del dia\n";
cin >> cantFunciones;
for (int i=0;i<cantFunciones;i++){
  //recibe los datos de cada funcion y los manda a funcion.h
  cout<<"Teclee cveFuncion"<<endl;
  cin>>cveFuncion;
  cout<<"Teclee el numero de pelicula"<<endl;
  cin>>numPeli;
  cout<<"Teclee el numero de la sala"<<endl;
  cin>>sala;
  cout<<"Teclee la Hora de la funcion"<<endl;
  cin>>hh;
  cout<<"Teclee los minutos de la funcion"<<endl;
  cin>>mm;
  Hora hora(hh,mm);
  Funcion agregaFunc(cveFuncion, numPeli, hora, sala);
  funciones[i] = agregaFunc;

  
  /*
  Tu programa deberá tener un menú con las siguientes opciones:
a. Consulta de todos los actores que están en la lista. Debe mostrar
todos los datos del actor. 
b. Consulta de todas las películas que están en la lista. Debe mostrar
el título, año, duración, género y la lista de los nombres de los
actores que participan en una película.
c. Consulta de todas las funciones disponibles, debe mostrar la clave
de la función, el nombre de la película, el número de sala en la que
está y la hora a la que se presenta.
d. Consulta de funciones por hora, deberás pedir al usuario la hora
(hora y minutos), verificar que sea válida (hora entre 0 y 23,
minutos entre 0 y 59) y mostrar el título de la película y el número
de sala de todas las funciones que se presentan en esa hora.
e. Consulta por clave de función, debes validar que la clave de la
función exista y mostrar en la pantalla el número de sala, el título
de la película, la hora a la que se presenta, la duración, el género y
los nombres de los actores que participan en la película.
f. Consulta de películas en las que participa un actor, debes pedir el
id del actor, validar que exista y mostrar en la pantalla el título y
año de todas las películas en las que participa ese actor.
g. Terminar.
 
  */
}
char opcion;
int validarCve = 0, j;






while(opcion!='g'){
  cout<<"\nelija una opcion:"<<endl;
cout<<"a. Consulta de todos los actores que están en la lista."<<endl;
cout<<"b. Consulta de todas las películas que están en la lista."<<endl;
cout<<"c. Consulta de todas las funciones disponibles."<<endl;
cout<<"d. Consulta de funciones por hora."<<endl;
cout<<"e. Consulta por clave de función."<<endl;
cout<<"f. Consulta de películas en las que participa un actor."<<endl;
cout<<"g. Terminar.";

cin>>opcion;

  switch(opcion){
  case'a':
  for(i = 0; i < contador; i++){
			cout << actores[i].getId() << " " << actores[i].getNombre() << endl;
	}
  break;

  case 'b':
  for(i = 0; i < totalPeliculas; i++){
			cout << peliculas[i].getnumPeli() << " " << peliculas[i].getAnio() << " " << peliculas[i].getDuracion() << " " << peliculas[i].getGenero() << " " << peliculas[i].getCantAct()<< " ";
      for(j=0; j<peliculas[i].getCantAct(); j++){
        cout << peliculas[i].getlistaActor(j) << " ";
      }
      cout << peliculas[i].getTitulo() <<  endl;
  }
  break;

  case'c':
  for(i = 0; i < cantFunciones; i++){
			cout << funciones[i].getCveFuncion() << " " << funciones[i].getNumPelicula() << " " << funciones[i].getHour().getHora() << ":"<<funciones[i].getHour().getMinutos() << " " << funciones[i].getSala(); 
      
  }
  break;

  case 'd':
  cout << "\nIngresa la hora de la funcion --> ";
			cin >> hour;
			cout << "Ingresa los minutos de la funcion --> ";
			cin >> minutos;

			if(hour < 23 && minutos < 59)
			{
        
				Hora horaFuncion(hour, minutos);
				int validarS = 0, validarT = 0;
				for(i = 0; i < cantFunciones; i++)
				{
					if(hour == funciones[i].getHour().getHora()
							&& minutos == funciones[i].getHour().getMinutos())
					{
						cout << "\nSala(s): " << funciones[i].getSala();
						validarS = 1;
						for(int j = 0; j < 20; j++)
						{
							if(peliculas[j].getnumPeli() == funciones[i].getNumPelicula())
							{
								cout << "\tTitulo: " << peliculas[j].getTitulo() << endl;
								validarT = 1;
							}
						}
					}
					if(validarS == 0)
					{
						cout << "\nNinguna sala coincide a esta hora.\n";
					}
					if(validarT == 0)
					{
						cout << "\nNingun numero ni tiutlo de pelicula coincide.\n";
					}
				}
			}

			else
			{
				cout << "\nLa hora ingresada es invalida.\n";
			}
  break;

  case'e':
  
    cout << "\nEscriba la clave de la funcion que busca\n--> ";
		cin.ignore();
		getline(cin, claveFuncion);
		

		for(i = 0; i < 20; i++)
			{
				if(claveFuncion == funciones[i].getCveFuncion())
				{
					cout << "\nSala: " << funciones[i].getSala() << " Hora: ";
					if(funciones[i].getHour().getHora() < 10)
					{
						cout << "0" << funciones[i].getHour().getHora();
					}
					else
					{
						cout << funciones[i].getHour().getHora();
					}
					if(funciones[i].getHour().getMinutos() < 10)
					{
						cout << ":0" << funciones[i].getHour().getMinutos();
					}
					else
					{
						cout << ":" << funciones[i].getHour().getMinutos();
					}
					for(int j = 0; j < 20; j++)
					{
						if(funciones[i].getNumPelicula() == peliculas[j].getnumPeli())
						{
							cout << " Titulo: " << peliculas[j].getTitulo() << " Duracion: "
								 << peliculas[j].getDuracion() << " minutos. Genero: "
								 << peliculas[j].getGenero() << ".\nActores: ";
							for(int k = 0; k < peliculas[j].getCantAct(); k++)
							{
								for(int l = 0; l < 20; l++)
								{
									if (actores[k].getId() == peliculas[j].getlistaActor(l))
									{
										cout << " -- " << actores[k].getNombre();
									}
								}
							}
						}
						validarCve = 1;
					}
					cout << endl;
				}

			}
			if(validarCve == 0)
			{
				cout << "\nLa clave ingresada es invalida.\n";
			}
  break;

  case'f':
    cout << "\nIngrese el numero de ID de un actor\n-->";
			cin >> identificacion[0];
			int validarID = 0;

			for(i = 0; i < 20; i++)
			{
				if(identificacion[0] == actores[i].getId())
				{
					cout << "\nEl actor: " << actores[i].getNombre()
						 << " ha participado en las siguientes peliculas:\n";
					for(int j = 0; j < 20; j++)
					{
						for(int k = 0; k < 10; k++)
						{
							if(actores[i].getId() == peliculas[j].getlistaActor(k))
							{
								cout << peliculas[j].getAnio() << " "
									 << peliculas[j].getTitulo() << endl;
							}
						}
					}
					validarID = 1;
				}
			}

			if(validarID == 0)
			{
				cout << "\nEl ID que ha ingresado es invalido.\n";
			}
  break; 
}
}

}
