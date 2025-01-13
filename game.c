#include "so_long.h"
void key_hooks(t_data *vars)
{
        

}

void close_window(t_data *vars)
{

}

void game_hook(t_data *vars)
{
        mlx_hook(vars->mlx_window,17, 0,close_window, vars);
        mlx_key_hook(vars->mlx_window, key_hooks, vars)
}