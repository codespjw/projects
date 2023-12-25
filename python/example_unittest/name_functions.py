
# name_functions.py
def get_formatted_name(first, last, middle=''):
    """获得一个全名"""
    if middle:
        full_name = first + ' ' + middle + ' ' + last
    else:
        full_name = first + ' ' + last
    return full_name.title()
