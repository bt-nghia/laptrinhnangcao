#pragma once
#include <string>
#include "ECS.h"
#include "TransformComponent.h"
#include "SDL.h"
#include "SpriteComponent.h"
#include "../Game.h"

class TileComponent : public Component {
public:
    TransformComponent *transform;
    SpriteComponent *sprite;
    char* path;
    SDL_Rect tileRect;
    int tileID;
    TileComponent() = default;

    TileComponent(int id) {
        tileID = id;
    }

    TileComponent(int x, int y, int w, int h, int id) {
        tileRect.x = x;
        tileRect.y = y;
        tileRect.w = w;
        tileRect.h = h;
        tileID = id;
        
        switch (id) {
            case 1:
                path = const_cast<char*>("gameimg/tiles/wall/wall_1.png");
                break;
            case 2:
                path = const_cast<char*>("gameimg/tiles/wall/wall_2.png");
                break;
            case 3:
                path = const_cast<char*>("gameimg/tiles/wall/wall_3.png");
                break;
            case 4:
                path = const_cast<char*>("gameimg/tiles/wall/door_anim_opening_f0.png");
                break;
            case 5:
                path = const_cast<char*>("gameimg/props_itens/chest_closed_anim_f0.png");
                break;
            case 6:
                path = const_cast<char*>("gameimg/props_itens/key_silver.png");
                break;
            case 10:// monster
                path = const_cast<char*>("gameimg/enemies/flyingcreature/fly_anim_spritesheet.png");
                break;
            default:
                break;
        }
    }

    void init() override {
        entity->addComponent<TransformComponent>((float)tileRect.x, (float)tileRect.y, tileRect.w, tileRect.h, 1);
        transform = &entity->getComponent<TransformComponent>();
        entity->addComponent<SpriteComponent>(path);
        sprite = &entity->getComponent<SpriteComponent>();
        Game::tilecomponents.push_back(this);
    }
};