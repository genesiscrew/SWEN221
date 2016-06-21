import csv
def add_vectors(vector_1, vector_2):
    """Returns a list object representing the result of adding two vectors together.

       Arguments:
       vector_1 -- list representing first vector
       vector_2 -- list representing second vector

       Error checking:
       Both arguments must be of type list.
       Both vectors must of the same length.
       Only vector elements of type int can be added together.
    """
    if isinstance(vector_2,list) == False and isinstance(vector_1,list) == False:
        print('Error: first argument is not a list')
        print('Error: second argument is not a list')
        return
    elif isinstance(vector_1,list) == False :
        print('Error: first argument is not a list')
        return
    elif isinstance(vector_2,list) == False :
        print('Error: second argument is not a list')
        return
    
    elif len(vector_1) != len(vector_2):
        print('Error: lengths of the two vectors are different')
        return
    count = [];
    for index, item in enumerate(vector_1):
        if isinstance(item, int) and isinstance(vector_2[index], int):
            count.append(item+vector_2[index])      
        else:
            print("Error: attempted to add incompatible" + " " + str(item) + " " + "to" + ' ' + str(vector_2[index]))
            return
    return count        

    

def print_frequency(some_text):
    """Prints a table of letter frequencies within a string. 

       Non-letter characters are ignored (use .isalpha()).
       Table is sorted alphabetically.
       Letter case is ignored.
       Two blank spaces will separate the letter from its count.

       Returns None in all cases.

       Argument:
       some_text -- string containing the text to be analysed.

       Error checking:
       The argument must be a string object.
    """
    
    if not isinstance(some_text,str):
        print('Error: only accepts strings')
        return
    if not some_text.strip():
        return
    table = []
    l = list(some_text)
    for index, item in enumerate(l):
        if item.isalpha():
            item = item.lower()
            l[index] = item
    for index, item in enumerate(l):
        if item.isalpha():
            table.append(item + "  " + str(l.count(item)))       
    print('\n'.join(sorted(set(table))))         
    


def verbing(some_text):
    """Returns a string where the each word has ing added to it if it is 3 or more characters or length and 
       ly to shorter words.

       Argument:
       some_text -- string containing the text to be analysed.

       Error checking:
       The argument must be a string object.
    """

    if isinstance(some_text,str) is False:
        print("Error: only accepts strings")
        return
    l = some_text.split()
    for index, item in enumerate(l):
        if len(item) >= 3:
            item+='ing'
            l[index] = item
        else:
            item +='ly'
            l[index] = item
    l = ' '.join(l)
    return l
   

def add_vectors_file(file_name):
    """
    Processes a given comma seperated file and extracts the 'pay' and 'bonus' columns
    then adds the two vectors together to determine the total price.

    Argument:
    file_name -- the name of the file (assumed to exist in the same directory as the 
                 python script is executed). The file is a set of comma seperated values
                 the first line contains headers (seperated by commas) and subsequent lines
                 contain data corrosponding to each header.

    Error checking:
    The argument must be a string object
    The file must exist and be readable (no need to distinguish these cases)
    The 'pay' and 'bonus' columns must exist in the header

    """
    error_to_catch = getattr(__builtins__,'FileNotFoundError', IOError)

    if isinstance(file_name,str) is False:
        print("Error: only accepts strings")
        return

    try:
        f = open(file_name, 'r' )
        reader = csv.reader(f)
        b = []
        for index, item in enumerate(reader):
            if  index == 0 and ('pay' not in item or 'bonus' not in item):
                print('Error: the file must contain pay and bonus columns')
                return
            if index == 0:
                index1 = item.index('pay')
                index2 = item.index('bonus')
            if index != 0:
                b.append(int(item[index2])+int(item[index1]))

        return b    
            
    except error_to_catch:
        print('Error reading from file' + ' ' + file_name)
        return
    





