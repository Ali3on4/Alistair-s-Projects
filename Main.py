import csv

phonebook = {}

while True:
    print("Option 1: Create new contact")
    print("Option 2: View Phonebook")
    print("Option 3: Import Contacts")
    print("Option 4: Delete contact")
    print("Option 5: Export Contacts")
    print("Option 6: Exit")

    print("")
    try:

        userchoice = int(input("Enter the option that you would like to proceed with: "))

        if userchoice == 1:
            nameofcontact = input("Enter the name of the contact: ")
            numberofcontact = int(input("Enter their phone number: "))
            phonebook[nameofcontact] = numberofcontact

        elif userchoice == 2:
            print("")
            for x in phonebook.items():
                print(x)

        elif userchoice == 3:
            while True:
                usersfile = input("Which file would you like to import?")
                try:
                    with open(usersfile, 'r') as file:
                        print('File found!')
                        reader = csv.reader(file, delimiter=',')
                        header =  next(reader)

                        for row in reader:
                            NameOfImport = row[0]
                            NumberOfImport = row[8]
                            phonebook[NameOfImport] = NumberOfImport
                        break


                except FileNotFoundError:
                    print('Could not find file')

                except OSError as e:
                    if e.errno == 22:
                        print(f"OSError: Invalid argument. Check the file path: {usersfile}")
                        print("Path does NOT require quotation marks or double slashes.")
                    else:
                        print(f"An error occurred: {e}")

        elif userchoice == 4:
            print("")
            deletecontact = input("Enter the name of contact you would like to delete: ")
            deleted = False
            for x in phonebook:
                if deletecontact == x:
                    print("Deletion in progress")
                    phonebook.pop(deletecontact)
                    deleted = True
                    break
            if deleted == False:
                print("The contact doesn't exist")

        elif userchoice == 5:
            Column_Names = ['Name', 'Number']  # Specify your column names here
            with open("C:\\Users\\Alist\\Desktop\\Phonebook.csv", 'w', newline='') as SavedFile:
                writer = csv.DictWriter(SavedFile, Column_Names)
                writer.writeheader()

                for name, number in phonebook.items():
                    writer.writerow({'Name': name, 'Number': number})

            print("Saved in Desktop!")


        elif userchoice == 6:
            break

        else:
            print("Please enter a number between 1 - 6")
    except ValueError:
        print("Please enter a valid number.")
