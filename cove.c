
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

const char *POSTFIX = ".cove";

/**
 * @brief Checks whether the filename ends with the postfix
 * 
 * @param *filename The file's full name you want to check
 * @param *postfix The postfix you want to check
 * @return A boolean (true / false) on whether the filename ends with the postfix
 */
bool endswith(const char *filename, const char *postfix) {
    if (!filename || !postfix) return false;

    // get lengths of strings
    size_t filename_len = strlen(filename);
    size_t suffix_len = strlen(postfix);

    // if the postfix is longer that the filename its not in it
    if (suffix_len > filename_len) return false;

    return (bool)strcmp(filename + filename_len - suffix_len, postfix);
}

int main(int argc, char const *argv[]) {
    char *filename = argv[1];
    if (!endswith(filename, POSTFIX)) {
        printf("Filename %s's postfix is not %s", filename, POSTFIX); // display error msg
        return 1;
    }
    FILE *file = fopen(filename, "r"); // open the file given
    // TODO: check if file is not found

    fclose(file);
    return 0;
}
