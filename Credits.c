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

#include "Credits.h"

Image c_background;
Text t;
Image back;

void CreditsInit()
{

    SDL_Color textColor = { 255, 255, 255 };
    ImageLoad("../../Resource/matrix.png", &c_background);
    TextLoad(&t, "../../Resource/alien.ttf", 30);
    TextPos(&t, 20, 250);
    TextColor(&t, &textColor);

    ButtonInit(&back, "../../Resource/back.png", 700, 500);

}

void CreditsEvent(SDL_Event* e, int* state)
{
    if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
    {
        *state = MENU_STATE;
    }

    if(ButtonEvent(&back, e))
    {
        *state = MENU_STATE;
    }
}

void CreditsDraw(SDL_Surface* screen)
{
    ImageDraw(screen, &c_background);
    TextDraw(&t, screen, "Programmed by: Nenad Palinkasevic... level over 9000.");
    ButtonDraw(&back, screen);
}

void CreditsDelete()
{
    ImageDelete(&c_background);
    ButtonDelete(&back);
    TextDelete(&t);
}
