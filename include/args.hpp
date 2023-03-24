#pragma once
#include <argp.h>
#include <iostream>

namespace args {
class Arguments {
  public:
    std::string elf_file;
    std::string video_mode;
    std::string iso_directory;

    Arguments() : video_mode("NTSC"), iso_directory("ISO/") {}
};

class Argsdoc {
  public:
    static char *docs;
    static char *argDocs;
};

class Option {
  public:
    static const argp_option options[];
    static error_t ParseOpt(int key, char *arg, struct argp_state *state);
};
} // namespace args
