/*
Copyright (c) Bryan Hughes <bryan@nebri.us>

This file is part of Raver Lights Messaging.

Raver Lights Messaging is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Raver Lights Messaging is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Raver Lights Messaging.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef RAVERLIGHTSMESSAGING_H_
#define RAVERLIGHTSMESSAGING_H_

#include <stdint.h>
#include "./rvl/wave.h"
#include "./rvl/logging.h"

// Note: we use the old style of enums here because we regularly switch between uint8_t values and these enum values
namespace RVLPacketType {
  enum RVLPacketType {
    Palette = 1,
    Wave = 2
  };
}

class RVLTransportInterface {
 public:
  virtual void beginWrite() = 0;
  virtual void write8(uint8_t data) = 0;
  virtual void write16(uint16_t data) = 0;
  virtual void write32(uint32_t data) = 0;
  virtual void write(uint8_t* data, uint16_t length) = 0;
  virtual void endWrite() = 0;

  virtual uint16_t parsePacket() = 0;
  virtual uint8_t read8() = 0;
  virtual uint16_t read16() = 0;
  virtual uint32_t read32() = 0;
  virtual void read(uint8_t* buffer, uint16_t length) = 0;
};

enum class RVLDeviceMode { Controller, Receiver };

class RVLPlatformInterface {
 protected:
  void onWaveSettingsUpdated();

 public:
  virtual uint32_t getLocalTime() = 0;
  virtual uint32_t getClockOffset() = 0;
  virtual void setClockOffset(uint32_t newOffset) = 0;

  virtual RVLDeviceMode getDeviceMode() = 0;
  virtual void setDeviceMode(RVLDeviceMode newMode) = 0;
  virtual uint16_t getDeviceId() = 0;

  virtual RVLWaveSettings* getWaveSettings() = 0;
  virtual void setWaveSettings(RVLWaveSettings* newWaveSettings) = 0;
};

void RVLMessagingInit(
  RVLPlatformInterface* platform,
  RVLTransportInterface* transport,
  RVLLoggingInterface* logging);

void RVLMessagingLoop();

#endif  // RAVERLIGHTSMESSAGING_H_