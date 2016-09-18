#include "keyboard.h"
#include "../assembly_interface.h"
#include "../stdio.h"
#include "../types.h"

#define KBD_DATA_PORT   0x60

/** read_scan_code:
*  Reads a scan code from the keyboard
*
*  @return The scan code (NOT an ASCII character!)
*/
uint8_t read_scan_code()
{
  return inb(KBD_DATA_PORT);
}

uint8_t consume_scan_code() {
  uint8_t scan_code = read_scan_code();
  log("consume_scan_code() consumed: ");
  print_uint8(LOG, scan_code);
  log("\n");

  return scan_code;
}