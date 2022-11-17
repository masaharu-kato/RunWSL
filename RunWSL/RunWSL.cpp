#include <sstream>
#include <string>
#include <vector>
#include <regex>
#include <direct.h>
#include "RunWSL.h"

constexpr static int PATH_MAX = 256;

std::vector<std::string> make_args(int argc, char *argv[]) {
	return {argv + 1, argv + argc};
}

int run_wsl_command(std::string app_name, std::vector<std::string> args) {
	std::string command = get_run_wsl_command(app_name, args);
	return system(command.c_str());
}

std::string get_run_wsl_command(std::string app_name, std::vector<std::string> args) {
	std::stringstream ss;
	ss << "wsl -- cd ";
	ss << to_wsl_path(get_current_dir());
	ss << "; ";
	ss << app_name;
	for(std::string arg : args) ss << " " << arg;
	return ss.str();
}

std::string get_current_dir() {
	char buf[PATH_MAX];
	char* _ret = _getcwd(buf, PATH_MAX);
	return std::string(buf);
}

std::string to_wsl_path(std::string win_path) {
	std::string drive{char(tolower(win_path[0]))};
	std::replace(win_path.begin() + 3, win_path.end(), '\\', '/');
	return "/mnt/" + drive + "/" + win_path.substr(3);
}
