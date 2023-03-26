#include "Threats.h"

Threats::Threats()
{
    threat_ = 0;
    thrAttack_ = 0;
    thrDead_ = 0;

    Thr_slowdown_ = 0;
    Thr_slowdownAT_ = 0;
    Thr_slowdownDead_ = 0;

    Thr_status_ = THR_IDLE;
    rectThr_.x = WINDOW_WIDTH;

}


Threats::~Threats()
{
    threat_ = 0;
    thrAttack_ = 0;
    thrDead_ = 0;

    Thr_slowdown_ = 0;
    Thr_slowdownAT_ = 0;
    Thr_slowdownDead_ = 0;

    Thr_status_ = THR_IDLE;
    rectThr_.x = WINDOW_WIDTH;
}

void Threats::Reset_threat()
{
    threat_ = 0;
    thrAttack_ = 0;
    thrDead_ = 0;

    Thr_slowdown_ = 0;
    Thr_slowdownAT_ = 0;
    Thr_slowdownDead_ = 0;

    Thr_status_ = THR_IDLE;
    rectThr_.x = WINDOW_WIDTH;

    thr_bool_idle_ = false;
    thr_bool_attack_ = true;
    thr_bool_dead_ = false;

    num_occurences_ = 0;
}

bool Threats::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseOJ::LoadImg(path, screen);

    if (ret == true)
    {
        width_threat_ = rect_.w * 2 - 50;
        height_threat_ = rect_.h * 2 - 50;
    }

    return ret;
}
