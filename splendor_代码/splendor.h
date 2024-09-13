//splendor.h
//
// Created by huawei on 2021/10/24.
//

#ifndef UNTITLED_SPLENDOR_H
#define UNTITLED_SPLENDOR_H


#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "gem.h"
#include "cartes.h"
#include "joueur.h"
#include "plateau.h"
using namespace std;
extern int isremenber;
extern string Remember;//存档读取与记录
 void to2File(const string s);
 const string getremember();
//定义游戏管家类
/*    游戏管家类对【玩家】的生命周期负责
 *
 *    游戏管家类将能够拥有的方法：
 *    （1）【贵族拜访】：   判断，当玩家手中的发展卡对应的宝石红利总量与种类
 *                  达到召唤贵族的要求时，
 *                  将能够在【流程~>当前的一位玩家】中自动为玩家添加一张【贵族牌】；
 *
 *
 *    （2）【流程】：能够<<依次>>让玩家从四种选项中选择其一执行命令；
 *
 *    （3）【结果】：能够判断是否有玩家胜出
 *
 *    (4)  【流程】：
 *       /*
 *      （1）【拿走桌（Plateau）上三个不同颜色的宝石】
 *           当玩家手中有8~10个宝石时，取走桌上3个后，必须归还多余的宝石
 *
 *      （2）【拿走桌（Plateau）上两个相同颜色的宝石】
 *           当该颜色的宝石数量>=4时，玩家才能选择进行此行为，否则将抛出异常
 *           当玩家手中有9~10个宝石时，取走桌上2个后，必须归还多余的宝石
 *
 *      （3）【从桌上（Plateau）现有可见的发展牌中预留一张，并拿走一个黄金】
 *           若玩家已有3张{预留发展牌}后，仍选择进行此行为，则抛出异常
 *
 *      （4）【从桌上（Plateau）现有可见的发展卡中购买一张】
 *             若玩家手中的【宝石】+【玩家持有的发展牌】.getbonus()的总量
 *           不抵【其欲购买的发展卡】，则抛出异常
 *             （bonus指玩家手中持有的【发展卡】所带有的【宝石红利bonus】）
 *
 *      （5）【购买自己手中的预留发展卡】
 *              若 【玩家手中的宝石】+
 *                 【玩家持有的发展牌】.getbonus()+
 *                 【玩家持有的黄金】
 *             的总量不抵【其欲购买的发展卡】，则抛出异常
 *             （注：黄金将能够抵充任意一个玩家缺少的宝石）
 *
 */
class Controleur{
private:
    Joueur* joueurs = nullptr;
    AIJ* AIj = nullptr;
    bool Flag = false;//flag = true时游戏结束
    int nb_joueur=0;
    int nb_joueurAI=0;
    Plateau *plateau = nullptr;
public:
    void Commencer_Game();
    void Commencer_Game_city();
    Controleur() = default;
    ~Controleur() { delete[] joueurs; }
    void ajouterNob(Joueur* j);
    void ajouterNobAI(Joueur* j);
    bool ajouterCity(Joueur* j);
    bool ajouterCityAI(Joueur* j);
    void processus(int i,Joueur* jr);
    void processusAI(AIJ* jr);
    void retirer3Gem_diff(char g1,char g2,char g3,Joueur* jr);//【选择3个不同颜色的宝石】宝石1，宝石2，宝石3，当前玩家
    void retirer2Gem_sim(char g,Joueur* jr);//【选择2个相同颜色的宝石】宝石，当前玩家
    void louerCarteDev(int grade,int pos,Joueur* jr);//【保留一张发展卡】卡牌等级，卡牌位置，当前玩家
    void acheterCarteDev_plateau(int grade,int pos,Joueur* jr);//【购买一张桌上发展卡】卡牌等级，卡牌位置，当前玩家
    void acheterCarte_loue(Joueur* jr,int pos_c_l);//【购买一张自己保存的发展卡】当前玩家
    void countergem(Joueur* jr,const CarteDeveloppee &C_D);



};


#endif //UNTITLED_SPLENDOR_H

