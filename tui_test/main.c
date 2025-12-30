#include <stdio.h>
#include <stdint.h>

#include "tui.h"

void main(void) {
  TuiFsm tui_fsm;

  InitTuiFsm(&tui_fsm);

  InitMessage(&tui_fsm);
}
