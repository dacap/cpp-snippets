#include <iostream>
#include <memory>

#include <windows.h>
#include <shlobj.h>
#include <shlwapi.h>

template<class T>
class iunknown_ptr {
public:
  iunknown_ptr() : ptr_(nullptr) { }
  iunknown_ptr(T* ptr) : ptr_(ptr) { }

  operator T*() { return ptr_; }
  T* operator->() { return ptr_; }
  T** operator&() { return &ptr_; }

private:
  T* ptr_;
};

class pidl_ptr {
public:
  pidl_ptr(IMalloc* malloc) : pidl_(nullptr), malloc_(malloc) { }
  ~pidl_ptr() {
    if (pidl_)
      malloc_->Free(pidl_);
  }

  operator LPITEMIDLIST() { return pidl_; }
  LPITEMIDLIST* operator&() { return &pidl_; }

private:
  LPITEMIDLIST pidl_;
  IMalloc* malloc_;
};

void test() {
  iunknown_ptr<IMalloc> malloc;
  HRESULT hr = SHGetMalloc(&malloc);
  if (hr != S_OK)
    throw std::runtime_error("SHGetMalloc failed");

  iunknown_ptr<IShellFolder> desktop;
  hr = SHGetDesktopFolder(&desktop);
  if (hr != S_OK)
    throw std::runtime_error("SHGetMalloc failed");

  pidl_ptr pidl(malloc);
  hr = SHGetSpecialFolderLocation(nullptr, CSIDL_DESKTOP, &pidl);
  if (hr != S_OK)
    throw std::runtime_error("SHGetSpecialFolderLocation failed");

  STRRET strret;
  hr = desktop->GetDisplayNameOf(pidl, SHGDN_FORPARSING, &strret);
  if (hr != S_OK)
    throw std::runtime_error("IShellFolder::GetDisplayNameOf failed");

  WCHAR name[MAX_PATH];
  StrRetToBuf(&strret, pidl, name, MAX_PATH);
  std::wcout << name << L"\n";
}

int main() {
  try {
    test();
  }
  catch (const std::exception& e) {
    std::cerr << "Exception: " << e.what() << "\n";
    return 1;
  }
}

