#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "MapCell.h"
#include "GameMap.h"
#include "Player.h"

using namespace std;

int main()
{
    //Declaración de variables
    GameMap MyGameMap;
    Player Hero;

    //Se inicia el juego
    MyGameMap.DrawIntro();

    // Mientras que no sea gameOver
    while(MyGameMap.GetIsGameOver() != true)
    {
        Hero.SetLevel(MyGameMap.GetLevel());
        Hero.CallInput();
        MyGameMap.DrawMap(Hero.GetHeroPosX(), Hero.GetHeroPosY());
        Hero.RefreshPosForMap(MyGameMap.GetHeroPosX(), MyGameMap.GetHeroPosY());

        cout << endl;
    }




    return 0;
}
