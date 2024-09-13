//
// Created by SLP-SUMHS on 2021/10/27.
//

#include "gem.h"

std::initializer_list<Gem> Gems = { Gem::vert, Gem::rouge, Gem::bleu,Gem::blanc, Gem::noir};

string toString(Gem g) {
    switch (g) {
        case Gem::vert: return "VERT";
        case Gem::rouge: return "ROUGE";
        case Gem::bleu: return "BLEU";
        case Gem::blanc: return "BLANC";
        case Gem::noir: return "NOIR";
        default: throw SplendorException("Couleur inconnue");
    }
}

std::ostream& operator<<(std::ostream& f, Gem g) { f << toString(g); return f; }
void printGems(std::ostream& f) {
    for (auto g : Gems) f << g << " ";
    f << "\n";
}


void JoueurGems::ajouter(int v, int r, int bbleu, int bblanc, int n, int d) {
    vert = vert + v;
    rouge = rouge + r;
    bleu = bleu + bbleu;
    blanc = blanc + bblanc;
    noir = noir + n;
    dore = dore + d;
}

void JoueurGems::retirer(int v, int r, int bbleu, int bblanc, int n, int d) {




    vert = vert - v;
    rouge = rouge - r;
    bleu = bleu - bbleu;
    blanc = blanc - bblanc;
    noir = noir - n;
    dore = dore - d;
}

void PlateauGem::ajouter(int v, int r, int bbleu, int bblanc, int n, int d) {
    vert = vert + v;
    rouge = rouge + r;
    bleu = bleu + bbleu;
    blanc = blanc + bblanc;
    noir = noir + n;
    dore = dore + d;
}

void PlateauGem::retirer(int v, int r, int bbleu, int bblanc, int n, int d) {
    vert = vert - v;
    rouge = rouge - r;
    bleu = bleu - bbleu;
    blanc = blanc - bblanc;
    noir = noir - n;
    dore = dore - d;
}