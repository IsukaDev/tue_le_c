#include "tue_le_c.h"

int main(int argc, char *argv[])
{
	FILE *file = NULL;
	char *line = NULL;
	size_t line_size = 0;

	file = fopen("data/tue_le_c.csv", "r");

	if (file != NULL) {
		while (getline(&line, &line_size, file) > 0) {
			printf("%s", line);
		}
		fclose(file);
		return 0;
	} else {
		printf(OPEN_ERROR, "data/tue_le_c.csv");
		return 1;
	}
}
