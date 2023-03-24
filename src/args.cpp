#include "args.hpp"
#include <argp.h>
#include <iostream>
// There's nothing we can do about this garbage here.

#ifdef VERSION
#define GET_VER(x) "elf2iso " #x
#define GET_MACRO_VALUE(x) GET_VER(x)
const char *argp_program_version = GET_MACRO_VALUE(VERSION);
#else
const char *argp_program_version = "elf2iso !unknown!";
#endif
const char *argp_program_bug_address = "<redson@riseup.net>";

namespace args {
char *Argsdoc::docs =
    (char *)"elf2iso -- Simple program to convert PS2 elf files to ISOs.";

char *Argsdoc::argDocs = (char *)"ELF_FILE";
} // namespace args

const argp_option args::Option::options[] = {
    {"video", 'V', 0, OPTION_ARG_OPTIONAL, "Video mode (Default: NTSC)"},
    {"dir", 'd', 0, OPTION_ARG_OPTIONAL,
     "Generate the ISO from this directory. Useful if you want to include "
     "other files.(Default: ISO) "},
    {"delete", 'D', 0, 0,
     "Delete ISO directory after building the ISO itself."},
    {0}};

error_t args::Option::ParseOpt(int key, char *arg, struct argp_state *state) {
    Arguments *arguments = reinterpret_cast<Arguments *>(state->input);

    switch (key) {
    case 'V':
        arguments->video_mode = arg;
        break;
    case 'd':
        arguments->iso_directory = arg;
        break;
    case ARGP_KEY_ARG:
        if (state->arg_num >= 1)
            argp_usage(state);
        arguments->elf_file = arg;
        break;
    case ARGP_KEY_END:
        if (state->arg_num < 1)
            argp_usage(state);
        break;
    default:
        return ARGP_ERR_UNKNOWN;
    };

    return 0;
}
