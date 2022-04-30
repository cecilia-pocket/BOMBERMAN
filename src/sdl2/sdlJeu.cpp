#include <cassert>
#include <time.h>
#include "sdlJeu.h"
#include <stdlib.h>
#include <chrono>


#include <iostream>
using namespace std;

const int TAILLE_SPRITE = 32;

float temps () {
    return float(SDL_GetTicks()) / CLOCKS_PER_SEC;  // conversion des ms en secondes en divisant par 1000
}

// ============= CLASS IMAGE =============== //

Bomberman::Bomberman () {
    surface = NULL;
    texture = NULL;
    has_changed = false;
}

void Bomberman::loadFromFile (const char* filename, SDL_Renderer * renderer) {
    surface = IMG_Load(filename);
    if (surface == NULL) {
        string nfn = string("../") + filename;
        cout << "Error: cannot load "<< filename <<". Trying "<<nfn<<endl;
        surface = IMG_Load(nfn.c_str());
        if (surface == NULL) {
            nfn = string("../") + nfn;
            surface = IMG_Load(nfn.c_str());
        }
    }
    if (surface == NULL) {
        cout<<"Error: cannot load "<< filename <<endl;
        SDL_Quit();
        exit(1);
    }

    SDL_Surface * surfaceCorrectPixelFormat = SDL_ConvertSurfaceFormat(surface,SDL_PIXELFORMAT_ARGB8888,0);
    SDL_FreeSurface(surface);
    surface = surfaceCorrectPixelFormat;

    texture = SDL_CreateTextureFromSurface(renderer,surfaceCorrectPixelFormat);
    if (texture == NULL) {
        cout << "Error: problem to create the texture of "<< filename<< endl;
        SDL_Quit();
        exit(1);
    }
}

void Bomberman::loadFromCurrentSurface (SDL_Renderer * renderer) {
    texture = SDL_CreateTextureFromSurface(renderer,surface);
    if (texture == NULL) {
        cout << "Error: problem to create the texture from surface " << endl;
        SDL_Quit();
        exit(1);
    }
}

void Bomberman::draw (SDL_Renderer * renderer, int x, int y, int w, int h) {
    int ok;
    SDL_Rect r;
    r.x = x;
    r.y = y;
    r.w = (w<0)?surface->w:w;
    r.h = (h<0)?surface->h:h;

    if (has_changed) {
        ok = SDL_UpdateTexture(texture,NULL,surface->pixels,surface->pitch);
        assert(ok == 0);
        has_changed = false;
    }

    ok = SDL_RenderCopy(renderer,texture,NULL,&r);
    assert(ok == 0);
}

SDL_Texture * Bomberman::getTexture() const {return texture;}

void Bomberman::setSurface(SDL_Surface * surf) {surface = surf;}

// ============= CLASS SDLJEU =============== //

