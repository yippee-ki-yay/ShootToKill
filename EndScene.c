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

#include "EndScene.h"

Image end_background;
Text vase_ime;
SDL_Surface* text;
TTF_Font* font;
int i;
int player_score;


char ime[MAX_NAME_LENGTH];
SDL_Surface* img_ime;

void EndSceneInit()
{
    SDL_EnableUNICODE( SDL_ENABLE);

    ImageLoad("../../Resource/matrix.png", &end_background);
    memset(ime, 0, MAX_NAME_LENGTH);

    SDL_Color color = {255, 65, 255};

    TextLoad(&vase_ime, "../../Resource/alien.ttf",30);
    TextColor(&vase_ime, &color);

    font = TTF_OpenFont("../../Resource/alien.ttf", 30);
    text = NULL;



    i = 0;
}

void EndSceneDelete()
{
    SDL_EnableUNICODE(SDL_DISABLE);
    ImageDelete(&end_background);
    TextDelete(&vase_ime);
    SDL_FreeSurface(text);
}

void EndSceneDraw(SDL_Surface* screen)
{
    ImageDraw(screen, &end_background);
    TextDraw(&vase_ime, screen, "Unestie vase ime (max 16 slova): ");

    SpriteDraw(screen, text, 300, 300);

}

void EndSceneEvent(SDL_Surface* screen, SDL_Event* e, int* state)
{
    char tmp[MAX_NAME_LENGTH];
    SDL_Color color = {255, 255, 255};


    if(e->type == SDL_KEYDOWN)
    {

        strcpy(tmp, ime);

        if(i < MAX_NAME_LENGTH - 1)
        {
            char c = (char)e->key.keysym.unicode;

            if(c >= (Uint16)'a' && c <= (Uint16)'z'  )
            {
                ime[i] = c;
                i++;

            }

            if(e->key.keysym.sym == SDLK_BACKSPACE && i > 1)
            {
                i -= 1;
                int idxToDel = i;
                memmove( &ime[ idxToDel ] , &ime[ idxToDel+1 ], strlen( ime ) - idxToDel ) ;
            }


        if(strcmp(ime, tmp) != 0){

        SDL_FreeSurface(text);
        text = TTF_RenderText_Solid(font, ime, color);}

        }

        //ako smo zavrsili sa imenom
       if(e->key.keysym.sym == SDLK_RETURN)
       {
					if(i >= 1)
					{
            HighScoreAdd(ime, player_score, i+1);
            i = 0;
            memset(ime, 0, MAX_NAME_LENGTH);
            text = TTF_RenderText_Solid(font, "", color);
            HighScoreRead();
           *state = HIGHSCORE_STATE;
					}
       }


    }



}


void GetStringInput(SDL_Event* e)
{

}

void EndGetScore(int score)
{
    player_score = score;
}
