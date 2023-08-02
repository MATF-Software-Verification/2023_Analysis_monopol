QT += testlib
QT += core gui multimedia

CONFIG += qt warn_on depend_includepath testcase
CONFIG += c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_CXXFLAGS += --coverage
QMAKE_LFLAGS += --coverage

DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000

TEMPLATE = app

SOURCES += \
        tst_monopoly.cpp
        ../03-monopol/monopoly/src/bank.cpp
        ../03-monopol/monopoly/src/board.cpp
        ../03-monopol/monopoly/src/bot.cpp
        ../03-monopol/monopoly/src/button.cpp
        ../03-monopol/monopoly/src/card_chance_commutnity.cpp
        ../03-monopol/monopoly/src/card_property.cpp
        ../03-monopol/monopoly/src/field.cpp
        ../03-monopol/monopoly/src/game.cpp
        ../03-monopol/monopoly/src/game_graphic.cpp
        ../03-monopol/monopoly/src/game_jail.cpp
        ../03-monopol/monopoly/src/game_logic.cpp
        ../03-monopol/monopoly/src/game_mortgage.cpp
        ../03-monopol/monopoly/src/game_options.cpp
        ../03-monopol/monopoly/src/game_over.cpp
        ../03-monopol/monopoly/src/game_tax.cpp
        ../03-monopol/monopoly/src/keyPressEventFilter.cpp
        ../03-monopol/monopoly/src/main.cpp
        ../03-monopol/monopoly/src/my_pixmap_graphics_item.cpp
        ../03-monopol/monopoly/src/notification.cpp
        ../03-monopol/monopoly/src/pause.cpp
        ../03-monopol/monopoly/src/player.cpp
        ../03-monopol/monopoly/src/rectangle_with_text.cpp
        ../03-monopol/monopoly/src/rules.cpp
        ../03-monopol/monopoly/src/welcome.cpp

SUBDIRS += \
        ../03-monopol/monopoly/monopoly.pro

HEADERS += \
        ../03-monopol/monopoly/include/bank.hpp
        ../03-monopol/monopoly/include/board.hpp
        ../03-monopol/monopoly/include/bot.hpp
        ../03-monopol/monopoly/include/button.hpp
        ../03-monopol/monopoly/include/card_chance_community.hpp
        ../03-monopol/monopoly/include/card_property.hpp
        ../03-monopol/monopoly/include/field.hpp
        ../03-monopol/monopoly/include/game.hpp
        ../03-monopol/monopoly/include/game_over.h
        ../03-monopol/monopoly/include/keyPressEventFilter.h
        ../03-monopol/monopoly/include/my_pixmap_graphics_item.hpp
        ../03-monopol/monopoly/include/notification.hpp
        ../03-monopol/monopoly/include/pause.h
        ../03-monopol/monopoly/include/rectangle_with_text.hpp
        ../03-monopol/monopoly/include/rules.h
        ../03-monopol/monopoly/include/welcome.hpp


RESOURCES += \
    ../03-monopol/monopoly/resources.qrc
