#include <iostream>
#include <stdlib.h>
#include <fstream>
#include "GameMap.h"
#include "Player.h"

using namespace std;

GameMap::GameMap()
{
    GetGameMap();
}

GameMap::GameMap(int InLevel)
{
    Level = InLevel;
    GetGameMap();
}

//Funcion que obtiene el mapa de un archivo de texto llamado GameMap.txt
void GameMap::GetGameMap()
{
    Counter = 0;
    MapLine = " ";
    IsFirstTime = true;


    string MapName = "GameMap" + to_string(Level) + ".txt";
    ifstream InGameMap(MapName);
    if(InGameMap.is_open())
    {
        while(getline(InGameMap, MapLine))
        {
            //counter fila -- i columna;
            for(int i = 0; i < MapLine.length() ; i++)
            {
                //Cuando encuentra el heroe
                if(MapLine[i] == 'x')
                {
                    HeroPosX = i;
                    HeroPosY = Counter;
                }
                //Cuando encuentra al enemigo
                if(MapLine[i] == 'E')
                {
                    Enemy.SetEnemyPosX(i);
                    Enemy.SetEnemyPosY(Counter);
                    EnemyPosX = i;
                    EnemyPosY = Counter;

                }

                GameMapMatrix[Counter][i].SetCellId(MapLine[i]);
            }

            Counter++;
        }
    }
    else
    {
        cout << "It's not possible open the map file, check your antivirus or if the file exists." << endl;
    }

    InGameMap.close();
    //Asigna los limites del mapa
    MaxRows = Counter;
    MaxColumns = MapLine.length();
}

//Funcion obtener mensaje de un archivo txt
void GameMap::DrawMessage(string FileName, string Message)
{
    Counter = 0;
    MapLine = "";
    ifstream File (FileName);
    if(File.is_open())
    {
        while(getline(File, MapLine))
        {
            cout << MapLine<< endl;

            Counter++;
        }
    }
    else
    {
        cout << Message << endl;
    }

    File.close();
}

//Funcion que dibuja el intro del juego
void GameMap::DrawIntro()
{
    string IntroFileName = "Intro.txt";
    string IntroErrorMessage = "It's not possible open the intro file, check your antivirus or if the file exists.";
    DrawMessage(IntroFileName,IntroErrorMessage);
    cin >> MapLine;

    cout << "You are the hero 'H' move using 'w' 'a' 's' 'd' and enter!" << endl;
    cout << "You need get the chest 'O'." << endl;
    cout << "Be careful 'e' is an enemy!! Don't touch it." << endl;
    DrawMap(HeroPosX, HeroPosY);
}

//Funcion que dibuja la victoria del juego
void GameMap::DrawVictory()
{
    string VictoryFileName = "Victory.txt";
    string VictoryErrorMessage = "It's not possible open the victory file, check your antivirus or if the file exists.";
    DrawMessage(VictoryFileName,VictoryErrorMessage);
    PlayAgain();
}

//Funcion que dibuja el intro del juego
void GameMap::DrawDefeat()
{
    string DefeatFileName = "Defeat.txt";
    string DefeatErrorMessage = "It's not possible open the defeat file, check your antivirus or if the file exists.";
    DrawMessage(DefeatFileName,DefeatErrorMessage);
    PlayAgain();
}

//Funcion para jugar otra vez
void GameMap::PlayAgain()
{
    char answer = ' ';

    cout << "Do you want to play again?" << endl;
    cout << "Yes 'y' and Enter" << endl;
    cout << "No 'n' and Enter" << endl;
    cin >> answer;

    switch(answer)
    {
    case 'y':
        system("CLS");
        Level = 1;
        GetGameMap();
        DrawIntro();
        break;

    case 'n':
        IsGameOver = true;
        break;

    default:
        cout << "Invalid option, try again :)" << endl;
        PlayAgain();
        break;
    }
}

void GameMap::LevelUp()
{
    char input = ' ';
    ifstream LevelUpScreen ("LevelUp.txt");
    string Screen = " ";
    if(Level == 4)
    {
        DrawVictory();
    }
    else
    {
        cout << "----------Congratulations----------" << endl;
        if(LevelUpScreen.is_open())
        {
            while(getline(LevelUpScreen, Screen))
            {
                cout << Screen<< endl;
                Counter++;
            }
        }
        else
        {
            cout << "It's not possible open the level up file, check your antivirus or if the file exists." << endl;
        }

        LevelUpScreen.close();
        cout << "----You have completed level " << Level << "----" << endl;
        cout << "--Press any key and Enter to continue--" << endl;
        cin >> input;
        Level++;
        GetGameMap();
        DrawMap(HeroPosX,HeroPosY);

    }



}

//Funcion que dibuja el mapa dependiendo la posicion del heroe y el arreglo del mapa
void GameMap::DrawMap(int NewHeroPosX, int NewHeroPosY)
{
    int CountFoundBoth = 0;

    HeroPosX = NewHeroPosX;
    HeroPosY = NewHeroPosY;

    Enemy.MoveEnemy();
    EnemyPosX = Enemy.GetEnemyPosX();
    EnemyPosY = Enemy.GetEnemyPosY();

    //Valida si es el juador paso de nivel

    //Valida si es un cofre la nueva posicion
    if(GameMapMatrix[NewHeroPosY][NewHeroPosX].IsAChest())
    {
        LevelUp();
    }
    //Valida si es un enemigo la nueva posicion
    else if((HeroPosX == EnemyPosX) && (HeroPosY == EnemyPosY) )
    {
        DrawDefeat();
    }
    else
    {
        // i fila, j columna
        for (int i = 0; i < MaxRows; i++)
        {
            for (int j = 0; j < MaxColumns; j++)
            {
                if(IsFirstTime)
                {
                    if(GameMapMatrix[i][j].GetCellId() == 'x')
                    {
                        cout << HeroCell.GetCellId();
                        CountFoundBoth++;

                    }
                    else if(GameMapMatrix[i][j].GetCellId() == 'E')
                    {
                        cout << Enemy.GetEnemyChar();
                        CountFoundBoth++;
                    }
                    else
                    {
                        cout << GameMapMatrix[i][j].GetCellId();
                    }

                    if(CountFoundBoth == 2)
                    {
                        IsFirstTime = false;
                    }

                }
                else
                {
                    if((NewHeroPosY == i) && (NewHeroPosX == j))
                    {
                        cout << HeroCell.GetCellId();
                    }
                    else if((EnemyPosY == i) && (EnemyPosX == j))
                    {
                        cout << Enemy.GetEnemyChar();
                    }
                    else
                    {
                        cout << GameMapMatrix[i][j].GetCellId();
                    }
                }
            }

            cout << endl;
        }
    }
}


//Setters
void GameMap::SetHeroPosX(int NewPos)
{
    HeroPosX = NewPos;
}
void GameMap::SetHeroPosY(int NewPos)
{
    HeroPosY = NewPos;
}

void GameMap::SetEnemyPosX(int NewPos)
{
    EnemyPosX = NewPos;
}
void GameMap::SetEnemyPosY(int NewPos)
{
    EnemyPosY = NewPos;
}
