// Author: David Seifert, Derek Barnett

// Reduce the number of exposed symbols in order to speed up
// DSO load times
// https://gcc.gnu.org/wiki/Visibility

#ifndef PBCOPPER_PBCOPPERCONFIG_H
#define PBCOPPER_PBCOPPERCONFIG_H

// clang-format off
#if defined _WIN32 || defined __CYGWIN__
#  ifdef PBCOPPER_BUILDING_LIBRARY
#    ifdef __GNUC__
#      define PBCOPPER_PUBLIC_API __attribute__((dllexport))
#    else
#      define PBCOPPER_PUBLIC_API __declspec(dllexport)  // Note: gcc seems to also supports this syntax
#    endif
#  else
#    ifdef __GNUC__
#      define PBCOPPER_PUBLIC_API __attribute__((dllimport))
#    else
#      define PBCOPPER_PUBLIC_API __declspec(dllimport)  // Note: gcc seems to also supports this syntax
#    endif
#  endif
#  define PBCOPPER_PRIVATE_API
#else
#  if __GNUC__ >= 4
#    define PBCOPPER_PUBLIC_API __attribute__((visibility("default")))
#    define PBCOPPER_PRIVATE_API __attribute__((visibility("hidden")))
#  else
#    define PBCOPPER_PUBLIC_API
#    define PBCOPPER_PRIVATE_API
#  endif
#endif
// clang-format on

/// Disable use of getrandom(), which requires Linux kernel 3.17+.
/// This define allows use of getentropy() in glibc 2.25+, otherwise
/// fallback to 'posix' provider
#ifndef BOOST_UUID_RANDOM_PROVIDER_DISABLE_GETRANDOM
#define BOOST_UUID_RANDOM_PROVIDER_DISABLE_GETRANDOM
#endif

#endif  // PBCOPPER_PBCOPPERCONFIG_H
