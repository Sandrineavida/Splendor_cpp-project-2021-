//
// Created by huawei on 2021/10/24.
//

#include "splendor.h"
int isremenber=0;
 string Remember;

void Controleur::Commencer_Game() {
    int judnp=1;
    string np;
    while(judnp==1){
        std::cout<<"Please enter the number of Players(2/3/4)(including Human Players and AI Player(s)): "<<std::endl;
        if(Remember.empty()||isremenber==0)
        { cin>>np;
        to2File(np);
        }
        else
        {string sss = getremember();
            np = sss;
        }
        if(np!="2"&&np!="3"&&np!="4") {
            cout<<"\n[You need to enter a valid number.]\n\n";
        }
        else {judnp=0;}
    }
    if(np=="2") nb_joueur=2;
    else if(np=="3") nb_joueur=3;
    else if(np=="4") nb_joueur=4;

    int judnai=1;
    string nai;
    while(judnai==1){
        std::cout<<"Please enter the number of AI Player(s) (>=0,<="<<nb_joueur<<")"<<std::endl;
        if(Remember.empty()||isremenber==0)
        { cin>>nai;
            to2File(nai);
        }
        else
        {string sss = getremember();
            nai = sss;
        }
        if(nai!="0"&&nai!="1"&&nai!="2"&&nai!="3"&&nai!="4") {
            cout<<"\n[You need to enter a valid number.]\n\n";
        }
        else {
            if(nai=="0") nb_joueurAI=0;
            else if(nai=="1") nb_joueurAI=1;
            else if(nai=="2") nb_joueurAI=2;
            else if(nai=="3") nb_joueurAI=3;
            else if(nai=="4") nb_joueurAI=4;
            if(nb_joueur>=nb_joueurAI)judnai=0;
            else judnai=1;
        }
    }

//    std::cin>>nb_joueur;
//    std::cout<<"Veuillez entrer le nombre de joueursAI(>=0,<="<<nb_joueur<<")"<<std::endl;
//    std::cin>>nb_joueurAI;
    Plateau plateau1(nb_joueur);
    plateau = &plateau1;
//    plateau->TCN.shuffle();
//    plateau->set_carte_nob();

    nb_joueur = nb_joueur-nb_joueurAI;
    if (nb_joueurAI>0) AIj = new AIJ[nb_joueurAI];
    if (nb_joueur>0) joueurs = new Joueur[nb_joueur];


    cout<<"\nNow we have "<<nb_joueur<<" Human Player(s) and "<<nb_joueurAI<<" AI Player(s).\n";
    for(int i = 0;i<nb_joueur;i++)
    {
        std::cout<<"\nPlease enter the name of player N.["<<(i+1)<<"]:"<<std::endl;
        string s;
        if(Remember.empty()||isremenber==0)
        { cin>>s;
            to2File(s);
        }
        else
        {string sss = getremember();
            s = sss;
        }
        for(int j = 0;j<i;j++)
        {
            while(s==joueurs[j].getName())
            {
                //throw SplendorException("Le nom existe déjà");
                std::cout<<"\nPlease enter the name of player N.["<<(i+1)<<"]:"<<std::endl;
                if(Remember.empty()||isremenber==0)
                { cin>>s;
                    to2File(s);
                }
                else
                {string sss = getremember();
                    s = sss;
                }
            }
        }
        joueurs[i].setName(s);//玩家姓名注册
        std::cout<<"\nPlease enter the birthday of player N.["<<(i+1)<<"] (eg:20010726):"<<std::endl;
        int b;
        //std::cin>>b;
        if(Remember.empty()||isremenber==0) {
            cin>>b;
            to2File(to_string(b));
        }
        else
        {string sss = getremember();
            b = atoi(sss.c_str());
        }
        joueurs[i].setbirthday(b);
    }
    for(int i=0; i<nb_joueur; i++){
        for(int j=0; j<nb_joueur-1; j++){
            if(joueurs[j].getbirthday() < joueurs[j+1].getbirthday()){
                Joueur temp;
                temp = joueurs[j];
                joueurs[j] = joueurs[j+1];
                joueurs[j+1] = temp;
            }
        }
    }




    int fois=0;//回合数
    while (Flag != true )
    {
        fois++;//每一回合！
        std::cout<<"\n[Round:"<<fois<<"]\n"<<std::endl;
//        cout<<"GEM:\n    v=vert  r=rouge  u=bleu  c=blanc  n=noir  d=doré"<<endl;


        for(int i = 0;i<nb_joueur;i++)
        {

            cout<<"Comportement valide:"<<endl;
            cout<<"Entrer 1 pour choisir 3 pierres precieuses du type different."<<endl;
            cout<<"Entrer 2 pour choisir 2 pierres precieuses du meme type."<<endl;
            cout<<"Entrer 3 pour louer une carte developpee."<<endl;
            cout<<"Entrer 4 pour acheter une carte developpee. "<<endl;
            cout<<"Entrer 5 pour acheter une carte louee.\n"<<endl;

            cout<<"[Cartes Developees:]\n";
            plateau->afficher_cartes_dev3();
            plateau->afficher_cartes_dev2();
            plateau->afficher_cartes_dev1();
            cout<<"[Cartes Nobiliaires:]\n";
            plateau->afficher_noble();
            cout<<"[Pierres presieuses:]\n";
            plateau->afficher_Gem();

            int cmptmt = 0;
            std::cout<<"\n"<<"["<<joueurs[i].getName()<<"],it's your turn.\n"<<std::endl;
            cout<<"Now you have:\n";
            joueurs[i].afficher_prestige();
            joueurs[i].afficher_Gem();
            joueurs[i].afficher_Bonus();

            joueurs[i].afficher_number_cl();
            joueurs[i].afficher_Carte_louee();
            joueurs[i].afficher_number_cn();
            joueurs[i].afficher_Carte_Nob();
            joueurs[i].afficher_number_cd();
            int judjud = 1;
            while(judjud == 1){//如果用户没有按照要求输入y/Y/n/N
                cout<<"\nVous voulez afficher vos cartes developpees?(y/Y/n/N):";
                string yn ;
                //cin >> yn;
                if(Remember.empty()||isremenber==0)
                { cin>>yn;
                    to2File(yn);
                }
                else
                {string sss = getremember();
                    yn = sss;
                }
                if(yn == "n" || yn == "N")
                {
                    judjud = 0;
                }
                else if(yn == "y"|| yn =="Y")
                {
                    joueurs[i].afficher_Carte_Dev();
                    judjud=0;
                }

                if(judjud==1) cout<<"\nYou need to enter(y/Y/n/N).\n";
            }

            int jud=1;//有错（输入的动作选择）
            while(jud == 1) {
                try {
                    processus(i, &joueurs[i]);
                    jud = 0;
                }
                catch (SplendorException &se) {
                    cout << se.getInfo();
                    jud = 1;
                }
            }


            ajouterNob( &joueurs[i]);
            if(joueurs[i].get_prestige()>=15)
                Flag = true;

            //update the state of the human player
            cout<<"\nNow you have:\n";
            joueurs[i].afficher_prestige();
            joueurs[i].afficher_Gem();
            joueurs[i].afficher_Bonus();

            joueurs[i].afficher_number_cl();
            joueurs[i].afficher_Carte_louee();
            joueurs[i].afficher_number_cn();
            joueurs[i].afficher_Carte_Nob();
            joueurs[i].afficher_number_cd();
            judjud = 1;
            while(judjud == 1){//如果用户没有按照要求输入y/Y/n/N
                cout<<"\nVous voulez afficher vos cartes developpees?(y/Y/n/N):";
                string yn ;
                //cin >> yn;
                if(Remember.empty()||isremenber==0)
                { cin>>yn;
                    to2File(yn);
                }
                else
                {string sss = getremember();
                    yn = sss;
                }
                if(yn == "n" || yn == "N")
                {
                    judjud = 0;
                }
                else if(yn == "y"|| yn =="Y")
                {
                    joueurs[i].afficher_Carte_Dev();
                    judjud=0;
                }

                if(judjud==1) cout<<"\nYou need to enter(y/Y/n/N).\n";
            }

            system("PAUSE");

        }
        for(int i = 0;i<nb_joueurAI;i++)
        {
            cout<<"[Cartes Developees:]\n";
            plateau->afficher_cartes_dev3();
            plateau->afficher_cartes_dev2();
            plateau->afficher_cartes_dev1();
            cout<<"[Cartes Nobiliaires:]\n";
            plateau->afficher_noble();
            cout<<"[Pierres presieuses:]\n";
            plateau->afficher_Gem();
            int cmptmt = 0;
            //std::cout<<joueurs[i].getName()<<",it's your turn."<<std::endl;
            cout<<"Now AI "<<i<<" have:\n";
            AIj[i].afficher_prestige();
            AIj[i].afficher_Gem();
            AIj[i].afficher_Bonus();

            AIj[i].afficher_number_cl();
            AIj[i].afficher_Carte_louee();
            AIj[i].afficher_number_cn();
            AIj[i].afficher_Carte_Nob();
            AIj[i].afficher_number_cd();

            AIj[i].afficher_Carte_Dev();

            int jud=1;//有错（输入的动作选择）
            while(jud == 1) {
                try {
                    processusAI(&AIj[i]);
                    jud = 0;
                }
                catch (SplendorException &se) {
                    cout << se.getInfo();
                    jud = 1;
                }
            }


            ajouterNobAI( &AIj[i]);
            if(AIj[i].get_prestige() >= 15)
                Flag = true;
            cout<<"Now AI "<<i<<" have:\n";
            AIj[i].afficher_prestige();
            AIj[i].afficher_Gem();
            AIj[i].afficher_Bonus();

            AIj[i].afficher_number_cl();
            AIj[i].afficher_Carte_louee();
            AIj[i].afficher_number_cn();
            AIj[i].afficher_Carte_Nob();
            AIj[i].afficher_number_cd();

            AIj[i].afficher_Carte_Dev();
        }
//        int Hong = plateau->plateaugem.getrouge();int lu = plateau->plateaugem.getvert();int bai = plateau->plateaugem.getblanc();
//        int lan = plateau->plateaugem.getbleu();int hei = plateau->plateaugem.getnoir();
//        for(int i = 0;i<nb_joueurAI;i++)
//        {
//            Hong += AIj[i].joueur_gem.getrouge();lu += AIj[i].joueur_gem.getvert(); bai += AIj[i].joueur_gem.getblanc();
//            lan += AIj[i].joueur_gem.getbleu();hei += AIj[i].joueur_gem.getnoir();
//        }


    }
    int max_p = 0;//最大声望值
    int winner = 0;//winner的位置
    int winnerai = 0;
    for(int i = 0;i<nb_joueur;i++)
    {
        if(joueurs[i].get_prestige()>max_p)
        {
            max_p = joueurs[i].get_prestige();
            winner = i;
        }
        else if(joueurs[i].get_prestige()==max_p)
        {
            if(joueurs[i].getNB_D()<joueurs[winner].getNB_D())
                winner = i;
        }
    }
    max_p = 0;
    for(int i = 0;i<nb_joueurAI;i++)
    {
        if(AIj[i].get_prestige()>max_p)
        {
            max_p = AIj[i].get_prestige();
            winnerai = i;
        }
        else if((AIj[i].get_prestige()) == max_p)
        {
            if(AIj[i].getNB_D()<AIj[winnerai].getNB_D())
                winnerai = i;
        }
    }
    if(nb_joueurAI!=0 && nb_joueur!=0)
    {
        if((AIj[winnerai].get_prestige())<(joueurs[winner].get_prestige()))
        {
            std::cout<<"Felicitations "<<joueurs[winner].getName()<<"! Vous avez gagne!"<<std::endl;
        }
        else if(AIj[winnerai].get_prestige()==joueurs[winner].get_prestige())
        {
            if(AIj[winnerai].getNB_D()>joueurs[winner].getNB_D())
                std::cout<<"Felicitations "<<joueurs[winner].getName()<<"! Vous avez gagne!"<<std::endl;
            else
                std::cout<<"Felicitations AI"<<winnerai<<"! Vous avez gagne!"<<std::endl;
        }
        else
            std::cout<<"Felicitations AI"<<winnerai<<"! Vous avez gagne!"<<std::endl;
    }
    else if(nb_joueur==0)
        {std::cout<<"Felicitations AI"<<winnerai<<"! Vous avez gagne!"<<std::endl;}
    else
        std::cout<<"Felicitations "<<joueurs[winner].getName()<<"! Vous avez gagne!"<<std::endl;

}
void Controleur::ajouterNobAI(Joueur* j) {
    bool flagN = false;
    int okk = 0;
    int jasa = j->get_Develope_Gem_U();
    int okkN[plateau->nbNob];
    for (int ppp = 0;ppp<plateau->nbNob; ppp++){
        okkN[ppp]=0;
    }
    for(int i=0; i<plateau->nbNob;i++)
    {
        if(j->get_Develope_Gem_B()>=plateau->pCarteNobiliaire[i].getnoir() &&
           j->get_Develope_Gem_W()>=plateau->pCarteNobiliaire[i].getblanc() &&
           j->get_Develope_Gem_R()>=plateau->pCarteNobiliaire[i].getRouge() &&
           j->get_Develope_Gem_G()>=plateau->pCarteNobiliaire[i].getVert() &&
           j->get_Develope_Gem_U()>=plateau->pCarteNobiliaire[i].getBleu())
        {
            int jasa = j->get_Develope_Gem_U();
            okkN[i] = 1;
            flagN = true;
            okk++;
        }
    }
    if (flagN)
    {
        std::cout<<"Veuillez selectionner l'une des " <<okk<< " cartes suivantes"<<std::endl;
        for(int i=0; i<plateau->nbNob;i++) {
            if (okkN[i] == 1)
            {
                    j->ajouter_CarteNobiliaire(plateau->pCarteNobiliaire[i]);
                    // std::cout<<"vous obtenez"<<plateau->pCarteNobiliaire[i];
                    plateau->retirerCartesNobiliaire(i);
                break;
            }
        }

    }

}
void Controleur::ajouterNob(Joueur* j) {
    bool flagN = false;
    int okk = 0;
    int okkN[plateau->nbNob];
    for (int ppp = 0;ppp<plateau->nbNob; ppp++){
        okkN[ppp]=0;
    }
    for(int i=0; i<plateau->nbNob;i++)
    {
        if(j->get_Develope_Gem_B()>=plateau->pCarteNobiliaire[i].getnoir() &&
            j->get_Develope_Gem_W()>=plateau->pCarteNobiliaire[i].getblanc() &&
            j->get_Develope_Gem_R()>=plateau->pCarteNobiliaire[i].getRouge() &&
            j->get_Develope_Gem_G()>=plateau->pCarteNobiliaire[i].getVert() &&
            j->get_Develope_Gem_U()>=plateau->pCarteNobiliaire[i].getBleu())
        {
            okkN[i] = 1;
            flagN = true;
            okk++;
        }
    }
        if (flagN)
        {
            std::cout<<"Veuillez selectionner l'une des " <<okk<< " cartes suivantes"<<std::endl;
            for(int i=0; i<plateau->nbNob;i++) {
                if (okkN[i] == 1)
                {
                    std::cout<<"carte N."<<i+1<<endl;
                    plateau->pCarteNobiliaire[i].afficher();//打印牌
                     if(okk == 1){
                         j->ajouter_CarteNobiliaire(plateau->pCarteNobiliaire[i]);
                         // std::cout<<"vous obtenez"<<plateau->pCarteNobiliaire[i];
                         plateau->retirerCartesNobiliaire(i);
                     }
                }
            }
            if(okk != 1 && flagN)
            {
                std::cout<<"Quelles cartes choisissez-vous?"<<"\n";
                int chois;
                //std::cin>>chois;
                if(Remember.empty()||isremenber==0) {
                    cin>>chois;
                    to2File(to_string(chois));
                }
                else
                {string sss = getremember();
                    chois = atoi(sss.c_str());
                }
                j->ajouter_CarteNobiliaire(plateau->pCarteNobiliaire[chois]);
                // std::cout<<"vous obtenez"<<plateau->pCarteNobiliaire[chois];
                plateau->retirerCartesNobiliaire(chois);
            }
        }

}






