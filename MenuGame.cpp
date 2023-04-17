#include "MenuGame.h"

MenuGame::MenuGame()
{
    m_rect.x = 0;
    m_rect.y = 0;
}

MenuGame::~MenuGame(){}

void MenuGame::Reset_menu()
{
    m_rect.x = 0;
    m_rect.y = 0;

    menu_play = Mix_LoadWAV("Music Game//MI_SFX 09.wav");
    menu_play2 = Mix_LoadWAV("Music Game//MI_SFX 44.wav");
    menu_exit = Mix_LoadWAV("Music Game//MI_SFX 09.wav");
    menu_exit2 = Mix_LoadWAV("Music Game//MI_SFX 31.wav");

    play_ = S_OUT;
    home_ = S_OUT;
    exit_ = S_OUT;
    again_ = S_OUT;
    pause_ = S_OUT;
    continue_ = S_OUT;
    setting_ = S_OUT;
    vol_1 = S_OUT;
    vol_2 = S_OUT;
    vol_1x = S_OUT;
    vol_2x = S_OUT;

    isrunning_ = true;
    play_game_ = true;
    b_menu_ = true;
    wt_return_ = true;
    b_pause_ = false;
    b_continue_ = false;
    b_setting_ = false;
}

bool MenuGame::LoadImgBG(std::string path, SDL_Renderer* screenBG)
{
    bool ret = BaseOJ::LoadImgBG(path, screenBG);

    if (ret == true)
    {
        menu_width = rect_.w;
        menu_height = rect_.h;
    }

    return ret;
}

bool MenuGame::LoadImgCommon(std::string path, SDL_Renderer* screen, int x, int y, int w, int h)
{
    bool ret = BaseOJ::LoadImgCommon(path, screen, x, y, w, h);

    if (ret == true)
    {
        m_rect.x = x;
        m_rect.y = y;
        menu_width = rect_.w;
        menu_height = rect_.h;
    }

    return ret;
}

void MenuGame::Show(SDL_Renderer* des)
{
    m_rect.w = menu_width;
    m_rect.h = menu_height;
    SDL_RenderCopy(des, p_object_, NULL, &m_rect);

}

void MenuGame::MoveImg(SDL_Renderer* des)
{
    m_rect.y -= 50;
    SDL_RenderCopy(des, p_object_, NULL, &m_rect);
}

