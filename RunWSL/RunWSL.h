#pragma once

#include <string>
#include <vector>

std::vector<std::string> make_args(int argc, char *argv[]);
int run_wsl_command(std::string app_name, std::vector<std::string> args);
std::string get_run_wsl_command(std::string app_name, std::vector<std::string> args);
std::string get_current_dir();
std::string to_wsl_path(std::string win_path);
