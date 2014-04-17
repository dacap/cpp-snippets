#ifndef SCOPED_VALUE_H_INCLUDED
#define SCOPED_VALUE_H_INCLUDED
#pragma once

template<typename T>
class scoped_value {
public:
  scoped_value(T& obj, const T& init_value, const T& exit_value) :
    obj_(obj), exit_value_(exit_value) {
    obj_ = init_value;
  }

  ~scoped_value() {
    obj_ = exit_value_;
  }

private:
  T& obj_;
  T exit_value_;
};

#endif // SCOPED_VALUE_H_INCLUDED
