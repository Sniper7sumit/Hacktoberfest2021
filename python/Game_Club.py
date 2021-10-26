print("\t\t--------Menu--------")
print("1. NQueens Problem\n2. Caesar Cipher\n3. Magic Square\n4. Black Jack\n5. Ascii Art")
a = int(input("Enter any one choise you want: "))
if a == 1:
    class QueenChessBoard:
        def __init__(self, size):
            self.size = size
            self.columns = []

        def get_size(self):
            return self.size

        def get_queens_count(self):
            return len(self.columns)

        def place_in_next_row(self, column):
            self.columns.append(column)

        def remove_in_current_row(self):
            return self.columns.pop()

        def is_this_column_safe_in_next_row(self, column):
            row = len(self.columns)

            for queen_column in self.columns:
                if column == queen_column:
                    return False

            # check diagonal
            for queen_row, queen_column in enumerate(self.columns):
                if queen_column - queen_row == column - row:
                    return False

            # check other diagonal
            for queen_row, queen_column in enumerate(self.columns):
                if ((self.size - queen_column) - queen_row
                    == (self.size - column) - row):
                    return False

            return True

        def display(self):
            for row in range(self.size):
                for column in range(self.size):
                    if column == self.columns[row]:
                        print('Q', end=' ')
                    else:
                        print('-', end=' ')
                print()


    def print_all_solutions_to_n_queen(size):
        board = QueenChessBoard(size)
        number_of_solutions = print_all_solutions_helper(board)
        print('Number of solutions:', number_of_solutions)

    def print_all_solutions_helper(board):
        size = board.get_size()

        # if board is full, display solution
        if size == board.get_queens_count():
            board.display()
            print()
            return 1

        number_of_solutions = 0
        # place queen in next row
        for column in range(size):
            if board.is_this_column_safe_in_next_row(column):
                board.place_in_next_row(column)
                number_of_solutions += print_all_solutions_helper(board)
                board.remove_in_current_row()

        return number_of_solutions


    n = int(input('Enter n: '))
    print_all_solutions_to_n_queen(n)

elif a == 2:
    def getMode():
        while True:
            mode = input("Do you want to encrypt or decrypt or brute force a message?: ").lower()
            if mode in 'encrypt e decrypt d brute b'.split():
                return mode
            else:
                print("Enter either 'encrypt' or 'e' or 'decrypt' or 'd' or 'brute' or 'b': ")

    def getMessage():
        print("Enter your message: ")
        return input()

    def getKey():
        key = 0
        while True:
            key = int(input("Enter the key number(1-26): "))
            if key >= 1 and key <= 26: 
                return key

    def getTranslatedMessage(mode, message, key):
        if mode[0] == 'd':
            key = -key
        translated = ""

        for symbol in message:
            if symbol.isalpha():
                num = ord(symbol)
                num += key

                if symbol.isupper():
                    if num > ord('Z'):
                        num -= 26
                    elif num < ord('A'):
                        num += 26
                elif symbol.islower():
                    if num > ord('z'):
                        num -= 26
                    elif num < ord('a'):
                        num += 26

                translated += chr(num)
            else:
                translated += symbol
        return translated

    mode = getMode()
    message = getMessage()
    if mode[0] != 'b':
        key = getKey()

    print("Your translated text is: ")
    if mode[0] != 'b':
        print(getTranslatedMessage(mode, message, key))
    else:
        for key in range (1, 27):
            print(key, ")", getTranslatedMessage('decrypt', message, key))

elif a == 3:
    from tabulate import tabulate
    from IPython.display import clear_output

    a = input("Enter you birth date (dd/mm/yyyy): ")
    a = a.split("/")
    e = int(a[2])
    b = int(a[1])
    a = int(a[0])
    d = int(e%100)
    c = int(e/100)

    clear_output(wait=True)

    print("Piyush's magic square:")

    prow = [[a, b, c, d],
     [d + 3, c - 7, b - 1, a + 5],
     [b + 2, a + 6, d + 2, c - 10],
     [c - 5, d + 1, a - 1, b + 5]]

    rrow = [[a, b, c, d],
     [d + 1, c - 1, b - 3, a + 3],
     [b - 2, a + 2, d + 2, c - 2],
     [c + 1, d - 1, a + 1, b - 1]]

    print(tabulate(prow, tablefmt = "grid"))

    #print('\033[1m' + "\nRamanujan's magic square:" + '\033[0m')

    #print(tabulate(rrow, tablefmt = "grid"))

