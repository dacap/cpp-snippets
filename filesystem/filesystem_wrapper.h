#ifndef FILESYSTEM_WRAPPER_H_INCLUDED
#define FILESYSTEM_WRAPPER_H_INCLUDED
#pragma once

#include "cxx_config.h"

#ifdef CXX_HAS_FILESYSTEM
  #include <filesystem>
#else
  #error <filesystem> is not available
#endif

#if defined CXX_HAS_STD_FILES_FILESYSTEM
  using namespace std::files;
#elif defined CXX_HAS_TR2_FILES_FILESYSTEM
  using namespace std::tr2::files;
#elif defined CXX_HAS_TR2_SYS_FILESYSTEM
  using namespace std::tr2::sys;
#else
  #error Unknown namespace for <filesystem>
#endif

#endif // FILESYSTEM_WRAPPER_H_INCLUDED
