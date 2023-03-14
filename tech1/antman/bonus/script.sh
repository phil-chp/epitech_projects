##
## EPITECH PROJECT, 2021
## antman
## File description:
## Script to automatically execute the programs and
## check for differences and percentage of reduction
##

# clear
# make re -s

SIZE=$(stat -c%s "$1")
./antman/antman $1 1 > temp.cmp
C_SIZE=$(stat -c%s "./temp.cmp")

REDUC=$((100-(C_SIZE*100/SIZE)));

./giantman/giantman ./temp.cmp 1 > temp.dcmp

# cat temp.cmp
# echo "\n\n"
# cat temp.dcmp
# echo "\n\n"

echo "=============================="
echo "Original size: $SIZE bytes\nCompressed:    $C_SIZE bytes"
echo -n "Reduction:     $REDUC%\nFiles Match?   "

cmp -s $1 ./temp.dcmp && echo "YES" || echo "NO"

echo "=============================="

rm -f temp.dcmp temp.cmp
