//
// Created by Varun Mannam on 10/3/23.
//

#ifndef EXAMPLE_PLAYER_H
#define EXAMPLE_PLAYER_H

#include "raylib.h"
#include "raymath.h"

#include <iostream>

using namespace std;

class Player {       // The class
public:             // Access specifier
    Texture texture;
    Vector2 acceleration;
    Vector2 velocity;
    Vector2 location;
    float heading;
    float r;
    float maxspeed;
    float maxforce;
    Player(float x, float y, string& filePath);
    void update();
    void applyForce(Vector2 force);
    void seek(Vector2 target);
    void arrive(Vector2 target);
    void draw();
};

#endif //EXAMPLE_PLAYER_H
