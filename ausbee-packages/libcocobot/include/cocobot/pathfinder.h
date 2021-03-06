#ifndef COCOBOT_PATHFINDER_H
#define COCOBOT_PATHFINDER_H

#include <include/generated/autoconf.h>
#ifdef CONFIG_LIBCOCOBOT_PATHFINDER

#include "cocobot/pathfinder_table_utils.h"

#define TRAJECTORY_NBR_POINTS_MAX   160

#define DESTINATION_NOT_AVAILABLE   0xfffe
#define NO_ROUTE_TO_TARGET          0xffff
#define TRAJECTORY_READY            2


typedef enum
{
    COCOBOT_PATHFINDER_MODE_GET_DURATION,
    COCOBOT_PATHFINDER_MODE_EXECUTE_TRAJ_FORWARD,
    COCOBOT_PATHFINDER_MODE_EXECUTE_TRAJ_BACKWARD,
}cocobot_pathfinder_mode_e;

/**
 * Execute trajectory from starting point to target point
 * Arguments:
 *  - starting_point_x: trajectory starting point x
 *  - starting_point_y: trajectory starting point y
 *  - target_point_x: trajectory target point x
 *  - target_point_y: trajectory target point y
 *  - mode: mode to be used for this execution
 *  
 * Return Value: NO_TRAJECTORY_AVAILABLE if the target_point is not reachable 0 eitherway 
 */
uint16_t cocobot_pathfinder_execute(int16_t starting_point_x, int16_t starting_point_y, int16_t target_point_x, int16_t target_point_y, cocobot_pathfinder_mode_e mode);

/**
 * Allow the entire start zone for pathfinder
 */
void cocobot_pathfinder_allow_start_zone();

/**
 * Set a position for opponent robot
 * Arguments:
 *  - adv_x: x position of the opponent (considered as the x center)
 *  - adv_y: y position of the opponent (considered as the y center)
 */
void cocobot_pathfinder_set_robot(int adv_x, int adv_y);

/**
 * Remove a game element from the pathfinder table
 * When it is removed, it not considered as an obstacle by the pathfinder.
 * WARNING : Units used here are grid units
 * This function cannot be internal, because it is called by pathfinder conf. Nevertheless it's easier to use grid coordinates.
 * Not to be called directly, only by conf
 * Arguments:
 *  - x : xposition of the game element to remove.
 *  - y : yposition of the game element to remove.
 *  - radius: Size of the game element to remove (it is considered as a circle)
 */
void cocobot_pathfinder_remove_game_element(uint8_t x, uint8_t y, uint8_t radius);

/**
 * Initialize the pathFinder
 * Arguments : 
 *  - initTable : Table containing all the elements to be used for initialisation
 */
void cocobot_pathfinder_init(cocobot_pathfinder_table_init_s * initTable);

void cocobot_pathfinder_handle_async_com(void);

#endif

#endif //COCOBOT_PATHFINDER_H
