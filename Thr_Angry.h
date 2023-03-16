#ifndef THR_ANGRY_H_INCLUDED
#define THR_ANGRY_H_INCLUDED

#include "BaseOJ.h"
#include "Common_Funtion.h"
#include "Threats.h"

class Thr_Angry : public BaseOJ
{
public:
    Thr_Angry();
    ~Thr_Angry();

    enum STATUS
    {
        NOR = 0, ING = 1,NOR_BACK = 2,
    };

    bool LoadImg(std::string path, SDL_Renderer* screen);
    void Show(SDL_Renderer* des);

    SDL_Rect Get_rect_ANGRY() const {return rect_angry;}
    bool Get_bool_angry() {return b_angry;}

private:
    SDL_Rect rect_angry;

    int num_ing = 0;
    int slowdown = 0;
    int times_ = 0;

    int w_angry, h_angry;

    int angry_status;

    bool b_angry = true;


};


#endif // THR_ANGRY_H_INCLUDED
