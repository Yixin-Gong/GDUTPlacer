//
// Created by eric on 4/18/23.
//

#ifndef ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H
#define ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H


#include <string>
#include <utility>
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
                int32_t pinLocation[2]{};
                int32_t offset[2]{};

                ///constructor
                Pin(string &pin_name, int32_t locY, int32_t locX, int32_t offsetX, int32_t offsetY) {
                    pinName.swap(pin_name);
                    pinLocation[0] = locX;
                    pinLocation[1] = locY;
                    offset[0] = offsetX;
                    offset[1] = offsetY;
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
                int32_t libCellSize[2]{};
                int32_t pinCount;
                vector<Pin> vPin;

                ///constructor
                LibCell(bool flag, string &lib_cell_name, int32_t x, int32_t y, int32_t pin_count, vector<Pin> v_pin) {
                    isMacro = flag;
                    libCellName.swap(lib_cell_name);
                    libCellSize[0] = x;
                    libCellSize[1] = y;
                    pinCount = pin_count;
                    vPin = std::move(v_pin);
                }

                virtual void reset() {
                    isMacro = false;
                    libCellName = "";
                    libCellSize[0] = libCellSize[1] = 0;
                    pinCount = 0;
                    vPin.clear();
                }
            };

            vector<LibCell> vLibCell;

            ///constructor
            Tech(int32_t tech_count, string &tech_name, int32_t lib_cell_count, vector<LibCell> v_lib_cell) {
                technologyCount = tech_count;
                techName.swap(tech_name);
                LibCellCount = lib_cell_count;
                vLibCell = std::move(v_lib_cell);
            }

            void reset() {
                technologyCount = 0;
                techName = "";
                LibCellCount = 0;
                vLibCell.clear();
            }
        };

        struct Die {
            int32_t DieSize[4]{};
            double DieUtil{};

            struct DieRow {
                int32_t startXY[2]{};   ///< x, y
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
            string DieTech;


            ///constructor
            Die(){
                reset();
            }

            ///constructor
            Die(int32_t startX, int32_t startY, int32_t sizeX, int32_t sizeY, double util,
                vector<DieRow> v, string &tech) {
                DieSize[0] = startX;
                DieSize[1] = startY;
                DieSize[2] = sizeX;
                DieSize[3] = sizeY;
                DieUtil = util;
                vDieRow = std::move(v);
                DieTech.swap(tech);
            }

            void reset() {
                DieSize[0] = DieSize[1] = DieSize[2] = DieSize[3] = 0;
                DieUtil = 0;
                vDieRow.clear();
                DieTech = "";
            }
        };

        struct Terminal {
            int32_t TerminalSize[2]{};
            int32_t spacing;
            int32_t cost;

            ///constructor
            Terminal(int32_t x, int32_t y, int32_t spc, int32_t cst) {
                TerminalSize[0] = x;
                TerminalSize[1] = y;
                spacing = spc;
                cost = cst;
            }

            void reset() {
                TerminalSize[0] = TerminalSize[1] = 0;
                spacing = 0;
                cost = 0;
            }

        };

        struct Instance {
            int32_t instanceCount{};
            int32_t netCount{};

            struct InstCell {
                string instName;
                string libCellName;

                ///constructor
                InstCell(string &inst_name, string &lib_cell_name) {
                    instName.swap(inst_name);
                    libCellName.swap(lib_cell_name);
                }

                virtual void reset() {
                    instName = "";
                    libCellName = "";
                }


            };


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
                vector<InstPin> vInstPin{};

                ///constructor
                Net(string &name, int32_t num_pins, vector<InstPin> v) {
                    netName.swap(name);
                    numPins = num_pins;
                    vInstPin = std::move(v);
                }

                void reset() {
                    netName = "";
                    numPins = 0;
                    vInstPin.clear();
                }
            };

            vector<InstCell> vInstCell{};
            vector<Net> vNet{};


            Instance(){
                reset();
            }


            ///constructor
            Instance(int32_t cell_count, int32_t net_count, vector<Net> v_net, vector<InstCell> v_cell) {
                instanceCount = cell_count;
                netCount = net_count;
                vNet = std::move(v_net);
                vInstCell = std::move(v_cell);
            }

            void reset() {
                instanceCount = 0;
                netCount = 0;
                vNet.clear();
                vInstCell.clear();
            }
        };

        vector<Tech> vTech;

        static Die TopDie(){ return {}; };

        static Die BottomDie(){return {};};

        static Terminal myTerminal(){ return {0, 0, 0, 0}; };

        static Instance myInstance(){return {};};


        ///constructor
        ContestFileDataBase(vector<Tech> v_tech, Die top, Die bottom, Terminal terminal, Instance instance) {
            vTech = std::move(v_tech);
            TopDie() = std::move(top);
            BottomDie() = std::move(bottom);
            myTerminal() = terminal;
            myInstance() = std::move(instance);
        }

        void reset() {
            vTech.clear();
            TopDie().reset();
            BottomDie().reset();
            myTerminal().reset();
            myInstance().reset();
        }
    };
}


#endif //ICCAD_CONTEST_2023_PROBLEMB_CONTESTFILEDATABASE_H
