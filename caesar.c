/* Caesar cipher: encrypt, decrypt, or brute-force a message. */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

static void shift_text(const char *in, char *out, int key) {
    key = ((key % 26) + 26) % 26;
    size_t i;
    for (i = 0; in[i] != '\0'; i++) {
        if (isupper((unsigned char)in[i]))
            out[i] = 'A' + (in[i] - 'A' + key) % 26;
        else if (islower((unsigned char)in[i]))
            out[i] = 'a' + (in[i] - 'a' + key) % 26;
        else
            out[i] = in[i];
    }
    out[i] = '\0';
}

static void usage(const char *prog) {
    fprintf(stderr,
        "Usage:\n"
        "  %s encrypt <key> \"text\"\n"
        "  %s decrypt <key> \"text\"\n"
        "  %s crack \"text\"      (tries all 25 keys)\n", prog, prog, prog);
}

int main(int argc, char *argv[]) {
    if (argc < 3) { usage(argv[0]); return 1; }

    if (strcmp(argv[1], "crack") == 0) {
        size_t n = strlen(argv[2]);
        char *buf = malloc(n + 1);
        if (!buf) return 1;
        for (int k = 1; k < 26; k++) {
            shift_text(argv[2], buf, -k);
            printf("Key %2d: %s\n", k, buf);
        }
        free(buf);
        return 0;
    }

    if (argc != 4) { usage(argv[0]); return 1; }
    int key = atoi(argv[2]);
    int enc = strcmp(argv[1], "encrypt") == 0;
    if (!enc && strcmp(argv[1], "decrypt") != 0) { usage(argv[0]); return 1; }

    char *buf = malloc(strlen(argv[3]) + 1);
    if (!buf) return 1;
    shift_text(argv[3], buf, enc ? key : -key);
    printf("%s\n", buf);
    free(buf);
    return 0;
}
