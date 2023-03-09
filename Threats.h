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


private:

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
