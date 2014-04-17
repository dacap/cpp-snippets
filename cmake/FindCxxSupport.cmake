include(CheckCXXSourceCompiles)

if(CMAKE_COMPILER_IS_GNUCXX)
  add_definitions(-std=c++11)
endif()

check_cxx_source_compiles("
  int main() {
    static_assert(sizeof(char) == 1);
  }
  "
  CXX_HAS_STATIC_ASSERT)

check_cxx_source_compiles("
  #include <vector>
  int main() {
    std::vector<int> v;
    auto it = a.begin();
  }
  "
  CXX_HAS_AUTO)

check_cxx_source_compiles("
  #include <vector>
  int main() {
    decltype(2f + 2.3f) var = 10.f;
  }
  "
  CXX_HAS_DECLTYPE)

check_cxx_source_compiles("
  #include <functional>
  int main() {
    std::function<int> f = []() -> int { return 5; };
    int v = f();
  }
  "
  CXX_HAS_LAMBDAS)

check_cxx_source_compiles("
  #include <initializer_list>
  int main() {
    std::initializer_list<int> = { 1, 2, 3 };
  }
  "
  CXX_HAS_INITIALIZER_LISTS)

check_cxx_source_compiles("
  #include <vector>
  int main() {
    std::vector<int> v = { 1, 2, 3 };
  }
  "
  CXX_HAS_INIT_VECTOR_W_INITIALIZER_LISTS)

# <filesystem> in C++ library

check_cxx_source_compiles("
  #include <filesystem>
  int main() { }
  "
  CXX_HAS_FILESYSTEM)

if(CXX_HAS_FILESYSTEM)
  check_cxx_source_compiles("
    #include <filesystem>
    int main() {
      std::files::path p;
    }
    "
    CXX_HAS_STD_FILES_FILESYSTEM)

  check_cxx_source_compiles("
    #include <filesystem>
    int main() {
      std::tr2::files::path path;
    }
    "
    CXX_HAS_TR2_FILES_FILESYSTEM)

  check_cxx_source_compiles("
    #include <filesystem>
    int main() {
      std::tr2::sys::path path;
    }
    "
    CXX_HAS_TR2_SYS_FILESYSTEM)
endif()
