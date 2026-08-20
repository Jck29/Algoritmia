#include <iostream>
using namespace std;

const int N = 6;
const int M = 11;

void imprimirMapa(char mapa[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cout << mapa[i][j] << " ";
        }
        cout << endl;
    }
}

//analisis por galeria
void resolver(int posFila, int posColum, int numGaleria, int cantGalerias, char (&mapa)[N][M]) {
    int varFila =0;
    int varColum =0;
    static bool terminado = false; // solo se ejecuta una vez
    if (terminado) return;
    bool arriba = false, derecha = false, abajo = false;

    if (numGaleria >cantGalerias) {
        terminado = true;
        return;
    }
    if (posFila <0||posFila >= N  ||  posColum<0|| posColum >=M ) {
        return;
    }

    // si nos encontramos en la última columna volvemos
    if (posColum == M-1) {
        if (  posFila < N && posColum <M && mapa[posFila][posColum] == ' ') {
            mapa[posFila][posColum] = (char)(numGaleria+'0');
        }

        resolver(posFila-1, 0, numGaleria+1, cantGalerias, mapa);

        return;
    }

    if (  posFila < N && posColum <M && mapa[posFila][posColum] == ' ') {
        mapa[posFila][posColum] = (char)(numGaleria+'0');
    }

        //decision para moverse

        //abajo
        if (posFila + 1 < N  && mapa[posFila + 1][posColum] == ' '  ) {
            abajo = true;
        } else if (posColum + 1 < M &&  mapa[posFila][posColum + 1] == ' '  ) {
            //derecha
            derecha = true;
        } else if (posFila -1 >= 0 && mapa[posFila - 1][posColum] == ' '  ) {
            arriba = true;
        }


        //abajo derecha arriba
        //abajo
        if (abajo) {

            varFila =1;
            varColum =0;
        }

        //derecha
        if (derecha) {
            varFila =0;
            varColum =1;
        }
        //arriba

        if (arriba) {
            varFila =-1;
            varColum =0;
        }

        if (abajo || derecha || arriba  ) {
            resolver(posFila+varFila, posColum+varColum, numGaleria, cantGalerias, mapa);
        } else {
            return ;
        }

}



int main() {

    char mapa[N][M] = {
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', '*', ' ', ' ', ' ', ' ', ' '},
    };
    int cantGalerias = 3;

        resolver(N-1, 0, 1, cantGalerias, mapa);


    imprimirMapa(mapa);

    return 0;
}
