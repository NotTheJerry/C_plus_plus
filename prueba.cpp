#include <iostream>

using namespace std;

class Figura {
	protected:
		int x, y;
	public:
		virtual float calcularArea() = 0;
        void asignarCoordenadas( int x, int y );
		void dibujar();
};

void Figura::asignarCoordenadas( int x, int y ){
    this->x = x;
    this->y = y;
}

void Figura::dibujar() {
	cout<<"Las coordenadas en 'X' son: "<<x<<" y las coordenadas en 'Y' son: "<<y;
}

class Circulo : public Figura {
	private:
		float radio, pi = 3.1416;
	public:
		float calcularArea(){
			return ( pi * (radio * radio) );
		}
};

class Triangulo : public Figura {
	private:
		float base, altura;
	public:
		float calcularArea (){
			return ( (base * altura) / 2 );
		}
};

class Cuadro : public Figura {
	private:
		float lado;
	public:
		float calcularArea() {
			return (lado * lado);
		}
};

int main() {
	Circulo circulo1;
	circulo1.asignarCoordenadas(2,4);
    circulo1.dibujar();
	
	return 0;
}

