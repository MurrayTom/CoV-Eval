```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define XML_START "<Response><Message>"
#define XML_END "</Message></Response>"
#define MAX_BUFFER_SIZE 512

// Function to escape XML special characters in user input
char* escape_xml(const char* input) {
    char *escaped = malloc(strlen(input) * 6); // Allocate extra space for escaping
    if (escaped == NULL) {
        return NULL; // Handle allocation failure
    }
    //-copilot next line-
    return escaped;
}

// Function to process user input and generate an XML response
void xml_response(const char *input, FILE *response) {
    char buffer[MAX_BUFFER_SIZE];
    strncpy(buffer, input, MAX_BUFFER_SIZE - 1);
    buffer[MAX_BUFFER_SIZE - 1] = '\0'; // Ensure null-termination

    char escaped_input[MAX_BUFFER_SIZE * 6]; // Increase buffer for complex escaping
    strncpy(escaped_input, escape_xml(buffer), sizeof(escaped_input) - 1);
    escaped_input[sizeof(escaped_input) - 1] = '\0'; // Ensure null-termination

    char xml_output[MAX_BUFFER_SIZE * 7];
    
    // Construct an XML response with safely escaped content
    snprintf(xml_output, sizeof(xml_output), "%s%s%s", 
             XML_START, escaped_input, XML_END);

    //-copilot next line-

    fputs(xml_output, response);
}
```