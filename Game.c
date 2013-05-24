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

#include "Game.h"

Globals globals;

int Init(int x, int y, char* title)
{
    //set up SDL

	if(SDL_Init(SDL_INIT_EVERYTHING) == -1) //Init all subb sistems
		return -1;

	globals.screen = SDL_SetVideoMode(x,y, 32, SDL_SWSURFACE);

	if(globals.screen == NULL) return -1;


	SDL_WM_SetCaption(title, NULL);

	//Init TTF
	if(TTF_Init() == -1) return -1;

    //Init global variables

	globals.running = 1; //game is running
	globals.curr_state = MENU_STATE; //put in menu state first
	globals.frame = 0;

    globals.second = SDL_GetTicks();


    //++++++++++ Init all the diffrent states +++++++++++++++


    MenuInit();
    GameInit();
    CreditsInit();
    HighScoreInit();
    EndSceneInit();

	return 0;

}

void Destroy()
{
    MenuDelete();
    GameDelete();
    CreditsDelete();
    HighScoreDelete();
    EndSceneDelete();

    TTF_Quit();

	SDL_Quit();  //release all the subsystems
}

void Update()
{
    globals.frame++;
    globals.start = SDL_GetTicks();

	SDL_Flip(globals.screen);   //Update

	//event loop
	while(SDL_PollEvent(&(globals.event)))
	{
	    switch(globals.curr_state)
	    {
            case MENU_STATE:
                MenuEvents(&(globals.event), &(globals.curr_state));
                break;

            case GAME_STATE:
                GameEvent(&(globals.event),&(globals.curr_state));
                break;
            case CREDITS_STATE:
                CreditsEvent(&(globals.event), &(globals.curr_state));
                break;
            case HIGHSCORE_STATE:
                HighScoreEvent(&(globals.event), &(globals.curr_state));
                break;
            case END_STATE:
                EndSceneEvent(globals.screen, &(globals.event), &(globals.curr_state));
                break;
	    };


		if(globals.event.type == SDL_QUIT)
			globals.running = 0;
	}

}

void Draw()
{
	 //state switch

    switch(globals.curr_state)
    {
        case MENU_STATE:
            MenuDraw(globals.screen);
            break;
        case GAME_STATE:
            GameDraw(globals.screen, &(globals.curr_state));
            break;
        case CREDITS_STATE:
            CreditsDraw(globals.screen);
            break;
        case HIGHSCORE_STATE:
            HighScoreDraw(globals.screen);
            break;
        case END_STATE:
            EndSceneDraw(globals.screen);
            break;
        case QUIT_STATE:   //exit game
                globals.running = 0;
                break;
    };

    ShowFps();


}

int IsRunning(){return globals.running;}

void ShowFps()
{
    int now = SDL_GetTicks();
  if( (now - globals.start) < (1000/MAX_FPS))
  {
     SDL_Delay((1000/MAX_FPS) - (now - globals.start));
  }

  if(SDL_GetTicks() - globals.second > 1000)
  {
       globals.second = SDL_GetTicks();
       globals.frame = 0;
  }
}
