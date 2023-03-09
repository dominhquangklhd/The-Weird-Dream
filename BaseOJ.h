#ifndef BASEOJ_H_INCLUDED
#define BASEOJ_H_INCLUDED

#include "Common_Funtion.h"

class BaseOJ
{
public:
    BaseOJ();
    ~BaseOJ();

    virtual bool LoadImg(std::string path, SDL_Renderer* screen);
    void Render(SDL_Renderer* des, SDL_Rect* clip, int speed);
    void Free();

    bool LoadImgBG(std::string pathBG, SDL_Renderer* screenBG);

protected:
    SDL_Rect rect_;
    SDL_Rect rect2_;
    SDL_Texture* p_object_;
};


#endif // BASEOJ_H_INCLUDED
