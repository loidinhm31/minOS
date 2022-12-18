#ifndef INCLUDE_KEYBOARD_H
#define INCLUDE_KEYBOARD_H

#define KBD_DATA_PORT 0x60

unsigned char keyboard_read_scan_code(void);

unsigned char keyboard_scan_code_to_ascii(unsigned char);

#endif /* INCLUDE_KEYBOARD_H */