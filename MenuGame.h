#ifndef MENUGAME_H_INCLUDED
#define MENUGAME_H_INCLUDED

#include "BaseOJ.h"
#include "Common_Funtion.h"
#include "TextObject.h"

class MenuGame : public BaseOJ, TextObject
{
public:
    MenuGame();
    ~MenuGame();

    bool LoadImgBG(std::string path, SDL_Renderer* screenBG);
    void Show(SDL_Renderer* des);
    void MoveImg(SDL_Renderer* des);
    SDL_Rect Get_mrect(){return m_rect;}
    void HandleInputMenu(SDL_Event m_event);

    int Get_n_play(){return play_;}
    int Get_n_exit(){return exit_;}

    bool Get_b_isrunning(){return isrunning_;}
    bool Get_b_play_game(){return play_game_;}
    bool Get_b_menu(){return b_menu_;}


private:
    SDL_Rect m_rect;

    int xp, yp;
    int menu_width, menu_height;

    Mix_Chunk* menu_play = Mix_LoadWAV("Music Game//MI_SFX 09.wav");
    Mix_Chunk* menu_play2 = Mix_LoadWAV("Music Game//MI_SFX 44.wav");
    Mix_Chunk* menu_exit = Mix_LoadWAV("Music Game//MI_SFX 09.wav");
    Mix_Chunk* menu_exit2 = Mix_LoadWAV("Music Game//MI_SFX 31.wav");

    int play_ = 1;
    int exit_ = 1;

    bool isrunning_ = true;
    bool play_game_ = true;
    bool b_menu_ = true;
};

#endif // MENUGAME_H_INCLUDED
