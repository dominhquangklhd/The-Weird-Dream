#include "IceObject.h"

void IceObject::Show(SDL_Renderer* des)
{
    if (ice_status_ == ICE_ATTACK)
    {
        switch(frame_ice_)
        {
    case 0:
        {
            LoadImg("Ice Frames//VFX 1 Repeatable1.png", des);
        }
        break;
    case 1:
        {
            LoadImg("Ice Frames//VFX 1 Repeatable2.png",des);
        }
        break;
    case 2:
        {
            LoadImg("Ice Frames//VFX 1 Repeatable3.png",des);
        }
        break;
    case 3:
        {
            LoadImg("Ice Frames//VFX 1 Repeatable4.png",des);
        }
        break;
    case 4:
        {
            LoadImg("Ice Frames//VFX 1 Repeatable5.png",des);
        }
        break;
    case 5:
        {
            LoadImg("Ice Frames//VFX 1 Repeatable6.png",des);
        }
        break;
    case 6:
        {
            LoadImg("Ice Frames//VFX 1 Repeatable7.png",des);
        }
        break;
    case 7:
        {
            LoadImg("Ice Frames//VFX 1 Repeatable8.png",des);
        }
        break;
    case 8:
        {
            LoadImg("Ice Frames//VFX 1 Repeatable9.png",des);
        }
        break;
    case 9:
        {
            LoadImg("Ice Frames//VFX 1 Repeatable10.png",des);
        }
        break;
        }

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
        switch(frame_break_)
        {
        case 0:
            {
                LoadImg("Ice Frames//VFX 1 Hit1.png", des);
            }
            break;
        case 1:
            {
                LoadImg("Ice Frames//VFX 1 Hit2.png", des);
            }
            break;
        case 2:
            {
                LoadImg("Ice Frames//VFX 1 Hit3.png", des);
            }
            break;
        case 3:
            {
                LoadImg("Ice Frames//VFX 1 Hit4.png", des);
            }
            break;
        case 4:
            {
                LoadImg("Ice Frames//VFX 1 Hit5.png", des);
            }
            break;
        case 5:
            {
                LoadImg("Ice Frames//VFX 1 Hit6.png", des);
            }
            break;
        case 6:
            {
                LoadImg("Ice Frames//VFX 1 Hit7.png", des);
            }
            break;
        case 7:
            {
                LoadImg("Ice Frames//VFX 1 Hit8.png", des);
            }
            break;
        }


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
