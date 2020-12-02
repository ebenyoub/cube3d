#!/bin/sh

cub='includes/cub3d.h'
key='includes/keycode.h'
ini='sources/key_init.c'
os='ressources/os'
main='souces/cub_main.c'

if [ -e $cub ]; then rm $cub; fi
if [ -e $key ]; then rm $key; fi
if [ -e $ini ]; then rm $ini; fi
if [ -e $os ]; then rm $os; fi
if [ -e $main ]; then rm $main; fi