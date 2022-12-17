AS = nasm
ASFLAGS = -f elf32

LD = ld
LDFLAGS = -T link.ld -melf_i386

OBJECTS = loader.o

clean:
	rm -rf *.o *os.iso kernel.elf ./iso/boot/kernel.elf

%.o: %.s
	$(AS) $(ASFLAGS) $< -o $@

linker: $(OBJECTS)
	$(LD) $(LDFLAGS) $(OBJECTS) -o kernel.elf

minos: linker
	cp kernel.elf iso/boot/kernel.elf
	genisoimage -R                              \
				-b boot/grub/stage2_eltorito    \
				-no-emul-boot                   \
                -boot-load-size 4               \
                -A os                           \
                -input-charset utf8             \
                -quiet                          \
                -boot-info-table                \
                -o minos.iso                    \
                iso