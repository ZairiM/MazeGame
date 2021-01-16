#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "Player.h"
#include "GameMap.h"

using namespace std;

Player::Player()
{
    CallHeroPosFromMap();
}

//Llama la posicion del jugador de la que encuentra cuando dibujua por primera vez el mapa
void Player::CallHeroPosFromMap()
{
    GameMap NewGameMap;
    HeroPosX = NewGameMap.GetHeroPosX();
    HeroPosY = NewGameMap.GetHeroPosY();
}

//Refresca la posicion del heroe del mapa.
void Player::RefreshPosForMap(int NewPosx, int NewPosy)
{
    HeroPosX = NewPosx;
    HeroPosY = NewPosy;
}

//Valida si el movimiento es valido viendo si no se desborda de los limites del mapa
bool Player:: IsValidMovement(char Mov)
{
    GameMap NewGameMap(CurrentLevel);

    int MaxBorderX = NewGameMap.GetMaxColumns();
    int MaxBorderY = NewGameMap.GetMaxRows();
    int MinBorder = 0;

    switch(Mov)
    {
    case 'd':
        if(HeroPosX + 1 > MaxBorderX)
        {
            return false;
        }
        else if(NewGameMap.GetMapCell((HeroPosX + 1), HeroPosY).IsBlocked())
        {
            return false;
        }
        break;

    case 'a':
        if(HeroPosX - 1 < MinBorder)
        {
            return false;
        }
        else if(NewGameMap.GetMapCell((HeroPosX - 1), HeroPosY).IsBlocked())
        {
            return false;
        }
        break;

    case 'w':
        if(HeroPosY - 1 < MinBorder)
        {
            return false;
        }
        else if(NewGameMap.GetMapCell(HeroPosX, (HeroPosY - 1)).IsBlocked())
        {

            return false;
        }
        break;

    case 's':
        if(HeroPosY + 1 > MaxBorderY)
        {
            return false;
        }
        else if(NewGameMap.GetMapCell(HeroPosX, (HeroPosY + 1)).IsBlocked())
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

//Funcion que recibe una entrada
void Player:: CallInput()
{
    char CharInput = ' ';

    //Recibe movimiento
    cin >> CharInput;

    //Evalua las opciones
    if(IsValidMovement(CharInput))
    {

        switch(CharInput)
        {
        //Se mueve a la derecha
        case 'd':
            HeroPosX++;

            break;

        //Se mueve a la izquierda
        case 'a':
            HeroPosX--;
            break;

        //Se mueve arriba
        case 'w':
            HeroPosY--;
            break;

        //Se mueve abajo
        case 's':
            HeroPosY++;
            break;

        //Cualquier opción que no sea una de las anteriores
        default:
            cout << "Invalid option, try again :)" << endl;
            break;
        }

        system ("CLS");
    }
    else
    {
        system ("CLS");
        cout << "Invalid movement in (x,y): " << HeroPosY << " " << HeroPosX << endl << "You can't pass walls! :c" << endl;
    }

}

//Setters
void Player::SetHeroPosX(int NewPos)
{
    HeroPosX = NewPos;
}

void Player::SetHeroPosY(int NewPos)
{
    HeroPosY = NewPos;
}

void Player::SetLevel(int Level)
{
    CurrentLevel = Level;
}
