
#include <time.h>
#include "Common_Funtion.h"
#include "BaseOJ.h"
#include "MainObject.h"
#include "Threats.h"
#include "ImgTimer.h"
#include "TextObject.h"
#include "WaterObject.h"
#include "IceObject.h"
#include "Thr_Angry.h"
#include "MenuGame.h"

SDL_Window* g_window = NULL;
SDL_Renderer* g_screen = NULL;
SDL_Event g_event;

BaseOJ g_background;
BaseOJ g_background2;
BaseOJ g_background3;
BaseOJ g_background4;
BaseOJ g_background5;
BaseOJ g_background6;

TTF_Font* font_score;
TTF_Font* htp;
TTF_Font* gf_menu;

Threats t_threat;
WaterObject w_water;
IceObject i_ice;
Thr_Angry a_angry;
BaseOJ out_side_p;

TextObject your_score;
TextObject your_best;
TextObject text_menu_play;
TextObject text_menu_exit;

Mix_Chunk* chunk2;
Mix_Chunk* chunk_angry;
Mix_Chunk* chunk1;



void init()
{
    SDL_Init(SDL_INIT_EVERYTHING);

    g_window = SDL_CreateWindow(WINDOW_TITLE.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    TTF_Init();
    font_score = TTF_OpenFont("font-full//dlxfont.ttf", 30);
    htp = TTF_OpenFont("font-full//dlxfont.ttf", 15);
    gf_menu = TTF_OpenFont("font-full//dlxfont.ttf", 60);

    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, ATTACK_MUSIC, 4096);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, JUMP_MUSIC, 4096);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, THEME_MUSIC, 4096);
    Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, MENU_MUSIC, 4096);

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

void Reset_all()
{
    Mix_FreeChunk(chunk1);
    Mix_FreeChunk(chunk2);
    Mix_FreeChunk(chunk_angry);
    chunk1 = Mix_LoadWAV("Music Game//3_Travel_1_Master.mp3");
    chunk2 = Mix_LoadWAV("Music Game//DavidKBD - Concerto Pack - 02 - In the Hall of the Mountain King (Grieg).ogg");
    chunk_angry = Mix_LoadWAV("Music Game//Suck 1V2.wav");
}

