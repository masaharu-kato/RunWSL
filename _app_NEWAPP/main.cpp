#include "RunWSL.h"

int main(int argc, char *argv[]) {
	return run_wsl_command("NEWAPP", make_args(argc, argv));
}
