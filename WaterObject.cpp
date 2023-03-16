
#include "WaterObject.h"
#include "MainObject.h"
void WaterObject::Show(SDL_Renderer* des)
 {
//spike
     if (type_W_ == SPIKE)
     {
        switch (W_num_startup_)
        {
        case 0:
            {
            LoadImg("Water//StartUp_type1_1.png", des);
            }
            break;
        case 1:
            {
            LoadImg("Water//StartUp_type1_2.png", des);
            }
            break;
        case 2:
            {
            LoadImg("Water//StartUp_type1_3.png", des);
            }
            break;
        case 3:
            {
            LoadImg("Water//StartUp_type1_4.png", des);
            }
            break;
        case 4:
            {
            LoadImg("Water//StartUp_type1_5.png", des);
            }
            break;
        case 5:
            {
            LoadImg("Water//StartUp_type1_6.png", des);
            }
            break;
        case 6:
            {
            LoadImg("Water//StartUp_type1_7.png", des);
            }
            break;
        case 7:
            {
             LoadImg("Water//StartUp_type1_8.png", des);
            }
            break;
        case 8:
            {
            LoadImg("Water//StartUp_type1_9.png", des);
            }
            break;
        case 9:
            {
            LoadImg("Water//StartUp_type1_10.png", des);
            }
            break;
        case 10:
            {
            LoadImg("Water//StartUp_type1_11.png", des);
            }
            break;
        }

    rectW_.x -= 5;
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
        switch (W_num_attack_)
        {
        case 0:
            {
            LoadImg("Water//Water_spike1_1.png", des);
            }
            break;
        case 1:
            {
            LoadImg("Water//Water_spike1_2.png", des);
            }
            break;
        case 2:
            {
            LoadImg("Water//Water_spike1_3.png", des);
            }
            break;
        case 3:
            {
            LoadImg("Water//Water_spike1_4.png", des);
            }
            break;
        case 4:
            {
            LoadImg("Water//Water_spike1_5.png", des);
            }
            break;
        case 5:
            {
            LoadImg("Water//Water_spike1_6.png", des);
            }
            break;
        case 6:
            {
            LoadImg("Water//Water_spike1_7.png", des);
            }
            break;
        case 7:
            {
             LoadImg("Water//Water_spike1_8.png", des);
            }
            break;
        case 8:
            {
            LoadImg("Water//Water_spike1_9.png", des);
            }
            break;
        case 9:
            {
            LoadImg("Water//Water_spike1_10.png", des);
            }
            break;
        case 10:
            {
            LoadImg("Water//Water_spike1_11.png", des);
            }
            break;
        case 11:
            {
            LoadImg("Water//Water_spike1_12.png", des);
            }
            break;
        case 12:
            {
            LoadImg("Water//Water_spike1_13.png", des);
            }
            break;
        case 13:
            {
            LoadImg("Water//Water_spike1_14.png", des);
            }
            break;
        case 14:
            {
            LoadImg("Water//Water_spike1_15.png", des);
            }
            break;
        case 15:
            {
            LoadImg("Water//Water_spike1_16.png", des);
            }
            break;
        case 16:
            {
            LoadImg("Water//Water_spike1_17.png", des);
            }
            break;
        case 17:
            {
            LoadImg("Water//Water_spike1_18.png", des);
            }
            break;
        }


    rectW_.y = ON_THE_GROUND_Y - 30;
    rectW_.w = width_water_ - 60;
    rectW_.h = height_water_ - 60;

    SDL_RenderCopy(des, p_object_ , NULL, &rectW_);

    rectW_.x -= 5;
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
        switch (W_num_startup_)
        {
        case 0:
            {
            LoadImg("Water//StartUp_type2_1.png", des);
            }
            break;
        case 1:
            {
            LoadImg("Water//StartUp_type2_2.png", des);
            }
            break;
        case 2:
            {
            LoadImg("Water//StartUp_type2_3.png", des);
            }
            break;
        case 3:
            {
            LoadImg("Water//StartUp_type2_4.png", des);
            }
            break;
        case 4:
            {
            LoadImg("Water//StartUp_type2_5.png", des);
            }
            break;
        case 5:
            {
            LoadImg("Water//StartUp_type2_6.png", des);
            }
            break;
        case 6:
            {
            LoadImg("Water//StartUp_type2_7.png", des);
            }
            break;
        case 7:
            {
             LoadImg("Water//StartUp_type2_8.png", des);
            }
            break;
        case 8:
            {
            LoadImg("Water//StartUp_type2_9.png", des);
            }
            break;
        case 9:
            {
            LoadImg("Water//StartUp_type2_10.png", des);
            }
            break;
        case 10:
            {
            LoadImg("Water//StartUp_type2_11.png", des);
            }
            break;
        }

    rectW_.x -= 5;
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
        switch (W_num_attack_)
        {
        case 0:
            {
            LoadImg("Water//Water_splash_1.png", des);
            }
            break;
        case 1:
            {
            LoadImg("Water//Water_splash_2.png", des);
            }
            break;
        case 2:
            {
            LoadImg("Water//Water_splash_3.png", des);
            }
            break;
        case 3:
            {
            LoadImg("Water//Water_splash_4.png", des);
            }
            break;
        case 4:
            {
            LoadImg("Water//Water_splash_5.png", des);
            }
            break;
        case 5:
            {
            LoadImg("Water//Water_splash_6.png", des);
            }
            break;
        case 6:
            {
            LoadImg("Water//Water_splash_7.png", des);
            }
            break;
        case 7:
            {
             LoadImg("Water//Water_splash_8.png", des);
            }
            break;
        case 8:
            {
            LoadImg("Water//Water_splash_9.png", des);
            }
            break;
        case 9:
            {
            LoadImg("Water//Water_splash_10.png", des);
            }
            break;
        case 10:
            {
            LoadImg("Water//Water_splash_11.png", des);
            }
            break;
        case 11:
            {
            LoadImg("Water//Water_splash_12.png", des);
            }
            break;
        case 12:
            {
            LoadImg("Water//Water_splash_13.png", des);
            }
            break;
        case 13:
            {
            LoadImg("Water//Water_splash_14.png", des);
            }
            break;
        case 14:
            {
            LoadImg("Water//Water_splash_15.png", des);
            }
            break;
        case 15:
            {
            LoadImg("Water//Water_splash_16.png", des);
            }
            break;
        case 16:
            {
            LoadImg("Water//Water_splash_17.png", des);
            }
            break;
        case 17:
            {
            LoadImg("Water//Water_splash_18.png", des);
            }
            break;
        }
    rectW_.y = ON_THE_GROUND_Y - 30;
    rectW_.w = width_water_ - 60;
    rectW_.h = height_water_ - 60;

    SDL_RenderCopy(des, p_object_ , NULL, &rectW_);

    rectW_.x -= 5;
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


