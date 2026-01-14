#include "libraries.h"
#include "defines.h"
#include "joc.h"

/* DEFINICIÓ DEL TAULELL , "fitxa" es un struct que conté el color, tipus y simbol de la fitxa*/
Fitxa taulell[TAMANYTAULELL][TAMANYTAULELL];


//imprimir taulell utilitzant dos bucles for
void imprimirTaulell() {
    std::cout <<"Escacs- Pol Mates i Martin Pastor"<<std::endl;

    std::cout<<NUMEROSTABLERO; //imprimim la numeració de les files y columnes dels taulers, definits al defines.h.

    for (int f = 0; f < TAMANYTAULELL; f++) {
        std::cout << " " << TAMANYTAULELL - f ;
        for (int c = 0; c < TAMANYTAULELL; c++)
            std::cout << taulell[f][c].simbol;
       std::cout<< "\n";
    }
}

/*Funcio per a nombrar a les fitxes dels dos usuaris(fitxes al taulell en anglès com s'ha especificat a la entrega,
però amb el "nom" en català per entrendre-ho millor al programar) */

void posarFitxa(int f, int c, ColorFitxa color, TipusFitxa tipus) {
    taulell[f][c].color = color;
    taulell[f][c].tipus = tipus;


    if (tipus == TipusFitxa::BUIT) taulell[f][c].simbol = " . ";
    else if (color == ColorFitxa::BLANC) {
        if (tipus == TipusFitxa::PEO) taulell[f][c].simbol = " P ";
        else if (tipus == TipusFitxa::TORRE) taulell[f][c].simbol = " T ";
        else if (tipus == TipusFitxa::CAVALL) taulell[f][c].simbol = " H ";
        else if (tipus == TipusFitxa::ALFIL) taulell[f][c].simbol = " B ";
        else if (tipus == TipusFitxa::REINA) taulell[f][c].simbol = " Q ";
        else if (tipus == TipusFitxa::REI) taulell[f][c].simbol = " K ";
    }
    else {
        if (tipus == TipusFitxa::PEO) taulell[f][c].simbol = " p ";
        else if (tipus == TipusFitxa::TORRE) taulell[f][c].simbol = " t ";
        else if (tipus == TipusFitxa::CAVALL) taulell[f][c].simbol = " h ";
        else if (tipus == TipusFitxa::ALFIL) taulell[f][c].simbol = " b ";
        else if (tipus == TipusFitxa::REINA) taulell[f][c].simbol = " q ";
        else if (tipus == TipusFitxa::REI) taulell[f][c].simbol = " k ";
    }
}


//funció per inicialitzar el taulell, usa la funcio de posar fitxes per colocarles a la posicio correponent al taulell.

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
    posarFitxa(7, 6, ColorFitxa::BLANC, TipusFitxa::CAVALL);
    posarFitxa(0, 2, ColorFitxa::NEGRE, TipusFitxa::ALFIL);
    posarFitxa(0, 5, ColorFitxa::NEGRE, TipusFitxa::ALFIL);
    posarFitxa(7, 2, ColorFitxa::BLANC, TipusFitxa::ALFIL);
    posarFitxa(7, 5, ColorFitxa::BLANC, TipusFitxa::ALFIL);
    posarFitxa(7, 4, ColorFitxa::BLANC, TipusFitxa::REI);
    posarFitxa(7, 3, ColorFitxa::BLANC, TipusFitxa::REINA);
    posarFitxa(0, 4, ColorFitxa::NEGRE, TipusFitxa::REI);
    posarFitxa(0, 3, ColorFitxa::NEGRE, TipusFitxa::REINA);
}

/*funcio per al moviment de les fitxes, assegura que les coordenades que has passat(tant d’origen com de destí)
existeixin dins del tauler abans d’intentar moure res.*/
    void moureFitxa(int filaOrigen, int colOrigen, int filaDesti, int colDesti) {
        if (filaOrigen >= 0 && filaOrigen < TAMANYTAULELL && colOrigen >= 0 && colOrigen < TAMANYTAULELL &&
            filaDesti >= 0 && filaDesti < TAMANYTAULELL && colDesti >= 0 && colDesti < TAMANYTAULELL) {

            Fitxa f = taulell[filaOrigen][colOrigen];
            posarFitxa(filaDesti, colDesti, f.color, f.tipus);
            posarFitxa(filaOrigen, colOrigen, ColorFitxa::CAP, TipusFitxa::BUIT);
        }
    }
