//
// Created by Varun Mannam on 10/3/23.
//

#include "Player.h"

Player::Player(float x, float y, string& filePath)
{
    texture = LoadTextureFromImage(LoadImage(filePath.c_str()));
    acceleration = (Vector2){0, 0};
    velocity = (Vector2){0, 0};
    location = (Vector2){x, y};
    heading = 0.0;
    r = 3.0;
    maxspeed = 4;
    maxforce = 0.1;
}

void Player::update() {
    velocity = Vector2Add(velocity, acceleration);
    velocity = Vector2ClampValue(velocity, -maxspeed, maxspeed);
    location = Vector2Add(location, velocity);
    acceleration = Vector2Scale(acceleration, 0);
    heading = Vector2Angle(velocity, (Vector2){1, 0}) * (180/PI);
}

void Player::applyForce(Vector2 force) {
    acceleration = Vector2Add(acceleration, force);
}

void Player::seek(Vector2 target) {
    Vector2 desired = Vector2Subtract(target, location);
    desired = Vector2Normalize(desired);
    desired = Vector2Scale(desired, maxspeed);
    Vector2 steer = Vector2Subtract(desired, velocity);
    steer = Vector2ClampValue(steer, -maxforce, maxforce);
    applyForce(steer);
}

void Player::arrive(Vector2 target) {
    Vector2 desired = Vector2Subtract(target, location);
    float d = Vector2Length(desired);
    desired = Vector2Normalize(desired);
    if(d<100){
        float val = d/100.0;
        float m = val*maxspeed;
        desired = Vector2Scale(desired, m);
    }
    else{
        desired = Vector2Scale(desired, maxspeed);
    }
    Vector2 steer = Vector2Subtract(desired, velocity);
    steer = Vector2ClampValue(steer, -maxforce, maxforce);
    applyForce(steer);
}

void Player::draw() {
    DrawTexturePro(texture,
               (Rectangle){0, 0, texture.width, texture.height},
               (Rectangle){location.x, location.y, texture.width, texture.height},
               (Vector2){texture.width/2, texture.height/2},
               heading-90.0,
               WHITE);
}

