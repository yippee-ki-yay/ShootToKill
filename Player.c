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


#include "Player.h"

Player player;
int player_state;
int player_side;

void PlayerInit()
{
    AnimLoad("../../Resource/hero0.png", &(player.anim_player));
    AnimFrameSize(&(player.anim_player), 49, 65);
    AnimSet(&(player.anim_player), "trci desno", 1, 3, 0);
    AnimSet(&(player.anim_player), "trci levo", 1, 3, 1);
    AnimSet(&(player.anim_player), "pucaj desno", 1, 3, 2);
    AnimSet(&(player.anim_player), "stoji desno", 1, 1, 0);
    AnimSet(&(player.anim_player), "stoji levo", 1, 1, 1);
    AnimSet(&(player.anim_player), "pucaj levo", 1, 3, 3);


    player.vel.x = 0;
    player.vel.y = 0;

    player_state = 0;
    player_side = 2;

    player.anim_player.img_anim->x = PLAYER_POS_X;
    player.anim_player.img_anim->y = PLAYER_POS_Y;

    BulletInit("../../Resource/fireball.png");
}

void PlayerDelete()
{
    AnimDelete(&(player.anim_player));
    BulletDelete();
}

void PlayerDraw(SDL_Surface* screen)
{
    if(player_state == 0)
    {
        AnimLoop(&(player.anim_player), "stoji levo", screen);
    }
    if(player_state == 1)
       {
           AnimLoop(&(player.anim_player), "trci desno", screen);
       }
     if(player_state == 2)
     {
          AnimLoop(&(player.anim_player), "trci levo", screen);
     }
    if(player_state == 3)
     {
         AnimLoop(&(player.anim_player), "pucaj desno", screen);
     }
    if(player_state == 4)
    {
          AnimLoop(&(player.anim_player), "stoji desno", screen);
    }
    if(player_state == 5)
    {
        AnimLoop(&(player.anim_player), "pucaj levo", screen);
    }

    BulletDraw(screen);
}

void PlayerEvents(SDL_Event* e)
{

    if(e->type == SDL_KEYDOWN)
    {
        int key = e->key.keysym.sym;

        if(key == SDLK_RIGHT || key == SDLK_d)  //move right
        {
            player.vel.x += VEL_PLAYER;
            player_state = 1;
            player_side = 0;
        }
        else if(key == SDLK_LEFT || key == SDLK_a)  //move left
        {
            player.vel.x -= VEL_PLAYER;
            player_state = 2;
            player_side = 2;
        }
        else if((key == SDLK_UP || key == SDLK_w || key == SDLK_SPACE) && (player.anim_player.img_anim->y >= GROUND_POS))  //jump
        {
            player.vel.y -= VEL_PLAYER;
        }

        if(key == SDLK_RETURN)
        {
            BulletFire(player.anim_player.img_anim->x + 12, player.anim_player.img_anim->y + 25 , player_side);
            if(player_side == 2)
                player_state = 5;
            else
                player_state = 3;
        }

    }

    //shoot with mouse
    if(e->type == SDL_MOUSEBUTTONDOWN)
    {
        if(e->button.button == SDL_BUTTON_LEFT)
             BulletFire(player.anim_player.img_anim->x + 12, player.anim_player.img_anim->y + 25 , player_side);
               if(player_side == 2)
                    player_state = 5;
               else
                    player_state = 3;
    }
    if(e->type == SDL_MOUSEBUTTONUP)
    {
        if(e->button.button == SDL_BUTTON_LEFT)
        {
              if(player_side == 2)
                player_state = 0;
              else
                player_state = 4;
        }
    }

    if(e->type == SDL_KEYUP)
    {
        int key = e->key.keysym.sym;

         if(key == SDLK_RIGHT || key == SDLK_d)  //move right
          {
            player.vel.x = 0;
            player_state = 4;
          }
           else if(key == SDLK_LEFT || key == SDLK_a)  //move left
          {
            player.vel.x = 0;
            player_state  = 0;
          }
          else if(key == SDLK_RETURN)
          {
              if(player_side == 2)
                player_state = 0;
              else
                player_state = 4;
          }
    }
}

void PlayerUpdate()
{
    player.anim_player.img_anim->x += player.vel.x;
    player.anim_player.img_anim->y += player.vel.y;

    //add gravity

    if(player.anim_player.img_anim->y < GROUND_POS)
    {
        player.vel.y += VEL_GRAVITY;
    }
    else
        player.vel.y = 0;


    //did the bullet player fired go out of screen
    BulletMiss();

    //add player bounderys
    if(player.anim_player.img_anim->x >= SCREEN_WIDTH - 40)
            player.anim_player.img_anim->x = SCREEN_WIDTH - 40;
    if(player.anim_player.img_anim->x <= 0)
            player.anim_player.img_anim->x = 0;
}


void PlayerRestart()
{
     player.vel.x = 0;
    player.vel.y = 0;

    player.anim_player.img_anim->x = PLAYER_POS_X;
    player.anim_player.img_anim->y = PLAYER_POS_Y;
}
