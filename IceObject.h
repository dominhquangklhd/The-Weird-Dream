#ifndef ICEOBJECT_H_INCLUDED
#define ICEOBJECT_H_INCLUDED

#include "BaseOJ.h"
#include "Common_Funtion.h"
#include "Threats.h"

class IceObject : public BaseOJ
{
public:

    IceObject();
    ~IceObject();

    enum ICE
    {
        ICE_ATTACK = 0, ICE_BREAK = 1,
    };

    bool LoadImg(std::string path, SDL_Renderer *screen);
    void Show(SDL_Renderer* des);

    SDL_Rect Get_rectICE_() {return rectICE_;}
    int Change_ice_status_ (int ice_change_);
    int Get_num_occ(){return num_occurences_;}
    int Get_ice_status() {return ice_status_;}

    void Reset_ice();

private:
    SDL_Rect rectICE_;

    int frame_ice_, frame_break_;
    int ice_status_;
    int ice_slowndown_, iceBR_slowndown;

    int width_ice_, height_ice_;

    int num_occurences_ = 0;

};


#endif // ICEOBJECT_H_INCLUDED
