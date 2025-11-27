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

max_comparisons=0        ### NEW ###
max_args=""              ### NEW ###

> tested.txt

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

    output="$($PROGRAM "${args[@]}" 2>/dev/null)"
    ret=$?

    permutations=$((permutations + 1))

    # extracts comparison count (adjust pattern if needed)
    # comparisons=$(echo "$output" | grep -Eo '[0-9]+ comparisons' | grep -Eo '[0-9]+')
    comparisons=$(echo "$output" | grep -Eo 'comparisons=[0-9]+' | grep -Eo '[0-9]+')
    if [ -z "$comparisons" ]; then
        comparisons="?"
    fi

    # writes permutation + comparison count
    echo "${args[*]} : $comparisons" >> tested.txt

  if [ "$comparisons" != "?" ] && [ "$comparisons" -ge "$max_comparisons" ]; then
    max_comparisons=$comparisons
    max_args="${args[*]}"
fi


    if [ $ret -ne 0 ]; then
        fail_count=$((fail_count + 1))
        fails+=("${args[*]} : $comparisons")
    fi

    ok_count=$((permutations - fail_count))

    # overwrites console 
    printf "\r[%d/%d] SUCCESS=${GREEN}%d${RESET}  FAIL=${RED}%d${RESET}\n" \
        "$permutations" "$total_perms" "$ok_count" "$fail_count"

    # PRINT / OVERWRITE HIGHEST RESULT LINE
    
    printf "highest comparison: ${WHITE}%s${RESET}  |  from: ${WHITE}%s${RESET}\n" \
       "$max_comparisons" "$max_args"
    # sleep 0.05                      # remove to show speed


    # MOVE CURSOR UP 2 LINES FOR NEXT OVERWRITE
    printf "\033[2A"   ### NEW ###
}

permute "${NUMBERS[@]}"

printf "\n"  # clear last overwrite block

echo "======================="
echo "Total permutations: $permutations"
echo "Failures: $fail_count"
echo "All tested permutations saved to tested.txt"

if [ $fail_count -gt 0 ]; then
    echo "Failing permutations:"
    > failures.txt
    for f in "${fails[@]}"; do
        echo "$f" | tee -a failures.txt
    done
    echo "Saved failing inputs to failures.txt"
fi
