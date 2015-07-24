osx {
QMAKE_CXXFLAGS += -std=c++11 -stdlib=libc++
QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9
} else {
QMAKE_CXXFLAGS += -std=c++11
}