void Controleur::retirer3Gem_diff(char g1,char g2,char g3,Joueur* jr){
//    if(jr->getNbJoueurGem()==10) throw SplendorException("\nComportement invalide! Vous avez deja 10 pierres precieuses.\n");
    if(g1 == g2||g1 == g3||g2 == g3) throw SplendorException("\n[ Vous devez choisir 3 differentes pierres precieuses. ]\n");



    if(g1!='v'&&g1!='r'&&g1!='u'&&g1!='c'&&g1!='n')throw SplendorException("\n[ You need to enter 3 valid letters. ]\n");
    if(g2!='v'&&g2!='r'&&g2!='u'&&g2!='c'&&g2!='n')throw SplendorException("\n[ You need to enter 3 valid letters. ]\n");
    if(g3!='v'&&g3!='r'&&g3!='u'&&g3!='c'&&g3!='n')throw SplendorException("\n[ You need to enter 3 valid letters. ]\n");

    int v=0,r=0,bbleu=0,bblanc=0,n=0;
    if (g1 == 'v'||g2 == 'v'||g3 == 'v') {
        if(plateau->plateaugem.getvert()==0) {cout<<"\n[ No green gem accessible. ]\n";}
        else {v=1;}
    }
    if (g1 == 'r'||g2 == 'r'||g3 == 'r') {
        if(plateau->plateaugem.getrouge()==0) {cout<<"\n[ No red gem accessible. ]\n";}
        else {r=1;}
    }
    if (g1 == 'u'||g2 == 'u'||g3 == 'u') {
        if(plateau->plateaugem.getbleu()==0) {cout<<"\n[ No blue gem accessible. ]\n";}
        else {bbleu=1;}
    }
    if (g1 == 'c'||g2 == 'c'||g3 == 'c') {
        if(plateau->plateaugem.getblanc()==0) {cout<<"\n[ No diamond(blanc) accessible. ]\n";}
        else {bblanc=1;}
    }
    if (g1 == 'n'||g2 == 'n'||g3 == 'n') {
        if(plateau->plateaugem.getnoir()==0) {cout<<"\n[ No black gem accessible. ]\n";}
        else {n=1;}
    }

    plateau->retirerGem3(g1,g2,g3);//如果玩家想选择的3种宝石都无了，就抛出异常到processus上级，让玩家从新选择动作
    jr->ajouter_Gem(v,r,bbleu,bblanc,n);

    int playergem = jr->getNbJoueurGem();

    if(playergem==8+3){
        int jud=1;
        while(jud==1){
            try{
                cout << "Vous devez rendre 1 pierre." << endl;
                cout << "GEM:\n    c=blanc  u=bleu  v=vert  r=rouge  n=noir " << endl;
                cout << "Entrez 1 char: ";
                string g;
                //cin >> g;
                if(Remember.empty()||isremenber==0)
                { cin>>g;
                    to2File(g);
                }
                else
                {string sss = getremember();
                    g = sss;
                }
                int v = 0, r = 0, bbleu = 0, bblanc = 0, n = 0;
                if (g == "v") { v = 1; }
                else if (g == "r") { r = 1; }
                else if (g == "u") { bbleu = 1; }
                else if (g == "c") { bblanc = 1; }
                else if (g == "n") { n = 1; }
                jr->retirer_Gem(v, r, bbleu, bblanc, n);//玩家宝石溢出
                jud=0;
            }
            catch(SplendorException& se){
                cout<<se.getInfo();
                jud=1;
            }
        }
        plateau->ajouterGem(v,r,bbleu,bblanc,n);//归还给桌面
    }
    else if(playergem==9+3){
        int jud=1;
        while(jud==1){
            try{
                cout<<"Vous devez rendre 2 pierres."<<endl;
                cout << "GEM:\n    c=blanc  u=bleu  v=vert  r=rouge  n=noir " << endl;
                cout<<"Entrez 2 char: ";
                char gg1,gg2;
                //cin>>gg1>>gg2;
                if(Remember.empty()||isremenber==0)
                {
                    cin>>gg1>>gg2;
                    string s23 = string(1,gg1)+string(1,gg2);
                    to2File(s23);
                }
                else
                {string sss = getremember();
                    string s23 = sss;
                    gg1 = s23[0];gg2 = s23[1];
                }
                int v=0,r=0,bbleu=0,bblanc=0,n=0;
                if (gg1 == 'v') {v++;}
                else if (gg1 == 'r') {r++;}
                else if (gg1 == 'u') {bbleu++;}
                else if (gg1 == 'c') {bblanc++;}
                else if (gg1 == 'n') {n++;}
                if (gg2 == 'v') {v++;}
                else if (gg2 == 'r') {r++;}
                else if (gg2 == 'u') {bbleu++;}
                else if (gg2 == 'c') {bblanc++;}
                else if (gg2 == 'n') {n++;}
                jr->retirer_Gem(v,r,bbleu,bblanc,n);//玩家宝石溢出
                jud=0;
            }
            catch(SplendorException& se){
                cout<<se.getInfo();
                jud=1;
            }
        }
        plateau->ajouterGem(v,r,bbleu,bblanc,n);//归还给桌面
    }

    cout<<"\n[Executed successfully.]\n";
//    plateau->afficher_Gem();
}

