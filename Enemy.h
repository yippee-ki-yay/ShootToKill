/*
    Shoot Stuff - A small 2d shooter game
    Copyright (C) 2013  Nenad Palinkasevic

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef _ENEMY_H
#define _ENEMY_H

#include "Animation.h"
#include "Globals.h"

typedef struct Enemy
{
    Anim anim_enemy;
    Vec vel;
    int state;

}Enemy;

extern Enemy enemies[MAX_ENEMIES];

void EnemyInit();

void EnemyDelete();

void EnemySpawn();

void EnemyLost();

void EnemyDie();

void EnemyDraw(SDL_Surface*);


#endif
