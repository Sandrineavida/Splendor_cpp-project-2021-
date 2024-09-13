//
// Created by SLP-SUMHS on 2021/10/27.
//

#include "plateau.h"



Plateau::Plateau(int nbPersonne) {
    if(nbPersonne == 2){
        plateaugem.ajouter(4,4,4,4,4,5);
        pCarteNobiliaire = new CarteNobiliaire [3];
        nbNob = 3;
        for (int i=0;i<nbNob;i++){
            pCarteNobiliaire[i] = TCN.carte_nobiliaire[i];
        }

    }
    else if(nbPersonne == 3){
        plateaugem.ajouter(5,5,5,5,5,5);
        pCarteNobiliaire = new CarteNobiliaire [4];
        nbNob = 4;
        for (int i=0;i<nbNob;i++){
            pCarteNobiliaire[i] = TCN.carte_nobiliaire[i];
        }
    }
    else if(nbPersonne == 4){
        plateaugem.ajouter(7,7,7,7,7,5);
        pCarteNobiliaire = new CarteNobiliaire [5];
        nbNob = 5;
        for (int i=0;i<nbNob;i++){
            pCarteNobiliaire[i] = TCN.carte_nobiliaire[i];
        }
    }
    else if(nbPersonne <= 1 || nbPersonne >=5 ){
        throw SplendorException("Wrong player number.");
    }

    for (int i=0;i<4;i++){//初始化使桌上一共翻开了各级别发展卡各4张
        pCarteDeveloppee1[i] = TCD.pre_cartes[i];
        pCarteDeveloppee2[i] = TCD.sec_cartes[i];
        pCarteDeveloppee3[i] = TCD.tro_cartes[i];
    }
}


void Plateau::ajouterCartesDeveloppee1(int pos){
    if (posCD1 != 40){
        pCarteDeveloppee1[pos] = TCD.pre_cartes[posCD1];posCD1++;
    }
    else{
        pCarteDeveloppee1[pos] = {0,0,0,0,0,0,0};

    }
}

void Plateau::ajouterCartesDeveloppee2(int pos){
    if (posCD2 != 30){
        pCarteDeveloppee2[pos] = TCD.sec_cartes[posCD2];posCD2++;
    }
    else{
        pCarteDeveloppee2[pos] = {0,0,0,0,0,0,0};
    }
}

void Plateau::ajouterCartesDeveloppee3(int pos){
    if (posCD3 != 20){
        pCarteDeveloppee3[pos] = TCD.tro_cartes[posCD3];posCD3++;
    }
    else{
        pCarteDeveloppee3[pos] = {0,0,0,0,0,0,0};
    }
}

CarteDeveloppee Plateau::retirerCartesDeveloppee1(int i) {
    if((!pCarteDeveloppee1[i-1].isnullcartedev())&&i>=0&&i<=4){
        CarteDeveloppee cartedev1 = pCarteDeveloppee1[i-1];//拿出i位置上的1级发展牌
        //ajouterCartesDeveloppee1(i-1);//为i位置的1级发展牌重新发牌
        return cartedev1;
    }
    else{
        throw SplendorException("Il n'y a pas de carte.");
    }
}

CarteDeveloppee Plateau::retirerCartesDeveloppee2(int i) {
    if((!pCarteDeveloppee2[i-1].isnullcartedev())&&i>0&&i<=4){
        CarteDeveloppee cartedev2 = pCarteDeveloppee2[i-1];//拿出i位置上的2级发展牌
        //ajouterCartesDeveloppee2(i-1);//为i位置的2级发展牌重新发牌
        return cartedev2;
    }
    else{
        throw SplendorException("Il n'y a pas de carte.");
    }
}

CarteDeveloppee Plateau::retirerCartesDeveloppee3(int i) {
    if((!pCarteDeveloppee3[i-1].isnullcartedev())&&i>0&&i<=4){
        CarteDeveloppee cartedev3 = pCarteDeveloppee3[i-1];//拿出i位置上的1级发展牌
        //ajouterCartesDeveloppee3(i-1);//为i位置的1级发展牌重新发牌
        return cartedev3;
    }
    else{
        throw SplendorException("Il n'y a pas de carte.");
    }
}

void Plateau::retirerCartesNobiliaire(int i){

    while (i < nbNob-1){
        pCarteNobiliaire[i] = pCarteNobiliaire[i+1];i++;
    }
    nbNob--;
}

