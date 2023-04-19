//
// Created by eric on 4/18/23.
//

#include "ContestFileDataBase.h"

namespace ContestFileParser {
    class ContestFileParser {
    public:
        void parseContestFile(const string &filename);

        void getTechInfo();

        void getLibCellInfo();

        void getPinInfo();

        void getDieInfo();

        void getTerminalInfo();

        void getInstInfo();

        void getInstCellInfo();

        void getInstNetInfo();

        void getNetPinInfo();
    };
}