sdlJeu::sdlJeu () : jeu() {
    // Initialisation de la SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        cout << "Erreur lors de l'initialisation de la SDL : " << SDL_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if (TTF_Init() != 0) {
        cout << "Erreur lors de l'initialisation de la SDL_ttf : " << TTF_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    int imgFlags = IMG_INIT_PNG | IMG_INIT_JPG;
    if( !(IMG_Init(imgFlags) & imgFlags)) {
        cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << endl;
        SDL_Quit();
        exit(1);
    }

    if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
    {
        cout << "SDL_mixer could not initialize! SDL_mixer Error: " << Mix_GetError() << endl;
        cout << "No sound !!!" << endl;
        //SDL_Quit();exit(1);
        withSound = false;
    }
    else withSound = true;

	int dimx, dimy;
	dimx = jeu.getConstTerrain().getDimX();
	dimy = jeu.getConstTerrain().getDimY();
	dimx = dimx * TAILLE_SPRITE;
	dimy = dimy * TAILLE_SPRITE;

    // Creation de la fenetre
    window = SDL_CreateWindow("Bomberman", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, dimx, dimy, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
    if (window == NULL) {
        cout << "Erreur lors de la creation de la fenetre : " << SDL_GetError() << endl; 
        SDL_Quit(); 
        exit(1);
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // IMAGES
    im_perso.loadFromFile("data/perso.png", renderer);
    im_in_perso.loadFromFile("data/perso.png", renderer);
    im_mur.loadFromFile("data/mur.png", renderer);
    im_brique.loadFromFile("data/brique.png", renderer);
    im_b1.loadFromFile("data/bombe.png", renderer);
    im_b2.loadFromFile("data/bombe.png", renderer);
    im_ter.loadFromFile("data/terrain.png", renderer);
    im_perdu.loadFromFile("data/perdu.png", renderer);

    // SONS
    if (withSound)
    {
        soundBackground = Mix_LoadWAV("data/background.wav");
        Mix_VolumeChunk(soundBackground, MIX_MAX_VOLUME/4);
        if (soundBackground == NULL) {
            soundBackground = Mix_LoadWAV("../data/background.wav");
        }
        if (soundBackground == NULL) {
            cout << "Failed to load wav! SDL_mixer Error: " << Mix_GetError() << endl; 
            SDL_Quit();
            exit(1);
        }
    }
}

sdlJeu::~sdlJeu () {
    if (withSound) Mix_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    //Mix_CloseAudio();
    SDL_Quit();
}

void sdlJeu::sdlAff () {
	//Remplir l'écran de blanc
    SDL_SetRenderDrawColor(renderer, 230, 240, 255, 255);
    SDL_RenderClear(renderer);

	int x,y;
	const Terrain& ter = jeu.getConstTerrain();
	const Personnage& perso = jeu.getConstPerso(0);
    const Personnage& in_perso = jeu.getConstPerso(1);
    const Bombe& b1 = jeu.getConstBombe(0);
    const Bombe& b2 = jeu.getConstBombe(1);
    // Afficher le sprite du sol
    for (x = 0 ; x < ter.getDimX() ; ++x) {
        for (y = 0 ; y < ter.getDimY() ; ++y) {
            im_ter.draw(renderer, x * TAILLE_SPRITE, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
        }
    }

    // Afficher les sprites des murs et des pastilles
	for (x=0 ; x < ter.getDimX() ; ++x) {
        for (y=0 ; y < ter.getDimY() ; ++y) {
            if (ter.getXY(x,y) == '#') {
                im_mur.draw(renderer, x * TAILLE_SPRITE, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
            }	
			else if (ter.getXY(x,y) == '.') {
                im_brique.draw(renderer, x * TAILLE_SPRITE, y * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
            }
        }	
    }
		
	// Afficher le sprite des perso
    if(perso.vivant == true){
        im_in_perso.draw(renderer, perso.getPosX() * TAILLE_SPRITE, perso.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    }
    if(in_perso.vivant == true){
        im_in_perso.draw(renderer, in_perso.getPosX() * TAILLE_SPRITE, in_perso.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    }
    if(b1.estSurLeTerrain == true) {
        im_b1.draw(renderer, b1.getPosX() * TAILLE_SPRITE, b1.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    }
    if(b2.estSurLeTerrain == true) {
        im_b2.draw(renderer, b2.getPosX() * TAILLE_SPRITE, b2.getPosY() * TAILLE_SPRITE, TAILLE_SPRITE, TAILLE_SPRITE);
    }
    if(!perso.vivant || !in_perso.vivant){  
        im_perdu.draw(renderer, 90,50,300,200);
    }
    
    
    // Ecrire un titre par dessus
    SDL_Rect positionTitre;
    positionTitre.x = 270; positionTitre.y = 49; positionTitre.w = 100; positionTitre.h = 30;
    SDL_RenderCopy(renderer, font_im.getTexture(), NULL, &positionTitre);

}

void sdlJeu::sdlBoucle () {
    SDL_Event events;
    bool quit = false;
    auto t0 = chrono::system_clock::now();
    auto t2 = chrono::system_clock::now();
    while (!quit) {
        auto t1 = chrono::system_clock::now();
        jeu.getBombe(0).setTempsExplo((t1 - t0).count());
        if(jeu.getBombe(0).estSurLeTerrain) {
            if(jeu.getBombe(0).getTempsExplo() < 1){            
                jeu.exploserBombe(jeu.getPerso(0), jeu.getTerrain(), jeu.getBombe(0));
                jeu.tuerPerso(jeu.getPerso(1), jeu.getTerrain(), jeu.getBombe(0));
                jeu.tuerPerso(jeu.getPerso(0), jeu.getTerrain(), jeu.getBombe(0));
            }
        }
        auto t3 = chrono::system_clock::now();
        jeu.getBombe(1).setTempsExplo((t3 - t2).count());
        if(jeu.getBombe(1).estSurLeTerrain) {
            if(jeu.getBombe(1).getTempsExplo() < 1){
                jeu.exploserBombe(jeu.getPerso(1), jeu.getTerrain(), jeu.getBombe(1));
                jeu.tuerPerso(jeu.getPerso(1), jeu.getTerrain(), jeu.getBombe(1));
                jeu.tuerPerso(jeu.getPerso(0), jeu.getTerrain(), jeu.getBombe(1));
            }
        }


        while (SDL_PollEvent(&events)) {
            if(jeu.getPerso(0).vivant && jeu.getPerso(1).vivant) {
                if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
                else if (events.type == SDL_KEYDOWN) {              // Si une touche est enfoncee
                    bool briqueExplosee = false;
                    switch (events.key.keysym.sym) {
                        // Commandes du 1er joueur
                        case SDLK_o:
                            briqueExplosee = jeu.actionClavier('b');    // car Y inverse
                            break;
                        case SDLK_l:
                            briqueExplosee = jeu.actionClavier('h');     // car Y inverse
                            break;
                        case SDLK_k:
                            briqueExplosee = jeu.actionClavier('g');
                            break;
                        case SDLK_m:
                            briqueExplosee = jeu.actionClavier('d');
                            break;
                        case SDLK_p:
                            if(!jeu.getBombe(0).estSurLeTerrain) {
                                briqueExplosee = jeu.actionClavier('n');
                                t0 = t1;
                            }
                            break;
                        // Commandes du 2e joueur
                        case SDLK_s:
                            briqueExplosee = jeu.actionClavier('v');    // car Y inverse
                            break;
                        case SDLK_z:
                            briqueExplosee = jeu.actionClavier('j');     // car Y inverse
                            break;
                        case SDLK_q:
                            briqueExplosee = jeu.actionClavier('f');
                            break;
                        case SDLK_d:
                            briqueExplosee = jeu.actionClavier('c');
                            break;
                        case SDLK_a:
                            if(!jeu.getBombe(1).estSurLeTerrain) {
                                briqueExplosee = jeu.actionClavier('u');
                                t2 = t3;
                            }
                            break;
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                        default: break;
                    }
                }
                Mix_PlayChannel(-1,soundBackground,0);
            }
            else if (events.type == SDL_QUIT) quit = true;           // Si l'utilisateur a clique sur la croix de fermeture
                else if (events.type == SDL_KEYDOWN) {               // Si une touche est enfoncee        
                    bool briqueExplosee = false;
                    switch (events.key.keysym.sym) {
                         case SDLK_ESCAPE:
                            quit = true;
                            break;
                        default: break;
                    }
                }
        }
        // On affiche le jeu sur le buffer caché
        sdlAff();
        // On permute les deux buffers (cette fonction ne doit se faire qu'une seule fois dans la boucle)
        SDL_RenderPresent(renderer);
    }
}