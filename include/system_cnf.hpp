#pragma once
#include "args.hpp"
#include <filesystem>
// #include <iostream>
namespace system_cnf {
error_t createCNF(std::filesystem::path path, args::Arguments args);
}
