
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <vector>
using namespace std;

const double M_E = 	2.71828182845904523536; //constante "e";

double gbellmf(double x, double a, double b, double x0 ) {
	// x : variable
	// a : determina el anchob
	// b : determina la pendiente
	// x0 : fija el centro
	double y, denominator, valor_abs;
	valor_abs = fabs( (x-x0)/a );
	denominator = 1 + pow( valor_abs,2*b );
	y = 1/denominator;
	return y;
}

double gaussmf(double x, double sigma, double x0) {
	// x : variable
	// sigma : determina el ancho
	// x0 : fija el centro
	double y, exponente;
	exponente = pow(((x-x0)/sigma),2)*-1/2;
	y = pow(M_E,exponente);
	return y;
}

// x : variable
// a : determina la pendiente
// x0 : fija el punto de cruce
double sigmf(double x, double a, double x0) {
	double denominator, y;
	denominator = 1 + pow( M_E,(-a)*(x-x0) );
	y = 1/denominator;
	return y;
}

double trapmf(double x, double a, double b, double c, double d) {
	if( a<=b && b<=c && c<=d ) {
		if( x<=a || x>=d )
			return 0.0;
		else if( b<=x && x<=c )
			return 1.0;
		else if( a<=x && x<=b )
			return (x-a)/(b-a);
		else if( c<=x && x<=d )
			return (d-x)/(d-c);
	}
	else {
		cout << "error";
		system("EXIT_FAILURE");
	}
}

double trimf(double x, double a, double b, double c) {
	if( a<=b && b<=c) {
		if( x<=a || x>=c )
			return 0.0;
		else if( a<=x && x<=b )
			return (x-a)/(b-a);
		else if( b<=x && x<=c )
			return (c-x)/(c-b);
	}
	else {
		cout << "error";
		system("EXIT_FAILURE");
	}
}

class Servicio {
	double step;
	vector <double> servicio;
	vector <double> servPobre;
	vector <double> servBueno;
	vector <double> servExcelente;
public:
	Servicio(double paso) {
		this->step = paso;
	}
	// Define los elementos en el vector servicio
	void defServicio(double, double);
	// Devuelve un elemento en la posicion indicada del vector servicio
	double getServicio(int);
	// Muestra todos los valores de la variable servicio
	int sizeServicio() {
		return servicio.size();
	}
	// Define valores mediante una función gaussiana para un servicio POBRE
	void defServPobre(double);
	double getServPobre(int i) {
		return servPobre.at(i);
	}
	// Define valores mediante una función gaussiana para un servicio BUENO
	void defServBueno(double);
	double getServBueno(int i) {
		return servBueno.at(i);
	}
	// Define valores mediante una función gaussiana para un servicio EXCELENTE
	void defServExcelente(double);
	double getServExcelente(int i) {
		return servExcelente.at(i);
	}
	// Busca y devuelve la posicion de un elemento
	int buscarS(double);

	vector <double> V_SERVICIO() {
		return servicio;
	}
	vector <double> V_SERVICIO_POBRE() {
		return servPobre;
	}
	vector <double> V_SERVICIO_BUENO() {
		return servBueno;
	}
	vector <double> V_SERVICIO_EXCELENTE() {
		return servExcelente;
	}

};
int Servicio::buscarS(double e) {
	int pos = 0;
	if( e>=9.6 || e<=2.2 )
		pos++;
	for(float i=0; i<=e; i=i+step) {	//OJO: error logico
		pos++;
	}
	return pos;
}

void Servicio::defServicio(double a, double b) {
	for( double i=a; i<=b; i=i+step ) {
		servicio.push_back(i);
	}
}

double Servicio::getServicio(int i) {
	return servicio.at(i);
}
void Servicio::defServPobre(double valor) {
	servPobre.push_back(valor);
}

void Servicio::defServBueno(double valor) {
	servBueno.push_back(valor);
}

