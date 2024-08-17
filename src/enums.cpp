/**
 * Copyright 2020-2024 Fraunhofer Institute for Applied Information Technology
 * FIT
 *
 * This file is part of iec104-python.
 * iec104-python is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * iec104-python is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with iec104-python. If not, see <https://www.gnu.org/licenses/>.
 *
 *  See LICENSE file for the complete license text.
 *
 *
 * @file Enums.cpp
 * @brief shared enums, flags and string conversion of these
 *
 * @package iec104-python
 * @namespace
 *
 * @authors Martin Unkel <martin.unkel@fit.fraunhofer.de>
 *
 */

#include <numeric>
#include <vector>

#include "enums.h"

std::string Debug_toString(Debug mode) {
  if (is_none(mode)) {
    return "Debug set: {}, is_none: True";
  }
  std::vector<std::string> sv{};
  if (test(mode, Debug::Server))
    sv.emplace_back("Server");
  if (test(mode, Debug::Client))
    sv.emplace_back("Client");
  if (test(mode, Debug::Connection))
    sv.emplace_back("Connection");
  if (test(mode, Debug::Station))
    sv.emplace_back("Station");
  if (test(mode, Debug::Point))
    sv.emplace_back("Point");
  if (test(mode, Debug::Message))
    sv.emplace_back("Message");
  if (test(mode, Debug::Callback))
    sv.emplace_back("Callback");
  if (test(mode, Debug::Gil))
    sv.emplace_back("Gil");
  return "Debug set: { " +
         std::accumulate(std::next(sv.begin()), sv.end(), sv[0],
                         [](const std::string &a, const std::string &b) {
                           return a + " | " + b;
                         }) +
         " }, is_none: False";
}

std::string Debug_toFlagString(Debug mode) {
  if (is_none(mode)) {
    return "None";
  }
  std::vector<std::string> sv{};
  if (test(mode, Debug::Server))
    sv.emplace_back("Server");
  if (test(mode, Debug::Client))
    sv.emplace_back("Client");
  if (test(mode, Debug::Connection))
    sv.emplace_back("Connection");
  if (test(mode, Debug::Station))
    sv.emplace_back("Station");
  if (test(mode, Debug::Point))
    sv.emplace_back("Point");
  if (test(mode, Debug::Message))
    sv.emplace_back("Message");
  if (test(mode, Debug::Callback))
    sv.emplace_back("Callback");
  if (test(mode, Debug::Gil))
    sv.emplace_back("Gil");
  return std::accumulate(
      std::next(sv.begin()), sv.end(), sv[0],
      [](const std::string &a, const std::string &b) { return a + " | " + b; });
}

std::string Quality_toString(Quality quality) {
  if (is_none(quality)) {
    return "Quality set: {}, is_good: True";
  }
  std::vector<std::string> sv{};
  if (test(quality, Quality::Overflow))
    sv.emplace_back("Overflow");
  //  if (test(quality, Quality::Reserved))
  //    sv.emplace_back("Reserved");
  if (test(quality, Quality::ElapsedTimeInvalid))
    sv.emplace_back("ElapsedTimeInvalid");
  if (test(quality, Quality::Blocked))
    sv.emplace_back("Blocked");
  if (test(quality, Quality::Substituted))
    sv.emplace_back("Substituted");
  if (test(quality, Quality::NonTopical))
    sv.emplace_back("NonTopical");
  if (test(quality, Quality::Invalid))
    sv.emplace_back("Invalid");
  return "Quality set: { " +
         std::accumulate(std::next(sv.begin()), sv.end(), sv[0],
                         [](const std::string &a, const std::string &b) {
                           return a + " | " + b;
                         }) +
         " }, is_good: False";
}

