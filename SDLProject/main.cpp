#define SDL_MAIN_USE_CALLBACKS 1  /* Use the SDL callback system instead of main() */
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#define CIRCLE_RADIUS 20  
#define SPEED 5 

static SDL_Window* window = NULL;  
static SDL_Renderer* renderer = NULL; 



SDL_AppResult SDL_AppInit(void** appstate, int argc, char* argv[])
{
    SDL_SetAppMetadata("Movable Circle", "1.0", "com.example.movable-circle");

    if (!SDL_Init(SDL_INIT_VIDEO)) {  
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }


    if (!SDL_CreateWindowAndRenderer("Movable Circle", 640, 480, 0, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        return SDL_APP_FAILURE;
    }

    return SDL_APP_CONTINUE;  
}

SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
{
    if (event->type == SDL_EVENT_QUIT) {  
        return SDL_APP_SUCCESS;
    }
    return SDL_APP_CONTINUE;
}

//method to draw a cricle of a given radius at point x and y
void DrawCircle(SDL_Renderer* renderer, int cx, int cy, int radius)
{
    for (int w = 0; w < radius * 2; w++) {
        for (int h = 0; h < radius * 2; h++) {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx * dx + dy * dy) <= (radius * radius)) {  // Check if point is within circle boundary
                SDL_RenderPoint(renderer, cx + dx, cy + dy);  // Draw point at (cx + dx, cy + dy)
            }
        }
    }
}

SDL_AppResult SDL_AppIterate(void* appstate)
{
    static double circle_x = 320, circle_y = 240;  // Initial position of the circle
    const bool* state = SDL_GetKeyboardState(NULL);  //returns pointer to array of key states

    //macros to check what the key states are and adjust the speed accordingly
    if (state[SDL_SCANCODE_W]) circle_y -= SPEED;  
    if (state[SDL_SCANCODE_S]) circle_y += SPEED;  
    if (state[SDL_SCANCODE_A]) circle_x -= SPEED;  
    if (state[SDL_SCANCODE_D]) circle_x += SPEED;  

    // make background black
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);

    //draw the circle
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    DrawCircle(renderer, circle_x, circle_y, CIRCLE_RADIUS);

    //draw the frame
    SDL_RenderPresent(renderer);

    return SDL_APP_CONTINUE;  
}


void SDL_AppQuit(void* appstate, SDL_AppResult result)
{
    /* SDL automatically cleans up the window and renderer. */
}
