#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <stdlib.h>
#include "Enemy.h"
#include "GameMap.h"

using namespace std;

Enemy::Enemy()
{
}

//Valida si el movimiento es valido viendo si no se desborda de los limites del mapa
bool Enemy:: IsValidMovement(int Mov)
{
    GameMap NewGameMap;

    int MaxBorderX = NewGameMap.GetMaxColumns();
    int MaxBorderY = NewGameMap.GetMaxRows();
    int MinBorder = 0;

    switch(Mov)
    {
    case 3:
        if(EnemyPosX + 1 > MaxBorderX)
        {
            return false;
        }
        else if(NewGameMap.GetMapCell((EnemyPosX + 1), EnemyPosY).IsBlocked())
        {

            return false;
        }
        break;

    case 1:
        if(EnemyPosX - 1 < MinBorder)
        {
            return false;
        }
        else if(NewGameMap.GetMapCell((EnemyPosX - 1), EnemyPosY).IsBlocked())
        {

            return false;
        }
        break;

    case 0:
        if(EnemyPosY - 1 < MinBorder)
        {
            return false;
        }
        else if(NewGameMap.GetMapCell(EnemyPosX, (EnemyPosY - 1)).IsBlocked())
        {

            return false;
        }
        break;

    case 2:
        if(EnemyPosY + 1 > MaxBorderY)
        {
            return false;
        }
        else if(NewGameMap.GetMapCell(EnemyPosX, (EnemyPosY + 1)).IsBlocked())
        {

            return false;
        }
        break;

    //Cualquier opción que no sea una de las anteriores
    default:
        return true;
        break;
    }



    return true;
}

//Funcion que mueve al enemigo
void Enemy:: MoveEnemy()
{
    //Moves[4] = {'w','a','s','d'};
    int RandomPos = rand() % 4;

    //Evalua las opciones
    if(IsValidMovement(RandomPos))
    {
        switch(RandomPos)
        {
        //Se mueve arriba
        case 0:
            EnemyPosY--;
            break;

        //Se mueve a la izquierda
        case 1:
            EnemyPosX--;
            break;

        //Se mueve abajo
        case 2:
            EnemyPosY++;
            break;

        //Se mueve a la derecha
        case 3:
            EnemyPosX++;
            break;

        //Cualquier opción que no sea una de las anteriores
        default:
            break;
        }
    }

}

//Setters

void Enemy::SetEnemyPosX(int NewPos)
{
    EnemyPosX = NewPos;
}

void Enemy::SetEnemyPosY(int NewPos)
{
    EnemyPosY = NewPos;
}
