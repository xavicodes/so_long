#ifndef SO_LONG

#define SO_LONG

#include <unistd.h>
#include <fcntl.h>
#include "minilibx/mlx_new_window.h"
#include "minilibx/mlx_int.h"
#include "minilibx/mlx.h"
#include "libft/libft.h"

#define FLOOR  '0'
#define WALL  '1'
#define COLECTABLE 'C'
#define EXIT    'E'
#define PLAYER  'P'
typedef struct s_flood
{
        char **map_copy;
        int vertical;
        int horizontal;
        int colectables;
        int exit;
}       t_flood;

typedef struct s_map
{
        int horizontal;
        int vertical;
        char **map;
        int map_wid;
        int map_hight

}       t_map;
typedef struct s_img
{
        void *walls;
        void *floor;
        void *collectable;
        void *player;
        void *exit;
        int     img_width;
        int     img_height;
}       t_img;

typedef struct s_player
{
        int x;
        int y;
        int moves;
        int m_colectables;
}       t_player;


typedef struct s_data
{
        void            *mlx;
        void            *mlx_window;
        void            *mlx_img;
        char            *mlx_adress;

        int             bits_per_pixel;
        int             size_line;
        int             endian;
        int             window_width;
        int             window_height;
        t_player player;
        t_map game;
        t_img sprites;
        
} t_data;

//parsing--------------
int     verify_map_name(char **av,t_data *vars);
int read_map(char *file,t_data *vars);
//error----------
void error();
void free_map(char **map, t_data *vars);
//map_utils---------
int strlen_no_n(char *map);
void check_map(t_data *vars);
void check_walls(t_data *vars);
void check_letters(t_data *vars);
void floodfill(t_flood *flood,int x, int y);
void check_if_map_is_playable(t_data *vars);
void check_conditions(t_data *vars);
void check_player_position(t_data *vars);

#endif