void Controleur::retirer2Gem_sim(char g, Joueur *jr) {//只有当该类宝石剩余数量大于2时才能执行此操作
//    if (jr->getNbJoueurGem() == 10)
//        throw SplendorException("\nComportement invalide! Vous avez deja 10 pierres precieuses.\n");
    if(g!='v'&&g!='r'&&g!='u'&&g!='c'&&g!='n')throw SplendorException("\n[ You need to enter A valid letter. ]\n");
    int v = 0, r = 0, bbleu = 0, bblanc = 0, n = 0;
    if (g == 'v') {
        if(plateau->plateaugem.getvert()<4)throw SplendorException("\n[ Not sufficient green gems. ]\n");
        else {v = 2;} }
    else if (g == 'r') { if(plateau->plateaugem.getrouge()<4)throw SplendorException("\n[ Not sufficient red gems. ]\n");
        else {r = 2;} }
    else if (g == 'u') { if(plateau->plateaugem.getbleu()<4)throw SplendorException("\n[ Not sufficient blue gems. ]\n");
        else {bbleu = 2;} }
    else if (g == 'c') { if(plateau->plateaugem.getblanc()<4)throw SplendorException("\n[ Not sufficient diamonds(blanc). ]\n");
        else {bblanc = 2;} }
    else if (g == 'n') {if(plateau->plateaugem.getnoir()<4)throw SplendorException("\n[ Not sufficient black gem. ]\n");
        else {n = 2;}}

    plateau->retirerGem2(g);
    jr->ajouter_Gem(v, r, bbleu, bblanc, n);
    int playergem = jr->getNbJoueurGem();
    if (playergem == 9 + 2) {
        int jud=1;
        while(jud==1){
            try{
                cout << "Vous devez rendre 1 pierre." << endl;
                cout << "GEM:\n    c=blanc  u=bleu  v=vert  r=rouge  n=noir " << endl;
                cout << "Entrez 1 char: ";
                char g;
                //cin >> g;
                if(Remember.empty()||isremenber==0)
                { cin>>g;
                    to2File(string(1,g));
                }
                else
                {string sss = getremember();
                    g = sss[0];
                }
                int v = 0, r = 0, bbleu = 0, bblanc = 0, n = 0;
                if (g == 'v') { v = 1; }
                else if (g == 'r') { r = 1; }
                else if (g == 'u') { bbleu = 1; }
                else if (g == 'c') { bblanc = 1; }
                else if (g == 'n') { n = 1; }
                jr->retirer_Gem(v, r, bbleu, bblanc, n);//玩家宝石溢出
                jud=0;
            }
            catch(SplendorException& se){
                cout<<se.getInfo();
                jud=1;
            }
        }

        plateau->ajouterGem(v,r,bbleu,bblanc,n);//归还给桌面
    }

    cout<<"\n[Executed successfully.]\n";
//    plateau->afficher_Gem();
}

