#ifndef logger_h
#define logger_h

#if defined(LOGGER)
#define log_print(...) LOGGER.print(__VA_ARGS__)
#define log_println(...) LOGGER.println(__VA_ARGS__)
#define log_printf(...) _logger_printf(__VA_ARGS__)

const size_t _logger_printf(const char *szFormat, ...) {
  va_list argptr;
  va_start(argptr, szFormat);
  char *szBuffer = 0;
  const size_t nBufferLength = vsnprintf(szBuffer, 0, szFormat, argptr) + 1;
  if (nBufferLength == 1) return 0;
  szBuffer = (char *) malloc(nBufferLength);
  if (! szBuffer) return - nBufferLength;
  vsnprintf(szBuffer, nBufferLength, szFormat, argptr);
  log_print(szBuffer);
  free(szBuffer);
  return nBufferLength - 1;
}
#else

#define log_print(...)((void) 0)
#define log_println(...)((void) 0)
#define log_printf(...)((void) 0)

#endif

#endif