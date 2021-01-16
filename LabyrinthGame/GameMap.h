#ifndef GAMEMAP_H_INCLUDED
#define GAMEMAP_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "MapCell.h"
#include "Player.h"
#include "Enemy.h"

using namespace std;

class GameMap
{
private:

    //Game variables
    bool IsFirstTime = true;
    bool IsGameOver = false;

    //Map variables
    int Level = 1;
    int MaxRows = 0;
    int MaxColumns = 0;
    int Counter = 0;
    string MapLine = "";
    //--Matriz del mapa
    MapCell GameMapMatrix [50][50];
    MapCell HeroCell = MapCell('H');

    //Posicion del heroe dentro del mapa
    int HeroPosX = 0;
    int HeroPosY = 0;

    //Enemigo y posicion del enemigo dentro del mapa
    Enemy Enemy;
    int EnemyPosX = 0;
    int EnemyPosY = 0;

public:

    GameMap();
    GameMap(int Level);

    //Funcion que obtiene el mapa de un archivo de texto llamado GameMap.txt
    void GetGameMap();

    //Funcion obtener mensaje de un archivo txt
    void DrawMessage(string FileName, string Message);

    //Funcion que dibuja el intro del juego
    void DrawIntro();

    //Funcion que dibuja la victoria del juego
    void DrawVictory();

    //Funcion que dibuja la derrota del juego
    void DrawDefeat();

    //Funcion para jugar de nuevo.
    void PlayAgain();

    //Funcion para subir de nivel
    void LevelUp();

    //Funcion que dibuja el mapa dependiendo la posicion del heroe y el arreglo del mapa
    void DrawMap(int NewHeroPosX, int NewHeroPosY);


    //Getters and Setters
    //--Del juego
    bool GetIsGameOver(){return IsGameOver;}
    int GetLevel(){return Level;}
    //--Del mapa
    int GetMaxRows(){return MaxRows;}
    int GetMaxColumns(){return MaxColumns;}
    MapCell GetMapCell(int Posx, int Posy){return GameMapMatrix[Posy][Posx];};
    //--Del heroe
    int GetHeroPosX(){return HeroPosX;}
    int GetHeroPosY(){return HeroPosY;}
    //--Del enemigo
    int GetEnemyPosX(){return EnemyPosX;}
    int GetEnemyPosY(){return EnemyPosY;}

    void SetHeroPosX(int NewPos);
    void SetHeroPosY(int NewPos);

    void SetEnemyPosX(int NewPos);
    void SetEnemyPosY(int NewPos);
};


#endif // GAMEMAP_H_INCLUDED
