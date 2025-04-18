cd spindrv
make
make install
cd ..

cd spinnvme
make
insmod nvme.ko
cd ..

cd libspin
make

echo "build and install finished!"