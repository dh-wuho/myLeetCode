# Read from the file file.txt and print its transposed content to stdout.
awk ' {
    for(i = 1; i <= NF; i++) {
        if(NR == 1) {
            s[i] = $i;
        }
        else {
            s[i] = s[i] " " $i;
        }
    }
}
END {
    for(i = 1; i <= NF; i++) {
        print s[i];
    }
}
' file.txt


# Read from the file file.txt and print its transposed content to stdout.
while read -a line
do
    for ((i = 0; i < ${#line[@]}; i++))
    do
        s[$i]="${s[$i]} ${line[$i]}"
    done
done < file.txt
for((i = 0; i < ${#s[@]}; i++))
do
    echo ${s[$i]}
done