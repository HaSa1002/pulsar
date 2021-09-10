#pragma once

#include "../common.hpp"
#include "../string/string.hpp"

// Adapted freely from Godot

#define FUNCTION_STR __FUNCTION__


/**
 * Don't use GENERATE_TRAP() directly, should only be used be the macros below.
 */
#ifdef _MSC_VER
#define GENERATE_TRAP() __debugbreak()
#else
#define GENERATE_TRAP() __builtin_trap()
#endif

// Used to strip debug messages in release mode
#ifdef DEBUG_ENABLED
#define DEBUG_STR(m_msg) m_msg
#else
#define DEBUG_STR(m_msg) ""
#endif

void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error);
void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error);
void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error, const char *p_message);
void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error, const char *p_message);
void _err_print_error(const char *p_function, const char *p_file, int p_line, const char *p_error, const String &p_message);
void _err_print_error(const char *p_function, const char *p_file, int p_line, const String &p_error, const String &p_message);
void _err_print_index_error(const char *p_function, const char *p_file, int p_line, int64_t p_index, int64_t p_size, const char *p_index_str, const char *p_size_str, const char *p_message = "", bool fatal = false);
void _err_print_index_error(const char *p_function, const char *p_file, int p_line, int64_t p_index, int64_t p_size, const char *p_index_str, const char *p_size_str, const String &p_message, bool fatal = false);

/**
 * Try using `ERR_FAIL_INDEX_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures an integer index `m_index` is less than `m_size` and greater than or equal to 0.
 * If not, the current function returns.
 */
#define AERR_FAIL_INDEX(m_index, m_size)                                                                         \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                     \
		_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size)); \
		return;                                                                                                 \
	} else                                                                                                      \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_INDEX(m_index, m_size) AERR_FAIL_INDEX(m_index, m_size)
#else
#define ERR_FAIL_INDEX(m_index, m_size) ((void)0)
#endif

/**
 * Ensures an integer index `m_index` is less than `m_size` and greater than or equal to 0.
 * If not, prints `m_msg` and the current function returns.
 */
#define AERR_FAIL_INDEX_MSG(m_index, m_size, m_msg)                                                                                \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                                       \
		_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), DEBUG_STR(m_msg)); \
		return;                                                                                                                   \
	} else                                                                                                                        \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_INDEX_MSG(m_index, m_size, m_msg) AERR_FAIL_INDEX_MSG(m_index, m_size, m_msg)   
#else
#define ERR_FAIL_INDEX_MSG(m_index, m_size, m_msg) ((void)0)
#endif

/**
 * Try using `ERR_FAIL_INDEX_V_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures an integer index `m_index` is less than `m_size` and greater than or equal to 0.
 * If not, the current function returns `m_retval`.
 */
#define AERR_FAIL_INDEX_V(m_index, m_size, m_retval)                                                             \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                     \
		_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size)); \
		return m_retval;                                                                                        \
	} else                                                                                                      \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_INDEX_V(m_index, m_size, m_retval) AERR_FAIL_INDEX_V(m_index, m_size, m_retval)   
#else
#define ERR_FAIL_INDEX_V(m_index, m_size, m_retval) ((void)0)
#endif

/**
 * Ensures an integer index `m_index` is less than `m_size` and greater than or equal to 0.
 * If not, prints `m_msg` and the current function returns `m_retval`.
 */
#define AERR_FAIL_INDEX_V_MSG(m_index, m_size, m_retval, m_msg)                                                                    \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                                       \
		_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), DEBUG_STR(m_msg)); \
		return m_retval;                                                                                                          \
	} else                                                                                                                        \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_INDEX_V_MSG(m_index, m_size, m_retval, m_msg) AERR_FAIL_INDEX_V_MSG(m_index, m_size, m_retval, m_msg)   
#else
#define ERR_FAIL_INDEX_V_MSG(m_index, m_size, m_retval, m_msg) ((void)0)
#endif

/**
 * Try using `ERR_FAIL_INDEX_MSG` or `ERR_FAIL_INDEX_V_MSG`.
 * Only use this macro if there is no sensible fallback i.e. the error is unrecoverable, and
 * there is no sensible error message.
 *
 * Ensures an integer index `m_index` is less than `m_size` and greater than or equal to 0.
 * If not, the application crashes.
 */
#define ACRASH_BAD_INDEX(m_index, m_size)                                                                                  \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                               \
		_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), "", true); \
		GENERATE_TRAP();                                                                                                  \
	} else                                                                                                                \
		((void)0)

