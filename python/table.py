def print_multiplication_table(n):
    for i in range(1, 11):  # Generate table for numbers 1 to 10
        result = n * i
        print(f"{n} x {i} = {result}")

# Example usage:
if __name__ == "__main__":
    natural_number = int(input("Enter a natural number: "))
    print_multiplication_table(natural_number)
