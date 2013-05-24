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

#ifndef _HIGHSCORE_H
#define _HIGHSCORE_H

#include <stdio.h>

#include "Button.h"
#include "Text.h"

#include "Globals.h"

#include <stdlib.h>

extern Image h_background;
extern Text h_text;
extern Image h_back;

typedef struct Score
{
    char name[MAX_NAME_LENGTH];
    int score;
}Score;

extern Score scores[200];

extern FILE* fp;
extern Text high[MAX_SCORE_NAMES];
extern Text names[MAX_SCORE_NAMES];

extern int n_lines;
extern int tt;

void HighScoreInit();

void HighScoreEvent(SDL_Event*, int*);

void HighScoreDraw(SDL_Surface*);

void HighScoreDelete();

void HighScoreAdd(char*, int, int);

void HighScoreRead();

void HighScoreShow(SDL_Surface*);

#endif
