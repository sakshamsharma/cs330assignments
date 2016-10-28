for index in {1..6};
do
    echo "File Batch${index}"

    for i in {1..10};
    do
        echo -n "|${i}"
        sed -i -E "1s/[0-9]+/${i}/g" Batch${index}
        ./nachos -F Batch${index} | tail -n 14 | head -n 12 | cut -f 2 -d ':' -s | awk 'BEGIN {printf "|"}; {printf "%s|", $1}; END {print ""}'
    done;

    echo ""
    echo ""
done
