#pragma once
#include <argp.h>
#include <filesystem>
namespace args {
class Arguments {
  public:
    std::filesystem::path elf_file;
    std::string video_mode;
    std::filesystem::path iso_directory;

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
