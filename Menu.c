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

#include "Menu.h"

Image start;
Image quit;
Image highscore;
Image credits;

Image background;

void MenuInit()
{
    ButtonInit(&start, "../../Resource/start.png", 290, 100);
    ButtonInit(&quit, "../../Resource/quit.png", 290, 400);
    ButtonInit(&highscore, "../../Resource/highscore.png", 290, 200);
    ButtonInit(&credits, "../../Resource/credits.png", 290, 300);

    ImageLoad("../../Resource/matrix.png", &background);
}

void MenuDelete()
{
    ButtonDelete(&start);
    ButtonDelete(&quit);
    ButtonDelete(&highscore);
    ButtonDelete(&credits);

    ImageDelete(&background);
}

void MenuEvents(SDL_Event* e, int* state)
{
    if(ButtonEvent(&start, e))
    {
        *state = GAME_STATE;  //game state
        PlayerRestart();
        game_active = 1;
    }
    else if(ButtonEvent(&quit, e))
    {
        *state = QUIT_STATE; //quit state
    }
    else if(ButtonEvent(&credits, e))
    {
        *state = CREDITS_STATE;
    }
    else if(ButtonEvent(&highscore, e))
    {
        *state = HIGHSCORE_STATE;
    }
}


void MenuDraw(SDL_Surface* screen)
{

    ImageDraw(screen, &background);

    ButtonDraw(&start, screen);
    ButtonDraw(&quit, screen);
    ButtonDraw(&highscore, screen);
    ButtonDraw(&credits, screen);
}
