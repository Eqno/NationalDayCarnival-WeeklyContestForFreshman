#!/bin/sh
for((i=0;i<=20;i++))
do
	./I < $i.in > $i.out
done
