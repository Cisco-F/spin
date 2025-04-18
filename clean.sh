cd libspin
rm -f *.so *.o
cd ..

cd spindrv
make clean
cd ..

cd spinnvme
rm -f .*.cmd *.symvers *.order *.ko *.mod.c *.o
rm -rf .tmp_versions
cd ..

echo "cleared!"