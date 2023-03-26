
#include "IceObject.h"

IceObject::IceObject()
{
    iceBR_slowndown = 0;
    ice_slowndown_ = 0;
    frame_ice_ = 0;
    frame_break_ = 0;

    rectICE_.y = ON_THE_GROUND_Y;
    rectICE_.x = WINDOW_WIDTH;
    rectICE_.w = width_ice_;
    rectICE_.h = height_ice_;

    ice_status_ = ICE_ATTACK;

}

IceObject::~IceObject()
{

}

bool IceObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseOJ::LoadImg(path, screen);

    if (ret == false) std::cout << "can't load ice" << std::endl;
    if (ret == true)
    {
        width_ice_ = rect_.w*2;
        height_ice_ = rect_.h*2;
    }

    return ret;
}

int IceObject::Change_ice_status_(int ice_change_)
{
    if (ice_change_ == ICE_ATTACK) ice_status_ = ICE_ATTACK;
    if (ice_change_ == ICE_BREAK) ice_status_ = ICE_BREAK;
}

void IceObject::Reset_ice()
{
    iceBR_slowndown = 0;
    ice_slowndown_ = 0;
    frame_ice_ = 0;
    frame_break_ = 0;

    rectICE_.y = ON_THE_GROUND_Y;
    rectICE_.x = WINDOW_WIDTH;
    rectICE_.w = width_ice_;
    rectICE_.h = height_ice_;

    ice_status_ = ICE_ATTACK;
    num_occurences_ = 0;
}
