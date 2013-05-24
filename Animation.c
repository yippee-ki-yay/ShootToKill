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

#include "Animation.h"


void AnimLoad(char* name, Anim* a)
{

   a->img_anim = malloc(sizeof(Image*));
   a->curr = 0;
   a->p = 0;
   a->frame_index = 0;


   ImageLoad(name, a->img_anim);

}


void AnimFrameSize(Anim* a, int w, int h)
{
    a->w = w;
    a->h = h;
}

void AnimDelete(Anim* a)
{
    free(a->img_anim);
    ImageDelete(a->img_anim);
}

void AnimSet(Anim* a, char* name, int b, int e, int n)
{
    if(a->curr <= MAX_ANIM_STATE)
    {
        strcpy(a->anim_data[a->curr].name, name);
        a->anim_data[a->curr].begin = b;
        a->anim_data[a->curr].end = e;
        a->anim_data[a->curr].nivo = n;

        a->curr++;

    }
}

void AnimLoop(Anim* a, char* name, SDL_Surface* screen)
{
    int i,b = 0,e = 0, n = 0;
    for(i = 0; i < MAX_ANIM_STATE; ++i)
    {
        if(strcmp(a->anim_data[i].name, name) == 0)
        {
            b = a->anim_data[i].begin;
            e = a->anim_data[i].end;
            n = a->anim_data[i].nivo;
            break;
        }
    }

       a->frame_index++;
       if(a->frame_index == 12){
           a->frame_index = 0;
        if(a->p < e)
            a->p++;

        if(a->p == e)
            a->p = 0;}

     ImageDrawSheet(screen, a->img_anim, a->w, a->h, (b*a->w) * a->p, n * ((b*a->h)));

}

void AnimDraw(Anim* a, SDL_Surface* screen)
{
    ImageDrawSheet(screen, a->img_anim, a->w, a->h, 0, 0);
}