int main(int argv, char* args[])
{

    init();

    MenuGame m_menu;
    MenuGame m_lose;
    MenuGame m_again;
    MenuGame m_home;
    MainObject p_player;
    ImgTimer t_timer;
    TextObject how_to_play1;
    TextObject how_to_play2;

    your_score.SetColor(TextObject::RED_TEXT);
    your_best.SetColor(TextObject::BROWN_TEXT);
    how_to_play1.SetColor(TextObject::RED_TEXT);
    how_to_play2.SetColor(TextObject::RED_TEXT);
    text_menu_play.SetColor(TextObject::PINK_TEXT);
    text_menu_exit.SetColor(TextObject::PINK_TEXT);

    LoadBackground1();
    LoadBackground2();
    LoadBackground3();
    LoadBackground4();
    LoadBackground5();
    LoadBackground6();

    Uint32 past_time;
    Uint32 text_time;

    chunk2 = Mix_LoadWAV("Music Game//DavidKBD - Concerto Pack - 02 - In the Hall of the Mountain King (Grieg).ogg");
    chunk_angry = Mix_LoadWAV("Music Game//Suck 1V2.wav");
    chunk1 = Mix_LoadWAV("Music Game//3_Travel_1_Master.mp3");

    int ene_type, ene_type_lv3;
    int num_ene_past, num_wi_past;
    int NUM_ENEMY_APEAR = 0, NUM_WI;
    int turn = 0;
    int xp = -1200, speed_text = 50;

    bool agree = true;
    bool b_text = true;
    bool b_char_dead = false;
    bool b_menu = true;
    bool isrunning = true;
    bool play_game = true;
    bool b_wt_return = false;

    while (isrunning)
    {
        while(b_menu == true){
        SDL_RenderClear(g_screen);

        isrunning = m_menu.Get_b_isrunning();
        play_game = m_menu.Get_b_play_game();
        b_menu = m_menu.Get_b_menu();
        while  (SDL_PollEvent(&g_event))
        {
            if (g_event.type == SDL_QUIT) return 0;
            m_menu.HandleInputMenu(g_event, MenuGame::NOR);
        }

        m_menu.LoadImgBG("Menu//Main_Menu.png", g_screen);
        m_menu.Show(g_screen);

        out_side_p.LoadImgOutSide("Menu//khung3.png", g_screen, xm_p - 30, ym_p - 75);
        out_side_p.LoadImgOutSide("Menu//khung3.png", g_screen, xm_e - 30, ym_e - 75);

        if (m_menu.Get_n_play() == 1){
        text_menu_play.SetText(m_play);
        text_menu_play.LoadFromRenderText(gf_menu, g_screen);
        text_menu_play.RenderText(g_screen, xm_p, ym_p);
        }
        if (m_menu.Get_n_play() == 2){
        text_menu_play.SetText(m_play2);
        text_menu_play.LoadFromRenderText(gf_menu, g_screen);
        text_menu_play.RenderText(g_screen, xm_p, ym_p);
        }
        if (m_menu.Get_n_exit() == 1){
        text_menu_exit.SetText(m_exit);
        text_menu_exit.LoadFromRenderText(gf_menu, g_screen);
        text_menu_exit.RenderText(g_screen, xm_e, ym_e);
        }
        if (m_menu.Get_n_exit() == 2){
        text_menu_exit.SetText(m_exit2);
        text_menu_exit.LoadFromRenderText(gf_menu, g_screen);
        text_menu_exit.RenderText(g_screen, xm_e, ym_e);
        }

        SDL_RenderPresent(g_screen);
        }
//////////////////
        t_timer.start();
//////////////////
        while (play_game == true){

        int score = t_timer.get_ticks()/100;
        int current_time = t_timer.get_ticks()/1000;

        SDL_RenderClear(g_screen);
        NUM_ENEMY_APEAR = t_threat.Get_num_occ() + i_ice.Get_num_occ() + w_water.Get_num_occ();
        NUM_WI = i_ice.Get_num_occ() + w_water.Get_num_occ();

        if (turn == 0) Mix_PlayChannel(THEME_MUSIC, chunk1, 0);
        if (turn == 0) turn++;

        while  (SDL_PollEvent(&g_event))
        {
            if (g_event.type == SDL_QUIT)
            {
                isrunning = false;
                play_game = false;
            }
            p_player.HandleInputAction(g_event);
        }

            g_background.Render(g_screen, NULL, SPEED_BG_1);
            g_background2.Render(g_screen, NULL, SPEED_BG_2);
            g_background3.Render(g_screen, NULL, SPEED_BG_3);
            g_background4.Render(g_screen, NULL, SPEED_BG_4);
            g_background5.Render(g_screen, NULL, SPEED_BG_5);
//lv1
///////////////////
            if (current_time >= 5)
            {
                if (t_threat.Get_num_occ() == 0) t_threat.Show(g_screen);
                if (t_threat.Get_num_occ() == 1 && i_ice.Get_num_occ() == 0) i_ice.Show(g_screen);
                if (i_ice.Get_num_occ() == 1 && w_water.Get_num_occ() == 0) w_water.Show(g_screen);

                if (i_ice.Get_num_occ() == 1 && w_water.Get_num_occ() == 1) i_ice.Show(g_screen);
                if (w_water.Get_num_occ() == 1 && i_ice.Get_num_occ() == 2) w_water.Show(g_screen);
                if (t_threat.Get_num_occ() == 1 && w_water.Get_num_occ() == 2) t_threat.Show(g_screen);

///////////////////
//lv2
///////////////////////
                if (agree == true && NUM_ENEMY_APEAR >= 6)
                {
                    past_time = current_time;
                    num_ene_past = NUM_ENEMY_APEAR;
                    num_wi_past = NUM_WI;
                    ene_type = rand()%NUM_OF_TYPE;
                    ene_type_lv3 = rand()%2;
                    agree = false;
                }

                if (NUM_ENEMY_APEAR >= 6 && NUM_ENEMY_APEAR < num_lv3)
                {
                    if (ene_type == ENEMY_TYPE_1)
                    {
                        w_water.Show(g_screen);
                        if (current_time - past_time >= 1 && num_ene_past == NUM_ENEMY_APEAR) i_ice.Show(g_screen);
                        if (NUM_ENEMY_APEAR > num_ene_past + 1) agree = true;
                    }
                    if (ene_type == ENEMY_TYPE_2)
                    {
                        w_water.Show(g_screen);
                        if (num_ene_past == NUM_ENEMY_APEAR) i_ice.Show(g_screen);
                        if (NUM_ENEMY_APEAR > num_ene_past + 1) agree = true;
                    }
                    if (ene_type == ENEMY_TYPE_3)
                    {
                        t_threat.Show(g_screen);
                        if (num_ene_past == NUM_ENEMY_APEAR) i_ice.Show(g_screen);
                        if (NUM_ENEMY_APEAR > num_ene_past + 1) agree = true;
                    }
                    if (ene_type == ENEMY_TYPE_4)
                    {
                        t_threat.Show(g_screen);
                        if (num_ene_past == NUM_ENEMY_APEAR) w_water.Show(g_screen);
                        if (NUM_ENEMY_APEAR > num_ene_past + 1) agree = true;
                    }
                    if (ene_type == ENEMY_TYPE_5)
                    {
                        t_threat.Show(g_screen);
                        if (current_time - past_time >= 2 && num_ene_past == NUM_ENEMY_APEAR) i_ice.Show(g_screen);
                        if (NUM_ENEMY_APEAR > num_ene_past + 1) agree = true;
                    }
                    if (ene_type == ENEMY_TYPE_6)
                    {
                        if (current_time - past_time >= 2) w_water.Show(g_screen);
                        if (num_ene_past == NUM_ENEMY_APEAR) t_threat.Show(g_screen);
                        if (NUM_ENEMY_APEAR > num_ene_past + 1) agree = true;
                    }
                }
/////////////////////////
//lv_3
///////////////////////////
                if (NUM_ENEMY_APEAR == num_lv3 && a_angry.Get_bool_angry() == true)
                {
                    if (turn == 1) Mix_PlayChannel(THEME_MUSIC, chunk_angry, 7);
                    if (turn == 1) turn++;
                    a_angry.Show(g_screen);
                }
                if (NUM_ENEMY_APEAR >= num_lv3 && a_angry.Get_bool_angry() == false)
                {
                    if (turn == 2) Mix_PlayChannel(THEME_MUSIC, chunk2, 8);
                    if (turn == 2) turn++;

                    if (ene_type_lv3 == ENEMY_TYPE_1)
                    {
                        w_water.Show(g_screen);
                        if (current_time - past_time >= 1 && num_wi_past == NUM_WI) i_ice.Show(g_screen);
                        if (NUM_WI > num_wi_past + 1) agree = true;
                    }
                    if (ene_type_lv3 == ENEMY_TYPE_2)
                    {
                        w_water.Show(g_screen);
                        if (num_wi_past == NUM_WI) i_ice.Show(g_screen);
                        if (NUM_WI > num_wi_past + 1) agree = true;
                    }
                    t_threat.Show(g_screen);
                }
            }
////////////////////////

                p_player.Show(g_screen);
                g_background6.Render(g_screen, NULL, SPEED_BG_6);

//thr_dead
            if (p_player.Get_status_Power() == true
                && (p_player.Get_rectPW_().x + 63 >= t_threat.Get_rectThr_().x
                && (t_threat.Get_rectThr_().x + t_threat.Get_rectThr_().w) >= (p_player.Get_rectPW_().x + 63)))
                    t_threat.Change_Thr_status_(G_THR_DEAD);

//ice_break
            if((i_ice.Get_rectICE_().x <= p_player.Get_rectC_().x + p_player.Get_rectC_().w - 40 && p_player.Get_rectC_().x <= i_ice.Get_rectICE_().x + i_ice.Get_rectICE_().w - 20)
                && (p_player.Get_rectC_().y + p_player.Get_rectC_().h >= i_ice.Get_rectICE_().y + 10))
                    i_ice.Change_ice_status_(G_ICE_BREAK);

//character_dead
            if (b_char_dead == false){
            if (t_threat.Get_num_AT() == 6

                || ((w_water.Get_rectW_().x <= p_player.Get_rectC_().x + p_player.Get_rectC_().w - 40 && p_player.Get_rectC_().x <= w_water.Get_rectW_().x + w_water.Get_rectW_().w - 20)
                && (p_player.Get_rectC_().y + p_player.Get_rectC_().h >= w_water.Get_rectW_().y + 20))

                || ((i_ice.Get_rectICE_().x <= p_player.Get_rectC_().x + p_player.Get_rectC_().w - 40 && p_player.Get_rectC_().x <= i_ice.Get_rectICE_().x + i_ice.Get_rectICE_().w - 20)
                && (p_player.Get_rectC_().y + p_player.Get_rectC_().h >= i_ice.Get_rectICE_().y + 10)))
                {
                    p_player.Change_Char_status_(G_CHAR_DEAD);
                    b_char_dead = true;
                }
            }

///////////////////delay
//        int delta_time = t_timer.get_ticks();
//        int time_one_frame = 1000/FRAME_PER_SECOND;
//
//        std::cout << delta_time << std::endl;
//        if (delta_time < time_one_frame)
//        {
//            SDL_Delay(time_one_frame - delta_time);
//        }
/////////////////////////
        std::string str_val = std::to_string(score);
        your_score.SetText(str_val);
        your_score.LoadFromRenderText(font_score, g_screen);

        if (score < 10)  your_score.RenderText(g_screen, WINDOW_WIDTH - 40, 15);
        if (score >= 10 && score < 100) your_score.RenderText(g_screen, WINDOW_WIDTH - 70, 15);
        if (score >= 100 && score < 1000) your_score.RenderText(g_screen, WINDOW_WIDTH - 100, 15);
        if (score >= 1000 && score < 10000) your_score.RenderText(g_screen, WINDOW_WIDTH - 120, 15);
        if (score >= 10000 && score < 100000) your_score.RenderText(g_screen, WINDOW_WIDTH - 150, 15);
        if (score >= 100000) your_score.RenderText(g_screen, WINDOW_WIDTH - 180, 15);

        your_best.SetText(highest_score);
        your_best.LoadFromRenderText(font_score, g_screen);
        your_best.RenderText(g_screen, WINDOW_WIDTH/2 - 150, 15);

        if (xp <= WINDOW_WIDTH)
        {
            if (xp < 10) xp += speed_text;
            if (xp >= 10 && b_text == true)
            {
                text_time = current_time;
                b_text = false;
            }
            if (current_time - text_time >= 5 && b_text == false)
            {
                xp += speed_text;
            }

            how_to_play1.SetText(help1);
            how_to_play1.LoadFromRenderText(htp, g_screen);
            how_to_play1.RenderText(g_screen, xp, 60);

            how_to_play2.SetText(help2);
            how_to_play2.LoadFromRenderText(htp, g_screen);
            how_to_play2.RenderText(g_screen, xp, 85);
        }

            if (m_menu.Get_mrect().y + WINDOW_HEIGHT >= 0){
            m_menu.LoadImgBG("Menu//Main_Menu.png", g_screen);
            m_menu.MoveImg(g_screen);
            }
//////play_again
            if (b_char_dead == true && p_player.Get_fDead() == 7 && p_player.Get_rectC_().y == ON_THE_GROUND_Y){
                SDL_Delay(1000);

                xp = -1200;
                b_char_dead = false;
                b_wt_return = true;
                b_text = true;
                turn = 0;

                Reset_all();
                m_menu.Reset_menu();
                p_player.Reset_obj();
                w_water.Reset_water();
                i_ice.Reset_ice();
                t_threat.Reset_threat();
                while (b_wt_return == true)
                {
                    m_lose.LoadImgCommon("Menu//Want_to_return.png", g_screen, 218, 20, 0, 0);
                    m_lose.Show(g_screen);
                    m_again.LoadImgCommon("Menu//Again1.png", g_screen, xm_a, ym_a, 100, 100);
                    m_again.Show(g_screen);
                    m_home.LoadImgCommon("Menu//Home1.png", g_screen, xm_h, ym_h, 100, 100);
                    m_home.Show(g_screen);

                    while (SDL_PollEvent(&g_event)){
                    m_again.HandleInputMenu(g_event, MenuGame::LOSE);
                    m_home.HandleInputMenu(g_event, MenuGame::LOSE);
                    if (g_event.type == SDL_QUIT) return 0;
                    }

                    if (m_again.Get_n_again() == 2){
                    m_again.LoadImgCommon("Menu//Again2.png", g_screen, xm_a, ym_a, 100, 100);
                    b_menu = m_again.Get_b_menu();
                    play_game = m_again.Get_b_play_game();
                    b_wt_return = m_again.Get_b_wt_return();
                    }
                    if (m_home.Get_n_home() == 2){
                    m_home.LoadImgCommon("Menu//Home2.png", g_screen, xm_h, ym_h, 100, 100);
                    b_menu = m_home.Get_b_menu();
                    play_game = m_home.Get_b_play_game();
                    b_wt_return = m_again.Get_b_wt_return();
                    }
                    SDL_RenderPresent(g_screen);
                }
                m_again.Reset_menu();
                m_home.Reset_menu();
                t_timer.start();
            }
/////////////////////////
            SDL_RenderPresent(g_screen);
        }//finish_playgame
    }
    SDL_Delay(100);
    sdlQuit(g_screen, g_window);
    return 0;
}


