//carte_merde
//
// Created by SLP-SUMHS on 2021/10/27.
//

#include "cartes.h"
#include "gem.h"
#include "splendor.h"

ToutesLesCartesDeveloppees::ToutesLesCartesDeveloppees(){
    pre_cartes=new CarteDeveloppee[40]{
            {1,'W',0,0,4,0,0},    {1,'U',0,0,0,4,0},    {1,'G',0,0,0,0,4},    {1,'R',4,0,0,0,0},    {1,'B',0,4,0,0,0},
            {0,'W',0,3,0,0,0},    {0,'U',0,0,0,0,3},    {0,'G',0,0,0,3,0},    {0,'R',3,0,0,0,0},    {0,'B',0,0,3,0,0},
            {0,'W',0,0,0,2,1},    {0,'U',1,0,0,0,2},    {0,'G',2,1,0,0,0},    {0,'R',0,2,1,0,0},    {0,'B',0,0,2,1,0},
            {0,'W',0,1,1,1,1},    {0,'U',1,0,1,1,1},    {0,'G',1,1,0,1,1},    {0,'R',1,1,1,0,1},    {0,'B',1,1,1,1,0},
            {0,'W',0,2,0,0,2},    {0,'U',0,0,2,0,2},    {0,'G',0,2,0,2,0},    {0,'R',2,0,0,2,0},    {0,'B',2,0,2,0,0},
            {0,'W',0,2,2,0,1},    {0,'U',1,0,2,2,0},    {0,'G',0,1,0,2,2},    {0,'R',2,0,1,0,2},    {0,'B',2,2,0,1,0},
            {0,'W',0,1,2,1,1},    {0,'U',1,0,1,2,1},    {0,'G',1,1,0,1,2},    {0,'R',2,1,1,0,1},    {0,'B',1,2,1,1,0},
            {0,'W',3,1,0,0,1},    {0,'U',0,1,3,1,0},    {0,'G',1,3,1,0,0},    {0,'R',3,1,0,0,1},    {0,'B',1,0,0,1,3}
            //W:白色  U：蓝色  G：绿色  R：红色  B：黑色
    };

////洗牌////////
    vector<CarteDeveloppee> vec1;
    for (int i = 0; i < 40; i++) vec1.push_back(pre_cartes[i]);
    int n1 = vec1.size();
    if (n1 <= 0)
        throw CarteException("\nBad shuffle.\n");
    srand(time(0));

    for (int i = 0; i < n1; i++) {
        //保证每次第i位的值不会涉及到第i位以前
        //int index = i + rand() % (n1 - i);
        int index;
        if(Remember.empty()||isremenber==0) {
             index = i + rand() % (n1 - i);
            to2File(to_string(index));
        }
        else
        {string sss = getremember();
            index = atoi(sss.c_str());
            }
        swap(vec1[index], vec1[i]);
    }

    int i=0;
    for (vector<CarteDeveloppee>::iterator it=vec1.begin(); it!=vec1.end(); ++it){
        pre_cartes[i]=*it;
        i++;
    }
    vector<CarteDeveloppee>().swap(vec1);


    sec_cartes=new CarteDeveloppee[30]{
            {3,'W',6,0,0,0,0},    {3,'U',0,6,0,0,0},    {3,'G',0,0,6,0,0},    {3,'R',0,0,0,6,0},    {3,'B',0,0,0,0,6},
            {2,'W',0,0,0,5,0},    {2,'U',0,5,0,0,0},    {2,'G',0,0,5,0,0},    {2,'R',0,0,0,0,5},    {2,'B',5,0,0,0,0},
            {2,'W',0,0,0,5,3},    {2,'U',5,3,0,0,0},    {2,'G',0,5,3,0,0},    {2,'R',3,0,0,0,5},    {2,'B',0,0,5,3,0},
            {2,'W',0,0,1,4,2},    {2,'U',2,0,0,1,4},    {2,'G',4,2,0,0,1},    {2,'R',1,4,2,0,0},    {2,'B',0,1,4,2,0},
            {1,'W',0,0,3,2,2},    {1,'U',0,2,2,3,0},    {1,'G',2,3,0,0,2},    {1,'R',2,0,0,2,3},    {1,'B',3,2,2,0,0},
            {1,'W',2,3,0,3,0},    {1,'U',0,2,3,0,3},    {1,'G',3,0,2,3,0},    {1,'R',0,3,0,2,3},    {1,'B',3,0,3,0,2}
    };

//    //洗牌////////
    vector<CarteDeveloppee> vec2;
    for (int i = 0; i < 30; i++) vec2.push_back(sec_cartes[i]);
    int n2 = vec2.size();
    if (n2 <= 0)
        throw CarteException("\nBad shuffle.\n");

    for (int i = 0; i < n2; i++) {
        //保证每次第i位的值不会涉及到第i位以前
        //int index = i + rand() % (n2 - i);
        int index;
        if(Remember.empty()||isremenber==0) {
            index = i + rand() % (n2 - i);
            to2File(to_string(index));
        }
        else
        {string sss = getremember();
            index = atoi(sss.c_str());
        }
        swap(vec2[index], vec2[i]);
    }

    int j=0;
    for (auto & it : vec2){
        sec_cartes[j]=it;
        j++;
    }
    vector<CarteDeveloppee>().swap(vec2);



    tro_cartes=new CarteDeveloppee[20]{
            {5,'W',3,0,0,0,7},    {5,'U',7,3,0,0,0},    {5,'G',0,7,3,0,0},    {5,'R',0,0,7,3,0},    {5,'B',0,0,0,7,3},
            {4,'W',0,0,0,0,7},    {4,'U',7,0,0,0,0},    {4,'G',0,7,0,0,0},    {4,'R',0,0,7,0,0},    {4,'B',0,0,0,7,0},
            {4,'W',3,0,0,3,6},    {4,'U',6,3,0,0,3},    {4,'G',3,6,3,0,0},    {4,'R',0,3,6,3,0},    {4,'B',0,0,3,6,3},
            {3,'W',0,3,3,5,3},    {3,'U',3,0,3,3,5},    {3,'G',5,3,0,3,3},    {3,'R',3,5,3,0,3},    {3,'B',3,3,5,3,0}
    };

//    //洗牌////////
    vector<CarteDeveloppee> vec3;
    for (int i = 0; i < 20; i++) vec3.push_back(tro_cartes[i]);
    int n3 = vec3.size();
    if (n3 <= 0)
        throw CarteException("\nBad shuffle.\n");

    for (int i = 0; i < n3; i++) {
        //保证每次第i位的值不会涉及到第i位以前
        //int index = i + rand() % (n3 - i);
        int index;
        if(Remember.empty()||isremenber==0) {
            index = i + rand() % (n3 - i);
            to2File(to_string(index));
        }
        else
        {string sss = getremember();
            index = atoi(sss.c_str());
        }
        swap(vec3[index], vec3[i]);
    }

    int k=0;
    for (auto & it : vec3){
        tro_cartes[k]=it;
        k++;
    }
    vector<CarteDeveloppee>().swap(vec3);

}

