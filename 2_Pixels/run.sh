rm -rf ./build
mkdir ./build
cd ./build
cmake ..
make
./addImages
./colorReduce
./contrast
./remapping
./saltImage