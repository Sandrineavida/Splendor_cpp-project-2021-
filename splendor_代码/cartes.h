//
// Created by SLP-SUMHS on 2021/10/27.
//

#ifndef UNTITLED_CARTES_H
#define UNTITLED_CARTES_H


#include <iostream>
#include "gem.h"
#include <utility>
#include <vector>
#include <ctime>
#include <cstdio>
#include <stdexcept>
using namespace std;

class CarteException:public exception{
    string info;
public:
    explicit CarteException(string  i)noexcept :info(std::move(i)){}
    ~CarteException()noexcept override = default;
    const char* what() const noexcept  {return info.c_str();}

};


//发展卡定义
class CarteDeveloppee{
private:
    int prestige;//声望
    char bonus;//持有这张卡片可以获得的宝石红利，即这张卡片可以被当做什么宝石永久使用
    int blanc;
    int bleu;
    int vert;
    int rouge;
    int noir;//购买这张发展卡需要花费多少宝石
public:
    const int& getPrestige() const {return prestige;}
    const char& getBonus() const {return bonus;}
    const int& getVert() const {return vert;}
    const int& getRouge() const {return rouge;}
    const int& getBleu() const {return bleu;}
    const int& getblanc() const {return blanc;}
    const int& getnoir() const {return noir;}
    CarteDeveloppee(int p=0,char bonus='0',int blanc=0,int bleu=0,int v=0,int r=0,int n=0 ):prestige(p),bonus(bonus),blanc(blanc),bleu(bleu),vert(v),rouge(r),noir(n){}
    const char& getbonus() const {return  bonus;}
    //需要一个有初始化参数的构造器来让此类型动态数组生成ok
    CarteDeveloppee& operator = (const CarteDeveloppee & c) = default;
    bool operator != (CarteDeveloppee& c);
    bool isnullcartedev() const{
        return (this->getbonus_string()=="NONO~");
    }


    string getbonus_string()const;

    void afficher()const;

};


//贵族卡定义
class CarteNobiliaire{
private:
    int prestige;
    int blanc;
    int bleu;
    int vert;
    int rouge;
    int noir;//需要多少张发展卡

public:
    const int& getPrestige() const {return prestige;}
    const int& getVert() const {return vert;}
    const int& getRouge() const {return rouge;}
    const int& getBleu() const {return bleu;}
    const int& getblanc() const {return blanc;}
    const int& getnoir() const {return noir;}
    CarteNobiliaire(int p=3,int blanc=0,int bleu=0,int v=0,int r=0,int n=0 ):prestige(p),vert(v),rouge(r),bleu(bleu),blanc(blanc),noir(n){}
    void afficher()const;

};
class CarteCity{
private:
    int prestige;
    int blanc;
    int bleu;
    int vert;
    int rouge;
    int noir;
    int samegem;
public:
    const int& getPrestige() const {return prestige;}
    const int& getVert() const {return vert;}
    const int& getRouge() const {return rouge;}
    const int& getBleu() const {return bleu;}
    const int& getblanc() const {return blanc;}
    const int& getnoir() const {return noir;}
    const int& getsame() const {return samegem;}
    CarteCity(int p=0,int blanc=0,int bleu=0,int v=0,int r=0,int n=0 ,int sa =0):prestige(p),vert(v),rouge(r),bleu(bleu),blanc(blanc),noir(n),samegem(sa){}
    void afficher()const;
};
//整套【发展牌】定义）
//         ToutesLesCartesDeveloppees类应【对】{发展牌}的生命周期负责
//         应包含3个级别的【发展卡】，分别对应3个私有成员变量
class ToutesLesCartesDeveloppees{
private:
    CarteDeveloppee* pre_cartes= nullptr;
    CarteDeveloppee* sec_cartes= nullptr;
    CarteDeveloppee* tro_cartes= nullptr;
    //ToutesLesCartesDeveloppees* Developpees;

public:
/*    static ToutesLesCartesDeveloppees& getDeveloppees(){
        if(Developpees== nullptr) Developpees= new ToutesLesCartesDeveloppees;
        return *Developpees;
    }
     static void libererDeveloppees(){
        delete Developpees;
        Developpees= nullptr;
    }*/
    ToutesLesCartesDeveloppees();
    ~ToutesLesCartesDeveloppees();
    ToutesLesCartesDeveloppees(const ToutesLesCartesDeveloppees& tout)=default;
    ToutesLesCartesDeveloppees& operator=(const ToutesLesCartesDeveloppees& tout)=default;
    friend class Plateau;


};



//整套【贵族牌】定义）
//         ToutesLesCartesNobiliaires类应【对】{贵族牌}的生命周期负责
class ToutesLesCartesNobiliaires{
private:
    CarteNobiliaire* carte_nobiliaire= nullptr;
    static ToutesLesCartesNobiliaires* Nobiliaires;
public:
    static ToutesLesCartesNobiliaires& getNobiliaires() {
        if (Nobiliaires == nullptr) Nobiliaires = new ToutesLesCartesNobiliaires;
        return *Nobiliaires;
    }
    static void libererNobiliaires(){
        delete Nobiliaires;
        Nobiliaires= nullptr;
    }
    ToutesLesCartesNobiliaires();
    ~ToutesLesCartesNobiliaires();
    ToutesLesCartesNobiliaires(const ToutesLesCartesNobiliaires& nob)=delete;
    ToutesLesCartesNobiliaires& operator=(const ToutesLesCartesNobiliaires& nob)=delete;
    friend class Plateau;


};
class ToutLesCarteCity{
private:
    CarteCity* carte_city= nullptr;
    static ToutLesCarteCity* City;
public:
    static ToutLesCarteCity& getCity() {
        if (City == nullptr) City = new ToutLesCarteCity;
        return *City;
    }
    static void libererCity(){
        delete City;
        City= nullptr;
    }
    ToutLesCarteCity();
    ~ToutLesCarteCity();
    ToutLesCarteCity(const ToutLesCarteCity& nob)=delete;
    ToutLesCarteCity& operator=(const ToutLesCarteCity& nob)=delete;
    friend class Plateau;
};

#endif //UNTITLED_CARTES_H
