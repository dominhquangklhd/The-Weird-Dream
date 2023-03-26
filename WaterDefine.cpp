#include "WaterObject.h"


WaterObject::WaterObject()
{
    type_W_ = rand()%2;

    W_num_startup_ = 0;
    W_num_attack_ = 0;

    W_slowdown_S_ = 0;

    rectW_.x = WINDOW_WIDTH;
}

WaterObject::~WaterObject()
{

}

void WaterObject::Reset_water()
{
    type_W_ = rand()%2;

    W_num_startup_ = 0;
    W_num_attack_ = 0;

    W_slowdown_S_ = 0;
    num_occurences_ = 0;

    rectW_.x = WINDOW_WIDTH;
    w_attack_ = true;
}

bool WaterObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseOJ::LoadImg(path, screen);
    if (ret == false) std::cout << "can't load image" << std::endl;

    if (ret == true)
    {
        width_water_ = rect_.w * 2;
        height_water_ = rect_.h * 2;
    }

    return ret;
}
