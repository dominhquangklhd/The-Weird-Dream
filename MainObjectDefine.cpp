
#include "MainObject.h"

MainObject::MainObject()
{
    frame_ = 0;
    fAttack_ = 0;
    fPower_ = 0;
    fHits_ = 0;
    fDead_ = 0;

    slowdown_ = 0;
    slowdownAT_ = 0;
    slowdownPW_ = 0;
    slowdownHITS_ = 0;
    slowdownDEAD_ = 0;

    rectPW_.x = ON_THE_GROUND_X;
    rectPW_.y = ON_THE_GROUND_Y;

    x_pos_ = ON_THE_GROUND_X;

    width_frame_ = 0;
    height_frame_ = 0;
    status_ = RUN;

    jumping_ = false;
}

MainObject::~MainObject()
{

}

bool MainObject::LoadImg(std::string path, SDL_Renderer* screen)
{
    bool ret = BaseOJ::LoadImg(path, screen);

    if (ret == true)
    {
        width_frame_ = rect_.w*2;
        height_frame_ = rect_.h*2;
    }

    return ret;
}

void MainObject::Reset_obj()
{
    frame_ = 0;
    fAttack_ = 0;
    fPower_ = 0;
    fHits_ = 0;
    fDead_ = 0;

    slowdown_ = 0;
    slowdownAT_ = 0;
    slowdownPW_ = 0;
    slowdownHITS_ = 0;
    slowdownDEAD_ = 0;

    rectPW_.x = ON_THE_GROUND_X;
    rectPW_.y = ON_THE_GROUND_Y;

    x_pos_ = ON_THE_GROUND_X;

    width_frame_ = 0;
    height_frame_ = 0;
    status_ = RUN;

    jumping_ = false;
    power_ = false;
    hits_ = false;
}

