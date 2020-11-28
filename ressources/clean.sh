#!/bin/sh

cub='includes/cub3d.h'
key='includes/keycode.h'
ini='sources/key_init.c'
os='ressources/os'

if [ -e $cub ]; then rm $cub; fi
if [ -e $key ]; then rm $key; fi
if [ -e $ini ]; then rm $ini; fi
if [ -e $os ]; then rm $os; fi