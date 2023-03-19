
#include "MainObject.h"

void MainObject::Show(SDL_Renderer* des)
{
//Runnn
    if (status_ == RUN)
    {
        switch (frame_)
        {
        case 0:
            {
            LoadImg("Character//MainCharacter1.png", des);
            }
            break;
        case 1:
            {
            LoadImg("Character//MainCharacter2.png", des);
            }
            break;
        case 2:
            {
            LoadImg("Character//MainCharacter3.png", des);
            }
            break;
        case 3:
            {
            LoadImg("Character//MainCharacter4.png", des);
            }
            break;
        case 4:
            {
            LoadImg("Character//MainCharacter5.png", des);
            }
            break;
        case 5:
            {
            LoadImg("Character//MainCharacter6.png", des);
            }
            break;
        case 6:
            {
            LoadImg("Character//MainCharacter7.png", des);
            }
            break;
        case 7:
            {
            LoadImg("Character//MainCharacter8.png", des);
            }
            break;
        }

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
        switch (fAttack_)
        {
        case 0:
            {
            LoadImg("Character//C_Attack1.png", des);
            }
            break;
        case 1:
            {
            LoadImg("Character//C_Attack2.png", des);
            }
            break;
        case 2:
            {
            LoadImg("Character//C_Attack3.png", des);
            }
            break;
        case 3:
            {
            LoadImg("Character//C_Attack4.png", des);
            }
            break;
        case 4:
            {
            LoadImg("Character//C_Attack5.png", des);
            }
            break;
        case 5:
            {
            LoadImg("Character//C_Attack6.png", des);
            }
            break;
        case 6:
            {
            LoadImg("Character//C_Attack7.png", des);
            }
            break;
        case 7:
            {
            LoadImg("Character//C_Attack8.png", des);
            }
            break;
        }

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


    if (rectC_.y < ON_THE_GROUND_Y && fAttack_ >= 8)
    {
        status_ = JUMP;
        fAttack_ = 0;
        slowdownAT_ = 0;
    }

    SDL_RenderCopy(des, p_object_ , NULL, &rectC_);

    fAttack_ = slowdownAT_/SLOW_ACTION;
    slowdownAT_++;

    if (fAttack_ == 3) power_ = true;

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
        switch (fPower_)
        {
        case 0:
            {
            LoadImg("Character//charged1.png", des);
            }
            break;
        case 1:
            {
            LoadImg("Character//charged2.png", des);
            }
            break;
        case 2:
            {
            LoadImg("Character//charged3.png", des);
            }
            break;
        case 3:
            {
            LoadImg("Character//charged4.png", des);
            }
            break;
        case 4:
            {
            LoadImg("Character//charged5.png", des);
            }
            break;
        case 5:
            {
            LoadImg("Character//charged6.png", des);
            }
            break;
        }

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
        switch (fHits_)
        {
        case 0:
            {
            LoadImg("Character//hits_41.png", des);
            }
            break;
        case 1:
            {
            LoadImg("Character//hits_42.png", des);
            }
            break;
        case 2:
            {
            LoadImg("Character//hits_43.png", des);
            }
            break;
        case 3:
            {
            LoadImg("Character//hits_44.png", des);
            }
            break;
        case 4:
            {
            LoadImg("Character//hits_45.png", des);
            }
            break;
        case 5:
            {
            LoadImg("Character//hits_46.png", des);
            }
            break;
        case 6:
            {
            LoadImg("Character//hits_47.png", des);
            }
            break;
        }

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
        switch (fDead_)
        {
        case 0:
            {
            LoadImg("Character//death1.png", des);
            }
            break;
        case 1:
            {
            LoadImg("Character//death2.png", des);
            }
            break;
        case 2:
            {
            LoadImg("Character//death3.png", des);
            }
            break;
        case 3:
            {
            LoadImg("Character//death4.png", des);
            }
            break;
        case 4:
            {
            LoadImg("Character//death5.png", des);
            }
            break;
        case 5:
            {
            LoadImg("Character//death6.png", des);
            }
            break;
        case 6:
            {
            LoadImg("Character//death7.png", des);
            }
            break;
        case 7:
            {
            LoadImg("Character//death8.png", des);
            }
            break;
        }

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
    std::cout << slowdownDEAD_ << std::endl;
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
                    //Mix_PlayMusic(music_jump, 1);
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

