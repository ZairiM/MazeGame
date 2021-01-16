#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "GameMap.h"


using namespace std;

class Player
{
private:

    int HeroPosX = 0;
    int HeroPosY = 0;
    int CurrentLevel = 0;

public:

    Player();

    //Funcion que recibe una entrada
    void CallHeroPosFromMap();
    void RefreshPosForMap(int NewPosx, int NewPosy);
    bool IsValidMovement(char Mov);
    void CallInput();


    int GetHeroPosX(){return HeroPosX;}
    int GetHeroPosY(){return HeroPosY;}

    void SetHeroPosX(int NewPos);
    void SetHeroPosY(int NewPos);
    void SetLevel(int Level);
};


#endif // PLAYER_H_INCLUDED
