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

#ifndef _END_SCENE_H
#define _END_SCENE_H

#include <string.h>

#include "Sprite.h"
#include "Globals.h"
#include "Text.h"

#include "HighScore.h"

extern Image end_background;
extern Text vase_ime;

extern char ime[MAX_NAME_LENGTH];
extern SDL_Surface* text;
extern TTF_Font* font;
extern int i;
extern int player_score;

void EndSceneInit();

void EndSceneDelete();

void EndSceneDraw(SDL_Surface*);

void EndSceneEvent(SDL_Surface*, SDL_Event*, int*);

void GetStringInput(SDL_Event*);

void EndGetScore(int);

#endif
