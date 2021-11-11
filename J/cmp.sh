#!/bin/bash
for ((i=0;i<=20;i++))
do
	diff $i.out $i-ex.out
done