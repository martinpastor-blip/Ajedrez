#pragma once
#include "defines.h"
#include "libraries.h"

//DEFINICIO ENUMS per millor legibilitat de les peçes al codi
enum class ColorFitxa { BLANC, NEGRE, CAP };
enum class TipusFitxa { PEO, TORRE, CAVALL, ALFIL, REINA, REI, BUIT };


struct Fitxa {
    ColorFitxa color;
    TipusFitxa tipus;
    std::string simbol;
};

// TAULELL GLOBAL 
extern Fitxa taulell[TAMANYTAULELL][TAMANYTAULELL];

// Definició funcions de imprimir taulell, posar moviments i colocació de fitxes.
void imprimirTaulell();
void posarFitxa(int f, int c, ColorFitxa color, TipusFitxa tipus);
void moureFitxa(int filaOrigen, int colOrigen, int filaDesti, int colDesti);
void inicialitzarTaulell();
