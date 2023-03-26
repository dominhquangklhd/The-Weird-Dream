#ifndef MAINOBJECT_H_INCLUDED
#define MAINOBJECT_H_INCLUDED


#include "BaseOJ.h"

#define PLAYER_SPEED 5
#define STEP_JUMP 5
#define MAX_JUMP_Y 350
#define SLOW_ACTION 3
#define ON_THE_GROUND_Y 500
#define ON_THE_GROUND_X 200

class MainObject : public BaseOJ
{
public:
    MainObject();
    ~MainObject();

    enum WalkType
    {
        RUN = 0, JUMP = 1, ATTACK = 2, DEAD = 3,
    };

    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);
    void HandleInputAction(SDL_Event events);

    SDL_Rect Get_rectC_() {return rectC_;}
    SDL_Rect Get_rectPW_() {return rectPW_;}
    void Change_Char_status_(int change_s_);
    bool Get_status_Power() {return power_;}
    int Get_fDead() {return fDead_;}

    void Reset_obj();

private:
    Mix_Music* music_jump = Mix_LoadMUS("Music Game//Jump_005.wav");
    Mix_Chunk* chunk_jump = Mix_LoadWAV("Music Game//Jump_005.wav");
    Mix_Chunk* chunk_attack = Mix_LoadWAV("Music Game//Explosion_003.wav");

    float x_pos_;

    int width_frame_;
    int height_frame_;

    SDL_Rect rectC_;
    SDL_Rect rectPW_;
    SDL_Rect rectHITS_;

    int frame_, fAttack_, fPower_, fHits_, fDead_;
    int slowdown_, slowdownAT_, slowdownPW_, slowdownHITS_, slowdownDEAD_;
    int status_;

    bool jumping_ = false;
    bool power_ = false;
    bool hits_ = false;

};


#endif // MAINOBJECT_H_INCLUDED