ToutesLesCartesDeveloppees::~ToutesLesCartesDeveloppees(){
    delete [] pre_cartes;
    delete [] sec_cartes;
    delete [] tro_cartes;

}



//ToutesLesCartesDeveloppees* ToutesLesCartesDeveloppees::Developpees= nullptr;



ToutesLesCartesNobiliaires::ToutesLesCartesNobiliaires(){
    carte_nobiliaire=new CarteNobiliaire[10]{
            {3,0,3,3,3,0},      {3,3,0,0,3,3},       {3,0,0,3,3,3},      {3,0,4,4,0,0},     {3,3,3,0,0,3},
            {3,4,0,0,0,4},      {3,4,4,0,0,0},       {3,0,0,4,4,0},      {3,0,0,0,4,4},     {3,3,3,3,0,0}
    };

    //    //洗牌////////
    vector<CarteNobiliaire> vec;
    for (int i = 0; i < 10; i++) vec.push_back(carte_nobiliaire[i]);
    int n = vec.size();
    if (n <= 0)
        throw CarteException("\nBad shuffle.\n");

    for (int i = 0; i < n; i++) {
        //保证每次第i位的值不会涉及到第i位以前
        //int index = i + rand() % (n - i);
        int index;
        if(Remember.empty()||isremenber==0) {
            index = i + rand() % (n - i);
            to2File(to_string(index));
        }
        else
        {string sss = getremember();
            index = atoi(sss.c_str());
        }
        swap(vec[index], vec[i]);
    }

    int j=0;
    for (auto & it : vec){
        carte_nobiliaire[j]=it;
        j++;
    }
    vector<CarteNobiliaire>().swap(vec);

//    vector<CarteNobiliaire> c_n;
//    for (int i = 0;i<10;i++) c_n.push_back(carte_nobiliaire[i]);
//    random_shuffle(c_n.begin(),c_n.end());
//    int k=0;
//    for (vector<CarteNobiliaire>::iterator it=c_n.begin(); it!=c_n.end(); ++it){
//        carte_nobiliaire[k]=*it;
//        k++;
//    }

}

