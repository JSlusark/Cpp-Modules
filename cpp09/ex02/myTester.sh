#!/usr/bin/env bash

PROGRAM="./PmergeMe"

# ======== GET INPUT NUMBERS ========
if [ $# -lt 1 ]; then
    echo "Usage: $0 n1 n2 n3 ..."
    exit 1
fi
NUMBERS=("$@")
# ===================================

fail_count=0
fails=()
perm_count=0

permute() {
    local arr=("$@")
    local n=${#arr[@]}

    local c=()
    for ((i=0; i<n; i++)); do c[i]=0; done

    # first permutation
    run_test "${arr[@]}"

    local i=1
    while [ $i -lt $n ]; do
        if [ ${c[$i]} -lt $i ]; then
            if (( i % 2 == 0 )); then
                swap_index=0
            else
                swap_index=${c[$i]}
            fi

            # swap
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
    echo "Running: $PROGRAM ${args[*]}"
    $PROGRAM "${args[@]}"
    ret=$?

    perm_count=$((perm_count + 1))

    if [ $ret -ne 0 ]; then
        fail_count=$((fail_count + 1))
        fails+=("${args[*]}")
    fi
}

# run all permutations
permute "${NUMBERS[@]}"

# summary
echo
echo "======================="
echo "Total permutations: $perm_count"
echo "Failures: $fail_count"

if [ $fail_count -gt 0 ]; then
    echo "Failing permutations:"
    > failures.txt
    for f in "${fails[@]}"; do
        echo "$f" | tee -a failures.txt
    done
    echo "Saved failing inputs to failures.txt"
fi