elif a == 4:
    import random
    from supportSystem import *

    # GAMEPLAY!
    if __name__ == "__main__":

        player_Chips = Chips()
        print("Welcome to BlackJack!")

        while (True):
            print("How many chips would you like to bet? you have now {} ".format(
                player_Chips.total))

            # if y is int  , and you have Enough Chips to Play
            y = Error().Error_bet(player_Chips.total)
            player = Hand()
            dealer = Hand()
            card_in_game = Deck(Card().all_card)

            #  1 card to dealer
            random_choice = random.choices(
                card_in_game.cards)  # random ...[('3', 'Hearts')]....
            card_in_game.Deck_pop(card_in_game.find_idx(
                random_choice[0]))  # pop obj in card_in_game by idx
            dealer.add_card(
                random_choice,
                card_in_game.cart[random_choice[0][0]])  # add card to player
            #  2 card to dealer
            random_choice = random.choices(
                card_in_game.cards)  # random ...[('3', 'Hearts')]....
            card_in_game.Deck_pop(card_in_game.find_idx(
                random_choice[0]))  # pop obj in card_in_game by idx
            dealer.add_card(
                random_choice,
                card_in_game.cart[random_choice[0][0]])  # add card to player
            Presentation().dealer_printing(
                dealer)  # print 2 card in player hand

            #  1 card to player
            # random ...[('3', 'Hearts')]....
            random_choice = random.choices(card_in_game.cards)

            card_in_game.Deck_pop(card_in_game.find_idx(
                random_choice[0]))  # pop obj in card_in_game by idx
            player.add_card(
                random_choice,
                card_in_game.cart[random_choice[0][0]])  # add card to player
            #  2 card to player
            # random ...[('3', 'Hearts')]....
            random_choice = random.choices(card_in_game.cards)

            # pop obj in card_in_game by idx
            card_in_game.Deck_pop(card_in_game.find_idx(random_choice[0]))

            # add card to player
            player.add_card(random_choice, card_in_game.cart[random_choice[0][0]])
            print("~ Player Hand  ~")
            print("~~~~~~~~~~~~~~~~")

            # print 2 card in player hand
            Presentation().Hand_printing(player)

            # win , lose or go on
            for_loop_2 = player.hand_win()

            # player win or not , if not player can take another card
            while (True):
                if (player.hand_win() == "Win"):
                    print("player Win")
                    for_loop_2 = player.hand_win()
                    player_Chips.add(y)
                    break

                elif (player.hand_win() == "Lose"):
                    print("player Lose")
                    for_loop_2 = player.hand_win()
                    player_Chips.remove(y)
                    break
                else:
                    print("You want to take another card : yes or no ")
                    x = Error().is_Error()  # need to be yes or no
                    if x == "yes" or x == 'y':
                        random_choice = random.choices(
                            card_in_game.cards)  # random ...[('3', 'Hearts')]....
                        card_in_game.Deck_pop(
                            card_in_game.find_idx(random_choice[0])
                        )  # pop obj in card_in_game by idx
                        player.add_card(random_choice, card_in_game.cart[
                            random_choice[0][0]])  # add card to player
                        print("~ Player Hand  ~")
                        print("~~~~~~~~~~~~~~~~")
                        Presentation().Hand_printing(
                            player)  # print 2 card in player hand
                    else:
                        print("~ Dealer Hand  ~")
                        print("~~~~~~~~~~~~~~~~")
                        Presentation().Hand_printing(dealer)
                        for_loop_2 = player.hand_win()
                        break

            while (for_loop_2 == "Go on"):  #if player dont win or lose Dealer move

                if (dealer.hand_win() == "Win"):
                    print("Dealer Win")
                    player_Chips.remove(y)
                    break

                elif (dealer.hand_win() == "Lose"):
                    print("Dealer Lose")
                    player_Chips.add(y)
                    break

                elif (dealer.value < 17):  # 17 > dealer  , dealer +1 card
                    random_choice = random.choices(
                        card_in_game.cards)  # random ...[('3', 'Hearts')]....
                    card_in_game.Deck_pop(card_in_game.find_idx(
                        random_choice[0]))  # pop obj in card_in_game by idx
                    dealer.add_card(random_choice, card_in_game.cart[
                        random_choice[0][0]])  # add card to player
                    print("~ Dealer Hand  ~")
                    print("~~~~~~~~~~~~~~~~")
                    Presentation().Hand_printing(dealer)

                elif (dealer.value >= 17
                      and dealer.value > player.value):  #    17 <= dealer > player
                    print("Dealer Win")
                    player_Chips.remove(y)
                    break
                else:  # 17 < = dealer < player or  dealer == player
                    print("Player Win")
                    player_Chips.add(y)
                    break

            if (player_Chips.total == 0):
                print("you have 0 Chips !! sorry Game over !! :( ")
                break

            print("You'll want a new game : yes / no ")
            x = Error().is_Error()  # need to be yes or no
            if x == "no":
                print("Game End")
                print("you have {} Chips in the End of the Game ".format(
                    player_Chips.total))
                break
            else:
                print(" ")  # \n
                print(" New Game ")
                print(" ")  # \n

elif a == 5:
    from PIL import Image

    ASCII_CHARS = ['@', '#', 'S', '%', '?', '*', '+', ';', ':', ',', '.']
    #ASCII_CHARS = ASCII_CHARS[::-1]

    def resize(image, new_width=100):
        (old_width, old_height) = image.size
        aspect_ratio = float(old_height)/float(old_width)
        new_height = int(aspect_ratio * new_width)
        new_dim = (new_width, new_height)
        new_image = image.resize(new_dim)
        return new_image

    def grayscalify(image):
        return image.convert('L')

    def modify(image, buckets=25):
        initial_pixels = list(image.getdata())
        new_pixels = [ASCII_CHARS[pixel_value//buckets] for pixel_value in initial_pixels]
        return ''.join(new_pixels)

    def do(image, new_width=100):
        image = resize(image)
        image = grayscalify(image)

        pixels = modify(image)
        len_pixels = len(pixels)

        # Construct the image from the character list
        new_image = [pixels[index:index+new_width] for index in range(0, len_pixels, new_width)]

        return '\n'.join(new_image)

    def runner(path):
        image = None
        try:
            image = Image.open(path)
        except Exception:
            print("Unable to find image in",path)
            #print(e)
            return
        image = do(image)

        # To print on console
        print(image)

        f = open('img.txt','w')
        f.write(image)
        f.close()

    if __name__ == '__main__':
        import sys
        import urllib.request
        argv = input("Enter your image path: ")
        if argv.startswith('http://') or argv.startswith('https://'):
            urllib.request.urlretrieve(sys.argv[1], "asciify.jpg")
            path = "asciify.jpg"
        else:
            path = argv 
        runner(path)