#include "MenuGame.h"

MenuGame::MenuGame()
{
    m_rect.x = 0;
    m_rect.y = 0;
}

MenuGame::~MenuGame(){}

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

void MenuGame::HandleInputMenu(SDL_Event m_event)
{
    switch(m_event.type)
        {
        case SDL_MOUSEMOTION:
            {
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
            break;
        case SDL_MOUSEBUTTONDOWN:
            {
                if (play_ == 2)
                {
                Mix_PlayChannel(MENU_MUSIC, menu_play2, 0);
                b_menu_ = false;
                isrunning_ = true;
                }
                if (exit_ == 2)
                {
                Mix_PlayChannel(MENU_MUSIC, menu_exit2, 0);
                b_menu_ = false;
                isrunning_ = false;
                play_game_ = false;
                SDL_Delay(300);
                }
            }
            break;
            }
}
