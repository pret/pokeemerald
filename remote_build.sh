#!/bin/bash

# Rsync repo to build machine; build and scp the ROM back

set +v
set -e
git push build --force # ssh://merrbot:/home/ubuntu/pokeemerald
ssh merrbot "source /etc/profile.d/devkit-env.sh && cd pokeemerald && git reset --hard && git checkout dexnav && make"
scp merrbot:pokeemerald/pokeemerald.gba romhack.gba
