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

#ifndef _GLOBALS_H
#define _GLOBALS_H

#define MAX_BULLETS 100
#define MAX_ENEMIES 100
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

#define MENU_STATE 0
#define GAME_STATE 1
#define CREDITS_STATE 2
#define HIGHSCORE_STATE 3
#define QUIT_STATE 4
#define END_STATE 5

#define MAX_NAME_LENGTH 16
#define MAX_SCORE_NAMES 10

#define MAX_TMPSTR 32
#define MAX_ANIM_NAME 20
#define MAX_ANIM_STATE 32

#define MAX_FPS 60

#define VEL_GRAVITY 0.03
#define VEL_PLAYER  2
#define VEL_BULLET 10
#define VEL_ENEMY 2

#define PLAYER_POS_X 350
#define PLAYER_POS_Y 400
#define GROUND_POS 490

#define ALIVE 2
#define DEAD 1

typedef struct Vec
{
    float x,y;
}Vec;

#endif