void Plateau::retirerGem3(char g1, char g2, char g3) {

    int v=0,r=0,bbleu=0,bblanc=0,n=0;
    if (g1 == 'v'||g2 == 'v'||g3 == 'v') {
        if(plateaugem.vert!=0){
            v=1;
        }
//    if(plateaugem.vert==0) throw SplendorException("Comportement invalide! Il n'y a plus de pierre précieuse de ce type sur la table.");
    }
    if (g1 == 'r'||g2 == 'r'||g3 == 'r') {if(plateaugem.rouge!=0) r=1;}
    if (g1 == 'u'||g2 == 'u'||g3 == 'u') {if(plateaugem.bleu!=0) bbleu=1;}
    if (g1 == 'c'||g2 == 'c'||g3 == 'c') {if(plateaugem.blanc!=0)bblanc=1;}
    if (g1 == 'n'||g2 == 'n'||g3 == 'n') {if(plateaugem.noir!=0)n=1;}

    if (plateaugem.getnoir()<n && plateaugem.getblanc()<bblanc && plateaugem.getbleu()<bbleu && plateaugem.getrouge()<r && plateaugem.getvert() < v) {
        throw SplendorException("Comportement invalide! Il n'y a plus de pierre precieuse de ces types sur la table.");
    }

    plateaugem.retirer(v,r,bbleu,bblanc,n);

}

void Plateau::retirerGem2(char g) {

    int v=0,r=0,bbleu=0,bblanc=0,n=0;
    if (g == 'v') {v=2;if(plateaugem.vert<=2) throw SplendorException("Comportement invalide! Il y a moins de 2 pierres précieuses de ce type sur la table.");}
    else if (g == 'r') {r=2;if(plateaugem.rouge<=2) throw SplendorException("Comportement invalide! Il y a moins de 2 pierres précieuses de ce type sur la table.");}
    else if (g == 'u') {bbleu=2;if(plateaugem.bleu<=2) throw SplendorException("Comportement invalide! Il y a moins de 2 pierres précieuses de ce type sur la table.");}
    else if (g == 'c') {bblanc=2;if(plateaugem.blanc<=2) throw SplendorException("Comportement invalide! Il y a moins de 2 pierres précieuses de ce type sur la table.");}
    else if (g == 'n') {n=2;if(plateaugem.noir<=2) throw SplendorException("Comportement invalide! Il y a moins de 2 pierres précieuses de ce type sur la table.");}

    plateaugem.retirer(v,r,bbleu,bblanc,n);
}

void Plateau::ajouterGem(int v,int r,int bbleu,int bblanc,int n ,int d) {
    plateaugem.ajouter(v,r,bbleu,bblanc,n,d);
}

