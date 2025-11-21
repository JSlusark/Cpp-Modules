#!/usr/bin/env bash

# ========= CONFIG =========
NUMBERS=(1 2 3 4 5)
PROGRAM="./PmergeMe"
# ==========================

fail_count=0
fails=()

permute() {
    local arr=("$@")
    local n=${#arr[@]}

    # Heap's algorithm
    local c=()
    for ((i=0; i<n; i++)); do c[i]=0; done

    # First permutation
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
echo "Total permutations: 120"
echo "Failures: $fail_count"

if [ $fail_count -gt 0 ]; then
    echo "Failing permutations:"
    for f in "${fails[@]}"; do
        echo "$f"
    done > failures.txt
    echo "Saved failing inputs to failures.txt"
fi
