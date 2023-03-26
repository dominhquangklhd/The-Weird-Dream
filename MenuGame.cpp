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

    play_ = 1;
    exit_ = 1;
    again_ = 1;
    home_ = 1;

    isrunning_ = true;
    play_game_ = true;
    b_menu_ = true;
    wt_return_ = true;

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
                        play_ = 2;
                    }else
                    {
                        play_ = 1;
                    }

                if (m_event.motion.x <= xm_e + 250 && m_event.motion.x >= xm_e
                    && m_event.motion.y >= ym_e && m_event.motion.y <= ym_e + 55)
                    {
                    exit_ = 2;
                    }else
                    {
                    exit_ = 1;
                    }
                }
                else if (typem == LOSE)
                {
                    if (m_event.motion.x <= xm_a + 100 && m_event.motion.x >= xm_a
                    && m_event.motion.y >= ym_a && m_event.motion.y <= ym_a + 100)
                    {
                        again_ = 2;
                    }else
                    {
                        again_ = 1;
                    }

                    if (m_event.motion.x <= xm_h + 100 && m_event.motion.x >= xm_h
                    && m_event.motion.y >= ym_h && m_event.motion.y <= ym_h + 100)
                    {
                        home_ = 2;
                    }else
                    {
                        home_ = 1;
                    }
                }

            }
            break;
        case SDL_MOUSEBUTTONDOWN:
            {
                if (typem == NOR){
                    if (play_ == 2)
                    {
                    Mix_PlayChannel(MENU_MUSIC, menu_play2, 0);
                    isrunning_ = true;
                    b_menu_ = false;
                    }
                    if (exit_ == 2)
                    {
                    Mix_PlayChannel(MENU_MUSIC, menu_exit2, 0);
                    isrunning_ = false;
                    b_menu_ = false;
                    play_game_ = false;
                    SDL_Delay(300);
                    }
                }
                if (typem == LOSE){
                    if (again_ == 2)
                    {
                        b_menu_ = false;
                        isrunning_ = true;
                        play_game_ = true;
                        wt_return_ = false;
                    }
                    if (home_ == 2)
                    {
                        b_menu_ = true;
                        isrunning_ = true;
                        play_game_ = false;
                        wt_return_ = false;
                    }
                }
            }
            break;
            }
}


