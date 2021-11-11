#!/bin/sh
for ((i=0; i<=20; i++)) ;
do
	cat $i.in ;
	cat $i.out;
	echo -----------
done