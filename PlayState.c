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

#include "PlayState.h"

Image sky;
Image ground;

Text tekst;

int game_active;
int percent;

char score_str[MAX_TMPSTR];
int score = 0;

void GameInit()
{
    ImageLoad("../../Resource/skyhorizon01.png", &sky);
    ImageLoad("../../Resource/grass.png", &ground);

    SetPos(&ground, 0, 550);

    srand(time(NULL));

    Int2String(score, score_str);

    TextLoad(&tekst, "../../Resource/alien.ttf", 36);

    TextPos(&tekst, 720,10);

    PlayerInit();
    EnemyInit();

    percent = 142;

    game_active = 1;
}

void GameDelete()
{
    ImageDelete(&sky);
    ImageDelete(&ground);

    PlayerDelete();

    TextDelete(&tekst);

    EnemyDelete();

}

void GameDraw(SDL_Surface* screen, int* state)
{

    ImageDraw(screen, &sky);
    ImageDraw(screen, &ground);

    PlayerDraw(screen);

    EnemyDraw(screen);

    SDL_Color c = {0, 0, 0};
    TextDrawC(&tekst, screen, score_str, &c);

  if(game_active)
  {
    PlayerUpdate();
    EnemyLost();


    int p = random() % percent;

    if(p == 1) EnemySpawn();

    CollEnemyWithBullets(state);
   }

}


void GameEvent(SDL_Event* e, int* state)
{
    PlayerEvents(e);
}


void CollEnemyWithBullets(int* state)
{
    int i, j;
    for(i = 0; i < MAX_ENEMIES; ++i)
    {

        if((enemies[i].state == 2))
        {
            if(AnimCollision(&enemies[i].anim_enemy, &(player.anim_player)))  //collison box je od slike ne od frejma
            {
                  game_active = 0;
                  EnemyDie();
                  PlayerRestart();
                  score_str[0] = '0';
                  EndGetScore(score);
                  score = 0;
                  SDL_Delay(300);
                *state = END_STATE;
            }
        }


        for(j = 0; j < MAX_BULLETS; ++j)
        {
            if(enemies[i].state == ALIVE && bullets[j].state == ALIVE) //oba su aktivna
            {
                if(RecCollision(bullets[j].img_bullet, enemies[i].anim_enemy.img_anim, 32, 64))
                {
                    enemies[i].state = DEAD;
                    enemies[i].vel.x = 0;

                    bullets[j].state = DEAD;
                    bullets[j].vel.x = 0;

                    score += 20;
                    Int2String(score, score_str);

                     if(score < 140)
                     {
                         percent -= score;
                     }
                     if(percent < 10) percent = 20;

                }
            }
        }
    }
}

