#pragma once

#include "ch.h"
#include "hal.h"
#include "flash/config_struct.h"
#include "util/usbcfg.h"
#include "string.h"

constexpr uint32_t pack4(uint8_t b0, uint8_t b1, uint8_t b2, uint8_t b3)
{
  return (uint32_t(b0) << 24) | (uint32_t(b1) << 16) | (uint32_t(b2) << 8) | (uint32_t(b3) << 0);
}

enum class Command : uint32_t
{
  Read = pack4(0xAA, 0xBB, 0xCC, 0xDD),
  Write = pack4(0xEE, 0xFF, 0x00, 0x11),
  Defaults = pack4(0x22, 0x33, 0x44, 0x55),
  Unknown = 0xFFFFFFFFu
};

inline Command classifyCommand(const uint8_t buf[4])
{
  uint32_t v = pack4(buf[0], buf[1], buf[2], buf[3]);
  switch (v)
  {
  case static_cast<uint32_t>(Command::Read):
    return Command::Read;
  case static_cast<uint32_t>(Command::Write):
    return Command::Write;
  case static_cast<uint32_t>(Command::Defaults):
    return Command::Defaults;
  default:
    return Command::Unknown;
  }
}

void read_command(void);

#endif // API_H
