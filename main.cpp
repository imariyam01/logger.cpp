#include "mylogger.h"
#include <stdarg.h>

static FILE *log_file = NULL;
static pthread_mutex_t log_mutex;

void init_logger(const char *filename) {
    log_file = fopen(filename, "w");
    if (!log_file) {
        perror("fopen");
    }
    pthread_mutex_init(&log_mutex, NULL);
}

void log_message(const char *format, ...) {
    if (!log_file) return;
    pthread_mutex_lock(&log_mutex);

    va_list args;
    va_start(args, format);
    vfprintf(log_file, format, args);
    fprintf(log_file, "\n");
    va_end(args);

    pthread_mutex_unlock(&log_mutex);
}

void close_logger() {
    if (log_file) {
        fclose(log_file);
        log_file = NULL;
    }
    pthread_mutex_destroy(&log_mutex);
}