#ifdef DEBUG_ENABLED
#define CRASH_BAD_INDEX(m_index, m_size) ACRASH_BAD_INDEX(m_index, m_size)   
#else
#define CRASH_BAD_INDEX(m_index, m_size) ((void)0)
#endif

/**
 * Try using `ERR_FAIL_INDEX_MSG` or `ERR_FAIL_INDEX_V_MSG`.
 * Only use this macro if there is no sensible fallback i.e. the error is unrecoverable.
 *
 * Ensures an integer index `m_index` is less than `m_size` and greater than or equal to 0.
 * If not, prints `m_msg` and the application crashes.
 */
#define ACRASH_BAD_INDEX_MSG(m_index, m_size, m_msg)                                                                                     \
	if (unlikely((m_index) < 0 || (m_index) >= (m_size))) {                                                                             \
		_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), DEBUG_STR(m_msg), true); \
		GENERATE_TRAP();                                                                                                                \
	} else                                                                                                                              \
		((void)0)

#ifdef DEBUG_ENABLED
#define CRASH_BAD_INDEX_MSG(m_index, m_size, m_msg) ACRASH_BAD_INDEX_MSG(m_index, m_size, m_msg)
#else
#define CRASH_BAD_INDEX_MSG(m_index, m_size, m_msg) ((void)0)
#endif

// Unsigned integer index out of bounds error macros.

/**
 * Try using `ERR_FAIL_UNSIGNED_INDEX_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures an unsigned integer index `m_index` is less than `m_size`.
 * If not, the current function returns.
 */
#define AERR_FAIL_UNSIGNED_INDEX(m_index, m_size)                                                                \
	if (unlikely((m_index) >= (m_size))) {                                                                      \
		_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size)); \
		return;                                                                                                 \
	} else                                                                                                      \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_UNSIGNED_INDEX(m_index, m_size) AERR_FAIL_UNSIGNED_INDEX(m_index, m_size)
#else
#define ERR_FAIL_UNSIGNED_INDEX(m_index, m_size) ((void)0)
#endif

/**
 * Ensures an unsigned integer index `m_index` is less than `m_size`.
 * If not, prints `m_msg` and the current function returns.
 */
#define AERR_FAIL_UNSIGNED_INDEX_MSG(m_index, m_size, m_msg)                                                                       \
	if (unlikely((m_index) >= (m_size))) {                                                                                        \
		_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), DEBUG_STR(m_msg)); \
		return;                                                                                                                   \
	} else                                                                                                                        \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_UNSIGNED_INDEX_MSG(m_index, m_size, m_msg) AERR_FAIL_UNSIGNED_INDEX_MSG(m_index, m_size, m_msg)
#else
#define ERR_FAIL_UNSIGNED_INDEX_MSG(m_index, m_size, m_msg) ((void)0)
#endif

/**
 * Try using `ERR_FAIL_UNSIGNED_INDEX_V_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures an unsigned integer index `m_index` is less than `m_size`.
 * If not, the current function returns `m_retval`.
 */
#define AERR_FAIL_UNSIGNED_INDEX_V(m_index, m_size, m_retval)                                                    \
	if (unlikely((m_index) >= (m_size))) {                                                                      \
		_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size)); \
		return m_retval;                                                                                        \
	} else                                                                                                      \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_UNSIGNED_INDEX_V(m_index, m_size, m_retval) AERR_FAIL_UNSIGNED_INDEX_V(m_index, m_size, m_retval)
#else
#define ERR_FAIL_UNSIGNED_INDEX_V(m_index, m_size, m_retval) ((void)0)
#endif

/**
 * Ensures an unsigned integer index `m_index` is less than `m_size`.
 * If not, prints `m_msg` and the current function returns `m_retval`.
 */
#define AERR_FAIL_UNSIGNED_INDEX_V_MSG(m_index, m_size, m_retval, m_msg)                                                           \
	if (unlikely((m_index) >= (m_size))) {                                                                                        \
		_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), DEBUG_STR(m_msg)); \
		return m_retval;                                                                                                          \
	} else                                                                                                                        \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_UNSIGNED_INDEX_V_MSG(m_index, m_size, m_retval, m_msg) AERR_FAIL_UNSIGNED_INDEX_V_MSG(m_index, m_size, m_retval, m_msg)
