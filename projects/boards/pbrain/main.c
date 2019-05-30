#include <FreeRTOS.h>
#include <task.h>
#include <platform.h>
#include <cocobot.h>
#include <stdio.h>
#include "meca.h"

extern cocobot_pathfinder_table_init_s initTable [];

void stop(void)
{
    
    cocobot_trajectory_wait();
  cocobot_asserv_set_state(COCOBOT_ASSERV_DISABLE);
  while(1)
  {
      vTaskDelay(100/portTICK_PERIOD_MS);
  }
}

void run_homologation(void * arg)
{
  (void)arg;

  cocobot_game_state_wait_for_configuration();
  
  //set initial position

  switch(cocobot_game_state_get_color())
  {
    case COCOBOT_GAME_STATE_COLOR_NEG:
      cocobot_position_set_x(-1180);
      cocobot_position_set_y(550);
      cocobot_position_set_angle(0);
      break;

    case COCOBOT_GAME_STATE_COLOR_POS:
      cocobot_position_set_x(1180);
      cocobot_position_set_y(550);
      cocobot_position_set_angle(180);
      break;
  }
    
  //pose exp
  cocobot_game_state_add_points_to_score(5);
  cocobot_game_state_wait_for_starter_removed();

  //electron
  cocobot_game_state_add_points_to_score(35);

  if(cocobot_game_state_get_color() == COCOBOT_GAME_STATE_COLOR_NEG)
  {
      cocobot_trajectory_goto_a(10, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  }
  else
  {
      cocobot_trajectory_goto_a(190, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  }
  //saisir truc au sol
  meca_action(0, MECA_TAKE_FLOOR);

  cocobot_trajectory_goto_a(0, COCOBOT_TRAJECTORY_UNLIMITED_TIME);

  
  if(cocobot_game_state_get_color() == COCOBOT_GAME_STATE_COLOR_NEG)
      cocobot_trajectory_goto_xy(-980, 550, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  else
      cocobot_trajectory_goto_xy_backward(1000, 550, COCOBOT_TRAJECTORY_UNLIMITED_TIME);

  cocobot_trajectory_goto_a(0, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
cocobot_trajectory_wait();
meca_action(3, MECA_TAKE_FLOOR);


  if(cocobot_game_state_get_color() == COCOBOT_GAME_STATE_COLOR_NEG)
  {
      cocobot_trajectory_goto_xy(-991, 160, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  cocobot_trajectory_goto_a(90, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  }
  else
  {
      cocobot_trajectory_goto_xy_backward(1000, 160, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
      cocobot_trajectory_goto_a(90, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  }

  cocobot_trajectory_wait();
  meca_action(2, MECA_TAKE_FLOOR);  

  //retour case rouge
  if(cocobot_game_state_get_color() == COCOBOT_GAME_STATE_COLOR_NEG)
      cocobot_trajectory_goto_xy(-1080, 560, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  else
      cocobot_trajectory_goto_xy(1080, 560, COCOBOT_TRAJECTORY_UNLIMITED_TIME);

  int i;
  for(i = 0; i < 4; i += 1)
  {
      cocobot_trajectory_goto_a(-i * 90 + 90, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
      cocobot_trajectory_wait();

      if(cocobot_game_state_get_color() == COCOBOT_GAME_STATE_COLOR_NEG)
      meca_action((i + 1)%4, MECA_DROP_FLOOR);
      else
      meca_action((i + 3)%4, MECA_DROP_FLOOR);

  }
  cocobot_game_state_add_points_to_score(1 + 6 + 6);

    while(1)
        vTaskDelay(100/portTICK_PERIOD_MS);

  cocobot_trajectory_goto_xy_backward(200, 687, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  cocobot_trajectory_goto_a(-90, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  cocobot_trajectory_wait();

  meca_action(2, MECA_TAKE_ACCEL);
  cocobot_trajectory_goto_d(-30, 2000);
  meca_action(2, MECA_TAKE_ACCEL_END);
  //stop();

  cocobot_trajectory_goto_xy_backward(330, 750, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  cocobot_trajectory_wait();
  cocobot_trajectory_goto_xy_backward(713, 740, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  cocobot_trajectory_goto_a(180, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  cocobot_trajectory_wait();
  cocobot_trajectory_goto_xy(-154, -290, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  cocobot_trajectory_wait();



#if 0
  meca_action(1, MECA_TAKE_FLOOR);

  //sort de la zone vers l'experience
  cocobot_trajectory_goto_d(150, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  cocobot_trajectory_wait();

  //tourne face a l'autre equipe
  if(cocobot_game_state_get_color() == COCOBOT_GAME_STATE_COLOR_NEG)
  {
      cocobot_trajectory_goto_a(0, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  }
  else
  {
      cocobot_trajectory_goto_a(180, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  }

  cocobot_trajectory_wait();

  //Avance de 20cm
  cocobot_trajectory_goto_d(300, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  cocobot_trajectory_wait();

  //tourne face à la balance
  if(cocobot_game_state_get_color() == COCOBOT_GAME_STATE_COLOR_NEG)
  {
      cocobot_trajectory_goto_a(-90, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  }
  else
  {
      cocobot_trajectory_goto_a(-90, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  }
  cocobot_trajectory_wait();

  //Avance de 20cm
  cocobot_trajectory_goto_d(200, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  cocobot_trajectory_wait();

  //tourne face à la balance
  if(cocobot_game_state_get_color() == COCOBOT_GAME_STATE_COLOR_NEG)
  {
      cocobot_trajectory_goto_a(180, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  }
  else
  {
      cocobot_trajectory_goto_a(0, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  }
  cocobot_trajectory_wait();

  //Avance de 30cm
  cocobot_trajectory_goto_d(300, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  cocobot_trajectory_wait();
#endif
  

  //cocobot_trajectory_goto_xy(500, 0, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  //cocobot_trajectory_goto_xy(500, 500, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  //cocobot_trajectory_goto_xy(0, 500, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  //cocobot_trajectory_goto_xy(0, 0, COCOBOT_TRAJECTORY_UNLIMITED_TIME);
  //cocobot_trajectory_wait();

  while(1)
  {
    vTaskDelay(100/portTICK_PERIOD_MS);
  }

  while(1)
  {
    //do nothing !
    uprintf("x=%d y=%d a=%d d=%d -- l=%ld r=%ld\r\n", 
            (int)cocobot_position_get_x(),
            (int)cocobot_position_get_y(),
            (int)cocobot_position_get_angle(),
            (int)cocobot_position_get_distance(),
            (int)cocobot_position_get_left_encoder(),
            (int)cocobot_position_get_right_encoder());

    cocobot_com_printf(COM_DEBUG, "x=%d y=%d a=%d d=%d -- l=%ld r=%ld\r\n", 
            (int)cocobot_position_get_x(),
            (int)cocobot_position_get_y(),
            (int)cocobot_position_get_angle(),
            (int)cocobot_position_get_distance(),
            (int)cocobot_position_get_left_encoder(),
            (int)cocobot_position_get_right_encoder());

    vTaskDelay(100/portTICK_PERIOD_MS);
  }

  while(1)
    vTaskDelay(100/portTICK_PERIOD_MS);
}
 
int main(void) 
{
  platform_init();

  cocobot_com_init();
  cocobot_com_run();
  cocobot_position_init(4);
  cocobot_action_scheduler_init();
  cocobot_asserv_init();
  cocobot_trajectory_init(4);
  cocobot_opponent_detection_init(3);
  cocobot_game_state_init(NULL);
  cocobot_pathfinder_init(initTable);
  cocobot_action_scheduler_use_pathfinder(1);
  meca_init();

  cocobot_com_set_mode(UAVCAN_PROTOCOL_NODESTATUS_MODE_OPERATIONAL);

  //set initial position
  cocobot_position_set_x(0);
  cocobot_position_set_y(0);
  cocobot_position_set_angle(0);

  xTaskCreate(run_homologation, "strat", 600, NULL, 2, NULL );

  vTaskStartScheduler();

  return 0;
}
