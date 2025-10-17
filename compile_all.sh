#!/bin/bash

rm -rf export
rm -rf .dep && rm -rf build && rm -rf h743bootloader/.dep && rm -rf h743bootloader/build

cd h743bootloader
make clean && make -j $(nproc)
cd ..
make clean && make -j $(nproc)

mkdir export
cp build/ch.bin export/ && cp h743bootloader/build/h7bl.bin export/
cd export

CRC_HEX=$(python3 -c "import zlib; print(hex(zlib.crc32(open('ch.bin','rb').read()) & 0xffffffff))")
SIZE=$(python3 -c "print(open('ch.bin','rb').read().__len__())")
python3 -c "import sys, struct; sys.stdout.buffer.write(struct.pack('<I', int('$CRC_HEX', 16)))" > crc.bin
python3 -c "import sys, struct; sys.stdout.buffer.write(struct.pack('<I', int('$SIZE')))" > size.bin

dd if=/dev/zero of=configbl_raw.bin bs=1 count=1024
dd if=size.bin of=configbl_raw.bin bs=1 seek=0 conv=notrunc
dd if=crc.bin  of=configbl_raw.bin bs=1 seek=4 conv=notrunc
arm-none-eabi-objcopy -I binary -O elf32-littlearm -B arm --rename-section .data=.configbl,alloc,load,readonly,contents configbl_raw.bin configbl.o
arm-none-eabi-objcopy -I binary -O elf32-littlearm -B arm h7bl.bin bootloader.o
arm-none-eabi-objcopy -I binary -O elf32-littlearm -B arm ch.bin application.o
arm-none-eabi-objcopy --rename-section .data=.bootloader,alloc,load,readonly,contents bootloader.o bootloader-renamed.o
arm-none-eabi-objcopy --rename-section .data=.application,alloc,load,readonly,contents application.o application-renamed.o
arm-none-eabi-ld -T ../combine.ld bootloader-renamed.o configbl.o application-renamed.o -o combined.elf
arm-none-eabi-objcopy -O binary combined.elf ch_with_bl.bin
rm *.o