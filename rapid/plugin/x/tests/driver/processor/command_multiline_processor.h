/*
 * Copyright (c) 2017, Oracle and/or its affiliates. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; version 2 of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA
 */

#ifndef X_TESTS_DRIVER_PROCESSOR_COMMAND_MULTILINE_PROCESSOR_H_
#define X_TESTS_DRIVER_PROCESSOR_COMMAND_MULTILINE_PROCESSOR_H_

#include <string>
#include "processor/block_processor.h"
#include "processor/command_processor.h"


class Command_multiline_processor : public Command_processor {
 public:
  using Command_processor::Command_processor;

  Result feed(std::istream &input, const char *command_line) override;

 private:
  bool is_multiline(const char *command_line);
  bool append_and_check_command(
      const char *command_line,
      const char **out_full_command,
      bool *out_wrong_format);

  bool m_eating_multiline{ false };
  std::string m_multiline_command;
};

#endif  // X_TESTS_DRIVER_PROCESSOR_COMMAND_MULTILINE_PROCESSOR_H_
