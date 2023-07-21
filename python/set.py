# Example of creating a set
fruits = {'apple', 'banana', 'orange', 'apple'}
print(fruits)  # Output: {'banana', 'orange', 'apple'} (Note: 'apple' appears only once due to uniqueness)

# Adding elements to a set
fruits.add('grape')
print(fruits)  # Output: {'banana', 'grape', 'orange', 'apple'}

# Removing elements from a set
fruits.remove('orange')
print(fruits)  # Output: {'banana', 'grape', 'apple'}

# Set operations
set1 = {1, 2, 3}
set2 = {3, 4, 5}
union_set = set1.union(set2)
print(union_set)  # Output: {1, 2, 3, 4, 5}
intersection_set = set1.intersection(set2)
print(intersection_set)  # Output: {3}
