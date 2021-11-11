#!/bin/bash
for ((i=0;i<=20;i++));
do
	./J < $i.in > $i.out
done