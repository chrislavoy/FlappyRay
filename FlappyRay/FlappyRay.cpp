// FlappyRay.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <raylib.h>

#include "pipe.h"
#include "player.h"

int main()
{
    constexpr int screen_width = 450;
    constexpr int screen_height = 800;
    player player{};
    pipe pipe{};
    int score{0};
    bool game_over{ false };
    float game_over_countdown{ 2.0f };
    bool game_over_countdown_active{ false };
    float countdown{ 3.0f };
    bool countdown_active{ true };

    InitWindow(screen_width, screen_height, "FlappyRay");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        player.update(game_over, countdown_active);

        if (!game_over)
        {
            if (countdown_active)
            {
                countdown -= 1 * GetFrameTime();

                if (countdown <= 0)
                {
                    countdown_active = false;
                }
            }
            else
            {
                pipe.update();

                if (player.get_position().x - pipe.get_position().x > 0 && !pipe.get_is_past_player())
                {
                    score++;
                    pipe.set_is_past_player(true);
                }

                if (pipe.is_off_screen())
                {
                    pipe.reset_pipe(500, static_cast<float>(GetRandomValue(150, 700)));
                }

                if (player.is_off_screen() || pipe.is_player_colliding(player.get_position()))
                {
                    game_over = true;
                    game_over_countdown_active = true;
                    player.set_velocity(Vector2{ 0, -30 });
                }
            }
        }
        else
        {
            if (!game_over_countdown_active)
            {
                if (IsKeyPressed(KEY_SPACE))
                {
                    player.reset();
                    pipe.reset_pipe(500, 400);
                    pipe.update();
                    score = 0;
                    game_over = false;
                    countdown = 3.0f;
                    countdown_active = true;
                    game_over_countdown = 2.0f;
                }
            }

            game_over_countdown -= 1 * GetFrameTime();

            if (game_over_countdown <= 0)
            {
                game_over_countdown_active = false;

            }
        }

        BeginDrawing();
        ClearBackground(RAYWHITE);
        player.draw();
        pipe.draw();

        if (countdown_active)
        {
            DrawText(TextFormat("%d", static_cast<int>(countdown)), 200, 250, 50, BLACK);
            DrawText("Press <Space> to flap!", 50, 400, 30, BLACK);
        }

        if (game_over)
        {
            DrawText("Game Over!", 90, 300, 50, BLACK);

            if (!game_over_countdown_active)
            {
                DrawText("Press <Space> to try again!", 15, 400, 30, BLACK);
            }
        }

        DrawText(TextFormat("Score: %d", score), 160, 10, 30, BLACK);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
