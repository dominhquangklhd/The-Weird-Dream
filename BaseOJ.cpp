
#include "BaseOJ.h"
#include "Common_Funtion.h"

BaseOJ::BaseOJ()
{
    p_object_ = NULL;
    rect_.x = 0;
    rect_.y = 0;

    rect2_.x = WINDOW_WIDTH;
    rect2_.y = 0;

}

BaseOJ::~BaseOJ()
{

}

bool BaseOJ::LoadImg(std::string path, SDL_Renderer* screen)
{
    Free();
    p_object_ = IMG_LoadTexture(screen, path.c_str());

    SDL_QueryTexture(p_object_, NULL, NULL, &rect_.w, &rect_.h);

    return p_object_ != NULL;
}

bool BaseOJ::LoadImgBG(std::string pathBG, SDL_Renderer* screenBG)
{

    p_object_ = IMG_LoadTexture(screenBG, pathBG.c_str());

    rect_.w = WINDOW_WIDTH;
    rect_.h = WINDOW_HEIGHT;

    rect2_.w = WINDOW_WIDTH;
    rect2_.h = WINDOW_HEIGHT;

    return p_object_ != NULL;
}

void BaseOJ::Render(SDL_Renderer* des,SDL_Rect* clip, int speed)
{
    SDL_RenderCopy(des, p_object_, clip, &rect_);
    rect_.x -= speed ;
    if (rect_.x <= -WINDOW_WIDTH) rect_.x = WINDOW_WIDTH;

    SDL_RenderCopy(des, p_object_, clip, &rect2_);
    rect2_.x -= speed;
    if (rect2_.x <= -WINDOW_WIDTH) rect2_.x = WINDOW_WIDTH;

}

void BaseOJ::Free()
{
    if (p_object_ != NULL)
    {
        SDL_DestroyTexture(p_object_);
        p_object_ = NULL;

    }
}
