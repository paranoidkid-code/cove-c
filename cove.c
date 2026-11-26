
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

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
    size_t postfix_len = strlen(postfix);
    
    // if the postfix is longer that the filename its not in it
    if (postfix_len > filename_len) return false;

    // point start to the start of the postfix
    const char *start = filename + filename_len - postfix_len;

    // loop until see that its not the same
    for (size_t i = 0; i < postfix_len; i++) {
        if (tolower((unsigned char)start[i]) != tolower((unsigned char)postfix[i])) {
            return false;
        }
    }

    return true;
}

int main(int argc, char const *argv[]) {
    // if there are more or less than 2 args (cove filename.cove), display error msg and return
    if (argc != 2) {
        fprintf(stderr, "Unexpected amount of args, 1 needed\nUsage: cove filename.cove\n");
        return 1;
    }

    const char *filename = argv[1];

     // if the filename doesnt end with the needed postfix, display error msg and return
    if (!endswith(filename, POSTFIX)) {
        fprintf(stderr, "Filename %s's postfix is unrecognized\nExpected: %s\n", filename, POSTFIX);
        return 1;
    }

    FILE *file = fopen(filename, "r"); // open the file given
    if (file == NULL) { // could not open file
        perror("Error opening file");
        return 1;
    }

    // TODO: process file

    fclose(file);
    return 0;
}
