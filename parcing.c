#include "so_long.h"

void error()
{
        write(1,"error\n",7);
        return(1);
}

int     verify_map_name(char **av,t_data *vars)
{
        int i;

        i = 0;
        while(av[i] != '.')
        i++;
        i++;
        if(av[i] == 'b')
        i++;
        else
        return(1);
        if(av[i] == 'e')
        i++;
        else
        return(1);
        if(av[i] == 'r')
        i++;
        else
        return(1);
        return(0);

}
int create_matrix(char *file, t_data *vars)
{
        int i;
        int fd;
        char *line;

        i = 0;
        vars->game.map = malloc(vars->game.horizontal *sizeof(char *));
        if(!vars->game.map)
                return(1);
        fd = open(file, O_RDONLY);
        line = get_next_line(fd);
        while(line)
        {
                vars->game.map = line;
                i++;
                line = get_next_line(fd);
        }
        close(fd);
        check_walls(vars);
        check_map(vars);
        check_letters(vars);
        vars->game.map_wid = vars->game.vertical * 32;
        vars->game.map_hight = vars->game.horizontal * 32;
}
int read_map(char *file, t_data *vars)
{
        int fd;
        char *line;

        fd = open(file, O_RDONLY);
        line = get_next_line(fd);
        if(!line)
        {
                free(line);
                return(1);
        }
        vars->game.vertical = 0;
        while(line[vars->game.vertical] != '\n' || file[vars->game.vertical] != '\0')
        vars->game.vertical++;
        while(line)
        {
                vars->game.horizontal++;
                free(line);
                line = get_next_line(fd);
        }
        close(fd);
        create_matrix(file, vars);
        return(0);
}