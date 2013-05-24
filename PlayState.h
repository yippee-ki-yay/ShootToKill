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

#ifndef _PLAY_STATE_H
#define _PLAY_STATE_H

#include "Player.h"
#include "Enemy.h"

#include "Animation.h"
#include "Collision.h"

#include "Text.h"

#include <stdlib.h>
#include <time.h>
#include "EndScene.h"

extern Text tekst;

extern char score_str[MAX_TMPSTR];
extern int score;

extern Image sky;
extern Image ground;
extern int percent;

extern int game_active;

void GameInit();

void GameDelete();

void GameDraw(SDL_Surface*, int*);

void GameEvent(SDL_Event*, int*);

void CollEnemyWithBullets(int*);

#endif
