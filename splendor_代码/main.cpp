#include <iostream>
#include "splendor.h"

int main() {

    fstream srcFile("log.txt"); //以文本模式打开in.txt备读
    if(srcFile) {
        cout << "Do you want to resume the previous game?.(Y/N)" << endl;
        int judjud = 1;
        while(judjud == 1){//如果用户没有按照要求输入y/Y/n/N
            string yn ;
            cin >> yn;
            if(yn == "n" || yn == "N")
            {
                judjud = 0;
                Remember.clear();
                srcFile.close();
                fstream srcFile("log.txt",ios::out);
                srcFile.close();
                isremenber =0;
            }
            else if(yn == "y"|| yn =="Y")
            {
                judjud=0;
                getline(srcFile,Remember);
                srcFile.close();
                isremenber =1;
            }

            if(judjud==1) cout<<"\n[You need to enter(y/Y/n/N).]\n";
        }
    }
    else {
        ofstream ccFile("log.txt");
        ccFile.close();
    }
    Controleur con;
    std::cout<<"Do you want to play the expansion mode of Cities?(Y/N)"<<std::endl;
    int judjud = 1;
    while(judjud == 1){//如果用户没有按照要求输入y/Y/n/N
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
            con.Commencer_Game();
        }
        else if(yn == "y"|| yn =="Y")
        {
            judjud=0;
            con.Commencer_Game_city();
        }

        if(judjud==1) cout<<"\n[You need to enter(y/Y/n/N).]\n";
    }

    return 0;
}
