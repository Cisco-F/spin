#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define TEST_FILE "testfile.bin"
#define TEST_SIZE 4096  // 测试读取4KB数据

int main() {
    // 1. 创建测试文件并写入数据
    int fd = open(TEST_FILE, O_RDWR | O_CREAT, 0644);
    if (fd < 0) {
        perror("open failed");
        return -1;
    }

    // 写入测试数据
    char *write_buf = malloc(TEST_SIZE);
    memset(write_buf, 0xAA, TEST_SIZE);  // 填充测试数据
    if (write(fd, write_buf, TEST_SIZE) != TEST_SIZE) {
        perror("write failed");
        close(fd);
        return -1;
    }
    free(write_buf);

    // 2. 测试pread64
    char *read_buf = malloc(TEST_SIZE);
    ssize_t ret = pread64(fd, read_buf, TEST_SIZE, 0);
    
    if (ret < 0) {
        perror("pread64 failed");
    } else {
        printf("pread64 succeeded, read %zd bytes\n", ret);
        
        // 简单验证数据
        for (int i = 0; i < 16; i++) {
            printf("%02x ", (unsigned char)read_buf[i]);
        }
        printf("...\n");
    }

    // 3. 清理
    free(read_buf);
    close(fd);
    unlink(TEST_FILE);  // 删除测试文件
    
    return 0;
}