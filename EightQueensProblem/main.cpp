

#include <iostream>
#define N 26
using namespace std;

void imprimirTablero( int tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

//funcion para verificar si es seguro colocar una reina en la posicion [fila][columna]
bool esSeguro(int tablero[N][N], int fila, int columna) {
    //verificamos en la vertical
    for (int k = 0; k < N; k++) {
        if (tablero[k][columna] == 1) {
            return false;
        }
    }
    //verificamos en la horizontal
    for (int k = 0; k < N; k++) {
        if (tablero[fila][k] == 1) {
            return false;
        }
    }
    //verificamos en la diagonal inferior derecha
    for (int n=fila, m=columna; n < N and m<N; n++, m++) {
        if (tablero[n][m] == 1) {
            return false;
        }
    }
    //verificamos en la diagonal inferior izquierda
    for (int n=fila, m=columna; n < N and m>=0; n++, m--) {
        if (tablero[n][m] == 1) {
            return false;
        }
    }
    //verificamos en la diagonal superior derecha
    for (int n=fila, m=columna; n >=0 and m<N; n--, m++) {
        if (tablero[n][m] == 1) {
            return false;
        }
    }
    //verificamos en la diagonal superior izquierda
    for (int n=fila, m=columna; n >=0 and m>=0 ; n--, m--) {
        if (tablero[n][m] == 1) {
            return false;
        }
    }

    return true;
}

bool solve(int (&tablero) [N][N], int fila) {
    //si ya colocamos reinas en todas las filas, hemos terminado
  if (fila>=N) {
      return true;
  }
    //probar cada columna de la fila actual
    for (int colum = 0; colum < N; colum++) {
        if (esSeguro(tablero, fila, colum)) {
            //colocar reina provisionalmente
            tablero[fila][colum] = 1;
            //llamar recursivamente para la siguiente fila
            if (solve(tablero, fila+1)) {
                return true;
            }
            //backtracking: si la jugada no lleva a una solucion se retira la reina
            tablero[fila][colum] = 0;
        }
    }
    //si ninguna columna es valida en esta fila, retorna falso para retroceder
    return false;
}

int main() {
    //considerar N >3 
    int tablero[N][N] {} ; //{} inicializa en 0s

    solve(tablero, 0);
    imprimirTablero(tablero);
    return 0;
}
