#include <vector>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "./STexture.cpp"
#include "./System.h"
#include "./Components.hpp"


class MovementSystem : public UpdateSystem {
  private:
    int counter = 0;

  public:
    MovementSystem(int c) : counter(c) {}

    void run(double dT) override {
      const auto view = scene->r.view<TransformComponent, MovementComponent>();
      for (const entt::entity e : view) {
        TransformComponent& t = view.get<TransformComponent>(e);
        MovementComponent& m = view.get<MovementComponent>(e);

        if (t.posX <= 0)
        {
          m.velX *= -1;
        }

        if (t.posX >= 640)
        {
          m.velX *= -1;
        }

        if (t.posY <= 0)
        {
          m.velY *= -1;
        }

        if (t.posY >= 480)
        {
          m.velY *= -1;
        }

        t.posX += m.velX * dT;
        t.posY += m.velY * dT;

        std::cout << "x: " << t.posX << std::endl;
        std::cout << "y: " << t.posY << std::endl;
        std::cout << "c: " << counter++ << std::endl;
      }
    }
};

class CubeSystem : public RenderSystem {
  public:
    void run(SDL_Renderer* renderer) override {
      SDL_SetRenderDrawColor(renderer, 255, 100, 100, 1);

      const auto view = scene->r.view<TransformComponent, ColliderComponent>();
      for (const entt::entity e : view) {
        const TransformComponent& t = view.get<TransformComponent>(e);
        const ColliderComponent& c = view.get<ColliderComponent>(e);
        const int x = t.posX;
        const int y = t.posY;
        const int w = c.w;
        const int h = c.h;

        SDL_Rect rect = { x, y, w, h };    
        SDL_RenderFillRect(renderer, &rect);
      }
    }
};

class HelloSystem : public SetupSystem {
  public:
    HelloSystem() {
      std::cout << "Hello System Constructor" << std::endl;
    }

    ~HelloSystem() {
      std::cout << "Hello System Destructor" << std::endl;
    }

    void run() override {
      std::cout << "Hello System!" << std::endl;
    }
};


class TilemapSystem : public SetupSystem, public RenderSystem {
  private:
    SDL_Renderer* renderer;

    constexpr static int tilesCount = 3;
    constexpr static int tilesWidth = 20;
    constexpr static int tilesHeight = 20;

    constexpr static int x = 0;
    constexpr static int y = 0;
    constexpr static int tileWidth = 32;
    constexpr static int tileHeigth = 32;

    constexpr static char mmap[tilesWidth][tilesHeight] = {
      
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0},
{0,0,0,2,0,0,0,0,0,0,0,0,0,0,2,1,1,0,0,0},
{0,0,2,1,2,2,0,0,0,0,0,0,0,2,1,1,1,0,0,0},
{0,0,2,1,1,1,0,0,0,0,0,0,2,1,1,1,0,0,0,0},
{0,0,2,1,1,1,2,0,0,0,2,2,1,1,1,1,0,0,0,0},
{0,0,2,1,1,1,1,2,0,0,2,1,1,1,1,1,2,0,0,0},
{0,0,2,2,1,1,2,0,0,0,2,2,0,0,0,2,2,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,2,0,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,2,2,1,1,2,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,1,2,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,0,2,1,1,1,2,0,0,0},
{0,0,2,2,0,0,0,0,0,0,0,0,0,2,2,2,2,0,0,0},
{0,2,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,2,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,2,1,1,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,2,1,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
{0,0,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    const std::string files[tilesCount] = {
      "assets/tiles/sand.png",
      "assets/tiles/water.png",
      "assets/tiles/grass.png"
    };

    std::map<char, SDL_Texture*> tiles;
    SDL_Texture** tilemap;

  public:
    TilemapSystem(SDL_Renderer* r) : renderer(r) {
      std::cout << "Tile map system started" << std::endl;
      tilemap = new SDL_Texture*[tilesWidth * tilesHeight];
    }

    ~TilemapSystem() {
      /*
      for(int i = 0; i < tilesCount; i++) {
        SDL_FreeSurface(surfaces[i]);
      }
      */
    }

    // setup
    void run() override {
      SDL_Surface* surfaces[tilesCount];

      for(int i = 0; i < tilesCount; i++) {
        surfaces[i] = IMG_Load(files[i].c_str());
      }
      
      for(int i = 0; i < tilesWidth; i++) {
        for(int j = 0; j < tilesHeight; j++) {
          char surfaceIndex = mmap[i][j];
          auto found = tiles.find(surfaceIndex);
          if (found == tiles.end()) {
            SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surfaces[surfaceIndex]);
            tiles.insert(
              std::make_pair(
                surfaceIndex,
                texture
              )
            );
            tilemap[i*tilesWidth + j] = texture;
          } else {
            tilemap[i*tilesWidth + j] = found->second;
          }
        }
      }

      for(int i = 0; i < tilesCount; i++) {
        SDL_FreeSurface(surfaces[i]);
      }
    }

    void run(SDL_Renderer* r) override {
      SDL_Rect rect = { x, y, tileWidth, tileHeigth };

      for(int i = 0; i < tilesWidth; i++) {
        for(int j = 0; j < tilesHeight; j++) {
          SDL_RenderCopy(r, tilemap[i*tilesWidth + j], nullptr, &rect);
          rect.x += tileWidth;
        }
        rect.x = 0;
        rect.y += tileHeigth;
      }
    }
};

