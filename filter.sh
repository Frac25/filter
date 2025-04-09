#!/bin/sh
[ -z "$1" ] && exit 1
PATTERN=$(echo "$1" | sed 's/[][\(){}.^*+?$|]/\\&/g')
REPLACEMENT=$(echo "$1" | sed -E 's/./*/g')

sed -E "s/$PATTERN/$REPLACEMENT/g"
