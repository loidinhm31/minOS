#include "io.h"

/* The I/O ports */
#define FB_COMMAND_PORT         0x3D4
#define FB_DATA_PORT            0x3D5

/* The I/O port commands */
#define FB_HIGH_BYTE_COMMAND    14
#define FB_LOW_BYTE_COMMAND     15

#define FB_GREEN     2
#define FB_DARK_GREY 8

char *fb = (char *) 0x000B8000;

int write(char *buf, unsigned int len);

/** fb_write_cell:
     *  Writes a character with the given foreground and background to position i
     *  in the framebuffer.
     *
     *  @param i  The location in the framebuffer
     *  @param c  The character
     *  @param fg The foreground color
     *  @param bg The background color
     */
void fb_write_cell(unsigned int i, char c, unsigned char fg, unsigned char bg) {
    fb[i] = c;
    fb[i + 1] = ((fg & 0x0F) << 4) | (bg & 0x0F)
}

/** fb_move_cursor:
     *  Moves the cursor of the framebuffer to the given position
     *
     *  @param pos The new position of the cursor
     */
void fb_move_cursor(unsigned short pos) {
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb(FB_DATA_PORT, ((pos >> 8) & 0x00FF));
    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb(FB_DATA_PORT, pos & 0x00FF);
}

unsigned int* cursor_position() {
    outb(FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    unsigned char high = inb(FB_DATA_PORT);

    outb(FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    unsigned char low = inb(FB_DATA_PORT);

    return (high << 8) | low;
}

int fb_write(char *buf, unsigned int len) {
    unsigned int* position = cursor_position();

    for (unsigned int i = 0; i < len; i++) {
        fb_write_cell(position, *(buf + i), FB_GREEN, FB_DARK_GREY);
        position += 1;
        fb_move_cursor(position);
    }
    return 0;
}