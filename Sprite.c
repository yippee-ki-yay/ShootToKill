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

#include "Sprite.h"


int ImageLoad(char* path, Image* pic)
{
	SDL_Surface* tmpImage = NULL;

	tmpImage = IMG_Load(path);  //Load the image

	if(tmpImage == NULL)
	{
	    return -1;
	}


	pic->img = SDL_DisplayFormatAlpha(tmpImage);

	if(pic->img == NULL) return -1;

	SDL_FreeSurface(tmpImage); //destroy the tmp one

	return 0;
}

void ImageDraw(SDL_Surface* screen, Image* pic)
{
	SDL_Rect offset;

    offset.x = pic->x;
	offset.y = pic->y;


	SDL_BlitSurface(pic->img, NULL, screen, &offset);

}

void ImageDrawSheet(SDL_Surface* screen, Image* pic, int w, int h, int s_x, int s_y)
{
	SDL_Rect offset;

    offset.x = pic->x;
	offset.y = pic->y;

	SDL_Rect test;

    //sa ovime izrezemo koja povrsina slike

	test.w = w;
	test.h = h;

	//sa ovime pomeramo

	test.x = s_x;
	test.y = s_y;

	SDL_BlitSurface(pic->img, &test, screen, &offset);

}

void SpriteDraw(SDL_Surface* screen, SDL_Surface* sprite, int x, int y)
{
    SDL_Rect offset;

    offset.x = x;
	offset.y = y;


	SDL_BlitSurface(sprite, NULL, screen, &offset);
}

void ImageAlpha(Image* pic, int alpha)
{
    SDL_SetAlpha(pic->img, SDL_SRCALPHA, alpha);

}

void ImageDelete(Image* pic)
{
	SDL_FreeSurface(pic->img);
}


int GetWidth(Image* pic)
{
    return pic->img->w;
}

int GetHeight(Image* pic)
{
    return pic->img->h;
}

int GetPosX(Image* pic)
{
    return pic->x;
}

int GetPosY(Image* pic)
{
    return pic->y;
}


void SetPosX(Image* pic, int x)
{
    pic->x = x;
}

void SetPosY(Image* pic, int y)
{
    pic->y = y;
}


void SetPos(Image* pic, int x, int y)
{
    pic->x = x;
    pic->y = y;
}
