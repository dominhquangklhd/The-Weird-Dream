
#include <time.h>
#include "Common_Funtion.h"
#include "BaseOJ.h"
#include "MainObject.h"
#include "Threats.h"
#include "ImgTimer.h"
#include "TextObject.h"
#include "WaterObject.h"
#include "IceObject.h"


BaseOJ g_background;
BaseOJ g_background2;
BaseOJ g_background3;
BaseOJ g_background4;
BaseOJ g_background5;
BaseOJ g_background6;

TTF_Font* font_time;


void init()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    g_window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    TTF_Init();
    font_time = TTF_OpenFont("font-full//VHANTIQ.ttf", 36);
    if (font_time == NULL) std::cout << "font erorr";

}

bool LoadBackground1()
{
    bool ret = g_background.LoadImgBG("Background//Hills Layer 01.png", g_screen);
    if (ret == false) return false;
    return true;
}

bool LoadBackground2()
{
    bool ret = g_background2.LoadImgBG("Background//Hills Layer 02.png", g_screen);
    if (ret == false) return false;
    return true;
}

bool LoadBackground3()
{
    bool ret = g_background3.LoadImgBG("Background//Hills Layer 03.png", g_screen);
    if (ret == false) return false;
    return true;
}

bool LoadBackground4()
{
    bool ret = g_background4.LoadImgBG("Background//Hills Layer 04.png", g_screen);
    if (ret == false) return false;
    return true;
}

bool LoadBackground5()
{
    bool ret = g_background5.LoadImgBG("Background//Hills Layer 05.png", g_screen);
    if (ret == false) return false;
    return true;
}

bool LoadBackground6()
{
    bool ret = g_background6.LoadImgBG("Background//Hills Layer 06.png", g_screen);
    if (ret == false) return false;
    return true;
}


void sdlQuit(SDL_Renderer* renderer, SDL_Window* window)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argv, char* args[])
{

    init();

    TextObject time_game;
    time_game.SetColor(TextObject::BLACK_TEXT);

    LoadBackground1();
    LoadBackground2();
    LoadBackground3();
    LoadBackground4();
    LoadBackground5();
    LoadBackground6();

    MainObject p_player;
    Threats t_threat;
    WaterObject w_water;
    IceObject i_ice;
    ImgTimer t_timer;


    bool isrunning = true;
    while (isrunning)
    {
        t_timer.start();
        //std::cout << t_timer.get_ticks() << std::endl;
        std::string str_time = "Time: ";
        Uint32 current_time = SDL_GetTicks()/1000;
        while  (SDL_PollEvent(&g_event))
        {
            if (g_event.type == SDL_QUIT)
            {
                isrunning = false;
            }
            p_player.HandleInputAction(g_event);
        }

            SDL_RenderClear(g_screen);

            g_background.Render(g_screen, NULL, SPEED_BG_1);
            g_background2.Render(g_screen, NULL, SPEED_BG_2);
            g_background3.Render(g_screen, NULL, SPEED_BG_3);
            g_background4.Render(g_screen, NULL, SPEED_BG_4);
            g_background5.Render(g_screen, NULL, SPEED_BG_5);

            t_threat.Show(g_screen);
            p_player.Show(g_screen);
            w_water.Show(g_screen);
            i_ice.Show(g_screen);
            g_background6.Render(g_screen, NULL, SPEED_BG_6);


            if (p_player.Get_status_Power() == true
                && (p_player.Get_rectPW_().x + 63 >= t_threat.Get_rectThr_().x
                     && (t_threat.Get_rectThr_().x + t_threat.Get_rectThr_().w) >= (p_player.Get_rectPW_().x + 63)))
                     {
                          t_threat.Change_Thr_status_(G_THR_DEAD);
                     }

            if((i_ice.Get_rectICE_().x <= p_player.Get_rectC_().x + p_player.Get_rectC_().w - 40 && p_player.Get_rectC_().x <= i_ice.Get_rectICE_().x + i_ice.Get_rectICE_().w - 20)
                && (p_player.Get_rectC_().y + p_player.Get_rectC_().h >= i_ice.Get_rectICE_().y + 10))
            {
                i_ice.Change_ice_status_(G_ICE_BREAK);
            }

            if (t_threat.Get_num_AT() == 6

                || ((w_water.Get_rectW_().x <= p_player.Get_rectC_().x + p_player.Get_rectC_().w - 40 && p_player.Get_rectC_().x <= w_water.Get_rectW_().x + w_water.Get_rectW_().w - 20)
                && (p_player.Get_rectC_().y + p_player.Get_rectC_().h >= w_water.Get_rectW_().y + 20))

                || ((i_ice.Get_rectICE_().x <= p_player.Get_rectC_().x + p_player.Get_rectC_().w - 40 && p_player.Get_rectC_().x <= i_ice.Get_rectICE_().x + i_ice.Get_rectICE_().w - 20)
                && (p_player.Get_rectC_().y + p_player.Get_rectC_().h >= i_ice.Get_rectICE_().y + 10)))
                {
                    p_player.Change_Char_status_(G_CHAR_DEAD);
                }


//            if (val_time <= 0)
//            {
//                if (MessageBox(NULL, L"GAME OVER", L"Info", MB_OK | MB_ICONSTOP) == IDOK)
//                {
//                    //
//                }
//            }
//            else
           // {
                std::string str_val = std::to_string(current_time);
                str_time += str_val;

                time_game.SetText(str_time);
                time_game.LoadFromRenderText(font_time, g_screen);
                time_game.RenderText(g_screen, WINDOW_WIDTH - 200, 15);
           // }
            SDL_RenderPresent(g_screen);


    }
    SDL_Delay(100);
    sdlQuit(g_screen, g_window);
    return 0;
}
