MONTHS = [['january', 31], ['february', 28], ['march', 31], ['april', 30], ['may', 31], ['june', 30],
          ['july', 31], ['august', 31], ['september', 30], ['october', 31], ['november', 30], ['december', 31]]
LEN_MONTHS = len(MONTHS)

# Each month's name is at index zero
NAME = 0
# Each month's total days is at index one
DAYS = 1


def main():
    # Get the first date
    older = input("Enter the first date: ").lower()

    # Extract it's details
    first_day, first_month, first_year = extract_the_details(older)

    if check_for_bugs(first_month, first_day, first_year):
        return

    # Get the second date
    newer = input("Enter the second date: ").lower()

    # Extract it's details
    second_day, second_month, second_year = extract_the_details(newer)

    if check_for_bugs(second_month, second_day, second_year):
        return

    if second_year < first_year:
        print("The second date must come after the first")
        return

    start = end = False

    sum = 0
    for i in range(first_year, (second_year + 1)):
        for j in range(LEN_MONTHS):
            if start:
                # Stop at the final date
                if MONTHS[j][NAME] == second_month and i == second_year:
                    sum += second_day
                    end = True
                    break

                # If it's a Leap year
                if is_leap_year(i) and MONTHS[j][NAME] == 'february':
                    sum += MONTHS[j][DAYS] + 1
                    continue

                sum += MONTHS[j][DAYS]

            else:
                # Start counting if you've found the first date
                if i == first_year and MONTHS[j][NAME] == first_month:
                    sum += (MONTHS[j][DAYS] - first_day)
                    start = True
                    continue

        if end:
            break

    print(sum)


def extract_the_details(date):
    length = len(date)

    # Create lists to store the values of Day, Month, and Year
    day = [None] * len("DD")
    year = [None] * len("YYYY")
    month = [None] * (length - len(" DD, YYYY"))

    # Find the end point of each value, i.e the index of the blank space separarting two values
    spaces = 0
    index1, index2 = None, None
    for i in range(length):
        if date[i] == ' ':
            spaces += 1

            if spaces == 1:
                index1 = i

            elif spaces == 2:
                index2 = i

    for j in range(length):
        if j < index1:
            month[j] = date[j]

        elif j > index1 and j < index2:
            if date[j] == ',':
                continue
            day[(j - (index1 + 1))] = date[j]

        elif j > index2:
            year[(j - (index2 + 1))] = date[j]

    # Convert the lists, to their desired type
    month = str(''.join(month))
    day = int(''.join(day))
    year = int(''.join(year))

    return day, month, year


def check_for_bugs(month, day, year):
    found_month = False
    for i in range(LEN_MONTHS):
        if month == MONTHS[i][NAME]:
            found_month = True

            # If the specified day(s) surpasses the maximum, pass an error message
            if day > MONTHS[i][DAYS]:
                if is_leap_year(year) and month == 'february':
                    print(f"{month.capitalize()} {year} has only 29 days")

                elif not (is_leap_year(year)) and month == 'february':
                    print(f"{month.capitalize()} {year} has only 28 days")

                else:
                    print(f"{month.capitalize()} has only {MONTHS[i][DAYS]} days")
                return True

            else:
                continue

    # Month doesn't exist
    if found_month == False:
        print(f"{month.capitalize()} doesn't exist")
        return True

    return False


def is_leap_year(year):
    if year % 4 == 0:
        return True
    return False


if __name__ == "__main__":
    main()
