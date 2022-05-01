#!/bin/bash

# Git REmote Make
# Push to SSH machine; build and scp build products back

set -e
git_branch=$(git branch --show-current)
# See https://unix.stackexchange.com/a/13472
remote_host=$(git remote get-url build | sed -nr -e "s/ssh:\/\/(\w+@?\w*):.*/\1/p") # Extract remote host
remote_path=$(git remote get-url build | sed -nr -e "s/ssh:\/\/\w+@?\w*://p") # Extract remote path
make_cmd=$(git config --local remake.make)
make_product=$(git config --local remake.src)
make_dest=$(git config --local remake.dest)
set -x
git push build --force-with-lease
ssh $remote_host "cd $remote_path && git reset --hard && git checkout $git_branch && $make_cmd"
scp "$remote_host:$remote_path/$make_product" $make_dest
