#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

const int n_tablas = 6;
const int n_discos = 3;


void cargaCromo(int num, int n, int  cromo [], int base) {
    for (int i = 0; i < n; i++) cromo[i] = 0;
    int j=0;
    while (num > 0) {
        cromo [j]=num % base;
        num = num / base;
        j++;
    }
}

int calcularMin(int & discoVelMin, const int arr [], int n) {
    int minimo=INT_MAX;
    for (int i = 0; i < n; i++) {
        if (arr[i] < minimo) {
            minimo = arr[i];
            discoVelMin=i;
        }
    }
    return minimo;
}
void calcularVelocMinima(int &velocMinima, int &discoVelMin,  const int velocidadDiscos[],const int cromo[],  const int velocidadTablas[]) {
     int  auxVelocDisc [n_discos]{};
    for (int i = 0; i < n_discos; i++) {
        auxVelocDisc[i] = velocidadDiscos[i];
    }
    int discoAsignado ;
    for (int i = 0; i < n_tablas; i++) {// vamos de la tabla 0 a la tabla 5
        discoAsignado = cromo[i];// 0, 1,2
            auxVelocDisc[discoAsignado] -= velocidadTablas[i];
            // cout<<auxVelocDisc[discoAsignado]<<endl;
            if (auxVelocDisc[discoAsignado]<0) {
                velocMinima=-1;
                return;
            }
    }
   velocMinima= calcularMin(discoVelMin, auxVelocDisc, n_discos);
}

int main() {
    //opciones por tabla : 0 1 2 3  : base 3 porque sí o sí queremos que todas las tablas se asignen a los discos
    int  cromo[n_tablas]{} ;
    int opciones =(int) pow (n_discos, n_tablas);
    int velocidadTablas[n_tablas]= {150, 100, 80, 50, 120, 10};
    int velocidadDiscos[n_discos]= {250, 200, 200};
    int velocMinima=0;
    int velocMaxMinima=0;
    int mejorCromo[n_tablas]{} ;
    int discoVelMin;
    int mejorDiscoVelMin;
    for (int i = 0; i < opciones; i++) {
        cargaCromo(i, n_tablas, cromo, 3);

        calcularVelocMinima(velocMinima, discoVelMin, velocidadDiscos, cromo, velocidadTablas);
        if (velocMinima==-1) continue; // se ignora la combinación porque sobrepasa la capacidad de los discos
        if (velocMinima>velocMaxMinima) {
            velocMaxMinima=velocMinima;
            mejorDiscoVelMin=discoVelMin;
            for (int j = 0; j < n_tablas; j++) {
                mejorCromo[j] = cromo[j];
            }
        }
    }
   for (int i = 0; i < n_discos; i++) {
       cout<<"Disco "<< i+1<< " Tablas : ";
       for (int j = 0; j < n_tablas; j++) {
           if (mejorCromo[j] == i) {
               cout<<j+1<<" ";
           }
       }
       cout<<endl;
   }
    cout<<"Esta solución tiene una velocidad mínima de grupo de "<<velocMaxMinima<<" IOPs que se da en el disco : "<<mejorDiscoVelMin+1<<endl;
    return 0;

}
