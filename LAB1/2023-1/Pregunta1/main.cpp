#include <iostream>
#include <fstream>
#include <cmath>
#include <climits>
using namespace std;

//3 camiones: 0: Ninguno         1: Cam1        2: Cam2     3: Cam3
void cargabin(int num , int n,int base, int cromosoma[]) {
    for (int i=0; i<n; i++) cromosoma[i] = 0;
    int j =0;
    while (num > 0) {
        cromosoma[j] = num % base;
        num = num / base;
        j++;
    }
}

void calculaMaxMin(int cant ,int capAux[],int &min, int &max) {
    for (int i=0; i<cant; i++) {
        if (capAux[i] < min) min = capAux[i];
        if (capAux[i] > max) max = capAux[i];
    }
}

void copiar(int NUM_CAMIONES,int *origen, int *destino) {
    for (int i=0; i<NUM_CAMIONES; i++) {
        destino[i] = origen[i];
    }
}
void solve(int *arrCamiones,int * arrPaquetes,int  NUM_CAMIONES,int  NUM_PAQUETES) {
    int opciones = pow(NUM_CAMIONES,NUM_PAQUETES);
    int min_diferencia = 9999999;
    int mejor_solucion[NUM_PAQUETES];
    bool encontrada_valida=false;

    //Fuerza bruta: evaluar todas las opciones posibles
    for (int i=0 ;i < opciones;i++) {
        int opcion_actual = i;
        int capacidades_actual[NUM_CAMIONES];
        copiar(NUM_CAMIONES,arrCamiones, capacidades_actual);

    }
}
int main() {
    //lectura de cantidad caminos y capacidades respectivas
    ifstream input;
    input.open("ArchivosDeDatos/camionesYpaquetes.txt", ios::in);
    if (!input.is_open()) {
        cout<<"Error de abrir el archivo "<<"camionesYpaquetes"<<endl;
        exit(1);
    }
    int m, n;//m camiones y n paquetes
    input>>m>>n;
    input>>ws;
    int arrCamiones[m];
    int arrPaquetes[n];
    int i=0;
    while(input.peek()!='\n') {
        input>>arrCamiones[i];
        i++;
    }
    input>>ws;
    int j=0;
    while(input.peek()!='\n') {
        input>>arrPaquetes[j];
        j++;
    }

    int mcomb, min,max, dif=9999999; 
    int base = m+1, flag =0;
    int cromosoma[n];
    int opciones = (int)pow(base, n);

    for (int i=0; i<opciones; i++) {
        flag = 0;
        min = INT_MAX;
        max = INT_MIN;
        for (int j=0; j<n; j++) {}
    }
    solve(arrCamiones, arrPaquetes, m, NUM_PAQUETES);
    return 0;
}
