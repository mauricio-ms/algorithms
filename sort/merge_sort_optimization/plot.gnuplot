set xlabel "k"
set ylabel "Tempo de execução"
set arrow from 0,0.225 to 1000,0.225 nohead linecolor "black"
plot "times.dat" with lines linestyle 1 title "MergeSort Otimizado", 1/0 t "MergeSort Original" linecolor "black"
