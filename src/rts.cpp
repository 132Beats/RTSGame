//
// Created by hendrik on 15.10.19.
//

#include <QtWidgets/QApplication>
#include "rts.h"
#include <memory>



RTS::RTS() {
}
RTS::~RTS() {
}

int RTS::start(int argc, char** argv) {
    QApplication qapp(argc, argv);
    return qapp.exec();
}