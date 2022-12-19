#ifndef SEGMENTATION_H
#define SEGMENTATION_H

struct gdt {
    unsigned int address;
    unsigned short size;
} __attribute__((packed));

#endif //SEGMENTATION_H
