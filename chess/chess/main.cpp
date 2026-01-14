#include "libraries.h"
#include "defines.h"
#include "joc.h"

int main() {
    inicialitzarTaulell();

    int f1, c1, f2, c2;
    while (true) {
        imprimirTaulell();

        std::cout << "\nORIGEN - Fila (1-8)  Columna (1-8) ";
        std::cin >> f1 >> c1;
        std::cout << "DESTI  - Fila (1-8) i Columna (1-8)";
        std::cin >> f2 >> c2;

        moureFitxa(TAMANYTAULELL - f1, c1 - 1, TAMANYTAULELL - f2, c2 - 1);

        std::system("cls");
    }

    return 0;
}