#else
#define ERR_FAIL_UNSIGNED_INDEX_V_MSG(m_index, m_size, m_retval, m_msg) ((void)0)
#endif

/**
 * Try using `ERR_FAIL_UNSIGNED_INDEX_MSG` or `ERR_FAIL_UNSIGNED_INDEX_V_MSG`.
 * Only use this macro if there is no sensible fallback i.e. the error is unrecoverable, and
 * there is no sensible error message.
 *
 * Ensures an unsigned integer index `m_index` is less than `m_size`.
 * If not, the application crashes.
 */
#define ACRASH_BAD_UNSIGNED_INDEX(m_index, m_size)                                                                         \
	if (unlikely((m_index) >= (m_size))) {                                                                                \
		_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), "", true); \
		GENERATE_TRAP();                                                                                                  \
	} else                                                                                                                \
		((void)0)

#ifdef DEBUG_ENABLED
#define CRASH_BAD_UNSIGNED_INDEX(m_index, m_size) ACRASH_BAD_UNSIGNED_INDEX(m_index, m_size)
#else
#define CRASH_BAD_UNSIGNED_INDEX(m_index, m_size) ((void)0)
#endif

/**
 * Try using `ERR_FAIL_UNSIGNED_INDEX_MSG` or `ERR_FAIL_UNSIGNED_INDEX_V_MSG`.
 * Only use this macro if there is no sensible fallback i.e. the error is unrecoverable.
 *
 * Ensures an unsigned integer index `m_index` is less than `m_size`.
 * If not, prints `m_msg` and the application crashes.
 */
#define ACRASH_BAD_UNSIGNED_INDEX_MSG(m_index, m_size, m_msg)                                                                            \
	if (unlikely((m_index) >= (m_size))) {                                                                                              \
		_err_print_index_error(FUNCTION_STR, __FILE__, __LINE__, m_index, m_size, _STR(m_index), _STR(m_size), DEBUG_STR(m_msg), true); \
		GENERATE_TRAP();                                                                                                                \
	} else                                                                                                                              \
		((void)0)

#ifdef DEBUG_ENABLED
#define CRASH_BAD_UNSIGNED_INDEX_MSG(m_index, m_size, m_msg) ACRASH_BAD_UNSIGNED_INDEX_MSG(m_index, m_size, m_msg)
#else
#define CRASH_BAD_UNSIGNED_INDEX_MSG(m_index, m_size, m_msg) ((void)0)
#endif

// Null reference error macros.

/**
 * Try using `ERR_FAIL_NULL_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures a pointer `m_param` is not null.
 * If it is null, the current function returns.
 */
