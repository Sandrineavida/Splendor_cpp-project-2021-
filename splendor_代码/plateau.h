//
// Created by SLP-SUMHS on 2021/10/27.
//

#ifndef UNTITLED_PLATEAU_H
#define UNTITLED_PLATEAU_H

#include <iostream>
#include "gem.h"
#include "cartes.h"
#include "joueur.h"

using namespace std;


//桌上现有状况定义（包含可见【发展牌】、可见【贵族牌】、【宝石】）
/*         Plateau应【对】{宝石}的生命周期负责
 *                (Pour les pierres précieuses,
 *                on peut faire comme cela:
 *                <<Gem* gem = nullptr;>>
 *                puis,dans le destructeur,
 *                on doit [delete] les [gem] un par un,
 *                puisqu'ils sont créés un par un par [new].)
           Plateau【不对】{卡牌}的生命周期负责
      Plateau将能够实现：
      (1) {添加}、{移除}桌上的【发展牌】；

               注意：
               1）当{移除}发生时，应自动进行{添加}

               2）当【发展牌】某一类被取尽，【不必】抛出异常
                  因此需要先对尚未翻开的【发展牌】数量进行判断，
                如果还有尚未翻开的【发展牌】，则进行{添加}

      (2) {移除}桌上的【贵族牌】； 注意，当【贵族牌】被取尽，【不必】抛出异常

      (3) {增}、{减}桌上的宝石个数； 当宝石全被取走后，若仍接到取用宝石指令，则抛出异常
      */

class Plateau{
private:

    PlateauGem plateaugem;
    CarteDeveloppee* pCarteDeveloppee1 = new CarteDeveloppee[4];
    CarteDeveloppee* pCarteDeveloppee2 = new CarteDeveloppee[4];
    CarteDeveloppee* pCarteDeveloppee3 = new CarteDeveloppee[4];
    CarteNobiliaire* pCarteNobiliaire = nullptr;
    CarteCity* pCartecity = nullptr;
    size_t nbNob = 0;
    ToutLesCarteCity& TCC = ToutLesCarteCity::getCity();
    ToutesLesCartesDeveloppees TCD = ToutesLesCartesDeveloppees();
    ToutesLesCartesNobiliaires& TCN = ToutesLesCartesNobiliaires::getNobiliaires();
    size_t nbCity = 3;
    size_t posCD1 = 4;//第posCD1张1级发展牌等待被翻开
    size_t posCD2 = 4;//第posCD2张2级发展牌等待被翻开
    size_t posCD3 = 4;//第posCD3张3级发展牌等待被翻开


public:

    friend class AIJ;
    friend class Controleur;
    Plateau(int nbPersonne);//根据玩家数量来构成桌上所需道具数目
    Plateau(int nbPersonne,int i);
    ~Plateau() {
        delete[] pCarteDeveloppee1;
        delete[] pCarteDeveloppee2;
        delete[] pCarteDeveloppee3;
        delete[] pCarteNobiliaire;
        delete[] pCartecity;}
//    size_t getNbCartesDeveloppee1()const{return nbDev1;}
//    size_t getNbCartesDeveloppee2()const{return nbDev2;}
//    size_t getNbCartesDeveloppee3()const{return nbDev3;}
    Plateau& operator=(const Plateau& plateau)=default;
    size_t getNbCartesNobiliaire()const{return nbNob;}
    void ajouterCartesDeveloppee1(int pos);
    CarteDeveloppee retirerCartesDeveloppee1(int i);
    void ajouterCartesDeveloppee2(int pos);
    CarteDeveloppee retirerCartesDeveloppee2(int i);
    void ajouterCartesDeveloppee3(int pos);
    CarteDeveloppee retirerCartesDeveloppee3(int i);

    void retirerCartesNobiliaire(int i);
    void retierCartCity(int i);
    void ajouterGem(int v=0,int r=0,int bbleu=0,int bblanc=0,int n=0 ,int d=0);
    void retirerGem3(char,char,char);
    void retirerGem2(char);

    int retirerGold();

    void afficher_cartes_dev1();
    void afficher_cartes_dev2();
    void afficher_cartes_dev3();

    void afficher_noble();
    void afficher_city();
    void afficher_Gem();
//    void set_carte_nob();

};



#endif //UNTITLED_PLATEAU_H
