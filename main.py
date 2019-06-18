#!/usr/bin/env python
from py_expression_eval import Parser
import decimal
from sympy import Symbol, Derivative



def get_zeros(num):
    decimalPlaces = 0
    for x in str(num).split('.')[-1]:
        if x == '0':
            decimalPlaces += 1

    return decimalPlaces

def get_parsed_equation(driv_eq):
    return str(driv_eq.doit()).replace('**', '^')

def get_unparsed_equation(equation):
    return str(equation).replace('^', '**')

def bisection():
    print("""
            Bisection Method 
        """)
    # Ask user for the equation, interval, requiredDecimalPlaces
    
    # Get the equation 
    equation = str(input("Enter the root equation: "))
    # equation = "x^3+x^2+x+7"

    # Get the requiredDecimalPlaces 
    requiredDecimalPlaces = int(input("Please enter the required decimal places: "))

    #Get the interval 
    rootInput = str(input("Enter the interval seprated by comma (,): "))
    roots = rootInput.split(',')
    roots.sort()

    # Evaluate the equation
    parser = Parser()
    eq = parser.parse(equation)

    
    # Check if x is found in the interval 
    f1 = eq.evaluate({'x': float(roots[0])}) # Equation substitution with value of interval 1
    f2 = eq.evaluate({'x': float(roots[1])}) # Equation substitution with value of interval 2

    # Check if f1 * f2 < 0 
    if f1 * f2 > 0:
        print("Error: F({}) * F({}) > 0".format(float(roots[0]), float(roots[1])))
        quit()

    # Values initialization
    x_values = [0]
    
    x_previous = 0
    x_current = 0

    decimalPlaces = 0

    # Initial values of a, b 
    a = float(roots[0])
    b = float(roots[1])

    # Get number of iteration 
    noOfIterations = 0

    # Start iterations 
    while decimalPlaces <= requiredDecimalPlaces:    
        # Get x 
        x_current = ( a + b ) / 2
        # Set the previous x 
        x_previous = x_values.pop()
        # Append the new value to the queue 
        x_values.append(x_current)

        # Check if fa * fb < 0 
        f1 = eq.evaluate({'x': float(a)})
        f2 = eq.evaluate({'x': float(x_current)})

        if f1 * f2 < 0:
            b = x_current
        else: 
            a = x_current
        
        # Get the error value 
        error = abs(x_current - x_previous)
        decimalPlaces = get_zeros(error)
        
        noOfIterations += 1


    # Print output 
    print("The root is: {}, The Error is: {}, No of iterations is: {}".format(x_current, error, noOfIterations ))

def newton():
    print("""
            Newton Method 
        """)
    # Ask user for the equation, interval, requiredDecimalPlaces
    
    # Get the equation 
    equation = str(input("Enter the root equation: "))

    # Get the requiredDecimalPlaces 
    requiredDecimalPlaces = int(input("Please enter the required decimal places: "))

    # Prepare the equation to fit derivative shape (** instead of ^ )
    derv_equation = get_unparsed_equation(equation)

    # Get the first and the second derivative
    x = Symbol('x') # Variable
    first_derivative = Derivative(derv_equation, x)
    second_derivative = Derivative(first_derivative.doit(), x)

    # Select interval 
    guess0 = 0
    guess1 = 1

    # get the values of functions 
    parser = Parser()
    fOf0 = parser.parse(equation).evaluate({'x': guess0})
    fOf1 = parser.parse(equation).evaluate({'x': guess1})
    
    x0InSecondDrv = parser.parse(get_parsed_equation(second_derivative)).evaluate({'x': guess0})

    # Check
    if fOf0 * fOf1 < 0:
        print("Root lies between {} and {}".format(guess0, guess1))
    else: 
        quit("Root isn't between {} and {}".format(guess0, guess1))

    # print("Function:",function, "Derivative:", first_derivative.doit(), "Second derivative:", second_derivative.doit())

    # Set x0 
    x0 = guess0
    if fOf0 * x0InSecondDrv > 0:
        print("Good convergent initial point")
    
    # Start Iteration
    currentx = 0
    x_values = [0]

    decimalPlaces = 0

    noOfIterations = 0

    while decimalPlaces <= requiredDecimalPlaces:
        previousx = x_values.pop()
        fx = parser.parse(equation).evaluate({'x': previousx}) # F(x)
        fPrime = parser.parse(get_parsed_equation(first_derivative)).evaluate({'x': previousx}) # F`(x)
        currentx = previousx - (float(fx) / float(fPrime))
        x_values.append(currentx)

        # Calculate the error 
        # Get the error value 
        error = abs(currentx - previousx)
        decimalPlaces = get_zeros(error)

        noOfIterations += 1

    # Printing results 
    print("The root is {}, The error is: {}, No of iterations is: {}".format(currentx, error, noOfIterations))

    

if __name__ == "__main__":
    print("""                                                                                                               
    
8888888  .d8888b.   .d8888b.  8888888b.        888b    888                                         d8b                   888 
  888   d88P  Y88b d88P  Y88b 888   Y88b       8888b   888                                         Y8P                   888 
  888   Y88b.      Y88b.      888    888       88888b  888                                                               888 
  888    "Y888b.    "Y888b.   888   d88P       888Y88b 888 888  888 88888b.d88b.   .d88b.  888d888 888  .d8888b  8888b.  888 
  888       "Y88b.     "Y88b. 8888888P"        888 Y88b888 888  888 888 "888 "88b d8P  Y8b 888P"   888 d88P"        "88b 888 
  888         "888       "888 888 T88b         888  Y88888 888  888 888  888  888 88888888 888     888 888      .d888888 888 
  888   Y88b  d88P Y88b  d88P 888  T88b        888   Y8888 Y88b 888 888  888  888 Y8b.     888     888 Y88b.    888  888 888 
8888888  "Y8888P"   "Y8888P"  888   T88b       888    Y888  "Y88888 888  888  888  "Y8888  888     888  "Y8888P "Y888888 888                                                                                           
    """)

    method = int(input("""
    Please Select an method
        1) Bisection
        2) Newton 
        
        Choice: """))

    if method == 1:
        bisection()
    elif method == 2:
        newton()
    else:
        print("Unknown choice..")
        quit()
