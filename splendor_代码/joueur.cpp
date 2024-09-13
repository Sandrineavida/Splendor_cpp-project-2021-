//
// Created by SLP-SUMHS on 2021/10/27.
//

#include "joueur.h"

void Joueur::ajouter_CarteDeveloppee(const CarteDeveloppee &C_D) {
    if (nb_D == nbMax_D) {
         CarteDeveloppee* newtab = new  CarteDeveloppee[(nbMax_D + 1) * 2];
        for (size_t i = 0; i < nb_D; i++) newtab[i] = cart_developee[i];
        auto old = cart_developee;
        cart_developee = newtab;
        nbMax_D = (nbMax_D + 1) * 2;
        delete[] old;
    }
    cart_developee[nb_D++] = C_D;
    prestige += C_D.getPrestige();
}

void Joueur::ajouter_CarteNobiliaire(const CarteNobiliaire &C_N) {
    if (nb_N == nbMax_N) {
         CarteNobiliaire* newtab_N = new  CarteNobiliaire[(nbMax_N + 1) * 2];
        for (size_t i = 0; i < nb_N; i++) newtab_N[i] = cart_nobiliaire[i];
        auto old = cart_nobiliaire;
        cart_nobiliaire = newtab_N;
        nbMax_N = (nbMax_N + 1) * 2;
        delete[] old;
    }
    cart_nobiliaire[nb_N++] = C_N;
    prestige += C_N.getPrestige();
}

void Joueur::ajouter_CarteDeveloppee_loue(const CarteDeveloppee &C_Y) {

        nb_Y++;
         CarteDeveloppee* newtab = new  CarteDeveloppee[nb_Y];
        for (size_t i = 0; i < (nb_Y-1); i++) newtab[i] = cart_developee_loue[i];
        auto old = cart_developee_loue;
        cart_developee_loue = newtab;
        delete[] old;
        cart_developee_loue[nb_Y-1] = C_Y;


}

void Joueur::acheter_CarteDeveloppee_loue(  CarteDeveloppee &C_Y,int p) {
    if (nb_D == nbMax_D) {
         CarteDeveloppee* newtab = new  CarteDeveloppee[(nbMax_D + 1) * 2];
        for (size_t i = 0; i < nb_D; i++) newtab[i] = cart_developee[i];
        auto old = cart_developee;
        cart_developee = newtab;
        nbMax_D = (nbMax_D + 1) * 2;
        delete[] old;
    }


    cart_developee[nb_D++] = C_Y;


    prestige += C_Y.getPrestige();
    size_t i = p;

    while (i < nb_Y) {
        if(i != (nb_Y-1))
        {
            cart_developee_loue[i] = cart_developee_loue[i+1];
        }
        else
            cart_developee_loue[i] = 0;
        i++;
    }
    nb_Y--;
}

void Joueur::ajouter_Gem(int v,int r,int bbleu,int bblanc,int n ,int d) {
    joueur_gem.ajouter(v, r, bbleu, bblanc, n, d);
}

void Joueur::retirer_Gem(int v, int r, int bbleu, int bblanc, int n, int d) {

    joueur_gem.retirer(v, r, bbleu, bblanc, n, d);
}

int Joueur::get_Develope_Gem_W() const {
    int i = 0;
    for(int dnb=0;dnb <nb_D;dnb++)
    {
        if(this->cart_developee[dnb].getBonus() == 'W')
            i++;
    }
    return i;
}

int Joueur::get_Develope_Gem_U() const {
    int i = 0;
    for(int dnb=0;dnb <nb_D;dnb++)
    {
        if(this->cart_developee[dnb].getBonus() == 'U')
            i++;
    }
    return i;
}
int Joueur::get_Develope_Gem_G() const {
    int i = 0;
    for(int dnb=0;dnb <nb_D;dnb++)
    {
        if(this->cart_developee[dnb].getBonus() == 'G')
            i++;
    }
    return i;
}
int Joueur::get_Develope_Gem_R() const {
    int i = 0;
    for(int dnb=0;dnb <nb_D;dnb++)
    {
        if(this->cart_developee[dnb].getBonus() == 'R')
            i++;
    }
    return i;
}
int Joueur::get_Develope_Gem_B() const {
    int i = 0;
    for(int dnb=0;dnb <nb_D;dnb++)
    {
        if(this->cart_developee[dnb].getBonus() == 'B')
            i++;
    }
    return i;
}


