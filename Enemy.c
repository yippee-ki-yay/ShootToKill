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

#include "Enemy.h"

Enemy enemies[MAX_ENEMIES];

void EnemyInit()
{
    int i;
    for(i = 0; i < MAX_ENEMIES; ++i)
    {
        AnimLoad( "../../Resource/brainmonster.png", &enemies[i].anim_enemy);
        AnimFrameSize(&enemies[i].anim_enemy, 32, 64);
        AnimSet(&enemies[i].anim_enemy, "trci", 1, 3, 0);
        enemies[i].state = DEAD;
        enemies[i].vel.x = 0;
        enemies[i].vel.y = 0;


    }

}

void EnemyDelete()
{
    int i;
    for(i = 0; i < MAX_ENEMIES; ++i)
    {
        AnimDelete(&enemies[i].anim_enemy);
    }
}


void EnemyDraw(SDL_Surface* screen)
{
    int i;
    for(i = 0; i < MAX_ENEMIES; ++i)
    {
        if(enemies[i].state == ALIVE)
        {
            AnimLoop(&enemies[i].anim_enemy, "trci", screen);

            enemies[i].anim_enemy.img_anim->x += enemies[i].vel.x;
            enemies[i].anim_enemy.img_anim->y += enemies[i].vel.y;

    if(enemies[i].anim_enemy.img_anim->y < GROUND_POS)
    {
        enemies[i].vel.y += VEL_GRAVITY;
    }
    else
        enemies[i].vel.y = 0;
        }
    }
}


void EnemySpawn()
{
    int i;
    for(i = 0; i < MAX_ENEMIES; ++i)
    {
         if(enemies[i].state == DEAD)
         {
             enemies[i].state = ALIVE;
             break;
         }
    }

    int p = rand()%3;

    //random jump
    if(p == 1)
    {
        enemies[i].vel.y = -2.2;

    }

    SetPos(enemies[i].anim_enemy.img_anim, SCREEN_WIDTH, SCREEN_HEIGHT - 115);

    //which side will the enemy appear
    int k = rand()%2;

    if(k == 1)
    {
         enemies[i].vel.x -= VEL_ENEMY;
    }
    else if(k == 0)
    {
        enemies[i].anim_enemy.img_anim->x = 0;
        enemies[i].vel.x += VEL_ENEMY;
    }


}

//if the enemy walks out of the screen
void EnemyLost()
{
      int i;
    for(i = 0; i < MAX_ENEMIES; ++i)
    {
        if(enemies[i].state == ALIVE)
        {
            if(enemies[i].anim_enemy.img_anim->x < -20)
            {
                enemies[i].state = DEAD;
                enemies[i].vel.x = 0;
            }
        }
    }
}


void EnemyDie()
{
 int i;
 for(i = 0; i < MAX_ENEMIES; ++i)
 {
     enemies[i].state = DEAD;
     enemies[i].vel.x = 0;
 }
}
