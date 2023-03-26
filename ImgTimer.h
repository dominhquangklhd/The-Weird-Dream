#ifndef IMGTIMER_H_INCLUDED
#define IMGTIMER_H_INCLUDED

#include "SDL.h"
#include "Common_Funtion.h"
#include "BaseOJ.h"

class ImgTimer
{
public:
    ImgTimer();
    ~ImgTimer();

    void start();
    void stop();
    void paused();
    void unpaused();

    int get_ticks();

    bool is_started();
    bool is_paused();

    int get_time(){return start_tick_;}


private:
    int start_tick_;
    int paused_tick_;

    bool is_paused_;
    bool is_started_;

};


#endif // IMGTIMER_H_INCLUDED
