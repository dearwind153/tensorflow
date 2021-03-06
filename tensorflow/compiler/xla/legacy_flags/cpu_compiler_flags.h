/* Copyright 2017 The TensorFlow Authors. All Rights Reserved.

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
==============================================================================*/

#ifndef TENSORFLOW_COMPILER_XLA_LEGACY_FLAGS_CPU_COMPILER_FLAGS_H_
#define TENSORFLOW_COMPILER_XLA_LEGACY_FLAGS_CPU_COMPILER_FLAGS_H_

// Legacy flags for the XLA's cpu_compiler module.

#include <vector>

#include "tensorflow/compiler/xla/types.h"
#include "tensorflow/core/platform/types.h"
#include "tensorflow/core/util/command_line_flags.h"

namespace xla {
namespace legacy_flags {

// Append to *flag_list flag definitions associated with XLA's cpu_compiler
// module.
void AppendCpuCompilerFlags(std::vector<tensorflow::Flag>* flag_list);

// The values of flags associated with XLA's cpu_compiler module.
typedef struct {
  // The LLVM optimization level for the CPU XLA backend.
  // Valid range is from 0 to 3 where 0 means no optimizations.
  int32 xla_cpu_llvm_opt_level;
  string xla_cpu_llvm_cl_opts;  // Comma-separated list of command line options
                                // to pass to LLVM.
  bool xla_cpu_embed_ir;  // Embed the LLVM IR module string in the resultant
                          // CpuExecutable
  bool xla_cpu_parallel;  // Use the multi-threaded CPU backend.
} CpuCompilerFlags;

// Return a pointer to the CpuCompilerFlags struct;
// repeated calls return the same pointer.
// This should be called only after Flags::Parse() has returned.
CpuCompilerFlags* GetCpuCompilerFlags();

}  // namespace legacy_flags
}  // namespace xla

#endif  // TENSORFLOW_COMPILER_XLA_LEGACY_FLAGS_CPU_COMPILER_FLAGS_H_
