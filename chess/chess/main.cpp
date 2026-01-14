#include "libraries.h"
#include "defines.h"
#include "joc.h"

int main() {
    inicialitzarTaulell(); //inicialitzem taulell

    int f1, c1, f2, c2; //variables de les files i columnes per l'input dels usuaris
    while (true) {
        imprimirTaulell(); //funció per imprimir taulell a pantalla


        //moviment de fitxes dels l'usuaris, input de posicions desitjades
        std::cout << "\nORIGEN - Fila (1-8)  Columna (1-8) ";
        std::cin >> f1 >> c1;
        std::cout << "DESTI  - Fila (1-8) i Columna (1-8)";
        std::cin >> f2 >> c2;

        //funció per al moviment de les fitxes
        moureFitxa(TAMANYTAULELL - f1, c1 - 1, TAMANYTAULELL - f2, c2 - 1);

        //netejar pantalla a cada jugada
        std::system("cls");
    }

    return 0;
}
