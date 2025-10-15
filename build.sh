#rm -rf build
mkdir -p build
cd build/
cmake -DCMAKE_TOOLCHAIN_FILE="../toolchain.cmake" ..
make -j32
wait
cd ../ 
cp bin/main bin/lv_test_demo
echo "get app bin/lv_test_demo"
