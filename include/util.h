#ifndef MPS_UTIL_H_
#define MPS_UTIL_H_

/**
 * The fallthrough attribute with a null statement serves as a fallthrough
 * statement. It hints to the compiler that a statement that falls through
 * to another case label, or user-defined label in a switch statement is
 * intentional and thus the -Wimplicit-fallthrough warning must not trigger.
 * The fallthrough attribute may appear at most once in each attribute list,
 * and may not be mixed with other attributes. It can only be used in a switch
 * statement (the compiler will issue an error otherwise), after a preceding
 * statement and before a logically succeeding case label, or user-defined
 * label.
 */
#if __has_attribute(fallthrough) || (defined(__GNUC__) && __GNUC__ >= 7)
#  define FALLTHROUGH __attribute__((fallthrough))
#else
#  define FALLTHROUGH
#endif

#ifndef __printf
#  ifdef __GNUC__
#    define __printf(n,m) __attribute__((format(printf,n,m)))
#  else
#    define __printf(n,m)
#  endif
#endif

#endif /* MPS_UTIL_H_ */
