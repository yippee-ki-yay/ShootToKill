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

#ifndef _GAME_H
#define _GAME_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"

#include "Sprite.h"

#include "Globals.h"

#include "Menu.h"
#include "PlayState.h"
#include "Credits.h"
#include "HighScore.h"
#include "EndScene.h"

typedef struct{
 SDL_Surface* screen;
 SDL_Event event;

 TTF_Font* font;

 int start;
 int frame;

 int second;

 int running;
 int curr_state;
} Globals;


extern Globals globals;

int Init(int, int, char*);
void Destroy();

void Draw();
void Update();

void ShowFps();

int IsRunning();

#endif
