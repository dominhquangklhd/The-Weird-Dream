#ifndef THREATS_H_INCLUDED
#define THREATS_H_INCLUDED

#include "MainObject.h"
#include "BaseOJ.h"
#include "time.h"

#define SLOW_THREAT 3
#define GROUND 564


class Threats : public MainObject
{
public:
    Threats();
    ~Threats();

    enum THR_TYPE
    {
        THR_IDLE = 0, THR_DEAD = 1, THR_ATTACK = 2,
    };


    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);


    SDL_Rect Get_rectThr_() const {return rectThr_;}

    void Change_Thr_status_(int change_t_);
    int Get_Threat_status_(){return Thr_status_;}
    int Get_num_AT() {return thrAttack_;}

    int Get_num_occ(){return num_occurences_;}

    void Reset_threat();


private:
    std::string link_idle[6] = {"Threats//idle_1.png", "Threats//idle_2.png", "Threats//idle_3.png",
                                "Threats//idle_4.png", "Threats//idle_5.png", "Threats//idle_6.png"};
    std::string link_attack[7] = {"Threats//1_atk_1.png", "Threats//1_atk_2.png", "Threats//1_atk_3.png",
                                  "Threats//1_atk_4.png", "Threats//1_atk_5.png", "Threats//1_atk_6.png", "Threats//1_atk_7.png"};
    std::string link_death[16] = {"Threats//death_1.png", "Threats//death_2.png", "Threats//death_3.png", "Threats//death_4.png",
                                "Threats//death_5.png", "Threats//death_6.png", "Threats//death_7.png", "Threats//death_8.png",
                                "Threats//death_9.png", "Threats//death_10.png", "Threats//death_11.png", "Threats//death_12.png",
                                "Threats//death_13.png", "Threats//death_14.png", "Threats//death_15.png", "Threats//death_16.png"};
    int width_threat_;
    int height_threat_;

    int Thr_status_;
    int threat_, thrAttack_, thrDead_;
    int Thr_slowdown_, Thr_slowdownAT_, Thr_slowdownDead_;

    SDL_Rect rectThr_, rectThrPW_;

    bool thr_bool_idle_ = false;
    bool thr_bool_attack_ = true;
    bool thr_bool_dead_ = false;

    int num_occurences_ = 0;

};


#endif // THREATS_H_INCLUDED
