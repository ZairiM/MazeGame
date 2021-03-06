#ifndef ENEMY_H_INCLUDED
#define ENEMY_H_INCLUDED


using namespace std;

class Enemy
{
private:

    int EnemyPosX = 0;
    int EnemyPosY = 0;
    char EnemyChar = 'e';

public:

    Enemy();
    //Funcion para saber si el movimiento es valido
    bool IsValidMovement(int Mov);
    //Funcion que mueve al enemigo
    void MoveEnemy();

    //Getters and Setters
    int GetEnemyPosX(){return EnemyPosX;}
    int GetEnemyPosY(){return EnemyPosY;}
    char GetEnemyChar(){return EnemyChar;}

    void SetEnemyPosX(int NewPos);
    void SetEnemyPosY(int NewPos);

};

#endif // ENEMY_H_INCLUDED
