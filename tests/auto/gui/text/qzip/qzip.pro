CONFIG += testcase
TARGET = tst_qzip
QT += gui-private testlib
SOURCES += tst_qzip.cpp

wince* {
   addFiles.files = testdata
   addFiles.path = .
   DEPLOYMENT += addFiles
   DEFINES += SRCDIR=\\\".\\\"
} else {
   DEFINES += SRCDIR=\\\"$$PWD\\\"
}
DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0
