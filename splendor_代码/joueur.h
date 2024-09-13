//
// Created by SLP-SUMHS on 2021/10/27.
//

#ifndef UNTITLED_JOUEUR_H
#define UNTITLED_JOUEUR_H

#include <iostream>
#include "gem.h"
#include "cartes.h"
#include <cstring>
#include "plateau.h"
using namespace std;

class Plateau;

//玩家定义
/*    玩家将持有【发展牌】、【贵族牌】、【宝石】、【声望】、【预留发展牌】
 *    玩家【不对】{发展牌}、{贵族牌}、{预留发展牌}、{宝石}的生命周期负责
 *    玩家【对】{声望}的生命周期负责
 *             (Pour le prestige, on peut faire comme cela:<<int prestige=0;>>,
 *             dans ce cas-là, prestige est un argument primitif
 *             et son cycle de vie est géré automatiquement.)
 *    注：{声望}={发展牌}.getprestige()+{贵族牌}.getprestige()
 *
 *    玩家类可以拥有的方法：
 *    （1）get一堆东西
 *
 *
*/
class Joueur{
protected:
    CarteDeveloppee* cart_developee = nullptr;
    size_t nbMax_D = 0;
    size_t nb_D = 0;
     CarteDeveloppee* cart_developee_loue = nullptr;//new const CarteDeveloppee*[2];
    size_t nbMax_Y = 3;
    size_t nb_Y = 0;
    CarteNobiliaire* cart_nobiliaire = nullptr;
    size_t nbMax_N = 0;
    size_t nb_N = 0;
    JoueurGems joueur_gem ;
//    int gem = 0;  //get_sumGem()
    bool city = false;
    bool huiqi = true;
    int prestige = 0;
    string name ;
    int birthday = 0;

public:
    Joueur() = default;
    ~Joueur() {delete [] cart_nobiliaire;delete [] cart_developee;delete [] cart_developee_loue;}
    void ajouter_CarteDeveloppee (const CarteDeveloppee& C_D) ;
    void ajouter_CarteNobiliaire (const CarteNobiliaire& C_N) ;
    void ajouter_CarteDeveloppee_loue ( const CarteDeveloppee &C_Y) ;
    void acheter_CarteDeveloppee_loue (  CarteDeveloppee& C_Y,int p) ;

    int get_prestige()const {return prestige;}
    void ajouter_Gem(int v=0,int r=0,int bbleu=0,int bblanc=0,int n=0 ,int d=0);////////////////////////////////////////////////
    void retirer_Gem(int v=0,int r=0,int bbleu=0,int bblanc=0,int n=0 ,int d=0);////////////////////////////////////////////////
    void setName(string &q)  { name = q;}
    CarteDeveloppee& get_CarteDeveloppee_loue(int i)  {return cart_developee_loue[i]; }
    string getName()const {return name;}
    int getbirthday()const {return birthday;}
    void setbirthday(int b) {birthday = b;}
    int getNB_D()const {return nb_D;}
    Joueur(const Joueur& j)=default;
    Joueur& operator=(const Joueur& j)=default;
    int getNbJoueurGem()const{return joueur_gem.get_sumGem();}//获取玩家手中总宝石数
    int get_Develope_Gem_W()const ;
    int get_Develope_Gem_U()const ;
    int get_Develope_Gem_G()const ;
    int get_Develope_Gem_R()const ;
    int get_Develope_Gem_B()const ;
    bool getcity()const {return city;}
    void setcity(){city = true;}
    bool gethuiqi()const {return huiqi;}
    void sethuiqi(){huiqi = false;}
    friend class Controleur;

    bool isaffordable(CarteDeveloppee&);
     int doit(const CarteDeveloppee& cd);

    void afficher_Gem();
    void afficher_Bonus();
    void afficher_number_cd();//this one
    void afficher_Carte_Dev();
    void afficher_number_cl();//this one
    void afficher_Carte_louee();
    void afficher_number_cn();//and this one   in joueur.h
    void afficher_Carte_Nob();

    void afficher_prestige();

    int get_bonus_blanc();
    int get_bonus_bleu();
    int get_bonus_vert();
    int get_bonus_rouge();
    int get_bonus_noir();

};
class AIJ: public Joueur{
public:
    int op_AI(Plateau& p);
};

#endif //UNTITLED_JOUEUR_H
