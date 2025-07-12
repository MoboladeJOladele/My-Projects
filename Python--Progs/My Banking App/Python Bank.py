import random

registered_accounts = [['2531042', 16000], ['223146', 7500], ['204562', 0],
                       ['2222312', 76000], ['2489281', 300], ['2123972', 53000], [None, None]]
array_length = len(registered_accounts)

account_no = 0
account_balance = 1

# The account at index six (col 7) is yet to be registered. That position is left for any new customers.
new_costumer = 6


def fairwell_message():
    print("Thank you for using Python Bank.")


def main():
    have_an_account = input("Do you have an account? ").lower()

    while True:
        if have_an_account == 'no':
            register_new_account()

            status = input("If you'd like to proceed to your dashboard, type 'PROCEED'. "
                        "But, if you prefer to exit the program, type 'X' ").lower()

            while True:
                if status == 'x':
                    fairwell_message()
                    return

                elif status == 'proceed':
                    dashboard_(new_costumer)
                    return

                else:
                    print("You can't give a response that is not amongst the two options")
                    status = input("Response: ").lower()

        elif have_an_account == 'yes':
            _account_no = input("What is your account number? ")


            costumer = None

            registered, costumer = is_account_registered(_account_no)

            if registered == True:
                amount = check_balance(costumer)

                if amount == 0:
                    print("You don't have any funds in your account.")

                    fund = input("Would you like to fund it? ").lower()

                    while fund != 'yes':
                        print("You can't proceed unless you fund your account")
                        fund = input("Would you like to fund it? ").lower()
                    
                    new_balance = fund_account(costumer)
                    print("Congratulations, your account balance has been updated.")
                    print(f"You now have ${new_balance} in your account")

                    print()

                else:
                    print(f"Welcome '{registered_accounts[costumer][account_no]}'")

                # Go to dashboard
                dashboard = input("To proceed to your Dashboard, respond 'DB' to this message. "
                                "But if you'd prefer to exit the program type 'X' ").lower()
                
                while True:
                    if dashboard == 'x':
                        fairwell_message()
                        return

                    elif dashboard == 'db':
                        # Go to dashboard
                        print()
                        dashboard_(costumer)
                        return

                    else:
                        print("You can't give a response that is not amongst the two options")
                        dashboard = input("Response: ").lower()
        else:
            have_an_account = input("Response is either 'YES' or 'NO': ").lower()

def is_account_registered(number):
    for i in range(array_length):
        if number == registered_accounts[i][account_no]:
            return True, i

    print(f"'{number}' We couldn't find this account. Ensure you put in the right details.")
    _account_number = input("Enter your account number  ")
    return is_account_registered(_account_number)


def register_new_account():
    name = input("What's your name? ")

    phone_number = get_postive_int("What's your phone number? ")
    already_have_an_account = input("Do you have any existing bank account? ").lower()

    if already_have_an_account == 'yes':
        bank = input("Is it with our bank or another bank? Answer('Yours', 'Others') ").lower()
        if bank == 'others':
            input("What's the name of the bank? ")
        print("That's lovely.")

    create_the_account = input("Should we proceed to create your new account? ").lower()
    if create_the_account == 'yes':

        # Temporarily,
        account_number = list('3000000')
        _length = len(account_number)

        _zeros = 0
        for i in range(1, _length):
            digit = (phone_number * random.randint(1, 4)) % 9

            if digit == 0:
                _zeros += 1

                if _zeros > 1:
                    digit = (i * i) % 11
            account_number[i] = str(digit)

        # After the loop, combine the list of numbers to form the actual account number
        account_number = str(''.join(account_number))

        # Congrats
        print(f"Great.  Your account number is {account_number}")

        # Add to the list
        registered_accounts[new_costumer][account_no] = account_number
        registered_accounts[new_costumer][account_balance] = 0

        fund_new_account()


def get_postive_int(text):
    number = int(input(f"{text}"))

    if number < 1:
        return get_postive_int(text)
    
    else:
        return number

def check_balance(costumer):
    return registered_accounts[costumer][account_balance]


def fund_account(costumer):
    number = input("Enter your account number -> ")
    if number == registered_accounts[costumer][account_no]:
        amount = get_postive_int("How much are you sending to the account? $")

        # The next line is not actually needed, but it's just there for professionality
        get_postive_int("Please enter your transaction PIN -> ")

        # Add to the current balance
        registered_accounts[costumer][account_balance] += amount

        return registered_accounts[costumer][account_balance]

    return fund_account(costumer)


def fund_new_account():
    account_number = registered_accounts[new_costumer][account_no]

    print()

    print("To fund your new account kindly type in your account number, and the amount to be funded below")
    details = input("Account Number/ Funds added -> ")

    size = len(details) - (len(account_number) + len('/ '))
    funds = [None] * size

    for i in range(size):
        funds[i] = details[((len(details) - size) + i)]

    # Add the funds to the account
    registered_accounts[new_costumer][account_balance] += int(''.join(funds))

    print(
        f"Congrats, you now have ${registered_accounts[new_costumer][account_balance]} in your account")
    print()


def dashboard_(costumer):
    print(f"'{registered_accounts[costumer][account_no]}' Welcome, to your Python dashboard")
    print()
    options(costumer)


def options(costumer):
    print("What would you like to do today?")

    print("1. fund your account")
    print("2. check your account balance ")
    print("3. refer a friend")

    response = input("input: ")

    if response == '1' or response == '1.':
        fund_account(costumer)

    elif response == '2' or response == '2.':
        balance = check_balance(costumer)
        print(f"You have ${balance} in your account")

    elif response == '3' or response == '3.':
        print(
            f"Here's you unique referral code 'pythonbank.refer.{registered_accounts[costumer][account_no]}', invite your friends and win cool cash")

    else:
        print("Please select an option")
        return options(costumer)

    print()
    more_services = input("Would you like to use any other service? ").lower()

    while True:
        if more_services == 'yes':
            return options(costumer)

        elif more_services == 'no':
            print()
            fairwell_message()
            break

        else:
            more_services = input("Response is 'YES' or 'N0': ").lower()

if __name__ == "__main__":
    main()
