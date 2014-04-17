#ifndef SCOPED_TRACE_H_INCLUDED
#define SCOPED_TRACE_H_INCLUDED
#pragma once

#define SCOPED_TRACE(funcname) scoped_trace _trace(#funcname)

class scoped_trace {
public:
  scoped_trace(const char* funcname) : funcname_(funcname) {
    std::cout << funcname_ << " {\n";
  }

  ~scoped_trace() {
    std::cout << "} // " << funcname_ << "\n";
  }

private:
  const char* funcname_;
};

#endif // SCOPED_TRACE_H_INCLUDED
