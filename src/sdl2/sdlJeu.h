#ifndef _SDLJEU_H
#define _SDLJEU_H

#ifdef _WIN32
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#endif


#ifdef linux
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#endif

#include "Jeu.h"

//! \brief Pour gérer le Bomberman avec SDL2
class Bomberman {

    private:
        SDL_Surface * surface;
        SDL_Texture * texture;
        bool has_changed;

    public:
        Bomberman () ;
        void loadFromFile (const char* filename, SDL_Renderer * renderer);
        void loadFromCurrentSurface (SDL_Renderer * renderer);
        void draw (SDL_Renderer * renderer, int x, int y, int w=-1, int h=-1);
        SDL_Texture * getTexture() const;
        void setSurface(SDL_Surface * surf);
};

class sdlJeu {

    private :
        Jeu jeu;

        SDL_Window * window;
        SDL_Renderer * renderer;

        TTF_Font * font;
        Bomberman font_im;
        SDL_Color font_color;

        Mix_Chunk * soundBackground;
        bool withSound;

        Bomberman im_perso;
        Bomberman im_in_perso;
        Bomberman im_brique;
        Bomberman im_b1;
        Bomberman im_b2;
        Bomberman im_mur;
        Bomberman im_ter;
        Bomberman im_perdu;

        bool souris;
        bool touche;
        
    public :
        sdlJeu();
        ~sdlJeu();
        void sdlBoucle();
        void sdlAff();
};

#endif
