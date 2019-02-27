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

#ifndef PROTOCOLS_GIGGLE_PIXEL_WAVE_H_
#define PROTOCOLS_GIGGLE_PIXEL_WAVE_H_

#include "./RaverLightsMessaging.h"

// Packet:
// h: a b w_t w_x phi
// s: a b w_t w_x phi
// v: a b w_t w_x phi
// a: a b w_t w_x phi
// 20 bytes per wave, 4 waves total for 80 bytes

namespace Wave {

void init();
void loop();

void parsePacket();

}  // namespace Wave

#endif  // PROTOCOLS_GIGGLE_PIXEL_WAVE_H_
