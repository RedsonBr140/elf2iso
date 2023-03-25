#include "system_cnf.hpp"
#include "args.hpp"
#include <filesystem>
#include <fstream>
#include <iostream>

namespace system_cnf {
error_t createCNF(std::filesystem::path path, args::Arguments args) {
    std::ofstream file(path);
    if (!file) {
        std::cerr << "Error: could not open the file";
    }
    file << "BOOT2 = cdrom0:" << args.elf_file.filename() << ";1\n";

    // FIXME: Allow the user to insert the version
    file << "VER = "
         << "1.00" << '\n';

    file << "VMODE = " << args.video_mode << '\n';

    file.close();
    return 0;
}
} // namespace system_cnf