bool Joueur::isaffordable(CarteDeveloppee& cd) {
    int doit_dore = 0;
    if(joueur_gem.getblanc()+get_Develope_Gem_W() >= cd.getblanc() &&
       joueur_gem.getnoir()+get_Develope_Gem_B()  >= cd.getnoir() &&
       joueur_gem.getbleu()+get_Develope_Gem_U()  >= cd.getBleu() &&
       joueur_gem.getrouge()+get_Develope_Gem_R() >= cd.getRouge() &&
       joueur_gem.getvert()+get_Develope_Gem_G()  >= cd.getVert())
    {return true;}
    else
    {
        if((joueur_gem.getblanc()+get_Develope_Gem_W()-cd.getblanc())<0)
        {doit_dore = doit_dore - (joueur_gem.getblanc()+get_Develope_Gem_W()-cd.getblanc()) ;}
        if((joueur_gem.getnoir()+get_Develope_Gem_B()-cd.getnoir())<0)
        {doit_dore = doit_dore - (joueur_gem.getnoir()+get_Develope_Gem_B()-cd.getnoir()) ;}
        if((joueur_gem.getbleu()+get_Develope_Gem_U()  - cd.getBleu())<0)
        {doit_dore = doit_dore - (joueur_gem.getbleu()+get_Develope_Gem_U()  - cd.getBleu()) ;}
        if((joueur_gem.getrouge()+get_Develope_Gem_R() - cd.getRouge())<0)
        {doit_dore = doit_dore - (joueur_gem.getrouge()+get_Develope_Gem_R() - cd.getRouge()) ;}
        if((joueur_gem.getvert()+get_Develope_Gem_G()  - cd.getVert())<0)
        {doit_dore = doit_dore - (joueur_gem.getvert()+get_Develope_Gem_G()  - cd.getVert()) ;}
        if(doit_dore <= joueur_gem.getdore())
        {
            return true;
        }
        else
        {
            return false;
        }
    }

}
void Joueur::afficher_Gem() {

    cout<<"==================="<<endl;
    cout<<"| Gem:            |"<<endl;
    cout<<"|  Blanc: "<<joueur_gem.getblanc()<<"       |"<<endl;
    cout<<"|  Bleu : "<<joueur_gem.getbleu() <<"       |"<<endl;
    cout<<"|  Vert : "<<joueur_gem.getvert() <<"       |"<<endl;
    cout<<"|  Rouge: "<<joueur_gem.getrouge()<<"       |"<<endl;
    cout<<"|  Noir : "<<joueur_gem.getnoir() <<"       |"<<endl;
    cout<<"|  Dore : "<<joueur_gem.getdore() <<"       |"<<endl;
    cout<<"=================="<<endl;

}

int Joueur::doit(const CarteDeveloppee & cd) {
    int doit_dore=0;
    if((joueur_gem.getblanc()+get_Develope_Gem_W()-cd.getblanc())<0) doit_dore = doit_dore - (joueur_gem.getblanc()+get_Develope_Gem_W()-cd.getblanc()) ;
    if((joueur_gem.getnoir()+get_Develope_Gem_B()-cd.getnoir())<0) doit_dore = doit_dore - (joueur_gem.getnoir()+get_Develope_Gem_B()-cd.getnoir()) ;
    if((joueur_gem.getbleu()+get_Develope_Gem_U()  - cd.getBleu())<0) doit_dore = doit_dore - (joueur_gem.getbleu()+get_Develope_Gem_U()  - cd.getBleu()) ;
    if((joueur_gem.getrouge()+get_Develope_Gem_R() - cd.getRouge())<0) doit_dore = doit_dore - (joueur_gem.getrouge()+get_Develope_Gem_R() - cd.getRouge()) ;
    if((joueur_gem.getvert()+get_Develope_Gem_G()  - cd.getVert())<0) doit_dore = doit_dore - (joueur_gem.getvert()+get_Develope_Gem_G()  - cd.getVert()) ;
    return doit_dore;
}

