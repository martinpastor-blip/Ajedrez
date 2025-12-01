#include "libraries.h"
#include "defines.h"

char taulell[TAMANYTAULELL][TAMANYTAULELL];

void generarTaulell() {
    for (int fila = 0; fila < TAMANYTAULELL; fila++) {
        for (int col = 0; col < TAMANYTAULELL; col++)
        {
            taulell[fila][col] = '~';
            std::cout << taulell[fila][col] << ' ';
        }
        std::cout << "\n";
    }
}
