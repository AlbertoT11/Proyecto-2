#ifndef Funcion_h
#define Funcion_h
#include "Hora.h"
#include <string>
using namespace std;
class Funcion{

  private:
  string cveFuncion;
  int numPeli;
  int sala;
  Hora hora;

  public:
    Funcion();
		Funcion(string cveFuncion, int numPeli, Hora hh, int sala);
		
		void setCveFuncion(string cveFuncion);
		void setNumPelicula(int numPeli);
		void setHour(Hora hh);
		void setSala(int sala);
		
		string getCveFuncion();
		int getNumPelicula();
		Hora getHour();
		int getSala();
 
};

Funcion::Funcion() {
	cveFuncion = "";
	numPeli = 0;
	sala = 0;
	Hora hh(0,0);
	hora = hh;
}

Funcion::Funcion(string cveFuncion, int numPeli, Hora hh, int sala) {
	this->cveFuncion = cveFuncion;
	this->numPeli = numPeli;
	hora = hh;
	this->sala = sala;
}

void Funcion::setCveFuncion(string cveFuncion) {
	this->cveFuncion = cveFuncion;
}

void Funcion::setNumPelicula(int numPeli) {
	this->numPeli = numPeli;
}

void Funcion::setHour(Hora hh) {
	hora = hh;
}

void Funcion::setSala(int sala ) {
	this->sala = sala;
}

string Funcion::getCveFuncion() {
	return cveFuncion;
}

int Funcion::getNumPelicula() {
	return numPeli;
}

Hora Funcion::getHour() {
	return hora;
}

int Funcion::getSala() {
	return sala;
}

#endif