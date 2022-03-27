#ifndef _LOGGER_H_
#define _LOGGER_H_

#define PRINT_DEBUG_LOG 1
#if PRINT_DEBUG_LOG == 1
#define dbg_log(x) std::cout << x << std::endl;
#else
#define dbg_log(x)
#endif


#endif