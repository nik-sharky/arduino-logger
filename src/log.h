#ifndef log_h
#define log_h

#if defined(LOG)
#define log_print(...) LOG.print(__VA_ARGS__)
#define log_println(...) LOG.println(__VA_ARGS__)
#define log_printf(...) _log_printf(__VA_ARGS__)

const size_t _log_printf(const char *format, ...) {
    va_list arg;
    va_start(arg, format);
    char temp[64];
    char* buffer = temp;
    size_t len = vsnprintf(temp, sizeof(temp), format, arg);
    va_end(arg);
    if (len > sizeof(temp) - 1) {
        buffer = (char *) malloc(len+1);
        //buffer = new char[len + 1];
        if (!buffer) {
            return 0;
        }
        va_start(arg, format);
        vsnprintf(buffer, len + 1, format, arg);
        va_end(arg);
    }
    //len = write((const uint8_t*) buffer, len);
    log_print(buffer);
    if (buffer != temp) {
        free(buffer);
        //delete[] buffer;
    }
    return len;
}

#else

#define log_print(...)((void) 0)
#define log_println(...)((void) 0)
#define log_printf(...)((void) 0)

#endif

#endif