void Controleur::louerCarteDev(int grade, int pos, Joueur *jr) {


    if(grade == 1){
        if(plateau->pCarteDeveloppee1[pos-1].isnullcartedev()) throw SplendorException("\nPas de Carte.\n");
        CarteDeveloppee cd1=plateau->retirerCartesDeveloppee1(pos);
        plateau->ajouterCartesDeveloppee1(pos-1);//为i位置的1级发展牌重新发牌
        if(jr->getNbJoueurGem()<10)
        {
            int d = plateau->retirerGold();
            jr->ajouter_Gem(0,0,0,0,0,d);

        }
        jr->ajouter_CarteDeveloppee_loue(cd1);
    }
    else if(grade == 2){
        if(plateau->pCarteDeveloppee2[pos-1].isnullcartedev()) throw SplendorException("\nPas de Carte.\n");
        CarteDeveloppee cd2=plateau->retirerCartesDeveloppee2(pos);
        plateau->ajouterCartesDeveloppee2(pos-1);//为i位置的2级发展牌重新发牌
        if(jr->getNbJoueurGem()<10)
        {
            jr->ajouter_Gem(0,0,0,0,0,plateau->retirerGold());

        }
        jr->ajouter_CarteDeveloppee_loue(cd2);
    }
    else if(grade == 3){
        if(plateau->pCarteDeveloppee3[pos-1].isnullcartedev()) throw SplendorException("\nPas de Carte.\n");
        CarteDeveloppee cd3=plateau->retirerCartesDeveloppee3(pos);
        plateau->ajouterCartesDeveloppee3(pos-1);//为i位置的3级发展牌重新发牌
        if(jr->getNbJoueurGem()<10)
        {
            jr->ajouter_Gem(0,0,0,0,0,plateau->retirerGold());

        }
        jr->ajouter_CarteDeveloppee_loue(cd3);
    }

    cout<<"\n[Executed successfully.]\n";

}

void Controleur::acheterCarteDev_plateau(int grade, int pos, Joueur *jr) {

    if(grade == 1){
        CarteDeveloppee cd1=plateau->retirerCartesDeveloppee1(pos);
        if(cd1.isnullcartedev())  throw SplendorException("\n[ There isn't any card. Try to do something else please. ]\n");
        if((!jr->isaffordable(cd1)) )  throw SplendorException("\n[ You cannot afford this card. Try to do something else please. ]\n");//判断是否买得起卡

        countergem( jr,cd1);
        jr->ajouter_CarteDeveloppee(cd1);//买得起就拿走这张卡
        plateau->ajouterCartesDeveloppee1(pos-1);//为i位置的1级发展牌重新发牌
    }
    else if(grade == 2){
        CarteDeveloppee cd2=plateau->retirerCartesDeveloppee2(pos);
        if(cd2.isnullcartedev())  throw SplendorException("\n[ There isn't any card. Try to do something else please. ]\n");
        if((!jr->isaffordable(cd2)))  throw SplendorException("\n[ You cannot afford this card. Try to do something else please. ]\n");
        countergem( jr,cd2);
        jr->ajouter_CarteDeveloppee(cd2);
        plateau->ajouterCartesDeveloppee2(pos-1);//为i位置的1级发展牌重新发牌
    }
    else if(grade == 3){
        CarteDeveloppee cd3=plateau->retirerCartesDeveloppee3(pos);
        if(cd3.isnullcartedev())  throw SplendorException("\n[ There isn't any card. Try to do something else please. ]\n");
        if((!jr->isaffordable(cd3)))  throw SplendorException("\n[ You cannot afford this card. Try to do something else please. ]\n");
        countergem( jr,cd3);
        jr->ajouter_CarteDeveloppee(cd3);
        plateau->ajouterCartesDeveloppee3(pos-1);//为i位置的1级发展牌重新发牌
    }

    cout<<"\n[Executed successfully.]\n";

}

void Controleur::acheterCarte_loue(Joueur *jr , int pos_c_l) {

    CarteDeveloppee cd1 = jr->get_CarteDeveloppee_loue(pos_c_l-1);
    if(cd1.isnullcartedev())  throw SplendorException("\n[ There isn't any card. Try to do something else please. ]\n");
    if(!jr->isaffordable(cd1))  throw SplendorException("\n[ You cannot afford this card. Try to do something else please. ]\n");

    countergem( jr,cd1);
    jr->acheter_CarteDeveloppee_loue(cd1,pos_c_l-1);

    cout<<"\n[Executed successfully.]\n";
}

