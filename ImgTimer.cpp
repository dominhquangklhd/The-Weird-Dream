
#include "ImgTimer.h"

ImgTimer::ImgTimer()
{
    start_tick_ = 0;
    paused_tick_ = 0;
    is_paused_ = false;
    is_started_ = false;
}

ImgTimer::~ImgTimer(){}

void ImgTimer::start()
{
    is_started_ = true;
    is_paused_ = false;
    start_tick_ = SDL_GetTicks();
}

void ImgTimer::stop()
{
    is_paused_ = false;
    is_started_ = false;
}

void ImgTimer::paused()
{
    if (is_started_ == true && is_paused_ == false)
    {
        is_paused_ = true;
        paused_tick_ = SDL_GetTicks() - start_tick_;
    }
}

void ImgTimer::unpaused()
{
    if (is_paused_ == true)
    {
        is_paused_ = false;
        start_tick_ = SDL_GetTicks() - paused_tick_;
        paused_tick_ = 0;
    }
}

int ImgTimer::get_ticks()
{
    if (is_started_ == true)
    {
        if (is_paused_ == true)
        {
            return paused_tick_;
        }
        else
        {
            return SDL_GetTicks() - start_tick_;
        }
    }
    return 0;
}

bool ImgTimer::is_started()
{
    return is_started_;
}

bool ImgTimer::is_paused()
{
    return is_paused_;
}



