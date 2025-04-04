#!/bin/bash

for k in {1..10}; do
	for i in {01..12}; do
		./bin < test/txt/$i.txt;
	done
done
