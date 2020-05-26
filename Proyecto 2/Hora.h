#ifndef Hora_h
#define Hora_h
using namespace std;
class Hora{

  private:
  int hh;
  int mm;

  public:
  Hora();
		Hora(int hora, int minutos);
		
		void setHora(int hora);
		void setMinutos(int minutos);
		
		int getHora();
		int getMinutos();
  
};

Hora::Hora() {
	hh = 0;
	mm = 0;
}

Hora::Hora(int hora, int minutos) {
	hh = hora;
	mm = minutos;
}

void Hora::setHora(int hora) {
	hh = hora;
}

void Hora::setMinutos(int minutos) {
	mm = minutos;
}

int Hora::getHora() {
	return hh;
}

int Hora::getMinutos() {
	return mm;
}

#endif