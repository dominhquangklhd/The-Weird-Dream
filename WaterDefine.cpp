#include "WaterObject.h"


WaterObject::WaterObject()
{
    type_W_ = SPIKE;

    W_num_startup_ = 0;
    W_num_attack_ = 0;

    W_slowdown_S_ = 0;

    rectW_.x = WINDOW_WIDTH;
}

WaterObject::~WaterObject()
{

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
