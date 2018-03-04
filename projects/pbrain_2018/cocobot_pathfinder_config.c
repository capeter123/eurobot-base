#include "cocobot_pathfinder_config.h"
#include "cocobot.h"


const cocobot_pathfinder_table_init_s initTable [] = 
{
    //Walls
    {0, 0, TABLE_LENGTH_GRID, ROBOT_HALF_WIDTH_GRID, FORBIDDEN, RECTANGLE, 0},
    {0, TABLE_WIDTH_GRID - ROBOT_HALF_WIDTH_GRID, TABLE_LENGTH_GRID, ROBOT_HALF_WIDTH_GRID, FORBIDDEN, RECTANGLE, 0},
    {0, 0, ROBOT_HALF_WIDTH_GRID, TABLE_WIDTH_GRID, FORBIDDEN, RECTANGLE, 0},
    {TABLE_LENGTH_GRID - ROBOT_HALF_WIDTH_GRID, 0, ROBOT_HALF_WIDTH_GRID, TABLE_WIDTH_GRID, FORBIDDEN, RECTANGLE, 0},

    //Epuration station
    {17, TABLE_WIDTH_GRID - 5 - ROBOT_HALF_WIDTH_GRID, 26, 5 + ROBOT_HALF_WIDTH_GRID, FORBIDDEN, RECTANGLE, 0},
    {17 - ROBOT_HALF_WIDTH_GRID, TABLE_WIDTH_GRID - 5, ROBOT_HALF_WIDTH_GRID, 5, FORBIDDEN, RECTANGLE, 0},
    {17, TABLE_WIDTH_GRID - 5, ROBOT_HALF_WIDTH_GRID, 5, FORBIDDEN, CIRCLE, 0},
    {43, TABLE_WIDTH_GRID - 5, ROBOT_HALF_WIDTH_GRID, 5, FORBIDDEN, RECTANGLE, 0},
    {43, TABLE_WIDTH_GRID - 5, ROBOT_HALF_WIDTH_GRID, 0, FORBIDDEN, CIRCLE, 0},

    //Distributors
    {0, 16, 2 + ROBOT_HALF_WIDTH_GRID, 2, FORBIDDEN, RECTANGLE, 0},
    {0, 16 - ROBOT_HALF_WIDTH_GRID, 2, ROBOT_HALF_WIDTH_GRID, FORBIDDEN, RECTANGLE, 0},
    {0, 16 + 2, 2, ROBOT_HALF_WIDTH_GRID, FORBIDDEN, RECTANGLE, 0},
    {0 + 1, 16 + 1, ROBOT_HALF_WIDTH_GRID, 2, FORBIDDEN, CIRCLE, 0},

    {TABLE_LENGTH_GRID - 2 - ROBOT_HALF_WIDTH_GRID, 16, 2 + ROBOT_HALF_WIDTH_GRID, 2, FORBIDDEN, RECTANGLE, 0},
    {TABLE_LENGTH_GRID - 2, 16 - ROBOT_HALF_WIDTH_GRID, 2, ROBOT_HALF_WIDTH_GRID, FORBIDDEN, RECTANGLE, 0},
    {TABLE_LENGTH_GRID - 2, 16 + 2, 2, ROBOT_HALF_WIDTH_GRID, FORBIDDEN, RECTANGLE, 0},
    {TABLE_LENGTH_GRID - 1, 16 + 1, ROBOT_HALF_WIDTH_GRID, 2, FORBIDDEN, CIRCLE, 0},

    {11, TABLE_WIDTH_GRID - 2 - ROBOT_HALF_WIDTH_GRID, 2, 2 + ROBOT_HALF_WIDTH_GRID, FORBIDDEN, RECTANGLE, 0},
    {11 - ROBOT_HALF_WIDTH_GRID, TABLE_WIDTH_GRID - 2, ROBOT_HALF_WIDTH_GRID, 2, FORBIDDEN, RECTANGLE, 0},
    {11 + 2, TABLE_WIDTH_GRID - 2, ROBOT_HALF_WIDTH_GRID, 2, FORBIDDEN, RECTANGLE, 0},
    {11 + 1, TABLE_WIDTH_GRID - 1, ROBOT_HALF_WIDTH_GRID, 0, FORBIDDEN, CIRCLE, 0},

    {47, TABLE_WIDTH_GRID - 2 - ROBOT_HALF_WIDTH_GRID, 2, 2 + ROBOT_HALF_WIDTH_GRID, FORBIDDEN, RECTANGLE, 0},
    {47 - ROBOT_HALF_WIDTH_GRID, TABLE_WIDTH_GRID - 2, ROBOT_HALF_WIDTH_GRID, 2, FORBIDDEN, RECTANGLE, 0},
    {47 + 2, TABLE_WIDTH_GRID - 2, ROBOT_HALF_WIDTH_GRID, 2, FORBIDDEN, RECTANGLE, 0},
    {47 + 1, TABLE_WIDTH_GRID - 1, ROBOT_HALF_WIDTH_GRID, 0, FORBIDDEN, CIRCLE, 0},
    
    //Cubes
    #warning TODO : Need to pass to the right mask
    //Cube 0
    {17, 11, 2 + ROBOT_HALF_WIDTH_GRID, 4, GAME_ELEMENT, CIRCLE, 1},
    //{15, 9, 4, 4, OBSTACLE, RECTANGLE},
    //Cube 1
    {43, 11, 2 + ROBOT_HALF_WIDTH_GRID, 4, GAME_ELEMENT, CIRCLE, 1},
    //{41, 9, 4, 4, OBSTACLE, RECTANGLE},
    //Cube 2
    {6, 24, 2 + ROBOT_HALF_WIDTH_GRID, 4, GAME_ELEMENT, CIRCLE, 1},
    //{4, 22, 4, 4, OBSTACLE, RECTANGLE},
    //Cube 3
    {54, 24, 2 + ROBOT_HALF_WIDTH_GRID, 4, GAME_ELEMENT, CIRCLE, 1},
    //{52, 22, 4, 4, OBSTACLE, RECTANGLE},
    //Cube 4
    {22, 30, 2 + ROBOT_HALF_WIDTH_GRID, 4, GAME_ELEMENT, CIRCLE, 1},
    //{20, 28, 4, 4, OBSTACLE, RECTANGLE},
    //Cube 5
    {38, 30, 2 + ROBOT_HALF_WIDTH_GRID, 4, GAME_ELEMENT, CIRCLE, 1},
    //{36, 28, 4, 4, OBSTACLE, RECTANGLE},
    


    //{30, 20, 5, 0, FORBIDDEN, CIRCLE},
    {0, 0, 0, 0, 0, 0}//Last line
};


void cocobot_pathfinder_conf_remove_game_element(gameElement_e element)
{
    switch (element)
    {
        case CUBE_CROSS_0:
            cocobot_pathfinder_remove_game_element(17, 11, 2); 
            break;
        case CUBE_CROSS_1:
            cocobot_pathfinder_remove_game_element(43, 11, 2); 
            break;
        case CUBE_CROSS_2:
            cocobot_pathfinder_remove_game_element(6, 24, 2); 
            break;
        case CUBE_CROSS_3:
            cocobot_pathfinder_remove_game_element(54, 24, 2); 
            break;
        case CUBE_CROSS_4:
            cocobot_pathfinder_remove_game_element(22, 30, 2); 
            break;
        case CUBE_CROSS_5:
            cocobot_pathfinder_remove_game_element(38, 30, 2); 
            break;
    }
}

