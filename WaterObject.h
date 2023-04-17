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

    std::string link_spike_idle[11] = {"Water//StartUp_type1_1.png", "Water//StartUp_type1_2.png", "Water//StartUp_type1_3.png", "Water//StartUp_type1_4.png",
                                    "Water//StartUp_type1_5.png", "Water//StartUp_type1_6.png", "Water//StartUp_type1_7.png", "Water//StartUp_type1_8.png",
                                    "Water//StartUp_type1_9.png", "Water//StartUp_type1_10.png", "Water//StartUp_type1_11.png"};
    std::string link_spike_attack[18] = {"Water//Water_spike1_1.png", "Water//Water_spike1_2.png", "Water//Water_spike1_3.png", "Water//Water_spike1_4.png",
                                        "Water//Water_spike1_5.png", "Water//Water_spike1_6.png", "Water//Water_spike1_7.png", "Water//Water_spike1_8.png",
                                        "Water//Water_spike1_9.png", "Water//Water_spike1_10.png", "Water//Water_spike1_11.png", "Water//Water_spike1_12.png",
                                        "Water//Water_spike1_13.png", "Water//Water_spike1_14.png", "Water//Water_spike1_15.png", "Water//Water_spike1_16.png",
                                        "Water//Water_spike1_17.png", "Water//Water_spike1_18.png"};
    std::string link_splash_idle[11] = {"Water//StartUp_type2_1.png", "Water//StartUp_type2_2.png", "Water//StartUp_type2_3.png", "Water//StartUp_type2_4.png",
                                    "Water//StartUp_type2_5.png", "Water//StartUp_type2_6.png", "Water//StartUp_type2_7.png", "Water//StartUp_type2_8.png",
                                    "Water//StartUp_type2_9.png", "Water//StartUp_type2_10.png", "Water//StartUp_type2_11.png"};
    std::string link_splash_attack[18] = {"Water//Water_splash_1.png", "Water//Water_splash_2.png", "Water//Water_splash_3.png", "Water//Water_splash_4.png",
                                        "Water//Water_splash_5.png", "Water//Water_splash_6.png", "Water//Water_splash_7.png", "Water//Water_splash_8.png",
                                        "Water//Water_splash_9.png", "Water//Water_splash_10.png", "Water//Water_splash_11.png", "Water//Water_splash_12.png",
                                        "Water//Water_splash_13.png", "Water//Water_splash_14.png", "Water//Water_splash_15.png", "Water//Water_splash_16.png",
                                        "Water//Water_splash_17.png", "Water//Water_splash_18.png"};
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
