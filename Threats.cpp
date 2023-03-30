#include "Threats.h"
#include "MainObject.h"
#include "time.h"
void Threats::Show(SDL_Renderer* des)
{
//IDLE
    if (Thr_status_ == THR_IDLE)
    {
        switch (threat_)
        {
        case 0:
            {
            LoadImg("Threats//idle_1.png", des);
            }
            break;
        case 1:
            {
            LoadImg("Threats//idle_2.png", des);
            }
            break;
        case 2:
            {
            LoadImg("Threats//idle_3.png", des);
            }
            break;
        case 3:
            {
            LoadImg("Threats//idle_4.png", des);
            }
            break;
        case 4:
            {
            LoadImg("Threats//idle_5.png", des);
            }
            break;
        case 5:
            {
            LoadImg("Threats//idle_6.png", des);
            }
            break;
        }

    rectThr_.x -= SPEED_BG_5;
    rectThr_.y = GROUND - height_threat_ - 50 + 40;
    rectThr_.w = width_threat_ + 50;
    rectThr_.h = height_threat_ + 50;

    SDL_RenderCopy(des, p_object_ , NULL, &rectThr_);

    threat_ = Thr_slowdown_/SLOW_THREAT;
    Thr_slowdown_++;

    if (rectThr_.x <= 350 && thr_bool_attack_ == true)
    {
        Thr_status_ = THR_ATTACK;
        thrAttack_ = 0;
        Thr_slowdownAT_ = 0;
    }

    if (rectThr_.x <= -400)
    {
        srand(time(0));
        rectThr_.x = rand()%100 + WINDOW_WIDTH;
        thr_bool_attack_ = true;
        num_occurences_++;
    }
    if (threat_ >= 6)
    {
        Thr_slowdown_ = 0;
        threat_ = 0;
    }

    }

//thr_attack

    if (Thr_status_ == THR_ATTACK)
    {
        switch (thrAttack_)
        {
        case 0:
            {
            LoadImg("Threats//1_atk_1.png", des);
            }
            break;
        case 1:
            {
            LoadImg("Threats//1_atk_2.png", des);
            }
            break;
        case 2:
            {
            LoadImg("Threats//1_atk_3.png", des);
            }
            break;
        case 3:
            {
            LoadImg("Threats//1_atk_4.png", des);
            }
            break;
        case 4:
            {
            LoadImg("Threats//1_atk_5.png", des);
            }
            break;
        case 5:
            {
            LoadImg("Threats//1_atk_6.png", des);
            }
            break;
        case 6:
            {
            LoadImg("Threats//1_atk_7.png", des);
            }
            break;
        }

    rectThr_.x -= SPEED_BG_5;

    SDL_RenderCopy(des, p_object_ , NULL, &rectThr_);

    if (thrAttack_ == 6)
    {
        LoadImg("Threats//threat_hit6.png", des);

        rectThrPW_.x = rectThr_.x - 60;
        rectThrPW_.y = rectThr_.y + 35;
        rectThrPW_.w = width_threat_ + 150;
        rectThrPW_.h = height_threat_ + 150;

        SDL_RenderCopy(des, p_object_ , NULL, &rectThrPW_);
    }

    thrAttack_ = Thr_slowdownAT_/(SLOW_THREAT + 1);
    Thr_slowdownAT_++;


    if (thrAttack_ >= 7)
    {
         Thr_slowdownAT_ = 0;
         thrAttack_ = 0;
         Thr_status_ = THR_IDLE;
         thr_bool_attack_ = false;
    }
    }


//th_dead
    if (Thr_status_ == THR_DEAD)
    {
        switch (thrDead_)
        {
        case 0:
            {
            LoadImg("Threats//death_1.png", des);
            }
            break;
        case 1:
            {
            LoadImg("Threats//death_2.png", des);
            }
            break;
        case 2:
            {
            LoadImg("Threats//death_3.png", des);
            }
            break;
        case 3:
            {
            LoadImg("Threats//death_4.png", des);
            }
            break;
        case 4:
            {
            LoadImg("Threats//death_5.png", des);
            }
            break;
        case 5:
            {
            LoadImg("Threats//death_6.png", des);
            }
            break;
        case 6:
            {
            LoadImg("Threats//death_7.png", des);
            }
            break;
        case 7:
            {
            LoadImg("Threats//death_8.png", des);
            }
            break;
        case 8:
            {
            LoadImg("Threats//death_9.png", des);
            }
            break;
        case 9:
            {
            LoadImg("Threats//death_10.png", des);
            }
            break;
        case 10:
            {
            LoadImg("Threats//death_11.png", des);
            }
            break;
        case 11:
            {
            LoadImg("Threats//death_12.png", des);
            }
            break;
        case 12:
            {
            LoadImg("Threats//death_13.png", des);
            }
            break;
        case 13:
            {
            LoadImg("Threats//death_14.png", des);
            }
            break;
        case 14:
            {
            LoadImg("Threats//death_15.png", des);
            }
            break;
        case 15:
            {
            LoadImg("Threats//death_16.png", des);
            }
            break;
        }

    rectThr_.x -= SPEED_BG_5;

    SDL_RenderCopy(des, p_object_ , NULL, &rectThr_);

    thrDead_ = Thr_slowdownDead_/SLOW_THREAT;
    if(Thr_slowdownDead_ < 15*SLOW_THREAT) Thr_slowdownDead_++;

    if (rectThr_.x <= -400)
    {
         rectThr_.x = WINDOW_WIDTH;
         Thr_slowdownDead_ = 0;
         thrDead_ = 0;

         thrAttack_ = 0;
         Thr_slowdownAT_ = 0;

         Thr_status_ = THR_IDLE;
         thr_bool_attack_ = true;
         num_occurences_++;
    }
    }

}

void Threats::Change_Thr_status_(int change_t_)
{
    if (change_t_ == G_THR_IDLE) Thr_status_ = THR_IDLE;
    if (change_t_ == G_THR_ATTACK) Thr_status_ = THR_ATTACK;
    if (change_t_ == G_THR_DEAD) Thr_status_ = THR_DEAD;
}