void Controleur::processus(int i, Joueur *jr) {

    int cmptmt = 0;

    cout << "\nEntrez un nombre pour choisir un comportement:";
    //cin >> cmptmt;
    if(Remember.empty()||isremenber==0) {
        cin>>cmptmt;
        to2File(to_string(cmptmt));
    }
    else
    {string sss = getremember();
        cmptmt = atoi(sss.c_str());
    }
    cout << endl;

    if(jr->gethuiqi())
    {

        switch(cmptmt){
            case 1:
                cout << "Vous avez decide de  [choisir 3 pierres precieuses de 3 differents types]." << endl;
                break;
            case 2:
                cout << "Vous avez decide de [choisir 2 pierres precieuses du meme type]." << endl;
                break;
            case 3:
                cout << "Vous avez decide de [ louer une carte developpee ]." << endl;
                break;
            case 4:
                cout << "Vous avez decide d'[ acheter une carte developpee ]." << endl;
                break;
            case 5:
                cout << "Vous avez decide d'[ acheter une carte louee ]." << endl;
                break;
            default:
                throw SplendorException("Choix invalide.");
                break;
        }
        cout << "Are you sure?(You can only undo once):(Y/N)";
        int judjud = 1;
        while(judjud == 1){//如果用户没有按照要求输入y/Y/n/N
            string yn ;
            //cin >> yn;
            if(Remember.empty()||isremenber==0)
            { cin>>yn;
                to2File(yn);
            }
            else
            {string sss = getremember();
                yn = sss;
            }
            if(yn == "n" || yn == "N")
            {
                jr->sethuiqi();
                cout<<"Comportement valide:"<<endl;
                cout<<"Entrer 1 pour choisir 3 pierres precieuses du type different."<<endl;
                cout<<"Entrer 2 pour choisir 2 pierres precieuses du meme type."<<endl;
                cout<<"Entrer 3 pour louer une carte developpee."<<endl;
                cout<<"Entrer 4 pour acheter une carte developpee. "<<endl;
                cout<<"Entrer 5 pour acheter une carte louee.\n"<<endl;
                cout << "\nEntrez un nombre pour choisir un comportement:";
                //cin >> cmptmt;
                if(Remember.empty()||isremenber==0) {
                    cin>>cmptmt;
                    to2File(to_string(cmptmt));
                }
                else
                {string sss = getremember();
                    cmptmt = atoi(sss.c_str());
                }
                cout << endl;
                judjud = 0;
            }
            else if(yn == "y"|| yn =="Y")
            {judjud=0;}

            if(judjud==1) cout<<"\nYou need to enter(y/Y/n/N).\n";
        }

    }

    int jud = 1;

    switch (cmptmt) {
        case 1:
            cout << "Vous avez decide de  [choisir 3 pierres precieuses de 3 differents types]." << endl;
            if(jr->getNbJoueurGem()==10) throw SplendorException("\n[ Comportement invalide! Vous avez deja 10 pierres precieuses. ]\n");
            if(plateau->plateaugem.getnoir()<1 && plateau->plateaugem.getrouge()<1 && plateau->plateaugem.getvert()<1 && plateau->plateaugem.getblanc()<1 && plateau->plateaugem.getbleu()<1)
                throw SplendorException("\nComportement invalide! Il n'y plus de pierre precieuse.\n");
            while (jud == 1) {
                try {
                    cout << "GEM:\n    c=blanc  u=bleu  v=vert  r=rouge  n=noir " << endl;
                    cout << "Entrez 3 char: ";
                    char g1, g2, g3;
                    //cin >> g1 >> g2 >> g3;
                    if(Remember.empty()||isremenber==0)
                    { cin>>g1>>g2>>g3;
                    string s23 = string(1,g1)+string(1,g2)+string(1,g3);
                        to2File(s23);
                    }
                    else
                    {string sss = getremember();
                        g1 = sss[0];g2=sss[1];g3=sss[2];
                    }
                    retirer3Gem_diff(g1, g2, g3, jr);

                    jud = 0;
                }
                catch (SplendorException &se) {
                    cout << se.getInfo();
                    jud = 1;
                }
            }

            break;
        case 2:
            cout << "Vous avez decide de [choisir 2 pierres precieuses du meme type]." << endl;
            if (jr->getNbJoueurGem() == 10)
                throw SplendorException("\nComportement invalide! Vous avez deja 10 pierres precieuses.\n");
            if(plateau->plateaugem.getnoir()<4 && plateau->plateaugem.getrouge()<4 && plateau->plateaugem.getvert()<4 && plateau->plateaugem.getblanc()<4 && plateau->plateaugem.getbleu()<4)
                throw SplendorException("\nComportement invalide! Il n'y plus de pierre precieuse.\n");
            while (jud == 1) {
                try {
                    cout << "GEM:\n    c=blanc  u=bleu  v=vert  r=rouge  n=noir " << endl;
                    cout << "Entrez 1 char: ";
                    char g;
                    //cin >> g;
                    if(Remember.empty()||isremenber==0)
                    { cin>>g;
                        to2File(string(1,g));
                    }
                    else
                    {string sss = getremember();
                        g = sss[0];
                    }
                    retirer2Gem_sim(g, jr);

                    jud = 0;
                }
                catch (SplendorException &se) {
                    cout << se.getInfo();
                    jud = 1;
                }
            }
            break;
        case 3:
            cout << "Vous avez decide de [ louer une carte developpee ]." << endl;


            //jr->retirer_Gem(0,0,0,0,0,plateau->retirerGold());//如果没有黄金了，就抛出异常给上级processus

            if (jr->nb_Y == jr->nbMax_Y)
            {
                throw SplendorException("\n[Comportement invalide.Vous avez deja loue trois cartes.]\n");
            }


            cout << "Niveau:\n    1=primaire  2=moyen  3=superieur " << endl;
            cout << "Entrez un chiffre pour indiquer le niveau du carte:";
            int niveau;
            //cin >> niveau;
            if(Remember.empty()||isremenber==0) {
                cin>>niveau;
                to2File(to_string(niveau));
            }
            else
            {string sss = getremember();
                niveau = atoi(sss.c_str());
            }
            cout << endl;
            cout << "Entrez un chiffre pour indiquer la position du carte:";
            int pos_carte;
            //cin >> pos_carte;
            if(Remember.empty()||isremenber==0) {
                cin>>pos_carte;
                to2File(to_string(pos_carte));
            }
            else
            {string sss = getremember();
                pos_carte = atoi(sss.c_str());
            }
            cout << endl;
            louerCarteDev(niveau, pos_carte, jr);
            break;
        case 4:
            cout << "Vous avez decide d'[ acheter une carte developpee ]." << endl;
            cout << "Niveau:\n    1=primaire  2=moyen  3=superieur " << endl;
            cout << "Entrez un chiffre pour indiquer le niveau du carte:";
            int niv;
            //cin >> niv;
            if(Remember.empty()||isremenber==0) {
                cin>>niv;
                to2File(to_string(niv));
            }
            else
            {string sss = getremember();
                niv = atoi(sss.c_str());
            }
            cout << endl;
            cout << "Entrez un chiffre pour indiquer la position du carte:";
            int pos;
            //cin >> pos;
            if(Remember.empty()||isremenber==0) {
                cin>>pos;
                to2File(to_string(pos));
            }
            else
            {string sss = getremember();
                pos = atoi(sss.c_str());
            }
            cout << endl;
            acheterCarteDev_plateau(niv, pos, jr);
            break;
        case 5:
            cout << "Vous avez decide d'[ acheter une carte louee ]." << endl;
            cout<<"\nChoisissez une de vos cartes louees:(entrez sa position de 1 a 3) ";
            int pos_c_l;
            //cin>>pos_c_l;
            if(Remember.empty()||isremenber==0) {
                cin>>pos_c_l;
                to2File(to_string(pos_c_l));
            }
            else
            {string sss = getremember();
                pos_c_l = atoi(sss.c_str());
            }
            acheterCarte_loue(jr,pos_c_l);
            break;
        default:
            throw SplendorException("Choix invalide.");
            break;
    }
}

