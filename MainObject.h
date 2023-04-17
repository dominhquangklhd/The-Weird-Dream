#ifndef MAINOBJECT_H_INCLUDED
#define MAINOBJECT_H_INCLUDED

#include "Common_Funtion.h"
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

    bool Change_b_loadmusic(bool change){b_load_music = change;}

    void Reset_obj();

private:
    std::string link_run[8] = {"Character//MainCharacter1.png", "Character//MainCharacter2.png", "Character//MainCharacter3.png",
                            "Character//MainCharacter4.png", "Character//MainCharacter5.png", "Character//MainCharacter6.png",
                            "Character//MainCharacter7.png", "Character//MainCharacter8.png"};
    std::string link_attack[8] = {"Character//C_Attack1.png", "Character//C_Attack2.png", "Character//C_Attack3.png",
                                "Character//C_Attack4.png", "Character//C_Attack5.png", "Character//C_Attack6.png",
                                "Character//C_Attack7.png", "Character//C_Attack8.png"};
    std::string link_power[6] = {"Character//charged1.png", "Character//charged2.png", "Character//charged3.png",
                                "Character//charged4.png", "Character//charged5.png", "Character//charged6.png"};
    std::string link_hit[7] = {"Character//hits_41.png", "Character//hits_42.png", "Character//hits_43.png", "Character//hits_44.png",
                              "Character//hits_45.png", "Character//hits_46.png", "Character//hits_47.png"};
    std::string link_death[8] = {"Character//death1.png", "Character//death2.png", "Character//death3.png", "Character//death4.png",
                                "Character//death5.png", "Character//death6.png", "Character//death7.png", "Character//death8.png"};

    Mix_Music* music_jump = Mix_LoadMUS("Music Game//Jump_005.wav");
    Mix_Chunk* chunk_jump = Mix_LoadWAV("Music Game//Jump_005.wav");
    Mix_Chunk* chunk_attack = Mix_LoadWAV("Music Game//Explosion_003.wav");

    bool b_load_music = true;

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
