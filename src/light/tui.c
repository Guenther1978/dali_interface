#include <stdio.h>
#include <stdint.h>

#include "tui.h"
#include "../mcc_generated_files/uart/uart1.h"
#include "../mcc_generated_files/uart/uart2.h"


void InitTuiFsm(TuiFsm* tui_fsm) {
    // Draw Rectangle
  ClearScreen(tui_fsm);
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
  
  MoveCursorHome(tui_fsm);   
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
  
  UART1_Write('+');
  for(uint8_t i = kColumnRight - 2; i > 0; i--)
    {
        UART1_Write('-');
    }
  UART1_Write('+');
  UART1_Write('\r');
  UART1_Write('\n');

  for (uint8_t j = kLineBottom - 2; j > 0; j--)
  {
    UART1_Write('|');
    for(uint8_t i = kColumnRight - 2; i > 0; i++)
      {
          UART1_Write(' ');
      }
    UART1_Write('|');
    UART1_Write('\r');
    UART1_Write('\n');
  }

   UART1_Write('+');
  for(uint8_t i = kColumnRight - 2; i > 0; i--)
    {
        UART1_Write('-');
    }
   
  MoveCursorToPosition(kLineCaption, kColumnValue, tui_fsm);
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }

  for(uint8_t i = 0; i < strlen(kCaption); i++)
    {
        UART1_Write(kCaption[i]);
    }

  MoveCursorToPosition(kLineCaption + 1, kColumnValue - 1, tui_fsm);
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
  
  for (uint8_t i = kColumnValue - 1; i < 35  ; i++) {
      UART1_Write('-');
  }
  
  
  // Add Labels
  MoveCursorToPosition(kLineNumber, kColumnLabel, tui_fsm);
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
  for(uint8_t i = 0; i < strlen(kNumber); i++)
    {
        UART1_Write(kNumber[i]);
    }
  
  MoveCursorToPosition(kLineValue, kColumnLabel, tui_fsm);
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
  for(uint8_t i = 0; i < strlen(kValue); i++)
    {
        UART1_Write(kValue[i]);
    }
  
  MoveCursorToPosition(kLineReception, kColumnLabel, tui_fsm);
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
  for(uint8_t i = 0; i < strlen(kReception); i++)
    {
        UART1_Write(kReception[i]);
    }
  
  MoveCursorToPosition(kLineMessage, kColumnLabel, tui_fsm);
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
  for(uint8_t i = 0; i < strlen(kMessage); i++)
    {
        UART1_Write(kMessage[i]);
    }
  
  InitMessage(tui_fsm);
}

void ShowDaliAnswer(TuiFsm* tui_fsm, uint8_t answer) {
  MoveCursorToPosition(kLineReception, kColumnValue, tui_fsm);
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
  UART1_Write(answer);
  tui_fsm->state = CHOOSE_ACTION;
}

void InitMessage(TuiFsm* tui_fsm) {
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
  for(uint8_t i = 0; i < strlen(kChoose); i++)
    {
        UART1_Write(kChoose[i]);
    }
  tui_fsm->state = CHOOSE_ACTION;
}

void InitReadNumber(TuiFsm* tui_fsm) {
  tui_fsm->state = READ_NUMBER;
  tui_fsm->number = 0;
  for (uint8_t i = 0; i < 3; i++) {
    tui_fsm->buffer_number[i] = '0';
  }
  tui_fsm->buffer_number[2] = 0;
  MoveCursorToPosition(kLineMessage, kColumnValue, tui_fsm);
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
  for(uint8_t i = 0; i < strlen(kInputNumber); i++)
    {
        UART1_Write(kInputNumber[i]);
    }
  MoveCursorToPosition(kLineNumber, kColumnValue, tui_fsm);
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
}

void InitReadValue(TuiFsm* tui_fsm) {
  tui_fsm->state = READ_VALUE;
  tui_fsm->value = 0;
  for (uint8_t i = 0; i < 3; i++) {
    tui_fsm->buffer_value[i] = '0';
  }
  tui_fsm->buffer_value[2] = 0;
  MoveCursorToPosition(kLineMessage, kColumnValue, tui_fsm);
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
  for(uint8_t i = 0; i < strlen(kInputValue); i++)
    {
        UART1_Write(kInputValue[i]);
    }
  MoveCursorToPosition(kLineValue, kColumnValue, tui_fsm);
  for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
}

