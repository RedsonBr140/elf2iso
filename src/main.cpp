#include "args.hpp"
#include <argp.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  args::Arguments arguments;
  args::Option options;

  const argp argp_parser = {
      options.options,     options.ParseOpt, args::Argsdoc::argDocs,
      args::Argsdoc::docs, nullptr,          nullptr};

  /* Parse our arguments; every option seen by parse_opt will
   *      be reflected in arguments. */
  argp_parse(&argp_parser, argc, argv, 0, 0, &arguments);

  std::cout << "ELF FILE:" << arguments.elf_file;

  return 0;
}
