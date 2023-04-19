//
// Created by eric on 4/18/23.
//

#ifndef ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H
#define ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H


#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cassert>
#include <limits>

namespace ContestFileParser {
    using std::cerr;
    using std::cout;
    using std::endl;
    using std::make_pair;
    using std::ostream;
    using std::pair;
    using std::string;
    using std::vector;
    typedef int int32_t;
    typedef unsigned int uint32_t;
    typedef long int64_t;


    class ContestFileDataBase {

        /// @brief Temporary data structures to hold parsed data.
        /// Base class for all temporary data structures.
        struct Item {
            /// print data members
            virtual void print(ostream &) const {};

            /// print data members with stream operator
            /// @param ss output stream
            /// @param rhs target object
            /// @return output stream
            friend ostream &operator<<(ostream &ss, Item const &rhs) {
                rhs.print(ss);
                return ss;
            }
        };

        struct Tech : public Item {
            int32_t technologyCount;
            std::string techName;
            int32_t LibCellCount;
            struct Pin {
                string pinName;
                int32_t pinLocation[2];
                int32_t offset[2];
            };

            struct LibCell {
                bool isMacro;
                string libCellCount;
                int32_t libCellSize[2];
                int32_t pinCount;
                vector<Pin> vPin;
            };
            vector<LibCell> LibCell;
        };


        struct Die : public Item {
            int32_t DieSize[4];
            double TopDieUtil;
            double BottomDieUtil;
            struct DieRow : public Item {
                int32_t startXY[2];   ///< x, y
                int32_t rowLength;      ///< row length
                int32_t rowHeight;      ///< row height
                int32_t repeatCount; ///< repeat count
            };
            DieRow topDieRow;
            DieRow bottomDieRow;
            string TopDieTech;
            string BottomDieTech;
        };

        struct Terminal {
            int32_t TerminalSize[2];
            int32_t spacing;
            int32_t cost;
        };

        struct Instance {
            int32_t instanceCount;
            int32_t netCount;
            string instName;
            string libCellName;
            struct InstPin {
                string instName;
                string libPinName;
            };
            struct Net {
                string netName;
                int32_t numPins;
                vector<InstPin> vInstPin;

            };
        };

    };
}


#endif //ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H
