# CMake Template
CMake templates including:
- example_exe
- example_header_only_lib
- example_lib

## Build

To build the static library, run the following commands:

```shell
cmake -S . -B build
cmake --build build
```

> -S 选项后面跟着的是 CMakeLists.txt 所在目录  
> -B 选项后面跟着的是构建目录的路径

To build a shared libary, run the following commands:

```shell
cmake -S . -B build -DBUILD_SHARED_LIBS=ON
cmake --build build
```

## Installing the library

To install the library, run the following command:

```shell
cmake --install build --prefix ./install
```

> --install 选项后面跟着的是构建目录的路径  
> --prefix 选项后面跟着的是安装路径