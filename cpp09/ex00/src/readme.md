Notes to check on applied logic:
Creates a program that compares the csv data of input_file against csv data of reference_file.

It creates map elements for both files.
To create a map element efficiently, it does the following checks:
- checks if file ends in .csv
- checks if file can be opened
- collects 1st key until ',';
    - does the following checks:
        - checks if key is not empty
        - overwrites unique keys <---- not handling as unsure
        - checks if date format is correct
- collects 2nd key until end of the line;
    - does the following checks:
        - checks if value is not empty
        - checks if value is a number
