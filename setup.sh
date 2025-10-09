#!/bin/bash
SCRIPT_PATH=$(readlink -f "$0")
SCRIPT_DIR=$(dirname "$SCRIPT_PATH")
GOOGLETEST_INSTALL_PATH="$SCRIPT_DIR/contrib/googletest_install"

git submodule init
git submodule update --recursive
rm -r $GOOGLETEST_INSTALL_PATH 2>/dev/null || true
(cd "$SCRIPT_DIR/contrib/googletest" && (rm -r build 2>/dev/null || true) && mkdir build && cd build && cmake .. -DCMAKE_INSTALL_PREFIX="$GOOGLETEST_INSTALL_PATH" && make && make install)
