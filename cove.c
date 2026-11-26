
#include <stdio.h>

int main(int argc, char const *argv[]) {
    FILE *file = fopen(argv[1], "r"); // open the file given
    // TODO: check if file is not found

    fclose(file);
    return 0;
}
