#include "RunWSL.h"

int main(int argc, char *argv[]) {
	return run_wsl_command("ls", make_args(argc, argv));
}