void Controleur::processusAI(AIJ *jr) {
    int cmptmt = 0;
    int aitry =0;
    int jud = 1;
    cmptmt=jr->op_AI(*plateau);
    cout<<"AI have decide to choose command N.["<<cmptmt<<"]"<<endl;
    switch (cmptmt) {
        case 1:
            break;
        case 2:
            cout << "Vous avez decide de [choisir 2 pierres precieuses du meme type]." << endl;
            if (jr->getNbJoueurGem() == 10)
                throw SplendorException("\nComportement invalide! Vous avez deja 10 pierres precieuses.\n");
            if(plateau->plateaugem.getnoir()<4 && plateau->plateaugem.getrouge()<4 && plateau->plateaugem.getvert()<4 && plateau->plateaugem.getblanc()<4 && plateau->plateaugem.getbleu()<4)
                throw SplendorException("\nComportement invalide! Il n'y plus de pierre precieuse.\n");

            while (jud == 1) {
                char g[5];
                g[0] = 'r';g[1] = 'v';g[2] = 'u';g[3] = 'c';g[4] = 'n';
                try {
                    cout << "GEM:\n    v=vert  r=rouge  u=bleu  c=blanc  n=noir " << endl;
                    cout << "Entrez 1 char: ";
                    //cin >> g;

                    retirer2Gem_sim(g[aitry], jr);

                    jud = 0;
                }
                catch (SplendorException &se) {
                    cout << se.getInfo();
                    jud = 1;
                    aitry++;
                }
            }
            break;
        case 3:

            //jr->retirer_Gem(0,0,0,0,0,plateau->retirerGold());//如果没有黄金了，就抛出异常给上级processus

            int niv1;
            niv1=1;
            int pos1;
            pos1 = 1;
            while (jud == 1) {
                try {
                    louerCarteDev(niv1, pos1, jr);
                    jud = 0;
                }
                catch (SplendorException &se) {
                    cout << se.getInfo();
                    jud = 1;
                    if(pos1==4)
                    {niv1++;
                    pos1=1;}
                    else
                        pos1++;
                }
            }

            break;
        case 4:
            int niv;
            niv=3;
            int pos;
            pos = 1;
            while (jud == 1) {
                try {
                    acheterCarteDev_plateau(niv, pos, jr);
                    jud = 0;
                }
                catch (SplendorException &se) {
                    cout << se.getInfo();
                    jud = 1;
                    if(pos==4)
                    {niv--;
                    pos = 1;}
                    else
                        pos++;
                }
            }

            break;
        case 5:
            int pos2;
            pos2=1;
            while (jud == 1) {
                try {
                        acheterCarte_loue(jr,pos2);
                    jud = 0;
                }
                catch (SplendorException &se) {
                    cout << se.getInfo();
                    jud = 1;
                    pos2++;
                }
            }

            break;
        default:
            throw SplendorException("Choix invalide.");
            break;
    }
}

