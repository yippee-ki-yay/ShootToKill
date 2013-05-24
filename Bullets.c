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

#include "Bullets.h"

Bullet bullets[MAX_BULLETS];

void BulletInit(char* name)
{
    int i;
    for(i = 0; i < MAX_BULLETS; ++i)
    {
        bullets[i].img_bullet = malloc(sizeof(Image*));
        ImageLoad(name, bullets[i].img_bullet);
        bullets[i].state = DEAD;

        bullets[i].vel.x = 0;
        bullets[i].vel.y = 0;

        bullets[i].img_bullet->x = -300;
    }
}

void BulletDelete()
{
    int i;
    for(i = 0; i < MAX_BULLETS; ++i)
    {
        free(bullets[i].img_bullet);
        ImageDelete(bullets[i].img_bullet);
    }
}


void BulletDraw(SDL_Surface* screen)
{
    int i;
    for(i = 0; i < MAX_BULLETS; ++i)
    {
        if(bullets[i].state == ALIVE)
        {
            bullets[i].img_bullet->x += bullets[i].vel.x;
             bullets[i].img_bullet->y += bullets[i].vel.y;
            ImageDraw(screen, bullets[i].img_bullet);

        }
    }

}


void BulletFire(int x, int y, int side)
{
    //grab one alive(state = 1) bullet
    int i;
    for(i = 0; i < MAX_BULLETS; ++i)
    {
        if(bullets[i].state == DEAD)
        {
            bullets[i].state = ALIVE;
            break;
        }
    }

    //we found our bullet set x,y position
    bullets[i].img_bullet->x = x;
    bullets[i].img_bullet->y = y;

    if(side == 0)
    bullets[i].vel.x += VEL_BULLET;
    else if(side == 2)
    bullets[i].vel.x -= VEL_BULLET;
}


void BulletMiss()
{
    int i;
    for(i = 0; i < MAX_BULLETS; ++i)
    {
        if(bullets[i].state == ALIVE)
        {
            if(bullets[i].img_bullet->x > SCREEN_WIDTH)
            {
                bullets[i].state = DEAD;
                bullets[i].vel.x = 0;
            }
        }
    }
}
