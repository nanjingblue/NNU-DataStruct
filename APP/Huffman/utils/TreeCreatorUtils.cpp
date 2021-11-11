#include "TreeCreatorUtils.h"

namespace utils {
    void getWeight(char fileName[], int *weight) {
        std::cout << "hahhahhhh哈哈哈哈哈哈" << std::endl;
        char filename[] = "../images/xst.png";
        FILE *in = fopen(filename, "rb");
        if (!in) {
            printf("打开文件失败");
            exit(1);
        }
        char ch;
        while((ch=getc(in))!=EOF){
            weight[ch]++;
        }   

        for(int i=0;i<256;i++) {
            std::cout << weight[i] << std::endl;
        }
        fclose(in);
    }
}