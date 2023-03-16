#ifndef COMMON_FUNTION_H_INCLUDED
#define COMMON_FUNTION_H_INCLUDED

#include <windows.h>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <string>
#include <vector>
#include <SDL_ttf.h>
#include <SDL_mixer.h>

const int WINDOW_WIDTH = 1260;
const int WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "MyGame";
const int SCREEN_BPP = 32;

static SDL_Window* g_window = NULL;
static SDL_Renderer* g_screen = NULL;
static SDL_Event g_event;

//const int COLOR_KEY_R = 167;
//const int COLOR_KEY_G = 175;
//const int COLOR_KEY_B = 180;

const int G_THR_IDLE = 0;
const int G_THR_ATTACK = 1;
const int G_THR_DEAD = 2;

const int G_CHAR_RUN = 0;
const int G_CHAR_ATTACK = 2;
const int G_CHAR_DEAD = 3;

const int G_ICE_ATTACK = 0;
const int G_ICE_BREAK = 1;

const int SPEED_BG_1 = 1;
const int SPEED_BG_2 = 2;
const int SPEED_BG_3 = 3;
const int SPEED_BG_4 = 4;
const int SPEED_BG_5 = 5;
const int SPEED_BG_6 = 6;

const int NUM_OF_TYPE = 6;
const int ENEMY_TYPE_1 = 0;
const int ENEMY_TYPE_2 = 1;
const int ENEMY_TYPE_3 = 2;
const int ENEMY_TYPE_4 = 3;
const int ENEMY_TYPE_5 = 4;
const int ENEMY_TYPE_6 = 5;

const int THEME_MUSIC = 1;
const int JUMP_MUSIC = 2;
const int ATTACK_MUSIC = 3;


#endif // COMMON_FUNTION_H_INCLUDED
