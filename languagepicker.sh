#!/bin/bash

languages=("c" "c++" "go" "java" "typescript")
random_index=$((RANDOM % ${#languages[@]}))
echo "${languages[$random_index]}"