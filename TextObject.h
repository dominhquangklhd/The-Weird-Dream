#ifndef TEXTOBJECT_H_INCLUDED
#define TEXTOBJECT_H_INCLUDED

#include "Common_Funtion.h"

class TextObject
{
public:
    TextObject();
    ~TextObject();
    enum TextColor
    {
        RED_TEXT = 0,
        WHITE_TEXT = 1,
        BLACK_TEXT = 2,
        BROWN_TEXT = 3,
        PINK_TEXT = 4,
    };

    bool LoadFromFile(std::string path);
    bool LoadFromRenderText(TTF_Font* font, SDL_Renderer* screen);
    void Free();

    //void SetColor(Uint32 red, Uint32 green, Uint32 blue);
    void SetColor(const int& type);

    void RenderText(SDL_Renderer* screen,
                    int xp, int yp,
                    SDL_Rect* clip = NULL,
                    double angle = 0.0,
                    SDL_Point* center = NULL,
                    SDL_RendererFlip flip = SDL_FLIP_NONE);
    int GetWidth() {return width_;}
    int GetHeight() {return height_;}

    void SetText(const std::string& text) {str_val_ = text;}
    std::string GetText() {return str_val_;}

    std::string GetHighScoreFromFile(std::string path);
    void UpdateHighScore(std::string path,
                        const int& score,
                        const std::string& old_high_score);

private:
    std::string str_val_;
    SDL_Color text_color_;
    SDL_Texture* texture_;
    int width_;
    int height_;

};

#endif // TEXTOBJECT_H_INCLUDED
