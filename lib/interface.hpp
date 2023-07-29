#include <iostream>
#include <cstdlib>
#include <SDL2/SDL.h>
#include <vector>

void drawPos(SDL_Window*,SDL_Renderer*,std::vector<char>);
void drawCircle(SDL_Renderer*,int,int,int);
char getPlayer(std::vector<char>);