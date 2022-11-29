#include <vector>
#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include "./STexture.cpp"
#include "./System.h"
#include "./Components.hpp"

class MovementUpdateSystem : public UpdateSystem {
    public:
        void run(double dT) override {
          const auto view = scene->r.view<TransformComponent, MovementComponent>();
          for (const entt::entity e : view) {
            auto& pos = view.get<TransformComponent>(e);
            const auto vel = view.get<MovementComponent>(e);

            pos.posX += vel.velX * dT;
            pos.posY += vel.velY * dT;
          }
        }
};

class PlayerInputSystem : public InputSystem {
  public:
    void run(SDL_Event event) override {
      auto& playerMovement = scene->player->getComponent<MovementComponent>();

      int speed = 100;

      if (event.type == SDL_KEYDOWN)
      {
        switch (event.key.keysym.sym) {
          case SDLK_LEFT:
            playerMovement.velX = -speed;
            break;
          case SDLK_RIGHT:
            playerMovement.velX = speed;
            break;
          case SDLK_UP:
            playerMovement.velY = -speed;
            break;
          case SDLK_DOWN:
            playerMovement.velY = speed;
            break;
        }
      }  
      if (event.type == SDL_KEYUP)
      {
        switch (event.key.keysym.sym) {
          case SDLK_LEFT:
            playerMovement.velX = 0;
            break;
          case SDLK_RIGHT:
            playerMovement.velX =  0;
            break;
          case SDLK_UP:
            playerMovement.velY = 0;
            break;
          case SDLK_DOWN:
            playerMovement.velY = 0;
            break;
        }
      }
    }
};

class CharacterSetupSystem : public SetupSystem {
    private:
        const std::string spritefile = "./assets/characters/main/front/rambi.png";        
        SDL_Renderer* renderer;

    public:
        CharacterSetupSystem(SDL_Renderer* r) : renderer(r) {}

        ~CharacterSetupSystem() {}

        void run() override {


          SDL_Surface* surface = IMG_Load(spritefile.c_str());
          SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
          SDL_FreeSurface(surface);

          Entity player = scene->createEntity(
            "PLAYER",
            100, 100
          );
          player.addComponent<MovementComponent>(100, 100);
          player.addComponent<SpriteComponent>(0, 0, 32, texture);
          scene->player = new Entity(player);
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

    constexpr static int tilesCount = 4;
    constexpr static int tilesWidth = 20;
    constexpr static int tilesHeight = 20;

    constexpr static int x = 0;
    constexpr static int y = 0;
    constexpr static int tileWidth = 32;
    constexpr static int tileHeigth = 32;

    constexpr static char mmap[tilesWidth][tilesHeight] = {
      
{0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,3,0,0,0},
{0,0,0,3,0,0,0,0,0,0,0,0,0,0,3,2,2,3,0,0},
{0,0,3,2,3,3,0,0,0,0,0,0,0,3,2,1,1,2,3,0},
{0,3,2,1,2,2,3,0,0,0,0,0,3,2,1,1,1,2,3,0},
{0,3,2,1,1,1,3,0,0,0,0,3,2,1,1,1,2,3,3,0},
{0,3,2,1,1,1,2,3,0,0,2,2,1,1,1,1,2,3,0,0},
{0,3,2,1,1,1,1,2,0,0,2,1,1,1,1,1,2,3,0,0},
{0,3,2,2,1,1,2,3,0,0,3,2,2,2,2,2,2,3,0,0},
{0,3,3,3,2,2,3,3,0,0,0,0,0,3,3,3,3,3,0,0},
{0,0,0,3,3,3,3,0,0,0,0,3,3,3,2,2,3,0,0,0},
{0,0,0,0,0,0,0,0,0,0,0,2,2,2,1,1,2,3,0,0},
{0,0,0,0,0,0,0,0,0,0,3,2,1,1,1,1,2,3,0,0},
{0,0,0,0,0,0,0,0,0,0,3,2,1,1,1,1,2,3,0,0},
{0,3,3,3,0,0,0,0,0,0,3,3,2,1,1,1,2,3,0,0},
{0,3,2,2,3,3,0,0,0,0,0,3,3,2,2,2,2,3,0,0},
{3,2,1,1,2,2,3,3,0,0,0,0,3,3,3,3,3,3,0,0},
{3,2,1,1,1,1,2,3,0,0,0,0,0,0,0,0,0,0,0,0},
{3,2,1,1,1,1,2,3,0,0,0,0,0,0,0,0,0,0,0,0},
{0,3,2,1,1,2,3,3,0,0,0,0,0,0,0,0,0,0,0,0},
{0,3,2,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
    };
    const std::string files[tilesCount] = {
      "assets/tiles/sand.png",
      "assets/tiles/water.png",
      "assets/tiles/grass.png",
      "assets/tiles/rock.png"
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

class SpriteRenderSystem : public RenderSystem {
    public:
        SpriteRenderSystem() {}

        ~SpriteRenderSystem() {}

        void run(SDL_Renderer* renderer) override {
          auto cameraTransform = scene->player->getComponent<TransformComponent>();
          // auto cameraZoom = scene->mainCamera->getComponent<CameraComponent>().zoom;
          const int cx = cameraTransform.posX;
          const int cy = cameraTransform.posY;

          const auto view = scene->r.view<TransformComponent, SpriteComponent>();
          for (const entt::entity e : view) {
            const auto pos = view.get<TransformComponent>(e);
            const auto sprite = view.get<SpriteComponent>(e);
            const int dstTileSize = sprite.size;

            SDL_Rect src = { sprite.x, sprite.y, sprite.size, sprite.size };
            SDL_Rect dst = { pos.posX - cx, pos.posY - cy, dstTileSize, dstTileSize };


            SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

            // SDL_RenderFillRect(renderer, &dst);
            SDL_RenderCopy(renderer, sprite.texture, &src, &dst);                        
          }
        }
};