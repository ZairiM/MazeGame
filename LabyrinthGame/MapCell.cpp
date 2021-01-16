#include "MapCell.h"
#include <iostream>
#include <stdlib.h>
#include <fstream>

using namespace std;

MapCell::MapCell()
{
}

MapCell::MapCell(char NewId)
{
    id = NewId;
}

bool MapCell::IsBlocked()
{
    if(id == '|')
    {
        return true;
    }
    else if(id == '-')
    {
        return true;
    }
    else
    {
        return false;
    }

    return false;
}

bool MapCell::IsAChest()
{
    if(id == 'O')
    {
        return true;
    }

    return false;
}
//---Se puede borrar----
bool MapCell::IsAnEnemy()
{
    if(id == 'e')
    {
        return true;
    }

    return false;
}


void MapCell::SetCellId(char NewId)
{
    id = NewId;
}


