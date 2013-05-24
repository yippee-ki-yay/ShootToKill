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

#include "Button.h"


void ButtonInit(struct Image* b, char* img_path, int pos_x, int pos_y)
{
    ImageLoad(img_path, b);

    SetPos(b, pos_x, pos_y);

}

void ButtonDelete(struct Image* b)
{
    ImageDelete(b);
}


int ButtonEvent(struct Image* b, SDL_Event* e)
{
    int m_x,m_y;  //mouse x,y position
    int x,y,w,h;

    x = GetPosX(b);
    y = GetPosY(b);

    w = GetWidth(b);
    h = GetHeight(b);

    if((e->type == SDL_MOUSEBUTTONDOWN))
    {
        if(e->button.button == SDL_BUTTON_LEFT)
        {
            m_x = e->motion.x;  //get mouse pos
            m_y = e->motion.y;

            //is the mouse in the sprite rectangle?
            if((m_x > x) && (m_x < x + w) && (m_y > y) && (m_y < y + h))
            {
                return 1;
            }
        }

    }

    return 0;
}


void ButtonDraw(struct Image* b, SDL_Surface* screen)
{
    ImageDraw(screen, b);
}
