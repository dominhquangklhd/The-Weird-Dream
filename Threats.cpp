#include "Threats.h"
#include "MainObject.h"
#include "time.h"
void Threats::Show(SDL_Renderer* des)
{
//IDLE
    if (Thr_status_ == THR_IDLE)
    {

    LoadImg(link_idle[threat_], des);

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

    LoadImg(link_attack[thrAttack_], des);

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

    LoadImg(link_death[thrDead_], des);

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
