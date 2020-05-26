#ifndef Actor_h
#define Actor_h
#include <string>
using namespace std;
class Actor{

  private:
  int id;
  string nombre;

  public:
  	Actor();
		Actor(int id, string nombre);
		
		void setId(int id);
		void setNombre(string nombre);
		
		int getId();
		string getNombre();
 

};

Actor::Actor() {
	id = 0;
	nombre = "";
}

Actor::Actor(int id, string nombre) {
	this->id = id;
	this->nombre = nombre;
}

void Actor::setId(int id) {
	this->id = id;
}

void Actor::setNombre(string nombre) {
	this->nombre = nombre;
}

int Actor::getId() {
	return id;
}

string Actor::getNombre() {
	return nombre;
}

#endif