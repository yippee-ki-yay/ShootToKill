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

#include "Collision.h"

int RecCollision(struct Image* first, struct Image* second, int w, int h)
{
    int xA, yA, wA, hA, xB, yB, wB, hB;

    xA = GetPosX(first);
    yA = GetPosY(first);

    wA = GetWidth(first) + xA;
    hA = GetHeight(first) + yA ;

    xB = GetPosX(second);
    yB = GetPosY(second);

    wB = w + xB;
    hB = h + yB;

    if((hA <= yB) || (yA >= hB) || (wA <= xB) || (xA >= wB)) return 0;

    return 1;
}

int AnimCollision(Anim *f, Anim* s)
{
     int xA, yA, wA, hA, xB, yB, wB, hB;

    xA = GetPosX(f->img_anim);
    yA = GetPosY(f->img_anim);

    wA = f->w + xA - 20;
    hA = f->h + yA - 20;

    xB = GetPosX(s->img_anim);  //nastelujemo da radi boolje za nas slucaj
    yB = GetPosY(s->img_anim);

    wB = s->w + xB - 20;  //takodje
    hB = s->h + yB - 10;

    if((hA <= yB) || (yA >= hB) || (wA <= xB) || (xA >= wB)) return 0;

    return 1;
}
