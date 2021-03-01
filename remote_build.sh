#!/bin/bash

# Rsync repo to build machine; build and scp the ROM back

set +v
set -e
git_branch=$(git branch --show-current)
git push build --force # ssh://merrbot:/home/ubuntu/pokeemerald
ssh merrbot "cd pokeemerald && git reset --hard && git checkout $git_branch && make"
scp merrbot:pokeemerald/pokeemerald.gba romhack.gba
