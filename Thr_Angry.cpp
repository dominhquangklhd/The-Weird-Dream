
#include "Thr_Angry.h"

Thr_Angry::Thr_Angry()
{
    rect_angry.x = WINDOW_WIDTH + 100;
    rect_angry.y = 200;

    angry_status = NOR;
}

Thr_Angry::~Thr_Angry()
{

}

void Thr_Angry::Reset_obj()
{
    rect_angry.x = WINDOW_WIDTH + 100;
    rect_angry.y = 200;

    angry_status = NOR;

    num_ing = 0;
    slowdown = 0;
    times_ = 0;

    b_angry = true;
}

bool Thr_Angry::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseOJ::LoadImg(path, screen);

    if (ret == true)
    {
        w_angry = rect_.w;
        h_angry = rect_.h;
    }

    return ret;
}

void Thr_Angry::Show(SDL_Renderer* des)
{
    if (angry_status == NOR && b_angry == true)
    {
        LoadImg("Threats//thr_angry_special.png", des);

        rect_angry.x -= 5;
        rect_angry.w = w_angry;
        rect_angry.h = h_angry;

        SDL_RenderCopy(des, p_object_, NULL, &rect_angry);

        if (rect_angry.x <= WINDOW_WIDTH - rect_angry.w)
        {
            angry_status = ING;
        }
    }

    if (angry_status == ING && b_angry == true)
    {
        switch(num_ing)
        {
        case 0:
            {
                LoadImg("Threats//thr_angry_complete1.png", des);
            }
            break;
        case 1:
            {
                LoadImg("Threats//thr_angry_complete2.png", des);
            }
            break;
        case 2:
            {
                LoadImg("Threats//thr_angry_complete3.png", des);
            }
            break;
        }

        num_ing = slowdown/(SLOW_THREAT + 3);
        slowdown++;

        SDL_RenderCopy(des, p_object_, NULL, &rect_angry);

        if (slowdown >= 3*(SLOW_THREAT + 3))
        {
            slowdown = 0;
            num_ing = 0;
            times_++;
        }
        if (times_ == 10)
        {
            angry_status = NOR_BACK;
        }
    }

    if (angry_status == NOR_BACK && b_angry == true)
    {
        LoadImg("Threats//thr_angry_special.png", des);

        rect_angry.x += 5;
        SDL_RenderCopy(des, p_object_, NULL, &rect_angry);

        if (rect_angry.x >= WINDOW_WIDTH + 100)
        {
            b_angry = false;
        }
    }
}
