#pragma once
#include "defines.h"
#include "libraries.h"


enum class ColorFitxa { BLANC, NEGRE, CAP };
enum class TipusFitxa { PEO, TORRE, CAVALL, ALFIL, REINA, REI, BUIT };

struct Fitxa {
    ColorFitxa color;
    TipusFitxa tipus;
    std::string simbol;
};

// TAULELL GLOBAL 
extern Fitxa taulell[TAMANYTAULELL][TAMANYTAULELL];

// FUNCIONS
void inicialitzarTaulell();
void imprimirTaulell();
void posarFitxa(int f, int c, ColorFitxa color, TipusFitxa tipus);
