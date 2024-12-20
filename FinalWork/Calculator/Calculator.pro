QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    calculatorcore.cpp \
    historypanel.cpp \
    main.cpp \
    mainwindow.cpp \
    settingsmanager.cpp \
    unitconverter.cpp

HEADERS += \
    calculatorcore.h \
    historypanel.h \
    mainwindow.h \
    settingsmanager.h \
    unitconverter.h

RESOURCES += \
    resources.qrc

TRANSLATIONS += \
    translations/calculator_zh_CN.ts \
    translations/calculator_en_US.ts
