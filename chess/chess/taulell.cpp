#include "libraries.h"
#include "defines.h"
#include "taulell.h"

#include "taulell.h"
#include <iostream>

/* DEFINICIÓ DEL TAULELL */
Fitxa taulell[TAMANYTAULELL][TAMANYTAULELL];

void imprimirTaulell() {
    std::cout << "\n   a  b  c  d  e  f  g  h\n";
    for (int f = 0; f < TAMANYTAULELL; f++) {
        std::cout << TAMANYTAULELL - f << " ";
        for (int c = 0; c < TAMANYTAULELL; c++)
            std::cout << taulell[f][c].simbol;
        std::cout << " " << TAMANYTAULELL - f << "\n";
    }
    std::cout << "   a  b  c  d  e  f  g  h\n";
}


void posarFitxa(int f, int c, ColorFitxa color, TipusFitxa tipus) {
    taulell[f][c].color = color;
    taulell[f][c].tipus = tipus;

    if (tipus == TipusFitxa::BUIT) taulell[f][c].simbol = " . ";
    else if (color == ColorFitxa::BLANC) {
        if (tipus == TipusFitxa::PEO) taulell[f][c].simbol = " P ";
        else if (tipus == TipusFitxa::TORRE) taulell[f][c].simbol = " T ";
        else if (tipus == TipusFitxa::CAVALL) taulell[f][c].simbol = " C ";
        else if (tipus == TipusFitxa::ALFIL) taulell[f][c].simbol = " A ";
        else if (tipus == TipusFitxa::REINA) taulell[f][c].simbol = " Q ";
        else if (tipus == TipusFitxa::REI) taulell[f][c].simbol = " R ";
    }
    else {
        if (tipus == TipusFitxa::PEO) taulell[f][c].simbol = " p ";
        else if (tipus == TipusFitxa::TORRE) taulell[f][c].simbol = " t ";
        else if (tipus == TipusFitxa::CAVALL) taulell[f][c].simbol = " c ";
        else if (tipus == TipusFitxa::ALFIL) taulell[f][c].simbol = " a ";
        else if (tipus == TipusFitxa::REINA) taulell[f][c].simbol = " q ";
        else if (tipus == TipusFitxa::REI) taulell[f][c].simbol = " r ";
    }
}

void inicialitzarTaulell() {
    for (int f = 0; f < TAMANYTAULELL; f++)
        for (int c = 0; c < TAMANYTAULELL; c++)
            posarFitxa(f, c, ColorFitxa::CAP, TipusFitxa::BUIT);

    for (int c = 0; c < TAMANYTAULELL; c++) {
        posarFitxa(1, c, ColorFitxa::NEGRE, TipusFitxa::PEO);
        posarFitxa(6, c, ColorFitxa::BLANC, TipusFitxa::PEO);
    }

    posarFitxa(0, 0, ColorFitxa::NEGRE, TipusFitxa::TORRE);
    posarFitxa(0, 7, ColorFitxa::NEGRE, TipusFitxa::TORRE);
    posarFitxa(7, 0, ColorFitxa::BLANC, TipusFitxa::TORRE);
    posarFitxa(7, 7, ColorFitxa::BLANC, TipusFitxa::TORRE);

    posarFitxa(0, 1, ColorFitxa::NEGRE, TipusFitxa::CAVALL);
    posarFitxa(0, 6, ColorFitxa::NEGRE, TipusFitxa::CAVALL);
    posarFitxa(7, 1, ColorFitxa::BLANC, TipusFitxa::CAVALL);

}