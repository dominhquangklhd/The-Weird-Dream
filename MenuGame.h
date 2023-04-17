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
        SETTING = -1, NOR = 0, LOSE = 1, PAUSE = 2, SOUND = 3, INFOR = 4,
        S_IN = 2, S_OUT = 1,
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
    int Get_n_pause(){return pause_;}
    int Get_n_continue(){return continue_;}
    int Get_n_setting() {return setting_;}
    int Get_n_vol_1(){return vol_1;}
    int Get_n_vol_2(){return vol_2;}
    int Get_n_vol_2x(){return vol_2x;}
    int Get_n_vol_1x(){return vol_1x;}

    bool Get_b_isrunning(){return isrunning_;}
    bool Get_b_play_game(){return play_game_;}
    bool Get_b_menu(){return b_menu_;}
    bool Get_b_wt_return(){return wt_return_;}
    bool Get_b_pause(){return b_pause_;}
    bool Get_b_continue(){return b_continue_;}
    bool Get_b_setting() {return b_setting_;}
    bool Get_b_vol_1(){return b_vol_1;}
    bool Get_b_vol_2(){return b_vol_2;}

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
    int pause_ = 1;
    int continue_ = 1;
    int setting_ = 1;
    int vol_1 = 1;
    int vol_2 = 1;
    int vol_1x = 1;
    int vol_2x = 1;

    bool isrunning_ = true;
    bool play_game_ = true;
    bool b_menu_ = true;
    bool wt_return_ = true;
    bool b_pause_ = false;
    bool b_continue_ = false;
    bool b_setting_ = false;
    bool b_vol_1 = true;
    bool b_vol_2 = true;

    int type_menu = 0;

};

#endif // MENUGAME_H_INCLUDED
