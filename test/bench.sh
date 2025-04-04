#!/bin/bash

for i in {01..12}; do
	./bin < test/txt/$i.txt;
done
