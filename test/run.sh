#!/bin/bash

#for i in {01..12}; do
#	./bin < test/txt/$i.txt;
#done
mapfile -t < test/txt/ans.txt

for i in {01..12}; do
    [[ "$(./bin < test/txt/$i.txt)" == "${MAPFILE[$((10#$i - 1))]}" ]] \
        && echo "✅ Test $i passed" \
        || { echo "❌ Test $i failed"; echo "Expected: '${MAPFILE[$((10#$i - 1))]}'"; echo "Got     : '$(./bin < test/txt/$i.txt)'"; }
done
