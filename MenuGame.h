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

    enum TYPE_MENU
    {
        NOR = 0, LOSE = 1, PAUSE = 2, SOUND = 3, INFOR = 4,
    };

    bool LoadImgBG(std::string path, SDL_Renderer* screenBG);
    bool LoadImgCommon(std::string path, SDL_Renderer* screen, int x, int y, int w, int h);
    void Show(SDL_Renderer* des);
    void MoveImg(SDL_Renderer* des);
    SDL_Rect Get_mrect(){return m_rect;}
    void HandleInputMenu(SDL_Event m_event, int typem);

    int Get_n_play(){return play_;}
    int Get_n_exit(){return exit_;}
    int Get_n_again(){return again_;}
    int Get_n_home(){return home_;}

    bool Get_b_isrunning(){return isrunning_;}
    bool Get_b_play_game(){return play_game_;}
    bool Get_b_menu(){return b_menu_;}
    bool Get_b_wt_return(){return wt_return_;}

    bool Change_b_isrunning(bool change_isrunning_){isrunning_ = change_isrunning_; return isrunning_;}
    bool Change_b_playgame(bool change_playgame_){play_game_ = change_playgame_; return play_game_;}
    bool Change_b_menu(bool change_menu_){b_menu_ = change_menu_; return b_menu_;}

    void Reset_menu();

private:
    SDL_Rect m_rect;

    int menu_width, menu_height;

    Mix_Chunk* menu_play = Mix_LoadWAV("Music Game//MI_SFX 09.wav");
    Mix_Chunk* menu_play2 = Mix_LoadWAV("Music Game//MI_SFX 44.wav");
    Mix_Chunk* menu_exit = Mix_LoadWAV("Music Game//MI_SFX 09.wav");
    Mix_Chunk* menu_exit2 = Mix_LoadWAV("Music Game//MI_SFX 31.wav");

    int play_ = 1;
    int exit_ = 1;
    int again_ = 1;
    int home_ = 1;

    bool isrunning_ = true;
    bool play_game_ = true;
    bool b_menu_ = true;
    bool wt_return_ = true;

    int type_menu = 0;

};

#endif // MENUGAME_H_INCLUDED
