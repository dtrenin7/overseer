pkill -f overseer
rm -rf build
mkdir build
cd build
cmake ../ -DCMAKE_BUILD_TYPE=Release
make
cd ..
