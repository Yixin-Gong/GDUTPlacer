//
// Created by eric on 4/18/23.
//

#ifndef ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H
#define ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H


#include <string>
#include <vector>

namespace ContestFileParser {
    using std::string;
    using std::vector;
    typedef int int32_t;
    typedef unsigned int uint32_t;
    typedef long int64_t;


    class ContestFileDataBase {

        struct Tech {
            int32_t technologyCount;
            std::string techName;
            int32_t LibCellCount;

            struct Pin {
                string pinName;
                int32_t pinLocation[2];
                int32_t offset[2];

                ///constructor
                Pin(string &pin_name, int32_t pin_loc[2], int32_t off_set[2]) {
                    pinName.swap(pin_name);
                    pinLocation[2] = pin_loc[2];
                    offset[2] = off_set[2];
                }

                virtual void reset() {
                    pinName = "";
                    pinLocation[0] = pinLocation[1] = 0;
                    offset[0] = offset[1] = 0;
                }
            };

            struct LibCell {
                bool isMacro;
                string libCellName;
                int32_t libCellSize[2];
                int32_t pinCount;
                vector<Pin> vPin;

                ///constructor
                LibCell(bool flag, string &lib_cell_name, int32_t x, int32_t y, int32_t pin_count, vector<Pin> v_pin) {
                    isMacro = flag;
                    libCellName.swap(lib_cell_name);
                    libCellSize[0] = x;
                    libCellSize[1] = y;
                    pinCount = pin_count;
                    vPin = v_pin;
                }

                virtual void reset() {
                    isMacro = 0;
                    libCellName = "";
                    libCellSize[0] = libCellSize[1] = 0;
                    pinCount = 0;
                    vPin.clear();
                }
            };

            vector<LibCell> vLibCell;

            ///constructor
            Tech(int32_t tech_count, string &tech_name, int32_t lib_cell_count, vector<LibCell> v_libcell) {
                technologyCount = tech_count;
                techName.swap(tech_name);
                LibCellCount = lib_cell_count;
                vLibCell = v_libcell;
            }

            virtual void reset() {
                technologyCount = 0;
                techName = "";
                LibCellCount = 0;
                vLibCell.clear();
            }
        };


        struct Die {
            int32_t DieSize[4];
            double TopDieUtil;
            double BottomDieUtil;

            struct DieRow {
                int32_t startXY[2];   ///< x, y
                int32_t rowLength;      ///< row length
                int32_t rowHeight;      ///< row height
                int32_t repeatCount; ///< repeat count

                ///constructor
                DieRow(int32_t x, int32_t y, int32_t length, int32_t height, int32_t repeat) {
                    startXY[0] = x;
                    startXY[1] = y;
                    rowLength = length;
                    rowHeight = height;
                    repeatCount = repeat;
                }

                virtual void reset() {
                    startXY[0] = startXY[1] = 0;
                    rowLength = 0;
                    rowHeight = 0;
                    repeatCount = 0;
                }
            };

            vector<DieRow> vDieRow;
            string TopDieTech;
            string BottomDieTech;

            ///constructor
            Die(int32_t startX, int32_t startY, int32_t sizeX, int32_t sizeY, double top_util, double bot_util,
                vector<DieRow> v, string &top_tech, string &bot_tech) {
                DieSize[0] = startX;
                DieSize[1] = startY;
                DieSize[2] = sizeX;
                DieSize[3] = sizeY;
                TopDieUtil = top_util;
                BottomDieUtil = bot_util;
                vDieRow = v;
                TopDieTech.swap(top_tech);
                BottomDieTech.swap(bot_tech);
            }

            virtual void reset() {
                DieSize[0] = DieSize[1] = DieSize[2] = DieSize[3] = 0;
                TopDieUtil = BottomDieUtil = 0;
                vDieRow.clear();
                TopDieTech = "";
                BottomDieTech = "";
            }
        };

        struct Terminal {
            int32_t TerminalSize[2];
            int32_t spacing;
            int32_t cost;

            ///constructor
            Terminal(int32_t x, int32_t y, int32_t spc, int32_t cst) {
                TerminalSize[0] = x;
                TerminalSize[1] = y;
                spacing = spc;
                cost = cst;
            }

            virtual void reset() {
                TerminalSize[0] = TerminalSize[1] = 0;
                spacing = 0;
                cost = 0;
            }

        };

        struct Instance {
            int32_t instanceCount;
            int32_t netCount;
            string instName;
            string libCellName;

            struct InstPin {
                string instName;
                string libPinName;

                ///constructor
                InstPin(string &inst_name, string &pin_name) {
                    instName.swap(inst_name);
                    libPinName.swap(pin_name);
                }

                virtual void reset() {
                    instName = "";
                    libPinName = "";
                }
            };

            struct Net {
                string netName;
                int32_t numPins;
                vector<InstPin> vInstPin;

                ///constructor
                Net(string &name, int32_t num_pins, vector<InstPin> v) {
                    netName.swap(name);
                    numPins = num_pins;
                    vInstPin = v;
                }

                virtual void reset() {
                    netName = "";
                    numPins = 0;
                    vInstPin.clear();
                }
            };

            vector<Net> vNet;

            ///constructor
            Instance(int32_t count, int32_t net_count, string &inst_name, string &lib_cell_name, vector<Net> v) {
                instanceCount = count;
                netCount = net_count;
                instName.swap(inst_name);
                libCellName.swap(lib_cell_name);
                vNet = v;
            }

            virtual void reset() {
                instanceCount = 0;
                netCount = 0;
                instName = "";
                libCellName = "";
                vNet.clear();
            }
        };
    };
}


#endif //ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H