ToutesLesCartesNobiliaires::~ToutesLesCartesNobiliaires(){
    delete [] carte_nobiliaire;
}


ToutesLesCartesNobiliaires* ToutesLesCartesNobiliaires::Nobiliaires= nullptr;
ToutLesCarteCity* ToutLesCarteCity::City = nullptr;

ToutLesCarteCity::ToutLesCarteCity() {
    carte_city=new CarteCity[14]{
            {13,0,3,4,0,0,0},      {14,0,0,4,0,0,4},       {11,3,3,0,3,3,0},      {11,3,0,3,3,3,0},     {13,3,4,0,0,0,0},
            {13,4,0,0,3,0,0},      {17,0,0,0,0,0,0},       {16,1,1,1,1,1,0},      {13,0,0,0,4,3,0},     {13,0,0,3,0,4,0},
            {14,2,1,1,2,2,0},      {13,2,2,2,2,2,0},       {15,0,0,0,0,0,5},      {12,0,0,0,0,0,6}
    };

    //    //洗牌////////
    vector<CarteCity> vec;
    for (int i = 0; i < 14; i++) vec.push_back(carte_city[i]);
    int n = vec.size();
    if (n <= 0)
        throw CarteException("\nBad shuffle.\n");
    srand(time(0));

    for (int i = 0; i < n; i++) {
        //保证每次第i位的值不会涉及到第i位以前
        //int index = i + rand() % (n - i);
        int index;
        if(Remember.empty()||isremenber==0) {
            index = i + rand() % (n - i);
            to2File(to_string(index));
        }
        else
        {string sss = getremember();
            index = atoi(sss.c_str());
        }
        swap(vec[index], vec[i]);
    }

    int j=0;
    for (auto & it : vec){
        carte_city[j]=it;
        j++;
    }
    vector<CarteCity>().swap(vec);
}

ToutLesCarteCity::~ToutLesCarteCity() {
    delete [] carte_city;
}
//void ToutesLesCartesNobiliaires::shuffle() {
//    vector<CarteNobiliaire> vec1;
//    for (int i = 0; i < 40; i++) vec1.push_back(carte_nobiliaire[i]);
//    int n1 = vec1.size();
//    if (n1 <= 0)
//        throw CarteException("\nBad shuffle.\n");
//    srand(time(0));
//
//    for (int i = 0; i < n1; i++) {
//        //保证每次第i位的值不会涉及到第i位以前
//        int index = i + rand() % (n1 - i);
//        swap(vec1[index], vec1[i]);
//    }
//
//    int i=0;
//    for (vector<CarteNobiliaire>::iterator it=vec1.begin(); it!=vec1.end(); ++it){
//        carte_nobiliaire[i]=*it;
//        i++;
//    }
//    vector<CarteNobiliaire>().swap(vec1);
//
//
//}

