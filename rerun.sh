echo "--------before dmesg -C--------"
dmesg -c | tail -20
echo "running app with LD_PRELOAD..."
LD_PRELOAD=libspin/libspin.so ./test
echo "--------app finished, now printing dmesg--------"
dmesg