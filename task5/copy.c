#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_FILE_SIZE 10

void copy_file(const char *source, const char *destination) {
    FILE *src = fopen(source, "rb"); 
    if (src == NULL) {
        perror("Cannot open file for reading");
        exit(1);
    }

    fseek(src, 0, SEEK_END);
    long file_size = ftell(src);
    fseek(src, 0, SEEK_SET);

    if (file_size > MAX_FILE_SIZE) {
        fprintf(stderr, "File size exceeds the limit of %d bytes\n", MAX_FILE_SIZE);
        fclose(src);
        exit(1);
    }

    FILE *dst = fopen(destination, "wb"); 
    if (dst == NULL) {
        perror("Cannot open file for writing");
        fclose(src);
        exit(1);
    }

    char buffer[1024];
    size_t bytes_read, bytes_written;
    while ((bytes_read = fread(buffer, 1, sizeof(buffer), src)) > 0) {
        bytes_written = fwrite(buffer, 1, bytes_read, dst);
        if (bytes_written != bytes_read) {
            fprintf(stderr, "Error writing to file\n");
            fclose(src);
            fclose(dst);
            exit(1);
        }
    }

    fclose(src);
    fclose(dst);

    printf("File copied successfully!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Program need two arguments\n");
        return 1;
    }

    const char *source_file = argv[1];
    const char *destination_file = argv[2];

    copy_file(source_file, destination_file);

    return 0;
}
