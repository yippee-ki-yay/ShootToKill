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

#include "HighScore.h"

Image h_background;
Text h_text;
Image h_back;

FILE* fp;
Text high[MAX_SCORE_NAMES];
Text names[MAX_SCORE_NAMES];
int n_lines;
int tt;
Score scores[200];

void HighScoreInit()
{
    SDL_Color textColor = { 255, 255, 255 };
    ImageLoad("../../Resource/matrix.png", &h_background);
    TextLoad(&h_text, "../../Resource/alien.ttf", 46);
    TextPos(&h_text, 200, 50);
    TextColor(&h_text, &textColor);

    ButtonInit(&h_back, "../../Resource/back.png", 700, 500);

    n_lines = 0;

      tt = 0;

    SDL_Color color = {255, 255, 255};

    int i = 0;
    for(; i < MAX_SCORE_NAMES; ++i)
    {
        TextLoad(&high[i], "../../Resource/alien.ttf", 30);
        TextColor(&high[i], &color);
    }

     for(i = 0; i < MAX_SCORE_NAMES; ++i)
    {
        TextLoad(&names[i], "../../Resource/alien.ttf", 30);
        TextColor(&names[i], &color);
    }

    HighScoreRead();
}

void HighScoreEvent(SDL_Event* e, int* state)
{
    if(e->type == SDL_KEYDOWN && e->key.keysym.sym == SDLK_ESCAPE)
    {
        *state = MENU_STATE;
    }

   if(ButtonEvent(&h_back, e))
    {
        *state = MENU_STATE;
    }
}

void HighScoreDraw(SDL_Surface* screen)
{
     ImageDraw(screen, &h_background);
    TextDraw(&h_text, screen, "Your highscores: ");
    ButtonDraw(&h_back, screen);

    HighScoreShow(screen);

}

void HighScoreDelete()
{
    ImageDelete(&h_background);
    ButtonDelete(&h_back);
    TextDelete(&h_text);

      fclose(fp);

    int i = 0;
    for(; i < MAX_SCORE_NAMES; ++i)
    {
        TextDelete(&high[i]);
    }

    for(i = 0; i < MAX_SCORE_NAMES; ++i)
    {
        TextDelete(&names[i]);
    }
}

void HighScoreAdd(char* name, int score, int size)
{
    char tmp[MAX_NAME_LENGTH];
    strncpy(tmp, name, size);
    tmp[size - 1] = '\0';
    fprintf(fp,"%s %d\n", tmp, score);
    fflush(fp);
    n_lines++;
}


int compare(const void *a, const void *b)
{

  Score* f = (Score*)a;
  Score* s = (Score*)b;

    if(f->score > s->score)
        return -1;
    else if(f->score < s->score)
        return 1;

       return 0;
}

void HighScoreShow(SDL_Surface* screen)
{
    int i = 0;

   char tmp[MAX_NAME_LENGTH];

    if(tt > 10) tt = 10;

    for(; i < tt;i++)
    {
        TextPos(&names[i], 200, 100 + i* 50);
        Int2String(scores[i].score, tmp);
        TextPos(&high[i], 400, 100 + i* 50);
        TextDraw(&high[i], screen, tmp);
        TextDraw(&names[i], screen, scores[i].name);

    }

}

void HighScoreRead()
{
    int i = 0, skor;

    char ime[MAX_NAME_LENGTH];

    fp = fopen("../../Resource/highscore.txt", "a+");

    while(fscanf(fp, "%s %d", ime, &skor) != EOF && i < 200)
    {
        scores[i].score = skor;
        strcpy(scores[i].name, ime);
        i++;
    }

    qsort(scores, i, sizeof(Score), compare);


    tt= i;
}

