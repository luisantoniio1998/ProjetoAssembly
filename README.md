# Vector addition in C++ and Assembly

My Computer Architecture project. A C++ program sets up two arrays of 65,536 integers and calls an Assembly routine to add them.

The routine uses SSE instructions to process four integers at a time. The C++ code measures the call with `__rdtsc()` and prints the sums and cycle count.

## Files

- `Projeto.cpp` — array setup, Assembly call, and timing
- `Source.asm` — `add_vtr_asm` implementation

## Build notes

The source uses Microsoft-specific C++ syntax and MASM-style Assembly. Build the two files together with a compatible 32-bit Microsoft C++/MASM toolchain.

There is no benchmark dataset or separate C++ implementation here to support a general speedup claim. The cycle count is the output of this particular exercise.
