/*
Copyright (c) Bryan Hughes <bryan@nebri.us>

This file is part of RVL Arduino.

RVL Arduino is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

RVL Arduino is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with RVL Arduino.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <stdint.h>
#include <list>
#include "./rvl.h"
#include "./rvl/event.h"

namespace rvl {

struct ListenerEntry {
 public:
  int eventType;
  void (*listener)();
};
std::list<ListenerEntry> listeners;

void on(uint8_t eventType, void (*listener)()) {
  ListenerEntry entry = { eventType, listener };
  listeners.push_back(entry);
}

void emit(uint8_t eventType) {
  rvl::debug("Emitting event %d", eventType);
  for (auto& listener : listeners) {
    if (listener.eventType == eventType) {
      listener.listener();
    }
  }
}

}  // namespace rvl
