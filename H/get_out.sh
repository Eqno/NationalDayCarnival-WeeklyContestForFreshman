#!/bin/bash
for ((i=0;i<=20;i++));
do
	./gen_result < $i.in > $i.out ;
done
