**Problem Definition :**
The municipality of Hubli wants to maintain Birth and Death records. User must be able to add an entry and also search a specific entry in the records based on either date or name of the person.

**Approach :**
-	Create 2 lists
-	Each node consists of 2 members i.e., Name and Date
-	Take a name as input and search it in both the lists of Birth and Death.
-	This will display whether the name of that person is in Birth list and Death list.
-	Take a date as input and search it in both the lists of Birth and Death.
-	This will display all the names of people born and died on that specific day.
  
**Logic :**
- Declare a structure with members as name and date.
-	Declare the options for adding and searching and accepting key name or date.
-	Declare the cases.
-	While choice is equal to any of the cases, call the function.
-	Create function creates 2 lists.
-	Take input as name and compare it with each element in both the lists using strcmpi function.
-	And display.

This includes the concepts like :
- Singly linked list
- adding node in linked lists
- traversal in linked lists
- searching in linked lists
