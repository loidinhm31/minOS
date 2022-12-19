#include "multiboot.h"

int kmain(/* additional arguments */ unsigned int ebx) {
    multiboot_info_t *mbinfo = (multiboot_info_t *) ebx;
    unsigned int address_of_module = mbinfo->mods_addr;

    typedef void (*call_module_t)(void);
    call_module_t start_program = (call_module_t) address_of_module;
    start_program();

    return 0;
}