void Controleur::Commencer_Game_city() {
    int judnp=1;
    string np;
    while(judnp==1){
        std::cout<<"Please enter the number of Players(2/3/4)(including Human Players and AI Player(s)): "<<std::endl;
        //cin>>np;
        if(Remember.empty()||isremenber==0)
        { cin>>np;
            to2File(np);
        }
        else
        {string sss = getremember();
            np = sss;
        }
        if(np!="2"&&np!="3"&&np!="4") {
            cout<<"\n[You need to enter a valid number.]\n\n";
        }
        else {judnp=0;}
    }
    if(np=="2") nb_joueur=2;
    else if(np=="3") nb_joueur=3;
    else if(np=="4") nb_joueur=4;

    int judnai=1;
    string nai;
    while(judnai==1){
        std::cout<<"Please enter the number of AI Player(s) (>=0,<="<<nb_joueur<<")"<<std::endl;
        if(Remember.empty()||isremenber==0)
        { cin>>nai;
            to2File(nai);
        }
        else
        {string sss = getremember();
            nai = sss;
        }
        if(nai!="0"&&nai!="1"&&nai!="2"&&nai!="3"&&nai!="4") {
            cout<<"\n[You need to enter a valid number.]\n\n";
        }
        else {
            if(nai=="0") nb_joueurAI=0;
            else if(nai=="1") nb_joueurAI=1;
            else if(nai=="2") nb_joueurAI=2;
            else if(nai=="3") nb_joueurAI=3;
            else if(nai=="4") nb_joueurAI=4;
            if(nb_joueur>=nb_joueurAI)judnai=0;
            else judnai=1;
        }
    }

//    std::cin>>nb_joueur;
//    std::cout<<"Veuillez entrer le nombre de joueursAI(>=0,<="<<nb_joueur<<")"<<std::endl;
//    std::cin>>nb_joueurAI;
    Plateau plateau1(nb_joueur,1);
    plateau = &plateau1;
//    plateau->TCN.shuffle();
//    plateau->set_carte_nob();

    nb_joueur = nb_joueur-nb_joueurAI;
    if (nb_joueurAI>0) AIj = new AIJ[nb_joueurAI];
    if (nb_joueur>0) joueurs = new Joueur[nb_joueur];


    cout<<"\nNow we have "<<nb_joueur<<" Human Players and "<<nb_joueurAI<<" AI Player(s).\n";
    for(int i = 0;i<nb_joueur;i++)
    {
        std::cout<<"\nPlease enter the name of player N.["<<(i+1)<<"]:"<<std::endl;
        string s;
        //std::cin>>s;
        if(Remember.empty()||isremenber==0)
        { cin>>s;
            to2File(s);
        }
        else
        {string sss = getremember();
            s = sss;
        }
        for(int j = 0;j<i;j++)
        {
            while(s==joueurs[j].getName())
            {
                //throw SplendorException("Le nom existe déjà");
                std::cout<<"\nPlease enter the name of player N.["<<(i+1)<<"]:"<<std::endl;
                if(Remember.empty()||isremenber==0)
                { cin>>s;
                    to2File(s);
                }
                else
                {string sss = getremember();
                    s = sss;
                }
            }
        }
        joueurs[i].setName(s);//玩家姓名注册
        std::cout<<"\nPlease enter the birthday of player N.["<<(i+1)<<"] (eg:20010726):"<<std::endl;
        int b;
        //std::cin>>b;
        if(Remember.empty()||isremenber==0) {
            cin>>b;
            to2File(to_string(b));
        }
        else
        {string sss = getremember();
            b = atoi(sss.c_str());
        }
        joueurs[i].setbirthday(b);
    }
    for(int i=0; i<nb_joueur; i++){
        for(int j=0; j<nb_joueur-1; j++){
            if(joueurs[j].getbirthday() < joueurs[j+1].getbirthday()){
                Joueur temp;
                temp = joueurs[j];
                joueurs[j] = joueurs[j+1];
                joueurs[j+1] = temp;
            }
        }
    }




    int fois=0;//回合数
    while (Flag != true )
    {
        fois++;//每一回合！
        std::cout<<"\n[Round:"<<fois<<"]\n"<<std::endl;
//        cout<<"GEM:\n    v=vert  r=rouge  u=bleu  c=blanc  n=noir  d=doré"<<endl;


        for(int i = 0;i<nb_joueur;i++)
        {

            cout<<"Comportement valide:"<<endl;
            cout<<"Entrer 1 pour choisir 3 pierres precieuses du type different."<<endl;
            cout<<"Entrer 2 pour choisir 2 pierres precieuses du meme type."<<endl;
            cout<<"Entrer 3 pour louer une carte developpee."<<endl;
            cout<<"Entrer 4 pour acheter une carte developpee. "<<endl;
            cout<<"Entrer 5 pour acheter une carte louee.\n"<<endl;

            cout<<"[Cartes Developees:]\n";
            plateau->afficher_cartes_dev3();
            plateau->afficher_cartes_dev2();
            plateau->afficher_cartes_dev1();
            cout<<"[Cartes City:]\n";
            plateau->afficher_city();
            cout<<"[Pierres presieuses:]\n";
            plateau->afficher_Gem();

            int cmptmt = 0;
            std::cout<<"\n"<<"["<<joueurs[i].getName()<<"],it's your turn.\n"<<std::endl;
            cout<<"Now you have:\n";
            joueurs[i].afficher_prestige();
            joueurs[i].afficher_Gem();
            joueurs[i].afficher_Bonus();

            if(!joueurs[i].getcity()){cout<<"\n[You don't have any City card.]\n";}
            else{cout<<"\nNow you have your City card(s)!]\n";}

            joueurs[i].afficher_number_cl();
            joueurs[i].afficher_Carte_louee();
//            joueurs[i].afficher_number_cn();
//            joueurs[i].afficher_Carte_Nob();
            joueurs[i].afficher_number_cd();
            int judjud = 1;
            while(judjud == 1){//如果用户没有按照要求输入y/Y/n/N
                cout<<"\nVous voulez afficher vos cartes developpees?(y/Y/n/N):";
                string yn ;
                if(Remember.empty()||isremenber==0)
                { cin>>yn;
                    to2File(yn);
                }
                else
                {string sss = getremember();
                    yn = sss;
                }
                if(yn == "n" || yn == "N")
                {
                    judjud = 0;
                }
                else if(yn == "y"|| yn =="Y")
                {
                    joueurs[i].afficher_Carte_Dev();
                    judjud=0;
                }

                if(judjud==1) cout<<"\nYou need to enter(y/Y/n/N).\n";
            }

            int jud=1;//有错（输入的动作选择）
            while(jud == 1) {
                try {
                    processus(i, &joueurs[i]);
                    jud = 0;
                }
                catch (SplendorException &se) {
                    cout << se.getInfo();
                    jud = 1;
                }
            }
            bool flagc;
            if(plateau->nbCity!=0)
                flagc = ajouterCity( &joueurs[i]);
            if(flagc)
                Flag =flagc;
            //update the state of the human player
            cout<<"\nNow you have:\n";
            joueurs[i].afficher_prestige();
            joueurs[i].afficher_Gem();
            joueurs[i].afficher_Bonus();

            if(!joueurs[i].getcity()){cout<<"\n[You don't have any City card.]\n";}
            else{cout<<"\nNow you have your City card(s)!]\n";}

            joueurs[i].afficher_number_cl();
            joueurs[i].afficher_Carte_louee();
//            joueurs[i].afficher_number_cn();
//            joueurs[i].afficher_Carte_Nob();
            joueurs[i].afficher_number_cd();
            judjud = 1;
            while(judjud == 1){//如果用户没有按照要求输入y/Y/n/N
                cout<<"\nVous voulez afficher vos cartes developpees?(y/Y/n/N):";
                string yn ;
                //cin >> yn;
                if(Remember.empty()||isremenber==0)
                { cin>>yn;
                    to2File(yn);
                }
                else
                {string sss = getremember();
                    yn = sss;
                }
                if(yn == "n" || yn == "N")
                {
                    judjud = 0;
                }
                else if(yn == "y"|| yn =="Y")
                {
                    joueurs[i].afficher_Carte_Dev();
                    judjud=0;
                }

                if(judjud==1) cout<<"\nYou need to enter(y/Y/n/N).\n";
            }
            system("PAUSE");

        }
        for(int i = 0;i<nb_joueurAI;i++)
        {
            cout<<"[Cartes Developees:]\n";
            plateau->afficher_cartes_dev3();
            plateau->afficher_cartes_dev2();
            plateau->afficher_cartes_dev1();
            cout<<"[Cartes City:]\n";
            plateau->afficher_city();
            cout<<"[Pierres presieuses:]\n";
            plateau->afficher_Gem();
            int cmptmt = 0;
            //std::cout<<joueurs[i].getName()<<",it's your turn."<<std::endl;
            cout<<"Now AI "<<i<<" have:\n";
            AIj[i].afficher_prestige();
            AIj[i].afficher_Gem();
            AIj[i].afficher_Bonus();

            if(!AIj[i].getcity()){cout<<"\n[You don't have any City card.]\n";}
            else{cout<<"\nNow you have your City card(s)!]\n";}

            AIj[i].afficher_number_cl();
            AIj[i].afficher_Carte_louee();
//            AIj[i].afficher_number_cn();
//            AIj[i].afficher_Carte_Nob();
            AIj[i].afficher_number_cd();

            AIj[i].afficher_Carte_Dev();


            int jud=1;//有错（输入的动作选择）
            while(jud == 1) {
                try {
                    processusAI(&AIj[i]);
                    jud = 0;
                }
                catch (SplendorException &se) {
                    cout << se.getInfo();
                    jud = 1;
                }
            }
            bool flagc = false;
            if(plateau->nbCity!=0)
                flagc = ajouterCityAI( &AIj[i]);
            if(flagc)
                Flag =flagc;
            cout<<"Now AI "<<i<<" have:\n";
            AIj[i].afficher_prestige();
            AIj[i].afficher_Gem();
            AIj[i].afficher_Bonus();

            if(!AIj[i].getcity()){cout<<"\n[You don't have any City card.]\n";}
            else{cout<<"\nNow you have your City card(s)!]\n";}

            AIj[i].afficher_number_cl();
            AIj[i].afficher_Carte_louee();
//            AIj[i].afficher_number_cn();
//            AIj[i].afficher_Carte_Nob();
            AIj[i].afficher_number_cd();

            AIj[i].afficher_Carte_Dev();

        }
    }
    int max_p = 0;//最大声望值
    int winner = 0;//winner的位置
    int winnerai = 0;
    for(int i = 0;i<nb_joueur;i++)
    {
        if(joueurs[i].get_prestige()>max_p && joueurs[i].getcity())
        {
            max_p = joueurs[i].get_prestige();
            winner = i;
        }
        else if(joueurs[i].get_prestige()==max_p && joueurs[i].getcity())
        {
            if(joueurs[i].getNB_D()<joueurs[winner].getNB_D())
                winner = i;
        }
    }
    max_p = 0;
    for(int i = 0;i<nb_joueurAI;i++)
    {
        if(AIj[i].get_prestige()>max_p && AIj[i].getcity())
        {
            max_p = AIj[i].get_prestige();
            winnerai = i;
        }
        else if((AIj[i].get_prestige()) == max_p && AIj[i].getcity())
        {
            if(AIj[i].getNB_D()<AIj[winnerai].getNB_D())
                winnerai = i;
        }
    }
    if(nb_joueurAI!=0 && nb_joueur!=0 && AIj[winnerai].getcity() && joueurs[winner].getcity())
    {
        if((AIj[winnerai].get_prestige())<(joueurs[winner].get_prestige()))
        {
            std::cout<<"Felicitations "<<joueurs[winner].getName()<<"! Vous avez gagne!"<<std::endl;
        }
        else if(AIj[winnerai].get_prestige()==joueurs[winner].get_prestige())
        {
            if(AIj[winnerai].getNB_D()>joueurs[winner].getNB_D())
                std::cout<<"Felicitations "<<joueurs[winner].getName()<<"! Vous avez gagne!"<<std::endl;
            else
                std::cout<<"Felicitations AI"<<winnerai<<"! Vous avez gagne!"<<std::endl;
        }
        else
            std::cout<<"Felicitations AI"<<winnerai<<"! Vous avez gagne!"<<std::endl;
    }
    else if(nb_joueur==0 || (!joueurs[winner].getcity()))
    {std::cout<<"Felicitations AI"<<winnerai<<"! Vous avez gagne!"<<std::endl;}
    else
        std::cout<<"Felicitations "<<joueurs[winner].getName()<<"! Vous avez gagne!"<<std::endl;

}

