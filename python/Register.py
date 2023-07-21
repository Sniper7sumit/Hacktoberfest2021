def create_student():
    student = {}
    student['name'] = input("Enter student's name: ")
    student['age'] = int(input("Enter student's age: "))
    student['roll_number'] = input("Enter student's roll number: ")
    student['courses'] = input("Enter student's courses (comma-separated): ").split(',')
    return student

def display_student(student):
    print(f"\nName: {student['name']}")
    print(f"Age: {student['age']}")
    print(f"Roll Number: {student['roll_number']}")
    print("Courses:", ', '.join(student['courses']))

if __name__ == "__main__":
    print("Student Information Management System")
    students = []

    while True:
        print("\nOptions:")
        print("1. Add Student")
        print("2. Display Students")
        print("3. Exit")

        choice = input("Enter choice (1/2/3): ")

        if choice == '1':
            student = create_student()
            students.append(student)
            print("Student added successfully!")
        elif choice == '2':
            if len(students) == 0:
                print("No students found.")
            else:
                print("\nStudent List:")
                for student in students:
                    display_student(student)
        elif choice == '3':
            print("Exiting the program.")
            break
        else:
            print("Invalid choice. Please try again.")
