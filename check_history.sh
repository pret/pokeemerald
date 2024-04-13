#!/bin/bash

if [ -e .histignore ]
then
    exit 0
fi

if [ $GITHUB_ACTION ]
then
    exit 0
fi

has_hist=false
has_git=1
if which git >/dev/null
then
    has_hist="$(git rev-parse --is-inside-work-tree 2>/dev/null)"
else
    has_git=0
fi

if [ $has_git -ne 1 ]
then
    echo -e "\033[0;31mfatal: \033[0m\033[1;33mgit was not found. You will be unable to use version control, update pokeemerald-expansion, or use feature branches. To use version control, install \`git\` and clone the repository instead of using \"Download Zip\" on GitHub. Run \`touch .histignore\` to ignore this and continue anyways.\033[0m"
    exit 1
fi

if [ "$has_hist" ]
then
   exit 0
else
   echo -e "\033[0;31mfatal: \033[0m\033[1;33mno git history found. You will be unable to use version control, update pokeemerald-expansion, or use feature branches. To use version control, use \`git\` to clone the repository instead of using \"Download Zip\" on GitHub. Run \`touch .histignore\` to ignore this and continue anyways.\033[0m"
   exit 1
fi

