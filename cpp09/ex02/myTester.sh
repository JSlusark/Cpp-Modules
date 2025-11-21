#!/usr/bin/env bash

PROGRAM="./PmergeMe"
GREEN="\033[32m"
RED="\033[31m"
RESET="\033[0m"


# ======== GET INPUT NUMBERS ========
if [ $# -lt 1 ]; then
    echo "Usage: $0 n1 n2 n3 ..."
    exit 1
fi
NUMBERS=("$@")
# ===================================

fail_count=0
fails=()
permutations=0
total_perms=0

# first compute total permutations (n!)
factorial() {
    local n=$1
    local result=1
    for ((i=2; i<=n; i++)); do
        result=$((result * i))
    done
    echo $result
}

total_perms=$(factorial ${#NUMBERS[@]})

permute() {
    local arr=("$@")
    local n=${#arr[@]}

    local c=()
    for ((i=0; i<n; i++)); do c[i]=0; done

    run_test "${arr[@]}"

    local i=1
    while [ $i -lt $n ]; do
        if [ ${c[$i]} -lt $i ]; then
            if (( i % 2 == 0 )); then
                swap_index=0
            else
                swap_index=${c[$i]}
            fi

            tmp=${arr[$i]}
            arr[$i]=${arr[$swap_index]}
            arr[$swap_index]=$tmp

            run_test "${arr[@]}"

            c[$i]=$((c[$i] + 1))
            i=1
        else
            c[$i]=0
            i=$((i + 1))
        fi
    done
}

run_test() {
    local args=("$@")

    # silents program execution (ergo -> printing)
    $PROGRAM "${args[@]}" > /dev/null 2>&1
    ret=$?

    permutations=$((permutations + 1))

    if [ $ret -ne 0 ]; then
        fail_count=$((fail_count + 1))
        fails+=("${args[*]}")
    fi

    ok_count=$((permutations - fail_count))

    # overwrites console 
    printf "\r[%d/%d] SUCCESS=${GREEN}%d${RESET}  FAIL=${RED}%d${RESET}" \
        "$permutations" "$total_perms" "$ok_count" "$fail_count"
}

# run all permutations
permute "${NUMBERS[@]}"

# print final newline
echo

# summary
echo "======================="
echo "Total permutations: $permutations"
echo "Failures: $fail_count"

if [ $fail_count -gt 0 ]; then
    echo "Failing permutations:"
    > failures.txt
    for f in "${fails[@]}"; do
        echo "$f" | tee -a failures.txt
    done
    echo "Saved failing inputs to failures.txt"
fi
