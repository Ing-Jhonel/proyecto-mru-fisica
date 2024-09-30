#include <iostream>
#include <cmath>
using namespace std;

struct Datos{
	string x;
	double a, ti, tf, di, df, vi, vf, r;
};

void deltas(Datos a[], int i, double &t, double &d){
	
	t = a[i].tf - a[i].ti;
	d = a[i].df - a[i].di;
}
int main(){
	
	int totalAlmacenimiento=100;
	Datos datos[totalAlmacenimiento];
	char hallar;
	int i=0;
	double t=0, d=0, v=0;
	do{
	
	cout << "1. Calculadora" << endl << endl
		 << "Indique que quiere hallar: " << endl << endl
		 << "A) Aceleracion" << endl
		 << "B) Tiempo" << endl
		 << "C) Distancia" << endl
		 << "D) Velocidad Inicial" << endl
		 << "E) Velocidad Final" << endl
		 << "F) Salir "<< endl << endl;
	cin >> hallar;
	system("cls");
	
	switch(hallar){
		case 'A': //no se sabe la acelaracion
			cout << "Indique los datos disponibles: "<< endl << endl;
			cout << "Tiempo Inicial: ";
			cin >> datos[i].ti;
			cout << "Tiempo Final: ";
			cin >> datos[i].tf;
			cout << "Distancia Inicial: ";
			cin >> datos[i].di;
			cout << "Distancia Final: ";
			cin >> datos[i].df;
			cout << "Velocidad Inicial: ";
			cin >> datos[i].vi;
			cout << "Velocidad Final: ";
			cin >> datos[i].vf;
			
			deltas(datos, i, t, d);
			
			if(t==0){
				t=(2*d)/(datos[i].vf+datos[i].vi);
			}
			/*f(d==0){
				cout << "Datos insuficientes. ERROR: Distancia igual a 0";
				break;
			}*/
			if(datos[i].vf==0){
				datos[i].r=2*(d-datos[i].vi*t)/(t*t);
			} else {
				datos[i].r=(datos[i].vf-datos[i].vi)/t;
			}
			cout << "La aceleracion es: " << datos[i].r;
			break;
		case 'B': //no se sabe el tiempo
			cout << "Indique los datos disponibles: "<< endl << endl;
			cout << "Aceleracion: ";
			cin >> datos[i].a;
			cout << "Distancia Inicial: ";
			cin >> datos[i].di;
			cout << "Distancia Final: ";
			cin >> datos[i].df;
			cout << "Velocidad Inicial: ";
			cin >> datos[i].vi;
			cout << "Velocidad Final: ";
			cin >> datos[i].vf;
			
			deltas(datos, i, t, d);
			
			if(datos[i].a==0){
				datos[i].r=(2*d)/(datos[i].vf+datos[i].vi);
			} else{
				datos[i].r=(datos[i].vf-datos[i].vi)/datos[i].a;
			}
			cout << "El tiempo es: " << datos[i].r;
			break; 
		case 'C'://no se sabe la distancia
			cout << "Indique los datos disponibles: "<< endl << endl;
			cout << "Aceleracion: ";
			cin >> datos[i].a;
			cout << "Tiempo Inicial: ";
			cin >> datos[i].ti;
			cout << "Tiempo Final: ";
			cin >> datos[i].tf;
			cout << "Velocidad Inicial: ";
			cin >> datos[i].vi;
			cout << "Velocidad Final: ";
			cin >> datos[i].vf;
			
			deltas(datos, i, t, d);
			
			if(t==0 && datos[i].a!=0){
				datos[i].r=(datos[i].vf*datos[i].vf-datos[i].vi*datos[i].vi)/2*datos[i].a;
			}
			
			if(datos[i].vf==0){
				datos[i].r=datos[i].vi*t+(datos[i].a*t*t)/2;
			}
			cout << "La distancia es: " << datos[i].r;
			break;
		case 'D': //no se sabe la velocidad inicial
			cout << "Indique los datos disponibles: "<< endl << endl;
			cout << "Aceleracion: ";
			cin >> datos[i].a;
			cout << "Tiempo Inicial: ";
			cin >> datos[i].ti;
			cout << "Tiempo Final: ";
			cin >> datos[i].tf;
			cout << "Distancia Inicial: ";
			cin >> datos[i].di;
			cout << "Distancia Final: ";
			cin >> datos[i].df;
			cout << "Velocidad Final: ";
			cin >> datos[i].vf;
			
			deltas(datos, i, t, d);
			
			if(t==0){
				datos[i].r=sqrt(datos[i].vf*datos[i].vf-2*datos[i].a*d);
			}
			if(d==0){
				datos[i].r=datos[i].vf-datos[i].a*t;
			}
			if(datos[i].vf==0){
				datos[i].r=(2*d-datos[i].a*t*t)/2*t;
			}
			cout << "La velocidad inicial es: " << datos[i].r;
			break;
		case 'E': //no se sabe la velocidad final
			cout << "Indique los datos disponibles: "<< endl << endl;
			cout << "Aceleracion: ";
			cin >> datos[i].a;
			cout << "Tiempo Inicial: ";
			cin >> datos[i].ti;
			cout << "Tiempo Final: ";
			cin >> datos[i].tf;
			cout << "Distancia Inicial: ";
			cin >> datos[i].di;
			cout << "Distancia Final: ";
			cin >> datos[i].df;
			cout << "Velocidad Inicial: ";
			cin >> datos[i].vf;
			
			deltas(datos, i, t, d);
			
			if(t==0){
				datos[i].r=sqrt(datos[i].vi*datos[i].vi+2*datos[i].a*d);
			}
			if(d==0){
				datos[i].r=datos[i].vi+datos[i].a*t;
			}
			cout << "La velocidad final es: " << datos[i].r;
			break;
		case 'F':
			cout << "Saliendo del programa...";
			break;
		default:
			cout << "No valido."; 
			break;
	}
	cout << endl << endl;
	i++;
	system("pause");
	system("cls");
	}while(hallar!='F');
	return 0;
}
