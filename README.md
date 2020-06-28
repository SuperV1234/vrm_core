# vrm_core

> **General-purpose C++17 utility library.**

[![build][badge.build]][build]
[![stability][badge.stability]][stability]
[![license][badge.license]][license]
[![gratipay][badge.gratipay]][gratipay]
![badge.cpp](https://img.shields.io/badge/c++-14-ff69b4.svg?style=flat-square)
[![on-wandbox][badge.on-wandbox]][on-wandbox]
[![on-godbolt][badge.on-godbolt]][on-godbolt]

[badge.build]: https://img.shields.io/travis/SuperV1234/vrm_core.svg?style=flat-square
[badge.stability]: https://img.shields.io/badge/stability-unstable-yellow.svg?style=flat-square
[badge.license]: http://img.shields.io/badge/license-afl%203.0-blue.svg?style=flat-square
[badge.gratipay]: https://img.shields.io/gratipay/user/SuperV1234.svg?style=flat-square
[badge.on-wandbox]: https://img.shields.io/badge/on-wandbox-376666.svg?style=flat-square
[badge.on-godbolt]: https://img.shields.io/badge/on-godbolt-376666.svg?style=flat-square

[build]: https://travis-ci.org/SuperV1234/vrm_core
[stability]: http://github.com/badges/stability-badges
[license]: https://github.com/SuperV1234/vrm_core/blob/master/LICENSE
[gratipay]: https://gratipay.com/~SuperV1234/
[on-wandbox]: https://wandbox.org/permlink/DfXLlf7bHm2rDfFj
[on-godbolt]: https://godbolt.org/g/9t8gN5



## Intended usage (quick start)

1. Add this repository, [SuperV1234/vrm_cmake](https://github.com/SuperV1234/vrm_cmake) and [SuperV1234/vrm_pp](https://github.com/SuperV1234/vrm_pp) as submodules of your project, as subfolders in `your_project/extlibs/`:

    ```bash
    git submodule add   https://github.com/SuperV1234/vrm_cmake.git   your_project/extlibs/vrm_cmake
    git submodule add   https://github.com/SuperV1234/vrm_pp.git      your_project/extlibs/vrm_pp
    git submodule add   https://github.com/SuperV1234/vrm_core.git    your_project/extlibs/vrm_core
    ```

2. Include `vrm_cmake` in your project's `CMakeLists.txt` and look for the `vrm_pp` and `vrm_core` extlibs:

    ```cmake
    # Include `vrm_cmake`:
    list(APPEND CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/extlibs/vrm_cmake/cmake/")
    include(vrm_cmake)

    # Find `vrm_pp` and `vrm_core`:
    vrm_cmake_find_extlib(vrm_pp)
    vrm_cmake_find_extlib(vrm_core)
    ```

*(Altenatively, only add `vrm_core` and `vrm_cmake` as submodules, and recursively pull submodules to let `vrm_core` find `vrm_pp`.)*
