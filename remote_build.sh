#!/bin/bash

# Push to SSH machine; build and scp build products back

set -e
git_branch=$(git branch --show-current)
# See https://unix.stackexchange.com/a/13472
remote_host=$(git remote get-url build | sed -nr -e "s/ssh:\/\/(\w+@?\w*):.*/\1/p") # Extract remote host
remote_path=$(git remote get-url build | sed -nr -e "s/ssh:\/\/\w+@?\w*://p") # Extract remote path
set -x
git push build --force
# `nproc` must be escaped so that it executes on the remote machine
ssh $remote_host "cd $remote_path && git reset --hard && git checkout $git_branch && \
                  echo \"Using \`nproc\` job(s)\" && make DDEBUG=1 -j\`nproc\`"
scp "$remote_host:$remote_path/pokeemerald.gba" romhack.gba
