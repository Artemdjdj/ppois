from bloom_filter import BloomFilter
from interface import Interface
from colorama import init, Fore, Style


def main():
    start_condition = -1
    bloom_filter = BloomFilter(5, 100)
    init()
    while start_condition != 3:
        Interface.get_menu()
        try:
            start_condition = int(input("Choose option:\t"))
            match start_condition:
                case 1:
                    new_word = input("Enter new word:\t")
                    bloom_filter.add_value(new_word)
                    print(Fore.GREEN + "New word successfully added!" + Style.RESET_ALL)
                case 2:
                    new_word = input("Enter word which want to check:\t")
                    result = bloom_filter.check_value(new_word)
                    if result:
                        print(Fore.BLUE + "Your word might be in the filter!" + Style.RESET_ALL)
                    else:
                        print(Fore.RED + "Your word doesn't exist!" + Style.RESET_ALL)
                case 3:
                    start_condition = 3
                    print(Fore.GREEN + "\nThe program was successfully completed!" + Style.RESET_ALL)
                case _:
                    print(Fore.RED + "\nInvalid option!" + Style.RESET_ALL)
        except ValueError:
            print(Fore.RED + "\nWrong input!" + Style.RESET_ALL)


if __name__ == '__main__':
    main()
