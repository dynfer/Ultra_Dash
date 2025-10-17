#pragma once

#include <cstdint>
#include <cstddef>
#include "ch.h"
#include "hal.h"

using flashaddr_t = uintptr_t;

using flashdata_t = uint32_t;

struct Flash
{
    static void EraseSector(uint8_t sectorIdx);
    static void Write(flashaddr_t address, const char* buffer, size_t size);
};