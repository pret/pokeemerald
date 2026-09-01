#!/bin/bash
lalala1="graphics/object_events/pics/pokemon/"
lalala2="a2"
for file in graphics/object_events/pics/pokemon/*.png; do
    name=${file##*/}
    base=${name%.png}
    #echo "${file}"
    #echo "${base}"
    echo "graphics/pokemon/${base}/follower.png"
    mv -- "$file" "graphics/pokemon/${base}/follower.png"
done
