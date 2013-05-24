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

#ifndef _ANIMATION_H
#define _ANIMATION_H

#include "Sprite.h"

#include <string.h>  //zbog rukovanja sa char*

typedef struct Anim_data
{
    char name[MAX_ANIM_NAME];
    int begin, end;
    int nivo;

}Anim_data;


typedef struct Anim
{
    Anim_data anim_data[MAX_ANIM_STATE];
    Image* img_anim;
    int curr;
    int w,h;
    int p;
    int frame_index;
}Anim;


void AnimLoad(char*, Anim*);

void AnimDelete(Anim*);

void AnimFrameSize(Anim*, int, int);

void AnimSet(Anim*, char*, int, int, int);

void AnimLoop(Anim*, char*, SDL_Surface*);

void AnimDraw(Anim*, SDL_Surface*);


#endif
