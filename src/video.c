//
// Created by efry on 3/11/2017.
//

#include <SDL_system.h>
#include "video.h"

SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *texture;
SDL_Surface *surface;
SDL_Surface *windowSurface;

void display_fullscreen_image(uint8 image_number)
{

}

void fade_to_black_speed_3()
{

}

void load_status_panel_into_video_mem()
{

}

void struct4_clear_sprites()
{

}

void struct5_clear_sprites()
{

}

void struct6_clear_sprites()
{

}

void struct7_clear_sprites()
{

}

bool video_init()
{
    window = SDL_CreateWindow("Cosmo Engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    if(window == NULL)
    {
        printf("Error: creating SDL Window. %s\n", SDL_GetError());
        return false;
    }

    renderer = SDL_CreateRenderer( window, -1, SDL_RENDERER_ACCELERATED );
    if(renderer == NULL)
    {
        printf("Error: creating render. %s\n", SDL_GetError());
        return false;
    }

    texture = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STREAMING, SCREEN_WIDTH, SCREEN_HEIGHT);
    if(texture == NULL)
    {
        printf("Error: creating texture. %s\n", SDL_GetError());
        return false;
    }

    surface = SDL_CreateRGBSurface(0, SCREEN_WIDTH, SCREEN_HEIGHT, 8, 0, 0, 0, 0);
    if(surface == NULL)
    {
        printf("Error: creating indexed surface. %s\n", SDL_GetError());
        return false;
    }

    windowSurface = SDL_CreateRGBSurface(0,
                           surface->w, surface->h,
                           32, 0, 0, 0, 0);
    if(windowSurface == NULL)
    {
        printf("Error: creating window surface. %s\n", SDL_GetError());
        return false;
    }

    SDL_RenderSetLogicalSize( renderer, SCREEN_WIDTH, SCREEN_HEIGHT );
    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 255 );
    SDL_RenderClear( renderer );
    SDL_RenderPresent( renderer);

    return true;
}

void video_shutdown()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}