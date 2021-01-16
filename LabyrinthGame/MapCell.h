#ifndef MAPCELL_H_INCLUDED
#define MAPCELL_H_INCLUDED
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

class MapCell
{
private:

    char id = ' ';

public:

    MapCell();
    MapCell(char NewId);
    bool IsBlocked();
    bool IsAChest();
    bool IsAnEnemy();

    char GetCellId(){return id;}
    void SetCellId(char NewId);

};


#endif // MAPCELL_H_INCLUDED
