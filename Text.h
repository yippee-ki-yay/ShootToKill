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

#ifndef _TEXT_H
#define _TEXT_H

#include "Sprite.h"
#include "SDL/SDL_ttf.h"

typedef struct Text
{
    TTF_Font* font;
    SDL_Colour* c;
    Image* image;

}Text;

void TextLoad(Text*, char*, int);

void TextPos(Text*, int, int);

void TextDelete(Text*);

void TextColor(Text*, SDL_Color*);

void TextDraw(Text*, SDL_Surface*, char*);

void TextDrawC(Text* t, SDL_Surface* screen, char* text, SDL_Color* c);

void TextRefresh(Text*);

void Int2String(int, char*);

#endif
