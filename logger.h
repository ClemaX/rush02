#ifndef LOGGER_H
# define LOGGER_H

# ifndef DEBUG
#  define error(...) (void)1;
#  define debug(...) (void)1;
# else
#  define error(...) fprintf(stderr, __VA_ARGS__)
#  define debug(...) fprintf(stderr, __VA_ARGS__)
# endif

#endif
