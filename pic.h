#ifndef INCLUDE_PIC_H
#define INCLUDE_PIC_H

#define PIC1_PORT_A        0x20               /* IO base address for master PIC */
#define PIC2_PORT_A        0xA0               /* IO base address for slave PIC */

/* The PIC interrupts have been remapped */
#define PIC1_START_INTERRUPT 0x20
#define PIC2_START_INTERRUPT 0x28
#define PIC2_END_INTERRUPT PIC2_START_INTERRUPT + 7

#define PIC_ACK 0x20

void pic_remap(int offset1, int offset2);

void pic_acknowledge(unsigned int interrupt);

#endif /* INCLUDE_PIC_H */