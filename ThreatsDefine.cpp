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
