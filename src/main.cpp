#include "args.hpp"
#include "system_cnf.hpp"
#include <argp.h>
#include <filesystem>
#include <iostream>

int main(int argc, char **argv) {

    args::Arguments arguments;
    args::Option options;

    const argp argp_parser = {
        options.options,     options.ParseOpt, args::Argsdoc::argDocs,
        args::Argsdoc::docs, nullptr,          nullptr};

    /* Parse our arguments; every option seen by Option::ParseOpt will
     *      be reflected in arguments. */
    argp_parse(&argp_parser, argc, argv, 0, 0, &arguments);

    try {
        std::filesystem::create_directory(arguments.iso_directory);
        std::cout << arguments.iso_directory << " created.\n";
    } catch (const std::filesystem::filesystem_error &error) {
        std::cerr << error.what() << '\n';
    }

    try {
        std::filesystem::copy(arguments.elf_file, arguments.iso_directory);
        std::cout << arguments.elf_file << "copied to"
                  << arguments.iso_directory << '\n';
    } catch (const std::filesystem::filesystem_error &error) {
        std::cerr << error.what() << '\n';
    }

    std::filesystem::path path = arguments.iso_directory.append("SYSTEM.CNF");
    system_cnf::createCNF(path, arguments);
    return 0;
}
