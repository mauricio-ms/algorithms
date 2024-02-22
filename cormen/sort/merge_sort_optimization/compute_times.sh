rm times.dat
touch times.dat
TIMEFORMAT=%R

for k in $(seq 1 1000)
	do
	  echo "Computing time for k=$k"
		t=$({ time ./merge_sort_optimized 1000000 k ; } 2>&1)
		t=$(sed 's/\,/\./g' <<< $t)
		echo "$k $t" >> times.dat
	done
