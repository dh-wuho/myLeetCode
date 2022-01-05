# method 1
awk 'NR==10 {print $0}' file.txt

# method 2
sed -n 10p file.txt

# method 3
cnt=0
while read line && [ $cnt -le 10 ]
do
    let cnt=cnt+1
    if [ $cnt -eq 10 ]
    then
        echo $line
    fi
done < file.txt