void Joueur::afficher_Carte_Dev() {
    cout<<"==============================="<<endl;
    cout<<"| Carte(s) developpee(s):     |"<<endl;
    cout<<"|                             |"<<endl;
    for (int i=0;i<nb_D;i++){
        cart_developee[i].afficher();
    }
    cout<<"|                             |"<<endl;
    cout<<"==============================="<<endl;

}

void Joueur::afficher_Carte_louee() {
    cout<<"==============================="<<endl;
    cout<<"| Carte(s) louee(s):          |"<<endl;
    cout<<"|                             |"<<endl;
    for (int i=0;i<nb_Y;i++){
        cart_developee_loue[i].afficher();
    }
    cout<<"|                             |"<<endl;
    cout<<"==============================="<<endl;
}

void Joueur::afficher_Carte_Nob() {
    cout<<"==============================="<<endl;
    cout<<"* Carte(s) nobiliaire(s):     *"<<endl;
    cout<<"*                             *"<<endl;
    for (int i=0;i<nb_N;i++){
        cart_nobiliaire[i].afficher();
    }
    cout<<"*                             *"<<endl;
    cout<<"==============================="<<endl;
}

void Joueur::afficher_number_cd() {
    cout<<"\nCarte(s) developpee(s): [ "<<nb_D<<" ]"<<endl;
}

void Joueur::afficher_number_cl() {
    cout<<"\nCarte(s) louee(s): [ "<<nb_Y<<" ]"<<endl;
}

void Joueur::afficher_number_cn() {
    cout<<"\nCarte(s) nobiliaire(s): [ "<<nb_N<<" ]"<<endl;
}//in joueur.cpp


void Joueur::afficher_prestige(){
    cout<<"================="<<endl;
    cout<<"|| Prestige: "<<prestige<< " ||"<<endl;
    cout<<"================="<<endl;
}

void Joueur::afficher_Bonus() {

    cout<<"=================="<<endl;
    cout<<"|| Bonus:       ||"<<endl;
    cout<<"||  Blanc: "<<get_bonus_blanc()<<"    ||"<<endl;
    cout<<"||  Blue : "<<get_bonus_bleu() <<"    ||"<<endl;
    cout<<"||  Vert : "<<get_bonus_vert() <<"    ||"<<endl;
    cout<<"||  Rouge: "<<get_bonus_rouge()<<"    ||"<<endl;
    cout<<"||  Noir : "<<get_bonus_noir() <<"    ||"<<endl;
    cout<<"=================="<<endl;
}

int Joueur::get_bonus_blanc() {
    int nbc=0;
    int i=0;
    while (i!=nb_D){
        if(cart_developee[i].getbonus()=='W') nbc++;
        i++;
    }
    return nbc;
}

int Joueur::get_bonus_bleu() {
    int nbu=0;
    int i=0;
    while (i!=nb_D){
        if(cart_developee[i].getbonus()=='U') nbu++;
        i++;
    }
    return nbu;
}

int Joueur::get_bonus_vert() {
    int nbv=0;
    int i=0;
    while (i!=nb_D){
        if(cart_developee[i].getbonus()=='G') nbv++;
        i++;
    }
    return nbv;
}

int Joueur::get_bonus_rouge() {
    int nbr=0;
    int i=0;
    while (i!=nb_D){
        if(cart_developee[i].getbonus()=='R') nbr++;
        i++;
    }
    return nbr;
}

int Joueur::get_bonus_noir() {
    int nbn=0;
    int i=0;
    while (i!=nb_D){
        if(cart_developee[i].getbonus()=='B') nbn++;
        i++;
    }
    return nbn;
}
//W:白色  U：蓝色  G：绿色  R：红色  B：黑色



