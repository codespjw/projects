# name.py
from name_functions import get_formatted_name

print("Enter 'q' at any time to quit")
while True:
    first = input('\nFirst name: ')
    if first == 'q':
        break
    last = input('\nLast name: ')
    if last == 'q':
        break

    formatted_name = get_formatted_name(first, last)
    print('\Neatly formatted name: ' + formatted_name + '.')