void Plateau::afficher_cartes_dev1(){  //数字的输出可能是1位可能是2位；咋搞捏；；；

    if(!pCarteDeveloppee1[0].isnullcartedev()) {cout<<"|| Pres:"<<pCarteDeveloppee1[0].getPrestige()<<"  Bonus: "<<pCarteDeveloppee1[0].getbonus_string()<<"||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[1].isnullcartedev()) {cout<<"|| Pres:"<<pCarteDeveloppee1[1].getPrestige()<<"  Bonus: "<<pCarteDeveloppee1[1].getbonus_string()<<"||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[2].isnullcartedev()) {cout<<"|| Pres:"<<pCarteDeveloppee1[2].getPrestige()<<"  Bonus: "<<pCarteDeveloppee1[2].getbonus_string()<<"||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[3].isnullcartedev()) {cout<<"|| Pres:"<<pCarteDeveloppee1[3].getPrestige()<<"  Bonus: "<<pCarteDeveloppee1[3].getbonus_string()<<"||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee1[0].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[1].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[2].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[3].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee1[0].isnullcartedev()) {cout<<"||       Primaire      ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[1].isnullcartedev()) {cout<<"||       Primaire      ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[2].isnullcartedev()) {cout<<"||       Primaire      ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[3].isnullcartedev()) {cout<<"||       Primaire      ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee1[0].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[1].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[2].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[3].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee1[0].isnullcartedev()) {cout<<"|| Blanc:  "<<pCarteDeveloppee1[0].getblanc()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[1].isnullcartedev()) {cout<<"|| Blanc:  "<<pCarteDeveloppee1[1].getblanc()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[2].isnullcartedev()) {cout<<"|| Blanc:  "<<pCarteDeveloppee1[2].getblanc()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[3].isnullcartedev()) {cout<<"|| Blanc:  "<<pCarteDeveloppee1[3].getblanc()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee1[0].isnullcartedev()) {cout<<"|| Bleu:   "<<pCarteDeveloppee1[0].getBleu()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[1].isnullcartedev()) {cout<<"|| Bleu:   "<<pCarteDeveloppee1[1].getBleu()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[2].isnullcartedev()) {cout<<"|| Bleu:   "<<pCarteDeveloppee1[2].getBleu()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[3].isnullcartedev()) {cout<<"|| Bleu:   "<<pCarteDeveloppee1[3].getBleu()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee1[0].isnullcartedev()) {cout<<"|| Vert:   "<<pCarteDeveloppee1[0].getVert()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[1].isnullcartedev()) {cout<<"|| Vert:   "<<pCarteDeveloppee1[1].getVert()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[2].isnullcartedev()) {cout<<"|| Vert:   "<<pCarteDeveloppee1[2].getVert()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[3].isnullcartedev()) {cout<<"|| Vert:   "<<pCarteDeveloppee1[3].getVert()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee1[0].isnullcartedev()) {cout<<"|| Rouge:  "<<pCarteDeveloppee1[0].getRouge()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[1].isnullcartedev()) {cout<<"|| Rouge:  "<<pCarteDeveloppee1[1].getRouge()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[2].isnullcartedev()) {cout<<"|| Rouge:  "<<pCarteDeveloppee1[2].getRouge()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[3].isnullcartedev()) {cout<<"|| Rouge:  "<<pCarteDeveloppee1[3].getRouge()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee1[0].isnullcartedev()) {cout<<"|| Noir:   "<<pCarteDeveloppee1[0].getnoir()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[1].isnullcartedev()) {cout<<"|| Noir:   "<<pCarteDeveloppee1[1].getnoir()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[2].isnullcartedev()) {cout<<"|| Noir:   "<<pCarteDeveloppee1[2].getnoir()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee1[3].isnullcartedev()) {cout<<"|| Noir:   "<<pCarteDeveloppee1[3].getnoir()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;
    cout<<endl;

}

void Plateau::afficher_cartes_dev2() {

    if(!pCarteDeveloppee2[0].isnullcartedev()) {cout<<"|| Pres:"<<pCarteDeveloppee2[0].getPrestige()<<"  Bonus: "<<pCarteDeveloppee2[0].getbonus_string()<<"||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[1].isnullcartedev()) {cout<<"|| Pres:"<<pCarteDeveloppee2[1].getPrestige()<<"  Bonus: "<<pCarteDeveloppee2[1].getbonus_string()<<"||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[2].isnullcartedev()) {cout<<"|| Pres:"<<pCarteDeveloppee2[2].getPrestige()<<"  Bonus: "<<pCarteDeveloppee2[2].getbonus_string()<<"||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[3].isnullcartedev()) {cout<<"|| Pres:"<<pCarteDeveloppee2[3].getPrestige()<<"  Bonus: "<<pCarteDeveloppee2[3].getbonus_string()<<"||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee2[0].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[1].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[2].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[3].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee2[0].isnullcartedev()) {cout<<"||         Moyen       ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[1].isnullcartedev()) {cout<<"||         Moyen       ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[2].isnullcartedev()) {cout<<"||         Moyen       ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[3].isnullcartedev()) {cout<<"||         Moyen       ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee2[0].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[1].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[2].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[3].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee2[0].isnullcartedev()) {cout<<"|| Blanc:  "<<pCarteDeveloppee2[0].getblanc()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[1].isnullcartedev()) {cout<<"|| Blanc:  "<<pCarteDeveloppee2[1].getblanc()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[2].isnullcartedev()) {cout<<"|| Blanc:  "<<pCarteDeveloppee2[2].getblanc()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[3].isnullcartedev()) {cout<<"|| Blanc:  "<<pCarteDeveloppee2[3].getblanc()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee2[0].isnullcartedev()) {cout<<"|| Bleu:   "<<pCarteDeveloppee2[0].getBleu()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[1].isnullcartedev()) {cout<<"|| Bleu:   "<<pCarteDeveloppee2[1].getBleu()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[2].isnullcartedev()) {cout<<"|| Bleu:   "<<pCarteDeveloppee2[2].getBleu()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[3].isnullcartedev()) {cout<<"|| Bleu:   "<<pCarteDeveloppee2[3].getBleu()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee2[0].isnullcartedev()) {cout<<"|| Vert:   "<<pCarteDeveloppee2[0].getVert()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[1].isnullcartedev()) {cout<<"|| Vert:   "<<pCarteDeveloppee2[1].getVert()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[2].isnullcartedev()) {cout<<"|| Vert:   "<<pCarteDeveloppee2[2].getVert()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[3].isnullcartedev()) {cout<<"|| Vert:   "<<pCarteDeveloppee2[3].getVert()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee2[0].isnullcartedev()) {cout<<"|| Rouge:  "<<pCarteDeveloppee2[0].getRouge()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[1].isnullcartedev()) {cout<<"|| Rouge:  "<<pCarteDeveloppee2[1].getRouge()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[2].isnullcartedev()) {cout<<"|| Rouge:  "<<pCarteDeveloppee2[2].getRouge()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[3].isnullcartedev()) {cout<<"|| Rouge:  "<<pCarteDeveloppee2[3].getRouge()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee2[0].isnullcartedev()) {cout<<"|| Noir:   "<<pCarteDeveloppee2[0].getnoir()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[1].isnullcartedev()) {cout<<"|| Noir:   "<<pCarteDeveloppee2[1].getnoir()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[2].isnullcartedev()) {cout<<"|| Noir:   "<<pCarteDeveloppee2[2].getnoir()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee2[3].isnullcartedev()) {cout<<"|| Noir:   "<<pCarteDeveloppee2[3].getnoir()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;
    cout<<endl;

}

void Plateau::afficher_cartes_dev3() {

    if(!pCarteDeveloppee3[0].isnullcartedev()) {cout<<"|| Pres:"<<pCarteDeveloppee3[0].getPrestige()<<"  Bonus: "<<pCarteDeveloppee3[0].getbonus_string()<<"||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[1].isnullcartedev()) {cout<<"|| Pres:"<<pCarteDeveloppee3[1].getPrestige()<<"  Bonus: "<<pCarteDeveloppee3[1].getbonus_string()<<"||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[2].isnullcartedev()) {cout<<"|| Pres:"<<pCarteDeveloppee3[2].getPrestige()<<"  Bonus: "<<pCarteDeveloppee3[2].getbonus_string()<<"||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[3].isnullcartedev()) {cout<<"|| Pres:"<<pCarteDeveloppee3[3].getPrestige()<<"  Bonus: "<<pCarteDeveloppee3[3].getbonus_string()<<"||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee3[0].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[1].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[2].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[3].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee3[0].isnullcartedev()) {cout<<"||      Superieur      ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[1].isnullcartedev()) {cout<<"||      Superieur      ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[2].isnullcartedev()) {cout<<"||      Superieur      ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[3].isnullcartedev()) {cout<<"||      Superieur      ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee3[0].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[1].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[2].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[3].isnullcartedev()) {cout<<"||                     ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee3[0].isnullcartedev()) {cout<<"|| Blanc:  "<<pCarteDeveloppee3[0].getblanc()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[1].isnullcartedev()) {cout<<"|| Blanc:  "<<pCarteDeveloppee3[1].getblanc()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[2].isnullcartedev()) {cout<<"|| Blanc:  "<<pCarteDeveloppee3[2].getblanc()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[3].isnullcartedev()) {cout<<"|| Blanc:  "<<pCarteDeveloppee3[3].getblanc()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee3[0].isnullcartedev()) {cout<<"|| Bleu:   "<<pCarteDeveloppee3[0].getBleu()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[1].isnullcartedev()) {cout<<"|| Bleu:   "<<pCarteDeveloppee3[1].getBleu()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[2].isnullcartedev()) {cout<<"|| Bleu:   "<<pCarteDeveloppee3[2].getBleu()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[3].isnullcartedev()) {cout<<"|| Bleu:   "<<pCarteDeveloppee3[3].getBleu()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee3[0].isnullcartedev()) {cout<<"|| Vert:   "<<pCarteDeveloppee3[0].getVert()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[1].isnullcartedev()) {cout<<"|| Vert:   "<<pCarteDeveloppee3[1].getVert()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[2].isnullcartedev()) {cout<<"|| Vert:   "<<pCarteDeveloppee3[2].getVert()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[3].isnullcartedev()) {cout<<"|| Vert:   "<<pCarteDeveloppee3[3].getVert()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee3[0].isnullcartedev()) {cout<<"|| Rouge:  "<<pCarteDeveloppee3[0].getRouge()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[1].isnullcartedev()) {cout<<"|| Rouge:  "<<pCarteDeveloppee3[1].getRouge()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[2].isnullcartedev()) {cout<<"|| Rouge:  "<<pCarteDeveloppee3[2].getRouge()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[3].isnullcartedev()) {cout<<"|| Rouge:  "<<pCarteDeveloppee3[3].getRouge()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;

    if(!pCarteDeveloppee3[0].isnullcartedev()) {cout<<"|| Noir:   "<<pCarteDeveloppee3[0].getnoir()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[1].isnullcartedev()) {cout<<"|| Noir:   "<<pCarteDeveloppee3[1].getnoir()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[2].isnullcartedev()) {cout<<"|| Noir:   "<<pCarteDeveloppee3[2].getnoir()<<"           ||  ";}
    else{cout<<"                           ";}
    if(!pCarteDeveloppee3[3].isnullcartedev()) {cout<<"|| Noir:   "<<pCarteDeveloppee3[3].getnoir()<<"           ||  ";}
    else{cout<<"                           ";}

    cout<<endl;
    cout<<endl;

}


//void afficher(CarteDeveloppee&)const{
//    cout<<"Prestige: "<<prestige<<"    Bonus: "<<bonus<<endl;
//    cout<<"\n\n  Primaire\n\n";
//    cout<<"Blanc: "<<blanc<<endl;
//    cout<<"Bleu:  "<<bleu<<endl;
//    cout<<"Vert:  "<<vert<<endl;
//    cout<<"Rouge: "<<rouge<<endl;
//    cout<<"Noir:  "<<noir<<endl;
//}


void Plateau::afficher_noble() {

    cout<<"*******************************"<<endl;
    cout<<"* Carte(s) nobiliaire(s):     *"<<endl;
    cout<<"*                             *"<<endl;
    for (int i=0;i<nbNob;i++){
        pCarteNobiliaire[i].afficher();
    }
    cout<<"*                             *"<<endl;
    cout<<"*******************************"<<endl;

}

int Plateau::retirerGold() {
    if (plateaugem.dore>0){
        plateaugem.retirer(0,0,0,0,0,1);
        return 1;
    }
    else
        return 0;
}

void Plateau::afficher_Gem() {

    cout<<"********************"<<endl;
    cout<<"*Gem:              *"<<endl;
    cout<<"* Blanc: "<< plateaugem.getblanc()<<"         *"<<endl;
    cout<<"* Bleu : "<< plateaugem.getbleu() <<"         *"<<endl;
    cout<<"* Vert : "<< plateaugem.getvert() <<"         *"<<endl;
    cout<<"* Rouge: "<< plateaugem.getrouge()<<"         *"<<endl;
    cout<<"* Noir : "<< plateaugem.getnoir() <<"         *"<<endl;
    cout<<"* Dore : "<< plateaugem.getdore() <<"         *"<<endl;
    cout<<"********************"<<endl;

}

Plateau::Plateau(int nbPersonne, int i) {
    if(nbPersonne == 2){
        plateaugem.ajouter(4,4,4,4,4,5);
    }
    else if(nbPersonne == 3){
        plateaugem.ajouter(5,5,5,5,5,5);
    }
    else if(nbPersonne == 4){
        plateaugem.ajouter(7,7,7,7,7,5);
    }
    else if(nbPersonne <= 1 || nbPersonne >=5 ){
        throw SplendorException("Wrong player number.");
    }
    pCartecity = new CarteCity [3];
    nbNob = 3;
    for (int i=0;i<3;i++){
        pCartecity[i] = TCC.carte_city[i];
    }
    for (int i=0;i<4;i++){//初始化使桌上一共翻开了各级别发展卡各4张
        pCarteDeveloppee1[i] = TCD.pre_cartes[i];
        pCarteDeveloppee2[i] = TCD.sec_cartes[i];
        pCarteDeveloppee3[i] = TCD.tro_cartes[i];
    }
}

void Plateau::afficher_city() {
    cout<<"*******************************"<<endl;
    cout<<"* Carte(s) City(s):           *"<<endl;
    cout<<"*                             *"<<endl;
    for (int i=0;i<nbCity;i++){
        pCartecity[i].afficher();
    }
    cout<<"*                             *"<<endl;
    cout<<"*******************************"<<endl;
}

void Plateau::retierCartCity(int i) {
    while (i < nbCity-1){
        pCartecity[i] = pCartecity[i+1];i++;
    }
    nbCity--;
}




//void Plateau::set_carte_nob(){
//    pCarteNobiliaire = new CarteNobiliaire[nbNob];
//    for (int i=0;i<nbNob;i++)
//        pCarteNobiliaire[i] = TCN.carte_nobiliaire[i];
//}


