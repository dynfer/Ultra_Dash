#pragma once
#include "ch.h"
#include "hal.h"
#include <cstdint>
#include <cstddef>

using flashaddr_t = uintptr_t;

using flashdata_t = uint32_t;

struct Flash
{
    static void EraseSector(uint8_t sectorIdx, uint8_t bank);
    static void Write(flashaddr_t address, const char* buffer, size_t size, uint8_t bank);
};