

#include <iostream>
#define N 4
using namespace std;

void imprimirTablero( int tablero[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}
void solve(int (&tablero) [N][N]) {
    bool valido;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            //pasa por cada casilla
            valido=true;
            //buscamos en la fila
            for (int k = 0; k < N; k++) {
                if (tablero[i][k] == 1) {
                    valido=false;
                }
            }
            //buscamos en la columna
            for (int k = 0; k < N; k++) {
                if (tablero[k][j] == 1) {
                    valido=false;
                }
            }
            //buscamos en la diagonal_1
            for (int n=i, m=j; n < N and m<N; n++, m++) {
                if (tablero[n][m] == 1) {
                    valido=false;
                }
            }
            //buscamos en la diagonal_2
            for (int n=i, m=j; n >=0 and m>=0; n--, m--) {
                if (tablero[n][m] == 1) {
                    valido=false;
                }
            }
            //buscamos en la diagonal_3
            for (int n=i, m=j; n >=0 and m<N; n--, m++) {
                if (tablero[n][m] == 1) {
                    valido=false;
                }
            }
            //buscamos en la diagonal_4
            for (int n=i, m=j; n <N and m>=0; n++, m--) {
                if (tablero[n][m] == 1) {
                    valido=false;
                }
            }
            if (valido) {
                tablero[i][j] = 1;
            }
        }
    }
}
int contarReynas(int tablero[N][N]) {
    int cantidad=0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (tablero[i][j] == 1) {
                cantidad++;
            }
        }
    }
    return cantidad;
}
int main() {
    int tablero[N][N] {} ; //{} inicializa en 0s

    bool valido=false;
    for (int i = 0; i < N; i++) {
        if (valido) {
            break;
        }
        for (int j = 0; j < N; j++) {
            tablero[i][j] = 1;
            solve(tablero);
            if (contarReynas(tablero)==N) {
                valido=true;
                break;
            }
            for (int k = 0; k < N; k++) {
                for (int m = 0; m < N; m++) {
                    tablero[k][m] = 0;
                }
            }
        }
    }
    imprimirTablero(tablero);
    return 0;
}
