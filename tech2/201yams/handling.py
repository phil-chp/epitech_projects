#
## Epitech, project 2022
## 201 YAMS
## Co-authored by:
##   - Philippe CHEYPE <philippe.cheype@epitech.eu>
##   - Vitali DROUJKO  <vitali.droujko@epitech.eu>
## File Description:
## yams
#

from sys import stderr

def check_argv(number):
    if number <= 0 or number > 6:
        return 0
    return number


def handle_dices(args):
    dices_sum = 0
    try:
        for i in range(1, 6):
            dice = int(args[i])
            dices_sum += dice
            if dice == 0 and dices_sum != 0:
                print("Error: Thrown and not thrown dices are not compatible.\n", file=stderr)
                return 1
        if (int(args[1]) == 0 and dices_sum != 0):
            print("Error: Thrown and not thrown dices are not compatible.\n", file=stderr)
            return 1
    except ValueError as e:
        print(f"Error: {e}\n", file=stderr)
        return 1
    return 0

def handle_combinations(args):
    combination_list = ["pair_", "three_", "four_", "full__", "straight_", "yams_"]
    combination = args[6]
    valid_nums = "123456"
    for n in valid_nums:
        combination = combination.replace(n, '')
    if combination not in combination_list:
        print("Error: Combination not found.\n", file=stderr)
        return 1
    else:
        args[6] = args[6].split('_')
        if args[6][0] == "full" and \
            (len(args[6][2]) == 0 or args[6][1] == args[6][2]):
            print("Error: Combination not found.\n", file=stderr)
            return 1
    if len(args[6][1]) == 0:
        print("Error: Combination cannot be of 0's.\n", file=stderr)
        return 1
    if args[6][0] == "straight" and \
        (args[6][1] != '5' and args[6][1] != '6'):
        print("Error: Straight can only be 5 or 6.\n", file=stderr)
        return 1
    return 0

def handle_args(args):
    if len(args) != 7:
        print("Error: Bad arguments.\n", file=stderr)
        return 1
    if handle_dices(args):
        return 1
    if handle_combinations(args):
        return 1


def usage():
    print("USAGE")
    print("\t./201yams d1 d2 d3 d4 d5 c\n")
    print("DESCRIPTION")
    print("\td1\tvalue of the first die (0 if not thrown)")
    print("\td2\tvalue of the second die (0 if not thrown)")
    print("\td3\tvalue of the third die (0 if not thrown)")
    print("\td4\tvalue of the fourth die (0 if not thrown)")
    print("\td5\tvalue of the fifth die (0 if not thrown)")
    print("\tc\texpected combination")
    exit(84)  # TODO: Not always 84 ?