void MenuGame::HandleInputMenu(SDL_Event m_event, int typem)
{
    switch(m_event.type)
        {
        case SDL_MOUSEMOTION:
            {
            if (typem == NOR){
                if (m_event.motion.x <= xm_p + 250 && m_event.motion.x >= xm_p
                    && m_event.motion.y >= ym_p && m_event.motion.y <= ym_p + 55)
                    {
                        play_ = S_IN;
                    }else
                    {
                        play_ = S_OUT;
                    }
                if (m_event.motion.x <= xm_e + 250 && m_event.motion.x >= xm_e
                    && m_event.motion.y >= ym_e && m_event.motion.y <= ym_e + 55)
                    {
                    exit_ = S_IN;
                    }else
                    {
                    exit_ = S_OUT;
                    }
                if (m_event.motion.x <= 50 && m_event.motion.x >= 0
                    && m_event.motion.y >= 0 && m_event.motion.y <= 50)
                    {
                        setting_ = S_IN;
                    }else
                    {
                        setting_ = S_OUT;
                    }
                }
            else if (typem == SETTING)
            {
                if (b_vol_1 == true && (m_event.motion.x <= 170+50 && m_event.motion.x >= 170
                    && m_event.motion.y >= 100 && m_event.motion.y <= 100+50))
                    {
                        vol_1 = S_IN;
                    }else
                    {
                        vol_1 = S_OUT;
                    }
                if (b_vol_2 == true && (m_event.motion.x <= 170+50 && m_event.motion.x >= 170
                    && m_event.motion.y >= 190 && m_event.motion.y <= 190+50))
                    {
                        vol_2 = S_IN;
                    }else
                    {
                        vol_2 = S_OUT;
                    }
                if (b_vol_1 == false && (m_event.motion.x <= 170+50 && m_event.motion.x >= 170
                    && m_event.motion.y >= 100 && m_event.motion.y <= 100+50))
                    {
                        vol_1x = S_IN;
                    }else
                    {
                        vol_1x = S_OUT;
                    }
                if (b_vol_2 == false && (m_event.motion.x <= 170+50 && m_event.motion.x >= 170
                    && m_event.motion.y >= 190 && m_event.motion.y <= 190+50))
                    {
                        vol_2x = S_IN;
                    }else
                    {
                        vol_2x = S_OUT;
                    }
            }
            else if (typem == LOSE)
                {
                    if (m_event.motion.x <= xm_a + 100 && m_event.motion.x >= xm_a
                    && m_event.motion.y >= ym_a && m_event.motion.y <= ym_a + 100)
                    {
                        again_ = S_IN;
                    }else
                    {
                        again_ = S_OUT;
                    }

                    if (m_event.motion.x <= xm_h + 100 && m_event.motion.x >= xm_h
                    && m_event.motion.y >= ym_h && m_event.motion.y <= ym_h + 100)
                    {
                        home_ = S_IN;
                    }else
                    {
                        home_ = S_OUT;
                    }
                }
            else if (typem == PAUSE)
                {
                    if (m_event.motion.x <= 50 && m_event.motion.x >= 0
                    && m_event.motion.y >= 0 && m_event.motion.y <= 50)
                    {
                        pause_ = S_IN;
                    }else
                    {
                        pause_ = S_OUT;
                    }
                    if (m_event.motion.x <= 400 + 100 && m_event.motion.x >= 400
                    && m_event.motion.y >= 430 && m_event.motion.y <= 430 + 100)
                    {
                        continue_ = S_IN;
                    }else
                    {
                        b_continue_ = false;
                        continue_ = S_OUT;
                    }
                    if (m_event.motion.x <= 660 + 100 && m_event.motion.x >= 660
                    && m_event.motion.y >= 430 && m_event.motion.y <= 430 + 100)
                    {
                        home_ = S_IN;
                    }else
                    {
                        home_ = S_OUT;
                    }
                }
            }
            break;
        case SDL_KEYDOWN:
            {
                if (m_event.key.keysym.sym == SDLK_p)
                {
                    pause_ = S_IN;
                    b_pause_ = true;
                }
            }
            break;
        case SDL_KEYUP:
            {
                if (m_event.key.keysym.sym == SDLK_p)
                {
                    pause_ = S_OUT;
                }
            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            {
                if (typem == NOR){
                    if (play_ == S_IN)
                    {
                    Mix_PlayChannel(MENU_MUSIC, menu_play2, 0);
                    isrunning_ = true;
                    b_menu_ = false;
                    }
                    if (setting_ == S_IN)
                    {
                        b_setting_ = true;
                    }
                    if (exit_ == S_IN)
                    {
                    Mix_PlayChannel(MENU_MUSIC, menu_exit2, 0);
                    isrunning_ = false;
                    b_menu_ = false;
                    play_game_ = false;
                    SDL_Delay(300);
                    }
                }
                if (typem == SETTING)
                {
                    if (vol_1 == S_IN && b_vol_1 == true) b_vol_1 = false;
                    if (vol_1x == S_IN && b_vol_1 == false) b_vol_1 = true;
                    if (vol_2 == S_IN && b_vol_2 == true) b_vol_2 = false;
                    if (vol_2x == S_IN && b_vol_2 == false) b_vol_2 = true;
                    if (vol_1 == S_OUT && vol_1x == S_OUT && vol_2 == S_OUT && vol_2x == S_OUT)
                    {
                        setting_ = S_OUT;
                        b_setting_ = false;
                    }
                }
                if (typem == LOSE){
                    if (again_ == S_IN)
                    {
                        b_menu_ = false;
                        isrunning_ = true;
                        play_game_ = true;
                        wt_return_ = false;
                    }
                    if (home_ == S_IN)
                    {
                        b_menu_ = true;
                        isrunning_ = true;
                        play_game_ = false;
                        wt_return_ = false;
                    }
                }
                if (typem == PAUSE){
                    if (pause_ == S_IN)
                    {
                    b_pause_ = true;
                    }
                    if (home_ == S_IN)
                    {
                        b_pause_ = false;
                        b_menu_ = true;
                        isrunning_ = true;
                        play_game_ = false;
                    }
                    if (continue_ == S_IN)
                    {
                        b_continue_ = true;
                        b_pause_ = false;
                        b_menu_ = false;
                    }
                }
            }
            break;
            }
}
