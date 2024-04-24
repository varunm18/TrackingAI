#include "Main.h"

int HEIGHT = 675;
int WIDTH = 1200;
int NUM_DOTS = 40;
int DEADZONE = 2;

Item list[sizeof(NUM_DOTS)/sizeof(int)];

int main(void)
{
    InitWindow(WIDTH, HEIGHT, "raylib [core] example - basic window");
    SetTargetFPS(60);

    int count = 0;

    randomizeDots();

    string path = "examples/resources/shipTransparent.png";
    Player player = Player(WIDTH/2, HEIGHT/2, path);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(WHITE);

//        if(count%200==0){
//            randomizeDots();
//        }
        for(int i=0; i<NUM_DOTS; i++) {
            DrawCircle(list[i].x, list[i].y, 5.0f, list[i].color);
        }

        Vector2 target = (Vector2){list[NUM_DOTS-1].x, list[NUM_DOTS-1].y};
//        Vector2 target = GetMousePosition();
        player.seek(target);
        player.update();
        player.draw();

        if(player.location.x < list[NUM_DOTS-1].x+DEADZONE && player.location.x > list[NUM_DOTS-1].x-DEADZONE)
        {
            if(player.location.y < list[NUM_DOTS-1].y+DEADZONE && player.location.y > list[NUM_DOTS-1].y-DEADZONE)
            {
                randomizeDots();
            }
        }

        count++;

        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void randomizeDots(){
    Item point;
    for(int i=0; i<NUM_DOTS; i++){
        point.x = rand()%WIDTH;
        point.y = rand()%HEIGHT;
        point.color = BLACK;
        if(i==NUM_DOTS-1) {
            point.color = RED;
        }
        list[i] = point;
    }
}
