def split_text():
    text = input("Enter a sentence or paragraph: ")
    words = text.split()
    print("\nWords in the input:")
    for word in words:
        print(word)

if __name__ == "__main__":
    print("Text Processing Tool - Word Splitter")
    split_text()