void Servicio::defServExcelente(double valor) {
	servExcelente.push_back(valor);
}
class Comida {
	double step;
	vector <double> comida;
	vector <double> comidaRancia;
	vector <double> comidaDeliciosa;
public:
	Comida(double paso) {
		this->step = paso;
	}
	// Define los elementos en el vector comida
	void defComida(double, double);
	// Devuelve un elemento en la posicion indicada del vector comida
	double getComida(int);
	// Muestra todos los valores de la variable comida
	void showComida();
	// Retorna el tamaño del vector comida
	int sizeComida() {
		return comida.size();
	}
	// Define valores mediante una función trapezoidal para una comida RANCIA
	void defComidaRancia(double);
	double getComidaRancia(int i) {
		return comidaRancia.at(i);
	}
	// Define valores mediante una función gaussiana para una comida DELICIOSA
	void defComidaDeliciosa(double);
	double getComidaDeliciosa(int i) {
		return comidaDeliciosa.at(i);
	}
	int buscarC(double);

	vector <double> V_COMIDA() {
		return comida;
	}
	vector <double> V_COMIDA_RANCIA() {
		return comidaRancia;
	}
	vector <double> V_COMIDA_DELICIOSA() {
		return comidaDeliciosa;
	}
};

int Comida::buscarC(double elemento) {
	int posicion = 0;
	if( elemento>=9.6 || elemento<=2.2)
		posicion++;
	for(float i=0.0; i<=elemento; i=i+step) {
		posicion++;
	}
	return posicion;
}
void Comida::defComida(double a, double b) {
	for( double i=a; i<=b; i=i+step ) {
		comida.push_back(i);
	}
}

double Comida::getComida(int i) {
	return comida.at(i);
}
void Comida::defComidaRancia(double valor) {
	comidaRancia.push_back(valor);
}

void Comida::defComidaDeliciosa(double valor) {
	comidaDeliciosa.push_back(valor);
}

class Tip {
	double step;
	vector <double> tip;
	vector <double> tipBaja;
	vector <double> tipPromedio;
	vector <double> tipGenerosa;
public:
	Tip(double paso) {
		this->step = paso;
	}
	// Define los elementos en el vector comida
	void defTip(double, double);
	// Devuelve un elemento en la posicion indicada del vector comida
	double getTip(int);
	// Muestra todos los valores de la variable comida
	void showTip();
	// Retorna el tamaño del vector comida
	int sizeTip() {
		return tip.size();
	}
	// Define valores mediante una función triangular para una propina BAJA
	void defTipBaja(double);
	// Define valores mediante una función triangular para una propina PROMEDIO
	void defTipPromedio(double);
	// Define valores mediante una función triangular para una propina GENEROSA
	void defTipGenerosa(double);

	vector <double> VECTOR_TIP() {
		return tip;
	}
	vector <double> VECTOR_TIP_BAJA() {
		return tipBaja;
	}
	vector <double> VECTOR_TIP_PROMEDIO() {
		return tipPromedio;
	}
	vector <double> VECTOR_TIP_GENEROSA() {
		return tipGenerosa;
	}

};
void Tip::defTip(double a, double b) {
	for( double i=a; i<=b+step; i=i+step ) {	//OJO: error lógico, no genera el número adecuado
		tip.push_back(i);
	}
}

double Tip::getTip(int i) {
	return tip.at(i);
}
void Tip::defTipBaja(double valor) {
	tipBaja.push_back(valor);
}

void Tip::defTipPromedio(double valor) {
	tipPromedio.push_back(valor);
}

void Tip::defTipGenerosa(double valor) {
	tipGenerosa.push_back(valor);
}

//////////////////////////////////////////
/////////////////////////////////////////

vector <double> min(vector<double> &V, double v) {
	vector <double> aux;
	double minimo;
	auto it = V.begin();

	for(; it != V.end(); it++ ) {
		if( *it <= v )
			minimo = *it;
		else
			minimo = v;
		aux.push_back(minimo);
	}
	return aux;
}


vector <double> max(vector<double> &V1, vector <double> &V2) {
	vector <double> aux;
	double maximo;

	auto it1 = V1.begin();
	auto it2 = V2.begin();

	for(; it1 != V1.end(); it1++, it2++ ) {
		if( (*it1) >= (*it2) )
			maximo = *it1;
		else
			maximo = *it2;
		aux.push_back(maximo);
	}
	return aux;
}

// Por el método de la centroide
double defuzz(vector<double> &y, vector<double> &mu) {
	double sumatoria1(0), sumatoria2(0), y0;

	for(int i=0; i<mu.size(); i++)
		sumatoria1 += y.at(i)*mu.at(i);

	for(int i=0; i<mu.size(); i++)
		sumatoria2 += mu.at(i);

	y0 = sumatoria1/sumatoria2;
	return y0;
}

double noDifuso(double service, double food);