std::string
BinaryCounterQuality_toString(BinaryCounterQuality BinaryCounterQuality) {
  if (is_none(BinaryCounterQuality)) {
    return "BinaryCounterQuality set: {}, is_good: True";
  }
  std::vector<std::string> sv{};
  if (test(BinaryCounterQuality, BinaryCounterQuality::Adjusted))
    sv.emplace_back("Adjusted");
  if (test(BinaryCounterQuality, BinaryCounterQuality::Carry))
    sv.emplace_back("Carry");
  if (test(BinaryCounterQuality, BinaryCounterQuality::Invalid))
    sv.emplace_back("Invalid");
  return "BinaryCounterQuality set: { " +
         std::accumulate(std::next(sv.begin()), sv.end(), sv[0],
                         [](const std::string &a, const std::string &b) {
                           return a + " | " + b;
                         }) +
         " }, is_good: False";
}

std::string StartEvents_toString(StartEvents events) {
  if (is_none(events)) {
    return "StartEvent set: {}";
  }
  std::vector<std::string> sv{};
  if (test(events, StartEvents::General))
    sv.emplace_back("General");
  if (test(events, StartEvents::PhaseL1))
    sv.emplace_back("PhaseL1");
  if (test(events, StartEvents::PhaseL2))
    sv.emplace_back("PhaseL2");
  if (test(events, StartEvents::PhaseL3))
    sv.emplace_back("PhaseL3");
  if (test(events, StartEvents::InEarthCurrent))
    sv.emplace_back("InEarthCurrent");
  if (test(events, StartEvents::ReverseDirection))
    sv.emplace_back("ReverseDirection");
  return "StartEvents set: { " +
         std::accumulate(std::next(sv.begin()), sv.end(), sv[0],
                         [](const std::string &a, const std::string &b) {
                           return a + " | " + b;
                         }) +
         " }";
}

std::string OutputCircuits_toString(OutputCircuits infos) {
  if (is_none(infos)) {
    return "OutputCircuit set: {}";
  }
  std::vector<std::string> sv{};
  if (test(infos, OutputCircuits::General))
    sv.emplace_back("General");
  if (test(infos, OutputCircuits::PhaseL1))
    sv.emplace_back("PhaseL1");
  if (test(infos, OutputCircuits::PhaseL2))
    sv.emplace_back("PhaseL2");
  if (test(infos, OutputCircuits::PhaseL3))
    sv.emplace_back("PhaseL3");
  return "OutputCircuit set: { " +
         std::accumulate(std::next(sv.begin()), sv.end(), sv[0],
                         [](const std::string &a, const std::string &b) {
                           return a + " | " + b;
                         }) +
         " }";
}

std::string FieldSet16_toString(FieldSet16 infos) {
  if (is_none(infos)) {
    return "Field set: {}";
  }
  std::vector<std::string> sv{};
  if (test(infos, FieldSet16::I1))
    sv.emplace_back("I1");
  if (test(infos, FieldSet16::I2))
    sv.emplace_back("I2");
  if (test(infos, FieldSet16::I3))
    sv.emplace_back("I3");
  if (test(infos, FieldSet16::I4))
    sv.emplace_back("I4");
  if (test(infos, FieldSet16::I5))
    sv.emplace_back("I5");
  if (test(infos, FieldSet16::I6))
    sv.emplace_back("I6");
  if (test(infos, FieldSet16::I7))
    sv.emplace_back("I7");
  if (test(infos, FieldSet16::I8))
    sv.emplace_back("I8");
  if (test(infos, FieldSet16::I9))
    sv.emplace_back("I9");
  if (test(infos, FieldSet16::I10))
    sv.emplace_back("I10");
  if (test(infos, FieldSet16::I11))
    sv.emplace_back("I11");
  if (test(infos, FieldSet16::I12))
    sv.emplace_back("I12");
  if (test(infos, FieldSet16::I13))
    sv.emplace_back("I13");
  if (test(infos, FieldSet16::I14))
    sv.emplace_back("I14");
  if (test(infos, FieldSet16::I15))
    sv.emplace_back("I15");
  return "Field set: { " +
         std::accumulate(std::next(sv.begin()), sv.end(), sv[0],
                         [](const std::string &a, const std::string &b) {
                           return a + " | " + b;
                         }) +
         " }";
}

