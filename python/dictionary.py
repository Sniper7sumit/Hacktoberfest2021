# Example of creating a dictionary
student = {
    'name': 'John Doe',
    'age': 25,
    'roll_number': '12345',
    'courses': ['Math', 'Science', 'History']
}
print(student)  # Output: {'name': 'John Doe', 'age': 25, 'roll_number': '12345', 'courses': ['Math', 'Science', 'History']}

# Accessing values using keys
print(student['name'])  # Output: 'John Doe'
print(student['courses'])  # Output: ['Math', 'Science', 'History']

# Adding a new key-value pair
student['gender'] = 'Male'
print(student)  # Output: {'name': 'John Doe', 'age': 25, 'roll_number': '12345', 'courses': ['Math', 'Science', 'History'], 'gender': 'Male'}

# Removing a key-value pair
del student['age']
print(student)  # Output: {'name': 'John Doe', 'roll_number': '12345', 'courses': ['Math', 'Science', 'History'], 'gender': 'Male'}

# Dictionary methods
keys = student.keys()
print(keys)  # Output: dict_keys(['name', 'roll_number', 'courses', 'gender'])

values = student.values()
print(values)  # Output: dict_values(['John Doe', '12345', ['Math', 'Science', 'History'], 'Male'])
