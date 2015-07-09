#include <string.h>
#include <stdio.h>
#include <cocobot.h>
#include <FreeRTOS.h>
#include <task.h>

#define COCOBOT_CONSOLE_ASYNCHRONOUS_START  "#"
#define COCOBOT_CONSOLE_SYNCHRONOUS_START   "< "
#define COCOBOT_CONSOLE_COMMAND_SEPARATOR   "="
#define COCOBOT_CONSOLE_END_LINE            "\r\n"
#define COCOBOT_CONSOLE_USER_INPUT_START    "> "
#define COCOBOT_CONSOLE_BUFFER_LENGTH       255

static mcual_usart_id_t usart;
static char buffer[COCOBOT_CONSOLE_BUFFER_LENGTH];
static unsigned int buffer_position;

static void cocobot_console_send_string(char * str)
{
  while(*str != 0)
  {
    mcual_usart_send(usart, *str);

    str += 1;
  }
}

void cocobot_console_send_asynchronous(char * title, char * data)
{
  cocobot_console_send_string(COCOBOT_CONSOLE_ASYNCHRONOUS_START);
  cocobot_console_send_string(title);
  cocobot_console_send_string(COCOBOT_CONSOLE_COMMAND_SEPARATOR);
  cocobot_console_send_string(data);
  cocobot_console_send_string(COCOBOT_CONSOLE_END_LINE);
}

int cocobot_console_handle_freertos(char * command, char * arguments)
{
  (void)arguments;
  if(strcmp(command,"freertos") == 0)
  {
    xTaskStatusType tasks[10];
    int tasks_num = 0; //uxTaskGetSystemState(tasks, 10, NULL);
    for(int i = 0; i < tasks_num; i += 1)
    {
      snprintf(buffer, sizeof(buffer), "%s,%lu,%lu,%lu,%d", 
               tasks[i].pcTaskName,
               tasks[i].uxCurrentPriority,
               tasks[i].uxBasePriority,
               tasks[i].ulRunTimeCounter,
               tasks[i].usStackHighWaterMark
               );
      cocobot_console_send_string(buffer);
      cocobot_console_send_string(COCOBOT_CONSOLE_END_LINE);
    }
    return 1;
  }

  return 0;
}

void cocobot_console_thread(void *arg)
{
  (void)arg;
  
  cocobot_console_send_string(COCOBOT_CONSOLE_END_LINE);
  cocobot_console_send_asynchronous("console", "system started");
    cocobot_console_send_string(COCOBOT_CONSOLE_USER_INPUT_START);
  while(pdTRUE)
  {
    uint8_t recv = mcual_usart_recv(usart);
    if(recv != '\n')
    {      

      if(recv == '\r')
      {
        buffer[buffer_position] = 0;

        char * cmd = buffer;
        char * args = buffer;
        while(*args)
        {
          if(*args == ' ')
          {
            *args = 0;
            args += 1;
            break;
          }
          args += 1;
        }

        cocobot_console_send_string(COCOBOT_CONSOLE_END_LINE);

        int handled = 0;
        handled = cocobot_console_handle_freertos(cmd, args);

        if(!handled)
        {
          cocobot_console_send_string("invalid command: ");
          cocobot_console_send_string("invalid command: '");
          cocobot_console_send_string(cmd);
          cocobot_console_send_string("'" COCOBOT_CONSOLE_END_LINE);
        }
        buffer_position = 0;

        cocobot_console_send_string(COCOBOT_CONSOLE_USER_INPUT_START);
      }
      else
      {
        if(buffer_position < COCOBOT_CONSOLE_BUFFER_LENGTH - 1)
        {
          buffer[buffer_position] = recv;
          buffer_position += 1;
        }
        mcual_usart_send(usart, recv);
      }
    }
  }
}

void cocobot_console_init(mcual_usart_id_t usart_id, unsigned int priority)
{
  usart = usart_id;
  buffer_position = 0;

  mcual_usart_init(usart, 115200);

  xTaskCreate(cocobot_console_thread, (const signed char *)"console", 512, NULL, priority, NULL );
}