#define AERR_FAIL_NULL(m_param)                                                                          \
	if (unlikely(m_param == nullptr)) {                                                                 \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null."); \
		return;                                                                                         \
	} else                                                                                              \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_NULL(m_param) AERR_FAIL_NULL(m_param)
#else
#define ERR_FAIL_NULL(m_param) ((void)0)
#endif

/**
 * Ensures a pointer `m_param` is not null.
 * If it is null, prints `m_msg` and the current function returns.
 */
#define AERR_FAIL_NULL_MSG(m_param, m_msg)                                                                                 \
	if (unlikely(m_param == nullptr)) {                                                                                   \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null.", DEBUG_STR(m_msg)); \
		return;                                                                                                           \
	} else                                                                                                                \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_NULL_MSG(m_param, m_msg) AERR_FAIL_NULL_MSG(m_param, m_msg)
#else
#define ERR_FAIL_NULL_MSG(m_param, m_msg) ((void)0)
#endif

/**
 * Try using `ERR_FAIL_NULL_V_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures a pointer `m_param` is not null.
 * If it is null, the current function returns `m_retval`.
 */
#define AERR_FAIL_NULL_V(m_param, m_retval)                                                              \
	if (unlikely(m_param == nullptr)) {                                                                 \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null."); \
		return m_retval;                                                                                \
	} else                                                                                              \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_NULL_V(m_param, m_retval) AERR_FAIL_NULL_V(m_param, m_retval)
#else
#define ERR_FAIL_NULL_V(m_param, m_retval) ((void)0)
#endif

/**
 * Ensures a pointer `m_param` is not null.
 * If it is null, prints `m_msg` and the current function returns `m_retval`.
 */
#define AERR_FAIL_NULL_V_MSG(m_param, m_retval, m_msg)                                                                     \
	if (unlikely(m_param == nullptr)) {                                                                                   \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Parameter \"" _STR(m_param) "\" is null.", DEBUG_STR(m_msg)); \
		return m_retval;                                                                                                  \
	} else                                                                                                                \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_NULL_V_MSG(m_param, m_retval, m_msg) AERR_FAIL_NULL_V_MSG(m_param, m_retval, m_msg)
#else
#define ERR_FAIL_NULL_V_MSG(m_param, m_retval, m_msg) ((void)0)
#endif

/**
 * Try using `ERR_FAIL_COND_MSG`.
 * Only use this macro if there is no sensible error message.
 * If checking for null use ERR_FAIL_NULL_MSG instead.
 * If checking index bounds use ERR_FAIL_INDEX_MSG instead.
 *
 * Ensures `m_cond` is false.
 * If `m_cond` is true, the current function returns.
 */
#define AERR_FAIL_COND(m_cond)                                                                          \
	if (unlikely(m_cond)) {                                                                            \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true."); \
		return;                                                                                        \
	} else                                                                                             \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_COND(m_cond) AERR_FAIL_COND(m_cond)
#else
#define ERR_FAIL_COND(m_cond) ((void)0)
#endif

/**
 * Ensures `m_cond` is false.
 * If `m_cond` is true, prints `m_msg` and the current function returns.
 *
 * If checking for null use ERR_FAIL_NULL_MSG instead.
 * If checking index bounds use ERR_FAIL_INDEX_MSG instead.
 */
#define AERR_FAIL_COND_MSG(m_cond, m_msg)                                                                                 \
	if (unlikely(m_cond)) {                                                                                              \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true.", DEBUG_STR(m_msg)); \
		return;                                                                                                          \
	} else                                                                                                               \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_COND_MSG(m_cond, m_msg) AERR_FAIL_COND_MSG(m_cond, m_msg)
#else
#define ERR_FAIL_COND_MSG(m_cond, m_msg) ((void)0)
#endif

/**
 * Try using `ERR_FAIL_COND_V_MSG`.
 * Only use this macro if there is no sensible error message.
 * If checking for null use ERR_FAIL_NULL_V_MSG instead.
 * If checking index bounds use ERR_FAIL_INDEX_V_MSG instead.
 *
 * Ensures `m_cond` is false.
 * If `m_cond` is true, the current function returns `m_retval`.
 */
#define AERR_FAIL_COND_V(m_cond, m_retval)                                                                                         \
	if (unlikely(m_cond)) {                                                                                                       \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Returning: " _STR(m_retval)); \
		return m_retval;                                                                                                          \
	} else                                                                                                                        \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_COND_V(m_cond, m_retval) AERR_FAIL_COND_V(m_cond, m_retval)
#else
#define ERR_FAIL_COND_V(m_cond, m_retval) ((void)0)
#endif

/**
 * Ensures `m_cond` is false.
 * If `m_cond` is true, prints `m_msg` and the current function returns `m_retval`.
 *
 * If checking for null use ERR_FAIL_NULL_V_MSG instead.
 * If checking index bounds use ERR_FAIL_INDEX_V_MSG instead.
 */
#define AERR_FAIL_COND_V_MSG(m_cond, m_retval, m_msg)                                                                                                \
	if (unlikely(m_cond)) {                                                                                                                         \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Returning: " _STR(m_retval), DEBUG_STR(m_msg)); \
		return m_retval;                                                                                                                            \
	} else                                                                                                                                          \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_FAIL_COND_V_MSG(m_cond, m_retval, m_msg) AERR_FAIL_COND_V_MSG(m_cond, m_retval, m_msg)
#else
#define ERR_FAIL_COND_V_MSG(m_cond, m_retval, m_msg) ((void)0)
#endif

/**
 * Try using `ERR_CONTINUE_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures `m_cond` is false.
 * If `m_cond` is true, the current loop continues.
 */
#define AERR_CONTINUE(m_cond)                                                                                       \
	if (unlikely(m_cond)) {                                                                                        \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Continuing."); \
		continue;                                                                                                  \
	} else                                                                                                         \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_CONTINUE(m_cond) AERR_CONTINUE(m_cond)
#else
#define ERR_CONTINUE(m_cond) ((void)0)
#endif

/**
 * Ensures `m_cond` is false.
 * If `m_cond` is true, prints `m_msg` and the current loop continues.
 */
#define AERR_CONTINUE_MSG(m_cond, m_msg)                                                                                              \
	if (unlikely(m_cond)) {                                                                                                          \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Continuing.", DEBUG_STR(m_msg)); \
		continue;                                                                                                                    \
	} else                                                                                                                           \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_CONTINUE_MSG(m_cond, m_msg) AERR_CONTINUE_MSG(m_cond, m_msg)
#else
#define ERR_CONTINUE_MSG(m_cond, m_msg) ((void)0)
#endif

/**
 * Try using `ERR_BREAK_MSG`.
 * Only use this macro if there is no sensible error message.
 *
 * Ensures `m_cond` is false.
 * If `m_cond` is true, the current loop breaks.
 */
#define AERR_BREAK(m_cond)                                                                                        \
	if (unlikely(m_cond)) {                                                                                      \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Breaking."); \
		break;                                                                                                   \
	} else                                                                                                       \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_BREAK(m_cond) AERR_BREAK(m_cond)
#else
#define ERR_BREAK(m_cond) ((void)0)
#endif

/**
 * Ensures `m_cond` is false.
 * If `m_cond` is true, prints `m_msg` and the current loop breaks.
 */
#define AERR_BREAK_MSG(m_cond, m_msg)                                                                                               \
	if (unlikely(m_cond)) {                                                                                                        \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Condition \"" _STR(m_cond) "\" is true. Breaking.", DEBUG_STR(m_msg)); \
		break;                                                                                                                     \
	} else                                                                                                                         \
		((void)0)

#ifdef DEBUG_ENABLED
#define ERR_BREAK_MSG(m_cond, m_msg) AERR_BREAK_MSG(m_cond, m_msg)
#else
#define ERR_BREAK_MSG(m_cond, m_msg) ((void)0)
#endif

/**
 * Try using `ERR_FAIL_COND_MSG` or `ERR_FAIL_COND_V_MSG`.
 * Only use this macro if there is no sensible fallback i.e. the error is unrecoverable, and
 * there is no sensible error message.
 *
 * Ensures `m_cond` is false.
 * If `m_cond` is true, the application crashes.
 */
#define ACRASH_COND(m_cond)                                                                                    \
	if (unlikely(m_cond)) {                                                                                   \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: Condition \"" _STR(m_cond) "\" is true."); \
		GENERATE_TRAP();                                                                                      \
	} else                                                                                                    \
		((void)0)

#ifdef DEBUG_ENABLED
#define CRASH_COND(m_cond) ACRASH_COND(m_cond)
#else
#define CRASH_COND(m_cond) ((void)0)
#endif

/**
 * Try using `ERR_FAIL_COND_MSG` or `ERR_FAIL_COND_V_MSG`.
 * Only use this macro if there is no sensible fallback i.e. the error is unrecoverable.
 *
 * Ensures `m_cond` is false.
 * If `m_cond` is true, prints `m_msg` and the application crashes.
 */
#define ACRASH_COND_MSG(m_cond, m_msg)                                                                                           \
	if (unlikely(m_cond)) {                                                                                                     \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: Condition \"" _STR(m_cond) "\" is true.", DEBUG_STR(m_msg)); \
		GENERATE_TRAP();                                                                                                        \
	} else                                                                                                                      \
		((void)0)

#ifdef DEBUG_ENABLED
#define CRASH_COND_MSG(m_cond, m_msg) ACRASH_COND_MSG(m_cond, m_msg)
#else
#define CRASH_COND_MSG(m_cond, m_msg) ((void)0)
#endif

// Generic error macros.

/**
 * Try using `ERR_FAIL_COND_MSG` or `ERR_FAIL_MSG`.
 * Only use this macro if more complex error detection or recovery is required, and
 * there is no sensible error message.
 *
 * The current function returns.
 */
#define ERR_FAIL()                                                                     \
	if (true) {                                                                        \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed."); \
		return;                                                                        \
	} else                                                                             \
		((void)0)

/**
 * Try using `ERR_FAIL_COND_MSG`.
 * Only use this macro if more complex error detection or recovery is required.
 *
 * Prints `m_msg`, and the current function returns.
 */
#define ERR_FAIL_MSG(m_msg)                                                                              \
	if (true) {                                                                                          \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed.", DEBUG_STR(m_msg)); \
		return;                                                                                          \
	} else                                                                                               \
		((void)0)

/**
 * Try using `ERR_FAIL_COND_V_MSG` or `ERR_FAIL_V_MSG`.
 * Only use this macro if more complex error detection or recovery is required, and
 * there is no sensible error message.
 *
 * The current function returns `m_retval`.
 */
#define ERR_FAIL_V(m_retval)                                                                                      \
	if (true) {                                                                                                   \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed. Returning: " _STR(m_retval)); \
		return m_retval;                                                                                          \
	} else                                                                                                        \
		((void)0)

/**
 * Try using `ERR_FAIL_COND_V_MSG`.
 * Only use this macro if more complex error detection or recovery is required.
 *
 * Prints `m_msg`, and the current function returns `m_retval`.
 */
#define ERR_FAIL_V_MSG(m_retval, m_msg)                                                                                             \
	if (true) {                                                                                                                     \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "Method/function failed. Returning: " _STR(m_retval), DEBUG_STR(m_msg)); \
		return m_retval;                                                                                                            \
	} else                                                                                                                          \
		((void)0)

/**
 * Try using `ERR_FAIL_COND_MSG`, `ERR_FAIL_COND_V_MSG`, `ERR_CONTINUE_MSG` or ERR_BREAK_MSG.
 * Only use this macro at the start of a function that has not been implemented yet, or
 * if more complex error detection or recovery is required.
 *
 * Prints `m_msg`.
 */
#define ERR_PRINT(m_msg) \
	_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg)

/**
 * Prints `m_msg` once during the application lifetime.
 */
#define ERR_PRINT_ONCE(m_msg)                                          \
	if (true) {                                                        \
		static bool first_print = true;                                \
		if (first_print) {                                             \
			_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg); \
			first_print = false;                                       \
		}                                                              \
	} else                                                             \
		((void)0)

// Print warning message macros.

/**
 * Prints `m_msg`.
 *
 * If warning about deprecated usage, use `WARN_DEPRECATED` or `WARN_DEPRECATED_MSG` instead.
 */
#define WARN_PRINT(m_msg) \
	_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg)

/**
 * Prints `m_msg` once during the application lifetime.
 *
 * If warning about deprecated usage, use `WARN_DEPRECATED` or `WARN_DEPRECATED_MSG` instead.
 */
#define WARN_PRINT_ONCE(m_msg)                                                              \
	if (true) {                                                                             \
		static bool first_print = true;                                                     \
		if (first_print) {                                                                  \
			_err_print_error(FUNCTION_STR, __FILE__, __LINE__, m_msg); \
			first_print = false;                                                            \
		}                                                                                   \
	} else                                                                                  \
		((void)0)

// Print deprecated warning message macros.

/**
 * Warns that the current function is deprecated.
 */
#define WARN_DEPRECATED                                                                                                                                    \
	if (true) {                                                                                                                                            \
		static bool warning_shown = false;                                                                                                                     \
		if (!warning_shown) {                                                                                                                     \
			_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "This method has been deprecated and will be removed in the future."); \
			warning_shown = true;                                                                                                                           \
		}                                                                                                                                                  \
	} else                                                                                                                                                 \
		((void)0)

/**
 * Warns that the current function is deprecated and prints `m_msg`.
 */
#define WARN_DEPRECATED_MSG(m_msg)                                                                                                                                           \
	if (true) {                                                                                                                                                              \
		static bool warning_shown = false;                                                                                                                                       \
		if (!warning_shown) {                                                                                                                                       \
			_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "This method has been deprecated and will be removed in the future.", DEBUG_STR(m_msg)); \
			warning_shown = true;                                                                                                                                             \
		}                                                                                                                                                                    \
	} else                                                                                                                                                                   \
		((void)0)

/**
 * Do not use.
 * If the application should never reach this point use CRASH_NOW_MSG(m_msg) to explain why.
 *
 * The application crashes.
 */
#define CRASH_NOW()                                                                           \
	if (true) {                                                                               \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: Method/function failed."); \
		GENERATE_TRAP();                                                                      \
	} else                                                                                    \
		((void)0)

/**
 * Only use if the application should never reach this point.
 *
 * Prints `m_msg`, and then the application crashes.
 */
#define CRASH_NOW_MSG(m_msg)                                                                                    \
	if (true) {                                                                                                 \
		_err_print_error(FUNCTION_STR, __FILE__, __LINE__, "FATAL: Method/function failed.", DEBUG_STR(m_msg)); \
		GENERATE_TRAP();                                                                                        \
	} else                                                                                                      \
		((void)0)