bool CarteDeveloppee::operator!=(CarteDeveloppee &c) {
    if (this->bonus != c.bonus && this->noir != c.noir && this->bleu != c.bleu && this->blanc != c.blanc && this->rouge != c.rouge && this->vert != c.vert && this->prestige != c.prestige)
        return true;
    else
        return false;
}

string CarteDeveloppee::getbonus_string() const {

    //W:白色  U：蓝色  G：绿色  R：红色  B：黑色

    if(getBonus()=='W') return "Blanc";
    if(getBonus()=='U') return "Blue ";
    if(getBonus()=='G') return "Vert ";
    if(getBonus()=='R') return "Rouge";
    if(getBonus()=='B') return "Noir ";
    return "NONO~";
}

void CarteDeveloppee::afficher() const {

    cout<<"|  -------------------------  |";
    cout<<endl;
    cout<<"|  || Pres:"<<getPrestige()<<"  Bonus: "<<getbonus_string()<<"||  |";
    cout<<endl;
    cout<<"|  ||                     ||  |";
    cout<<endl;
    cout<<"|  ||                     ||  |";
    cout<<endl;
    cout<<"|  || Blanc:  "<<getblanc()<<"           ||  |";
    cout<<endl;
    cout<<"|  || Blue:   "<<getBleu() <<"           ||  |";
    cout<<endl;
    cout<<"|  || Vert:   "<<getVert() <<"           ||  |";
    cout<<endl;
    cout<<"|  || Rouge:  "<<getRouge()<<"           ||  |";
    cout<<endl;
    cout<<"|  || Noir:   "<<getnoir()<<"           ||  |";
    cout<<endl;
    cout<<"|  -------------------------  |";
    cout<<endl;

    cout<<"|                             |";
    cout<<endl;
    cout<<"|                             |";
    cout<<endl;
}


void CarteNobiliaire::afficher() const {

    cout<<"*  -------------------------  *";
    cout<<endl;
    cout<<"*  || Pres: "<<getPrestige()<<"             ||  *";
    cout<<endl;
    cout<<"*  ||                     ||  *";
    cout<<endl;
    cout<<"*  ||      Nobiliaire     ||  *";
    cout<<endl;
    cout<<"*  ||                     ||  *";
    cout<<endl;
    cout<<"*  || Blanc:  "<<getblanc()<<"           ||  *";
    cout<<endl;
    cout<<"*  || Blue:   "<<getBleu() <<"           ||  *";
    cout<<endl;
    cout<<"*  || Vert:   "<<getVert() <<"           ||  *";
    cout<<endl;
    cout<<"*  || Rouge:  "<<getRouge()<<"           ||  *";
    cout<<endl;
    cout<<"*  || Noir:   "<<getnoir() <<"           ||  *";
    cout<<endl;
    cout<<"*  -------------------------  *";
    cout<<endl;

    cout<<"*                             *";
    cout<<endl;
    cout<<"*                             *";
    cout<<endl;

}

void CarteCity::afficher() const {
    cout<<"*  -------------------------  *";
    cout<<endl;
    cout<<"*  || Pres: "<<getPrestige()<<"            ||  *";
    cout<<endl;
    cout<<"*  ||                     ||  *";
    cout<<endl;
    cout<<"*  ||         CITY        ||  *";
    cout<<endl;
    cout<<"*  ||                     ||  *";
    cout<<endl;
    cout<<"*  || Blanc:    "<<getblanc()<<"         ||  *";
    cout<<endl;
    cout<<"*  || Blue:     "<<getBleu() <<"         ||  *";
    cout<<endl;
    cout<<"*  || Vert:     "<<getVert() <<"         ||  *";
    cout<<endl;
    cout<<"*  || Rouge:    "<<getRouge()<<"         ||  *";
    cout<<endl;
    cout<<"*  || Noir:     "<<getnoir() <<"         ||  *";
    cout<<endl;
    cout<<"*  || SameGem:  "<<getsame() <<"         ||  *";
    cout<<endl;
    cout<<"*  -------------------------  *";
    cout<<endl;

    cout<<"*                             *";
    cout<<endl;
    cout<<"*                             *";
    cout<<endl;
}
