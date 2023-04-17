
#include "WaterObject.h"
#include "MainObject.h"
void WaterObject::Show(SDL_Renderer* des)
 {
//spike
     if (type_W_ == SPIKE)
     {
        LoadImg(link_spike_idle[W_num_startup_], des);

        rectW_.x -= SPEED_BG_5;
        rectW_.y = ON_THE_GROUND_Y + 60;
        rectW_.w = width_water_ - 20;
        rectW_.h = height_water_ - 20;

        SDL_RenderCopy(des, p_object_ , NULL, &rectW_);

        W_num_startup_ = W_slowdown_S_/SLOW_THREAT;
        W_slowdown_S_++;

        if (rectW_.x <= 300 && w_attack_ == true)
        {
            type_W_ = SPIKE_ATTACK;
            W_slowdown_S_ = 0;
            W_num_startup_ = 0;
            W_num_attack_ = 0;
        }

        if (rectW_.x <= -200)
        {
            w_attack_ = true;
            srand(time(0));
            rectW_.x = rand()%100 + WINDOW_WIDTH;
            type_W_ = rand()%2;
            W_slowdown_S_ = 0;
            W_num_startup_ = 0;
            num_occurences_++;
        }

        if (W_num_startup_ >= 11)
        {
            W_slowdown_S_ = 0;
            W_num_startup_ = 0;
        }
    }

//spike_atackkkkkkkk
    if (type_W_ == SPIKE_ATTACK && w_attack_ == true)
    {
    LoadImg(link_spike_attack[W_num_attack_], des);

    rectW_.y = ON_THE_GROUND_Y - 30;
    rectW_.w = width_water_ - 60;
    rectW_.h = height_water_ - 60;

    SDL_RenderCopy(des, p_object_ , NULL, &rectW_);

    rectW_.x -= SPEED_BG_5;
    W_num_attack_ = W_slowdown_S_/SLOW_THREAT;
    W_slowdown_S_++;

    if (W_num_attack_ >= 18)
    {
        W_num_attack_ = 0;
        W_slowdown_S_ = 0;
        type_W_ = SPIKE;
        w_attack_ = false;
    }

    }

//splash

    if (type_W_ == SPLASH)
    {
        LoadImg(link_splash_idle[W_num_startup_], des);

        rectW_.x -= SPEED_BG_5;
        rectW_.y = ON_THE_GROUND_Y + 60;
        rectW_.w = width_water_ - 20;
        rectW_.h = height_water_ - 20;

        SDL_RenderCopy(des, p_object_ , NULL, &rectW_);

        W_num_startup_ = W_slowdown_S_/SLOW_THREAT;
        W_slowdown_S_++;

        if (rectW_.x <= 300 && w_attack_ == true)
        {
            type_W_ = SPLASH_ATTACK;
            W_slowdown_S_ = 0;
            W_num_startup_ = 0;
            W_num_attack_ = 0;
        }

        if (rectW_.x <= -200)
        {
            w_attack_ = true;
            srand(time(0));
            rectW_.x = rand()%100 + WINDOW_WIDTH;
            type_W_ = rand()%2;
            W_slowdown_S_ = 0;
            W_num_startup_ = 0;
            num_occurences_++;
        }

        if (W_num_startup_ >= 11)
        {
            W_slowdown_S_ = 0;
            W_num_startup_ = 0;
        }
    }

//splash_atackkkkkkkk
    if (type_W_ == SPLASH_ATTACK && w_attack_ == true)
    {
        LoadImg(link_splash_attack[W_num_attack_], des);

        rectW_.y = ON_THE_GROUND_Y - 30;
        rectW_.w = width_water_ - 60;
        rectW_.h = height_water_ - 60;

        SDL_RenderCopy(des, p_object_ , NULL, &rectW_);

        rectW_.x -= SPEED_BG_5;
        W_num_attack_ = W_slowdown_S_/(SLOW_THREAT + 3);
        W_slowdown_S_++;

        if (W_num_attack_ >= 18)
        {
            W_num_attack_ = 0;
            W_slowdown_S_ = 0;
            type_W_ = SPLASH;
            w_attack_ = false;
        }
    }
}


