
#include "Common_Func.h"

BaseObject g_background;

bool InitData()
{
    bool success = true;
    int ret = SDL_Init(SDL_INIT_VIDEO);
    if (ret < 0) return false;
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    g_window = SDL_CreateWindow("Jumping Cat",
                                SDL_WINDOWPOS_CENTERED,
                                SDL_WINDOWPOS_CENTERED,
                                SCREEN_WIDTH, SCREEN_HEIGHT,
                                SDL_WINDOW_SHOWN);
    if (g_window == NULL)
    {
        success = false;
    }
    else
    {
        g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
        if (g_screen == NULL)
        {
            success = false;
        }
        else
        {
            SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);
            int imgFlags = IMG_INIT_PNG;
            if (!(IMG_Init(imgFlags) && imgFlags)) success = false;

        }
    }
    return success;
}

bool LoadBackground()
{
    bool ret = g_background.LoadImg("bg01.png", g_screen);
    if (ret == false) return false;
    return true;
}

void close()
{
    g_background.Free();
    SDL_DestroyRenderer(g_screen);
    g_screen = NULL;
    SDL_DestroyWindow(g_window);
    g_window = NULL;
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[])
{

    ImpTimer fps_timer;

    if (InitData() == false) return -1;
    if (LoadBackground() == false) return -1;

    ThreatsObject p_threat1;
    p_threat1.LoadImg("CatPNG//ball.png", g_screen);
    p_threat1.set_clips();
    p_threat1.set_x_pos(rand() % (SCREEN_WIDTH + 1500));

    ThreatsObject p_threat2;
    p_threat2.LoadImg("CatPNG//ball.png", g_screen);
    p_threat2.set_clips();
    p_threat2.set_x_pos(rand() % (SCREEN_WIDTH +500));

    ThreatsObject p_threat3;
    p_threat3.LoadImg("CatPNG//ball.png", g_screen);
    p_threat3.set_clips();
    p_threat3.set_x_pos(rand() % (SCREEN_WIDTH + 1000));

    ThreatsObject p_threat4;
    p_threat4.LoadImg("CatPNG//ball.png", g_screen);
    p_threat4.set_clips();
    p_threat4.set_x_pos(rand() % (SCREEN_WIDTH + 500));

    ThreatsObject p_threat5;
    p_threat5.LoadImg("CatPNG//ball.png", g_screen);
    p_threat5.set_clips();
    p_threat5.set_x_pos(rand() % (SCREEN_WIDTH + 500));

    ThreatsObject p_threat6;
    p_threat6.LoadImg("CatPNG//ball.png", g_screen);
    p_threat6.set_clips();
    p_threat6.set_x_pos(rand() % (SCREEN_WIDTH + 500));

    MainObject p_player;
    p_player.LoadImg("CatPNG//walk_trc.png", g_screen);
    p_player.set_clips();

    PlayerPower player_power;
    player_power.Init(g_screen);
    int num_die = 0;

    bool is_quit = false;
    while (!is_quit)
    {
        fps_timer.start();

        while (SDL_PollEvent(&g_event) != 0)
        {
            if (g_event.type == SDL_QUIT)
            {
                is_quit = true;
            }
            p_player.HandleInputAction(g_event, g_screen);

        }
        SDL_SetRenderDrawColor(g_screen, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR, RENDER_DRAW_COLOR);

        SDL_RenderClear(g_screen);

        g_background.Render(g_screen, NULL);

        player_power.Show(g_screen);

        p_player.Show(g_screen);

        p_threat1.Show(g_screen);
        p_threat2.Show(g_screen);
        p_threat3.Show(g_screen);
        p_threat4.Show(g_screen);
        p_threat5.Show(g_screen);
        p_threat6.Show(g_screen);

        SDL_Rect tRect1;
        tRect1.x = p_threat1.get_x_pos();
        tRect1.y = p_threat1.get_y_pos();
        tRect1.w = p_threat1.get_width_frame();
        tRect1.h = p_threat1.get_height_frame();

        SDL_Rect tRect2;
        tRect2.x = p_threat2.get_x_pos();
        tRect2.y = p_threat2.get_y_pos();
        tRect2.w = p_threat2.get_width_frame();
        tRect2.h = p_threat2.get_height_frame();

        SDL_Rect tRect3;
        tRect3.x = p_threat3.get_x_pos();
        tRect3.y = p_threat3.get_y_pos();
        tRect3.w = p_threat3.get_width_frame();
        tRect3.h = p_threat3.get_height_frame();

        SDL_Rect tRect4;
        tRect4.x = p_threat4.get_x_pos();
        tRect4.y = p_threat4.get_y_pos();
        tRect4.w = p_threat4.get_width_frame();
        tRect4.h = p_threat4.get_height_frame();

        SDL_Rect tRect5;
        tRect5.x = p_threat5.get_x_pos();
        tRect5.y = p_threat5.get_y_pos();
        tRect5.w = p_threat5.get_width_frame();
        tRect5.h = p_threat5.get_height_frame();

        SDL_Rect tRect6;
        tRect6.x = p_threat6.get_x_pos();
        tRect6.y = p_threat6.get_y_pos();
        tRect6.w = p_threat6.get_width_frame();
        tRect6.h = p_threat6.get_height_frame();

        SDL_Rect pRect;
        pRect.x = p_player.get_x_pos();
        pRect.y = p_player.get_y_pos();
        pRect.w = p_player.get_width_frame();
        pRect.h = p_player.get_height_frame();

        bool check1 = SDLCommonFunc::CheckCollision(pRect, tRect1);
        bool check2 = SDLCommonFunc::CheckCollision(pRect, tRect2);
        bool check3 = SDLCommonFunc::CheckCollision(pRect, tRect3);
        bool check4 = SDLCommonFunc::CheckCollision(pRect, tRect4);
        bool check5 = SDLCommonFunc::CheckCollision(pRect, tRect5);
        bool check6 = SDLCommonFunc::CheckCollision(pRect, tRect6);
        if (check1 == true || check2 == true || check3 == true || check4 == true || check5 == true || check6 == true)
        {
            if (num_die < 4) {
                num_die++;
                if (check1 == true)  p_threat1.set_y_pos(-10);
                if (check2 == true)  p_threat1.set_y_pos(-10);
                if (check3 == true)  p_threat1.set_y_pos(-10);
                if (check4 == true)  p_threat1.set_y_pos(-10);
                if (check5 == true)  p_threat1.set_y_pos(-10);
                if (check6 == true)  p_threat1.set_y_pos(-10);
                player_power.Decrease();
                player_power.Render(g_screen);
                continue;
            }
            SDL_Delay(300);
            if (num_die >= 4)

            {
                g_background.LoadImg("youlose.png", g_screen);

                p_threat1.set_drop_speed(0);
                p_threat2.set_drop_speed(0);
                p_threat3.set_drop_speed(0);
                p_threat4.set_drop_speed(0);
                p_threat5.set_drop_speed(0);
                p_threat6.set_drop_speed(0);

                p_player.set_y_pos(1000);
                p_threat1.set_x_pos(-500);
                p_threat2.set_x_pos(-500);
                p_threat3.set_x_pos(-500);
                p_threat4.set_x_pos(-500);
                p_threat5.set_x_pos(-500);
                p_threat6.set_x_pos(-500);
            }

        }

        SDL_RenderPresent(g_screen);
        int fps_act;
        if (p_player.check_act() == true)
        {
            fps_act= FRAME_PER_SECOND;
        }
        else
        {
            fps_act = wait_FRAME_PER_SECOND;
            
        }
        int real_imp_time = fps_timer.get_ticks();
        int time_one_frame = 1000 / fps_act;

        if (real_imp_time < time_one_frame)
        {
            int delay_time = time_one_frame - real_imp_time;
            if (delay_time >= 0)
                SDL_Delay(delay_time);
        }

    }
    close();
    return 0;
}