TEMPLATE = subdirs
QT_FOR_CONFIG += gui-private

qtConfig(thread): qtConfig(evdev) {
    SUBDIRS += evdevmouse evdevtouch evdevkeyboard
    qtConfig(tabletevent): \
        SUBDIRS += evdevtablet
}

qtConfig(tslib) {
    SUBDIRS += tslib
}

<<<<<<< HEAD
qtConfig(tuiotouch) {
=======
!emscripten:qtConfig(udpsocket) {
>>>>>>> 7d099b8... Introduce mkspec for web assembly
    SUBDIRS += tuiotouch
}

qtConfig(libinput) {
    SUBDIRS += libinput
}

freebsd {
    SUBDIRS += bsdkeyboard bsdmouse
}
