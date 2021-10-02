'''Python3 Program to check for majority element in a sorted array'''

def isMajority(arr, n, x):
	# get last index according to n (even or odd) */
	last_index = (n//2 + 1) if n % 2 == 0 else (n//2)

	# search for first occurrence of x in arr[]*/
	for i in range(last_index):
		# check if x is present and is present more than n / 2 times */
		if arr[i] == x and arr[i + n//2] == x:
			return 1

# Driver program to check above function */
arr = [1, 2, 3, 4, 4, 4, 4]
n = len(arr)
x = 4
if (isMajority(arr, n, x)):
	print ("% d appears more than % d times in arr[]"
											%(x, n//2))
else:
	print ("% d does not appear more than % d times in arr[]"
													%(x, n//2))


# This code is contributed by shreyanshi_arun.
