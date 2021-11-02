#include <dirent.h>
#include <stdio.h>

int main() {
	DIR *d= opendir("/");
	struct dirent *dir;
	while ((dir = readdir(d)) != NULL) {
		printf("%s\n", dir->d_name);
	}
	closedir(d);
	return 0;
}