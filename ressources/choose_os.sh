#!/bin/sh

os='os'

if [ ! -e $os ]
then
    if [[ "$OSTYPE" == "linux-gnu"* ]]; then
        sh ressources/linux/linux.sh
        touch ressources/os
    elif [[ "$OSTYPE" == "darwin"* ]]; then
        sh ressources/macos/macos.sh
        touch ressources/os
    fi
fi