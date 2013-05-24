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

#ifndef _SPRITE_H
#define _SPRITE_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

#include "Globals.h"

typedef struct Image
{
	float x,y;
	SDL_Surface *img;
}Image;


int ImageLoad(char*, Image*);

void ImageDraw(SDL_Surface*, Image*);

void ImageDrawSheet(SDL_Surface*, Image*, int , int, int, int);

void ImageDelete(Image*);

void ImageAlpha(Image*, int alpha);

void SpriteDraw(SDL_Surface*, SDL_Surface*, int, int);


int GetWidth(Image*);
int GetHeight(Image*);

int GetPosX(Image*);
int GetPosY(Image*);

void SetPos(Image*, int ,int);

void SetPosX(Image*, int);
void SetPosY(Image*, int);

#endif

