#!/bin/sh
[ -z "$1" ] && exit 1
sed -E "s/$(echo "$1" | sed 's/[][(){}\^.*+?$]/\\&/g')/$(echo "$1" | sed 's/./*/g')/g"