std::string QualifierOfCommand_toString(CS101_QualifierOfCommand qualifier) {
  switch (qualifier) {
  case CS101_QualifierOfCommand::NONE:
    return "NONE";
  case CS101_QualifierOfCommand::SHORT_PULSE:
    return "SHORT_PULSE";
  case CS101_QualifierOfCommand::LONG_PULSE:
    return "LONG_PULSE";
  case CS101_QualifierOfCommand::PERSISTENT:
    return "PERSISTENT";
  default:
    return "UNKNOWN";
  }
}

std::string ConnectionState_toString(const ConnectionState state) {
  switch (state) {
  case CLOSED:
    return "CLOSED";
  case CLOSED_AWAIT_OPEN:
    return "CLOSED_AWAIT_OPEN";
  case CLOSED_AWAIT_RECONNECT:
    return "CLOSED_AWAIT_RECONNECT";
  case OPEN_MUTED:
    return "OPEN_MUTED";
  case OPEN_AWAIT_INTERROGATION:
    return "OPEN_AWAIT_INTERROGATION";
  case OPEN_AWAIT_CLOCK_SYNC:
    return "OPEN_AWAIT_CLOCK_SYNC";
  case OPEN:
    return "OPEN";
  case OPEN_AWAIT_CLOSED:
    return "OPEN_AWAIT_CLOSED";
  default:
    return "UNKNOWN";
  }
}

std::string ConnectionEvent_toString(const CS104_ConnectionEvent event) {
  switch (event) {
  case CS104_CONNECTION_OPENED:
    return "OPENED";
  case CS104_CONNECTION_CLOSED:
    return "CLOSED";
  case CS104_CONNECTION_STARTDT_CON_RECEIVED:
    return "ACTIVATED";
  case CS104_CONNECTION_STOPDT_CON_RECEIVED:
    return "DEACTIVATED";
  default:
    return "UNKNOWN";
  }
}

std::string
PeerConnectionEvent_toString(const CS104_PeerConnectionEvent event) {
  switch (event) {
  case CS104_CON_EVENT_CONNECTION_OPENED:
    return "OPENED";
  case CS104_CON_EVENT_CONNECTION_CLOSED:
    return "CLOSED";
  case CS104_CON_EVENT_ACTIVATED:
    return "ACTIVATED";
  case CS104_CON_EVENT_DEACTIVATED:
    return "DEACTIVATED";
  default:
    return "UNKNOWN";
  }
}

std::string DoublePointValue_toString(const DoublePointValue value) {
  switch (value) {
  case IEC60870_DOUBLE_POINT_INDETERMINATE:
    return "INDETERMINATE";
  case IEC60870_DOUBLE_POINT_OFF:
    return "OFF";
  case IEC60870_DOUBLE_POINT_ON:
    return "ON";
  case IEC60870_DOUBLE_POINT_INTERMEDIATE:
    return "INTERMEDIATE";
  default:
    return "UNKNOWN";
  }
}

std::string StepCommandValue_toString(const StepCommandValue value) {
  switch (value) {
  case IEC60870_STEP_INVALID_0:
    return "INVALID_0";
  case IEC60870_STEP_LOWER:
    return "LOWER";
  case IEC60870_STEP_HIGHER:
    return "HIGHER";
  case IEC60870_STEP_INVALID_3:
    return "INVALID_3";
  default:
    return "UNKNOWN";
  }
}

std::string EventState_toString(const EventState state) {
  switch (state) {
  case IEC60870_EVENTSTATE_INDETERMINATE_0:
    return "INDETERMINATE_0";
  case IEC60870_EVENTSTATE_OFF:
    return "OFF";
  case IEC60870_EVENTSTATE_ON:
    return "ON";
  case IEC60870_EVENTSTATE_INDETERMINATE_3:
    return "INDETERMINATE_3";
  default:
    return "UNKNOWN";
  }
}

std::string CommandTransmissionMode_toString(CommandTransmissionMode mode) {
  switch (mode) {
  case DIRECT_COMMAND:
    return "DIRECT";
  case SELECT_AND_EXECUTE_COMMAND:
    return "SELECT_AND_EXECUTE";
  default:
    return "UNKNOWN";
  }
}
