#include <stdio.h>


int main (int argc, char* argv[])
{

	system("cat /proc/cpuinfo | grep -m 1 'model name'");
	return 0;
}