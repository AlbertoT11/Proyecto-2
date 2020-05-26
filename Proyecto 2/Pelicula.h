#ifndef Pelicula_h
#define Pelicula_h
#include <iostream>
#include <string>
#include "Actor.h"
using namespace std;

class Pelicula{

  private:
  int numPeli;
  int anio;
  int duracion;
  //Almacena cant actores q hay en el arreglo
  int cantActores;
  string titulo;
  string genero;
  //arreglo de 10 elementos, actores principales
  int listaActores[10];
  int i;
  
  public:
 
 //Constructor defaul que inicialice la pelicula con la lista de actores vacia y valores default para los demas atributos

    Pelicula(); //Constructor
    Pelicula(int numPeli, int anio, int duracion, int cantActores, string titulo, string genero);
    void set_numPeli(int numPeli);
    int getnumPeli();
    void set_titulo(string titulo);
    string getTitulo();
    void set_anio (int anio);
    int getAnio();
    void set_duracion(int duracion);
    int getDuracion();
    void set_genero(string genero);
    string getGenero();
    int getlistaActor(int i);
    void addActor(int id);
    int getCantAct();
   
    

    
};

//o El atributo cantidadActores debe tener solamente método de acceso, porque no es posible modificar la cantidad de actores directamente.


  Pelicula::Pelicula(){
   numPeli = 0;
   anio = 0;
   duracion = 0;
   cantActores = 0;
   titulo = 'a';
   genero = 'a';
   for(i=0; i<10; i++) {
		listaActores[i] = 0;
	  }
  }

  Pelicula::Pelicula(int numPeli, int anio, int duracion, int cantActores, string titulo, string genero){
    this->numPeli = numPeli;
    this->anio = anio;
    this->duracion = duracion;
    this->cantActores = cantActores;
    this->titulo = titulo;
    this->genero = genero;
  }

 //Metodos de acceso y modificacion para sus atributos numPeli, titulo, anio, duracion, genero

 void Pelicula::set_numPeli(int numPeli){
   this->numPeli = numPeli;
 }

 int Pelicula::getCantAct(){
   return cantActores;
 }

 int Pelicula::getnumPeli(){
   return numPeli;
}

void Pelicula::set_titulo(string titulo){
   this->titulo = titulo;
 }

 string Pelicula::getTitulo(){
   return titulo;
}

 void Pelicula::set_anio (int anio){
   this->anio = anio;
 }

 int Pelicula::getAnio(){
   return anio;
}

 void Pelicula::set_duracion(int duracion){
   this->duracion = duracion;
 }

 int Pelicula::getDuracion(){
   return duracion;
}

 void Pelicula::set_genero(string genero){
   this->genero = genero;
 }

 string Pelicula::getGenero(){
   return genero;
}

 //o Método de acceso para el atributo listaActores. Debe recibir como parámetro un entero. Este entero corresponderá al subíndice del arreglo de listaActores que se quiere accesar.

int Pelicula::getlistaActor(int i){
   return listaActores[i];
 }

//o Debe haber un método para agregar un actor a la lista de actores, este método debe recibir como parámetro el objeto Actor que se va a agregar y el método debe agregarlo al arreglo listaActores y ajustar el atributo cantidadActores. Es necesario que este método tenga como valor de retorno un valor booleano que indique si se pudo agregar o no el actor a la película, no se podrá agregar si se duplica o si el arreglo ya tiene los 10 actores.


void Pelicula::addActor(int id) {
	int disponible = 0, duplicado = 0;
	for(i=0; i<10; i++) {
		if(listaActores[i] == 0) {
			disponible++;
		}
		if(listaActores[i] == id) {
			duplicado++;
		}
	}
	if(disponible != 0 && duplicado == 0) {
		listaActores[10-disponible] = id;
	}
	cantActores = 11-disponible;
}



#endif