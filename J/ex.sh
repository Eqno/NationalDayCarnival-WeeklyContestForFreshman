#!/bin/bash
for ((i=0;i<=20;i++));
do
	./Jex < $i.in > $i-ex.out
done