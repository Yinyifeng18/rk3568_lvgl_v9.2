set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

set(tools "/opt/atk-dlrk356x-toolchain/usr")
set(CMAKE_C_COMPILER ${tools}/bin/aarch64-buildroot-linux-gnu-gcc)
set(CMAKE_CXX_COMPILER ${tools}/bin/aarch64-buildroot-linux-gnu-g++)
