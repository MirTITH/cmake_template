# example_header_only_lib
A template repository to showcase how to properly set up a library with CMake

## Building with CMake

To build the library, run the following commands:

```bash
cmake -S . -B build
cmake --build build
```

> -S 选项后面跟着的是 CMakeLists.txt 所在目录  
> -B 选项后面跟着的是构建目录的路径

### Installing the library

To install the library, run the following command:

```bash
cmake --install build --prefix ./install
```

> --install 选项后面跟着的是构建目录的路径  
> --prefix 选项后面跟着的是安装路径