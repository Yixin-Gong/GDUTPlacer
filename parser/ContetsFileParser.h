//
// Created by eric on 4/18/23.
//

#include "ContestFileDataBase.h"

namespace ContestFileParser {
    class Parser {
    public:
        explicit Parser(string &filename){
            static char filebuffer[1024*1024*128] = {0};
            fp_ = fopen(filename.c_str(),"r");
            std::cout << "\nOpen file: "<< filename <<std::endl;
            setbuffer(fp_,filebuffer,sizeof(filebuffer));
        }

        ~Parser(){
            fclose(fp_);
        }

        void getTechInfo();

        void getLibCellInfo();

        void getPinInfo();

        void getDieInfo();

        void getTerminalInfo();

        void getInstInfo();

        void getInstCellInfo();

        void getInstNetInfo();

        void getNetPinInfo();
    private:
        FILE *fp_;

    };
}