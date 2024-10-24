/*
 * This program merges multiple sorted files of strings into a single output file with unique strings and their frequency.
 * The input files are specified in "in.dat", which lists the number of files and their names.
 * The program reads all input files simultaneously using a heap to maintain a minimum ordering of strings across files.
 * It writes the unique strings along with their frequency count to "out.dat".
 */

// Name: Yuma Fukazawa
// ID Number: 1002236682
// Command to compile in omega: gcc -std=c99 -o 3318_lab2 3318_lab2.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LENGTH 50
#define MAX_STRING_LENGTH 300
#define MAX_FILES 50
typedef struct {
    FILE *file;
    char currentString[MAX_STRING_LENGTH];
} FileHandler;

// Maintains the min-heap property for the array of FileHandlers.
void minHeapify(FileHandler *fileHandlers[], int n, int i) {
    /*
     * Input: Array of pointers to FileHandler, number of files (n), index to start heapifying (i)
     * Output: None
     * Processing: Swaps elements to ensure the smallest string is at the root of the heap.
     */
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && strcmp(fileHandlers[left]->currentString, fileHandlers[smallest]->currentString) < 0) {
        smallest = left;
    }

    if (right < n && strcmp(fileHandlers[right]->currentString, fileHandlers[smallest]->currentString) < 0) {
        smallest = right;
    }

    if (smallest != i) {
        FileHandler *temp = fileHandlers[i];
        fileHandlers[i] = fileHandlers[smallest];
        fileHandlers[smallest] = temp;
        minHeapify(fileHandlers, n, smallest);
    }
}

// Builds a min-heap from an array of FileHandlers.
void buildMinHeap(FileHandler *fileHandlers[], int n) {
    /*
     * Input: Array of pointers to FileHandler, number of files (n)
     * Output: None
     * Processing: Calls minHeapify for each non-leaf node to build the heap.
     */
    for (int i = n / 2 - 1; i >= 0; i--) {
        minHeapify(fileHandlers, n, i);
    }
}

int main() {
    FILE *inFile = fopen("in.dat", "r");
    if (inFile == NULL) {
        perror("Error opening in.dat");
        return 1;
    }

    int fileCount;
    fscanf(inFile, "%d", &fileCount);

    // Prepare an array of file handlers
    FileHandler *fileHandlers[MAX_FILES];
    for (int i = 0; i < fileCount; i++) {
        char filename[MAX_FILENAME_LENGTH];
        fscanf(inFile, "%s", filename);

        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            perror("Error opening data file");
            continue;
        }

        fileHandlers[i] = (FileHandler *)malloc(sizeof(FileHandler));
        fileHandlers[i]->file = file;

        if (fgets(fileHandlers[i]->currentString, MAX_STRING_LENGTH, file) != NULL) {
            fileHandlers[i]->currentString[strcspn(fileHandlers[i]->currentString, "\n")] = '\0'; // Remove newline character
        }
    }
    fclose(inFile);

    // Build initial heap
    buildMinHeap(fileHandlers, fileCount);

    FILE *outFile = fopen("out.dat", "w");
    if (outFile == NULL) {
        perror("Error opening out.dat");
        return 1;
    }

    char previousString[MAX_STRING_LENGTH] = "";
    int count = 0;

    // Loop through files until all strings are processed
    while (fileCount > 0) {
        FileHandler *minFileHandler = fileHandlers[0];
        if (strcmp(minFileHandler->currentString, previousString) == 0) {
            count++; // Increment count if current string matches previous
        } else {
            if (count > 0) {
                fprintf(outFile, "%s %d\n", previousString, count); // Write the previous string and its count
            }
            strcpy(previousString, minFileHandler->currentString);
            count = 1; // Reset count for the new string
        }

        // Read the next line from the current file
        if (fgets(minFileHandler->currentString, MAX_STRING_LENGTH, minFileHandler->file) != NULL) {
            minFileHandler->currentString[strcspn(minFileHandler->currentString, "\n")] = '\0'; // Remove newline character
        } else {
            // Reached the end of the file
            fclose(minFileHandler->file);
            free(minFileHandler);
            fileHandlers[0] = fileHandlers[fileCount - 1]; // Replace the finished file with the last one in the list
            fileCount--; // Decrease the number of files being processed
        }

        // Rebuild the heap to maintain order
        minHeapify(fileHandlers, fileCount, 0);
    }

    // Write the last string and count
    if (count > 0) {
        fprintf(outFile, "%s %d\n", previousString, count);
    }

    fclose(outFile);
    return 0;
}