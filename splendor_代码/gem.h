//
// Created by SLP-SUMHS on 2021/10/27.
//

#ifndef UNTITLED_GEM_H
#define UNTITLED_GEM_H

#include <iostream>
using namespace std;

//异常处理
class SplendorException {
public:
    SplendorException(const string& i) :info(i) {}
    const string& getInfo() const { return info; }
private:
    string info;
};


//宝石类型定义
enum class Gem { vert, rouge, bleu, blanc, noir, dore };
string toString(Gem g);
ostream& operator<<(ostream& f, Gem g);
extern std::initializer_list<Gem> Gems;
void printGems(std::ostream& f = cout);

class PlateauGem{
private:
    int vert;
    int rouge;
    int bleu;
    int blanc;
    int noir;
    int dore;
public:
    PlateauGem(int v=0,int r=0,int bleu=0,int blanc=0,int n=0 ,int d=0):vert(v),rouge(r),bleu(bleu),blanc(blanc),noir(n),dore(d){}
    void ajouter (int v=0,int r=0,int bbleu=0,int bblanc=0,int n=0 ,int d=0);
    void retirer(int v=0,int r=0,int bbleu=0,int bblanc=0,int n=0 ,int d=0);
    friend class Plateau;

    int getvert ()const {return vert;}
    int getrouge()const {return rouge;}
    int getbleu()const {return bleu;}
    int getblanc()const {return blanc;}
    int getnoir()const {return noir;}
    int getdore()const {return dore;}

};

//【玩家拥有宝石】类型定义
class JoueurGems{
private:
    int vert;
    int rouge;
    int bleu;
    int blanc;
    int noir;
    int dore;
public:
    JoueurGems(int v=0,int r=0,int bleu=0,int blanc=0,int n=0 ,int d=0):vert(v),rouge(r),bleu(bleu),blanc(blanc),noir(n),dore(d){}
    int get_sumGem()const {return (vert+rouge+blanc+bleu+noir+dore);}
    void ajouter (int v=0,int r=0,int bbleu=0,int bblanc=0,int n=0 ,int d=0);
    void retirer(int v=0,int r=0,int bbleu=0,int bblanc=0,int n=0 ,int d=0);

    int getvert ()const {return vert;}
    int getrouge()const {return rouge;}
    int getbleu()const {return bleu;}
    int getblanc()const {return blanc;}
    int getnoir()const {return noir;}
    int getdore()const {return dore;}



};



#endif //UNTITLED_GEM_H
