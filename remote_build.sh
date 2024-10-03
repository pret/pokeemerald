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
old_head=$(git rev-parse --short @)
set +e
# Make a temp commit for unstaged changes
temp_commit_msg="temp build"
git commit -aem "$temp_commit_msg"
retVal=$?
set -e
# set -x
git push build --force-with-lease
# { set +x; } 2>/dev/null
# Reset temp commit
if [[ $retVal -eq 0 ]]; then
    commit_msg=$(git log -1 --pretty=%B)
    if [[ "$commit_msg" == "$temp_commit_msg" ]]; then
        # Keep i(N)tent to add
        git reset --mixed -N "$old_head" &>/dev/null
    fi
fi
set -x
ssh -o "VisualHostKey=no" $remote_host "cd $remote_path && git reset --hard && git checkout $git_branch && $make_cmd"
scp -o "VisualHostKey=no" "$remote_host:$remote_path/$make_product" $make_dest
