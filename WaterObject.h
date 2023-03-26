#ifndef WATEROBJECT_H_INCLUDED
#define WATEROBJECT_H_INCLUDED

#include "BaseOJ.h"
#include "MainObject.h"
#include "Threats.h"
#include "time.h"

//water

class WaterObject : public BaseOJ
{
public:
    WaterObject();
    ~WaterObject();

    enum TYPE_WATER
    {
        SPIKE = 0, SPLASH = 1, SPIKE_ATTACK = 2, SPLASH_ATTACK = 3,
    };

    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);

    SDL_Rect Get_rectW_() const {return rectW_;}
    int Get_num_occ(){return num_occurences_;}

    void Reset_water();

private:

    int width_water_;
    int height_water_;

    bool w_attack_ = true;

    int W_num_startup_, W_num_attack_;
    int W_slowdown_S_ = 0;

    int type_W_;

    SDL_Rect rectW_;

    int num_occurences_ = 0;

};


#endif // WATEROBJECT_H_INCLUDED
