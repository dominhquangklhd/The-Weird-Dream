
#include "MainObject.h"

void MainObject::Show(SDL_Renderer* des)
{
//Runnn
    if (status_ == RUN)
    {

    LoadImg(link_run[frame_], des);

    rectC_.x = ON_THE_GROUND_X;
    rectC_.y = ON_THE_GROUND_Y;
    rectC_.w = width_frame_;
    rectC_.h = height_frame_;

    SDL_RenderCopy(des, p_object_ , NULL, &rectC_);

    frame_ = slowdown_/SLOW_ACTION;
    slowdown_++;
    if (slowdown_ >= 8*SLOW_ACTION) slowdown_ = 0;

    }

//Jumpppp
    if (status_ == JUMP)
    {

    if (rectC_.y > MAX_JUMP_Y && jumping_ == true)
    {
        LoadImg("Character//CharacterJUMP3.png", des);
        rectC_.y -= STEP_JUMP;
    }else jumping_ = false;

    if (rectC_.y < ON_THE_GROUND_Y && jumping_ == false)
    {
        LoadImg("Character//CharacterJUMP6.png", des);
        rectC_.y += STEP_JUMP;
        if(rectC_.y == ON_THE_GROUND_Y)
            {
            status_ = RUN;
            }
    }

    SDL_RenderCopy(des, p_object_ , NULL, &rectC_);
    }

//Attackkk
    if (status_ == ATTACK)
    {

    LoadImg(link_attack[fAttack_], des);

    if (rectC_.y < ON_THE_GROUND_Y && fAttack_ <= 7)
    {
        if (rectC_.y > MAX_JUMP_Y && jumping_ == true)
        {
            rectC_.y -= STEP_JUMP;
        }else jumping_ = false;

        if (rectC_.y < ON_THE_GROUND_Y && jumping_ == false)
        {
            rectC_.y += STEP_JUMP;
        }
    }

    SDL_RenderCopy(des, p_object_ , NULL, &rectC_);

    fAttack_ = slowdownAT_/SLOW_ACTION;
    slowdownAT_++;

    if (fAttack_ == 3) power_ = true;

    if (rectC_.y < ON_THE_GROUND_Y && fAttack_ >= 8)
    {
        status_ = JUMP;
        fAttack_ = 0;
        slowdownAT_ = 0;
    }

     if (fAttack_ >= 8 && rectC_.y == ON_THE_GROUND_Y)
     {
        fAttack_ = 0;
        status_ = RUN;
        slowdownAT_ = 0;
     }
    }

//Power
    if (power_ == true)
    {
    LoadImg(link_power[fPower_], des);

    if (fPower_ == 0)
    {
        rectPW_.x = rectC_.x;
        rectPW_.y = rectC_.y -  20;
    }
    else rectPW_.x += 20;

    rectPW_.w = width_frame_;
    rectPW_.h = height_frame_;

    SDL_RenderCopy(des, p_object_ , NULL, &rectPW_);

    fPower_ = slowdownPW_/SLOW_ACTION;
    slowdownPW_++;

    fPower_++;
     if (fPower_ >= 6)
     {
        fPower_ = 0;
        slowdownPW_ = 0;
        x_pos_ = rectPW_.x;
        rectPW_.x = ON_THE_GROUND_X;
        power_ = false;
        hits_ = true;
     }
    }

//hittt
    if (hits_ == true)
    {
    LoadImg(link_hit[fHits_], des);

    fHits_ = slowdownHITS_/SLOW_ACTION;
    slowdownHITS_++;

    if (fHits_ == 0){
    rectHITS_.x = x_pos_ + 45;
    rectHITS_.y = rectPW_.y + 15;
    rectHITS_.w = width_frame_;
    rectHITS_.h = height_frame_;
    }

    SDL_RenderCopy(des, p_object_ , NULL, &rectHITS_);

     if (fHits_ >= 7)
     {
        fHits_ = 0;
        slowdownHITS_ = 0;
        hits_ = false;
     }
    }

    if (status_ == DEAD)
    {

    LoadImg(link_death[fDead_], des);

    if (rectC_.y < ON_THE_GROUND_Y && fAttack_ <= 7)
    {
        if (rectC_.y > MAX_JUMP_Y && jumping_ == true)
        {
            rectC_.y -= STEP_JUMP;
        }else jumping_ = false;

        if (rectC_.y < ON_THE_GROUND_Y && jumping_ == false)
        {
            rectC_.y += STEP_JUMP;
        }
    }

    SDL_RenderCopy(des, p_object_ , NULL, &rectC_);

    fDead_ = slowdownDEAD_/SLOW_ACTION;
    slowdownDEAD_++;

    if (fDead_ > 7) fDead_ = 7;

    if (slowdownDEAD_ >= 8*SLOW_ACTION && rectC_.y == ON_THE_GROUND_Y)
    {
        slowdownDEAD_ = 0;
        status_ = RUN;
        fAttack_ = 0;
        slowdownAT_ = 0;
    }

    }

}

void MainObject::HandleInputAction(SDL_Event events)
{

    if (events.type == SDL_KEYDOWN)
        {
            switch(events.key.keysym.sym)
            {
            case SDLK_SPACE:
                {
                if (rectC_.y == ON_THE_GROUND_Y && fAttack_ == 0 && status_ != DEAD)
                    {
                    if (chunk_jump == NULL) std::cout << "can't load chunkjump" << std::endl;
                    Mix_PlayChannel(JUMP_MUSIC, chunk_jump, 0);
                    status_ = JUMP;
                    jumping_ = true;
                    }
                }
            break;
            case SDLK_t:
                {
                    if (status_ != ATTACK && status_ != DEAD)
                    {
                    Mix_PlayChannel(ATTACK_MUSIC, chunk_attack, 0);
                    status_ = ATTACK;
                    }
                }
            break;
            }
        }

}

void MainObject::Change_Char_status_(int change_s_)
{
    if (change_s_ == RUN) status_ = RUN;
    if (change_s_ == JUMP) status_ = JUMP;
    if (change_s_ == ATTACK) status_ = ATTACK;
    if (change_s_ == DEAD) status_ = DEAD;
}

