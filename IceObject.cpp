#include "IceObject.h"

void IceObject::Show(SDL_Renderer* des)
{
    if (ice_status_ == ICE_ATTACK)
    {
        LoadImg(link_attack[frame_ice_], des);

        rectICE_.x -= 10;
        rectICE_.y = ON_THE_GROUND_Y;
        rectICE_.w = width_ice_;
        rectICE_.h = height_ice_;

        SDL_RenderCopy(des, p_object_, NULL, &rectICE_);

        ice_slowndown_++;
        frame_ice_ = ice_slowndown_/SLOW_THREAT;

        if (frame_ice_ >= 10)
        {
            ice_slowndown_ = 0;
            frame_ice_ = 0;
        }

        if (rectICE_.x <= -300)
        {
            rectICE_.x = WINDOW_WIDTH + rand()%100 + 100;
            ice_slowndown_ = 0;
            frame_ice_ = 0;
            num_occurences_++;

        }
    }

    if (ice_status_ == ICE_BREAK)
    {
        LoadImg(link_break[frame_break_], des);

        SDL_RenderCopy(des, p_object_, NULL, &rectICE_);

        iceBR_slowndown++;
        frame_break_ = iceBR_slowndown/SLOW_THREAT;

        if (frame_break_ >= 8)
        {
        rectICE_.x = WINDOW_WIDTH + rand()%100 + 100;
        ice_slowndown_ = 0;
        frame_ice_ = 0;
        iceBR_slowndown = 0;
        frame_break_ = 0;
        ice_status_ = ICE_ATTACK;
        num_occurences_++;
        }
    }
}
