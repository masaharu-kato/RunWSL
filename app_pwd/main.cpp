#include "RunWSL.h"

int main(int argc, char *argv[]) {
	return run_wsl_command("pwd", make_args(argc, argv));
}