bool Controleur::ajouterCity(Joueur* j) {
    bool flagN = false;
    int okk = 0;
    int okkN[plateau->nbCity];
    for (int ppp = 0;ppp<plateau->nbCity; ppp++){
        okkN[ppp]=0;
    }
    for(int i=0; i<plateau->nbCity;i++)
    {
        if(j->get_prestige()>=plateau->pCartecity[i].getPrestige() &&
           j->get_Develope_Gem_B()>=plateau->pCartecity[i].getnoir() &&
           j->get_Develope_Gem_W()>=plateau->pCartecity[i].getblanc() &&
           j->get_Develope_Gem_R()>=plateau->pCartecity[i].getRouge() &&
           j->get_Develope_Gem_G()>=plateau->pCartecity[i].getVert() &&
           j->get_Develope_Gem_U()>=plateau->pCartecity[i].getBleu())//判断能不能获得城市卡
        {
            if(plateau->pCartecity[i].getsame() == 4)//单独判断特殊卡既有绿色又有=
            {
                if(j->get_Develope_Gem_B()>=plateau->pCartecity[i].getsame() || j->get_Develope_Gem_R()>=plateau->pCartecity[i].getsame() ||j->get_Develope_Gem_W()>=plateau->pCartecity[i].getsame() ||j->get_Develope_Gem_U()>=plateau->pCartecity[i].getsame() )
                {
                    okkN[i] = 1;
                    flagN = true;
                    okk++;
                }
            }
            else{//判断只有=的卡
                if(j->get_Develope_Gem_G()>=plateau->pCartecity[i].getsame() || j->get_Develope_Gem_B()>=plateau->pCartecity[i].getsame() || j->get_Develope_Gem_R()>=plateau->pCartecity[i].getsame() ||j->get_Develope_Gem_W()>=plateau->pCartecity[i].getsame() ||j->get_Develope_Gem_U()>=plateau->pCartecity[i].getsame() )
                {
                    okkN[i] = 1;
                    flagN = true;
                    okk++;
                }

            }


        }
    }
    if (flagN)
    {
        std::cout<<"Veuillez selectionner l'une des" <<okk<< "cartes suivantes"<<std::endl;
        for(int i=0; i<plateau->nbCity;i++) {
            if (okkN[i] == 1)
            {
                std::cout<<i<<"carte"<<endl;
                plateau->pCartecity[i].afficher();//打印牌
                if(okk == 1){
                    j->setcity();
                    cout<<"\nNow you have:\n";
                    plateau->pCartecity[i].afficher();
                    plateau->retierCartCity(i);
                }
            }
        }
        if(okk != 1 && flagN)
        {
            std::cout<<"Quelles cartes choisissez-vous?"<<"\n";
            int chois;
            //std::cin>>chois;
            if(Remember.empty()||isremenber==0) {
                cin>>chois;
                to2File(to_string(chois));
            }
            else
            {string sss = getremember();
                chois = atoi(sss.c_str());
            }
            j->setcity();;
            cout<<"\nNow you have:\n";
            plateau->pCartecity[chois].afficher();
            plateau->retierCartCity(chois);;
        }
    }

    return flagN;
}

bool Controleur::ajouterCityAI(Joueur *j) {
    bool flagN = false;
    int okk = 0;
    int okkN[plateau->nbCity];
    for (int ppp = 0;ppp<plateau->nbCity; ppp++){
        okkN[ppp]=0;
    }
    for(int i=0; i<plateau->nbCity;i++)
    {
        if(j->get_prestige()>=plateau->pCartecity[i].getPrestige() &&
           j->get_Develope_Gem_B()>=plateau->pCartecity[i].getnoir() &&
           j->get_Develope_Gem_W()>=plateau->pCartecity[i].getblanc() &&
           j->get_Develope_Gem_R()>=plateau->pCartecity[i].getRouge() &&
           j->get_Develope_Gem_G()>=plateau->pCartecity[i].getVert() &&
           j->get_Develope_Gem_U()>=plateau->pCartecity[i].getBleu())
        {
            if(plateau->pCartecity[i].getsame() == 4)
            {
                if(j->get_Develope_Gem_B()>=plateau->pCartecity[i].getsame() || j->get_Develope_Gem_R()>=plateau->pCartecity[i].getsame() ||j->get_Develope_Gem_W()>=plateau->pCartecity[i].getsame() ||j->get_Develope_Gem_U()>=plateau->pCartecity[i].getsame() )
                {
                    okkN[i] = 1;
                    flagN = true;
                    okk++;
                }
            }
            else{
                if(j->get_Develope_Gem_G()>=plateau->pCartecity[i].getsame() || j->get_Develope_Gem_B()>=plateau->pCartecity[i].getsame() || j->get_Develope_Gem_R()>=plateau->pCartecity[i].getsame() ||j->get_Develope_Gem_W()>=plateau->pCartecity[i].getsame() ||j->get_Develope_Gem_U()>=plateau->pCartecity[i].getsame() )
                {
                    okkN[i] = 1;
                    flagN = true;
                    okk++;
                }
            }
        }
    }
    if (flagN)
    {
        std::cout<<"Veuillez selectionner l'une des" <<okk<< "cartes suivantes"<<std::endl;
        for(int i=0; i<plateau->nbCity;i++) {
            if (okkN[i] == 1)
            {
                    j->setcity();
                    cout<<"\nNow you have:\n";
                    plateau->pCartecity[i].afficher();
                    // std::cout<<"vous obtenez"<<plateau->pCarteNobiliaire[i];
                    plateau->retierCartCity(i);
                break;

            }
        }
    }

    return flagN;
}

void Controleur::countergem(Joueur *jr, const CarteDeveloppee &C_D) {
    int v =C_D.getVert()-jr->get_Develope_Gem_G();
    int r =C_D.getRouge()-jr->get_Develope_Gem_R();
    int bbleu=C_D.getBleu()-jr->get_Develope_Gem_U();
    int bblanc=C_D.getblanc()-jr->get_Develope_Gem_W();
    int n = C_D.getnoir()-jr->get_Develope_Gem_B();
    if (v<0) v=0;
    if(r<0) r=0;
    if(bbleu<0) bbleu=0;
    if(bblanc<0) bblanc=0;
    if(n <0) n=0;
    int _d = jr->doit(C_D);
    int _vert = jr->joueur_gem.getvert();
    int _rouge = jr->joueur_gem.getrouge();
    int _bleu = jr->joueur_gem.getbleu();
    int _blanc = jr->joueur_gem.getblanc();
    int _noir = jr->joueur_gem.getnoir();
    int _dore = jr->joueur_gem.getdore();
     _vert = jr->joueur_gem.getvert() - v;
     _rouge = jr->joueur_gem.getrouge() - r;
     _bleu = jr->joueur_gem.getbleu() - bbleu;
     _blanc = jr->joueur_gem.getblanc() - bblanc;
     _noir = jr->joueur_gem.getnoir() - n;
    int d =_d;
    if(_vert<0 && d>0) {d = d+_vert; _vert = 0;}
    if(_rouge<0 && d>0) {d = d+_rouge; _rouge = 0;}
    if(_bleu<0 && d>0) {d = d+_bleu; _bleu = 0;}
    if(_blanc<0 && d>0) {d = d+_blanc; _blanc = 0;}
    if(_noir<0 && d>0) {d = d+_noir; _noir = 0;}
    if(_vert<0) {throw SplendorException("\n[You don't have any green(vert) gem.]\n");}
    if(_rouge<0) {throw SplendorException("\n[You don't have any red(rouge) gem.]\n");}
    if(_bleu<0) {throw SplendorException("\n[You don't have any blue(bleu) gem.]\n");}
    if(_blanc<0) {throw SplendorException("\n[You don't have any diamond(blanc).]\n");}
    if(_noir<0) {throw SplendorException("\n[You don't have any black(noir) gem.]\n");}
     v = - _vert + jr->joueur_gem.getvert() ;
    r = - _rouge + jr->joueur_gem.getrouge() ;
    bbleu = -  _bleu + jr->joueur_gem.getbleu()  ;
     bblanc = - _blanc + jr->joueur_gem.getblanc() ;
    n= - _noir + jr->joueur_gem.getnoir() ;
    jr->retirer_Gem(v,r,bbleu,bblanc,n,_d);//付出对应的宝石
    plateau->plateaugem.ajouter(v,r,bbleu,bblanc,n,_d);
}
void to2File(const string s){
    fstream srcFile("log.txt",ios::app);
    srcFile<<s<<" ";
    srcFile.close();
}
const string getremember(){
    string s;
    for(auto it= Remember.begin(); (*it) != ' '; it++)
    {s+=*it;}
    Remember.erase(0,s.size()+1);
    string tt = Remember;
    return s;
}