int main(int argc, char *argv[]) {
	// FUSIFICACION

	// Paso que va dar  de número a número para generar los valores
	double step = 0.1;

	double service, pobre, bueno, excelente;
	Servicio SERVICIO(step);
	SERVICIO.defServicio(0,10);
	for(int i=0; i<SERVICIO.sizeServicio(); i++) {
		service = SERVICIO.getServicio(i);
		pobre = gaussmf( service, 1.5, 0 );
		bueno = gaussmf( service, 1.5, 5 );
		excelente = gaussmf( service, 1.5, 10);
		SERVICIO.defServPobre(pobre);
		SERVICIO.defServBueno(bueno);
		SERVICIO.defServExcelente(excelente);
	}

	double food, rancia, deliciosa;
	Comida COMIDA(step);
	COMIDA.defComida(0,10);
	for(int i=0; i<COMIDA.sizeComida(); i++) {
		food = COMIDA.getComida(i);
		rancia = trapmf( food, -2, 0, 1, 3 );
		deliciosa = trapmf( food, 7, 9, 10, 12 );
		COMIDA.defComidaRancia(rancia);
		COMIDA.defComidaDeliciosa(deliciosa);
	}

	double tip, baja, promedio, generosa;
	Tip TIP(step);
	TIP.defTip(0,30);
	for(int i=0; i<TIP.sizeTip(); i++) {
		tip = TIP.getTip(i);
		baja = trimf( tip, 0, 5, 10);
		promedio = trimf( tip, 10, 15, 20);
		generosa = trimf( tip, 20, 25, 30);
		TIP.defTipBaja(baja);
		TIP.defTipPromedio(promedio);
		TIP.defTipGenerosa(generosa);
	}
//	double serv_input(4.2), com_input(9.2);
	double serv_input, com_input;
	cout << "Ingrese la calidad del servicio (0/10): ";
	cin >> serv_input;

	cout << "Ingrese la calidad de la comida (0/10): ";
	cin >> com_input;

	int n1, n2;
	n1 = SERVICIO.buscarS(serv_input);
	n2 = COMIDA.buscarC(com_input);

	// PROCESO DE INFERENCIA
	vector <double> VTB = TIP.VECTOR_TIP_BAJA();
	vector <double> VTP = TIP.VECTOR_TIP_PROMEDIO();
	vector <double> VTG = TIP.VECTOR_TIP_GENEROSA();

	vector <double> B1A, B1B, B3A, B3B, Bp;
	vector <double> B, B1, B2, B3;

	B1A = min(VTB, SERVICIO.getServPobre(n1));
	B1B = min(VTB, COMIDA.getComidaRancia(n2));
	B1 = max( B1A, B1B );

	B2 = min( VTP, SERVICIO.getServBueno(n1));

	B3A = min(VTG, SERVICIO.getServExcelente(n1));
	B3B = min(VTG, COMIDA.getComidaDeliciosa(n2));
	B3 = max( B3A, B3B );

	B = max(B2,B3);
	Bp = max(B1,B);
	/*
	cout.precision(4);
	cout << fixed;
	auto it = Bp.begin();
	int contador = 0;
	int stop = 30;
	for(;it!=Bp.end(); it++) {
		cout << *it << endl;
		if( contador == stop ) {
			cin.get();
			stop += 30;
		}
		contador++;
	}
	cout << endl << "size(Bp): " << Bp.size();
	*/

	// DESFUZZIFICACIÓN
	double tip_final;
	vector <double> VT = TIP.VECTOR_TIP();
	tip_final = defuzz(VT, B);

	cout.precision(4);
	cout << fixed;
	cout << "\n[FuzzyLogic] el porcentaje de propina es " << tip_final << "%" << endl;
	cout << "\n[Enfoque no difuso] el porcentaje de propina es " << noDifuso(serv_input, com_input) << "%";

	return 0;
}

double noDifuso(double service, double food) {
	double servRatio = 0.8;
	double tip;

	if( service<3 )
		tip = ((0.10/3)*service+0.05)*servRatio + (1-servRatio)*(0.20/10*food+0.05);
	else if ( service<7 )
		tip = (0.15)*servRatio + (1-servRatio)*(0.20/10*food+0.05);
	else
		tip = ((0.10/3)*(service-7)+0.15)*servRatio+(1-servRatio)*(0.20/10*food+0.05);

	return tip*100;
}
