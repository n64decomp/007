#!/bin/bash

# This script should execute from root source control directory.
result=$(basename "$PWD")
if [ $result = "scripts" ] ; then
    cd ..
fi

./scripts/make/build_hashtable.sh -v u -o scripts/ge007.u-test_basis.csv
./scripts/make/build_hashtable.sh -v j -o scripts/ge007.j-test_basis.csv
./scripts/make/build_hashtable.sh -v e -o scripts/ge007.e-test_basis.csv