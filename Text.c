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

#include "Text.h"

void TextLoad(Text* t, char* font_name, int size)
{
    t->image = malloc(sizeof(Image*));

    t->font = TTF_OpenFont(font_name, size);

    t->image->img = NULL;


}

void TextDelete(Text* t)
{
    free(t->image);
    ImageDelete(t->image);
    TTF_CloseFont(t->font);
}

void TextRefresh(Text* t)
{
    ImageDelete(t->image);
}


void TextPos(Text* t, int x, int y)
{
    SetPos(t->image, x, y);
}

void TextColor(Text* t, SDL_Color* c)
{
    t->c = c;
}


void TextDraw(Text* t, SDL_Surface* screen, char* text)
{
     t->image->img = TTF_RenderText_Solid( t->font, text, *(t->c) );
     ImageDraw(screen, t->image);
}

void TextDrawC(Text* t, SDL_Surface* screen, char* text, SDL_Color* c)
{
     t->image->img = TTF_RenderText_Solid( t->font, text, *c );
     ImageDraw(screen, t->image);
}



void Int2String(int p, char* str)
{
    char int_string[MAX_TMPSTR];
    sprintf(int_string, "%d", p);
    strcpy(str, int_string);

}