int AIJ::op_AI(Plateau& p) {
    if(nb_Y>0)
    {
        for(int i=0; i<nb_Y;i++)
        {
            if(isaffordable(cart_developee_loue[i]))
                return 5;
        }
    }
    if((( !p.pCarteDeveloppee3[0].isnullcartedev() )||
    ( !p.pCarteDeveloppee3[1].isnullcartedev()) ||
    ( ( !p.pCarteDeveloppee3[2].isnullcartedev() ))||
    ( !p.pCarteDeveloppee3[3].isnullcartedev())) &&
            (( (!p.pCarteDeveloppee3[0].isnullcartedev()) && isaffordable(p.pCarteDeveloppee3[0])) ||
            ( ( !p.pCarteDeveloppee3[1].isnullcartedev() )&& isaffordable(p.pCarteDeveloppee3[1])) ||
            ( ( !p.pCarteDeveloppee3[2].isnullcartedev() )&& isaffordable(p.pCarteDeveloppee3[2])) ||
            ( ( !p.pCarteDeveloppee3[3].isnullcartedev() )&& isaffordable(p.pCarteDeveloppee3[3]))))return 4;

    if((( !p.pCarteDeveloppee2[0].isnullcartedev() )||
        ( !p.pCarteDeveloppee2[1].isnullcartedev()) ||
        ( ( !p.pCarteDeveloppee2[2].isnullcartedev() ))||
        ( !p.pCarteDeveloppee2[3].isnullcartedev())) &&
       (( (!p.pCarteDeveloppee2[0].isnullcartedev()) && isaffordable(p.pCarteDeveloppee2[0])) ||
        ( ( !p.pCarteDeveloppee2[1].isnullcartedev() )&& isaffordable(p.pCarteDeveloppee2[1])) ||
        ( ( !p.pCarteDeveloppee2[2].isnullcartedev() )&& isaffordable(p.pCarteDeveloppee2[2])) ||
        ( ( !p.pCarteDeveloppee2[3].isnullcartedev() )&& isaffordable(p.pCarteDeveloppee2[3]))))return 4;


    if((( !p.pCarteDeveloppee1[0].isnullcartedev() )||
        ( !p.pCarteDeveloppee1[1].isnullcartedev()) ||
        ( ( !p.pCarteDeveloppee1[2].isnullcartedev() ))||
        ( !p.pCarteDeveloppee1[3].isnullcartedev())) &&
       (( (!p.pCarteDeveloppee1[0].isnullcartedev()) && isaffordable(p.pCarteDeveloppee1[0])) ||
        ( ( !p.pCarteDeveloppee1[1].isnullcartedev() )&& isaffordable(p.pCarteDeveloppee1[1])) ||
        ( ( !p.pCarteDeveloppee1[2].isnullcartedev() )&& isaffordable(p.pCarteDeveloppee1[2])) ||
        ( ( !p.pCarteDeveloppee1[3].isnullcartedev() )&& isaffordable(p.pCarteDeveloppee1[3]))))return 4;
      if(getNbJoueurGem() <= 8) {
            if (p.plateaugem.getnoir() >= 4 || p.plateaugem.getrouge() >= 4 || p.plateaugem.getvert() >= 4 ||
                p.plateaugem.getblanc() >= 4 || p.plateaugem.getbleu() >= 4)
                return 2;
        }
      if(getNbJoueurGem() <= 7) {
          if (!(p.plateaugem.getnoir() < 1 && p.plateaugem.getrouge() < 1 && p.plateaugem.getvert() < 1 &&
                p.plateaugem.getblanc() < 1 && p.plateaugem.getbleu() < 1)) {
              int i = 0;
              if (i < 3 && p.plateaugem.getnoir() >= 1) {
                  p.plateaugem.retirer(0, 0, 0, 0, 1, 0);
                  joueur_gem.ajouter(0, 0, 0, 0, 1, 0);
                  i++;
              }
              if (i < 3 && p.plateaugem.getrouge() >= 1) {
                  p.plateaugem.retirer(0, 1, 0, 0, 0, 0);
                  joueur_gem.ajouter(0, 1, 0, 0, 0, 0);
                  i++;
              }
              if (i < 3 && p.plateaugem.getvert() >= 1) {
                  p.plateaugem.retirer(1, 0, 0, 0, 0, 0);
                  joueur_gem.ajouter(1, 0, 0, 0, 0, 0);
                  i++;
              }
              if (i < 3 && p.plateaugem.getblanc() >= 1) {
                  p.plateaugem.retirer(0, 0, 0, 1, 0, 0);
                  joueur_gem.ajouter(0, 0, 0, 1, 0, 0);
                  i++;
              }
              if (i < 3 && p.plateaugem.getbleu() >= 1) {
                  p.plateaugem.retirer(0, 0, 1, 0, 0, 0);
                  joueur_gem.ajouter(0, 0, 1, 0, 0, 0);
                  i++;
              }
              return 1;
          }

      }
    if(getNbJoueurGem() <= 8) {
        if (!(p.plateaugem.getnoir() < 1 && p.plateaugem.getrouge() < 1 && p.plateaugem.getvert() < 1 &&
              p.plateaugem.getblanc() < 1 && p.plateaugem.getbleu() < 1)) {
            int i = 0;
            if (i < 2 && p.plateaugem.getnoir() >= 1) {
                p.plateaugem.retirer(0, 0, 0, 0, 1, 0);
                joueur_gem.ajouter(0, 0, 0, 0, 1, 0);
                i++;
            }
            if (i < 2 && p.plateaugem.getrouge() >= 1) {
                p.plateaugem.retirer(0, 1, 0, 0, 0, 0);
                joueur_gem.ajouter(0, 1, 0, 0, 0, 0);
                i++;
            }
            if (i < 2 && p.plateaugem.getvert() >= 1) {
                p.plateaugem.retirer(1, 0, 0, 0, 0, 0);
                joueur_gem.ajouter(1, 0, 0, 0, 0, 0);
                i++;
            }
            if (i < 2 && p.plateaugem.getblanc() >= 1) {
                p.plateaugem.retirer(0, 0, 0, 1, 0, 0);
                joueur_gem.ajouter(0, 0, 0, 1, 0, 0);
                i++;
            }
            if (i < 2 && p.plateaugem.getbleu() >= 1) {
                p.plateaugem.retirer(0, 0, 1, 0, 0, 0);
                joueur_gem.ajouter(0, 0, 1, 0, 0, 0);
                i++;
            }
            return 1;
        }

    }
    if(getNbJoueurGem() <= 9) {
        if(nb_Y<3)
            return 3;
        if (!(p.plateaugem.getnoir() < 1 && p.plateaugem.getrouge() < 1 && p.plateaugem.getvert() < 1 &&
              p.plateaugem.getblanc() < 1 && p.plateaugem.getbleu() < 1)) {
            int i = 0;
            if (i < 1 && p.plateaugem.getnoir() >= 1) {
                p.plateaugem.retirer(0, 0, 0, 0, 1, 0);
                joueur_gem.ajouter(0, 0, 0, 0, 1, 0);
                i++;
            }
            if (i < 1 && p.plateaugem.getrouge() >= 1) {
                p.plateaugem.retirer(0, 1, 0, 0, 0, 0);
                joueur_gem.ajouter(0, 1, 0, 0, 0, 0);
                i++;
            }
            if (i < 1 && p.plateaugem.getvert() >= 1) {
                p.plateaugem.retirer(1, 0, 0, 0, 0, 0);
                joueur_gem.ajouter(1, 0, 0, 0, 0, 0);
                i++;
            }
            if (i < 1 && p.plateaugem.getblanc() >= 1) {
                p.plateaugem.retirer(0, 0, 0, 1, 0, 0);
                joueur_gem.ajouter(0, 0, 0, 1, 0, 0);
                i++;
            }
            if (i < 1 && p.plateaugem.getbleu() >= 1) {
                p.plateaugem.retirer(0, 0, 1, 0, 0, 0);
                joueur_gem.ajouter(0, 0, 1, 0, 0, 0);
                i++;
            }
            return 1;
        }

    }
    if(nb_Y<3)
        return 3;
    //for(int i = 0;i<5;i++)

    //return 0;
}