void MoveCursorToPosition(uint8_t line, uint8_t column, TuiFsm* puffer) {
  sprintf(puffer->buffer_command, "%c[%d;%dH", 27, line, column);
}

void ClearScreen(TuiFsm* puffer) {
  sprintf(puffer->buffer_command, "%c[2J", 27);
}

void ClearLine(TuiFsm* puffer) {
  sprintf(puffer->buffer_command, "%c[0K", 27);
}

void MoveCursorHome(TuiFsm* puffer) {
  sprintf(puffer->buffer_command, "%c[H", 27);
}

void ClearBuffer(unsigned char * buffer, unsigned char size_of_buffer) {
  for (int i = 0; i < size_of_buffer; i ++) {
    buffer[i] = '0';
  }
}

void HandleChar(char input, TuiFsm* tui_fsm) {
  if ((input >= '0') && (input <= '9')) {
    switch (tui_fsm->state) {
      case READ_NUMBER:
        tui_fsm->buffer_number[0] = tui_fsm->buffer_number[1];
        tui_fsm->buffer_number[1] = tui_fsm->buffer_number[2];
        tui_fsm->buffer_number[2] = input;
        MoveCursorToPosition(kLineNumber, kColumnValue, tui_fsm);
        for(uint8_t i = 0; i < strlen(tui_fsm->buffer_command); i++)
        {
            UART1_Write(tui_fsm->buffer_command[i]);
        }
        for (uint8_t i = 0; i < 3; i++)
        {
            UART1_Write(tui_fsm->buffer_number[i]);
        }
        tui_fsm->number = atoi(tui_fsm->buffer_number);
        break;
      case READ_VALUE:
        tui_fsm->buffer_value[0] = tui_fsm->buffer_value[1];
        tui_fsm->buffer_value[1] = tui_fsm->buffer_value[2];
        tui_fsm->buffer_value[2] = input;
        MoveCursorToPosition(kLineValue, kColumnValue, tui_fsm);
        for(uint8_t i = 0; i < strlen(tui_fsm->buffer_command); i++)
        {
            UART1_Write(tui_fsm->buffer_command[i]);
        }
        for (uint8_t i = 0; i < 3; i++)
        {
            UART1_Write(tui_fsm->buffer_value[i]);
        }
        tui_fsm->value = atoi(tui_fsm->buffer_value);
        break;
      default:
        break;
    }
  }
  if ((input == 'N') || (input == 'n')) {
    InitReadNumber(tui_fsm);
  }
  if ((input == 'V') || (input == 'v')) {
    InitReadValue(tui_fsm);
  }
  if ((input == 'S') || (input == 's')) {
    MoveCursorToPosition(kLineMessage, kColumnValue, tui_fsm);
    for(uint8_t i = 0; i < strlen(tui_fsm->buffer_command); i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }    
    for(uint8_t i = 0; i < strlen(kSending); i++)
    {
        UART1_Write(kSending[i]);
    }
    UART1_Write(tui_fsm->number);
    UART1_Write(' ');
    UART1_Write(tui_fsm->number);
    UART1_Write(',');
    UART1_Write(' ');
    UART1_Write(tui_fsm->value);
    UART1_Write(' ');
    UART1_Write(tui_fsm->value);
    UART1_Write(' ');

    UART2_Write(tui_fsm->number);
    UART2_Write(tui_fsm->value);

    ClearLine(tui_fsm);
    for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
    MoveCursorToPosition(kLineMessage, kColumnRight, tui_fsm);
    for(uint8_t i = 0; i < kBufferSizeCommand; i++)
    {
        UART1_Write(tui_fsm->buffer_command[i]);
    }
    UART1_Write('|');
  }
  if (input == '/r') {
    InitMessage(tui_fsm);
  }
}